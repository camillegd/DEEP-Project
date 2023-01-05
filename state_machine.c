/*
 *@file		state_machine.c
 *@brief 	programme de la machine à état
 *@date 	23/12/2022
 *@author	C. Guyonnaud
 */

#include "state_machine.h"
#include "ecran.h"
#include "moteur.h"
#include "stm32f1_ili9341.h"



/*
 * @brief 	machine à états permettant le fonctionnement du robot
 */
void state_machine(){
	uint8_t choix;
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

	switch(state){
		case INIT :
			init();
			state = SELECTION_JEU;
			break;
		case SELECTION_JEU :
			choix = selection_jeu();
			if(choix == 1){
				state = PRESIDENT;
			}else if(choix == 2){
				state = KEMS;
			}else if(choix == 3){
				state = PYRAMIDE;
			}
			break;
		case PRESIDENT :
			president();
			state = ETAT_FINAL;
			break;
		case KEMS :
			kems();
			state = ETAT_FINAL;
			break;
		case PYRAMIDE :
			pyramide();
			state = ETAT_FINAL;
			break;
		case ETAT_FINAL :
			etat_final();
			state = SELECTION_JEU;
			break;
		default :
			break;
	}
}



/*
 * @brief	initialisation de l'écran et du ruban de leds
 */
void init(){
	init_ecran();
}


/*
 * @brief 	fonction permettant de sélectionner un jeu à l'écran puis de valider la sélection
 * @return	le numéro correspondant au jeu sélectionné
 */
uint8_t selection_jeu(){
	uint8_t choix = 0;
	uint8_t valide = 0;
	affichage_ecran_accueil();
	choix = choix_jeu();
	while(choix != 0){
		affichage_ecran_validation(choix);
		while(valide == 0){
			valide = validation_param();
			if(valide==1){
				return choix;
			}else if (valide == 2){
				return 0;
			}
		}
	}
}


/*
 * @brief	mélange des cartes et distribution du jeu "président"
 */
void president(){
	uint8_t nb;
	nb = nombre_joueurs_president();


}


/*
 * @brief	mélange des cartes et distribution du jeu "kems"
 */
void kems(){
	uint8_t nb;
	nb = nombre_joueurs_kems();
	uint8_t valide = 0;
	affichage_ecran_validation_joueurs(nb);
	while(valide == 0){
		valide = validation_param();
	}
	melange();
	// faire toute la partie distribution avec  les moteurs
}


/*
 * @brief	mélange des cartes et mise en place du jeu "pyramide"
 */
void pyramide(){
	// faire toute la partie distribution avec  les moteurs
}


/*
 * @brief	affiche l'écran indiquant que la distribution est terminé et fait clignoter les leds deux fois
 */
void etat_final(){
	affichage_ecran_en_cours();
	affichage_ecran_final();
	HAL_Delay(1000);
	//ajouter les leds
}
