/* 
 * File:   pps.h
 * Author: main
 *
 * Created on 28. Oktober 2018, 18:46
 */

#ifndef PPS_H
#define	PPS_H

#ifdef	__cplusplus
extern "C" {
#endif


#define     _VSS        0b0000000
#define     _C1OUTPI    0b0000001
#define     _C2OUTPI    0b0000010
#define     _C3OUTPI    0b0000011
#define     _C4OUTPI    0b0000100
#define     _PTGO30     0b0000110
#define     _PTGO31     0b0000111
#define     _FINDX1     0b0001000
#define     _FHOME1     0b0001001
#define     _RP20       0b0010100
#define     _RPI24      0b0011000
#define     _RPI25      0b0011001
#define     _RPI27      0b0011011
#define     _RPI28      0b0011100
#define     _RPI32      0b0100000
#define     _RPI33      0b0100001
#define     _RPI34      0b0100010
#define     _RP35       0b0100011
#define     _RP36       0b0100100
#define     _RP37       0b0100101
#define     _RP38       0b0100110
#define     _RP39       0b0100111
#define     _RP40       0b0101000
#define     _RP41       0b0101001
#define     _RP42       0b0101010
#define     _RP43       0b0101011
#define     _RPI44      0b0101100
#define     _RPI45      0b0101101
#define     _RPI46      0b0101110
#define     _RPI47      0b0101111
#define     _RPI51      0b0110011
#define     _RPI52      0b0110100
#define     _RPI53      0b0110101
#define     _RP54       0b0110110
#define     _RP55       0b0110111
#define     _RP56       0b0111000
#define     _RP57       0b0111001
#define     _RPI58      0b0111010
#define     _RPI94      0b1011110
#define     _RPI95      0b1011111
#define     _RPI96      0b1100000
#define     _RP97       0b1100001
#define     _RP118      0b1110110
#define     _RPI119     0b1110111
#define     _RP120      0b1111000
#define     _RPI121     0b1111001

#define     _DEF_PPS    0b000000
#define     _U1TX       0b000001
#define     _U2TX       0b000011
#define     _SDO2       0b001000
#define     _SCK2       0b001001
#define     _SS2        0b001010
#define     _C1TX       0b001110
#define     _OC1        0b010000
#define     _OC2        0b010001
#define     _OC3        0b010010
#define     _OC4        0b010011
#define     _C1OUTPO    0b011000
#define     _C2OUTPO    0b011001
#define     _C3OUTPO    0b011010
#define     _SYNCO1     0b101101
#define     _QEI1CCMP   0b101111
#define     _REFCLKO    0b110001
#define     _C4OUTPO    0b110010

    
#ifdef	__cplusplus
}
#endif

#endif	/* PPS_H */
