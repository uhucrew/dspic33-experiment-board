/* 
 * File:   buffer.h
 * Author: main
 *
 * Created on 18. Januar 2019, 20:12
 */

#ifndef BUFFER_H
#define	BUFFER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <dsp.h>

void buffer_copy(uint16_t length, fractional *buffer, fractional *outbuffer);
void buffer_copy_offset(uint16_t length, uint16_t offset, uint16_t *buffer, uint16_t *outbuffer);
void buffer_copy_offset_sum(uint16_t length, uint16_t offset, fractional *buffer, fractional *outbuffer);
void buffer_copy_ad_fractional(uint16_t length, fractional *buffer, fractional *outbuffer, bool mono);
void convert_samplerate(uint16_t length, uint16_t samplerate_ratio, uint16_t input32bit, fractional *buffer);
void scale_buffer(uint16_t length, fractional *buffer, fractional ad_max_factor);
void buffer_put_sine_asm(uint16_t length, fractional *buffer, bool mono, uint32_t *phase_jump, fractional scale, uint32_t *phase_accu);
 


#ifdef	__cplusplus
}
#endif

#endif	/* BUFFER_H */

