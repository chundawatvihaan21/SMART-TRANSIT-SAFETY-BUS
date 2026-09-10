/* ==========================================
   SMART TRANSIT SAFETY NETWORK
   DEMO JAVASCRIPT
========================================== */


/* SAMPLE BUS DATA */

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


/* GO TO SECTION */

function goTo(id) {

  document.getElementById(id).scrollIntoView({
    behavior: "smooth"
  });

}


/* PUBLIC BUS SEARCH */

function checkBus() {

  let busNumber =
    document.getElementById("busInput")
    .value
    .trim()
    .toUpperCase();

  if (busNumber === "") {

    alert("Please enter a bus number.");

    return;
  }


  let bus = buses[busNumber];


  if (!bus) {

    alert(
      "Bus not found in demo database.\n\nTry RJ-01, RJ-02, RJ-03 or GJ-01."
    );

    return;
  }


  document.getElementById("busResult")
    .classList.remove("hidden");


  document.getElementById("resultBus")
    .textContent = busNumber;


  document.getElementById("resultPassengers")
    .textContent =
    bus.passengers + " / " + bus.capacity;


  document.getElementById("resultSeats")
    .textContent =
    bus.capacity - bus.passengers;


  document.getElementById("resultGate")
    .textContent =
    bus.gate;


  document.getElementById("resultEmergency")
    .textContent =
    bus.emergency;


  let status =
    document.getElementById("resultStatus");


  if (bus.passengers >= bus.capacity) {

    status.textContent = "● FULL";
    status.className = "status danger";

  } else {

    status.textContent = "● SAFE";
    status.className = "status safe";

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
      .textContent = "👑 Main Admin Login";

    document
      .getElementById("stateSelect")
      .style.display = "none";

  } else {

    document
      .getElementById("loginTitle")
      .textContent = "🏛️ State Admin Login";

    document
      .getElementById("stateSelect")
      .style.display = "block";

  }

}


function closeLogin() {

  document
    .getElementById("loginModal")
    .classList.add("hidden");

}


/* LOGIN */

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

    showDashboard("🇮🇳 National Main Admin");

  }


  /* RAJASTHAN */

  else if (
    loginType === "state" &&
    selectedState === "rajasthan" &&
    id === "rajasthan" &&
    password === "raj123"
  ) {

    valid = true;

    showDashboard("🏛️ Rajasthan Transport Safety");

  }


  /* GUJARAT */

  else if (
    loginType === "state" &&
    selectedState === "gujarat" &&
    id === "gujarat" &&
    password === "guj123"
  ) {

    valid = true;

    showDashboard("🏛️ Gujarat Transport Safety");

  }


  /* MAHARASHTRA */

  else if (
    loginType === "state" &&
    selectedState === "maharashtra" &&
    id === "maharashtra" &&
    password === "mah123"
  ) {

    valid = true;

    showDashboard("🏛️ Maharashtra Transport Safety");

  }


  /* MADHYA PRADESH */

  else if (
    loginType === "state" &&
    selectedState === "madhya" &&
    id === "madhya" &&
    password === "mp123"
  ) {

    valid = true;

    showDashboard("🏛️ Madhya Pradesh Transport Safety");

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


/* SHOW DASHBOARD */

function showDashboard(title) {

  closeLogin();


  document
    .getElementById("dashboard")
    .classList.remove("hidden");


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


/* BUS TABLE */

function loadBusTable() {

  let table =
    document.getElementById("busTable");


  table.innerHTML = "";


  Object.keys(buses).forEach(function(busNumber) {

    let bus = buses[busNumber];

    let seats =
      bus.capacity - bus.passengers;


    let status =
      bus.passengers >= bus.capacity
        ? '<span class="danger">● FULL</span>'
        : '<span class="green">● SAFE</span>';


    let row = `
      <tr>

        <td><b>${busNumber}</b></td>

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


/* LOGOUT */

function logout() {

  document
    .getElementById("dashboard")
    .classList.add("hidden");

  window.scrollTo({
    top: 0,
    behavior: "smooth"
  });

}
