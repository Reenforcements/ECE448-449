/*
Adafruit Arduino - Lesson 3. RGB LED
*/

int speakerPin = 12;
int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int buttonPin = 2;
       
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;
int reading;

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 500;


void setup()
{
  pinMode(speakerPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonPin, INPUT);  
}
 
void loop()
{
  reading = digitalRead(buttonPin);
  buttonState = digitalRead(buttonPin);

  if (reading != lastButtonState) 
  {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) 
  {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) 
    {
      buttonState = reading;


    if(buttonState == HIGH)
      {
    setColor(0,255,0);
    play();
      } 
      
    else
      {
    setColor(255,0,0);
    noTone(speakerPin);
       }
    }  
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
}
 
void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

void play() {
  tone(speakerPin,554);
  delay(500);
  tone(speakerPin,622); 
  delay(500);
  tone(speakerPin,622); 
  delay(500);
  tone(speakerPin,698); 
  delay(500);
  tone(speakerPin,831);
  delay(500); 
  tone(speakerPin,740);
  delay(500);
  tone(speakerPin,698); 
  delay(500);
  tone(speakerPin,622); 
  delay(500);
  tone(speakerPin,554); 
  delay(500);
  tone(speakerPin,622); 
  delay(500);
  tone(speakerPin,-1); 
  delay(500);
  tone(speakerPin,415); 
  delay(500);
  tone(speakerPin,415);
}
 
