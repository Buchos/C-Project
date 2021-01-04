#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"perso.h"

void viderBuffer()
{
	int c = 0;
	while (c != '\n' && c != EOF)
	{
		c = getchar();
	}
}

int lire(char *chaine, int longueur)
{
	char *positionEntree = NULL;
	if (fgets(chaine, longueur, stdin) != NULL)
	{
		positionEntree = strchr(chaine, '\n');
		if (positionEntree != NULL)
		{
			*positionEntree = '\0';
		}
		else
		{
			viderBuffer();
		}
		return 1;
	}
	else
	{
		viderBuffer();
		return 0;
	}
}

char lireCaractere()
{
	char caractere = 0;
	caractere = getchar(); /* On lit le premier caractère
	//caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà
	// On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer)*/
	while (getchar() != '\n') ;
	return caractere;
}

long lireLong()
{
	char nombreTexte[100] = {0};

	if (lire(nombreTexte, 100))
	{

		return strtol(nombreTexte, NULL, 10);
	}
	else
	{

		return 0;
	}
}


int lireInt()
{
	char nombreTexte[100] = {0};

	if (lire(nombreTexte, 100))
	{

		return atoi(nombreTexte);
	}
	else
	{

		return 0;
	}
}

void format(char *chaine, int longueur, char c)
{
	int i;

	for (i=0;i<longueur;i++)
		chaine[i]=c;
}

int continuer()
{
	char c;

	do
	{
		printf("\n Do you want to continue ? (Y/N)");
		c=lireCaractere();
	}while( c!='y' && c!='n' && c!='Y' && c!='N');

	if ( c=='y' || c=='Y')
		return 1;
	else
		return 0;
}

float lireFloat()
{
  	char nombreTexte[100] = {0};

	if (lire(nombreTexte, 100))
	{

		return strtof(nombreTexte, NULL);
	}
	else
	{

		return 0;
	}

}

void get_temps(Date *Date_du_jour)
{

    time_t timestamp;
    struct tm * t;

    timestamp = time(NULL);
    t = gmtime(&timestamp);

    Date_du_jour->i_jour=t->tm_mday;
    Date_du_jour->i_mois=t->tm_mon+1;
    Date_du_jour->i_annee=t->tm_year+1900;
}

int diff_temps(Date Date_de_debut, Date Date_de_fin)
{
    time_t now;
    struct tm newdate;
    struct tm newdate2;
    double seconds;

    time(&now);

    newdate = *localtime(&now);
    newdate2 = *localtime(&now);

    newdate.tm_hour = 0; newdate.tm_min = 0; newdate.tm_sec = 0;
    newdate.tm_mon = Date_de_debut.i_mois-1;
    newdate.tm_mday = Date_de_debut.i_jour;
    newdate.tm_year = Date_de_debut.i_annee - 1900;

    newdate2.tm_hour = 0; newdate2.tm_min = 0; newdate2.tm_sec = 0;
    newdate2.tm_mon = Date_de_fin.i_mois-1;
    newdate2.tm_mday = Date_de_fin.i_jour;
    newdate2.tm_year = Date_de_fin.i_annee - 1900;

    seconds = difftime(mktime(&newdate2),mktime(&newdate));

    return (int)seconds/(60*60*24);

}
