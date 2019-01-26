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
void buffer_copy_ad_fractcomplex(uint16_t length, fractional *buffer, fractcomplex *outbuffer);
void convert_samplerate(uint16_t length, uint16_t samplerate_ratio, uint16_t input32bit, fractional *buffer);

#ifdef	__cplusplus
}
#endif

#endif	/* BUFFER_H */

