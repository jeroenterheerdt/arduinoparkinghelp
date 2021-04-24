# arduinoparkinghelp
A simple parking help that lights up an green LED when car is inside of garage otherwise a red LED
It can be ran on any Arduino. I run it on an one-chip Arduino (atmega328).
I used Doctek's excellent tutorial to get the one-chip Arduino flashed: https://www.instructables.com/Cheap-One-Chip-Arduino/

Required:
- atmega328 or another arduino
- 10k resistor when using atmega
- two leds (one green, one red) + resistors
- hc-sr04 ultrasonic sensor
- wires/breadboard/pcb and the like

See sketch below. Power this using 5V (from a simple USB plug for example).
![image](sketch.png?raw=true)

connections:
- atmega pin 1 --> 10k resistor --> vcc
- atmega pin 7 --> vcc
- atmega pin 8 --> gnd
- atmega pin 13 --> 560 ohm resistor (or whatever you need for your led) --> green led anode (long leg)
- atmega pin 14 --> 560 ohm resistor (or whatever you need for your led) --> red led anode (long leg)
- atmega pin 22 --> gnd
- atmega pin 20 --> vcc
- red / green led cathode --> gnd
- hc-sr04 vcc --> vcc
- hc-sr04 gnd --> gnd
- hc-sr04 trig --> atmega pin 18
- hc-sr04 echo --> atmega pin 19
