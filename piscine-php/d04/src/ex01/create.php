<?php
  function createAccount($login, $pwd) {
    $user = array(
      "login" => $login,
      "passwd" => hash("sha256", $pwd),
    );
    return $user;
  }

  if ($_POST["submit"] ===  "OK" && $_POST["login"] && $_POST["passwd"]) {
    if (file_exists("../private/passwd")) {
      $users = unserialize(file_get_contents("../private/passwd"));
      $user_already_exists = false;
      foreach ($users as $user) {
        if ($user["login"] === $_POST["login"]) {
          $user_already_exists = true;
        }
      }
      if ($user_already_exists) {
        echo "ERROR\n";
      } else {
        $users[] = createAccount($_POST["login"], $_POST["passwd"]);
        file_put_contents("../private/passwd", serialize($users));
        echo "OK\n";
      }
    } else {
      if (!file_exists("../private")) {
        mkdir("../private");
      }
      $users = array();
      $users[] = createAccount($_POST["login"], $_POST["passwd"]);
      file_put_contents("../private/passwd", serialize($users));
      echo "OK\n";
    }
  } else {
    echo "ERROR\n";
  }
?>