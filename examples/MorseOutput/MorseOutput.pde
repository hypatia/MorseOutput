#include <MorseOutput.h>

// pin, words per minute
MorseOutput morse(9, 10);

//text to be blinked out
//The example text is, of course, the first message Samuel Morse
//ever sent.  It was sent on 24 May 1844
String text = "What hath God wrought?";

void setup()
{
}

void loop()
{
  // iterate through the text
  for (int i = 0; i < text.length(); i++ ){
    morse.encode(text.charAt(i));
  }
  delay(1000);
}
