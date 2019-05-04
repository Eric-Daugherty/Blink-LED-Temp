# **Blink-LED-Temp**
Using a Raspberry Pi and the GPIO interface to control hardware such as an LED and DS18B20 Temperature Sensor. Using a web server, PHP server-side and HTML to create a web interface that will control the hardware.
# **Prerequistes** 
Clone Repo:
```
sudo git clone https://github.com/Eric-Daugherty/Blink-LED-TEMP.git
```
Have g++ installed:
```
which g++
```
Should return:
```
/usr/bin/g++
```
If it says that it doesn't exist then execute the following:
```
sudo apt-get install mingw-w64
```
# **Installing**

You will need MINGW's g++ to compile blink.cpp. The PHP API is coded to use ./b so the following would need to be executed:
First step:
```
cd Blink
sudo g++ -Wall -o b blink.cpp -lwiringPi
```
Second step would be to move b to /web folder. Be sure that you are currently in the /Blink folder. (You should be from cd step taken above).
```
sudo cp b web/b
```
Third step, move web folder to /var/www/html. Be sure you are currently in the /Blink folder.
```
sudo cp -r web /var/www/html/web
```
Fix the securities. Allows website to execute C++.
```
sudo chmod 4755 /var/www/html/web/b
```
Should be able to test the front end or run the compiled blink.cpp
# **Running Tests**
Run ./b with different flags (s - status, o - on,f - off,b - blink twice,  u - user number of blinks, t - check temperature)
```
./b s
```
Run ./b without a flag and a menu will appear
```
./b
```
Try going onto the website while on the same network:
Find IP address of Raspberry Pi
```
ifconfig
```
Navigate to the following where x.x.x.x is Raspberry PI's Public IP address found above. (x.x.x.x = Public IP address)
```
https://x.x.x.x/web/
```
# **Documentation**
The documentation can be found within the Documentation folder of this project.



