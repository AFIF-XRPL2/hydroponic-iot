const express = require("express");
const http = require("http");
const { Server } = require("socket.io");
const cors = require("cors");

const app = express();
const server = http.createServer(app);

const io = new Server(server, {
  cors: {
    origin: "*",
  },
});

app.use(cors());
app.use(express.json());

// ===============================
// SIMPAN DATA TERAKHIR (STATE)
// ===============================
let lastSensorData = null;

// ===============================
// TEST ENDPOINT
// ===============================
app.get("/", (req, res) => {
  res.send("Backend IoT aktif 🚀");
});

// ===============================
// TERIMA DATA DARI ESP32
// ===============================
app.post("/api/sensor", (req, res) => {
  const data = req.body;

  // simpan data terakhir
  lastSensorData = data;

  console.log("Data dari ESP32:", lastSensorData);

  // kirim realtime ke semua client
  io.emit("sensor_update", lastSensorData);

  res.json({
    status: "success",
    message: "Data diterima backend",
    data: lastSensorData,
  });
});

// ===============================
// SOCKET.IO
// ===============================
io.on("connection", (socket) => {
  console.log("Client frontend terhubung");

  // ⬅️ INI KUNCI UTAMA
  // kirim data terakhir saat client baru connect
  if (lastSensorData) {
    socket.emit("sensor_update", lastSensorData);
  }

  socket.on("disconnect", () => {
    console.log("Client frontend terputus");
  });
});

// ===============================
// JALANKAN SERVER
// ===============================
server.listen(3000, () => {
  console.log("Server berjalan di http://localhost:3000");
});
