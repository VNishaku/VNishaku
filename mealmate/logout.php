<?php
  session_start();
  session_unset();
  session_destroy();
  header("Location: index.php");
  exit;
?>
<!-- CREATE TABLE users (
  id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
  username VARCHAR(30) NOT NULL,
  password VARCHAR(30) NOT NULL
)
 -->