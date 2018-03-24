<?php
    $var1 = $_GET['SPEED'];
    $var2 = $_GET['RPM'];

    $fileContent = "SPEED = " .$var1 " RPM " .$var2;

    $fileStatus = file_put_contents('data_file.txt', $fileContent, FILE_APPEND);
?>