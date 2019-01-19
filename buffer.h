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


void buffer_copy(uint16_t length, fractional *buffer, fractional *outbuffer);
void convert_samplerate(uint16_t length, fractional *buffer, fractional *outbuffer);

#ifdef	__cplusplus
}
#endif

#endif	/* BUFFER_H */

