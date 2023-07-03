<!DOCTYPE html>
<html>
<head>
  <title>Registration Page</title>
  <link rel="stylesheet" type="text/css" href="style.css">
  <script src="script.js"></script>
</head>
<body>
  <div class="container">
    <form action="register.php" method="post" onsubmit="return validateRegister()">
      <h2>Register</h2>
      <label for="username"><b>Username</b></label>
      <input type="text" placeholder="Enter Username" name="username" id="username" required>
      <label for="password"><b>Password</b></label>
      <input type="password" placeholder="Enter Password" name="password" id="password" required>
      <button type="submit">Register</button>
      <p>Already have an account? <a href="index.php">Login</a></p>
    </form>
  </div>
</body>
</html>
<?php
  $host = "localhost";
  $user = "root";
  $password = "";
  $database = "contact";
  $port=3306;

  $conn = mysqli_connect($host, $user, $password, $database);
  // $con = mysqli_connect($server, $username, $password,$db);

  if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
  }

  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = mysqli_real_escape_string($conn, $_POST["username"]);
    $password = mysqli_real_escape_string($conn, $_POST["password"]);

    $sql = "INSERT INTO users (username, password) VALUES ('$username', '$password')";

    if (mysqli_query($conn, $sql)) {
      header("Location: index.php");
      exit;
    } else {
      echo "Error: " . $sql . "<br>" . mysqli_error($conn);
    }
  }

  mysqli_close($conn);
?>
