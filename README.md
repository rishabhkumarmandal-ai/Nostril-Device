# 🌬️ Alternate Nostril Breathing IoT Device

This project integrates a mobile app with a BLE-powered IoT actuator to guide users through **Alternate Nostril Breathing (ANB)** techniques like *Anulom Vilom*, *Nadi Shodhan*, and more — fully hands-free.

## 📱 Mobile App Features

- Firebase Auth (Email & Google Sign-In)
- Breathing Modes: Anulom Vilom, Surya Bhedi, etc.
- BLE device pairing & real-time control
- Instructions, timers, and session history
- Device calibration and customization
- Notifications & sharing options

## 🔩 IoT Hardware Features

- Powered by **ESP32 + BLE**
- Two micro-servo actuators to control nostril occlusion
- Configurable through app commands (LEFT, RIGHT, OFF)
- Battery-powered with TP4056 charging module
- Custom-fit calibration system via BLE

---

## 🧠 Circuit Diagram

![Circuit Diagram](./A_schematic_circuit_diagram.png)

---

## 📦 Components Used

| Component         | Specs / Model           |
|------------------|--------------------------|
| ESP32            | BLE + WiFi Microcontroller |
| Micro Servos     | SG90 / MG90S             |
| Li-Po Battery     | 3.7V Rechargeable        |
| TP4056 Module    | Charging & protection     |
| Limit Switches   | Optional for feedback     |
| Wires, Case, etc | For wearable design       |

---

## 🚀 How It Works

1. ESP32 receives BLE commands from the app.
2. Depending on the breathing phase, it triggers a servo motor to close/open the appropriate nostril.
3. The session continues in sync with the app's visual and timed breathing guidance.

---

## 🛠️ Setup Instructions

### Arduino Environment
1. Install the following libraries:
   - `Servo.h`
   - `BLEDevice.h` (`ESP32 BLE Arduino`)
2. Connect ESP32 to servos as per circuit diagram.
3. Upload the code in `nostril_breathing_actuator.ino`.

### BLE Commands
| Command | Action                     |
|---------|----------------------------|
| `LEFT`  | Close Left / Open Right    |
| `RIGHT` | Close Right / Open Left    |
| `OFF`   | Open both nostrils         |

---

## 📲 App Integration

- The app scans and connects via BLE.
- Sends real-time phase commands (`LEFT`, `RIGHT`, `OFF`) to the device.
- User gets fully hands-free ANB guidance via actuator.

---

## 📄 License

MIT License

---

## 🙌 Acknowledgments

This project is part of a holistic wellness and breath-control automation initiative. Built with 

