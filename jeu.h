/*
 * state_machine.h
 *
 *  Created on: 23 déc. 2022
 *      Author: camil
 */

#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_

#include "config.h"

typedef enum
{
	INIT = 0,
	SELECTION_JEU,
	PRESIDENT,
	KEMS,
	PYRAMIDE,
	ETAT_FINAL,
}state_e;
static state_e state = INIT;

typedef enum
	{
		JOUEURS = 0,
		VALIDATION,
	}kems_e;
static kems_e state_kems = JOUEURS;


void state_machine(void);
void init(void);
uint8_t selection_jeu();
void president(void);
void kems(void);
void pyramide(void);
void etat_final(void);
void old_kems(void);
uint8_t sm_selection_jeu();

#endif /* STATE_MACHINE_H_ */
