* {
  margin: 0;
  padding: 0;
  box-sizing: border-box;
}

html {
  scroll-behavior: smooth;
}

body {
  font-family: Arial, Helvetica, sans-serif;
  background: #f5f8fc;
  color: #172033;
  line-height: 1.6;
}

/* HEADER */

header {
  height: 72px;
  background: #102a43;
  color: white;

  display: flex;
  align-items: center;
  justify-content: space-between;

  padding: 0 7%;
}

.logo {
  font-size: 22px;
  font-weight: bold;
}

nav {
  display: flex;
  gap: 28px;
}

nav a {
  color: white;
  text-decoration: none;
  font-size: 14px;
}

nav a:hover {
  color: #8fd3ff;
}


/* HERO */

.hero {
  min-height: 620px;

  display: flex;
  align-items: center;

  padding: 70px 8%;

  background:
    linear-gradient(120deg, #102a43, #176b87);
  
  color: white;
}

.hero h1 {
  font-size: clamp(38px, 6vw, 72px);
  line-height: 1.05;
  margin: 15px 0 20px;
}

.tag {
  font-size: 13px;
  font-weight: bold;
  letter-spacing: 2px;
  color: #2388a9;
}

.hero .tag {
  color: #9eddf3;
}

.subtitle {
  max-width: 650px;
  color: #d8e7f2;
  font-size: 18px;
}

.buttons {
  margin-top: 35px;
  display: flex;
  gap: 15px;
  flex-wrap: wrap;
}


/* BUTTONS */

button {
  border: none;
  border-radius: 8px;
  padding: 13px 20px;

  background: #2388a9;
  color: white;

  font-size: 15px;
  font-weight: bold;

  cursor: pointer;
}

button:hover {
  opacity: .88;
}

.outline {
  background: transparent;
  border: 1px solid white;
}


/* SECTIONS */

.section {
  padding: 85px 8%;
}

.section h2 {
  font-size: 38px;
  margin: 8px 0 10px;
}

.description {
  color: #64748b;
}


/* SEARCH */

.search-box {
  margin-top: 30px;
  display: flex;
  max-width: 550px;
}

input,
select {
  width: 100%;
  padding: 14px;

  border: 1px solid #d6dee8;
  border-radius: 8px;

  font-size: 15px;
}

.search-box input {
  border-radius: 8px 0 0 8px;
}

.search-box button {
  border-radius: 0 8px 8px 0;
}


/* RESULT */

.result {
  max-width: 900px;

  margin-top: 30px;

  background: white;

  padding: 25px;

  border-radius: 15px;

  box-shadow: 0 8px 30px rgba(0,0,0,.08);
}

.result-head {
  display: flex;
  justify-content: space-between;
  align-items: center;
}

.small {
  color: #64748b;
  font-size: 12px;
}

.result h3 {
  font-size: 28px;
}

.status {
  font-weight: bold;
}

.safe,
.green {
  color: #159447;
}

.danger {
  color: #d62828;
}

.stats {
  display: grid;

  grid-template-columns:
    repeat(auto-fit, minmax(160px, 1fr));

  gap: 15px;

  margin-top: 25px;
}

.stat {
  background: #f5f8fc;
  padding: 20px;
  border-radius: 12px;
}

.stat span {
  font-size: 24px;
}

.stat small {
  display: block;
  color: #64748b;
}

.stat strong {
  font-size: 23px;
}


/* LIGHT SECTION */

.light {
  background: #eaf1f7;
}


/* FEATURES */

.feature-grid {
  margin-top: 35px;

  display: grid;

  grid-template-columns:
    repeat(auto-fit, minmax(250px, 1fr));

  gap: 20px;
}

.feature-card {
  background: white;
  padding: 30px;
  border-radius: 15px;

  box-shadow: 0 5px 20px rgba(0,0,0,.06);
}

.icon {
  font-size: 38px;
}

.feature-card h3 {
  margin: 12px 0;
}


/* ENERGY */

.energy-grid {
  margin-top: 35px;

  display: grid;

  grid-template-columns:
    repeat(auto-fit, minmax(220px, 1fr));

  gap: 20px;
}

.energy-card {
  background: white;

  padding: 28px;

  border-radius: 15px;
}

.energy-card span {
  font-size: 38px;
}

.energy-card strong {
  display: block;
  margin: 8px 0;
}


/* LOGIN */

.login-grid {
  margin-top: 35px;

  display: grid;

  grid-template-columns:
    repeat(auto-fit, minmax(280px, 1fr));

  gap: 25px;
}

.login-card {
  background: white;
  padding: 35px;

  border-radius: 15px;

  box-shadow: 0 5px 20px rgba(0,0,0,.06);
}

.big-icon {
  font-size: 45px;
}

.login-card h3 {
  margin: 10px 0;
  font-size: 25px;
}

.login-card button {
  margin-top: 20px;
}


/* MODAL */

.modal {
  position: fixed;

  inset: 0;

  background: rgba(0,0,0,.65);

  display: flex;
  align-items: center;
  justify-content: center;

  padding: 20px;

  z-index: 10;
}

.modal-box {
  background: white;

  width: 100%;
  max-width: 420px;

  padding: 30px;

  border-radius: 15px;

  position: relative;
}

.modal-box h2 {
  margin-bottom: 20px;
}

.modal-box input,
.modal-box select {
  margin-bottom: 12px;
}

.modal-box button:not(.close) {
  width: 100%;
}

.close {
  position: absolute;
  right: 15px;
  top: 10px;

  background: none;
  color: #172033;

  font-size: 28px;
  padding: 5px;
}


/* DASHBOARD */

.dashboard {
  background: #f5f8fc;
}

.dashboard-head {
  display: flex;
  justify-content: space-between;
  align-items: center;
}

.logout {
  background: #d62828;
}

.dashboard-cards {
  margin-top: 30px;

  display: grid;

  grid-template-columns:
    repeat(auto-fit, minmax(190px, 1fr));

  gap: 18px;
}

.dash-card {
  background: white;
  padding: 25px;
  border-radius: 12px;
}

.dash-card small {
  color: #64748b;
}

.dash-card strong {
  display: block;
  font-size: 34px;
  margin-top: 5px;
}

.emergency-card strong {
  color: #d62828;
}


/* TABLE */

.table-box {
  margin-top: 30px;

  background: white;

  padding: 25px;

  border-radius: 15px;

  overflow-x: auto;
}

table {
  width: 100%;
  border-collapse: collapse;

  margin-top: 20px;
}

th,
td {
  padding: 13px;

  text-align: left;

  border-bottom: 1px solid #e6ebf1;
}

th {
  color: #64748b;
  font-size: 13px;
}


/* EMERGENCY */

.emergency-monitor {
  margin-top: 25px;

  background: #fff4f4;

  border-left: 5px solid #d62828;

  padding: 25px;

  border-radius: 10px;
}

.emergency-monitor p {
  margin-top: 8px;
}


/* FOOTER */

footer {
  text-align: center;

  background: #102a43;

  color: white;

  padding: 40px 20px;
}

footer p {
  color: #c5d5e4;
}

.copyright {
  margin-top: 8px;
  font-size: 13px;
}


/* HIDDEN */

.hidden {
  display: none !important;
}


/* MOBILE */

@media(max-width: 650px) {

  header {
    height: auto;
    padding: 20px;
    flex-direction: column;
    gap: 15px;
  }

  nav {
    gap: 15px;
    flex-wrap: wrap;
    justify-content: center;
  }

  .hero {
    min-height: 550px;
    padding: 50px 7%;
  }

  .section {
    padding: 60px 6%;
  }

  .section h2 {
    font-size: 30px;
  }

  .search-box {
    flex-direction: column;
  }

  .search-box input,
  .search-box button {
    border-radius: 8px;
  }

  .search-box button {
    margin-top: 8px;
  }

  .dashboard-head {
    align-items: flex-start;
    gap: 15px;
  }

}