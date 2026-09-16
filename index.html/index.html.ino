<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Smart Transit Safety Network</title>
  <link rel="stylesheet" href="style.css">
</head>

<body>

<header>
  <div class="logo">🚌 STSN</div>

  <nav>
    <a href="#home">Home</a>
    <a href="#public">Bus Status</a>
    <a href="#features">Features</a>
    <a href="#admin">Admin</a>
  </nav>
</header>

<!-- HOME -->
<section id="home" class="hero">
  <div>
    <p class="tag">DIGITAL PUBLIC TRANSPORT SAFETY</p>

    <h1>Safety & Digital Innovation<br>in Public Transit</h1>

    <p class="subtitle">
      Smart monitoring • Accident prevention • Emergency rescue • Sustainable energy
    </p>

    <div class="buttons">
      <button onclick="goTo('public')">Check Bus Status</button>
      <button class="outline" onclick="goTo('admin')">Admin Login</button>
    </div>
  </div>
</section>


<!-- PUBLIC BUS STATUS -->
<section id="public" class="section">

  <p class="tag">PUBLIC ACCESS</p>
  <h2>Check Bus Safety Status</h2>

  <p class="description">
    Enter a bus number to view its current safety information.
  </p>

  <div class="search-box">
    <input id="busInput" placeholder="Example: RJ-01">
    <button onclick="checkBus()">Check Bus</button>
  </div>


  <!-- ARDUINO LIVE CONNECTION -->
  <div class="arduino-connect">

    <button onclick="connectArduino()">
      🔌 Connect Arduino
    </button>

    <span id="arduinoStatus">
      ● Arduino Not Connected
    </span>

  </div>


  <!-- LIVE DATA -->
  <div id="busResult" class="result hidden">

    <div class="result-head">

      <div>
        <span class="small">BUS NUMBER</span>
        <h3 id="resultBus">RJ-01</h3>
      </div>

      <span id="resultStatus" class="status safe">
        ● SAFE
      </span>

    </div>


    <div class="stats">

      <div class="stat">
        <span>👥</span>
        <small>Passengers</small>
        <strong id="resultPassengers">0 / 5</strong>
      </div>

      <div class="stat">
        <span>💺</span>
        <small>Seats Left</small>
        <strong id="resultSeats">5</strong>
      </div>

      <div class="stat">
        <span>🚪</span>
        <small>Gate</small>
        <strong id="resultGate">CLOSED</strong>