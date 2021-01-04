#include<stdio.h>
#include<stdlib.h>
#include "controller.h"
#include "perso.h"

void Main_Controller()
{
    int choice;
    int i=0;
    int checkIdDis = -1; // check if there's at least one Disease and one Symptom
    int checkIdSymp = -1; // check if there's at least one Disease and one Symptom

    Disease d[100];
    CD cd1;

    Symptom s[100];
    CS cs1;

    Pivot p[10000];
    CP cp1;

    //démarrage, tous les index à 0
    cd1.current =cd1.first = cd1.last=cd1.id =0;
    cs1.current =cs1.first = cs1.last=cs1.id =0;
    cp1.id =0;

    //initialistation des structures
    for(i=0;i<100;i++)
    {
        initDisease(&d[i]);
        initSymptom(&s[i]);
    }
    for(i=0;i<10000;i++)
    {
        initPivot(&p[i]);
    }

    //chargement des données pré-existantes
    loadDisease(d,&cd1);
    loadSymptom(s,&cs1);
    loadPivot(p, &cp1);

    do
    {
        system("cls");  // Attention compatibilité de la fonction system
        printf("\nMain Menu");
        printf("\n***************\n");
        printf("\n1. Disease");
        printf("\n2. Symptom");
        printf("\n3. Links (Disease's Symptoms)");
        printf("\n9. exit \n");
        printf("Your choice ? :");
        choice=lireInt();

        switch(choice)
        {
            case 1:
                diseaseController(d,&cd1);
                break;
            case 2:
                symptomController(s,&cs1);
                break;
            case 3:
                for(i=0;i<100;i++)
                {
                    if(d[i].idDisease != -1)
                    {
                        checkIdDis =1;
                    }
                    if(s[i].idSymptom !=-1)
                    {
                        checkIdSymp =1;
                    }
                }
                if(checkIdDis == 1 &&checkIdSymp ==1)
                {
                    pivotController(p, &cp1, d, &cd1, s, &cs1);
                    break;
                }
                else
                {
                    printf("You need at least one disease and one symptom !");
                    getchar();
                }
            case 9:
                printf("\n Bye bye !!");
                // Ne pas oublier de sauvegarder les données avant la sortie
                saveDisease(d,cd1);
                saveSymptom(s,cs1);
                savePivot(p,cp1);
                break;
            default:
                printf("\n Wrong choice, please try again...");
                getchar();
                break;
        }
    } while (choice!=9);
}
void diseaseController(Disease *d,CD * cd1)
{
    int choice;
    int i;
    int idDeadlyDisease =-1;
    float deathRate= 0;
    do
    {
        initFirstLastDisease(d,cd1);
        system("cls");  // Attention compatibilité de la fonction system
        displayDisease(d[cd1->current]);
        printf("\n\nDisease's Menu");
        printf("\n***************\n");
        printf("\n1. Create Disease");
        printf("\n2. Read Disease");
        printf("\n3. Update Disease");
        printf("\n4. Delete Disease");
        printf("\n5. First Disease");
        printf("\n6. Next Disease");
        printf("\n7. Previous Disease");
        printf("\n8. Last Disease");
        printf("\n9. Select Disease");
        printf("\n10. View the most deadly Disease");
        printf("\n11. View the least deadly Disease");
        printf("\n12. exit to the main menu\n");
        printf("Your choice ? :");
        choice=lireInt();

        switch(choice)
        {
            case 1:
                createDisease(d,cd1);
                break;
            case 2:
                displayDisease(d[cd1->current]);
                getchar();
                break;
            case 3:
                updateDisease(&d[cd1->current]);
                break;
            case 4:
                deleteDisease(&d[cd1->current]);
                break;
            case 5:
                cd1->current=cd1->first;
                break;
            case 6:
                nextDisease(d,cd1);
                break;
            case 7:
                previousDisease(d,cd1);
                break;
            case 8:
                cd1->current=cd1->last;
                break;
            case 9:
                if (cd1->id!=0)
                {
                    cd1->current=selectDisease(d,cd1);
                }
                break;
            case 10:
                deathRate = -1;
                for(i=0;i<100;i++)
                {
                    if (d[i].deathRate > deathRate && d[i].isDeleted  != 1)
                    {
                        deathRate = d[i].deathRate;
                        idDeadlyDisease = d[i].idDisease;
                    }
                }
                displayDisease(d[idDeadlyDisease]);
                getchar();
                break;
            case 11:
                deathRate = 110;
                for(i=0;i<100;i++)
                {
                    if(d[i].deathRate < deathRate && d[i].isDeleted != 1 && d[i].deathRate >=0) // à l'initialisation, death rate mis à -1. deathrate>0 necessaire à la verification
                    {
                        deathRate = d[i].deathRate;
                        idDeadlyDisease = d[i].idDisease;
                    }
                }
                displayDisease(d[idDeadlyDisease]);
                getchar();
                break;
            case 12:
                break;
            default:
                printf("\n Wrong choice, please try again...");
                getchar();
                break;
        }
    } while (choice!=12);
}
void symptomController(Symptom * s,CS * cs1)
{
    int choice;
    do
    {
        initFirstLastSymptom(s,cs1);
        system("cls");  // Attention compatibilité de la fonction system
        displaySymptom(s[cs1->current]);
        printf("\n\nSymptom's Menu");
        printf("\n***************\n");
        printf("\n1. Create Symptom");
        printf("\n2. Read Symptom");
        printf("\n3. Update Symptom");
        printf("\n4. Delete Symptom");
        printf("\n5. First Symptom");
        printf("\n6. Next Symptom");
        printf("\n7. Previous Symptom");
        printf("\n8. Last Symptom");
        printf("\n9. Select Symptom");
        printf("\n10. exit to the main menu\n");
        printf("Your choice ? :");
        choice=lireInt();

        switch(choice)
        {
            case 1:
                createSymptom(s,cs1);
                break;
            case 2:
                displaySymptom(s[cs1->current]);
                getchar();
                break;
            case 3:
                updateSymptom(&s[cs1->current]);
                break;
            case 4:
                deleteSymptom(&s[cs1->current]);
                break;
            case 5:
                cs1->current=cs1->first;
                break;
            case 6:
                nextSymptom(s,cs1);
                break;
            case 7:
                previousSymptom(s,cs1);
                break;
            case 8:
                cs1->current=cs1->last;
                break;
            case 9:
                if (cs1->id!=0)
                {
                    cs1->current=selectSymptom(s,cs1);
                }
                break;
            case 10:
                break;
            default:
                printf("\n Wrong choice, please try again...");
                getchar();
                break;
        }
    } while (choice!=10);
}

void pivotController(Pivot *p,CP *cp1, Disease *d,CD *cd1,Symptom *s,CS *cs1)
{
    int i=0;
    int j=0;
    int k=0;
    int choice;
    int choice2;
    int nbSymptoms;
    int selected =0;
    int tabNbSymptoms[100];
    int idSelectedDisease;
    int tabOccurrencesSymptoms[100];
    int idSelectedSymptom;
    cd1->current=cd1->first; // si une maladie a été supprimée entre temps
    do
    {
        initFirstLastDisease(d,cd1);
        system("cls");  // Attention compatibilité de la fonction system
        displayDisease(d[cd1->current]);
        printf("\n\nLinks Menu");
        printf("\n***************\n");
        printf("\n1. First Disease\n");
        printf("\n2. Last Disease\n");
        printf("\n3. Previous Disease\n");
        printf("\n4. Next Disease\n");
        printf("\n5. Select Disease\n");
        printf("\n6. Add Symptom to this Disease\n");
        printf("\n7. Read this Disease's Symptoms\n");
        printf("\n8. View the Disease with the most symptoms\n");
        printf("\n9. View the Disease with the least symptoms\n");
        printf("\n10. View the most common Symptom\n");
        printf("\n11. exit to the main menu\n\n");
        printf("Your choice ? :");
        choice = lireInt();

        switch (choice)
        {
            case 1:
                cd1->current=cd1->first;
                break;
            case 2:
                cd1->current=cd1->last;
                    break;
            case 3:
                previousDisease(d,cd1);
                break;
            case 4:
                nextDisease(d, cd1);
                break;
            case 5:
                if (cd1->id!=0)
                    {
                        cd1->current=selectDisease(d,cd1);
                    }
                    break;
            case 6:
                system("cls");
                printf("\nSelect the symptom to add to %s: ",d[cd1->current].name);
                do
                {
                    nbSymptoms=0;
                    selected =0;
                    for(i=0;i<100; i++)
                    {
                        if(s[i].idSymptom !=-1 && s[i].isDeleted ==0)
                        {
                            printf("\n%d. %s\n",i,s[i].name);
                            nbSymptoms++;
                        }
                    }
                    printf("\n%d. Go back to the menu\n",nbSymptoms); // nbSymptoms = dernier id +1
                    choice2 = lireInt(); // choice2 sera l'id du symptome
                    if(choice2<0 || choice2 >nbSymptoms)
                    {
                        printf("\nWrong choice, please try again.");
                        getchar();
                    }
                }while (choice2 <0 || choice2 >nbSymptoms);

                if(choice2 == nbSymptoms)
                {
                    break;
                }
                //gestion des doublons
                for(i=0;i<10000;i++)
                {
                    if(p[i].idSymptom == s[choice2].idSymptom && p[i].idDisease == d[cd1->current].idDisease && p[i].idPivot!= -1)
                    {
                        selected = 1;
                    }
                }
                if(selected == 0)
                {
                    createPivot(p, cp1, d[cd1->current].idDisease, choice2);
                }
                else
                {
                    printf("\nSymptom already selected.");
                    getchar();
                }
                break;
            case 7:
                system("cls");
                nbSymptoms =0;
                for(i=0;i<10000;i++)
                {
                    for(j=0; j<100; j++)
                    {
                        if(p[i].idPivot != -1 && p[i].idDisease == d[cd1->current].idDisease && p[i].idSymptom == s[j].idSymptom && s[j].isDeleted ==0)
                        {
                            nbSymptoms++;
                        }
                    }
                }
                if(nbSymptoms ==0)
                {
                    printf("\nNo Symptom found for %s.\n", d[cd1->current].name);
                    getchar();
                    break;
                }
                else
                {
                    printf("\n%s's symptoms :", d[cd1->current].name);
                    for(i=0;i<10000;i++)
                    {
                        for(j=0; j<100; j++)
                        {
                            if(p[i].idPivot != -1 && p[i].idDisease == d[cd1->current].idDisease && p[i].idSymptom == s[j].idSymptom &&s[j].isDeleted ==0)
                            {
                                printf("\n-%s", s[j].name);
                            }
                        }
                    }
                getchar();
                break;
                }
            case 8:
                system("cls");
                //initialisation
                for(i=0;i<100;i++)
                {
                    tabNbSymptoms[i]= -1;
                }
                // insertion du nombre de symptomes de chaque maladie
                for(i=0; i<100;i++)
                {
                    nbSymptoms =0;
                    for(j=0;j<10000;j++)
                    {
                        for(k=0; k<100; k++)
                        {
                            if(p[j].idPivot != -1 && p[j].idDisease == d[i].idDisease && p[j].idSymptom == s[k].idSymptom && s[k].isDeleted ==0)
                            {
                                nbSymptoms++;
                            }
                        }
                    }
                    tabNbSymptoms[i] = nbSymptoms;
                }
                //comparaison
                nbSymptoms =-1;
                for(i=0;i<100;i++)
                {
                    if(nbSymptoms < tabNbSymptoms[i])
                    {
                        nbSymptoms = tabNbSymptoms[i];
                        idSelectedDisease = d[i].idDisease;
                    }
                }
                printf("The disease with the most symptoms is %s (%d symptoms)",d[idSelectedDisease].name, tabNbSymptoms[idSelectedDisease]);
                getchar();
                break;
            case 9:
                system("cls");
                //initialisation
                for(i=0;i<100;i++)
                {
                    tabNbSymptoms[i]= -1;
                }
                // insertion du nombre de symptomes de chaque maladie
                for(i=0; i<100;i++)
                {
                    nbSymptoms =0;
                    for(j=0;j<10000;j++)
                    {
                        for(k=0; k<100; k++)
                        {
                            if(p[j].idPivot != -1 && p[j].idDisease == d[i].idDisease && p[j].idSymptom == s[k].idSymptom && s[k].isDeleted ==0)
                            {
                                nbSymptoms++;
                            }
                        }
                    }
                    tabNbSymptoms[i] = nbSymptoms;
                }
                //comparaison
                nbSymptoms =100;
                for(i=0;i<100;i++)
                {
                    if(nbSymptoms > tabNbSymptoms[i] && tabNbSymptoms[i]>0)
                    {
                        nbSymptoms = tabNbSymptoms[i];
                        idSelectedDisease = d[i].idDisease;
                    }
                }
                printf("The disease with the least symptoms is %s (%d symptoms)",d[idSelectedDisease].name, tabNbSymptoms[idSelectedDisease]);
                getchar();
                break;
            case 10:
                nbSymptoms =0;
                for (i=0;i<100;i++)
                {
                    tabOccurrencesSymptoms[i]=0;
                }
                for(i=0; i<100;i++)
                {
                    for(j=0;j<10000;j++)
                    {
                        for(k=0; k<100; k++)
                        {
                            if(p[j].idPivot != -1 && p[j].idDisease == d[i].idDisease && p[j].idSymptom == s[k].idSymptom && s[k].isDeleted ==0)
                            {
                                tabOccurrencesSymptoms[s[k].idSymptom]++;
                            }
                        }
                    }
                }
                for(i=0;i<100;i++)
                {
                    if(nbSymptoms < tabOccurrencesSymptoms[i])
                    {
                        nbSymptoms = tabOccurrencesSymptoms[i];
                        idSelectedSymptom = i;
                    }
                }
                printf("The most common Symptom is %s. It is present in %d Diseases",s[idSelectedSymptom].name, nbSymptoms);
                getchar();
            case 11:
                    break;
            default:
                    printf("\n Wrong choice, please try again...");
                    getchar();
                    break;
        }
    }while(choice!=11);


}

