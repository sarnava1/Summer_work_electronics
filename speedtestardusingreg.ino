/********************************************************
 * setup() function
 *
 * Set B5 (Digital pin 13) to output by changing the DDRB
 * register instead of using pinMode().
 *******************************************************/
void setup()
{
  DDRB = B00100000;
}

/****************************************************************
 * loop() function
 *
 * Turn the LED attached to B5 (Digital pin 13) on and off
 * by changing the PORTB register instead of using digitalWrite().
 * Herein I have decided to comment out the delay functions as I wanted to do a speed test using arduino
 * Although I have used DDRB Regiter to setuop my pinMode but the normal pinMode would have worked ffine as the setup function only runs once
 * One thing: for speed test use a pin which is not PWM pin coz PWM pin has to check some more if else in their library
 * PWM pins are slower than others, because they have PWM timers that have to be disengaged.
 *  The while statement will be optimized to a relative  jump, which is a two clock instruction - so the whole loop should be 6 clock cycles long as:
 *  SBI and CBI are 2-cycle instructions (I guess that makes sense, since they're read-modify-write), as is the jmp, so 2.66666 MHz is exactly as expected after all!(16/6=2.6666)
 *  SBI and CBI are setting and clearing bits
 *  for more info on this:
 *  1.http://forum.arduino.cc/index.php?topic=4324.0
 *  2.https://playground.arduino.cc/Main/AVR
 *  http://www.instructables.com/id/Fast-digitalRead-digitalWrite-for-Arduino/
 *  https://www.arduino.cc/en/Reference/PortManipulation
 *   while (1) {
       PORTD = ones;
       PORTD = zeros;
 }
 Gives me 4Mhz (and noticeably not "square wave."  Adding a nop makes it more square but changes the max freq to about 3.2MHz.
 Adding two nops makes for very square, but back to 2.667MHz.)
DDRD = B11111110;  // sets Arduino pins 1 to 7 as outputs, pin 0 as input
DDRD = DDRD | B11111100;  // this is safer as it sets pins 2 to 7 as outputs
                    // without changing the value of pins 0 & 1, which are RX & TX 

 ****************************************************************/
void loop()
{
  PORTB = B00100000; //Turn LED on.
  //delay(1000);
  PORTB = B00000000; //Turn LED off.
  //delay(1000);
}

/* to read the state of a pin we can use the PIN register for the B,C,D bank of pins. like suppose if we give digital pin 8 as our input and then want to check what state it is in then:
 *  if ((PINB & B00000001)==1){
 *     then do something
 *  this is how we check the states of the input pins
 *  if we want to check the state of suppose digital pin 9 
 *  if ((PINB & B00000010)==2){
 *     then do something
 *  if ((PINB & B00000100)==4){   
 *     then do something
 */

 
