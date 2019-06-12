#pragma once

#include <stdint.h>

/*
 * initialize the SPI bus
 *  @param lsbfirst - if 0: most significant bit is transmitted first
 *  @param master - if 1: use master mode, if 0: slave mode is used
 *  @param mode - sets the transfer mode:
 *          mode   leading clock edge   trailing clock edge
 *          -----------------------------------------------
 *          0      sample (rising)      setup  (falling)
 *          1      setup  (rising)      sample (falling)
 *          2      sample (falling)     setup  (rising)
 *          3      setup  (falling)     sample (rising)
 *  @param clkrate - spi bus clock rate, valid speeds are 0-3
 *          rate   speed
 *          ------------
 *          0      CPUCLK/4
 *          1      CPUCLK/16
 *          2      CPUCLK/64
 *          3      CPUCLK/128
 *  @param dblclk - if 1: doubles the SPI clock rate in master mode
 */
void spi_init(uint8_t lsbfirst, uint8_t master, uint8_t mode, uint8_t clkrate, uint8_t dblclk);

/*
 *  shifts out 8 bits of data
 *  @param  data the data to be shifted out
 */
void spi_send(uint8_t value);

/*
 * @return the data received during sending
 */
uint8_t spi_receive();
