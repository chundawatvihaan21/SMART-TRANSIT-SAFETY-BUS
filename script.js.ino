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
   ARDUINO USB SERIAL
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
      "Web Serial is not supported.\n\n" +
      "Please open this website in Google Chrome or Microsoft Edge on a laptop/PC."
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


    status.textContent =
      "● Arduino Connected";


    status.classList.add("connected");


    /* Start reading Arduino */

    readArduinoData();


    /* Wait briefly for Arduino startup */

    setTimeout(function() {

      updateLiveWebsite();

    }, 1000);


  } catch (error) {

    console.error(
      "Arduino connection error:",
      error
    );


    alert(
      "Arduino connection failed.\n\n" +
      "Make sure:\n" +
      "1. Arduino is connected by USB\n" +
      "2. Serial Monitor is CLOSED\n" +
      "3. You selected the correct COM port"
    );

  }

}


/* ==========================================
   READ ARDUINO SERIAL DATA
========================================== */

async function readArduinoData() {

  if (!serialPort) {
    return;
  }


  const decoder =
    new TextDecoderStream();


  serialPort.readable.pipeTo(
    decoder.writable
  );


  serialReader =
    decoder.readable.getReader();


  try {

    while (true) {

      const {
        value,
        done
      } = await serialReader.read();


      if (done) {
        break;
      }


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

  } catch (error) {

    console.error(
      "Serial reading error:",
      error
    );


    const status =
      document.getElementById(
        "arduinoStatus"
      );


    status.textContent =
      "● Arduino Disconnected";


    status.classList.remove(
      "connected"
    );

  }

}


/* ==========================================
   PROCESS ARDUINO DATA
========================================== */

function processArduinoLine(line) {

  if (!line) {
    return;
  }


  console.log(
    "Arduino:",
    line
  );


  /* PASSENGERS */

  if (
    line.startsWith("PASSENGERS:")
  ) {

    arduinoData.passengers =
      parseInt(
        line.split(":")[1]
      );

  }


  /* SEATS LEFT */

  else if (
    line.startsWith("SEATS_LEFT:")
  ) {

    arduinoData.seatsLeft =
      parseInt(
        line.split(":")[1]
      );

  }


  /* CAPACITY */

  else if (
    line.startsWith("CAPACITY:")
  ) {

    arduinoData.capacity =
      parseInt(
        line.split(":")[1]
      );

  }


  /* GATE */

  else if (
    line.startsWith("GATE:")
  ) {

    arduinoData.gate =
      line
        .split(":")[1]
        .trim()
        .toUpperCase();

  }


  /* EMERGENCY */

  else if (
    line.startsWith("EMERGENCY:")
  ) {

    arduinoData.emergency =
      line
        .split(":")[1]
        .trim()
        .toUpperCase();

  }


  /*
     IMPORTANT:

     Arduino sends:
     PASSENGERS
     SEATS_LEFT
     CAPACITY
     GATE
     EMERGENCY
     ----------------

     So website updates only
     after complete packet.
  */

  else if (
    line === "----------------"
  ) {

    updateLiveWebsite();

  }

}


/* ==========================================
   UPDATE WEBSITE WITH LIVE ARDUINO DATA
========================================== */

function updateLiveWebsite() {

  let busNumber =
    document
      .getElementById("busInput")
      .value
      .trim()
      .toUpperCase();


  /*
     If no bus number is entered,
     use RJ-01 for the Arduino model.
  */

  if (busNumber === "") {
    busNumber = "RJ-01";
  }


  /* Save live data */

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


  /* Show result */

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


  /* Status */

  let status =
    document.getElementById(
      "resultStatus"
    );


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


  /* Update dashboard */

  loadBusTable();


  /* Update emergency section */

  updateEmergencyMonitor();

}


/* ==========================================
   PUBLIC BUS SEARCH
========================================== */

function checkBus() {

  let busNumber =
    document
      .getElementById("busInput")
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
     show its LIVE data.
  */

  if (serialPort) {

    updateLiveWebsite();

    return;

  }


  /* Demo mode */

  let bus =
    buses[busNumber];


  if (!bus) {

    alert(
      "