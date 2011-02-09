/*
  MorseOutput.cpp - Library for flashing Morse code.
  Created by Leigh Honeywell, 8 Feb 2011.
  Inspired by David A. Mellis's tutorial at 
  http://www.arduino.cc/en/Hacking/LibraryTutorial
  BSD-Licensed (see LICENSE).
*/

#include "WProgram.h"
#include "MorseOutput.h"

// We'll calculate the dotting speed according to the PARIS spec:
// http://en.wikipedia.org/wiki/Morse_code
// which is basically (1.2 seconds) / WPM
// Dashes are 3 * speed
// Further details of inter-character spacing are here:
// http://en.wikipedia.org/wiki/Morse_code#Representation.2C_timing_and_speeds
int speed;

static const char *codes[] = {

"....",		/*32   */
"-.-.--",	/*33 ! */
".-..-.",	/*34 " */
"",		/*35 # */
"...-..-",	/*36 $ */
"",  		/*37 % */
".-...",  	/*38 & */
".----.",  	/*39 ' */
"-.--.",  	/*40 ( */
"-.--.-", 	/*41 ) */
"",  		/*42 * */
".-.-.",  	/*43 + */
"--..--",  	/*44 , */
"-....-",  	/*45 - */
".-.-.-",  	/*46 . */
"-..-.",  	/*47 / */
"-----",  	/*48 0 */
".----",  	/*49 1 */
"..---",  	/*50 2 */
"...--",  	/*51 3 */
"....-",  	/*52 4 */
".....",  	/*53 5 */
"-....",  	/*54 6 */
"--...",  	/*55 7 */
"---..",  	/*56 8 */
"----.",  	/*57 9 */
"---...", 	/*58 : */
"-.-.-.", 	/*59 ; */
"",  		/*60 < */
"-...-",  	/*61 = */
"",  		/*62 > */
"..--..",  	/*63 ? */
".--.-.",  	/*64 @ */
".-",  		/*65 A */
"-...",  	/*66 B */
"-.-.",  	/*67 C */
"-..",  	/*68 D */
".",  		/*69 E */
"..-.",  	/*70 F */
"--.",  	/*71 G */
"....",  	/*72 H */
"..",  		/*73 I */
".---",  	/*74 J */
"-.-",  	/*75 K */
".-..",  	/*76 L */
"--",  		/*77 M */
"-.",  		/*78 N */
"---",  	/*79 O */
".--.",  	/*80 P */
"--.-",  	/*81 Q */
".-.",  	/*82 R */
"...",  	/*83 S */
"-",  		/*84 T */
"..-",  	/*85 U */
"...-",  	/*86 V */
".--",  	/*87 W */
"-..-",  	/*88 X */
"-.--", 	/*89 Y */
"--..", 	/*90 Z */
"",  		/*91 [ */
"",  		/*92 \ */
"",  		/*93 ] */
"",  		/*94 ^ */
"..--.-",  	/*95 _ */
"",  		/*96 ` */
".-",  		/*97 a */
"-...",  	/*98 b */
"-.-.",  	/*99 c */
"-..",  	/*100 d */
".",  		/*101 e */
"..-.",  	/*102 f */
"--.",  	/*103 g */
"....",  	/*104 h */
"..",  		/*105 i */
".---",  	/*106 j */
"-.-",  	/*107 k */
".-..",  	/*108 l */
"--",  		/*109 m */
"-.",  		/*110 n */
"---",  	/*111 o */
".--.",  	/*112 p */
"--.-",  	/*113 q */
".-.",  	/*114 r */
"...",  	/*115 s */
"-",  		/*116 t */
"..-",  	/*117 u */
"...-",  	/*118 v */
".--",  	/*119 w */
"-..-",  	/*120 x */
"-.--",  	/*121 y */
"--..",  	/*122 z */

};

MorseOutput::MorseOutput(int pin, int wpm)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  _wpm = wpm;
  speed = 1200/_wpm;
}

void MorseOutput::dot()
{
  digitalWrite(_pin, HIGH);
  delay(speed);
  digitalWrite(_pin, LOW);
  delay(speed);  
}

void MorseOutput::dash()
{
  digitalWrite(_pin, HIGH);
  delay(speed*3);
  digitalWrite(_pin, LOW);
  delay(speed);
}

void MorseOutput::space()
{
  delay(speed*4);
}

void MorseOutput::encode(char letter)
{
  const char *code;

  if (letter > 32 || letter >= 122)
  {
    code = codes[letter - 32];

    for (int j = 0; code[j] != NULL; j++)
    {
      if (code[j] == '.') dot();
      if (code[j] == '-') dash();
    }
  }
  else if (letter == 32) 
  {
    delay(speed*4);
  }

  //delay at the end of a letter
  delay(speed*2);
}
