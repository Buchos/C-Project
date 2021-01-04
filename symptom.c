#include "symptom.h"
#include "perso.h"
#include <string.h>
#include<stdio.h>

void initSymptom(Symptom *s)
{
    s->idSymptom = -1;
    strcpy(s->name, "Unknown");
    strcpy(s->type, "Unknown");
    strcpy(s->interpretation, "Unknown");
    s->isDeleted = 0;
}
void createSymptom(Symptom *s, CS *cs1)
{
    s[cs1->id].idSymptom = cs1->id;
    s[cs1->id].isDeleted = 0;

    printf("\nPlease enter the name of the symptom: ");
    lire(s[cs1->id].name,100);
    printf("\nPlease enter the type of the symptom (physical || general || radiological || biological): ");
    lire(s[cs1->id].type,100);
    printf("\nPlease enter the interpretation of the symptom (somatic || psychic): ");
    lire(s[cs1->id].interpretation,100);
    cs1->current=cs1->id;
    cs1->id++;
}
void displaySymptom(Symptom s)
{
    if(s.isDeleted == 1)
    {
        printf("\n Symptom erased");
    }
    else
    {
        printf("\n ID : %d", s.idSymptom);
        printf("\n Name : %s", s.name);
        printf("\n Type : %s", s.type);
        printf("\n Interpretation : %s", s.interpretation);
    }
}
void updateSymptom(Symptom *s)
{
    char rep;
    printf("\nDo you want to change the name of the symptom? (y/n) ");
    rep = lireCaractere();
    if(rep=='y' || rep=='Y')
    {
        printf("\n Please enter the name of the symptom: ");
        lire(s->name,100);
    }

    printf("\nDo you want to change the type of the symptom? (y/n) ");
    rep = lireCaractere();
    if(rep=='y' || rep=='Y')
    {
        printf("\nPlease enter the type of the symptom (physical || general || radiological || biological): ");
        lire(s->type,100);
    }
    printf("\nDo you want to change the interpretation of the symptom? (y/n) ");
    rep = lireCaractere();
    if(rep=='y' || rep=='Y')
    {
        printf("\nPlease enter the interpretation of the symptom (somatic || psychic): ");
        lire(s->interpretation,100);
    }
}
void deleteSymptom(Symptom *s)
{
    s->isDeleted =1;
}
void nextSymptom(Symptom *s, CS *cs1)
{
    if(cs1->current == cs1->last)
    {
        printf("\n You are already on the last item");
        getchar();
    }
    else
    {
        do
        {
            cs1->current++;
        }while(s[cs1->current].isDeleted==1);
    }
}
void previousSymptom(Symptom *s, CS *cs1)
{
    if(cs1->current == cs1->first)
    {
        printf("\n You are already on the first item");
        getchar();
    }
    else
    {
        do
        {
            cs1->current--;
        }while(s[cs1->current].isDeleted==1);
    }
}
void initFirstLastSymptom(Symptom *s, CS *cs1)
{
    int i=0;
    while(s[i].isDeleted==1)
    {
        i++;
    }
    cs1->first=i;

    i=cs1->id-1;
    while(s[i].isDeleted==1)
    {
        i--;
    }
    cs1->last=i;
}
int selectSymptom(Symptom *s,CS *cs1)
{
    int i=0;
    int choice=-1;

    do
    {
        do
        {
            printf("\n Select a symptom : ");
            printf("\n*******************");

            for(i=0; i< cs1->id; i++)
            {
                if(s[i].isDeleted==0)
                {
                    printf("\n%d. %s", s[i].idSymptom, s[i].name);
                }
            }
            printf("\n Please enter your choice : ");
            choice = lireInt();
        } while(choice<0 || choice> cs1->last);
    } while(s[choice].isDeleted==1);
    return choice;
}
void loadSymptom(Symptom *s,CS *cs1)
{
    int i=0;
    char *c=NULL;
    FILE *file=NULL;

    file=fopen("Symptom.txt","r");

    if(file != NULL)
    {
        // Lecture de la structure de controle
        fscanf(file,"%d\n%d\n%d\n%d\n",&cs1->id,&cs1->current,&cs1->first,&cs1->last);
        // Lecture des differentes structures
        for(i=0;i<cs1->id;i++)
        {
            fscanf(file,"%d\n",&s[i].idSymptom);

            fgets(s[i].name,100,file);
            c=strchr(s[i].name,'\n');
            *c='\0';
            fgets(s[i].type,100,file);
            c=strchr(s[i].type,'\n');
            *c='\0';
			fgets(s[i].interpretation,100,file);
            c=strchr(s[i].interpretation,'\n');
            *c='\0';

            fscanf(file,"%d\n",&s[i].isDeleted);
        }
        fclose(file);
    }
}
void saveSymptom(Symptom *s,CS cs1)
{
    int i=0;
    FILE *file = NULL;

    if(cs1.id>0)
    {
        file= fopen("Symptom.txt","w");

        if (file!=NULL)
        {

            //Enregistrement de la structure de controle
            fprintf(file,"%d\n",cs1.id);
            fprintf(file,"%d\n",cs1.current);
            fprintf(file,"%d\n",cs1.first);
            fprintf(file,"%d\n",cs1.last);



            //enregistrement des différentes structures
            for(i=0;i<cs1.id;i++)
            {
                fprintf(file,"%d\n", s[i].idSymptom);
                fprintf(file,"%s\n", s[i].name);
                fprintf(file,"%s\n", s[i].type);
                fprintf(file,"%s\n", s[i].interpretation);
                fprintf(file,"%d\n", s[i].isDeleted);
            }
            fclose(file);
        }
    }
}
