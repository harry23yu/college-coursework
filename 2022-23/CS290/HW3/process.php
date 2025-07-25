<!DOCTYPE html>
<html lang="en">
<head lang="en">
	<meta charset="utf-8">
	<title>Harry Yu</title>
	<link rel="stylesheet" href="style.css">
</head>
<body>
	<header>
		<h1>Harry Yu</h1>
		<h2>GET Data</h2>
			<?php 
				if (count($_GET) == 0)
					echo "<p><em>There are no GET variables</em></p>";
				foreach ($_GET as $key => $value) { 
					echo "<strong>" . $key . "=</strong>" . $value . "</br>";
				}
			?>  

			<h2>POST Data</h2>
			<?php 
				if (count($_POST) == 0)
					echo "<p><em>There are no POST variables</em></p>";
				foreach ($_POST as $key => $value) { 
					echo "<strong>" . $key . "=</strong>" . $value . "</br>";
				}  
			?>
	</header>
	<nav class="links">
		<a href="index.html">Home</a> |
		<a href="form.html">Form</a>
	</nav>
	<footer>
        <p>Copyright © 2023 by Harry Yu</p>
    </footer>
</body>
</html>