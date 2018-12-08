#include <SoftwareSerial.h>
#include <TinyGPS.h>

TinyGPS gps;
SoftwareSerial sgps(D5, D6);

void setup()
{
  Serial.begin(9600);
  sgps.begin(9600);
}

void loop()
{
  while (sgps.available())
  {
    int c = sgps.read();
    if (gps.encode(c))
    {
float slat,slon;
      gps.f_get_position(&slat, &slon);
      Serial.print("Latitude :");
      Serial.println(slat, 6);
      Serial.print("Longitude:");
      Serial.println(slon, 6);
    }
  }
}
