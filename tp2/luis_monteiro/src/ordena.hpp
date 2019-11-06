#ifndef __TP1_ED___
#define __TP1_ED__
#include "lista.hpp"

void mergeSort(Vector* planetas,int inicio, int fim);
void merge(Vector *planetas,int inicio,int meio,int fim);
void OrdenaMes(Vector *planetas, int T);
void ChangeStruct(Lista *lista, int nrPlanetas,int nrCaracteres);
void OrdenaChar(Vector *planetas,int nrPlanetas, int nrCaracteres);
void ContaChar(Vector *planetas, int totalPlanetas, size_t sizeChar);
#endif
