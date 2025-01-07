#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Servo.h>


// Initialize the library with RS, E, D4, D5, D6, D7
LiquidCrystal lcd(8, 7, A2, A3, A4, A5);

const int Forward_L = 13;
const int Backward_L = 12;
const int Forward_R = 11;
const int Backward_R = 10;

const int SW_pin = 9;
const int X_pin = A0;
const int Y_pin = A1;

const int trig = 6;
const int echo = 5;

const int speaker = 3;

int ParkingOn = -1;


Servo Left, Right;
int currentTime;
int FirstTime;
bool position = true;

void setup()
{
  Left.attach(4);
  Right.attach(2);

  Left.write(0);
  Right.write(180);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Salut!");
  lcd.setCursor(0, 1);
  lcd.print("Sunt Romica!");

  pinMode(Forward_R, OUTPUT);
  pinMode(Backward_R, OUTPUT);
  pinMode(Forward_L, OUTPUT);
  pinMode(Backward_L, OUTPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);

  pinMode(speaker, OUTPUT);

  Serial.begin(115200);
}

bool debounce(int buton)
{
    int lastButtonState = LOW;
    unsigned long lastDebounceTime = 0;
    unsigned long debounceDelay = 100;

    while(1) {
        int reading = digitalRead(buton);

        if (reading != lastButtonState) {
          lastDebounceTime = millis();
        }

        if ((millis() - lastDebounceTime) > debounceDelay) {
          if(reading == HIGH)
            return 1;

        }
        lastButtonState = reading;
    }
    return 0;
}

void loop()
{
  if (digitalRead(SW_pin) == LOW)
  {
      debounce(SW_pin);
      ParkingOn *= -1;
      lcd.clear();
  }

  if (ParkingOn == -1)
  {
    FirstTime = 1;

    lcd.setCursor(0, 0);
    lcd.print("Salut!");
    lcd.setCursor(0, 1);
    lcd.print("Sunt Romica!");

    int X = analogRead(X_pin);
    int Y = analogRead(Y_pin);

    if (X < 400)
    {
      digitalWrite(Forward_L, LOW);
      digitalWrite(Forward_R, HIGH);
      digitalWrite(Backward_L, HIGH);
      digitalWrite(Backward_R, LOW);
    }
    else if (X > 600)
    {
      digitalWrite(Forward_L, HIGH);
      digitalWrite(Forward_R, LOW);
      digitalWrite(Backward_L, LOW);
      digitalWrite(Backward_R, HIGH);
    }
    else if (Y < 400)
    {
      digitalWrite(Forward_L, HIGH);
      digitalWrite(Forward_R, HIGH);
      digitalWrite(Backward_L, LOW);
      digitalWrite(Backward_R, LOW);
    }
    else if (Y > 600)
    {
      digitalWrite(Forward_L, LOW);
      digitalWrite(Forward_R, LOW);
      digitalWrite(Backward_L, HIGH);
      digitalWrite(Backward_R, HIGH);
    }

    if (X > 400 && X < 600 && Y > 400 && Y < 600)
    {
      digitalWrite(Forward_L, LOW);
      digitalWrite(Forward_R, LOW);
      digitalWrite(Backward_L, LOW);
      digitalWrite(Backward_R, LOW);
    }
  }
  else
  {
      if(FirstTime == 1)
      {
        currentTime = millis();
        FirstTime = 0;
      }      

      if(millis() - currentTime > 1000)
      {
          if(!position)
          {
            Left.write(0);
            Right.write(180);
          }
          else
          {
            Left.write(90);
            Right.write(90);
          }
          currentTime = millis();
          position = !position;
      }

      // Trigger the ultrasonic sensor
      digitalWrite(trig, LOW);
      delayMicroseconds(2);
      digitalWrite(trig, HIGH);
      delayMicroseconds(10);
      digitalWrite(trig, LOW);

      // Measure the echo time
      long duration = pulseIn(echo, HIGH);

      // Calculate the distance in centimeters
      int distance = duration * 0.034 / 2;

      // Print the distance to the Serial Monitor
      lcd.setCursor(0, 0);
      lcd.print("Distance: ");
      lcd.print(distance);
      lcd.print(" cm");

      // Optional: Add logic based on distance
      if (distance < 10)
      {
          lcd.clear();
          ParkingOn *= -1;
          lcd.setCursor(0, 0);
          lcd.print("Felicitari! Ai p");
          lcd.setCursor(0, 1);
          lcd.print("arcat ca un bou!");
          delay(5000);
          lcd.clear();
      }
      else if (distance >= 10 && distance < 20)
      {
          lcd.setCursor(0, 1);
          lcd.print("Inca putin!    ");
		  tone(speaker, 800); // High-frequency tone
      	  delay(100);          // Short delay
      	  noTone(speaker);
      }
	  else if (distance >= 20 && distance < 30)
      {
          lcd.setCursor(0, 1);
          lcd.print("Inca putin!    ");
		  tone(speaker, 800); // Medium-frequency tone
      	  delay(300);         // Medium delay
      	  noTone(speaker);
      }
	  else if (distance >= 30 && distance < 50)
      {
          lcd.setCursor(0, 1);
          lcd.print("Inca putin!    ");
		  tone(speaker, 800); // Low-frequency tone
          delay(500);         // Long delay
          noTone(speaker);
      }
      else
      {
          lcd.setCursor(0, 1);
          lcd.print("dai tare!      ");
		  noTone(speaker); // Stop the tone when distance is greater
      }

  }
}
