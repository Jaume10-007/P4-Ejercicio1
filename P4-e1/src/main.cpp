#include <Arduino.h>

void anotherTask(void * parameter);

void setup() {
    Serial.begin(115200);
    delay(1000);

    xTaskCreate(
        anotherTask,   // Función de la tarea
        "another Task",// Nombre de la tarea
        10000,         // Tamaño de stack
        NULL,          // Parámetro
        1,             // Prioridad
        NULL           // Handle
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