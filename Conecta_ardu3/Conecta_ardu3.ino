#include <OneWire.h> 
#include <DallasTemperature.h>
#include <SPI.h>
#include <Ethernet.h>
#include <ThingerEthernet.h>

#define USERNAME "Ricardobruno"
#define DEVICE_ID "arduino"
#define DEVICE_CREDENTIAL "DWGbc9&3wwSF"

ThingerEthernet thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

/********************************************************************/
// Data wire is plugged into pin 2 on the Arduino 
#define ONE_WIRE_BUS 2 
/********************************************************************/
// Setup a oneWire instance to communicate with any OneWire devices  
// (not just Maxim/Dallas temperature ICs) 
OneWire oneWire(ONE_WIRE_BUS); 
/********************************************************************/
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
/********************************************************************/ 
void setup(void) 
{ 
 // start serial port 
 Serial.begin(9600); 
 Serial.println("Dallas Temperature IC Control Library Demo"); 
 // Start up the library 
 sensors.begin(); 
  /*/thing["temperature"] >> outputValue(sensors.getTempCByIndex(0));*/
  /*thing["data"] >> [](pson& out){
        out = sensors.getTempCByIndex(0);
    };*/
  /*pson data;
  data["temperature"] = sensors.getTempCByIndex(0);
  thing.call_endpoint("keen_endpoint", data);*/

} 
void loop(void) 
{ 
  Serial.print(sensors.getTempCByIndex(0));
  pson data;
  data["temperature"] = sensors.getTempCByIndex(0);
  thing.call_endpoint("keen_endpoint", data);
   
  thing.handle();

  //thing.call_endpoint("keen_endpoint", thing["data"]);
  //call sensors.requestTemperatures() //to issue a global temperature 
 // request to all devices on the bus 

 delay(5000);
 Serial.print(sensors.getTempCByIndex(0));
/********************************************************************
 Serial.print(" Requesting temperatures..."); 
 sensors.requestTemperatures(); // Send the command to get temperature readings 
 Serial.println("DONE"); 
/********************************************************************
 Serial.print("Temperature is: "); 
 Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"?  
   // You can have more than one DS18B20 on the same bus.  
   // 0 refers to the first IC on the wire */
   
} 
