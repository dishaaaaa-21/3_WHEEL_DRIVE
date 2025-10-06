# 3-Wheel Omni Drive Robot with PS4 Controller using Teensy USBHost_t36
Overview
This project demonstrates a 3-wheel omni-directional robot controlled by a PS4 controller via Bluetooth, using the Teensy 4 USBHost_t36 library.
The robot's motion—forward/backward, sideways, and rotation—is controlled by joystick inputs and converted into individual wheel speeds using inverse kinematics.

Elements Explained
vx, vy, and omega
vx: Robot's speed along the X-axis (forward/backward movement).

vy: Robot’s speed along the Y-axis (sideways movement).

omega (ω): Angular velocity (rotational speed), controls how fast the robot spins about its center.

These inputs are derived from joystick axes, normalized and scaled to control robot motion precisely.

Wheel Radius (wr) and Robot Radius (rr)
wr: Radius of the individual wheels, used to convert wheel angular velocity to linear velocity.

rr: Distance from the robot's center to each wheel, used to calculate contribution of rotation to wheel speed.

How I Studied and References
To understand the concepts and how to implement the code, I consulted the following resources:

PDF Resource
"Understanding vx, vy, and ω in 3-Wheel Drive Robots" - A detailed breakdown of robot speeds and inverse kinematics on omni-wheeled robots. [Attached PDF in repo]

YouTube Videos
Introduction to Arduino joystick control and motor driver basics.

PS4 controller communication with Arduino and Teensy via USBHost_t36.

Tutorials on omniwheel robot inverse kinematics and wireless control.

Online Articles and Libraries
Paul Stoffregen's USBHost_t36 library GitHub and documentation.

Arduino official documentation on PWM (analogWrite) and serial communication.

Various robotics blogs and university lecture notes on omniwheel kinematics and control.

Acknowledgments
Thanks to the Arduino and Teensy communities for USBHost_t36 library support.

PS4 controller interfacing and motor control concepts inspired by several open-source projects and YouTube educators.
