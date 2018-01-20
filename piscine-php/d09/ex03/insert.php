<?php

if (($handle = fopen("list.csv", "r+"))) {
  $csv = array();
  while ($data = fgetcsv($handle, 0, ";")) {
    $csv[] = $data;
  }
  $parsed = array(
    array(
      0 => 0,
      1 => $_GET['value']
    )
  );
  foreach ($csv as $key => $value) {
    $newArr = array(
      0 => $value[0] + 1,
      1 => $value[1]
    );
    $parsed[] = $newArr;
  }
  ftruncate($handle);
  rewind($handle);
  foreach ($parsed as $p) {
    fputcsv($handle, $p, ";");
  }
  exit(json_encode("OK"));
  fclose($handle);
}

?>