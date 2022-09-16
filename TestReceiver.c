#include <stdio.h>
#include "BMS_Receiver.h"

int dummy_temp[50] = { 6,7,14,5,45,24,34,32,21,13,13,24,5,32,15,26,37,48,5,34,23,13,13,6,7,32,21,32,5,6,6,5,9,7,6,5,8,5,6,7,8,8,9,7,12,12,14,24,34,7};
int dummy_SoC[50] = {6,7,14,5,45,24,34,32,21,13,13,24,5,32,15,26,37,48,5,34,23,13,13,6,7,32,21,32,5,6,6,5,9,7,6,5,8,5,6,7,8,8,9,7,12,12,14,24,34,7};

void testMaxTemp(void)
{
  assert(getMaxTemp(dummy_temp) == 48);
}

void testMinTemp(void)
{
  assert(getMinTemp(dummy_temp) == 5);
}

void testMaxSoC(void)
{
  assert(getMaxSoC(dummy_SoC) == 48);
}

void testMinSoC(void)
{
  assert(getMinSoC(dummy_SoC) == 5);
}

int main()
{
  testMaxTemp();
  testMinTemp();
  testMaxSoC();
  testMinSoC();
}
