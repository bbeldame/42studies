#!/usr/bin/php
<?php
  $arr = array();
  function ft_split($a) {
    return preg_split('/\ /', $a, NULL, PREG_SPLIT_NO_EMPTY);
  }
  foreach ($argv as $idx => $value) {
    if ($idx > 0) {
      $arr = array_merge($arr, ft_split($value));
    }
  }
  sort($arr);
  for ($i = 0; $i < count($arr); $i++)
  {
    echo "$arr[$i]\n";
  }
?>
