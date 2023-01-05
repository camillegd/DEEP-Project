/*
 * state_machine.h
 *
 *  Created on: 23 déc. 2022
 *      Author: camil
 */

#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_

#include "config.h"


void state_machine(void);
void init(void);
uint8_t selection_jeu();
void president(void);
void kems(void);
void pyramide(void);
void etat_final(void);

#endif /* STATE_MACHINE_H_ */
