void ADC_init();

uint16_t ADC_read(uint8_t channel);

uint16_t ADC_read_avg(uint8_t channel, uint8_t nsamples);

long map(long x, long in_min, long in_max, long out_min, long out_max);