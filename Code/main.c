// adolphe ebene -  mehdi aissi
#include "graphics.h"
#define HAUT 0
#define BAS 1
#define GAUCHE 2
#define DROITE 3
#define TOTALE 2

/* ############ DECLARATIONS ############## */
int tabJeu[8][8];


/* ############ PROTOTYPES ############## */
 //modeles
void init_tabJeu();
void init_tabPos(POINT tab[8][8]);
void ajoute_deux_aleatoirement();
void deplace_tout_a_gauche();
void deplace_tout_a_droite();
void deplace_tout_en_haut();
void deplace_tout_en_bas();
void fusionne_brique_a_gauche();
void fusionne_totale_a_gauche();
void fusionne_brique_a_droite();
void fusionne_totale_a_droite();
void fusionne_brique_en_haut();
void fusionne_totale_en_haut();
void fusionne_brique_en_bas();
void fusionne_totale_en_bas();
COULEUR calcul_couleur_brique_un(int valeur);
COULEUR calcul_couleur_brique_deux(int valeur);
COULEUR calcul_couleur_fond_brique(int valeur,int choixInterface);
void copie_tableau_jeu(int tab[8][8]);
int calcul_score();
 //vues
void affiche_fleches(COULEUR c);
void affiche_brique(POINT centre, int valeur,int choixInterface);
void affiche_premiere_grille();
void affiche_deuxieme_grille();
void affiche_premiere_entete();
void affiche_deuxieme_entete();
void affiche_plateau(int choixInterface);
void affiche_grille(int choixInterface);
void affiche_entete(int choixInterface);
void affiche_toutes_briques(POINT tabPos[8][8], int choixInterface);
void affiche_menu_fusions();
void affiche_menu_interface();
void affiche_score(int score);
void affiche_defaite(int score);
void affiche_victoire(int score);

 //controleurs
BOOL est_dans_retour (POINT P1);
BOOL est_dans_fleches (POINT P,int* directionBrique);
BOOL deplace_fusionne_affiche_brique(POINT tabPos[8][8], int directionBrique, int choixInterface,int choixFusion);
BOOL est_identitque_a_tabJeu(int tab[8][8]);
BOOL est_dans_menu (POINT P1);
BOOL est_fin_de_jeu(int score);
int choix_fusion();
int choix_interface();
int clic_utilsateur_choix_interface();




/* ############ MODELES ############## */

void init_tabJeu()
{
	int i,j;
	
	for (i=0; i<8;i++)
	{
		for (j=0;j<8;j++)
			tabJeu[i][j] = 0;	
	}	
	ajoute_deux_aleatoirement();
	ajoute_deux_aleatoirement();
}

void init_tabPos(POINT tab[8][8])
{
	int i,j,cptJ,cptI =7;
	
	for(i=35;i<=560;i = i+70)
	{		
		cptJ=7;
		for(j=40; j<=640;j=j+80)
		{
			 tab[cptI][cptJ].x = 640-j;
			 tab[cptI][cptJ].y = 560-i;
			 cptJ = cptJ-1;
		}
		cptI = cptI-1;
	}	
}

void ajoute_deux_aleatoirement()
{
	int i,j ;
	
	i = alea_int(7) ;
	j= alea_int (7) ;
	
	if (tabJeu[i][j] ==0 )
	{
		tabJeu[i][j] = 2 ;
	}else ajoute_deux_aleatoirement() ;
}

void deplace_tout_a_gauche()
{
	int i,j, cptDiffZero; //compte le nombre de case différente de zero
	
	for(i=0; i<8; i++)
	{	
		cptDiffZero=0;
		for (j=0; j<8;j++)
		{
			if(tabJeu[i][j] !=0)
			{
				tabJeu[i][cptDiffZero] = tabJeu[i][j];
				cptDiffZero++;
			}	
		}
		for(j=cptDiffZero; j<8; j++)
		{
			tabJeu[i][j] = 0;	
		}
	}
}

void deplace_tout_a_droite()
{
	int i,j, cptDiffZero; //compte le nombre de case différente de zero
	
	for(i=0; i<8; i++)
	{	
		cptDiffZero=7;
		for (j=7; j>=0;j--)
		{
			if(tabJeu[i][j] !=0)
			{
				tabJeu[i][cptDiffZero] = tabJeu[i][j];
				cptDiffZero--;
			}	
		}
		for(j=cptDiffZero; j>=0; j--)
		{
			tabJeu[i][j] = 0;	
		}
	}
}

void deplace_tout_en_haut()
{
	int i,j, cptDiffZero; //compte le nombre de case différente de zero
	
	for(i=0; i<8; i++)
	{	
		cptDiffZero=7;
		for (j=7; j>=0;j--)
		{
			if(tabJeu[j][i] !=0)
			{
				tabJeu[cptDiffZero][i] = tabJeu[j][i];
				cptDiffZero--;
			}	
		}
		for(j=cptDiffZero; j>=0; j--)
		{
			tabJeu[j][i] = 0;	
		}
	}
}

void deplace_tout_en_bas()
{
	int i,j, cptDiffZero; //compte le nombre de case différente de zero
	
	for(i=0; i<8; i++)
	{	
		cptDiffZero=0;
		for (j=0; j<8;j++)
		{
			if(tabJeu[j][i] !=0)
			{
				tabJeu[cptDiffZero][i] = tabJeu[j][i];
				cptDiffZero++;
			}	
		}
		for(j=cptDiffZero; j<8; j++)
		{
			tabJeu[j][i] = 0;	
		}
	}
}

void fusionne_brique_a_gauche()
{
	int i,j;
		
	for(i=0; i<8; i++)
	{	
		for (j=0; j<8;j++)
		{
			if(tabJeu[i][j] !=0)
			{
				if(j<7 && tabJeu[i][j] == tabJeu[i][j+1])
				{
					tabJeu[i][j] += tabJeu[i][j];
					tabJeu[i][j+1] = 0;
				}	
			}	
		}
	deplace_tout_a_gauche();
	}

}

void fusionne_totale_a_gauche()
{
	int i,j,k;
		
	for(i=0; i<8; i++)
	{	
		for (j=0; j<8;j++)
		{
			if(tabJeu[i][j] !=0)
			{
					for (k=0;k<7;k++)
					{	
						if(j<7 && tabJeu[i][j] == tabJeu[i][j+1])
						{
							tabJeu[i][j] += tabJeu[i][j];
							tabJeu[i][j+1] = 0;
							j=j-1;
							deplace_tout_a_gauche();
						}	
					}
				
			}	
		}
	deplace_tout_a_gauche();
	}

}

void fusionne_brique_a_droite()
{
	int i,j;
	
	for(i=0; i<8; i++)
	{	
		for (j=7; j>=0;j--)
		{
			if(j>0 && tabJeu[i][j] == tabJeu[i][j-1])
				{
					tabJeu[i][j] += tabJeu[i][j];
					tabJeu[i][j-1] = 0;
				}	
		}
	}
	deplace_tout_a_droite();
}

void fusionne_totale_a_droite()
{
	int i,j,k;
		
	for(i=0; i<8; i++)
	{	
		for (j=7; j>=0;j--)
		{
			if(tabJeu[i][j] !=0)
			{
					for (k=0;k<7;k++)
					{	
						if(j>0 && tabJeu[i][j] == tabJeu[i][j-1])
						{
							tabJeu[i][j] += tabJeu[i][j];
							tabJeu[i][j-1] = 0;
							j += 1;
							deplace_tout_a_droite();
						}	
					}
				
			}	
		}
	deplace_tout_a_droite();
	}

}

void fusionne_brique_en_haut()
{
	int i,j;
	
	for(i=0; i<8; i++)
	{	
		for (j=7; j>=0;j--)
		{
			if(j>0 && tabJeu[j][i] == tabJeu[j-1][i])
				{
					tabJeu[j][i] += tabJeu[j][i];
					tabJeu[j-1][i] = 0;
				}	
		}
	}
	deplace_tout_en_haut();
}

void fusionne_totale_en_haut()
{
	int i,j,k;
	
	for(i=0; i<8; i++)
	{	
		for (j=7; j>=0;j--)
		{
			if(tabJeu[j][i] !=0)
			{
				for (k=0;k<7;k++)
				{

					if(j>0 && tabJeu[j][i] == tabJeu[j-1][i])
					{
						tabJeu[j][i] += tabJeu[j][i];
						tabJeu[j-1][i] = 0;
						j=j+1;
						deplace_tout_en_bas();
					}
				}				
			}
		}
	}
	deplace_tout_en_haut();
}

void fusionne_brique_en_bas()
{
	int i,j;
		
	for(i=0; i<8; i++)
	{	
		for (j=0; j<8;j++)
		{
			if(tabJeu[j][i] !=0)
			{
				if(j<7 && tabJeu[j][i] == tabJeu[j+1][i])
				{
					tabJeu[j][i] += tabJeu[j][i];
					tabJeu[j+1][i] = 0;
				}				
			}	
		}
	deplace_tout_en_bas();
	}

}

void fusionne_totale_en_bas()
{
	int i,j,k;
		
	for(i=0; i<8; i++)
	{	
		for (j=0; j<8;j++)
		{
			if(tabJeu[j][i] !=0)
			{
				for (k=0;k<7;k++)
				{

					if(j<7 && tabJeu[j][i] == tabJeu[j+1][i])
					{
						tabJeu[j][i] += tabJeu[j][i];
						tabJeu[j+1][i] = 0;
						j=j-1;
						deplace_tout_en_bas();
					}
				}				
			}	
		}
	deplace_tout_en_bas();
	}

}

int calcul_score() 
{
	int i,j,score=0;
	
	for (i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			score += tabJeu[i][j];
		}	
	}
	//score += 2;	
	return score;	
}

COULEUR calcul_couleur_brique_un(int valeur)
{
	 	COULEUR c;
	 	switch(valeur)
	 	{
		case(2):
			c = couleur_RGB(94,69,75);
			break;
		case(4):
			c = couleur_RGB(247,213,156);
			break;
		case(8):
			c = couleur_RGB(243,240,215);
			break;
		case(16):
			c = couleur_RGB(193,172,149);
			break;
		case(32):
			c = couleur_RGB(181,205,163);
			break;
		case(64):
			c = couleur_RGB(201,228,197);
			break;
		case(128):
			c = couleur_RGB(250,235,224);
			break;
		case(256):
			c = couleur_RGB(202,247,227);
			break;
		case(512):
			c = couleur_RGB(248,237,237);
			break;
		case(1024):
			c = couleur_RGB(246,223,235);
			break;
		case(2048):
			c = couleur_RGB(228,186,212);
			break;
		default:
			c = black;
		}
	 return c;
 }
 
COULEUR calcul_couleur_brique_deux(int valeur)
{
	 	COULEUR c;
	 	switch(valeur)
	 	{
		case(2):
			c = couleur_RGB(253,185,252);
			break;
		case(4):
			c = couleur_RGB(237,80,241);
			break;
		case(8):
			c = couleur_RGB(255,0,228);
			break;
		case(16):
			c = couleur_RGB(195,43,173);
			break;
		case(32):
			c = couleur_RGB(112,39,160);
			break;
		case(64):
			c = couleur_RGB(23,39,116);
			break;
		case(128):
			c = couleur_RGB(174,0,251);
			break;
		case(256):
			c = couleur_RGB(62,0,255);
			break;
		case(512):
			c = couleur_RGB(23,05,85);
			break;
		case(1024):
			c = couleur_RGB(0,87,146);
			break;
		case(2048):
			c = couleur_RGB(72,0,50);
			break;
		default:
			c = black;
		}
	 return c;
 }

COULEUR calcul_couleur_fond_brique(int valeur,int choixInterface)
{
	
	COULEUR c;
	
	   if (choixInterface == 1) c = calcul_couleur_brique_un(valeur);
    else c= calcul_couleur_brique_deux(valeur);
	return c;
}

void copie_tableau_jeu(int tab[8][8])
{
	int i,j;
	
	for (i=0;i<8;i++)
	{
		for (j=0;j<8;j++)
			tab[i][j] = tabJeu[i][j];
	} 
		
}


/* ############ VUES ############## */

void affiche_fleches(COULEUR c)
{
	POINT P1,P2;

	//affichage fleches

	//gauche
	P1.x = 240; P1.y = 605;
	P2.x = 270; P2.y = 575;
	draw_rectangle(P1,P2,c);
	P1.x = P1.x+8; P1.y = P1.y-2;
	aff_pol("<", 20,P1, c);

	//bas
	P1.x = 270; P1.y = 605;
	P2.x = 300; P2.y = 575;
	draw_rectangle(P1,P2,c);
	P1.x = P1.x+8; P1.y = P1.y-2;
	aff_pol("V", 20,P1, c);

	//droite
	P1.x = 300; P1.y = 605;
	P2.x = 330; P2.y = 575;
	draw_rectangle(P1,P2,c);
	P1.x = P1.x+8; P1.y = P1.y-2;
	aff_pol(">", 20,P1, c);

	//haut
	P1.x = 270; P1.y = 635;
	P2.x = 300; P2.y = 605;
	draw_rectangle(P1,P2,c);
	P1.x = P1.x+8; P1.y = P1.y-2;
	aff_pol("^", 20,P1, c);	
}

void affiche_brique(POINT centre, int valeur,int choixInterface)
{
	POINT P1,P2;
	int decaleX;
	COULEUR c;
	c = calcul_couleur_fond_brique(valeur,choixInterface);
	//affichage de la brique
	P1.x = centre.x - 38; P1.y = centre.y + 33; // 
	P2.x = centre.x + 38; P2.y = centre.y - 33; // 
	draw_fill_rectangle(P1,P2,c);
	//affichage du text 
	if (choixInterface == 1) c = black;
	else c=white;
		if(valeur>999)
			decaleX = 19;
		else if(valeur>99)
			decaleX = 14;
		else if(valeur>9)
			decaleX = 9;
		else if (valeur == 2){
			c = white;
			decaleX = 5;
		 }
		else
			decaleX = 5;
			
	centre.x = centre.x-decaleX;
	centre.y = centre.y+10;
	aff_int(valeur,15,centre,c);
}	

void affiche_premiere_grille()
{
    POINT P1, P2 ;
    int i;
    
    P1.x = 0 ; P1.y = 560;
    P2.x = 640; P2.y = 0;
   
    draw_fill_rectangle(P1, P2, couleur_RGB(224,192,151));
    
    //on trace les lignes horizontales
    P1.x=0;
    P2.x=640;
    for(i=70 ; i<=560; i=i+70)
    {
		P1.y=i;
		P2.y=i; 
		draw_line(P1,P2,couleur_RGB(250,242,242));
	}

	// on trace les lignes verticales 
	P1.y=0;
    P2.y=560;
    
    for(i=80; i<640; i=i+80)
    {
		P1.x=i;
		P2.x=i; 
		draw_line(P1,P2,couleur_RGB(250,242,242));
	}
}

void affiche_deuxieme_grille()
{
    POINT P1, P2 ;
    int i;
    
    P1.x = 0 ; P1.y = 560;
    P2.x = 640; P2.y = 0;
   
    draw_fill_rectangle(P1, P2, couleur_RGB(52,91,99)) ;
    
    //on trace les lignes horizontales
    P1.x=0;
    P2.x=640;
    for(i=70 ; i<=560; i=i+70)
    {
		P1.y=i;
		P2.y=i; 
		draw_line(P1,P2,couleur_RGB(21,45,53));
	}

	// on trace les lignes verticales 
	P1.y=0;
    P2.y=560;
    
    for(i=80; i<640; i=i+80)
    {
		P1.x=i;
		P2.x=i; 
		draw_line(P1,P2,couleur_RGB(21,45,53));
	}
}

void affiche_premiere_entete()
{
	POINT P1,P2;
	COULEUR c=black;
	
	// dessin de la zone
	P1.y = 700; P1.x = 0;
    P2.y = 560; P2.x = 640; 
    draw_fill_rectangle(P1,P2,couleur_RGB(250,242,242));

	// affichage texte statique
	P1.y = 690; P1.x= 10;
	aff_pol("2048", 30,P1, black);
	P1.y = 655; P1.x= 10;
	aff_pol("By Adolphe Ebene & Mehdi Aissi", 10,P1, black);
	
	//affichage du bouton retour
	P1.y = 575; P1.x= 12;
	P2.y = 605; P2.x= 120;
	draw_rectangle (P1,P2, black) ;
	P1.y = 600 ; P1.x = 25 ;
	aff_pol("<< Retour", 15,P1, black);

	//affichage zone de score
	P1.y = 650; P1.x = 610;
    P2.y = 575; P2.x = 520;
    draw_rectangle(P1,P2,black);

    P1.x= 535; P1.y = 679;
    aff_pol("Score", 20,P1, black);
    
	affiche_fleches(c);
 }

void affiche_deuxieme_entete()
{
	POINT P1,P2;
	COULEUR c=couleur_RGB(250,242,242);
	// dessin de la zone
	P1.y = 700; P1.x = 0;
    P2.y = 560; P2.x = 640; 
    draw_fill_rectangle(P1,P2,couleur_RGB(21,45,53));

	// affichage texte statique
	P1.y = 690; P1.x= 10;
	aff_pol("2048", 30,P1, couleur_RGB(250,242,242));
	P1.y = 655; P1.x= 10;
	aff_pol("By Adolphe Ebene & Mehdi Aissi", 10,P1, couleur_RGB(250,242,242));
	
	//affichage du bouton retour
	P1.y = 575; P1.x= 12;
	P2.y = 605; P2.x= 120;
	draw_rectangle (P1,P2, couleur_RGB(250,242,242)) ;
	P1.y = 600 ; P1.x = 25 ;
	aff_pol("<< Retour", 15,P1, couleur_RGB(250,242,242));

	//affichage zone de score
	P1.y = 650; P1.x = 610;
    P2.y = 575; P2.x = 520;
    draw_rectangle(P1,P2,couleur_RGB(250,242,242));

    P1.x= 535; P1.y = 679;
    aff_pol("Score", 20,P1, couleur_RGB(250,242,242));
    
	affiche_fleches(c);
 }

void affiche_plateau(int choixInterface)
{
	affiche_auto_off();
	affiche_grille(choixInterface);
	affiche_entete(choixInterface);
	affiche_all();
}

void affiche_grille(int choixInterface)
{
    if (choixInterface == 1) affiche_premiere_grille();
    else affiche_deuxieme_grille();
}

void affiche_entete(int choixInterface)
{
    if (choixInterface == 1) affiche_premiere_entete();
    else affiche_deuxieme_entete();
}

void affiche_toutes_briques(POINT tabPos[8][8], int choixInterface)
{
	int i,j;
	affiche_grille(choixInterface);
	
	for(i=0; i<8; i++)
	{
		for (j=0; j<8; j++){
			if (tabJeu[i][j] != 0)
				affiche_brique(tabPos[i][j], tabJeu[i][j],choixInterface);
		}		
	}
	affiche_all();
}

void affiche_menu_fusions()
{
    POINT P1,P2 ;    
    
    P1.x= 0;   P1.y= 0 ;
    P2.x= 640 ;   P2.y=700 ;
    draw_fill_rectangle(P1,P2, black) ; 

    P1.x= 160;P1.y= 380 ;
    P2.x= 480 ;P2.y=450 ;
    draw_fill_rectangle(P1,P2, black) ;
    draw_rectangle(P1,P2, couleur_RGB(250,242,242));
 

    P1.x= 240;P1.y= 430 ;
    aff_pol("Fusion Totale", 25, P1 ,white) ;
    
    P1.x= 160;   P1.y= 460;
    P2.x= 480;   P2.y=530;
    draw_fill_rectangle(P1,P2, white);
    draw_rectangle(P1,P2, couleur_RGB(250,242,242));

    P1.x= 220;   P1.y= 510 ;
    aff_pol( "Fusion Normale", 25, P1 , black) ;
    
    P1.x= 100;   P1.y= 310 ;
    
    
    aff_pol( "Veuillez selectionner une methode de fusion.", 20, P1 , white) ;  
}

void affiche_menu_interface()
{
    POINT P1,P2 ;    
    
    P1.x= 0;   P1.y= 0 ;
    P2.x= 640 ;   P2.y=700 ;
    draw_fill_rectangle(P1,P2, black) ; 

    P1.x= 160;P1.y= 380 ;
    P2.x= 480 ;P2.y=450 ;
    draw_fill_rectangle(P1,P2, couleur_RGB(52,91,99)) ;
    draw_rectangle(P1,P2, couleur_RGB(250,242,242));
 

    P1.x= 250;P1.y= 430 ;
    aff_pol("Mode Nuit", 25, P1 , couleur_RGB(250,242,242)) ;
    
    P1.x= 160;   P1.y= 460;
    P2.x= 480;   P2.y=530;
    draw_fill_rectangle(P1,P2, couleur_RGB(224,192,151));
    draw_rectangle(P1,P2, couleur_RGB(250,242,242));

    P1.x= 250;   P1.y= 510 ;
    aff_pol( "Mode Jour", 25, P1 , black) ;
    
    P1.x= 100;   P1.y= 310 ;
    
    
    aff_pol( "Veuillez selectionner une interface.", 25, P1 , white) ;  
}

void affiche_score(int score) 
{
		POINT P1,P2;
		int decaleX;
		
		//efface zone de score
		P1.y = 650; P1.x = 610;
    	P2.y = 575; P2.x = 520;
    	draw_fill_rectangle(P1,P2,couleur_RGB(250,242,242));
    	draw_rectangle(P1,P2,black);

		
		//recentrer correctement le score en fonction du score
		if(score>999)
			decaleX = -24;
		else if(score>99)
			decaleX = -19;
		else if(score>9)
			decaleX = -12;
		else
			decaleX = -5;
		
		P1.x = ((P1.x-P2.x)/2) +P2.x; P1.y = ((P1.y-P2.y)/2) +P2.y;
		P1.x += decaleX; P1.y += 13;
		aff_int(score, 20,P1,black);
		affiche_all();
	}

void affiche_defaite(int score)
{
		POINT P1,P2;
		
		P1.x = 50; P1.y= 50;
		P2.x = 590; P2.y = 650;
		draw_fill_rectangle(P1,P2, couleur_RGB(220,20,60));
		draw_rectangle(P1,P2,black);
	
		P1.x = 180; P1.y = 550;
	
		aff_pol("DEFAITE !",60,P1, white);
		
		P1.x = 130; P1.y = 470;
		aff_pol("Re-essayer une prochaine fois !",25,P1,white);
		
		P1.x = 165; P1.y = 430;
		aff_pol("Il vous manquait",20,P1,white);
		
		score = 2048-score;
		P1.x = 340;
		aff_int(score,20,P1,white);
		P1.x = 400;
		aff_pol("point(s) :/",20,P1,white);

		affiche_all();
}

void affiche_victoire(int score)
{
		POINT P1,P2;
		
		P1.x = 50; P1.y= 50;
		P2.x = 590; P2.y = 650;
		draw_fill_rectangle(P1,P2, couleur_RGB(253,252,235));
		draw_rectangle(P1,P2,black);
	
		P1.x = 140; P1.y = 550;
	
		aff_pol("VICTOIRE !",60,P1, couleur_RGB(236, 226, 54));
		
		P1.x = 130; P1.y = 470;
		aff_pol("Felicitation vous avez triomphe !",25,P1,couleur_RGB(220,20,60));
		
		P1.x = 165; P1.y = 430;
		aff_pol("Vous avez scorer",20,P1,couleur_RGB(220,20,60));

		P1.x = 340;
		aff_int(score,20,P1,couleur_RGB(220,20,60));
		P1.x = 400;
		aff_pol("points !",20,P1,couleur_RGB(220,20,60));

		affiche_all();
}

/* ############ CONTROLLEURS ############## */

BOOL est_dans_retour (POINT P1) 
{
	BOOL estDansRetour ;
	
	printf (" j'y suis ") ;
	
	if ( P1.x>= 12 && P1.x<=120 )
	{
		if ( P1.y>= 575 && P1.y<= 605 ) 
		{
		   estDansRetour = true ;		   
		} 

	}
	
	return estDansRetour ;
}

BOOL est_dans_fleches (POINT P,int* directionBrique)
{
	if (P.y >575 && P.y<605) 
	{
		if(P.x >240 && P.x < 270)
		{
			*directionBrique = GAUCHE;
			return true;
		}
		else if(P.x > 270 && P.x <300)
		{
			*directionBrique = BAS;
			return true;
		}
		else if(P.x > 300 && P.x <330)
		{
			*directionBrique = DROITE;
			return true;
		}
		else
			return false;
	}
	else if (P.x>270 && P.x <300 && P.y>605 && P.y < 635)
	{
		*directionBrique = HAUT;
		return true;
	}
	else
		return false;
}

BOOL deplace_fusionne_affiche_brique(POINT tabPos[8][8], int directionBrique, int choixInterface,int choixFusion)
{
	int tabTemp[8][8];
	copie_tableau_jeu(tabTemp);
	
	switch(directionBrique){
		case(HAUT):
			deplace_tout_en_haut();
			if(choixFusion == TOTALE) fusionne_totale_en_haut();
			else fusionne_brique_en_haut();
			deplace_tout_en_haut();
			affiche_toutes_briques(tabPos,choixInterface);
			return est_identitque_a_tabJeu(tabTemp);
			break;
		case(BAS):
			deplace_tout_en_bas();
			if(choixFusion == TOTALE) fusionne_totale_en_bas();
			else fusionne_brique_en_bas();
			deplace_tout_en_bas();
			affiche_toutes_briques(tabPos,choixInterface);
			return est_identitque_a_tabJeu(tabTemp);
			break;
		case(DROITE):
			deplace_tout_a_droite();
			if(choixFusion == TOTALE) fusionne_totale_a_droite();
			else fusionne_brique_a_droite();			
			deplace_tout_a_droite();
			affiche_toutes_briques(tabPos,choixInterface);
			return est_identitque_a_tabJeu(tabTemp);
			break;
		case(GAUCHE):
			deplace_tout_a_gauche();
			if(choixFusion == TOTALE) fusionne_totale_a_gauche();
			else fusionne_brique_a_gauche();			
			deplace_tout_a_gauche();
			affiche_toutes_briques(tabPos,choixInterface);
			return est_identitque_a_tabJeu(tabTemp);
			break;
	}	
	
	return est_identitque_a_tabJeu(tabTemp);
;	
}

BOOL est_identitque_a_tabJeu(int tab[8][8])
{
	int i,j;
	
	for (i=0;i<8;i++)
	{
		for (j=0;j<8;j++)
		{
			if (tab[i][j] != tabJeu[i][j])
					return false;
		 }
	} 
	return true;
}

BOOL est_dans_menu (POINT P1) 
{		
	if ( P1.x>= 12 && P1.x<=120 )
	{
		if ( P1.y>= 575 && P1.y<= 605 )  return true ;		   
	}
	return false ;
}

BOOL est_fin_de_jeu(int score)
{

	int i,j,cptDiffZero=0;
	
	if (score >= 2048)
	{
		affiche_victoire(score);
		return true;
	}
	
	for(i=0; i<8 ; i++)
	{
		for(j=0;j<8;j++)
		{
			if(tabJeu[i][j] == 0)
				return false;
			else 
				cptDiffZero++;
		}
	}
	
	if (cptDiffZero == 64){
		affiche_defaite(score);
		return true;
	}
	return false;
}

int choix_fusion()
{
	int choixFusion;
	affiche_menu_fusions();
	do{
		choixFusion  = clic_utilsateur_choix_interface();
	}while(choixFusion >2 || choixFusion <1);
	
	return choixFusion;
}

int choix_interface()
{
	int choixInterface;
	affiche_menu_interface();

	do{
		choixInterface  = clic_utilsateur_choix_interface();
	}while(choixInterface >2 || choixInterface <1);
   
	
 return choixInterface ;
}

int clic_utilsateur_choix_interface()
{
	POINT clicUtilisateur;
	
	clicUtilisateur = wait_clic();
	
	if ( clicUtilisateur.x >= 160 && clicUtilisateur.x <= 480)
	{
		if( clicUtilisateur.y >= 380 && clicUtilisateur.y <= 450)
		{	
			 return 2 ;
		}
		if( clicUtilisateur.y >= 460 && clicUtilisateur.y <= 530)	
		{
			return 1 ;
		}
	}
	else 
	{
		return 0;
	}
	
	return 0;
}


/* ############ MAIN ############## */

int main(void) 
{ 
	POINT tabPos[8][8], P;
	int directionBrique,score;
	int choixInterface,choixFusion;
	BOOL estIchange,estFini;
	init_graphics(640,700); 
	
	choixFusion = choix_fusion();
	choixInterface = choix_interface();
	
	affiche_plateau(choixInterface) ;
	init_tabJeu();	
	init_tabPos(tabPos);
	
	
	affiche_toutes_briques(tabPos,choixInterface);
	score = calcul_score();
	affiche_score(score);
	
	do
	{
		do
		{
			P=wait_clic();
			if (est_dans_menu(P)) main();
			
		}while(!est_dans_fleches(P,&directionBrique));
		
		estIchange = deplace_fusionne_affiche_brique(tabPos,directionBrique,choixInterface,choixFusion);
			
		if(!estIchange)
		{
			ajoute_deux_aleatoirement();
			score = calcul_score();
			affiche_score(score);			
			affiche_toutes_briques(tabPos,choixInterface);			
		}	
		estFini = est_fin_de_jeu(score);
	}while(!estFini);
	
	wait_escape();
	return 0; 
}
