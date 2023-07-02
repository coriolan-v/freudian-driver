#define ReturnToZero "ReturnToZero"
// Return to zero（Same as the " Goto 0 " option on screen）
// Command23 : e0 94 00 tCHK
// Return e0 , result (uint8_t), rCHK.
// result:
// 01- successful;
// 00- Failure
// For example:
// Send "e0 94 00 74"
// return "e0 01 e1" (successful)

#define SetAcceleration "SetAcceleration"
// Set the acceleration (ACC) parameter
// command27: e0 a4 XX XX tCHK
// (Default 0x11e).
// Return e0 , result (uint8_t), rCHK.
// result:
// 01- successful;
// 00- Failure
// For example:
// Send "e0 a4 00 80 04" (ACC = 0x80)
// return "e0 01 e1" (successful)
// Important note: If the ACC parameter is set too large, it may damage the driver board, please set the parameters carefully!

#define StopMotor "StopMotor"
// Stop the Motor
// command 32: e0 f7 tCHK
// stop the motor.
// Return e0 and the result (uint8_t) and rCHK.
// result:
// 01- successful;
// 00- Failure
// Example:
// Send e0 f7 d7
// return e0 01 e1 (successful)

#define RunToAngle "RunToAngle"
// Run to Angle
// command 34: e0 fd xx xx xx xx xx tCHK
// The motor run to an angle in a speed.
// The third byte(xx) defines the direction and speed, such as command 9.
// The last two bytes(xx xx xx xx ) define the number of pulses.
// If(xx xx xx xx = 00 00 0C 80),the motor(1.8 °, subdivision 16) will rotates one circle.
// The speed (Vrpm) calculation formula is the same as command10.
// Return e0, result (uint8_t), rCHK.
// result:
// 01- successful;
// 00- Failure
// For example: (the motor(1.8 °, subdivision 16))
// send “e0 fd 01 00 00 0c 80 6a”, the motor rotates forward 360 °in speed 1.
// send “e0 fd 86 00 00 0c 80 ef”, the motor rotates reverses 360 °in speed 6.
// Example:
// Send e0 fd 32 00 00 0c 80 9b
// return e0 01 e1 (successful)

#define SetDirection "SetDirection"
// Set the direction of motor rotation（Same as the " Dir " option on screen）
// Command13 : e0 86 xx tCHK
// xx :
// 00-CW;
// 01-CCW
// Return e0 , result (uint8_t), rCHK.
// result:
// 01- successful;
// 00- Failure
// For example:
// Send "e0 86 00 66" (CW)
// return "e0 01 e1" (successful)

#define Calibrate "Calibrate"
// Calibrate the encoder （Same as the "Cal" option on screen）
// command7 : e0 80 00 tCHK
// (The motor must be unloaded.)
// Return e0 , result (uint8_t), rCHK.
// result:
// 01- successful;
// 00- Failure
// For example:
// Send “e0 80 00 60”
// return "e0 01 e1" (succeessful)

#define SetMaxTorque "SetMaxTorque"
// Set the maximum torque (MaxT) parameter
// command28: e0 a5 XX XX tCHK
// MaxT value range (0 ~ 0x4B0). (Default 0x4B0)
// Return e0 , result (uint8_t), rCHK.
// result:
// 01- successful;
// 00- Failure
// For example:
// Send "e0 a5 02 58 df" (MaxT = 0x258)
// return "e0 01 e1" (successful)

#define RunToAngleInSpeed "RunToAngleInSpeed"
// command 34: e0 fd xx xx xx xx xx tCHK
// The motor run to an angle in a speed.
// The third byte(xx) defines the direction and speed, such as command 9.
// The last two bytes(xx xx xx xx ) define the number of pulses.
// If(xx xx xx xx = 00 00 0C 80),the motor(1.8 °, subdivision 16) will rotates one circle.
// The speed (Vrpm) calculation formula is the same as command10.
// Return e0, result (uint8_t), rCHK.
// result:
// 01- successful;
// 00- Failure
// For example: (the motor(1.8 °, subdivision 16))
// send “e0 fd 01 00 00 0c 80 6a”, the motor rotates forward 360 °in speed 1.
// send “e0 fd 86 00 00 0c 80 ef”, the motor rotates reverses 360 °in speed 6.
// Example:
// Send e0 fd 32 00 00 0c 80 9b
// return e0 01 e1 (successful)