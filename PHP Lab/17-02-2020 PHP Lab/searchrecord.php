<!searchrecord.php : Write PHP Program to search a name in a table>
<html>
    <head><title>Program to Search a Name</title></head>
    <body bgcolor="#00ff66">
        <font face="impact" size="6" color="#000000">
            <center><u>Program to search a name in a Table</u></center>
            <table cellpadding=1 border=1 bordercolor=#000000 bgcolor="#ffffff" align="center">
                <tr>
                    <th colspan="5">
                        <font face="impact" size="6" color="#000000">List of records having </font>
                    </th>                    
                </tr>
                <tr>
                    <th><font face="impact" size="6" color="#000000">Emp-Code</font></th>
                    <th><font face="impact" size="6" color="#000000">Name</font></th>
                    <th><font face="impact" size="6" color="#000000">Salary</font></th>
                    <th><font face="impact" size="6" color="#000000">Phone</font></th>
                    <th><font face="impact" size="6" color="#000000">Email</font></th>
                </tr>
                <?php
                    //To connect database
                    $connect = mysqli_connect('localhost','root','','cmsa4');
                    if($connect){
                        echo "<font face=impact size=6 color=#000000>"."Database Connected"."</font>"."<br/>";
                    }
                    else{
                        echo "<font face=impact size=6 color=#000000>"."*** Database not Connected ***"."<br/>";
                    }
                    //To search records
                        $name = $_POST['name'];
                        $sql1 = "SELECT * FROM table3";
                        $records = mysqli_query($connect,$sql1);
                        $nrec=0; //$nrec = Number of records matching name field
                            while($rows=mysqli_fetch_array($records)){
                                echo "<tr>";
                                if($name==$rows['name']){
                                    echo "<td>"."<font face=impact size=6 color=#000000>".$rows['employeecode']."</font>"."</td>";
                                    echo "<td>"."<font face=impact size=6 color=#000000>".$rows['name']."</font>"."</td>";
                                    echo "<td>"."<font face=impact size=6 color=#000000>".$rows['salary']."</font>"."</td>";
                                    echo "<td>"."<font face=impact size=6 color=#000000>".$rows['phone']."</font>"."</td>";
                                    echo "<td>"."<font face=impact size=6 color=#000000>".$rows['email']."</font>"."</td>";
                                    $nrec++;
                                    echo "</table>";
                                }
                                echo "</tr>";
                            }
                        if($nrec!=0){
                            echo "<font face=impact size=6 color=#000000>"."Number of times $name found=$nrec"."</font>";
                        }
                        else{
                            echo "<font face=impact size=6 color=#000000>"."$name not Found"."</font>";
                        }
                        header("refresh:5;url=searchrecord.html");
                ?>
            </table>
        </font>
    </body>
</html>