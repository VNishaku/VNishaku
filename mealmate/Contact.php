<?php
$insert = false;
if(isset($_POST['name'])){
    // Set connection variables
    $server = "localhost";
    $username = "root";
    $password = "";
    $db = "contact";
    $port=3306;

    // Create a database connection
    $con = mysqli_connect($server, $username, $password,$db);

    // Check for connection success
    if(!$con){
        die("connection to this database failed due to" . mysqli_connect_error());
    }
    // echo "Success connecting to the db";

    // Collect post variables
    $name = $_POST['name'];
    $email = $_POST['email'];
    $phone = $_POST['phone'];
    $message = $_POST['message'];
    $sql = "INSERT INTO details (`name`, `email`, `phone`, `message`, `date`) VALUES ('$name', '$email', '$phone', '$message', current_timestamp());";
    // echo $sql;

    // Execute the query
    if($con->query($sql) == true){
        // echo "Successfully inserted";

        // Flag for successful insertion
        $insert = true;
    }
    else{
        echo "ERROR: $sql <br> $con->error";
    }

    // Close the database connection
    $con->close();
}
?>
<!-- INSERT INTO `details` (`name`, `email`, `phone`, `message`, `date`, `sno`) 
VALUES ('tae', 'tea123@gmail.com', '9669660966', 'hii!!your website is so old model', CURRENT_TIMESTAMP, '1'); -->
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>MEALMATE - Contact Us</title>
  <link rel="stylesheet" href="style.css">
</head>
<body>
  <header>
    <nav>
      <ul>
        <li><a href="index.html">Home</a></li>
        <li><a href="Meal.html">Menu</a></li>
        <!-- <li><a href="order.html">Order Now</a></li> -->
        <li class="active"><a href="contact.html">Contact Us</a></li>
        <li><a href="FAQ.html">FAQ</a></li>
      </ul>
    </nav>
  </header>

  <section class="contact">
    <h1>Contact Us</h1>
    <?php
        if($insert == true){
        echo "<p class='submitMsg'>Thanks for submitting your form. We are happy to see you joining us for the US trip</p>";
        }
    ?>
        <form action="contact.php" method="post">
    <form>
      <label for="name">Name:</label>
      <input type="text" id="name" name="name" required>

      <label for="email">Email:</label>
      <input type="email" id="email" name="email" required>

      <label for="phone">Phone:</label>
      <input type="tel" id="phone" name="phone">

      <label for="message">Message:</label>
      <textarea id="message" name="message" required></textarea>

      <button type="submit">Send Message</button>
    </form>
  </section>
<style>body {
  margin: 0;
  font-family: Arial, sans-serif;
}

header {
  background-color: #333;
  color: #fff;
  padding: 10px;
}

nav ul {
  list-style: none;
  margin: 0;
  padding: 0;
}

nav li {
  display: inline-block;
  margin-right: 20px;
}

nav li:last-child {
  margin-right: 0;
}

nav a {
  color: #fff;
  text-decoration: none;
}

section.contact {
  max-width: 800px;
  margin: 50px auto;
  padding: 20px;
}

section.contact h1 {
  font-size: 36px;
  margin-bottom: 20px;
}

section.contact form {
  display: flex;
  flex-direction: column;
}

section.contact label {
  font-size: 18px;
  margin-bottom: 10px;
}

section.contact input,
section.contact textarea {
  font-size: 18px;
  padding: 10px;
  margin-bottom: 20px;
}

section.contact button {
  font-size: 18px;
  padding: 10px;
  background-color: #333;
  color: #fff;
  border: none;
  cursor: pointer;
}

footer {
  background-color: #eee;
  padding: 10px;
  text-align: center;
}

footer p {
  font-size: 14px;
  margin: 0;
}

.active {
  border-bottom: 2px solid #fff;
}

@media (max-width: 600px) {
  header {
    padding: 20px;
  }
  
  nav li {
    display: block;
    margin-bottom: 10px;
  }
}
</style>
  <footer>
    <p>&copy; 2023 MEALMATE. All rights reserved.</p>
  </footer>

  <script src="script.js"></script>
</body>
</html>
