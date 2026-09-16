/* ==========================================
SMART TRANSIT SAFETY NETWORK
ARDUINO USB LIVE + DEMO JAVASCRIPT
========================================== */

/* ==========================================
SAMPLE BUS DATA
========================================== */

const buses = {

"RJ-01": {
passengers: 4,
capacity: 5,
gate: "OPEN",
emergency: "NORMAL"
},

"RJ-02": {
passengers: 5,
capacity: 5,
gate: "LOCKED",
emergency: "NORMAL"
},

"RJ-03": {
passengers: 3,
capacity: 5,
gate: "OPEN",
emergency: "NORMAL"
},

"GJ-01": {
passengers: 2,
capacity: 5,
gate: "OPEN",
emergency: "NORMAL"
}

};

/* ==========================================
ARDUINO LIVE DATA
========================================== */

let serialPort = null;
let serialReader = null;
let serialBuffer = "";

let arduinoData = {
passengers: 0,
seatsLeft: 5,
capacity: 5,
gate: "CLOSED",
emergency: "NORMAL"
};

/* ==========================================
GO TO SECTION
========================================== */

function goTo(id) {

document.getElementById(id).scrollIntoView({
behavior: "smooth"
});

}

/* ==========================================
CONNECT ARDUINO
========================================== */

async function connectArduino() {

if (!("serial" in navigator)) {

alert(
  "Web Serial is not supported in this browser.\n\n" +
  "Please use Google Chrome or Microsoft Edge on a computer."
);

return;

}

try {

serialPort = await navigator.serial.requestPort();

await serialPort.open({
  baudRate: 9600
});


const status =
  document.getElementById("arduinoStatus");

status.textContent = "● Arduino Connected";
status.classList.add("connected");


readArduinoData();

}

catch (error) {

console.error(error);

alert(
  "Arduino connection failed.\n\n" +
  "Make sure the Arduino is connected by USB."
);

}

}

/* ==========================================
READ ARDUINO SERIAL DATA
========================================== */

async function readArduinoData() {

if (!serialPort) return;

const decoder =
new TextDecoderStream();

const inputDone =
serialPort.readable.pipeTo(decoder.writable);

serialReader =
decoder.readable.getReader();

try {

while (true) {

  const { value, done } =
    await serialReader.read();


  if (done) break;


  if (value) {

    serialBuffer += value;


    let lines =
      serialBuffer.split("\n");


    serialBuffer =
      lines.pop();


    lines.forEach(function(line) {

      processArduinoLine(
        line.trim()
      );

    });

  }

}

}

catch (error) {

console.error(
  "Serial reading error:",
  error
);

}

}

/* ==========================================
PROCESS ARDUINO DATA
========================================== */

function processArduinoLine(line) {

if (!line) return;

console.log(
"Arduino:",
line
);

/* PASSENGERS */

if (line.startsWith("PASSENGERS:")) {

arduinoData.passengers =
  parseInt(
    line.split(":")[1]
  );

}

/* SEATS LEFT */

else if (line.startsWith("SEATS_LEFT:")) {

arduinoData.seatsLeft =
  parseInt(
    line.split(":")[1]
  );

}

/* CAPACITY */

else if (line.startsWith("CAPACITY:")) {

arduinoData.capacity =
  parseInt(
    line.split(":")[1]
  );

}

/* GATE */

else if (line.startsWith("GATE:")) {

arduinoData.gate =
  line.split(":")[1]
    .trim()
    .toUpperCase();

}

/* EMERGENCY */

else if (line.startsWith("EMERGENCY:")) {

arduinoData.emergency =
  line.split(":")[1]
    .trim()
    .toUpperCase();

}

/*
Once all data is received,
update website.
*/

updateLiveWebsite();

}

/* ==========================================
UPDATE LIVE WEBSITE
========================================== */

function updateLiveWebsite() {

const busNumber =
document.getElementById("busInput").value
.trim()
.toUpperCase() || "RJ-01";

/*
Update local bus data
*/

buses[busNumber] = {

passengers:
  arduinoData.passengers,

capacity:
  arduinoData.capacity,

gate:
  arduinoData.gate,

emergency:
  arduinoData.emergency

};

/*
Update public bus result
*/

document
.getElementById("busResult")
.classList.remove("hidden");

document
.getElementById("resultBus")
.textContent =
busNumber;

document
.getElementById("resultPassengers")
.textContent =
arduinoData.passengers +
" / " +
arduinoData.capacity;

document
.getElementById("resultSeats")
.textContent =
arduinoData.seatsLeft;

document
.getElementById("resultGate")
.textContent =
arduinoData.gate;

document
.getElementById("resultEmergency")
.textContent =
arduinoData.emergency;

/*
STATUS
*/

const status =
document.getElementById("resultStatus");

if (
arduinoData.emergency === "YES"
) {

status.textContent =
  "● EMERGENCY";

status.className =
  "status danger";

}

else if (
arduinoData.passengers >=
arduinoData.capacity
) {

status.textContent =
  "● FULL";

status.className =
  "status danger";

}

else {

status.textContent =
  "● SAFE";

status.className =
  "status safe";

}

/*
Update dashboard table
*/

loadBusTable();

/*
Update emergency monitor
*/

updateEmergencyMonitor();

}

/* ==========================================
PUBLIC BUS SEARCH
========================================== */

function checkBus() {

let busNumber =
document.getElementById("busInput")
.value
.trim()
.toUpperCase();

if (busNumber === "") {

alert(
  "Please enter a bus number."
);

return;

}

/*
If Arduino is connected,
show LIVE Arduino data.
*/

if (serialPort) {

updateLiveWebsite();

return;

}

/*
Otherwise use demo data.
*/

let bus =
buses[busNumber];

if (!bus) {

alert(
  "Bus not found in demo database.\n\n" +
  "Try RJ-01, RJ-02, RJ-03 or GJ-01."
);

return;

}

document
.getElementById("busResult")
.classList.remove("hidden");

document
.getElementById("resultBus")
.textContent =
busNumber;

document
.getElementById("resultPassengers")
.textContent =
bus.passengers +
" / " +
bus.capacity;

document
.getElementById("resultSeats")
.textContent =
bus.capacity -
bus.passengers;

document
.getElementById("resultGate")
.textContent =
bus.gate;

document
.getElementById("resultEmergency")
.textContent =
bus.emergency;

const status =
document.getElementById("resultStatus");

if (
bus.emergency === "YES"
) {

status.textContent =
  "● EMERGENCY";

status.className =
  "status danger";

}

else if (
bus.passengers >=
bus.capacity
) {

status.textContent =
  "● FULL";

status.className =
  "status danger";

}

else {

status.textContent =
  "● SAFE";

status.className =
  "status safe";

}

}

/* ==========================================
LOGIN SYSTEM
========================================== */

let loginType = "state";

function openLogin(type) {

loginType = type;

document
.getElementById("loginModal")
.classList.remove("hidden");

document
.getElementById("loginMessage")
.textContent = "";

if (type === "main") {

document
  .getElementById("loginTitle")
  .textContent =
  "👑 Main Admin Login";


document
  .getElementById("stateSelect")
  .style.display =
  "none";

}

else {

document
  .getElementById("loginTitle")
  .textContent =
  "🏛️ State Admin Login";


document
  .getElementById("stateSelect")
  .style.display =
  "block";

}

}

/* ==========================================
CLOSE LOGIN
========================================== */

function closeLogin() {

document
.getElementById("loginModal")
.classList.add("hidden");

}

/* ==========================================
LOGIN
========================================== */

function login() {

let id =
document
.getElementById("loginId")
.value
.trim()
.toLowerCase();

let password =
document
.getElementById("loginPassword")
.value;

let selectedState =
document
.getElementById("stateSelect")
.value;

let valid = false;

/* MAIN ADMIN */

if (
loginType === "main" &&
id === "mainadmin" &&
password === "demo123"
) {

valid = true;

showDashboard(
  "🇮🇳 National Main Admin"
);

}

/* RAJASTHAN */

else if (
loginType === "state" &&
selectedState === "rajasthan" &&
id === "rajasthan" &&
password === "raj123"
) {

valid = true;

showDashboard(
  "🏛️ Rajasthan Transport Safety"
);

}

/* GUJARAT */

else if (
loginType === "state" &&
selectedState === "gujarat" &&
id === "gujarat" &&
password === "guj123"
) {

valid = true;

showDashboard(
  "🏛️ Gujarat Transport Safety"
);

}

/* MAHARASHTRA */

else if (
loginType === "state" &&
selectedState === "maharashtra" &&
id === "maharashtra" &&
password === "mah123"
) {

valid = true;

showDashboard(
  "🏛️ Maharashtra Transport Safety"
);

}

/* MADHYA PRADESH */

else if (
loginType === "state" &&
selectedState === "madhya" &&
id === "madhya" &&
password === "mp123"
) {

valid = true;

showDashboard(
  "🏛️ Madhya Pradesh Transport Safety"
);

}

if (!valid) {

document
  .getElementById("loginMessage")
  .textContent =
  "❌ Invalid ID or password.";


document
  .getElementById("loginMessage")
  .style.color =
  "#d62828";

}

}

/* ==========================================
SHOW DASHBOARD
========================================== */

function showDashboard(title) {

closeLogin();

document
.getElementById("dashboard")
.classList
.remove("hidden");

document
.getElementById("dashboardTitle")
.textContent =
title;

loadBusTable();

document
.getElementById("dashboard")
.scrollIntoView({
behavior: "smooth"
});

}

/* ==========================================
BUS TABLE
========================================== */

function loadBusTable() {

let table =
document.getElementById("busTable");

if (!table) return;

table.innerHTML = "";

Object.keys(buses)
.forEach(function(busNumber) {

  let bus =
    buses[busNumber];


  let seats =
    bus.capacity -
    bus.passengers;


  let status;


  if (
    bus.emergency === "YES"
  ) {

    status =
      '<span class="danger">● EMERGENCY</span>';

  }

  else if (
    bus.passengers >=
    bus.capacity
  ) {

    status =
      '<span class="danger">● FULL</span>';

  }

  else {

    status =
      '<span class="green">● SAFE</span>';

  }


  let row = `

    <tr>

      <td>
        <b>${busNumber}</b>
      </td>

      <td>
        ${bus.passengers}/${bus.capacity}
      </td>

      <td>
        ${seats}
      </td>

      <td>
        ${bus.gate}
      </td>

      <td>
        ${status}
      </td>

    </tr>

  `;


  table.innerHTML += row;

});

}

/* ==========================================
EMERGENCY MONITOR
========================================== */

function updateEmergencyMonitor() {

const monitor =
document.querySelector(
".emergency-monitor"
);

if (!monitor) return;

if (
arduinoData.emergency === "YES"
) {

monitor.innerHTML = `

  <h3>🚨 Emergency Monitoring</h3>

  <p>
    Emergency sensor status:
    <strong class="danger">
      EMERGENCY DETECTED
    </strong>
  </p>

  <p>
    Emergency Exit:
    <strong class="green">
      OPEN
    </strong>
  </p>

`;

}

else {

monitor.innerHTML = `

  <h3>🚨 Emergency Monitoring</h3>

  <p>
    Emergency sensor status:
    <strong class="green">
      NORMAL
    </strong>
  </p>

  <p>
    Emergency Exit:
    <strong class="green">
      READY
    </strong>
  </p>

`;

}

}

/* ==========================================
LOGOUT
========================================== */

function logout() {

document
.getElementById("dashboard")
.classList
.add("hidden");

window.scrollTo({

top: 0,

behavior: "smooth"

});

}
