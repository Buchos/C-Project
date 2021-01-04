#ifndef PIVOT_H_INCLUDED
#define PIVOT_H_INCLUDED

typedef struct controlPivot CP;
struct controlPivot
{
    int id;
};
typedef struct Pivot Pivot;
struct Pivot
{
    int idPivot;

    int idDisease;
    int idSymptom;
};

/**
 *Name: initPivot
 *Used to initialize a structure in this case Pivot
 *@param Pivot *: Pointer of the Pivot's structure to initialize.
 */
void initPivot(Pivot *);

/**
 *Name: createPivot
 *Used to encode a new Pivot.
 *@param Pivot *: Pointer of the Pivot's structure to encode parameters.
 *@param CP *: pointer of Pivot's controller.
 *@param int : The disease's ID
 *@param int : The Symptom's ID
 */
void createPivot(Pivot *,CP *,int,int);

/**
 *Name: loadDisease
 *Used to load a Pivot from an external file.
 *@param Pivot *: Pointer of the Pivot's structure.
 *@param CP *: Pointer of the Pivot's controller.
 */
void loadPivot(Pivot *,CP *);

/**
 *Name: savePivot
 *Used to save a Pivot to an external file.
 *@param Pivot *: Pointer of the Pivot's structure.
 *@param CP *: Pointer of the Pivot's controller.
 */
void savePivot(Pivot *,CP);

#endif // PIVOT_H_INCLUDED
