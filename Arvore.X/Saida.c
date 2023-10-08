/*
 * File:   saida.c
 * Author: Andrey
 *
 * Created on October 7, 2023, 7:35 PM
 */

#include "main.h"

//Declaracao dos pinos usados
Pino_Saida Pino[QTD_SAIDAS];

//Prototipo

void acionaSaida(Pino_Saida *pino);

inline void Init_Saidas(void) {
    uint8_t initial_value = 0, i = 0;
    //OUT1
    Pino[0].port = &PORTA;
    Pino[0].tris = &TRISA;
    Pino[0].pinMask = 0b00000001; // PORTA0
    Pino[0].tempoTroca = 1 * SAIDA_TASK_TIME;
    Pino[0].valorAtual = initial_value;
    Pino[0].valorAnterior = !initial_value;
    Pino[0].ultimoTempo = 0;

    //OUT2
    Pino[1].port = &PORTA;
    Pino[1].tris = &TRISA;
    Pino[1].pinMask = 0b00000010; // PORTA1
    Pino[1].tempoTroca = 1 * SAIDA_TASK_TIME;
    Pino[1].valorAtual = initial_value;
    Pino[1].valorAnterior = !initial_value;
    Pino[1].ultimoTempo = 0;

    //OUT3
    Pino[2].port = &PORTA;
    Pino[2].tris = &TRISA;
    Pino[2].pinMask = 0b00000100; // PORTA2
    Pino[2].tempoTroca = 1 * SAIDA_TASK_TIME;
    Pino[2].valorAtual = initial_value;
    Pino[2].valorAnterior = !initial_value;
    Pino[2].ultimoTempo = 0;

    //OUT4
    Pino[3].port = &PORTA;
    Pino[3].tris = &TRISA;
    Pino[3].pinMask = 0b00010000; // PORTA4
    Pino[3].tempoTroca = 1 * SAIDA_TASK_TIME;
    Pino[3].valorAtual = initial_value;
    Pino[3].valorAnterior = !initial_value;
    Pino[3].ultimoTempo = 0;

    //OUT5
    Pino[4].port = &PORTA;
    Pino[4].tris = &TRISA;
    Pino[4].pinMask = 0b01000000; // PORTA6
    Pino[4].tempoTroca = 1 * SAIDA_TASK_TIME;
    Pino[4].valorAtual = initial_value;
    Pino[4].valorAnterior = !initial_value;
    Pino[4].ultimoTempo = 0;

    //Define os pinos como saida(tris + pinmask = 0) ex: TRISA0 = 0;
    for (i = 0; i < QTD_SAIDAS; i++) {
        *(Pino[0].tris) &= ~(Pino[0].pinMask);
    }
}

void Task_Saida(void) {
    uint8_t i = 0;
    for (i = 0; i < 5; i++) {
        if (Pino[i].ultimoTempo <= 0) {
            if ((Pino[i].valorAtual != Pino[i].valorAnterior)) {
                Pino[i].valorAnterior = Pino[i].valorAtual;
                acionaSaida(&Pino[i]);
                continue;
            }
        } else {
            Pino[i].ultimoTempo -= SAIDA_TASK_TIME;
        }
    }
}

void acionaSaida(Pino_Saida *pino) {
    if (pino->valorAtual) {
        *(pino->port) |= (pino->pinMask); // Liga o pino
    } else {
        *(pino->port) &= ~(pino->pinMask); // Desliga o pino
    }
}
