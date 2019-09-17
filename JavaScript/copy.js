function cop() {
          var target = document.getElementById("ans");
          target.select();
          document.execCommand("Copy");
          alert("copied! content: " + target.value);
}