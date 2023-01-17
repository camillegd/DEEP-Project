/*
 *@file		main.c
 *@brief 	programme principal
 *@date 	01/12/2022
 *@author	C. Guyonnaud
 */


#include "stm32f1xx_hal.h"
#include "stm32f1_motorDC.h"
#include "stm32f1_uart.h"
#include "stm32f1_sys.h"
#include "stm32f1_gpio.h"
#include "macro_types.h"
#include "systick.h"
#include "moteur.h"
#include "ecran.h"
#include "jeu.h"




void writeLED(bool_e b)
{
	HAL_GPIO_WritePin(LED_GREEN_GPIO, LED_GREEN_PIN, b);
}

bool_e readButton(void)
{
	return !HAL_GPIO_ReadPin(BLUE_BUTTON_GPIO, BLUE_BUTTON_PIN);
}

static volatile uint32_t t = 0;
void process_ms(void)
{
	if(t)
		t--;
}


int main(void)
{
	//Initialisation de la couche logicielle HAL (Hardware Abstraction Layer)
	//Cette ligne doit rester la premi�re �tape de la fonction main().
	HAL_Init();

	//Initialisation de l'UART2 � la vitesse de 115200 bauds/secondes (92kbits/s) PA2 : Tx  | PA3 : Rx.
		//Attention, les pins PA2 et PA3 ne sont pas reli�es jusqu'au connecteur de la Nucleo.
		//Ces broches sont redirig�es vers la sonde de d�bogage, la liaison UART �tant ensuite encapsul�e sur l'USB vers le PC de d�veloppement.
	UART_init(UART2_ID,115200);

	//"Indique que les printf sortent vers le p�riph�rique UART2."
	SYS_set_std_usart(UART2_ID, UART2_ID, UART2_ID);

	//Initialisation du port de la led Verte (carte Nucleo)
	BSP_GPIO_PinCfg(LED_GREEN_GPIO, LED_GREEN_PIN, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH);

	//Initialisation du port du bouton bleu (carte Nucleo)
	BSP_GPIO_PinCfg(BLUE_BUTTON_GPIO, BLUE_BUTTON_PIN, GPIO_MODE_INPUT,GPIO_PULLUP,GPIO_SPEED_FREQ_HIGH);

	//On ajoute la fonction process_ms � la liste des fonctions appel�es automatiquement chaque ms par la routine d'interruption du p�riph�rique SYSTICK
	Systick_add_callback_function(&process_ms);

	//init_ecran();
	//affichage_ecran_accueil();
	//affichage_ecran_validation();
	//affichage_ecran_joueurs(6);
	//choix_jeu();
	//XPT2046_demo();
	//affichage_ecran_en_cours();
	//affichage_ecran_final();
	//BSP_GPIO_PinCfg(GPIOA, GPIO_PIN_0, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_HIGH);

	while(1)	//boucle de tache de fond
	{
		state_machine();
		/*HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
		HAL_Delay(10);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 1);*/
		/*DEMO_MOTOR_statemachine(FALSE,'B');
		DEMO_MOTOR_statemachine(FALSE, '+');*/
	}


}
