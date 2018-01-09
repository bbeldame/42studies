#!/usr/bin/php
<?php
  $arr = preg_split('/\ /', $argv[1], NULL, PREG_SPLIT_NO_EMPTY);
  for ($i = 0; $i < count($arr); $i++)
  {
    echo $arr[$i];
    if ($i + 1 < count($arr))
    {
      echo " "; 
    }
  }
  if (count($arr) > 0)
    echo "\n";
?>
