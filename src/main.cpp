#include <func.h>
// işlemleri bir çekirdekte, seriale veri gönderme ve alma işlemini de başka bir çekirdekte yaptırma fikri.

void setup()
{
  Serial.begin(9600);
  pinMode(buton, INPUT_PULLUP);
  pinMode(yesilLed, OUTPUT);
  pinMode(kirmiziLed, OUTPUT);
  pinMode(maviLed, OUTPUT);
  pinMode(potans, INPUT);

  attachInterrupt(digitalPinToInterrupt(buton), buttonPress, FALLING);
  xTaskCreatePinnedToCore(receiveData, "ledYakSondur", 4096, NULL, 0, NULL, 0);
  dht.begin();
}

void loop()
{
  sendData();
}
