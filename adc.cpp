void ADC_init()
{
    // ADC einschalten und Prescaler 8 - 8MHz system clock -> 1MHz ADC Clock
    ADCSRA |= (1 << ADEN) | (1 << ADPS1) | (1 << ADPS0);

    ADC_read(0); // dummy Wandlung
}

uint16_t ADC_read(uint8_t channel)
{
    ADMUX = channel;             // select input
    ADCSRA |= (1 << ADSC);       // Wandlung starten
    while (ADCSRA & (1 << ADSC)) // Wandlung abwarten
    {
    }

    return ADCW; // ADC auslesen und zurückgeben
}

/* ADC Mehrfachmessung mit Mittelwertbbildung */
// nsamples <=64!!
uint16_t ADC_read_avg(uint8_t channel, uint8_t nsamples)
{
    uint16_t sum = 0;
    for (uint8_t i = 0; i < nsamples; ++i)
    {
        sum += ADC_read(channel);
    }

    return (uint16_t)(sum / nsamples);
}

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}