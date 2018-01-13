<?php
  if ($_POST["submit"] ===  "OK" && $_POST["login"] && $_POST["oldpw"] && $_POST["newpw"]) {
    if (file_exists("../private/passwd")) {
      $users = unserialize(file_get_contents("../private/passwd"));
      $userInDB = NULL;
      $userInDBKey = NULL;
      foreach ($users as $key => $user) {
        if ($user["login"] === $_POST["login"]) {
          $userInDB = $user;
          $userInDBKey = $key;
        }
      }
      if ($userInDB && $userInDB["passwd"] === hash("sha256", $_POST["oldpw"])) {
        $users[$userInDBKey]["passwd"] = hash("sha256", $_POST["newpw"]);
        file_put_contents("../private/passwd", serialize($users));
        echo "OK\n";
      } else {
        echo "ERROR\n";
      }
    } else {
      echo "ERROR\n"; 
    }
  } else {
    echo "ERROR\n";
  }
?>