# 💧 Arduino Water Level Monitor (Versión 2)

Sistema automatizado de monitoreo y control de nivel de agua en recipientes mediante tecnología ultrasónica, desarrollado para la plataforma Arduino. Esta versión incluye un indicador visual dinámico mediante un semáforo LED de dos colores y alertas sonoras intermitentes al alcanzar el nivel máximo de llenado.

---

## 🚀 Características Principales

* **Medición sin contacto:** Utiliza el sensor ultrasónico **HC-SR04** para calcular en tiempo real la distancia hacia la superficie del agua.
* **Indicador Visual Inteligente (Semáforo):**
  * 🟢 **LED Verde Fijo:** El recipiente está vacío o por debajo del umbral de inicio.
  * 🟢 **LED Verde Parpadeante:** Proceso de llenado activo (el nivel de agua está subiendo).
  * 🔴 **LED Rojo Fijo:** El recipiente ha alcanzado el límite máximo de capacidad.
* **Alerta Sonora de Precisión:** Buzzer activo programado para emitir **tres pitidos breves** como notificación sonora al completarse el llenado.
* **Telemetría en Tiempo Real:** Envío de mediciones continuas de distancia (en cm) a través del Monitor Serie para fácil depuración y seguimiento.

---

## 🛠️ Hardware y Conexiones

| Componente | Pin Arduino | Función |
| :--- | :--- | :--- |
| **Sensor HC-SR04 (Trig)** | Pin 2 | Salida de pulso ultrasónico |
| **Sensor HC-SR04 (Echo)** | Pin 3 | Entrada de recepción de eco |
| **Buzzer Activo** | Pin 4 | Alerta sonora de llenado |
| **LED Verde** | Pin 5 | Indicador de estado (Vacío / Llenándose) |
| **LED Rojo** | Pin 6 | Indicador de estado (Lleno) |

---

## 📏 Calibración y Umbrales

El sistema está configurado para adaptarse a un recipiente de **9.5 cm** de altura útil:

* `alturaTotal = 9.50 cm` — Límite de referencia para el recipiente vacío.
* `umbralVacio = 8.50 cm` — Punto de transición donde inicia el indicador de llenado activo.
* `umbralLleno = 2.00 cm` — Nivel crítico para activar la alerta sonoro-visual de recipiente lleno.

