#include <USBHost_t36.h>
USBHost myusb;
//BluetoothController bluet(myusb, true, "0000");
BluetoothController bluet(myusb);
JoystickController ps4(myusb);

int p1=2, p2=3, p3=23;
int d1=4, d2=5, d3=21;

float wr=0.10;  // wheel radius
float rr=0.30;  // robot radius
float maxSpeed = 0.25;

void setup() {
    pinMode(p1, OUTPUT);
    pinMode(d1, OUTPUT);
    pinMode(p2, OUTPUT);
    pinMode(d2, OUTPUT);
    pinMode(p3, OUTPUT);
    pinMode(d3, OUTPUT);
    myusb.begin();
    Serial.begin(9600);
    Serial.println("i am ready");

}

void loop() {
    myusb.Task();
    float vx=0.0, vy=0.0, omega=0.0;
    float w1=0.0, w2=0.0, w3=0.0;
    float deadband = 0.1;

    if (ps4.available()) {
        int lx = ps4.getAxis(0);
        int ly = ps4.getAxis(1);
        int rx = ps4.getAxis(2);
        int ry = ps4.getAxis(3);

        vx = (ly - 128) / 128.0;
        vy = (lx - 128) / 128.0;
        omega = (rx - 128) / 128.0;

        if (abs(vx) < deadband) vx = 0.0;
        if (abs(vy) < deadband) vy = 0.0;
        if (abs(omega) < deadband) omega = 0.0;

        w1 = (vy + rr * omega) / wr; 
        w2 = (0.866 * vx - 0.5 * vy + rr * omega) / wr;
        w3 = (-0.866 * vx - 0.5 * vy + rr * omega) / wr;
        w1*=maxSpeed;
        w2*=maxSpeed;
        w3*=maxSpeed;

        Serial.print(" | vx: "); Serial.print(vx, 3);
        Serial.print(" vy: "); Serial.print(vy, 3);
        Serial.print(" omega: "); Serial.print(omega, 3);
        Serial.print(" | w1: "); Serial.print(w1, 2);
        Serial.print(" w2: "); Serial.print(w2, 2);
        Serial.print(" w3: "); Serial.println(w3, 2);

        if (vx == 0.0 && vy == 0.0 && omega == 0.0) {
            runMotor(p1, d1, 0);
            runMotor(p2, d2, 0);
            runMotor(p3, d3, 0);
        } else {
            runMotor(p1, d1, w1);
            runMotor(p2, d2, w2);
            runMotor(p3, d3, -w3);
        }
    }
    delay(20);
}

void runMotor(int Ppin, int dpin, float speed) {
    int pValue = map(abs(speed), 0,1,0, 255);
    pValue = constrain(pValue, 0, 255);
    pValue*=maxSpeed;
    /*if (pValue > 0 && pValue < 50) {
        pValue = 50;
    }*/
    if (speed >= 0) {
        digitalWrite(dpin, HIGH);
    } else {
        digitalWrite(dpin, LOW);
    }
    analogWrite(Ppin, pValue);
    Serial.println(pValue);
}
