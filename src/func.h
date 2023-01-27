
#include <data.h>

void IRAM_ATTR buttonPress()
{
    // IRAM_ATTR IRAM, ESP32 için dahili bir bellek bölgesidir ve normal RAM'e göre daha hızlıdır.
    // IRAM, sistem çağrıları, interrupt veya diğer kritik işlemler için kullanılabilir.
    // IRAM, bellek sınırlı ESP32 sistemleri için önemlidir çünkü daha hızlı çalışan fonksiyonlar daha az bellek kullanır.
    // IRAM_ATTR macro, IRAM içinde çalışan fonksiyonları tanımlamak için kullanılır.
    // digitalWrite(yesilLed, !digitalRead(yesilLed));
    yesil.degistir();
    kirmizi.degistir();
    mavi.degistir();
}

void accordingPotency()
{
    int potencyValue = analogRead(potans);
    float voltaj = (3.3 / 4095) * potencyValue;
    if (voltaj > 2)
    {
        kirmizi.ac();
    }
    else
    {
        kirmizi.kapat();
    }
}

void receiveData(void *pvParameter)
{
    while (1)
    {

        String emir = Serial.readString();
        if (emir == "yesil_led_on")
        {
            yesil.ac();
        }
        else if (emir == "yesil_led_off")
        {
            yesil.kapat();
        }
        else if (emir == "mavi_led_on")
        {
            mavi.ac();
        }
        else if (emir == "mavi_led_off")
        {
            mavi.kapat();
        }
        else if (emir == "kirmizi_led_on")
        {
            kirmizi.ac();
        }
        else if (emir == "kirmizi_led_off")
        {
            kirmizi.kapat();
        }
    }
}

void sendData()
{
    int yesilLedStatus = yesil.durum();
    int kirmiziLedStatus = kirmizi.durum();
    int potansValue = analogRead(potans);
    float voltaj = (3.3 / 4095) * potansValue;
    int maviLedStatus = mavi.durum();
    Serial.print(yesilLedStatus);
    Serial.print("+");
    Serial.print(kirmiziLedStatus);
    Serial.print("+");
    Serial.print(maviLedStatus);
    Serial.print("+");
    Serial.print(voltaj);
    Serial.print("+");
    Serial.print(dht.readHumidity());
    Serial.print("+");
    Serial.println(dht.readTemperature());
}
