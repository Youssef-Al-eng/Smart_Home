# 🏠 Smart Home Automation Using ATmega32  

## 📌 Project Overview  
This project implements a **Smart Home Automation System** using an ATmega32 microcontroller. The system integrates multiple sensors and actuators to automatically control lighting, fan speed, and fire detection. An LCD displays real-time data and alerts, while a buzzer provides critical warnings.  

The system includes:  
- **Automatic lighting control** (via LDR).  
- **Fan speed regulation** (via LM35 temperature sensor & PWM).  
- **Fire detection & alarm system** (via flame sensor & buzzer).  
- **LCD feedback** for monitoring system status.  

---

## 🎯 Objectives  
- Automate **lighting** using ambient light readings.  
- Adjust **fan speed** proportionally to room temperature.  
- Detect **fire hazards** and trigger alarms.  
- Display **real-time system status** on an LCD.  

---

## ✨ Features  
- **Lighting Control (LDR-based):**  
  - Intensity < 15% → All 3 LEDs (Red, Green, Blue) ON.  
  - Intensity 16–50% → Red & Green ON.  
  - Intensity 51–70% → Only Red ON.  
  - Intensity > 70% → All LEDs OFF.  

- **Fan Speed Control (PWM + LM35):**  
  - ≥ 40°C → 100% speed  
  - 35–39°C → 75% speed  
  - 30–34°C → 50% speed  
  - 25–29°C → 25% speed  
  - < 25°C → Fan OFF  

- **Fire Detection (Flame Sensor):**  
  - LCD displays **"Critical alert!"**  
  - **Buzzer ON** until fire is cleared  

- **LCD Display (16x2):**  
  - Row 1 → "FAN is ON/OFF"  
  - Row 2 → "Temp= xx°C  LDR= xx%"  

---

## 🛠️ Hardware Components  
- **Microcontroller:** ATmega32  
- **Sensors:**  
  - LDR (PA0 – ADC0)  
  - LM35 Temperature Sensor (PA1 – ADC1)  
  - Flame Sensor (PD2)  
- **Actuators & Indicators:**  
  - DC Motor (Fan) via H-Bridge (IN1: PB0, IN2: PB1, EN1: PB3/OC0)  
  - Buzzer (PD3)  
  - LEDs (Red: PB5, Green: PB6, Blue: PB7)  
- **Display:** 16x2 LCD in 8-bit mode (RS: PD0, EN: PD1, Data: PORTC)  
- **Clock:** 16 MHz Crystal  

---

## 🔌 Pin Connections  

| Component              | ATmega32 Pin | Connected To |
|-------------------------|--------------|--------------|
| LDR Sensor              | PA0 (ADC0)   | Voltage Divider Output |
| LM35 Temp Sensor        | PA1 (ADC1)   | Sensor Output |
| Flame Sensor            | PD2          | Digital Output |
| Buzzer                  | PD3          | Alarm Output |
| LCD RS                  | PD0          | LCD RS |
| LCD Enable              | PD1          | LCD E |
| LCD RW                  | GND          | Write Mode |
| LCD Data (D0–D7)        | PORTC        | LCD Data Lines |
| DC Motor IN1            | PB0          | H-Bridge IN1 |
| DC Motor IN2            | PB1          | H-Bridge IN2 |
| DC Motor Enable (PWM)   | PB3 (OC0)    | H-Bridge EN1 |
| Red LED                 | PB5          | Indicator |
| Green LED               | PB6          | Indicator |
| Blue LED                | PB7          | Indicator |

---

## ⚙️ Software & Drivers  
The project is implemented in **C** with modular driver-based architecture:  

- **ADC Driver** → Reads analog sensors (LDR, LM35).  
- **PWM Driver** → Controls fan speed via Timer0 (non-inverting mode).  
- **GPIO Driver** → Configures I/O pins.  
- **LCD Driver** → Displays system status.  
- **LED Driver** → Manages RGB LED states.  
- **DC Motor Driver** → Controls motor direction & speed.  
- **Flame Sensor Driver** → Detects fire hazards.  
- **Buzzer Driver** → Provides audible alerts.  

---

## 🚀 Operation Flow  
1. **LDR checks light intensity** → LEDs toggle accordingly.  
2. **LM35 measures temperature** → Fan adjusts speed via PWM.  
3. **Flame sensor detects fire** → LCD + Buzzer alert.  
4. **LCD updates continuously** → Displays FAN status, Temp, and LDR readings.  

---

## 📐 Circuit Diagram  
Below is the **Proteus simulation circuit** for the project:  
<img width="1290" height="850" alt="Image" src="https://github.com/user-attachments/assets/654af1f9-ff2a-44ed-a7c7-bd938d17a817" />


---

## 👤 Author  
**Youssef Alaa**  
- GitHub: [@Youssef-Al-eng](https://github.com/Youssef-Al-eng)  
- LinkedIn: [Youssef Alaa](https://www.linkedin.com/in/youssef-alaa-1b9580332/)  
