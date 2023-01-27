#define yesilLed 26
#define kirmiziLed 27
#define maviLed 14
#define buton 33
#define potans 13
#define dhtPin 32
#define DHTTYPE DHT11

#include <DHT.h>
#include <DHT_U.h>
#include <Arduino.h>


DHT dht(dhtPin, DHTTYPE);

// Led sınıfı ile led açma kapama değiştirme ve kontrol etmeyi halledebiliriz.
class Led{
    public:
        Led(int pin) : pin_(pin){ } // Yapıcı method oluştur.
        void ac(){
            digitalWrite(pin_, HIGH);
        }
        void kapat(){
            digitalWrite(pin_, LOW);
        }
        int durum(){
            return digitalRead(pin_);
        }
        void degistir(){
            digitalWrite(pin_, !durum());
        }
        
    private:
        int pin_;

};


Led yesil(yesilLed);
Led kirmizi(kirmiziLed);
Led mavi(maviLed);