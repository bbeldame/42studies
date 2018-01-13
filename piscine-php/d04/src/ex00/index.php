<?php
  session_start();
  if ($_GET["submit"] === "OK") {
    $_SESSION["login"] = $_GET["login"];
    $_SESSION["passwd"] = $_GET["passwd"];
  }
?>

<html>
<head>
  <meta charset="utf-8" />
  <title>Connecte toi</title>
</head>
<body>
  <form action="./index.php">
    Identifiant: <input type="text" name="login" value="<?php echo $_SESSION["login"] ?>" />
    <br />
    Mot de passe: <input type="password" name="passwd" value="<?php echo $_SESSION["passwd"] ?>" />
    <br />
    <input type="submit" value="OK" name="submit" />
  </form>
</body>
</html>