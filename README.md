# 📘 Práctica 4 – Sistemas Operativos en Tiempo Real (FreeRTOS)

## 🎯 Objetivo

El objetivo de esta práctica es comprender el funcionamiento de un sistema operativo en tiempo real (RTOS) en el ESP32, utilizando FreeRTOS para ejecutar múltiples tareas de forma concurrente.

---

## ⚙️ Descripción del programa

En este ejercicio se implementan dos tareas:

* **Tarea principal (`loop`)**: imprime un mensaje por el puerto serie cada segundo.
* **Tarea secundaria (`anotherTask`)**: creada con `xTaskCreate`, también imprime un mensaje de forma periódica.

Ambas tareas se ejecutan simultáneamente gracias al planificador de FreeRTOS.

---

## 🧠 Conceptos clave

* **Multitarea**: ejecución concurrente de varias tareas.
* **Scheduler**: reparte el tiempo de CPU entre tareas.
* **vTaskDelay() / delay()**: permite ceder el control de la CPU.
* **Prioridad de tareas**: determina qué tarea se ejecuta antes en caso de conflicto.

---

## 💻 Código utilizado

```cpp
#include <Arduino.h>

void anotherTask(void * parameter);

void setup() {
    Serial.begin(115200);
    delay(1000);

    xTaskCreate(
        anotherTask,
        "another Task",
        10000,
        NULL,
        1,
        NULL
    );
}

void loop() {
    Serial.println("this is ESP32 Task");
    delay(1000);
}

void anotherTask(void * parameter) {
    for(;;) {
        Serial.println("this is another Task");
        delay(1000);
    }

    vTaskDelete(NULL);
}
```

---

## 🧾 Resultado obtenido

En el monitor serie se observan los siguientes mensajes:

```
this is ESP32 Task
this is another Task
this is ESP32 Task
this is another Task
```

Los mensajes aparecen de forma alternada, lo que demuestra que ambas tareas se ejecutan de manera concurrente.

---

## ⚙️ Funcionamiento

* La función `loop()` actúa como una tarea gestionada por FreeRTOS.
* `xTaskCreate()` crea una segunda tarea independiente.
* El sistema operativo reparte el tiempo de CPU entre ambas tareas.
* Gracias a los retardos (`delay`), ninguna tarea bloquea la ejecución de la otra.

---

## 🧠 Conclusión

Esta práctica permite entender cómo el ESP32, mediante FreeRTOS, es capaz de ejecutar múltiples tareas de forma eficiente, simulando ejecución paralela y mejorando el rendimiento del sistema.

---
