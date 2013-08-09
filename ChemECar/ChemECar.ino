// ChemE Car Sketch
// Runs in a standby loop waiting for a serial connection. Once recieved, 
// goes into a transmission and measurement loop. 

int measurement;
long rotaryTicks;
boolean constantLoop;

void rotaryInterrupt(){
  rotaryTicks++;
}

void sendMeasurement(){
  Serial.print(millis());
  Serial.print(',');
  Serial.println(rotaryTicks);
}


void setup(){
  Serial.begin(9600);
}

void loop(){
  if(Serial.available() > 0){
    char recieved = Serial.read();
    switch(recieved){
      
      case 'G':
      // Fall through
      case 'g':
        constantLoop = true;
        attachInterrupt(0, rotaryInterrupt, CHANGE);
        Serial.println("Attached Interrupt");
        break;
      
      case 'S':
      // Fall through
      case 's':
        constantLoop = false;
        Serial.println("Detached Interrupt");
        detachInterrupt(0);
        break;
    }
  }
  
  
  // Measurement Loop
  if(constantLoop){
    sendMeasurement();
  }
}


