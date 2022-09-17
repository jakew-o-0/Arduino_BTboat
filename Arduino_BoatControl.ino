#include<SoftwareSerial.h>
SoftwareSerial Ser(0, 1);

String Data = ""; //Holds the tranmited data from the bluetooth module
int TransistrL = 4;
int TransistrR = 5;

void setup() {
  Serial.begin(9600);
  Ser.begin(9600);
  pinMode(TransistrL, OUTPUT);
  pinMode(TransistrR, OUTPUT);
}

void loop() {
  if(Ser.available()){//Only activates if there is a bluetooth connection
      Data = Ser.read();
      Ser.println(Data);
  }
            
  if(Data == "1"){ //Drive fowrward
    digitalWrite(TransistrR, HIGH);
    digitalWrite(TransistrL, HIGH);
  }
  else if(Data == "3"){ //Steer left
    digitalWrite(TransistrL, HIGH);
    digitalWrite(TransistrR, LOW);
  }
  else if(Data == "2"){ //Steer right
    digitalWrite(TransistrR, HIGH);
    digitalWrite(TransistrL, LOW);
  }
  else if(Data == "0"){//Stop the boat
    digitalWrite(TransistrR, LOW);
    digitalWrite(TransistrL, LOW);
  }
}
