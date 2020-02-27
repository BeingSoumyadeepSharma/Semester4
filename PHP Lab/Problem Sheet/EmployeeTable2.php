<html>
    <head>
        <title>Employee Table Search</title>
    </head>
    <body bgcolor="#520b52">
        <font face="Caviar Dreams" size="20" color="#cb1ccb">
            <center><u>Employee Database</u></center>
        </font>
        <br>
        <font face="Caviar Dreams" size="5" color="#cb1ccb">
            <?php
                $name = $_POST['name'];                
                //Connect to database
                $connect = mysqli_connect('localhost','root','','CMSA4');
                if($connect){
                    echo "Data base is Connected<br><br>";
                }
                else{
                    die("*** Database Not Connected ***");
                }
                $sql1 = "SELECT * FROM emp_salary";
                $result1 = mysqli_query($connect,$sql1);
                $recordcount = 0;
                if($result1){
                    echo "<table bgcolor=#ffffff border=3 bordercolor=#000000>";
                    echo "<tr>";
                    echo "<th>Employee Code</th>";
                    echo "<th>Name</th>";
                    echo "<th>Salary</th>";
                    echo "<th>Phone</th>";
                    echo "<th>Email</th>";
                    echo "</tr>";
                    while($rows = mysqli_fetch_array($result1)){
                        if($name == $rows['name']){
                            echo "<tr>";
                            echo "<td>".$rows['employeecode']."</td>";
                            echo "<td>".$rows['name']."</td>";
                            echo "<td>".$rows['salary']."</td>";
                            echo "<td>".$rows['phone']."</td>";
                            echo "<td>".$rows['email']."</td>";
                            echo "</tr>";
                            $recordcount++;    
                        }                                           
                    }
                    echo "</table>";
                    if($recordcount == 0){
                        die( "*** No records found ***");
                    }
                    else{
                        echo "Number of Records Found: ".$recordcount."<br/><br/>";
                    }               
                }
                else{
                    die("*** Failed to retrieve data ***");
                }
            ?>
            <a href="EmployeeTable.html" style="color: #ffffff;">Click to Search Another value...</a>
        </font>
    </body>
</html>
