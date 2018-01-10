#!/usr/bin/php
<?php
  if ($argc !== 4) {
    echo "Incorrect Parameters\n";
    exit;
  }
  $left = trim($argv[1]);
  $middle = trim($argv[2]);
  $right = trim($argv[3]);
  if ($middle === "+")
    echo $left + $right;
  if ($middle === "-")
    echo $left - $right;
  if ($middle === "*")
    echo $left * $right;
  if ($middle === "/")
    echo $left / $right;
  if ($middle === "%")
    echo $left % $right;
  echo "\n";
?>