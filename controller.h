#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "disease.h"
#include "symptom.h"
#include "pivot.h"

/**
 *Name: Main_Controller
 *Used to launch the program.
 */
void Main_Controller();

/**
 *Name: diseaseController
 *Used to display the disease's Menu.
 *@param Disease *: Pointer of the Disease's structure.
 *@param CD *: Pointer of the Disease's controller.
 */
void diseaseController(Disease *,CD *);

/**
 *Name: symptomController
 *Used to display the symptom's Menu.
 *@param Symptom *: Pointer of the Symptom's structure.
 *@param CS *: Pointer of the Symptom's controller.
 */
void symptomController(Symptom *,CS *);

/**
 *Name: pivotController
 *Used to display the Pivot's Menu (link diseases with symptoms)
 *@param Pivot *: Pointer of the Pivot's structure.
 *@param CP*: Pointer of the Pivot's controller.
 *@param Disease *: Pointer of the Disease's structure.
 *@param CD *: Pointer of the Disease's controller.
 *@param Symptom *: Pointer of the Symptom's structure.
 *@param CS *: Pointer of the Symptom's controller.
 */
void pivotController(Pivot *,CP *, Disease *,CD *,Symptom *,CS *);
#endif // CONTROLLER_H_INCLUDED
