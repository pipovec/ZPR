/*
 * File:   boris_fekar_zadanie_4.c
 * Author: boris fekar
 *
 * Created on Pondelok, 2015, december 07, 07:00
 * Najskaredsi program aky som kedy urobil :-(	
 */

 #include <stdio.h>
 #include <string.h>


 int main()
{	
	char matica[5][5];
	char text[100];
	char c;
	int index1,index2,i;
	char *p_text = text;

	FILE *file_out;
	file_out = fopen("plafair_output.txt", "w");



	void NacitajText(char *p_text);
	NacitajText(p_text);


	/** Naplnenie matice */
	index1 = 0; 
	index2 = 0;

	FILE *file_in;
	file_in = fopen("playfair_matrix.txt", "r");

	if(file_in == NULL){printf("Neotvoril sa subor \n");}
	
	while(1)
	{
		c = fgetc(file_in);
				
		if(c >= 'a' && c <= 'z')
		{
		
				matica[index1][index2] = c;
				index2++;
				

				if(index2 == 5 )
				{ 
					index2  = 0;
				 	index1 ++;
				 	
				}

		}
		
		if(feof(file_in)){break;}
	}
	fclose(file_in);

	printf("--------------------\nPLAYFAIR MATRIX\n");
	fprintf(file_out,"--------------------\nPLAYFAIR MATRIX\n");

	for(index1 = 0; index1 < 5; index1 ++)
	{
		
		
		for(index2 = 0; index2 < 5; index2 ++ )	
		{
			printf("%c", matica[index1][index2]);
			fprintf(file_out,"%c", matica[index1][index2]);
		}
		printf("\n");
		fprintf(file_out,"\n");

	}
	
	printf("--------------------\n--------------------\nPLAINTEXT ENCRYPTION\n");
	fprintf(file_out,"--------------------\n--------------------\nPLAINTEXT ENCRYPTION\n");

	/* Sifrovanie */
	int pocet_pismen = strlen(text);
	int counter = 0;
	int ii = 0;
	char digram[2];
	i = 0;

	int d01,d02,d11,d22;
	

	while( i < pocet_pismen)
	{
		digram[counter] = text[i];
		
		
		
		if(counter == 1 )
			{
				
				/* Zacnem hladat v matici znaky digram 0 a zistim suradnice*/ 
					for(index1 = 0; index1 < 5; index1++)
					{
						for(index2 = 0; index2 < 5; index2++ )	
						{
							if(matica[index1][index2] == digram[0])
								{
									d01 = index1; d02 = index2;									
								}

						}
					}

					/* Zacnem hladat v matici znaky digram 1 a zistim suradnice*/ 
					for(index1 = 0; index1 < 5; index1++)
					{
						for(index2 = 0; index2 < 5; index2++ )	
						{
							if(matica[index1][index2] == digram[1])
								{
									d11 = index1; d22 = index2;									
								}

						}	
					}	
					/* Ak su znaky v rovnakom riadku */
					if(d01 == d11)
					{
						
						/* digram[0] */
						if(d02 < 4)	{d02++; }
						else
						{d02 = 0;}
						
						/* digram[1] */
						if(d22 < 4 ){d22++;}
							else
						{d22 = 0;}



						printf("%c%c --> %c%c\n", digram[0],digram[1], matica[d01][d02],matica[d11][d22] );
						fprintf(file_out,"%c%c --> %c%c\n", digram[0],digram[1], matica[d01][d02],matica[d11][d22] );

						
						
					}	
					
					/* Ak su znaky v jednom stlpci */	
					if(d02 == d22)
					{
						
						/* digram[0] */
						if(d01 < 4)	{d01++; }
						else
						{d01 = 0;}

						/* digram[1] */
						if(d11 < 4 ){d11++;}
							else
						{d11 = 0;}

						printf("%c%c --> %c%c\n", digram[0],digram[1], matica[d01][d02],matica[d11][d22] );
						fprintf(file_out,"%c%c --> %c%c\n", digram[0],digram[1], matica[d01][d02],matica[d11][d22] );
						
					}		

					/* Ak su znaky v inych stlpcoch a riadkoch */
					if(d01 != d11 && d02 !=d22)
					{
						printf("%c%c --> %c%c\n", digram[0],digram[1],matica[d01][d22], matica[d11][d02] );
						fprintf(file_out,"%c%c --> %c%c\n", digram[0],digram[1],matica[d01][d22], matica[d11][d02] );


					}



			counter = 0;
			}		

			else
			{counter++;}

		i++; 

		




		
	}

	printf("--------------------\n");
	fprintf(file_out,"--------------------\n");


	return 0;
}


void NacitajText(char  *p_text)
{
	
	char c;
	FILE *file_in;
	
	file_in = fopen("playfair_plaintext.txt", "r");
	if(file_in == NULL){printf("Neotvoril sa subor \n");}
	 

	while(1)
	{
		c = fgetc(file_in);
				
		if(c >= 'a' && c <= 'z')
		{
			
			*p_text = c; p_text++;
		}
		
		if(feof(file_in)){break;}
	}
	
	fclose(file_in);
	

}
