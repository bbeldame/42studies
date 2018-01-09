#!/usr/bin/php
<?php
  $arr = preg_split('/\ /', $argv[1], NULL, PREG_SPLIT_NO_EMPTY);
  for ($i = 1; $i < count($arr); $i++)
  {
    echo $arr[$i];
    echo " ";
  }
  if (count($arr) > 0)
  {
    echo $arr[0];
    echo "\n";
  }
?>
