// source: https://playground.arduino.cc/Main/TimerPWMCheatsheet
// good explanation: http://www.righto.com/2009/07/secrets-of-arduino-pwm.html

// Frequencies assume 16MHz clock


// good lib, not used here:
// https://github.com/yuvadm/arduino-playground/blob/master/vga-more/src/TimerHelpers.h




// timer0: pins 5 & 6; TIME (millis(), and delay()).
// Fast PWM mode (2x as fast)
// fast PWM holds the output high one cycle longer than the compare register value
// Arduino cheats: value of 0 should yield duty cycle 1/256.
// There is instead a jump straight from 0/256 to 2/256.
TCCR0B = (TCCR0B & 0b11111000) | 0x01 // changes only clock, keeping rest
// 0x01, prescaler 1,		62500Hz
// 0x02, prescaler 8,		7812.5Hz
// 0x03, prescaler 64,	976.5625Hz; default
// 0x04, prescaler 256,	244.140625Hz
// 0x05, prescaler 1024,	61.03515625Hz


// timer1: pins 9 & 10
// Phase-correct mode.
TCCR1B = (TCCR1B & 0b11111000) | 0x01
// 0x01, prescaler 1,		31372.55Hz
// 0x02, prescaler 8,		3921.16Hz
// 0x03, prescaler 64,	490.20Hz; default
// 0x04, prescaler 256,	122.55Hz
// 0x05, prescaler 1024,	30.64Hz


// timer2: pins 3 & 11
// Phase-correct mode, has more prescalers:
TCCR2B = (TCCR2B & 0b11111000) | 0x01
// 0x01, prescaler 1,		31372.55Hz
// 0x02, prescaler 8,		3921.16Hz
// 0x03, prescaler 32,	980.39Hz;
// 0x04, prescaler 64,	490.20Hz; default
// 0x05, prescaler 128,	245.10Hz
// 0x06, prescaler 256, 122.55Hz
// 0x07, prescaler 1024, 30.64Hz





// more detailed: https://www.sparkfun.com/datasheets/Components/SMD/ATMega328.pdf
// example usage: TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM20);
// bits:
// TCCR2A: Timer/Counter Control Register A (Usually don't change)
// TCCR0B: Timer/Counter Control Register B (last 3 bits for prescaler)
// TCNT0: direct access to counter. Risk missing a match against OCR0x!
// OCR0A, OCR0B: value to compare counter against - e.g. OCR0A=7 will, in certain mode, count up to 8

