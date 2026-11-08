# 💧 Arduino Water Level Monitor (Versión 1.1)

Sistema automatizado de monitoreo y control de nivel de agua en recipientes mediante tecnología ultrasónica, desarrollado para la plataforma Arduino. Esta versión incluye un indicador visual dinámico mediante un semáforo LED de dos colores, alertas sonoras ante llenado y un **sistema de detección de anomalías o lecturas erróneas**.

---

## 🚀 Características Principales

* **Medición sin contacto:** Utiliza el sensor ultrasónico **HC-SR04** para calcular en tiempo real la distancia hacia la superficie del agua.
* **Indicador Visual Inteligente (Semáforo):**
  * 🟢 **LED Verde Fijo:** El recipiente está vacío o en proceso de llenado dentro de parámetros normales.
  * 🔴 **LED Rojo Fijo:** El recipiente ha alcanzado el límite máximo de capacidad (`<= 2.50 cm`).
  * ⚡ **Doble Parpadeo Rápido (Verde y Rojo):** Alerta visual de error ante mediciones anómalas (`<= 0.0 cm` o lecturas desproporcionadas por encima del rango del recipiente).
* **Alerta Sonora de Precisión:** Buzzer activo programado para encenderse de forma constante al confirmarse el llenado completo del recipiente.
* **Telemetría en Tiempo Real:** Envío continuo de datos métricos de distancia en centímetros hacia el Monitor Serie para facilitar depuración y monitoreo.

---

## 🛠️ Hardware y Conexiones

| Componente | Pin Arduino | Color de Cable | Función |
| :--- | :--- | :--- | :--- |
| **Sensor HC-SR04 (Trig)** | Pin 2 | Amarillo | Salida de pulso ultrasónico |
| **Sensor HC-SR04 (Echo)** | Pin 3 | Azul | Entrada de recepción de eco |
| **LED Verde** | Pin 4 | Verde | Indicador de estado normal (no lleno) |
| **LED Rojo** | Pin 5 | Naranjo | Indicador de alerta (lleno) |
| **Buzzer Activo** | Pin 6 | Blanco | Alerta sonora de llenado |

---

## 📏 Calibración y Umbrales

El sistema está configurado para un recipiente con una profundidad de **9.50 cm**:

* `alturaTotal = 9.50 cm` — Límite de referencia para el recipiente vacío.
* `umbralLleno = 2.50 cm` — Distancia crítica para activar la alerta sonoro-visual de recipiente lleno.
* `margenError = 5.00 cm` — Tolerancia adicional para identificar fallos de medición o lecturas fuera de rango.

---

## 👨‍💻 Autor

Proyecto de electrónica y automatización desarrollado con Arduino.
