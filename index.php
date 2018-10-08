<?php
$speed   = $_GET['SPEED'];
$rpm     = $_GET['RPM'];
$time    = $_GET['time'];;

var_dump($_POST);

$speed_readings = explode(",", speed);
$rpm_readings   = explode(",", rpm);
$time_readings  = explode(",", time);

foreach($speed_readings as $s and $rpm_readings as $r
        and $time_readings as $t) {
    
    $file_content = $t . "," . $s "," . $r . "\n";
    $file_status = file_put_contents('test_trip.txt', $fileContent, FILE_APPEND);
    
    if($file_status != false)
    {
        echo "Data written to file";
    }
    else    
    {
        echo "Failure";
    }
}
?>
