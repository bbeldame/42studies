<?php
  function auth($login, $passwd) {
    if (file_exists("../private/passwd")) {
      $users = unserialize(file_get_contents("../private/passwd"));
      foreach ($users as $user) {
        if ($user["login"] === $login && $user["passwd"] === hash("sha256", $passwd)) {
          return true;
        }
      }
      return false;
    } else {
      return false;
    }
  }
?>