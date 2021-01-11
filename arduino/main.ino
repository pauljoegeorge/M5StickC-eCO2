/*
 * File: M5StickCPlus_CO2_Monitor.ino
 * 
 * Air quality measurement using M5Stack TVOC/eCO2 mini Unit w/ Sensirion SGP30 sensor.
 * SGP30 needs 15 seconds to initialize calibration after power on.
 * The M5StickC+ screen will display TVOC and CO2
 * 
 * 2020-10-25 Claus Kuehnel info@ckuehnel.ch
// */
#include <Adafruit_SGP30.h>
#include <M5StickC.h>

Adafruit_SGP30 sgp;

const int LED = 10;
uint8_t i = 15;
long last_millis = 0;
uint16_t eCO2, TVOC;
const uint16_t LIMIT = 1200;

void setup() 
{
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  
  M5.begin();
  M5.Lcd.setRotation(1);
  M5.Lcd.fillScreen(GREEN);

  Serial.begin(115200);
  Serial.println("CO2 Monitor");
  
  Wire.begin(32, 33); // Grove I2C Connector
  if (!sgp.begin())
  {
    Serial.println("Sensor not found :(");
    while (1);
  }
  Serial.print("Found SGP30 serial #");
  Serial.print(sgp.serialnumber[0], HEX);
  Serial.print(sgp.serialnumber[1], HEX);
  Serial.println(sgp.serialnumber[2], HEX);
}

void loop() 
{
  if (! sgp.IAQmeasure()) {
    Serial.println("Measurement failed");
    return;
  }
  
  TVOC = sgp.TVOC;
  eCO2 = sgp.eCO2;
  
  if(eCO2 > LIMIT){
    M5.Lcd.fillScreen(RED);
  }else {
    M5.Lcd.fillScreen(GREEN);
  }
  M5.Lcd.setTextDatum(MC_DATUM);
  M5.Lcd.drawString(String(eCO2) + "ppm", 70, 30, 4);
  
  Serial.print("eCO2 "); Serial.print(eCO2); Serial.println(" ppm");

 
  delay(1000);
}
