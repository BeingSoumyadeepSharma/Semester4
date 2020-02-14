<html>
    <head>
        <title>Submission Page</title>
    </head>
    <body bgcolor="#006ad1">
        <font face="Times New Roman" color="white" size="10">
            <center><u>Student Data Submitted</u></center>
            <?php
                $stdname = $_POST['studname'];
                $gname = $_POST['gname'];
                $cnumber = $_POST['cnumber'];
                $addr = $_POST['address'];
                echo "Student Name: ".$stdname."<br/>";
                echo "Guardian's Name: ".$gname."<br/>";
                if(isset($_REQUEST["gender1"])){
                    echo "Gender: Male<br/>";
                }
                elseif(isset($_REQUEST["gender2"])){
                    echo "Gender: Female<br/>";
                }            
                echo "Contact Number: ".$cnumber."<br/>";
                echo "Address: ".$addr."<br/>";
                if(isset($_REQUEST["hobby1"])){
                    echo "Hobby: ".$_REQUEST["hobby1"]."<br/>";
                }
                if(isset($_REQUEST["hobby2"])){
                    echo "Hobby: ".$_REQUEST["hobby2"]."<br/>";
                }
                if(isset($_REQUEST["hobby3"])){
                    echo "Hobby: ".$_REQUEST["hobby3"]."<br/>";
                }
            ?>
        </font>
        <a href="542.html">Click to go back</a>       
    </body>
</html>