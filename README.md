<h1>Arduino Temperatur- und Luftfeuchtigkeitsüberwachung</h1>

<h2>Beschreibung</h2>
<p>Dieses Arduino-Projekt verwendet einen DHT22-Sensor zur Messung der Temperatur und Luftfeuchtigkeit in der Umgebung. Es zeigt die gemessenen Werte auf einem LCD-Display an und nutzt außerdem ein TM1637-LED-Display zur Anzeige des maximal zulässigen Temperaturwerts, der durch ein Potentiometer eingestellt werden kann. Zusätzlich verwendet das Projekt drei LEDs (Rot, Grün, Blau), um den Temperaturzustand visuell darzustellen.</p>

<h2>Hardware-Komponenten</h2>
<ul>
  <li>Arduino Board (z.B. Arduino Uno)</li>
  <li>DHT22 Temperatur- und Luftfeuchtigkeitssensor</li>
  <li>LiquidCrystal_I2C LCD-Display</li>
  <li>TM1637 4-Digit 7-Segment-Display</li>
  <li>3 LEDs (Rot, Grün, Blau)</li>
  <li>1 Potentiometer</li>
  <li>Verschiedene Widerstände und Kabel</li>
</ul>

<h2>Schaltungsaufbau</h2>
<p>Details zum Anschluss der einzelnen Komponenten:</p>
<ul>
  <li><strong>DHT22 Sensor</strong>: Verbinden Sie den DHT22-Sensor mit dem digitalen Pin 12 des Arduino.</li>
  <li><strong>LCD-Display</strong>: Verbinden Sie das LCD über I2C mit dem Arduino.</li>
  <li><strong>TM1637 Display</strong>: Verbinden Sie CLK mit Pin 10 und DIO mit Pin 11.</li>
  <li><strong>LEDs</strong>: Verbinden Sie die Anoden der LEDs mit den Pins 4 (Rot), 5 (Grün) und 6 (Blau) über jeweils einen Vorwiderstand.</li>
  <li><strong>Potentiometer</strong>: Verbinden Sie das Potentiometer mit dem analogen Eingang A0.</li>
</ul>

<h2>Software-Anforderungen</h2>
<ul>
  <li>DHT Bibliothek</li>
  <li>LiquidCrystal_I2C Bibliothek</li>
  <li>TM1637TinyDisplay Bibliothek</li>
</ul>

<h2>Funktion</h2>
<p>Das System misst die Umgebungstemperatur und Luftfeuchtigkeit in regelmäßigen Abständen (alle 5 Sekunden). Die aktuelle Temperatur und Luftfeuchtigkeit werden auf dem LCD-Display angezeigt. Das TM1637-Display zeigt die maximale Temperatur an, die über das Potentiometer eingestellt wird. Die LEDs zeigen den Temperaturzustand an: Blau bei Unterschreitung der Mindesttemperatur, Rot bei Überschreitung der Maximaltemperatur und Grün bei normalen Bedingungen.</p>

<h2>Installation</h2>
<ol>
  <li>Installieren Sie die erforderlichen Bibliotheken über den Bibliotheksmanager in der Arduino-IDE.</li>
  <li>Laden Sie den bereitgestellten Code auf Ihr Arduino-Board hoch.</li>
  <li>Stellen Sie sicher, dass alle Komponenten gemäß dem Schaltungsdiagramm korrekt verbunden sind.</li>
</ol>

<h2>Verwendung</h2>
<p>Nach dem Hochladen des Codes und dem korrekten Anschluss der Hardware, beobachten Sie die Temperatur- und Luftfeuchtigkeitswerte auf dem LCD-Display und die Einstellung der maximalen Temperatur auf dem TM1637-Display. Passen Sie bei Bedarf den Wert der maximalen Temperatur mit dem Potentiometer an.</p>

<h2>Fehlerbehebung</h2>
<ul>
  <li>Überprüfen Sie alle Verbindungen, wenn der Sensor oder die Displays nicht ordnungsgemäß funktionieren.</li>
  <li>Stellen Sie sicher, dass alle erforderlichen Bibliotheken in der Arduino-IDE installiert sind.</li>
  <li>Überprüfen Sie die Serielle Ausgabe für Fehlermeldungen bei Problemen mit dem Sensor.</li>
</ul>
