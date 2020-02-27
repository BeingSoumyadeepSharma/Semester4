<html>
	<head><title>Word Extraction</title>
		<style>
		@import url('https://fonts.googleapis.com/css?family=Montserrat:400,500,600,700&display=swap');
		</style>
	</head>
	<body bgcolor="#ffa500">
		<font face="Montserrat" size="20" color="#ffffff">
			<center><u>Word Extractor</u></center>
		</font><br/>
		<font face="Montserrat" size="5" color="#ffffff">
			<?php
				$filen = $_POST['filename'];
				$outfilen = $_POST['outfilename'];
				$myfile1 = fopen($filen,"r") or die("*** Unable to open file ***");
				$myfile2 = fopen($outfilen,"a") or die("*** Unable to open file ***");
				if(feof($myfile1)){
					die("*** File is empty ***");
				}
				$nw = 0;
				$flag =1;
				while(!feof($myfile1)){
					$ch = fgetc($myfile1);
					$ch1 = strtoupper($ch);
					if($ch1>='A' && $ch1<='Z'){
						if($flag == 1){
							$nw++;
							$flag = 0;
						}
						echo $ch;
						fwrite($myfile2,$ch);
					}
					else if($flag == 0){
						echo "<br/>";
						fwrite($myfile2,"\n");
						$flag=1;;
					}
				}
				fclose($myfile2);
				fclose($myfile1);
				echo "Number of words: ".$nw."<br/>";
			?>
			<a href="WordExtract.html">Click here to redirect...</a>
		</font>
	</body>
</html>
