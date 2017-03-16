#!/usr/bin/php
<?php
while (1) {
	echo 'Entrez un nombre: ';
	$handle = fopen('php://stdin', 'r');
	$input = fgets($handle);
	if (feof($handle) == TRUE)
		exit();
	$input = trim($input);
	if (is_numeric($input)) {
		if ($input % 2 == 0) {
			echo "Le chiffre $input est Pair\n";
		} else {
			echo "Le chiffre $input est Impair\n";
		}
	} else {
		echo "'$input' n'est pas un chiffre\n";
	}
}
?>
