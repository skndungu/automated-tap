const int touchSensorPin = A0;   //attach arduino analog  pin to attach the touch sensor
const int relayPin = 4; // the pin to control the opening and closing of the solenoid valve

int mySensorValue = 0; // declare and initialise the variable
int tapStatus;

void setup ()
{
  Serial.begin(9600);
  pinMode(relayPin,OUTPUT);
}

void loop ()
{
  takeReading(); // program keeps checking the status of the touch sensor
  if (mySensorValue < 500) // when activated, open the valve and water starts flowing
  {
    digitalWrite(relayPin,HIGH);
  }

  if (tapStatus == 0 && mySensorValue < 500 ) //Keep the tap running if the touch sensor is still active
  {

    {
      digitalWrite(relayPin,HIGH);
      //delay(500);
    }
  }

    else
  takeReading(); // program keeps checking the status of the touch sensor

  if (mySensorValue > 500) // when sensor is not active it prompts the tap to close
  {
    digitalWrite(relayPin,LOW);
  }

  takeReading(); // program keeps checking the status of the touch sensor

}


void takeReading() // program keeps checking the status of the touch sensor
{

    mySensorValue = analogRead(touchSensorPin);
    tapStatus = digitalRead(relayPin);
    Serial.println(mySensorValue);
    delay(300);
    Serial.println(tapStatus);

}

