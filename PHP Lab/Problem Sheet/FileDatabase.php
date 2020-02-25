<html>
	<head><title>File Database</title>
	<style>
		@import url('https://fonts.googleapis.com/css?family=Montserrat:400,500,600,700&display=swap');
	</style> 
	</head>
	<body bgcolor="#678cff">
		<font face="Montserrat" size="15" color="darkblue">
			<center><u>DATABASE MANAGEMENT SYSTEM</u></center>
		</font><br/>
		<font face="Montserrat" size="5" color="darkblue">
			<?php
				$name = $_POST['name'];
				$phone = $_POST['phone'];
				$email = $_POST['email'];
				$myfile = $_POST['myfile']; 
				$fiopp = fopen($myfile,"a") or die("*** Unable to open file ***");
				$text = "Name: ".$name.",\tPhone: ".$phone.",\tEmail: ".$email."\n";
				fwrite($fiopp,$text);
				fclose($fiopp);
				$fiop = fopen($myfile,"r") or die("*** Unable to open file ***");
				$num = 0;
				while(!feof($fiop)){
					echo fgets($fiop)."<br/>";
					$num++;
				}
				$num = $num - 1;
				echo "<br/>Number of Records: ".$num."<br/><br/>";		
			?>
			<a href="FileDatabase.html">Click here to redirect</a>
		</font>
	</body>
</html>
