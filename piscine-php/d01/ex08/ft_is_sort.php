<?php

function ft_is_sort($arr) {
  $sorted_array = $arr;
  sort($sorted_array);
  foreach ($arr as $index => $value) {
    if ($value !== $sorted_array[$index]) {
      return false;
    }
  }
  return true;
}

?>