// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>

int led = D7;  // The on-board LED


//Constants
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE); 

void setup() {
  pinMode(led, OUTPUT);
  dht.begin();
}

void loop() {
  digitalWrite(led, HIGH);   // Turn ON the LED
  
    //Read data and store it to variable temp
    String temp= String(dht.getTempCelcius());

  //String temp = String(random(60, 80));
  Particle.publish("Temp", temp, PRIVATE);
  delay(15000);               // Wait for 30 seconds

  digitalWrite(led, LOW);    // Turn OFF the LED
  delay(15000);               // Wait for 30 seconds
}