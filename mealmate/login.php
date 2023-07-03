<!DOCTYPE html>
<html>
<head>
  <title>Login Page</title>
  <link rel="stylesheet" type="text/css" href="style.css">
  <script src="script.js"></script>
</head>
<body>
  <div class="container">
    <form action="login.php" method="post" onsubmit="return validateLogin()">
      <h2>Login</h2>
      <label for="username"><b>Username</b></label>
      <input type="text" placeholder="Enter Username" name="username" id="username" required>
      <label for="password"><b>Password</b></label>
      <input type="password" placeholder="Enter Password" name="password" id="password" required>
      <button type="submit">Login</button>
      <p>Don't have an account? <a href="register.php">Register</a></p>
    </form>
  </div>
  <style>.container {
    margin: auto;
    width: 50%;
    border: 3px solid #73AD21;
    padding: 10px;
  }
  
  input[type=text], input[type=password] {
    width: 100%;
    padding: 12px 20px;
    margin: 8px 0;
    display: inline-block;
    border: 1px solid #ccc;
    box-sizing: border-box;
  }
  
  button {
    background-color: #4CAF50;
    color: white;
    padding: 14px 20px;
    margin: 8px 0;
    border: none;
    cursor: pointer;
    width: 100%;
  }
  
  button:hover {
    opacity: 0.8;
  }
  
  a {
    color: dodgerblue;
  }
  
  label {
    font-weight: bold;
  }
  
  .error {
    color: red;
  }
  </style>
</body>
<script>
	function validateLogin() {
  var username = document.getElementById("username").value;
  var password = document.getElementById("password").value;

  if (username.trim() == "") {
    document.getElementById("username").classList.add("error");
    return false;
  } else {
    document.getElementById("username").classList.remove("error");
  }

  if (password.trim() == "") {
    document.getElementById("password").classList.add("error");
    return false;
  } else {
    document.getElementById("password").classList.remove("error");
  }

  return true;
}
</script>
</html>
