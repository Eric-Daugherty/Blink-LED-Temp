<html>
<body style="background-color: powderblue;">
        <navbar></navbar>
        <jumbotron></jumbotron>
        <div class='container'>
        <form  action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>" method="post">
        <fieldset class="form-group">
        <legend>Raspberry Pi Control Panel</legend>
            <div class="form-check">
                <label class="form-check-label">
                    <input type="radio" class="form-check-input" name="GPIOcontrol" id="optionsRadios1" value='s' checked>
                Check status of the light
                </label>
            </div>
            <div class="form-check">
                <label class="form-check-label">
                    <input type="radio" class="form-check-input" name="GPIOcontrol" id="optionsRadios2" value='o'>
                Turn on the light
                </label>
            </div>
            <div class="form-check disabled">
                <label class="form-check-label">
                    <input type="radio" class="form-check-input" name="GPIOcontrol" id="optionsRadios3" value='f'>
                Turn off the light
                </label>
            </div>
            <div class="form-check disabled">
                <label class="form-check-label">
                    <input type="radio" class="form-check-input" name="GPIOcontrol" id="optionsRadios3" value='b'>
                Blink Light Twice
                </label>
            </div>
            <div class="form-check disabled">
                <label class="form-check-label">
                    <input type="radio" class="form-check-input" name="GPIOcontrol" id="optionsRadios3" value='t'>
                Check the Temperature
                </label>
            </div>
        </fieldset>
        <button type="submit" class="btn btn-primary">Submit</button>
        </form>
        </div>
</body>
</html>

<?php

    $input = "";
    $output = "";
  if ($_SERVER["REQUEST_METHOD"] == "POST"){
    $input = "./b"." ".$_POST["GPIOcontrol"];

    exec($input, $output);
    if ($_POST["GPIOcontrol"]=='s')
       echo "<div class='container'>".$output[0]."</div>";
    if ($_POST["GPIOcontrol"]=='o')
       echo "<div class='container'>Turn Light On<br></div>";
    if ($_POST["GPIOcontrol"]=='f')
       echo "<div class='container'>Turn Light Off<br></div>";
    if ($_POST["GPIOcontrol"]=='t')
       echo "<div class='container'>".$output[0]."</div>";
    if ($_POST["GPIOcontrol"]=='b'){
       echo "<div class='container'>Light Blinked 2 Times<br></div>";      
    }
  }
?>