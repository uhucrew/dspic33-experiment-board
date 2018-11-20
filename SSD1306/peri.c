/*******************************************************************************
 * File:        peri.c
 * Project:     SP18 - I2C OLED Display
 * Author:      Nicolas Pannwitz
 * Version:     
 * Web:         http://pic-projekte.de
 ******************************************************************************/

#include <xc.h>
#include <stdint.h>

/*******************************************************************************
 * I2C
 */

void initI2C(void)
{
    /* Zugehörige Tris-Bits auf Input schalten */
    /* Master-Mode - Clock = Fosc / (4*(SSPxADD+1)) */  
    /* SSPxADD values of 0, 1 or 2 are not supported for I2C Mode */
        
    SSP1CON1bits.SSPM3 = 1;
    SSP1CON1bits.SSPM2 = 0;
    SSP1CON1bits.SSPM1 = 0;
    SSP1CON1bits.SSPM0 = 0;
    SSP1CON1bits.SSPEN = 1;
    SSP1ADD = 9;                      // für 200kHz (Fosc = 8 MHz)
    SSP1CON2bits.ACKDT = 0;
}

void waitI2C(void)
{
    while(!PIR1bits.SSP1IF);          // Aktion* wurde beendet
    PIR1bits.SSP1IF = 0;              // Flag zurücksetzten
} 
 
// *Zum Beispiel: START-Sequenze, Übertragung von 8 Bit, ...

void idleI2C(void)
{
    while( SSP1STATbits.R_W );        // Läuft eine Übertragung?
    while( SSP1CON2 & 0x1F );         // Ist irgendwas anderes aktiv?
}

void startI2C(void)
{
    idleI2C();                        // Ist der Bus frei?
    SSP1CON2bits.SEN = 1;             // Auslösen einer START-Sequenze
    while( SSP1CON2bits.SEN );        // Beendet, wenn SEN gelöscht wurde*
}
 
void restartI2C(void)
{
    idleI2C();                        // Ist der Bus frei?
    SSP1CON2bits.RSEN=1;              // Auslösen einer RESTART-Sequenze
    while( SSP1CON2bits.RSEN );       // Beendet, wenn RSEN gelöscht wurde*
}
 
void stopI2C(void)
{
    idleI2C();                        // Ist der Bus frei?
    SSP1CON2bits.PEN = 1;             // Auslösen einer RESTART-Sequenze
    while( SSP1CON2bits.PEN );        // Beendet, wenn RSEN gelöscht wurde*
}
 
// *Oder das Bit SSPxIF gesetzt wurde (siehe Datenblatt)

uint8_t sendI2C(uint8_t byte)
{
    idleI2C();                        // Ist der Bus verfügbar?
    PIR1bits.SSP1IF = 0;              // Flag löschen (wird in waitI2C() abgefragt)
    SSP1BUF = byte;                   // Durch füllen des Puffers Sendevorgang auslösen
    waitI2C();                        // Warten bis Übertragung abgeschlossen ist
 
    return ~SSP1CON2bits.ACKSTAT;     // Return 1: ACK empfangen, 0: kein ACK empfangen
}

uint8_t reciveI2C_nack(void)
{
    uint8_t incomming = 0;            // Einlesepuffer
 
    idleI2C();                        // Ist der Bus verfügbar?
    PIR1bits.SSP1IF = 0;              // Flag löschen (wird in waitI2C() abgefragt)
    SSP1CON2bits.RCEN = 1;            // Als Empfänger konfigurieren (wird autom. wieder gelöscht)
    waitI2C();                        // Warten bis Übertragung (lesend) abgeschlossen ist
    SSP1CON2bits.ACKDT = 1;           // Mit NACK quitieren (Nicht weiter einlesen)
    SSP1CON2bits.ACKEN = 1;           // NACK aussenden
    while( SSP1CON2bits.ACKEN );      // NACK abgeschlossen?
    incomming = SSP1BUF;              // Empfangenes Byte in den Puffer
        
    return incomming;                 // Und zurück geben
}
 
uint8_t reciveI2C_ack(void)
{
    uint8_t incomming = 0;            // Einlesepuffer
 
    idleI2C();                        // Ist der Bus verfügbar?
    PIR1bits.SSP1IF = 0;              // Flag löschen (wird in waitI2C() abgefragt)
    SSP1CON2bits.RCEN = 1;            // Als Empfänger konfigurieren (wird autom. wieder gelöscht)
    waitI2C();                        // Warten bis Übertragung (lesend) abgeschlossen ist
    SSP1CON2bits.ACKDT = 0;           // Mit AACK quitieren (weiter einlesen)
    SSP1CON2bits.ACKEN = 1;           // ACK aussenden
    while( SSP1CON2bits.ACKEN );      // ACK abgeschlossen?
    incomming = SSP1BUF;              // Empfangenes Byte in den Puffer
 
    return incomming;                 // Und zurück geben
}