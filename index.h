extern int rad;

char main_html[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
    <title>prova</title>
    <style>
        body {
            background-color: #fcfcc9; 
        }
    </style>
</head>
<body>
    <p><h1>)=====" + std::to_string(rad) + R"=====(</h1></p>
    
</body>
</html>
)=====";
