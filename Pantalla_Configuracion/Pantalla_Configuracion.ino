#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);//crear un objeto lcd (DIRECCIÓN pantalla, Tamaño x, Tamño y)

void setup() {
  lcd.clear();
  lcd.init();//inicializar la pantalla lcd
  lcd.begin(16,2);
  lcd.backlight();//Encender la luz de fondo

  lcd.setCursor (0, 0);//poner el cursor en las coordenadas (x,y)
  lcd.print("Pantalla lcd 16x2");//muestra en la pantalla max 20 caracteres
  lcd.setCursor (0, 1);//poner el cursor en las coordenadas (x,y)
  lcd.print("esp32-s");//muestra en la pantalla max 20 caracteres
  delay(1000);
  lcd.clear();
}

void loop() {
  

  lcd.setCursor (0, 0);//poner el cursor en las coordenadas (x,y)
  lcd.print("Tiempo");//muestra en la pantalla max 20 caracteres
  lcd.setCursor (0, 1);
  lcd.print("Activo: ");
  //La funcion millis() regresa los ms que lleva encendido
  //Lo dividimos entre 1000 para que nos muestre en segundos.
  lcd.print(millis()/1000);
  lcd.print("s");
  delay(1000);//Esperamos 1 segundo antes de repetir el loop
}