#include "disease.h"
#include "perso.h"
#include <string.h>
#include<stdio.h>


void initDisease(Disease * d)
{
    d->idDisease = -1;
    strcpy(d->name, "Unknown");
    strcpy(d->type, "Unknown");
    strcpy(d->origin, "Unknown");
    d->deathRate = -1;
    d->isDeleted = 0;
}
void createDisease(Disease *d, CD *cd1)
{
    d[cd1->id].idDisease = cd1->id;
    d[cd1->id].isDeleted = 0;

    printf("\nPlease enter the name of the disease: ");
    lire(d[cd1->id].name,100);
    printf("\nPlease enter the type of the disease: ");
    lire(d[cd1->id].type,100);
    printf("\nPlease enter the origin (Country) of the disease: ");
    lire(d[cd1->id].origin,100);
    printf("\nPlease enter the death-rate of the disease: ");
    d[cd1->id].deathRate =lireFloat();
    cd1->current=cd1->id;
    cd1->id++;
}
void displayDisease(Disease d)
{
    if(d.isDeleted == 1)
    {
        printf("\n Disease erased");
    }
    else
    {
        printf("\n ID : %d", d.idDisease);
        printf("\n Name : %s", d.name);
        printf("\n Type : %s", d.type);
        printf("\n Origin : %s", d.origin);
        printf("\n Death-rate : %.2f %%", d.deathRate);
    }
}

void updateDisease(Disease *d)
{
    char rep;
    printf("\nDo you want to change the name of the disease? (y/n) ");
    rep = lireCaractere();
    if(rep=='y' || rep=='Y')
    {
        printf("\n Please enter the name of the disease: ");
        lire(d->name,100);
    }

    printf("\nDo you want to change the type of the disease? (y/n) ");
    rep = lireCaractere();
    if(rep=='y' || rep=='Y')
    {
        printf("\n Please enter the type of the disease: ");
        lire(d->type,100);
    }
    printf("\nDo you want to change the origin of the disease? (y/n) ");
    rep = lireCaractere();
    if(rep=='y' || rep=='Y')
    {
        printf("\n Please enter the origin (Country) of the disease: ");
        lire(d->origin,100);
    }

    printf("\nDo you want to change the death-rate of the disease? (y/n) ");
    rep = lireCaractere();
    if(rep=='y' || rep=='Y')
    {
        printf("\n Please enter the death-rate of the disease: ");
        d->deathRate = lireFloat();
    }
}
void deleteDisease(Disease *d)
{
    d->isDeleted = 1;
}
void nextDisease(Disease *d, CD *cd1)
{
    if(cd1->current == cd1->last)
    {
        printf("\n You are already on the last item");
        getchar();
    }
    else
    {
        do
        {
            cd1->current++;
        }while(d[cd1->current].isDeleted==1);
    }
}
void previousDisease(Disease *d, CD *cd1)
{
    if(cd1->current == cd1->first)
    {
        printf("\n You are already on the first item");
        getchar();
    }
    else
    {
        do
        {
            cd1->current--;
        }while(d[cd1->current].isDeleted==1);
    }
}
void initFirstLastDisease(Disease * d, CD * cd1)
{
    int i=0;
    while(d[i].isDeleted==1)
    {
        i++;
    }
    cd1->first=i;

    i=cd1->id-1;
    while(d[i].isDeleted==1)
    {
        i--;
    }
    cd1->last=i;
}
int selectDisease(Disease * d,CD * cd1)
{
    int i=0;
    int choice=-1;

    do
    {
        do
        {
            printf("\n Select a disease ");
            printf("\n*******************");

            for(i=0; i< cd1->id; i++)
            {
                if(d[i].isDeleted==0)
                {
                    printf("\n%d. %s", d[i].idDisease, d[i].name);
                }
            }
            printf("\n Please enter your choice : ");
            choice = lireInt();
        } while(choice<0 || choice> cd1->last);
    } while(d[choice].isDeleted==1);
    return choice;
}
void saveDisease(Disease *d, CD cd1)
{
    int i=0;
    FILE *file = NULL;

    if(cd1.id>0)
    {
        file= fopen("Disease.txt","w");

        if (file!=NULL)
        {

            //Enregistrement de la structure de controle
            fprintf(file,"%d\n",cd1.id);
            fprintf(file,"%d\n",cd1.current);
            fprintf(file,"%d\n",cd1.first);
            fprintf(file,"%d\n",cd1.last);



            //enregistrement des différentes structures
            for(i=0;i<cd1.id;i++)
            {
                fprintf(file,"%d\n", d[i].idDisease);
                fprintf(file,"%s\n", d[i].name);
                fprintf(file,"%s\n", d[i].type);
                fprintf(file,"%s\n", d[i].origin);
                fprintf(file,"%f\n", d[i].deathRate);
                fprintf(file,"%d\n", d[i].isDeleted);
            }
            fclose(file);
        }
    }
}
void loadDisease(Disease *d, CD *cd1)
{
    int i=0;
    char *c=NULL;
    FILE *file=NULL;

    file=fopen("Disease.txt","r");

    if(file != NULL)
    {
        // Lecture de la structure de controle
        fscanf(file,"%d\n%d\n%d\n%d\n",&cd1->id,&cd1->current,&cd1->first,&cd1->last);
        // Lecture des differentes structures
        for(i=0;i<cd1->id;i++)
        {
            fscanf(file,"%d\n",&d[i].idDisease);

            fgets(d[i].name,100,file);
            c=strchr(d[i].name,'\n');
            *c='\0';
            fgets(d[i].type,100,file);
            c=strchr(d[i].type,'\n');
            *c='\0';
			fgets(d[i].origin,100,file);
            c=strchr(d[i].origin,'\n');
            *c='\0';

			fscanf(file,"%f\n",&d[i].deathRate);
            fscanf(file,"%d\n",&d[i].isDeleted);
        }
        fclose(file);
    }
}

