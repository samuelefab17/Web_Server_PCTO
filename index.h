#ifndef WEBPAGE_H
#define WEBPAGE_H

const char* webpage = R"=====(
<!DOCTYPE html>
<html>
<head>
    <title>ESP32 TEST</title>
</head>
<body>
    <h1>ESP32 Test</h1>
    <p>Rad: <span style="color: Rad;"><span id="Rad"></span></p>
    <script>
        function fetchRad() {
            fetch("/Rad")
                .then(response => response.text())
                .then(data => {
                    document.getElementById("Rad").textContent = data;
                });
        }

        fetchRad();
        setInterval(fetchRad, 1000); // Update temperature every 4 seconds
</script>
<p></p>
<p></p>
<canvas id="myCanvas" width="800" height="800"></canvas>
<script>
var canvas = document.getElementById("myCanvas"); // Seleziona l'elemento canvas
		var ctx = canvas.getContext("2d"); // Seleziona il contesto 2D

		var dati = [12, 19, 3, 5, 2, 3, 7]; // Dati per il grafico
		var labels = ["Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", "Giugno", "Luglio"]; // Etichette sull'asse x

		// Disegna il grafico
		ctx.beginPath();
		ctx.moveTo(0, 0);
		for (var i = 0; i < dati.length; i++) {
			var x = i * 60;
			var y = 600 - dati[i] * 10;
			ctx.lineTo(x, y);
			ctx.fillText(labels[i], x, 600);
			ctx.arc(x, y, 5, 0, Math.PI*2);
			ctx.fill();
		}
		ctx.stroke();
    </script>
    

</body>
</html>
)=====";

#endif