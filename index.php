<?php
    $var1 = $_GET['SPEED'];
    $var2 = $_GET['RPM'];
    
    var_dump($_POST);
	
    $fileContent = "SPEED = ".$var1." RPM ".$var2."\n";

    $fileStatus = file_put_contents('data_file.txt', $fileContent, FILE_APPEND);

    if($fileStatus != false)
    {
        echo "Data written to file";
    }
    else    
    {
        echo "Failure";
    }
?>
