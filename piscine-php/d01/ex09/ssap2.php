#!/usr/bin/php
<?php
  $arr = array();

  function ft_split($a) {
    return preg_split('/\ /', $a, NULL, PREG_SPLIT_NO_EMPTY);
  }

  function ft_get_strings($array) {
    $to_return = array();
    foreach ($array as $key => $value) {
      if (ctype_alpha($value))
        $to_return[] = $value;
    }
    return $to_return;
  }

  function ft_get_numbers($array) {
    $to_return = array();
    foreach ($array as $key => $value) {
      if (ctype_digit($value))
        $to_return[] = $value;
    }
    sort($to_return, SORT_STRING);
    return $to_return;
  }

  function ft_get_others($array, $final_array) {
    $to_return = array();
    foreach ($array as $key => $value) {
      if (!in_array($value, $final_array, true))
        $to_return[] = $value;
    }
    return $to_return;
  }

  foreach ($argv as $idx => $value) {
    if ($idx > 0) {
      $arr = array_merge($arr, ft_split($value));
    }
  }

  sort($arr, SORT_NATURAL | SORT_FLAG_CASE);
  $final_array = array();
  $final_array = array_merge($final_array, ft_get_strings($arr));
  $final_array = array_merge($final_array, ft_get_numbers($arr));
  $final_array = array_merge($final_array, ft_get_others($arr, $final_array));

  for ($i = 0; $i < count($final_array); $i++)
  {
    echo "$final_array[$i]\n";
  }
?>