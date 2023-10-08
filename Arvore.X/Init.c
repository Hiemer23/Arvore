/*
 * File:   Init.c
 * Author: Andrey
 *
 * Created on 7 de Outubro de 2023, 16:23
 */


#include "main.h"

//Prototipos
inline void Init_Osc(void);
//inline void Init_IO(void);
inline void Init_Timer(void);

void Inicializar_Hardware(void) {
    Init_Osc();
    Init_Timer();
    Init_Saidas();

    PEIE = 1;

    GIE = 1;
}

void Init_Osc(void) {
    //Indica a frequencia de trabalho
    PCONbits.OSCF = 1;
    __delay_ms(10);
}

void Init_Timer(void) {
    OPTION_REGbits.nRBPU = 1; //PORTB pull-ups are disabled
    OPTION_REGbits.PSA = 0; //Prescaler is assigned to the Timer0 module
    OPTION_REGbits.PS = 1; //Prescaler definido 1:4
    T0IE = 1; //Enables the TMR0 interrupt
    TMR0 = 6; //Inicia o Timer0 em 6
}