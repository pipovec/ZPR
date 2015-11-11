/*
 * File:   main.c
 * Author: boris fekar
 *
 * Created on Streda, 2015, november 4, 17:12
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
 

int main()
{

FILE *file_in;
FILE *file_out;


char c;
char buffer[8], *buff;
int SpracujRetazec(char *buff);
void VynulujPremennu(char* buff);

buff = &buffer[0];

int counter = 0;
int ibsl		= 0;
int dec 		= 0;

file_in   = fopen("./binary_input.txt", "r");
file_out  = fopen("./transformation.txt", "w");

/* Zobraz na obrazovke */
printf("%s\n","INPUT_STREAM");

/* Zapis do suboru */
fprintf(file_out,"%s\n","INPUT_STREAM");

	while(1)
	{
    /* Zacni citat znaky zo suboru */
    c  = fgetc(file_in);

    
	    /* Filtruj 1 a 0 */
	    if(c == 0x30 || c == 0x31 )
	    {
				
				/* pocitaj binarne cisla  */
				++ibsl; 	

	    	/* zapis honodtu c */
				buff[counter] = c;    
	    	++counter ;

	  		/* ak je znakov 8 tak ich spracuj */
	  		if(counter == 8)
	  		{
	  		  	dec = SpracujRetazec(buff);
	  		  	

	  		  	/* Zobraz na obrazovke */
	  		  	printf("%s[%i]\n",buffer,dec);

	  		  	/* Zapis do suboru */
	  		  	fprintf(file_out, "%s[%i]\n",buffer,dec);
	  		  	

	  		  	VynulujPremennu(buff);
	  			counter = 0;
	  		}
	    
  		 	

	    
	    }

	    if(feof(file_in))
		   {
		    	dec = SpracujRetazec(buff);
		    	
		    	/* Zobraz na obrazovke */
	  		  	printf("%s[%i]\n",buffer,dec);
	  		  	printf("INPUT_BINARY_STREAM_LENGHT=%i\n", ibsl);

	  		  	/* Zapis do suboru */
	  		  	fprintf(file_out, "%s[%i]\n",buffer,dec);
	  		  	fprintf(file_out, "INPUT_BINARY_STREAM_LENGHT=%i\n", ibsl);

		    	break;
		   }

	}



fclose(file_in);
fclose(file_out);


return 0;

}


/* 
*       Praca z retazcom
*/

int SpracujRetazec(char *buff)
{
	
	/* Deklaracia premennych */
	int c, i, decimal, mocnitel, dlzka_retazca;
	char znak;
	/* Deklaracia funkcii */
	void DoplnNuly(int dlzka_retazca, char* buff );
	
  

  /* Inicializacia */
	mocnitel = 7;
	decimal  = 0;
	

	/* Kontrola dlzky retazca */
	dlzka_retazca = strlen(buff);
		
	if (dlzka_retazca < 8)
	{
		DoplnNuly(dlzka_retazca,buff);
	} 


	/* Spracovanie retazca na desiatkovu sustavu */
	for(i = 0; i< 8; i++)
	{

		znak = buff[i];
		c = znak - '0';
		decimal = decimal + (c * pow(2,mocnitel));
		mocnitel = mocnitel - 1 ;

	}

	return decimal;
	
}


/* Nulovanie premennej buffer (*buff) */

void VynulujPremennu(char *buff)
{
	int i;

	for(i=0;i<8;i++)
	{
		buff[i] = '\0';
	}
}


/* Doplnenie nul pre kratsie retazce ako 8 znakov */

void DoplnNuly(int dlzka_retazca, char* buff)
{
	char retazec[8]; 
	int i;
	
	for(i = 0; i < 8; i++)
	{
	
		
		if(i >= dlzka_retazca)
		{
			buff[i] = '0' ;	
		}
		
	}

}
