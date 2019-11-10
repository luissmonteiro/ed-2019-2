#include "ordena.hpp"

void merge(Vector *planetas,int inicio,int meio,int fim){
	int i = 0;
	int j = 0;
	int k = 0;
	int a = meio-inicio+1;
	int b = fim-meio;
	Vector Esq = Vector(a);
	Vector Dir = Vector(b);

	for(i = 0; i < a; i++){
		Esq.celulas[i] = planetas->celulas[inicio+i];
	}
	for(j = 0; j < b; j++){
		Dir.celulas[j] = planetas->celulas[meio+1+j];
	}
	i = 0;
	j = 0;
	k = inicio;

	while(i < a && j < b){
		if(Esq.celulas[i]->tempo <= Dir.celulas[j]->tempo){
			planetas->celulas[k] = Esq.celulas[i];
			i++;
		}
		else{
			planetas->celulas[k] = Dir.celulas[j];
			j++;
		}
		k++;
	}

	while(i < a){
		planetas->celulas[k] = Esq.celulas[i];
		i++;
		k++;
	}

	while(j < b){
		planetas->celulas[k] = Dir.celulas[j];
		j++;
		k++;
	}

}

void mergeSort(Vector *planetas, int inicio,int fim){
	if(inicio < fim){
		int meio = (inicio+fim)/2;
		mergeSort(planetas,inicio,meio);
		mergeSort(planetas,meio+1,fim);
		merge(planetas,inicio,meio,fim);
	}
}

void OrdenaMes(Vector *planetas, int T){
	int mes = 1;
	int somaTempos = 0;
	celula *auxiliar = new celula;
	auxiliar = planetas->celulas[0];
	for(int i = 0; i < planetas->tamanho; i++){
		somaTempos += auxiliar->tempo;
		auxiliar->mes = mes;
		if(somaTempos > T){
			somaTempos = auxiliar->tempo;
			mes++;
			auxiliar->mes = mes;
		}
		auxiliar = planetas->celulas[i+1];
	}
	planetas->totalMeses = mes;
}
