<?php
  session_start();
  include "./auth.php";

  $_SESSION["logged_on_user"] = "";
  if ($_GET["login"] && $_GET["passwd"]) {
    if (auth($_GET["login"], $_GET["passwd"])) {
      $_SESSION["logged_on_user"] = $_GET["login"];
      echo "OK\n";
    } else {
      echo "ERROR\n";
    }
  } else {
    echo "ERROR\n";
  }
?>