/*
 *@file		moteur.c
 *@brief 	programme des moteurs � courant continu
 *@date 	13/12/2022
 *@author	C. Guyonnaud
 */

#include "moteur.h"
#include "stm32f1_motorDC.h"

/**
 * @brief	Cette fonction fait tourner les deux moteurs dans un m�me sens pour faire avancer le robot.
 */
void avance(){
	DEMO_MOTOR_statemachine(FALSE,'A');
	DEMO_MOTOR_statemachine(FALSE, '3');
	DEMO_MOTOR_statemachine(FALSE, 'B');
	DEMO_MOTOR_statemachine(FALSE,'3');
}


/**
 * @brief	Cette fonction fait tourner les deux moteurs dans un m�me sens pour faire reculer le robot.
 */
void recule(){
	DEMO_MOTOR_statemachine(FALSE,'A');
	DEMO_MOTOR_statemachine(FALSE, '-');
	DEMO_MOTOR_statemachine(FALSE, 'B');
	DEMO_MOTOR_statemachine(FALSE,'-');
}


/**
 * @brief	Cette fonction fait tourner un moteur dans un sens pour faire tourner le robot � gauche.
 */
void tourne_gauche(){
	DEMO_MOTOR_statemachine(FALSE,'A');
	DEMO_MOTOR_statemachine(FALSE, '+');
	DEMO_MOTOR_statemachine(FALSE, 'B');
	DEMO_MOTOR_statemachine(FALSE,'0');
}


/**
 * @brief	Cette fonction fait tourner un moteur dans un sens pour faire tourner le robot � droite.
 */
void tourne_droite(){
	DEMO_MOTOR_statemachine(FALSE,'A');
	DEMO_MOTOR_statemachine(FALSE, '0');
	DEMO_MOTOR_statemachine(FALSE, 'B');
	DEMO_MOTOR_statemachine(FALSE,'+');
}

/**
 * @brief	Cette fonction arr�te tous les moteurs.
 */
void arret(){
	DEMO_MOTOR_statemachine(FALSE,'A');
	DEMO_MOTOR_statemachine(FALSE, '0');
	DEMO_MOTOR_statemachine(FALSE, 'B');
	DEMO_MOTOR_statemachine(FALSE,'0');
}

/*
 * @brief	m�lange des cartes
 */
void melange(){

}


/*
 * @brief	distribue les cartes en fonction du nombres de joueurs pour le kem's
 */
void distribue_kems(uint8_t nb_joueurs){
	for(uint8_t i=0;i<nb_joueurs;i++){
		//moteur tourne pour 1 carte
		tourne_droite();
		Hal_Delay(1000);
		arret();
	}
}


/*
 * @brief	distribue les cartes en fonction du nombres de joueurs pour le president
 */
void distribue_president(uint8_t nb_joueurs){
	uint8_t nb_tours = 52/nb_joueurs;
	for(uint8_t j=0;j<nb_tours;j++){
		for(uint8_t i=0;i<nb_joueurs;i++){
			//moteur tourne pour 1 carte
			tourne_droite();
			Hal_Delay(1000);
			arret();
		}
	}
}


