# Guess The Missing Letter Using mbed lpc1768
![alt text](https://github.com/MohamedOsamaAhmed/Guess-The-Missing-Letter-Using-mbed-lpc1768/blob/main/logo.jpg?raw=true)

## Summary 
This is an application on using LCD with keypad to make meaningful combination or in other words usable application. It is implemented using lpc1768 Microcontroller which is ARM based and mbed platform with its own libraries.

## Description
>The idea of this project is that LCD displays a word with missing letter and asking user to guess the correct letter through writing using keypad 4×4 which includes only four letters which is considered a limitation of our App. If the user entered the correct letter the green led will light on for 1 second Using PWM module. And if the user entered wrong letter the red Led will light on for 1 second and the buzzer also will work and buzz for the same time also PWM is used here.


## Functions and their descriptions
1. **LCD**
•	TextLCD lcd (p5, p6, p10, p9, p8, p7); //RS, RW, D4, D5, D6, D7
This is used to initialize LCD ports (data ports D4:7 and control ports RS and RW).

    •	lcd.locate(column_number[0:16], row_number[0:1]);
This is used to select the position of start writing on LCD where our LCD is 2 * 16 => 2 rows and 16 columns. 

    •	lcd.printf("Text");
    This is used to display a string Text on the LCD.

    •	lcd.putc('A');
    This is used to display a one char like 'A' on the LCD.



2. **Keypad**
•	Keypad telepad(p27, p28, p29, p30, p23, p24, p25, p26);
This is used to initialize Keypad ports.

    •	getKey();
    This is used to get the entered key by the keypad.



3. **PWM**
•	PwmOut green_led(p21); and PwmOut red_led(p22);
This to make p21 and p22 pins to operate in PWM output mode.

    •	red_led.period(); and green_led.period();
    This to set the PWM period, specified in seconds (float).

    •	red_led.pulsewidth(); and green_led.pulsewidth();
    This to Set the PWM pulsewidth, specified in seconds (float).
    
4. **Others**
    •	wait(n);
    This for waiting for n seconds with doing nothing. 
	

## Flowchart
![alt text](https://github.com/MohamedOsamaAhmed/Guess-The-Missing-Letter-Using-mbed-lpc1768/blob/main/Flowchart.png?raw=true)


## Pseudocode

1.	Initialize LCD, Keypad and PWM output Pins
2.	Display word with missing letter
3.	Ask user to enter key
4.	If key is correct
    Green Led On for 1 Second then Off for 1 second ... repeat 2

5.	Else
    Red Led and Buzzer On for 1 Second then Off for 1 second ... repeat 2


## Issues
  > • 	**•	PWM Mode need function wait() to work properly as it isn’t containing internal waiting           as I thought.** 
  
  > •	**•	LCD needs to allocate where it will display using locate(columns, row) function I was           overwrite the first line every time till I knew this..**
   
  > •	**•	Key_pressed flag is very important to accept from the user only one insertion at one          time not many at one time as if I pressed wait till, I release to start checking again.** 

## How to Compile and build?

You can use https://ide.mbed.com/ for compiling and building your code

## User Manual

1.	LCD will display uncompleted word for you 
2.	Your role to guess the missing letter and enter it using Keypad letters
3.	If your guessing is correct Green Led will light on then game is end
4.	Else Red Led will light on and also Buzzer for 1 second then you can try enter another letter again 




