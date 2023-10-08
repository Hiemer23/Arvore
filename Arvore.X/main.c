/*
 * File:   main.c
 * Author: Andrey
 *
 * Created on 7 de Outubro de 2023, 15:53
 */


#include "main.h"

// timers
uint8_t counter_100ms = 0; // MODBUS

void __interrupt() interruptsManager(void) {

    if (INTCONbits.T0IE && INTCONbits.T0IF) {
        TMR0 = 6;
        INTCONbits.TMR0IF = 0;
        counter_100ms++;
    }
}

void tempo100_ms(void) {
    Task_Saida();
}

void main(void) {
    Inicializar_Hardware();
    __delay_us(10);
    while (1) {
        if (counter_100ms >= 100) {
            tempo100_ms();
            counter_100ms = 0;
        }
    }
    return;
}
