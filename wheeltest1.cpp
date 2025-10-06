int dir1 = 21;
int pwm1 = 23;

void setup() {
  pinMode(dir1, OUTPUT);
  pinMode(pwm1, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter PWM value :");
}

void loop() {
  if (Serial.available() > 0) {
    int pwmValue = Serial.parseInt(); 
  }
    if (pwmValue == 0) {
      analogWrite(pwm1, 0); // Stop motor
      Serial.println("Motor stopped");
    } else if (pwmValue > 0) {
      digitalWrite(dir1, HIGH);      // Clockwise
      analogWrite(pwm1, pwmValue);   // Set speed
      Serial.print("clockwise");
      Serial.println(pwmValue);
    } else {
      digitalWrite(dir1, LOW); 
      analogWrite(pwm1, -pwmValue); 
      Serial.print("anticlockwise");
      Serial.println(-pwmValue);
    }
  }

