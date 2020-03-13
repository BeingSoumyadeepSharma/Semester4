<?php
    error_reporting(0); // To suppress all warning message
?>
<!--imageupload1.php : Write a program to upload images in a folder-->
<html>
    <head><title>To Upload Images</title></head>
    <body bgcolor="#00ff66">
        <font face="impact" size="6" color="#000000">
            <center><u>Program to copy images from 1 folder to another</u></center>
            <form action="" method="POST" enctype="multipart/form-data">
                <input type="file" name="uploadfile" value="">
                <input type="submit" name="submit" value="UPLOAD IMAGE">
            </form>
        </font>
    </body>
</html>
<?php
    // Program to copy images from one folder to another folder
    $filename = $_FILES['uploadfile']['name'];
    $tempname = $_FILES['uploadfile']['tmp_name'];
    $folder = "myimage/".$filename;
    move_uploaded_file($tempname,$folder);
    echo "<center><a href=$folder><img src=$folder width=200 height=200 border=5></a><br/>";
    echo "<font face=impact size=6 color=#000000>".$folder."</center>";
?>
