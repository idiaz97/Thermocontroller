#include "Display.h"
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

void setup() {
  Display test(rs,en,d4,d5,d6,d7);
  test.updateData(10,10,50);
  test.printData();
  test.changeDisplayMode();
  test.printData();
}

void loop() {
  // put your main code here, to run repeatedly:

}
