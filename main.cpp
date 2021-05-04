#include "mbed.h"
#include "TextLCD.h"
#include "keypad.h"

TextLCD lcd(p5, p6, p10, p9, p8, p7); //RS, RW, D4, D5, D6, D7
Keypad telepad(p27, p28, p29, p30, p23, p24, p25, p26); // Init Keypad


PwmOut green_led(p21); // Green Led woring on PWM mode at pin p21

PwmOut red_led(p22); // Red Ledworing on PWM mode at pin p22
int main()
{
    
char key; // Varible to store enterd key in
    
char missing_key = 'A'; // The correct missing key
char key_pressed = 1; // flag to make press as one enter operation 
while(1) {
// Write the word in the first row
lcd.locate(0,0);
lcd.printf("_hmed");
key = telepad.getKey(); /* store pressed key to check if it is correct*/
/* wait unitl the user let the key*/
if (key != KEY_RELEASED && key_pressed ==1) {
// select the second row to write the Letter
lcd.locate(0,1);
lcd.putc(key);
// wrong Enter
if (key != missing_key) {
// Set Red LED ON for 1 second then set it off again for 1 second
red_led.period(2); // 2 second period total period on and off
red_led.pulsewidth(1); // 1 second pulse (on)
}
// Correct Guessing
else {
// Set Green LED ON for 1 second then set it off again for 1 second
green_led.period(2); // 2 second period total period on and off
green_led.pulsewidth(1); // 1 second pulse (on)


}

wait(2); // wait the total period 2 second 

key_pressed = 0; // now keypad can't repeat entering


green_led = 0; // clear value of green led
red_led = 0; // clear values of red led and it is also buzzer led

} else {
    // now key pad is released and ready to accept new enter
key_pressed = 1; // now key pad is released and ready to accept new enter
}
}
}