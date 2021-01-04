#ifndef SYMPTOM_H_INCLUDED
#define SYMPTOM_H_INCLUDED

typedef struct controlSymptom CS;
struct controlSymptom
{
    int id;
    int current;
    int first;
    int last;
};

typedef struct Symptom Symptom;
struct Symptom
{
    int idSymptom;
    char name[100];
    char type[100]; // physical || general || radiological || biological
    char interpretation[100]; // somatic || psychic
    int isDeleted; //1 yes; 0 no
};

/**
 *Name: initSymptom
 *Used to initialize a structure in this case symptom.
 *@param Symptom *:Pointer of the Symptom's structure to initialize.
 */
void initSymptom(Symptom *);

/**
 *Name: createSymptom
 *Used to encode a new symptom.
 *@param Symptom *:Pointer of the Symptom's structure to encode parameters.
 *@param CS *: pointer of Symptom's controller.
 */
void createSymptom(Symptom *, CS *);

/**
 *Name: displaySymptom
 *Used to display a symptom's parameters.
 *@param Symptom: Pointer of the Symptom's structure to display parameters.
 */
void displaySymptom(Symptom);

/**
 *Name: updateSymptom
 *Used to update the parameters of a symptom.
 *@param Symptom *: Pointer of the Symptom's structure to edit parameters.
 */
void updateSymptom(Symptom *);

/**
 *Name: deleteSymptom
 *Used to "delete" a symptom
 *@param Symptom *: Pointer of the Symptom's structure to delete.
 */
void deleteSymptom(Symptom *);

/**
 *Name: nextSymptom
 *Used to move on to the next symptom
 *@param Symptom *:  Pointer of the Symptom's structure to increment the ID.
 *@param CS *: Pointer of the Symptom's controller.
 */
void nextSymptom(Symptom *, CS *);

/**
 *Name: previousSymptom
 *Used to move on to the previous symptom.
 *@param Symptom *: Pointer of the Symptom's structure to decrement the ID.
 *@param CS *: Pointer of the Symptom's controller.
 */
void previousSymptom(Symptom *, CS *);

/**
 *Name: initFirstLastSymptom
 *Used to initialize the first and the last symptom.
 *@param Symptom *: Pointer of the Symptom's structure.
 *@param CS *: Pointer of the Symptom's controller.
 */
void initFirstLastSymptom(Symptom *, CS *);

/**
 *Name: selectSymptom
 *Used to select a symptom.
 *@param Symptom *: Pointer of the Symptom's structure.
 *@param CS *: Pointer of the Symptom's controller
 *@return the id of the selected symptom
 */

int selectSymptom(Symptom *,CS *);

/**
 *Name: loadSymptom
 *Used to load a Symptom from an external file.
 *@param Symptom *: Pointer of the Symptom's structure.
 *@param CS *: Pointer of the Symptom's controller.
 */
void loadSymptom(Symptom *,CS *);


/**
 *Name: saveSymptom
 *Used to save a Symptom to an external file.
 *@param Symptom *: Pointer of the Symptom's structure.
 *@param CS *: Pointer of the Symptom's controller
 */
void saveSymptom(Symptom *,CS);


#endif // SYMPTOM_H_INCLUDED
