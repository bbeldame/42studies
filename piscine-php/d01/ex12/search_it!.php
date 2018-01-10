#!/usr/bin/php
<?php
  if ($argc < 2)
    exit;
  $arr = array();
  for ($i = 2; $i < $argc; $i++)
    $arr[] = explode(":", $argv[$i]);
  for ($i = count($arr); $i >= 0; $i--)
  {
    if ($arr[$i][0] === $argv[1]) {
      echo $arr[$i][1];
      echo "\n";
      exit;
    }
  }
?>