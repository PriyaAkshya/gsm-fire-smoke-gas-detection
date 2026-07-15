#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

// ---------------- LCD ----------------
// RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// ---------------- GSM ----------------
SoftwareSerial gsm(10, 11); // Arduino RX, TX

// ---------------- Sensors ----------------
#define MQ2_PIN A0
#define MQ135_PIN A1
#define FLAME_PIN 8

// ---------------- Buzzer ----------------
#define BUZZER_PIN 9

// ---------------- Threshold Values ----------------
#define GAS_THRESHOLD 400
#define SMOKE_THRESHOLD 400

bool alertSent = false;

void setup()
{
  Serial.begin(9600);
  gsm.begin(9600);

  pinMode(FLAME_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(BUZZER_PIN, LOW);

  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("Safety System");

  lcd.setCursor(0, 1);
  lcd.print("Initializing");

  delay(3000);

  lcd.clear();

  Serial.println("System Started");
}

void loop()
{
  int gasValue = analogRead(MQ2_PIN);
  int smokeValue = analogRead(MQ135_PIN);
  int flameValue = digitalRead(FLAME_PIN);

  Serial.print("Gas: ");
  Serial.print(gasValue);

  Serial.print(" Smoke: ");
  Serial.print(smokeValue);

  Serial.print(" Flame: ");
  Serial.println(flameValue);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("G:");
  lcd.print(gasValue);

  lcd.print(" S:");
  lcd.print(smokeValue);

  // Gas Detection
  if (gasValue > GAS_THRESHOLD)
  {
    triggerAlert("GAS LEAKAGE!");

    if (!alertSent)
    {
      sendSMS("ALERT! Gas leakage detected.");
      alertSent = true;
    }
  }

  // Smoke Detection
  else if (smokeValue > SMOKE_THRESHOLD)
  {
    triggerAlert("SMOKE DETECTED");

    if (!alertSent)
    {
      sendSMS("ALERT! Smoke detected.");
      alertSent = true;
    }
  }

  // Flame Detection
  else if (flameValue == LOW)
  {
    triggerAlert("FIRE DETECTED!");

    if (!alertSent)
    {
      sendSMS("EMERGENCY! Fire detected.");
      alertSent = true;
    }
  }

  // Safe Condition
  else
  {
    digitalWrite(BUZZER_PIN, LOW);

    lcd.setCursor(0, 1);
    lcd.print("STATUS: SAFE");

    alertSent = false;
  }

  delay(1000);
}


// ---------------- Alert Function ----------------

void triggerAlert(String message)
{
  digitalWrite(BUZZER_PIN, HIGH);

  lcd.setCursor(0, 1);
  lcd.print(message);

  Serial.println(message);
}


// ---------------- GSM SMS Function ----------------

void sendSMS(String message)
{
  Serial.println("Sending SMS...");

  gsm.println("AT");
  delay(1000);

  gsm.println("AT+CMGF=1");
  delay(1000);

  gsm.println("AT+CMGS=\"+917981662301\"");
  delay(1000);

  gsm.print(message);
  delay(500);

  gsm.write(26);

  delay(5000);

  Serial.println("SMS Sent");
}
