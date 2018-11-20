/* 
 * File:   sine.h
 * Author: main
 *
 * Created on 6. Oktober 2018, 15:14
 */

#ifndef SINE_H
#define	SINE_H

#ifdef	__cplusplus
extern "C" {
#endif


#define PI                  3.1428571428571428571428571428571
#define SINE_TABLE_TYPE     uint32_t
#define SINE_POINTS         4096

__prog__ extern SINE_TABLE_TYPE sine_table[SINE_POINTS] __attribute__((space(prog)));

extern volatile uint16_t last_dds_step_r;
extern volatile uint16_t last_dds_step_l;


//void sine_lookup_table_init();
SINE_TABLE_TYPE get_sine_value(uint16_t index);
void set_dds_step(uint8_t samplerate, float frequency_l, float frequency_r);
void fill_sine_buffer(uint16_t *buffer, uint16_t len);



#ifdef	__cplusplus
}
#endif

#endif	/* SINE_H */

