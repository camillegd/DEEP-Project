/*
 *@file		moteur.c
 *@brief 	programme des moteurs à courant continu
 *@date 	13/12/2022
 *@author	C. Guyonnaud
 */

#include "moteur.h"
#include "stm32f1_motorDC.h"

/**
 * @brief	Cette fonction fait tourner les deux moteurs dans un même sens pour faire avancer le robot.
 */
void avance(){
	DEMO_MOTOR_statemachine(FALSE,'A');
	DEMO_MOTOR_statemachine(FALSE, '+');
	DEMO_MOTOR_statemachine(FALSE, 'B');
	DEMO_MOTOR_statemachine(FALSE,'+');
}


/**
 * @brief	Cette fonction fait tourner les deux moteurs dans un même sens pour faire reculer le robot.
 */
void recule(){
	DEMO_MOTOR_statemachine(FALSE,'A');
	DEMO_MOTOR_statemachine(FALSE, '-');
	DEMO_MOTOR_statemachine(FALSE, 'B');
	DEMO_MOTOR_statemachine(FALSE,'-');
}


/**
 * @brief	Cette fonction fait tourner un moteur dans un sens pour faire tourner le robot à gauche.
 */
void tourne_gauche(){
	DEMO_MOTOR_statemachine(FALSE,'A');
	DEMO_MOTOR_statemachine(FALSE, '+');
	DEMO_MOTOR_statemachine(FALSE, 'B');
	DEMO_MOTOR_statemachine(FALSE,'0');
}


/**
 * @brief	Cette fonction fait tourner un moteur dans un sens pour faire tourner le robot à droite.
 */
void tourne_droite(){
	DEMO_MOTOR_statemachine(FALSE,'A');
	DEMO_MOTOR_statemachine(FALSE, '0');
	DEMO_MOTOR_statemachine(FALSE, 'B');
	DEMO_MOTOR_statemachine(FALSE,'+');
}

/*
 * @brief	mélange des cartes
 */
void melange(){

}
