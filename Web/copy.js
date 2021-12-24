function cop(tar) {
          var target = document.getElementById(String(tar));
          target.select();
          document.execCommand("Copy");
}

/*ex:
<!DOCTYPE html>

<html lang="en" xmlns="http://www.w3.org/1999/xhtml">
<head>
    <meta charset="utf-8" />
    <title>test</title>

<script>
function cop(tar) {
          var target = document.getElementById(String(tar));
          target.select();
          document.execCommand("Copy");
}
</script>
</head>
<body>

<input id="temp"></input><input type="button" onclick="cop('temp')" value="test">

</body>
</html>
*/