/*
 * ecran.h
 *
 *  Created on: 13 déc. 2022
 *      Author: camil
 */

#ifndef ECRAN_H_
#define ECRAN_H_

#include "config.h"

void init_ecran(void);
void affichage_ecran_accueil(void);
void affichage_ecran_validation(uint8_t choix);
void affichage_ecran_joueurs(uint8_t nb_joueurs);
void affichage_ecran_final(void);
void affichage_ecran_en_cours(void);
void affichage_ecran_validation_joueurs(uint8_t nb_joueurs);
void test_choix(void);
uint8_t nombre_joueurs_president();
uint8_t nombre_joueurs_kems();
uint8_t choix_jeu();
uint8_t validation_param();


#endif /* ECRAN_H_ */
