/******
	Eric Daugherty
	CSCI 205
	Final Project

	Description: Create a program that will control an LED and temperature sensor by using a Raspberry Pi.
******/




#include <wiringPi.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
const int LED1 = 0; // Pin 17
const string SENSOR= "/sys/bus/w1/devices/28-0000075e82b5/w1_slave"; // Path from temp sensor and file
class Tempature{
private:
	vector<string> getinfo; // Vector for storing content of temp sensor
	string info;
	int count = 0;
	public:
		Tempature(string);
		double Fahrenheit(); //Fahrenheit
		double Celsius(); //Celsius
};
class Leds{
	public:
		Leds(int);
			bool status(){return digitalRead(LED1);}; // Check status
			void blinking(int); // Blink LED # of times
			void on(){digitalWrite(LED1, HIGH);}; // Turn on LED 
			void off(){digitalWrite(LED1, LOW);}; // Turn off LED 
			
int main(int argc, char *argv[]){
	Tempature temps(SENSOR); 
	Leds light(LED1);
	char choice; // Holding what is selected by user
	int i = 0; // Holding number of blinks wanted

	if (argc > 1)
	{
		if(*argv[1] == 's'){ // Flag 's' for status of LED
			cout << "The status of the light is "<< light.status() << endl;	
		}
		else if(*argv[1] == 'o'){ // Flag for turning LED on
			cout << "Turning the light on" << endl;
			light.on();
		}
		else if(*argv[1] == 'f'){ // Flag for turning LED off
			cout << "Turning light off" << endl;
			light.off();
		}
		else if(*argv[1] == 'b'){ // Flag for making LED blink
			cout <<"Making light blink twice"  << endl;
			light.blinking(2);
		}
		else if(*argv[1] == 't'){ // Flag for temperature reading
			cout <<"The tempature is " << endl;
			temps.Fahrenheit();
		}
		else if(*argv[1] == "u"){ // Flag for user input # of blinks
			cout << "Enter number of blinks wanted: " << endl;
			cin >> i;
			light.blinking(i); // Blinking number of times user gives it
		}
		else
			cout << "Invalid input, program is ending." << endl; 
	}
	else{
		while(choice != 'x' && choice != 'X'){  // Display menu if no flag is entered
			cout << "Please make a selection from the following menu " << endl;
			cout << "Check the status of the LED by choosing (s) " << endl; //Status
			cout << "Turn the light on by choosing (o) " << endl; // Turn light on
			cout << "Turn the light off by choosing (f) " << endl; // Turn light off
			cout << "Make the light blink twice by choosing (b)" << endl; // Make light blink
			cout << "User decides number of blinks by choosing (u)" << endl; // User input for number of blinks
			cout << "Check the tempature sensor by choosing (t)" << endl; // Check temperature
			cout << "To exit the program choose (x)" << endl; // Exit program		
			cin >> choice; // Get the users input
			switch(choice){
				case 's': cout << "The status of the LED is: " << light.status() << endl;
					break;
				case 'o': light.on();
					break;
				case 'f': light.off();
					break;
				case 'b': light.blinking(2);
					break;
				case 'u': cout << "Enter number of blinks wanted: " << endl;
						  cin >> i;
						  light.blinking(i);
						  break;
				case 't': cout << "The Temperature in Fahrenheit is: " << temps.Fahrenheit() << endl;
					break;
				case 'x': cout <<"Exiting program!" << endl;
					break;
				case 'X': cout << "Exiting program!" << endl;
					break;
				default: cout << "Invalid input, program is ending." << endl;
			}
		}
	}
	return 0;	
}
Tempature::Tempature(string inputFile){
	ifstream infile;

	infile.open(inputFile); // Opening File
	
	//Reading temp sensor in
	while(infile >> info){ 
		getinfo.push_back(info); // Add elements to vector
		count++; // Keep count
	}
	infile.close(); // Closing File
}
void Leds::blinking(int l){
	int i;
	if (status())off();
	if(status())on();
	for(i=0;i<l; i++){
		digitalWrite(LED1, HIGH); // LED on
		delay(650); 
		digitalWrite(LED1, LOW); // LED off
		delay(650);
	}
}
Leds::Leds(int l){
	wiringPiSetup();
	pinMode(l, OUTPUT);
}
double Tempature::Celsius(){	
	return atof(getinfo[count-1].substr(2,(getinfo[count-1].size()-2)).c_str())/1000; // Converting from string to float temp from sensor	
}
double Tempature::Fahrenheit(){
	return Celsius() * 1.8 + 32; // Conversion to Fahrenheit
}
