# Auto Face Tracker

A simple yet powerful **Auto Face Tracker** system that uses **OpenCV** and an **Arduino-controlled stepper motor** to automatically follow a moving face. Perfect for learning about **computer vision**, **serial communication**, and **embedded systems**.

---

## 🧠 Project Overview

This project demonstrates how to make a camera automatically track a person’s face in real-time. The Python program detects the face using OpenCV and sends commands to an Arduino, which controls a stepper motor to rotate the camera left or right so that the face stays centered in view.

### ✨ Features

* Real-time face detection using OpenCV
* Automatic camera panning via Arduino stepper control
* Smooth, continuous face tracking
* Serial communication between Python and Arduino
* Easily extendable for dual-axis (pan/tilt) tracking

---

## ⚙️ How It Works

1. OpenCV detects faces from the webcam feed.
2. The system calculates how far the face is from the frame center.
3. That offset is converted to a rotation command.
4. A control signal is sent via serial communication to Arduino.
5. The Arduino moves the stepper motor to re-center the camera.

---

## 🧩 Components Used

| Component        | Example Model              | Description               |
| ---------------- | -------------------------- | ------------------------- |
| Webcam           | Logitech C270 / USB camera | Captures video frames     |
| Arduino          | Arduino Uno                | Receives serial commands  |
| Stepper Motor    | NEMA 17                    | Rotates the camera        |
| Motor Driver     | A4988 / DRV8825            | Drives the stepper motor  |
| Power Supply     | 12V DC                     | Powers motor              |
| Connecting wires | —                          | Connections between parts |

---

## 🪛 Setup Instructions

### 1️⃣ Install Dependencies

Create a Python environment and install the required packages:

```bash
pip install -r requirements.txt
```

### 2️⃣ Upload the Arduino Code

Upload `face_tracker.ino` to your Arduino board using the Arduino IDE.

### 3️⃣ Connect Hardware

* Wire your motor driver (A4988/DRV8825) to Arduino.
* Connect the motor and provide external power.
* Make sure Arduino and the computer share a ground.

### 4️⃣ Run the Python Script

```bash
python python/face_tracker.py
```

If everything is connected, the camera will begin tracking faces automatically.

---

## ⚙️ Configuration

You can modify these parameters in the Python script:

| Parameter              | Default | Description                        |
| ---------------------- | ------- | ---------------------------------- |
| `CAMERA_INDEX`         | 0       | Selects which webcam to use        |
| `CAMERA_FOV_DEG`       | 62.0    | Camera field of view in degrees    |
| `DEADZONE_PIX`         | 30      | Center tolerance (prevents jitter) |
| `MAX_STEPS_PER_UPDATE` | 600     | Limits large jumps per update      |
| `STEPS_PER_REV`        | 200     | Stepper steps per revolution       |
| `MICROSTEPPING`        | 16      | Microstepping factor               |

---

## 🧰 File Structure

```
Auto-Face-Tracker/
├── arduino/
│   └── face_tracker.ino
├── python/
│   └── face_tracker.py
├── requirements.txt
├── README.md
└── LICENSE
```

---

## 🚀 Future Improvements

* Add **vertical tracking** (dual-axis pan/tilt)
* Integrate **Mediapipe Face Detection** for better accuracy
* Implement **PID control** for smoother motion
* Add **non-blocking motor control** using AccelStepper

---

## 📄 License

MIT License © 2025

You’re free to use, modify, and distribute this project under the MIT License.

---

# 📦 requirements.txt

```
opencv-python
pyserial
numpy
```

---

# ✅ Quick Test Commands

To test your setup step by step:

```bash
# Check if your camera works
python -m cv2

# Test serial port connection
python -m serial.tools.list_ports

# Run the tracker
python python/face_tracker.py
```

---

### 🧑‍💻 Contributed by

**Gabriella & Team** — Bringing computer vision and robotics together 🤖💡
