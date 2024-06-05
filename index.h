#ifndef WEBPAGE_H
#define WEBPAGE_H

const char* webpage = R"=====(
<!DOCTYPE html>
<html>
  <head>
      <title>ESP32 TEST</title>
    <style>
      body 
        {
          background-color: #fcfcc9; 
        }
	    .container 
      {
		    width: 1200px;
		    height: 600px;
	  	  display: flex;
	  	  align-items: flex-end;
	  	  background-color: #f0f0f0;
	    }
	    .barra 
      {
	  	  margin: 5px;
	  	  width: 100px;
	  	  height: calc(100% - 20px);
	  	  background-color: #6e9fc3;
	    }
    </style>
  </head>
  <body>
    <h1>ESP32 Test</h1>
    <p>Rad: <span style="color: Rad;"><span id="Rad"></span></p>
    <p>Rad: <span style="color: Rad1;"><span id="Rad1"></span></p>
    <script>
    function fetchRad() 
    {
      fetch("/Rad")
      .then(response => response.text())
      .then(data => 
      {
        document.getElementById("Rad").textContent = data;
      });
    }
    fetchRad();
    setInterval(fetchRad, 1000);
    </script>
    <p></p>
    <p></p>
    <div class="container">
		  <div class="barra" style="height: 80%;"></div>
		  <div class="barra" style="height: 60%;"></div>
		  <div class="barra" style="height: 40%;"></div>
		  <div class="barra" style="height: 70%;"></div>
		  <div class="barra" style="height: 50%;"></div>
		  <div class="barra" style="height: 30%;"></div>
		  <div class="barra" style="height: 90%;"></div>
		  <div class="barra" style="height: 10%;"></div>
		  <div class="barra" style="height: 35%;"></div>
		  <div class="barra" style="height: 45%;"></div>
		  <div class="barra" style="height: 86%;"></div>
	  </div>
  </body>
</html>
)=====";

#endif