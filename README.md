# Configuracion_Libreria_Pantalla_I2C
LiquidCrystal_I2C para el control de pantallas LCD 16x2 y 20x4.

## Configuración de Hardware y Pines (Pinout)
El protocolo I2C utiliza solo dos líneas de comunicación (SDA y SCL). Aunque la lógica de programación es la misma, la ubicación física de estos pines varía según la placa:

<img width="733" height="157" alt="image" src="https://github.com/user-attachments/assets/28c85d5f-b8a4-48f7-a7e7-ec8715845f1b" />

Nota Crítica: La mayoría de las pantallas LCD requieren 5V para un contraste óptimo. Si utilizas ESP32, asegúrate de alimentar el LCD desde el pin VIN (si estás conectado a USB) para obtener el voltaje necesario.

## Funciones Principales de la Librería
La librería LiquidCrystal_I2C estandariza el control de la pantalla mediante las siguientes funciones fundamentales:

### Inicialización y Energía
LiquidCrystal_I2C lcd(addr, cols, rows): Define la dirección I2C (usualmente 0x27 o 0x3F), el número de columnas y filas.
lcd.init(): Inicializa el controlador I2C y la pantalla. Debe ir siempre en el setup().
lcd.backlight(): Enciende el LED de fondo.
lcd.noBacklight(): Apaga el LED de fondo para ahorro de energía.

### Gestión de Texto y Cursor
lcd.setCursor(col, row): Posiciona el cursor. Recuerda que el índice comienza en 0 (ej: setCursor(0, 1) mueve el cursor a la primera columna de la segunda fila).
lcd.print("texto"): Imprime caracteres o variables en la posición actual.
lcd.clear(): Borra todo el contenido de la pantalla y regresa el cursor al inicio (0,0).
lcd.home(): Regresa el cursor al inicio sin borrar el contenido.

## Implementación de Código Base

Para asegurar la compatibilidad entre plataformas, se recomienda la siguiente estructura de código:

<img width="626" height="409" alt="image" src="https://github.com/user-attachments/assets/02f91f2e-4338-4e8f-80cf-b962f2416acc" />

## Resolución Analógica y Visualización

Independientemente de la placa, el uso del LCD es ideal para monitorear señales del mundo real. Sin embargo, recuerda que la resolución de lectura varía:

Arduino UNO: ADC de 10 bits (valores de 0 a 1023).
ESP32: ADC de 12 bits (valores de 0 a 4095).

Al mostrar datos en el LCD, asegúrate de realizar el mapeo o escalamiento adecuado según la resolución de tu hardware para que la información sea precisa.

## Solución de Problemas Comunes

- Pantalla encendida sin texto: Gira el potenciómetro de contraste (pieza azul) en la parte posterior del módulo I2C hasta que los caracteres sean visibles.
- Dirección I2C incorrecta: Si el código no funciona, utiliza un "I2C Scanner" para confirmar si la dirección de tu pantalla es 0x27, 0x3F u otra.
- Caracteres extraños: Asegúrate de no tener cables sueltos en las líneas SDA/SCL, ya que el ruido interrumpe la transmisión de datos.


