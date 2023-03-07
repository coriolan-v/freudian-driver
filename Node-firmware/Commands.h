// Return to zero（Same as the " Goto 0 " option on screen）
// Command23 : e0 94 00 tCHK
// Return e0 , result (uint8_t), rCHK.
// result:
// 01- successful;
// 00- Failure
// For example:
// Send "e0 94 00 74"
// return "e0 01 e1" (successful)

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

// command 32: e0 f7 tCHK
// stop the motor.
// Return e0 and the result (uint8_t) and rCHK.
// result:
// 01- successful;
// 00- Failure
// Example:
// Send e0 f7 d7
// return e0 01 e1 (successful)

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

#define ReturnToZero 0
#define SetAcceleration 1
#define StopMotor 2