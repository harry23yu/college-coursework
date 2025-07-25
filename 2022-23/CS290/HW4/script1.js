function drawTriangle(size) {

   // Your solution goes here
   for (let i = 1; i <= size; i++) {
      var triangle = "";
      for (let j = 1; j <= i; j++) {
        triangle += "*";
      }
      console.log(triangle);
   } 
}