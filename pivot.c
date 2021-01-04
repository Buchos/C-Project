#include<string.h>
#include<stdio.h>
#include "Pivot.h"
#include "perso.h"

void initPivot(Pivot *p)
{
    p->idPivot=-1;

    p->idDisease=-1;
    p->idSymptom=-1;
}
void createPivot(Pivot *p,CP *cp1,int idDisease,int idSymptom)
{
    p[cp1->id].idPivot=cp1->id;

    p[cp1->id].idDisease=idDisease;
    p[cp1->id].idSymptom=idSymptom;
    cp1->id++;
}
void loadPivot(Pivot *p,CP *cp1)
{
    int i=0;
    FILE *fichier=NULL;

    fichier=fopen("Pivot.txt","r");

    if(fichier != NULL)
    {
        // Lecture structure de controle
        fscanf(fichier,"%d\n",&cp1->id);
        // Lecture des differentes structures
        for(i=0;i<cp1->id;i++)
        {
            fscanf(fichier,"%d\n%d\n%d\n",&p[i].idPivot,&p[i].idDisease,&p[i].idSymptom);
        }
        fclose(fichier);
    }
}
void savePivot(Pivot *p,CP cp1)
{
    int i=0;
    FILE *fichier=NULL;

    if (cp1.id>0)
    {
        fichier=fopen("Pivot.txt","w");

        if(fichier != NULL)
        {
            // Enregistrement structure de controle
            fprintf(fichier,"%d\n",cp1.id);
            //ecriture des differentes structures
            for(i=0;i<cp1.id;i++)
            {
                fprintf(fichier,"%d\n%d\n%d\n",p[i].idPivot,p[i].idDisease,p[i].idSymptom);
            }
            fclose(fichier);
        }
    }
}
