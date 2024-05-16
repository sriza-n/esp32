#include <TinyGPS++.h> // library for GPS module
#include <HardwareSerial.h>

TinyGPSPlus gps;  // The TinyGPS++ object
HardwareSerial ss(1);

float latitude , longitude;

void setup()
{
    Serial.begin(115200);
    ss.begin(9600, SERIAL_8N1, 16, 17);
}

void loop()
{
    while (ss.available() > 0)
    {
        gps.encode(ss.read());
        if (gps.location.isUpdated() && gps.date.isValid() && gps.time.isValid())
        {
            latitude = gps.location.lat();
            longitude = gps.location.lng();

            // Print latitude and longitude to the serial monitor
            Serial.print("Latitude: ");
            Serial.println(latitude, 7);
            Serial.print("Longitude: ");
            Serial.println(longitude, 7);
             // Print date to the serial monitor
            Serial.print("Date: ");
            Serial.print(gps.date.day());
            Serial.print("/");
            Serial.print(gps.date.month());
            Serial.print("/");
            Serial.println(gps.date.year());

            // Print time to the serial monitor
            Serial.print("Time: ");
            Serial.print(gps.time.hour());
            Serial.print(":");
            Serial.print(gps.time.minute());
            Serial.print(":");
            Serial.println(gps.time.second());

            delay(1000);
        }
    }
}