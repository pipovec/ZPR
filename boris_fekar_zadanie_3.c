/*
* File:   boris_fekar_zadanie_3.c
* Author: boris fekar
*
* Created on Sobota, 2015, november 28, 14:50
*/


#include <stdio.h>



int main()
{
	
	/* Deklaracia premennych */
	char nazov_suboru[] = {"./input.txt"};

	int znaky[32] ={0},i, pocet_znakov;
	int *p_znaky;

	// pointer na pole integer
	p_znaky = &znaky[0];

	
	// Deklaracia funcii 
	int 	pocetnost_znakov(char* nazov_suboru, int* p_znaky);
	void 	zobrazenie_pocetnosti_znakov(int* p_znaky);

	
	// Volanie funkcii a somotne vykonanie programu
	pocet_znakov 	= pocetnost_znakov(nazov_suboru, p_znaky);
	
	zobrazenie_pocetnosti_znakov(p_znaky);

	printf("---------------------------\nCelkovy pocet pismen a-z v zdrojovom subore je %i\n", pocet_znakov );
	
	return 0;
}

/* Funkcia zodpovedna za stanovenie pocetnosti znakov */
int pocetnost_znakov(char* nazov_suboru, int* p_znaky)
{

	char c;
	int i, pocitaj_znaky;
	int count[32];

	FILE *file_in;
    file_in	= fopen(nazov_suboru, "r");

    pocitaj_znaky = 0;
    
    while(1)
    {
    	// Zacnem citat subor
    	c = fgetc(file_in);
    	
    	
    	/* Najdem znaky malej abecedy */
    	if(c >= 'a' && c <= 'z' )
    	{
    		
    		// Zmenim char na int, ulozim do pola p_znaky pod indexom a pridam 1
    		p_znaky[c - 'a'] ++ ;
    		
    		// Spocitam kolko znakov som uz robil
    		pocitaj_znaky ++;
    		
    	}

    	
    	// Ak narazim na koniec suboru skoncim v iteracii
    	if(feof(file_in)){break;}
    	
    }

    // Zavrem subor
    fclose(file_in);

	return pocitaj_znaky;
}


/* Funkcia zodpovedna za stanovenie pola pocetnosti znakov */
void zobrazenie_pocetnosti_znakov(int* p_znaky)
{
	int i;
	printf("---------------------------\nALPHABET QUANTITY\n");
	
	
	for (i = 0; i < 32; i++)
	{
		
			if(p_znaky[i] > 0)
			{
				printf("%c[%ix] \n", i+'a', p_znaky[i]);
			}
			
	}


}
