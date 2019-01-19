/* 
 * File:   dsp.h
 * Author: main
 *
 * Created on 18. Januar 2019, 23:41
 */

#ifndef DSP_H
#define	DSP_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <dsp.h>



#ifdef SPIBUF_IN_EDS
//FIXME: fix function to work with __eds__ buffers
void process_buffer(uint16_t points, __eds__ fractional *buffer, __eds__ fractional *outbuffer, void (*process_fn)(void));
#else
void process_buffer(uint16_t points, fractional *buffer, fractional *outbuffer, void (*process_fn)(void));
#endif



#ifdef	__cplusplus
}
#endif

#endif	/* DSP_H */

