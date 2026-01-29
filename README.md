# Monopolar HVDC-Link

This project presents a low-power laboratory model of a **High Voltage DC (HVDC) link** implemented using a single-phase inverter–rectifier system controlled by SPWM (Sinusoidal Pulse Width Modulation).

The setup demonstrates the basic operating principle of an HVDC bus, including power conversion, isolation, and gate driving, suitable for educational and prototyping purposes.

---

### Block Description

The implemented system consists of:
- A rectifier stage converting AC to DC
- A DC-link capacitor for smoothing and energy storage
- A single-phase inverter stage controlled using SPWM
- Optical isolation for safe gate driving

The inverter is driven using complementary SPWM signals with dead-band insertion to prevent shoot-through.

---

### SPWM Waveforms

**Figure 1:** Single-phase SPWM gate signals with dead-band  
![SPWM with Deadband](https://github.com/user-attachments/assets/c82cc449-0fd5-44e5-b536-a4a7ebdc61fe)

---

### Hardware Components Used

| Component | Description |
|-----------|-------------|
| ESP32 | PWM generation and control |
| MOSFETs (×4) | Full-bridge inverter switches |
| TLP251 | Opto-isolated gate driver |
| Resistors | Gate and signal conditioning |
| Capacitors | DC-link smoothing |
| Breadboard | Prototype assembly |

---

### Features

- Single-phase SPWM-based inverter
- Dead-time insertion for MOSFET protection
- Opto-isolated gate drive using TLP251
- Low-power HVDC link demonstration
- Modular design suitable for scaling and control experiments

---

### Applications

- HVDC transmission concept demonstration  
- Power electronics education  
- Inverter control and modulation studies  
- Isolation and gate-driver design practice  
- DC-link dynamics analysis  

---

### Author

Thejas  
Electronics Engineering  

