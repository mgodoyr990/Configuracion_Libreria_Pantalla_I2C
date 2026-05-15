  #include <LiquidCrystal_I2C.h>
  LiquidCrystal_I2C lcd(0x27, 16, 2);
  const int analog_pin=15;
  int valor_pot=0;
  float voltaje = 0.0;
  
void setup() {
  // put your setup code here, to run once:
  lcd.clear();
  lcd.init();//inicializar la pantalla lcd
  lcd.begin(16,2);
  lcd.backlight();//Encender la luz de fondo

  Serial.begin(115200);
  delay(1000);
  
  lcd.setCursor (0, 0);//poner el cursor en las coordenadas (x,y)
  lcd.print("LECTURA ANALOGICA");//muestra en la pantalla max 20 caracteres
  lcd.setCursor (0, 1);//poner el cursor en las coordenadas (x,y)
  lcd.print("POTENCIOMETRO");//muestra en la pantalla max 20 caracteres
  delay(1000);
  lcd.clear();

}


void loop() {
  // put your main code here, to run repeatedly:
  
  valor_pot=analogRead(analog_pin);
  Serial.println(valor_pot);
  voltaje=(5.0 * valor_pot)/4095;

  lcd.setCursor (0, 0);//poner el cursor en las coordenadas (x,y)
  lcd.print("LECTURA");//muestra en la pantalla max 20 caracteres
  lcd.setCursor (0, 1);
  lcd.print("POT: ");

  lcd.print(voltaje);
  delay(200);
}