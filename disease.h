#ifndef DISEASE_H_INCLUDED
#define DISEASE_H_INCLUDED

typedef struct controlDisease CD;
struct controlDisease
{
    int id;
    int current;
    int first;
    int last;

};

typedef struct Disease Disease;
struct Disease
{
    int idDisease;
    char name[100];
    float deathRate;
    char type[100]; //neural,..
    char origin[100]; //country
    int isDeleted; // 0 exists; 1 is deleted

};

/**
 *Name: initDisease
 *Used to initialize a structure in this case disease.
 *@param Disease *: Pointer of the Disease's structure to initialize.
 */

void initDisease(Disease *);

/**
 *Name: createDisease
 *Used to encode a new disease.
 *@param Disease *: Pointer of the Disease's structure to encode parameters.
 *@param CD *: pointer of Disease's controller.
 */

void createDisease(Disease *, CD *);

/**
 *Name: displayDisease
 *Used to display a disease's parameters.
 *@param Disease *: Pointer of the Disease's structure to display parameters.
 */

void displayDisease(Disease);

/**
 *Name: updateDisease
 *Used to update the parameters of a disease.
 *@param Disease *: Pointer of the Disease's structure to edit parameters.
 */

void updateDisease(Disease *);

/**
 *Name: deleteDisease
 *Used to "delete" a disease
 *@param Disease *: Pointer of the Disease's structure to delete.
 */

void deleteDisease(Disease *);

/**
 *Name: nextDisease
 *Used to move on to the next disease.
 *@param Disease *: Pointer of the Disease's structure to increment the ID.
 *@param CD *: Pointer of the Disease's controller.
 */

void nextDisease(Disease *, CD *);

/**
 *Name: previousDisease
 *Used to move on to the previous disease.
 *@param Disease *: Pointer of the Disease's structure to decrement the ID.
 *@param CD *: Pointer of the Disease's controller.
 */

void previousDisease(Disease *, CD *);

/**
 *Name: initFirstLastDisease
 *Used to initialize the first and the last disease.
 *@param Disease *: Pointer of the Disease's structure.
 *@param CD *: Pointer of the Disease's controller.
 */

void initFirstLastDisease(Disease *, CD *);

/**
 *Name: selectDisease
 *Used to select a disease.
 *@param Disease *: Pointer of the Disease's structure.
 *@param CD *:  Pointer of the Disease's controller.
 *@return the id of the selected disease
 */

int selectDisease(Disease *,CD *);

/**
 *Name: loadDisease
 *Used to load a Disease from an external file.
 *@param Disease *: Pointer of the Disease's structure.
 *@param CD *: Pointer of the Disease's controller.
 */

void loadDisease(Disease *,CD *);

/**
 *Name: saveDisease
 *Used to save a Disease to an external file.
 *@param Disease *: Pointer of the Disease's structure.
 *@param CD *: Pointer of the Disease's controller.
 */

void saveDisease(Disease *,CD);

#endif // DISEASE_H_INCLUDED
