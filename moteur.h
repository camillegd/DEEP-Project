/*
 * moteur.h
 *
 *  Created on: 13 déc. 2022
 *      Author: camil
 */

#ifndef MOTEUR_H_
#define MOTEUR_H_

#include "config.h"

void avance(void);
void recule(void);
void tourne_gauhce(void);
void tourne_droite(void);
void melange(void);
void distribution_kems(uint8_t nb_joueurs);

#endif /* MOTEUR_H_ */
