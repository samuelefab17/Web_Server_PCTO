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
          background-color: #Ffffff; 
        }
        h1 
        {
        color: red;
        font-size: 60px;
        text-align: center;
        }
    </style>
  </head>
  <body>
    <h1>TEST WEB SERVER</h1>
    <p><h2>Accelerometro: <span style="color: black;"><span id="acces"></span></h2></p>
    <p></p>
    <p><h2>Magnetometro: <span style="color: black;"><span id="magns"></span></h2></p>
    <script>
    function fetchacces() 
    {
      fetch("/acces")
      .then(response => response.text())
      .then(data => 
      {
        document.getElementById("acces").textContent = data;
      });
    }
    fetchacces();
    setInterval(fetchacces, 1000);

    function fetchmagns() 
    {
      fetch("/magns")
      .then(response => response.text())
      .then(data => 
      {
        document.getElementById("magns").textContent = data;
      });
    }
    fetchmagns();
    setInterval(fetchmagns, 1000);
    </script>
	  </div>
  </body>
</html>
)=====";

#endif