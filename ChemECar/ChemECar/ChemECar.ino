
// ChemE Car Sketch
// Runs in a standby loop waiting for a serial connection. Once recieved, 
// goes into a transmission and measurement loop. 

int measurement;
long rotaryTicks;
boolean constantLoop;
long timeRunning = 0;
long timeStart = 0;


void rotaryInterrupt(){
  rotaryTicks++;
}

void timerStart(){
  if( (millis() - timeStart) > 400){
    constantLoop = !constantLoop;
    timeStart = millis();
  }

}
    
void resetValues(){
  rotaryTicks = 0;
  timeRunning = 0;
}

void sendMeasurement(){
  if((millis() - timeStart) > 100){
      Serial1.print(millis() - timeStart);
      Serial1.print(',');
      Serial1.println(rotaryTicks);
  }
}


void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.println("Stuff");
  attachInterrupt(1, timerStart, CHANGE);
  attachInterrupt(0, rotaryInterrupt, CHANGE);

}

void loop(){
  if(Serial1.available() > 0){
    char recieved = Serial1.read();
    switch(recieved){
      
      case 'G':
      // Fall through
      case 'g':
        constantLoop = true;
        resetValues();
        break;
      
      case 'S':
      // Fall through
      case 's':
        constantLoop = false;
        resetValues();
        break;

    }
  }
  
  
  // Measurement Loop
  if(constantLoop){
    sendMeasurement();
    Serial.println(rotaryTicks);
  }
}


