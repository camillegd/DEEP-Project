/*
 *@file		ecran.c
 *@brief 	programme de l'écran TFT tactile
 *@date 	13/12/2022
 *@author	C. Guyonnaud
 */

#include "ecran.h"
#include "stm32f1_ili9341.h"
#include "stm32f1_xpt2046.h"

uint8_t nb_joueurs;
char joueurs[32];
char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };



/*
 * @brief 	initialise les paramètres de l'affichage de l'écran et du tactile
 */
void init_ecran(){
	ILI9341_Init();
	XPT2046_init();
}

/**
 * @brief	affiche sur l'écran les différentes options de jeux
*/
void affichage_ecran_accueil(){
	ILI9341_Fill(ILI9341_COLOR_WHITE);
	ILI9341_DrawFilledRectangle(30, 10, 210, 45, ILI9341_COLOR_BLUE);
	ILI9341_Puts(62, 20,"Master Card",&Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
	ILI9341_Puts(55, 60, "Choisissez un jeu :", &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	ILI9341_DrawRectangle(10, 90, 990, 150, ILI9341_COLOR_BLACK);
	ILI9341_Puts(80, 115,"President", &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	ILI9341_DrawRectangle(10, 165, 990, 225, ILI9341_COLOR_BLACK);
	ILI9341_Puts(95, 190, "Kem's", &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	ILI9341_DrawRectangle(10, 240, 990, 300, ILI9341_COLOR_BLACK);
	ILI9341_Puts(85, 265,"Pyramide", &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
}


/*
 * @brief	affiche l'écran permettant de valider le choix du jeu
 */
void affichage_ecran_validation(uint8_t jeu){
	ILI9341_Fill(ILI9341_COLOR_WHITE);
	ILI9341_DrawFilledRectangle(30, 10, 210, 45, ILI9341_COLOR_BLUE);
	ILI9341_Puts(62, 20,"Master Card",&Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
	if(jeu == 1){
		ILI9341_Puts(20, 80, "Vous avez choisi le president.", &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	}else if(jeu == 2){
		ILI9341_Puts(20, 80, "Vous avez choisi le kem's.", &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	}else if(jeu == 3){
		ILI9341_Puts(20, 80, "Vous avez choisi la pyramide.", &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	}
	ILI9341_DrawRectangle(10, 135, 990, 195, ILI9341_COLOR_BLACK);
	ILI9341_Puts(90, 160, "VALIDER", &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	ILI9341_DrawRectangle(10, 220, 990, 280, ILI9341_COLOR_BLACK);
	ILI9341_Puts(90, 245, "ANNULER", &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
}


/*
 * @brief	affiche l'écran permettant de valider le choix du nombre de joueurs
 */
void affichage_ecran_validation_joueurs(uint8_t nb_joueurs){
	sprintf(joueurs,"%lu", nb_joueurs);
	ILI9341_Fill(ILI9341_COLOR_WHITE);
	ILI9341_DrawFilledRectangle(30, 10, 210, 45, ILI9341_COLOR_BLUE);
	ILI9341_Puts(62, 20,"Master Card",&Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
	ILI9341_Puts(20, 50, "Vous êtes ", &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	ILI9341_Puts(115, 65, joueurs, &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	ILI9341_Puts(97, 80, "joueurs.", &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	ILI9341_DrawRectangle(10, 135, 990, 195, ILI9341_COLOR_BLACK);
	ILI9341_Puts(90, 160, "VALIDER", &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	ILI9341_DrawRectangle(10, 220, 990, 280, ILI9341_COLOR_BLACK);
	ILI9341_Puts(90, 245, "ANNULER", &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
}


/*
 * @brief	affiche l'écran permettant de sélectionner le nombre de joueurs
 */
void affichage_ecran_joueurs(uint8_t nb_joueurs){
	sprintf(joueurs,"%lu", nb_joueurs);
	ILI9341_Fill(ILI9341_COLOR_WHITE);
	ILI9341_DrawFilledRectangle(30, 10, 210, 45, ILI9341_COLOR_BLUE);
	ILI9341_Puts(62, 20,"Master Card",&Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
	ILI9341_Puts(12, 70, "Choisissez le nombre de joueurs", &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	ILI9341_DrawRectangle(10, 90, 990, 130, ILI9341_COLOR_BLACK);
	ILI9341_Puts(115, 105,"+", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	ILI9341_DrawRectangle(10, 150, 990, 190, ILI9341_COLOR_BLACK);
	ILI9341_Puts(115, 152, "_", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	ILI9341_Puts(115, 205, joueurs, &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	ILI9341_Puts(97, 235, "joueurs", &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	ILI9341_DrawRectangle(10, 260, 990, 300, ILI9341_COLOR_BLACK);
	ILI9341_Puts(90, 280,"VALIDER", &Font_7x10, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
}


/*
 * @brief affiche l'écran indiquant que le jeu est en cours de préparation
 */
void affichage_ecran_en_cours(){
	uint8_t compteur = 0;
	ILI9341_Fill(ILI9341_COLOR_WHITE);
	ILI9341_DrawFilledRectangle(30, 10, 210, 45, ILI9341_COLOR_BLUE);
	ILI9341_Puts(62, 20,"Master Card",&Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
	ILI9341_Puts(75, 150,"En cours", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	ILI9341_Puts(30, 200,"de preparation", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	while(compteur<5){
		ILI9341_DrawFilledRectangle(185, 200, 220, 220, ILI9341_COLOR_WHITE);
		HAL_Delay(500);
		ILI9341_Puts(190, 200,".", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
		HAL_Delay(500);
		ILI9341_Puts(200, 200,".", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
		HAL_Delay(500);
		ILI9341_Puts(210, 200,".", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
		HAL_Delay(500);
		compteur ++;
	}

}


/*
 * @brief	affiche l'écran indiquant que les joueurs peuvent commencer à jouer
 */
void affichage_ecran_final(){
	ILI9341_Fill(ILI9341_COLOR_WHITE);
	ILI9341_DrawFilledRectangle(30, 10, 210, 45, ILI9341_COLOR_BLUE);
	ILI9341_Puts(62, 20,"Master Card",&Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
	ILI9341_Puts(60, 140, "Vous pouvez", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	ILI9341_Puts(18, 170, "commencer a jouer !", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
}


/*
 * @brief	sélectionne le jeu en fonction de la case sur laquelle un appui est détecté
 * @return 	un nombre correspondant au jeu sélectionné
 */
uint8_t choix_jeu(){
	int16_t x, y;
	uint8_t choix = 0;
		if(XPT2046_getMedianCoordinates(&x, &y, XPT2046_COORDINATE_SCREEN_RELATIVE)){
			if(y > 100 && y < 140){
				choix = 1;
			}else if (y > 185 && y < 205){
				choix = 2;
			}else if (y > 260 && y < 280){
				choix = 3;
			}
		}
	return choix;
}


/*
 * @brief	valide le jeu sélectionné
 * @return 	uint8_t qui indique si les paramètres sont validés (1) ou s'ils ne le sont pas (2)
 */
uint8_t validation_param(){
	int16_t x, y;
	uint8_t valide;
	if(XPT2046_getMedianCoordinates(&x, &y, XPT2046_COORDINATE_SCREEN_RELATIVE)){
		if(y > 135 && y < 180){
			valide = 1;
			//ILI9341_DrawCircle(x,y,15,ILI9341_COLOR_BLUE);
		}else if (y > 220 && y < 280){
			valide = 2;
			//ILI9341_DrawCircle(x,y,15,ILI9341_COLOR_RED);
		}else{
			valide = 0;
		}
	return valide;
	}
}


/*
 * @brief	sélectionne le nombre de joueurs
 * @return 	entier correspondant au nombre de joueurs
 */
uint8_t nombre_joueurs_president(){
	int16_t x, y;
	_Bool valide = FALSE;
	uint8_t nb_joueurs = 2;
	affichage_ecran_joueurs(nb_joueurs);
	while(!valide){
		if(XPT2046_getMedianCoordinates(&x, &y, XPT2046_COORDINATE_SCREEN_RELATIVE)){
			if(y > 90 && y < 130 && nb_joueurs <= 8){
				HAL_Delay(100);
				nb_joueurs ++;
				//IILI9341_DrawCircle(125, 210, 10, ILI9341_COLOR_WHITE);
				sprintf(joueurs,"%lu", nb_joueurs);
				ILI9341_Puts(115, 205, joueurs, &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
			}else if(y > 150 && y < 190 && nb_joueurs >= 3){
				HAL_Delay(100);
				nb_joueurs --;
				ILI9341_DrawCircle(125, 210, 10, ILI9341_COLOR_WHITE);
				sprintf(joueurs,"%lu", nb_joueurs);
				ILI9341_Puts(115, 205, joueurs, &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
			}else if(y > 260 && y < 300){
				valide = TRUE;
			}
		}
	}
	return nb_joueurs;
}


/*
 * @brief	sélectionne le nombre de joueurs selon les règles du kems (nombre pair)
 * @return 	entier correspondant au nombre de joueurs
 */
uint8_t nombre_joueurs_kems(){
	int16_t x, y;
	_Bool valide = FALSE;
	uint8_t nb_joueurs = 4;
	affichage_ecran_joueurs(nb_joueurs);
	while(!valide){
		if(XPT2046_getMedianCoordinates(&x, &y, XPT2046_COORDINATE_SCREEN_RELATIVE)){
			if(y > 90 && y < 130 && nb_joueurs <= 6){
				HAL_Delay(100);
				nb_joueurs += 2;
				ILI9341_DrawCircle(125, 210, 10, ILI9341_COLOR_WHITE);
				sprintf(joueurs,"%lu", nb_joueurs);
				ILI9341_Puts(115, 205, joueurs, &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
			}else if(y > 150 && y < 190 && nb_joueurs >= 6){
				HAL_Delay(100);
				nb_joueurs -= 2;
				ILI9341_DrawCircle(125, 210, 10, ILI9341_COLOR_WHITE);
				sprintf(joueurs,"%lu", nb_joueurs);
				ILI9341_Puts(115, 205, joueurs, &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
			}else if(y > 260 && y < 300){
				valide = TRUE;
			}
		}
	}
	return nb_joueurs;
}


/*
 * @brief	teste si l'écran détecte la sélection d'un bouton par rapport à un autre
 */
void test_choix(){
	XPT2046_init();
	int16_t x, y;
	while(1){
		if(XPT2046_getMedianCoordinates(&x, &y, XPT2046_COORDINATE_SCREEN_RELATIVE)){
			if(y > 100 && y < 140){
				static int16_t static_x,static_y;
				ILI9341_DrawCircle(static_x,static_y,15,ILI9341_COLOR_WHITE);
				ILI9341_DrawCircle(x,y,15,ILI9341_COLOR_BLUE);
				static_x = x;
				static_y = y;
			}
		}
	}
}
