<?php

if (($handle = fopen("list.csv", "r"))) {
  $csv = array();
  while ($data = fgetcsv($handle, 0, ";")) {
    $csv[] = $data;
  }
  fclose($handle);
  $parsed = array();
  foreach ($csv as $value) {
    $parsed[] = $value[1];
  }
  exit(json_encode($parsed));
}

?>