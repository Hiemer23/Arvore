/*
 * File:   Saida.h
 * Author: andrey.hiemer
 *
 * Created on 07 de Outubro de 2023, 10:01
 */

#ifndef SAIDAS_H
#define SAIDAS_H

// Struct type

typedef struct {
    volatile uint8_t *port;  // Registrador da Porta (PORTA, PORTB, etc.)
    volatile uint8_t *tris;  // Registrador de direção da Porta (TRISA, TRISB, etc.)
    uint8_t pinMask;         // Máscara do pino (BIT0, BIT1, etc.)
    uint8_t tempoTroca;      // Tempo em milissegundos para a troca de estado
    uint8_t valorAtual;      // Valor atual do pino (0 ou 1)
    uint8_t valorAnterior;   // Valor anterior do pino (0 ou 1)
    uint16_t ultimoTempo;    // Último tempo em que o pino foi alterado
} Pino_Saida;

// tempo
#define SAIDA_TASK_TIME 100

// Prototipos
void Task_Saida(void);
inline void Init_Saidas(void);

//Valores fixos
#define QTD_SAIDAS 5
#endif /* SAIDAS_H */
