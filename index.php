<?php
    $speed   = $_GET['SPEED'];
    $rpm     = $_GET['RPM'];
    $voltage = $_GET['Voltage'];
    $time    = $_GET['time'];;
    
    var_dump($_POST);
	
    $fileContent = "Speed ".$speed." RPM ".$rpm." Voltage ".$voltage." time ".$time."\n";

    $fileStatus = file_put_contents('car_test.txt', $fileContent, FILE_APPEND);

    if($fileStatus != false)
    {
        echo "Data written to file";
    }
    else    
    {
        echo "Failure";
    }
?>
