<?php

if (($handle = fopen("list.csv", "r+"))) {
  $csv = array();
  while ($data = fgetcsv($handle, 0, ";")) {
    $csv[] = $data;
  }
  $parsed = array();
  foreach ($csv as $key => $value) {
    $newArr = array(
      0 => $value[0],
      1 => $value[1]
    );
    $parsed[] = $newArr;
  }
  fclose($handle);
  file_put_contents("list.csv", "");
  $handle = fopen("list.csv", "r+");
  $idOfDelete = $_GET['id'] === "-1" ? 0 : $_GET['id'];
  foreach ($parsed as $idx => $p) {
    if ($idx != $idOfDelete) {
      $newP = array();
      if ($idx > $idOfDelete) {
        $newP = array(
          0 => $p[0] - 1,
          1 => $p[1]
        );
      } else {
        $newP = $p;
      }
      fputcsv($handle, $newP, ";");
    }
  }
  exit(json_encode("OK"));
  fclose($handle);
}

?>