<html>
    <head>
        <title>Employee Table</title>
    </head>
    <body bgcolor="#520b52">
        <font face="Caviar Dreams" size="20" color="#cb1ccb">
            <center><u>Employee Database</u></center>
        </font>
        <br>
        <font face="Caviar Dreams" size="5" color="#cb1ccb">
            <?php
                $empcode = $_POST['employeecode'];
                $name = $_POST['name'];
                $salary = $_POST['salary'];
                $phone = $_POST['phone'];
                $email = $_POST['email'];
                //Connect to database
                $connect = mysqli_connect('localhost','root','','CMSA4');
                if($connect){
                    echo "Data base is Connected<br>";
                }
                else{
                    die("*** Database Not Connected ***");
                }
                $sql1 = "INSERT INTO emp_salary VALUES ('$empcode','$name','$salary','$phone','$email')";
                $result1 = mysqli_query($connect,$sql1);
                if($result1){
                    echo "~~~~ Insertion Complete ~~~~<br>";
                }
                else{
                    die("*** Insertion Unsuccessfull***");
                }
                $sql2 = "SELECT * FROM emp_salary";
                $result2 = mysqli_query($connect,$sql2);
                if($result2){
                    echo "<table bgcolor=#ffffff border=3 bordercolor=#000000>";
                    echo "<tr>";
                    echo "<th>Employee Code</th>";
                    echo "<th>Name</th>";
                    echo "<th>Salary</th>";
                    echo "<th>Phone</th>";
                    echo "<th>Email</th>";
                    echo "</tr>";
                    while($rows = mysqli_fetch_array($result2)){                        
                        echo "<tr>";
                        echo "<td>".$rows['employeecode']."</td>";
                        echo "<td>".$rows['name']."</td>";
                        echo "<td>".$rows['salary']."</td>";
                        echo "<td>".$rows['phone']."</td>";
                        echo "<td>".$rows['email']."</td>";
                        echo "</tr>";                        
                    }
                    echo "</table>";                    
                }
                else{
                    die("*** Failed to retrieve data ***");
                }
            ?>
            <a href="EmployeeTable.html">Click to Insert more values...</a>
        </font>
    </body>
</html>