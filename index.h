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
    <p>Rad: <span style="color: red;"><span id="Rad"></span></p>
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
</body>
</html>
)=====";

#endif