#include "timer0.h"

void wait_us(uint32_t duration)
{
  uint32_t lastTime = micros();
  while (micros() - lastTime < duration)
  {
    asm("nop");
    // wait
  }
}

void wait_ms(uint32_t duration)
{
  uint32_t lastTime = millis();
  while (millis() - lastTime < duration)
  {
    asm("nop");
    // wait
  }
}
