#include "spi.hpp"
#include <avr/io.h>

#define SPI_PORT PORTB
#define SPI_DDR DDRB

void spi_init(uint8_t lsbfirst, uint8_t master, uint8_t mode, uint8_t clkrate, uint8_t dblclk)
{
    // set outputs
    SPI_DDR |= ((1 << SPI_MOSI) | (1 << SPI_SCK) |
                (1 << SPI_SS)); // set SS pin to output since it is necessary
                                // in master mode to work properly

    // set inputs
    SPI_DDR &= ~(1 << SPI_MISO);
    SPI_PORT |= (1 << SPI_MISO); // turn on pull-up resistor

    // set SPI control register
    SPCR = ((1 << SPE) |                 // enable SPI
            ((lsbfirst & 0b1) << DORD) | // set msb/lsb ordering
            ((master & 0b1) << MSTR) |   // set master/slave mode
            ((mode & 0b11) << CPHA) |    // set mode
            ((clkrate & 0b11) << SPR0)   // set speed
    );

    // set double speed bit
    SPSR = ((dblclk & 0b1) << SPI2X);
}

void spi_send(uint8_t value)
{
    // shift the first byte of the value
    SPDR = value;

    // wait for the SPI bus to finish
    while (!(SPSR & (1 << SPIF)))
        ;
}

uint8_t spi_receive()
{
    return SPDR;
}
