<html>
    <head>
        <title>Modify Names</title>
        <style>
            @import url('https://fonts.googleapis.com/css?family=Lacquer&display=swap');
        </style>
    </head>
    <body bgcolor="#483d8b">
        <font face="Lacquer" size="15" color="#ffffff">
            <center><u>Name Modification</u></center>
        </font>
        <?php
            $connect = mysqli_connect('localhost','root','','cmsa4');
            if($connect){
                echo "<font face=Lacquer size=6 color=#ffffff>"."Database Connected"."</font>"."<br/>";
            }
            else{
                echo "<font face=Lacquer size=6 color=#ffffff>"."*** Database not Connected ***"."<br/>";
            }
            //To modify the names
            $sql1 = "SELECT * FROM table4";
            $records = mysqli_query($connect,$sql1);
            $nrec = 0;
            while($rows = mysqli_fetch_array($records)){
                $name = $rows['name'];
                $name0 = trim($name);
                $pos = strrpos($name0," ");
                $name1 = substr($name0,$pos+1);
                $name2 = substr($name0,0,$pos);
                $modifiedname = $name1.", ".$name2;
                $sql2 = "UPDATE table4 SET modifiedname = '$modifiedname' WHERE name = '$name'";
                $results = mysqli_query($connect,$sql2);
                if($results){
                    echo "<font face=Lacquer size=6 color=#ffffff>"."Updated"."</font>"."<br/>";
                }
                else{
                    echo "<font face=Lacquer size=6 color=#ffffff>"."Not Updated"."</font>"."<br/>";
                }
                $nrec++;
            }
        ?>
    </body>
</html>
