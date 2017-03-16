<?php
function ft_split($str) {
	return (preg_split('/\ /', $str, NULL, PREG_SPLIT_NO_EMPTY));	
}
?>
