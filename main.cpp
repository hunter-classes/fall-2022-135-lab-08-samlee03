#include <iostream>
#include "funcs.h"
int main()
{
  //task a
  invert("inImage.pgm");
  //task b
  invert_half("inImage.pgm");
  //task c
  white_box("inImage.pgm");
  //task d
  white_frame("inImage.pgm");
  //task e
  scale("inImage.pgm");
  //task f
  pixel("inImage.pgm");
  return 0;
}
