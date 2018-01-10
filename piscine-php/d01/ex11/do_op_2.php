#!/usr/bin/php
<?php
  function serr() {
    echo "Syntax Error\n";
    exit;
  }
  if ($argc !== 2) {
    echo "Incorrect Parameters\n";
    exit;
  }
  if (preg_match_all('/[\*\/+\-%]/', $argv[1]) !== 1)
    serr();
  $arr = preg_split('/[\*\/+\-%]/', $argv[1], NULL, PREG_SPLIT_NO_EMPTY);
  if (count($arr) !== 2)
    serr();
  $left = trim($arr[0]);
  $right = trim($arr[1]);
  if (!is_numeric($left) || !is_numeric($right))
    serr();
  if (strpos($argv[1], "+"))
    echo $left + $right;
  if (strpos($argv[1], "-"))
    echo $left - $right;
  if (strpos($argv[1], "*"))
    echo $left * $right;
  if (strpos($argv[1], "/"))
    echo $left / $right;
  if (strpos($argv[1], "%"))
    echo $left % $right;
  echo "\n";
?>