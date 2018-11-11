---


---

<h1 id="temporizador-arduino">Temporizador Arduino</h1>
<p>Este esquema tiene como finalidad controlar un relé según el tiempo configurado de manera regresiva. Los materiales a usar se detallan a continuación:</p>
<ul>
<li>Arduino UNO R3</li>
<li>Buzzer</li>
<li>Relé 5V</li>
<li>LED x1</li>
<li>5 pulsadores</li>
<li>LCD 16x2</li>
</ul>
<h1 id="archivos">Archivos</h1>
<p>Los archivos que se encuentran el proyecto corresponden a diferente software. En la carpeta <strong>arduino</strong> se encuentra el código el archivo <strong>.hex</strong> que permitirá la simulación en <strong>proteus</strong>. En la carpeta <strong>proteus</strong> encontrará el esquema de simulación con los componentes necesarios y configuraciones adecuadas… Finalmente para una labor más didáctica está la carpeta <strong>fritzing</strong> que tiene el archivo de esquema conceptual para el proyecto.<br>
Es de vital importancia para el proyecto que instale las librerías utilizadas. Para el IDE de arduino necesitará: <strong>LiquidCrystal</strong></p>
<p>Para proteus necesitará del la librería <strong><a href="https://github.com/crixodia/arduino-temp-relay/blob/master/libraries/proteus/ARDUINO.LIB">ARDUINO.LIB</a></strong>. y se deberá instalar antes de cargar el archivo de simulación de proteus <strong>Proto.pdsprj</strong>.</p>
<p><strong>Nota:</strong> estos archivos se encuentran en la carpeta <strong><a href="https://github.com/crixodia/arduino-temp-relay/tree/master/libraries">libraries</a></strong> del proyecto como respaldo en caso de dificultades al instalar.</p>
<h2 id="arduino">Arduino</h2>
<p>El código se encuentra comentado para mejor legibilidad, además encontrará el archivo <strong><a href="https://github.com/crixodia/temporizador-arduino/blob/master/Temporizador/Temporizador.ino.standard.hex">.hex</a></strong> que <strong>deberá cargarlo siempre en proteus haciendo doble clic en el esquema de arduino</strong> y buscar la ruta en donde se encuentra.</p>
<h2 id="proteus">Proteus</h2>
<p><img src="https://lh3.googleusercontent.com/K83oOGnGD_sXUmlpOEflZtzCHU53HUKDt64QRv0LFN4FtdEk2GZmM5-FK5e4zhZF54jqFxHZBlL7=s770" alt="enter image description here" title="proteus-esc"></p>
<h1 id="recomendaciones">Recomendaciones</h1>
<ul>
<li>Para ejecutar este proyecto en hardware real. Por favor asegúrese de usar resistencias de 			protección en el diodo emisor de luz,  pantalla LCD.</li>
<li>Si bien puede usar cualquier potenciómetro, es recomendable de valor 10k.</li>
<li>Mantener localizado el archivo <strong>.hex</strong> en el arduino uno simulado en proteus.</li>
</ul>

