<?php
function ft_split($str) {
	$arr = preg_split('/\ /', $str, NULL, PREG_SPLIT_NO_EMPTY);
	sort($arr);
	return $arr;
}
?>
