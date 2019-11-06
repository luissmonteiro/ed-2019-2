#include "ordena.hpp"


/*void mergeSort(Lista *planetas, int inicio, int fim){
	int i,j,k,metadeTamanho;
	Lista *temp = new Lista;
	if(planetas->primeiro->nome == planetas->ultimo->nome){
		return;
	}
	metadeTamanho = (planetas->searchName(planetas->primeiro->nome) + planetas->searchName(planetas->ultimo->nome))/2;
	
	mergeSort(planetas, inicio , metadeTamanho);
	mergeSort(planetas,metadeTamanho+1,fim);

	i = inicio;
	j = metadeTamanho +1;
	k = 0;
	temp = (Lista *) malloc(sizeof(int) * (fim - inicio + 1));

	while(i < metadeTamanho+1 || j < fim+1){
		if(i == metadeTamanho+1){
			celula *auxiliar = new celula;
			auxiliar = planetas->primeiro;
			for(int i = 1; i < j;i++){
				auxiliar = auxiliar->proximo;
			}
			temp->Inserir(auxiliar->t,auxiliar->nome);
			j++;
			k++;
			free(auxiliar);
			delete auxiliar;
		}
		else{
			if(j == fim+1){
				if(i == 0){
					temp->Inserir(planetas->primeiro->t,planetas->primeiro->nome);
					i++;
					k++;
					return;
				}
				celula *auxiliar = new celula;
				auxiliar = planetas->primeiro;
				for(int x = 1; x < i; x++){
					auxiliar = auxiliar->proximo;
				}
				temp->Inserir(auxiliar->t,auxiliar->nome);
				i++;
				k++;
				free(auxiliar);
				delete auxiliar;
			}
			else{
				celula *aux1 = new celula;
				celula *aux2 = new celula;
				aux1 = planetas->primeiro;
				aux2 = planetas->primeiro;
				for(int l = 1; l < i; l++){
					aux1 = aux1->proximo;
				}
				for(int l = 1; l < j; l++){
					aux2 = aux2->proximo;
				}
				if(aux1->t < aux2->t){
					aux2 = temp->primeiro;
					for(int z = 1; z < k; z++){
						aux2 = aux2->proximo;
					}
					aux2->t = aux1->t;
					aux2->nome = aux1->nome;
					i++;
					k++;
					aux1 = NULL;
					aux2 = NULL;
					delete aux1;
					delete aux2;
				}
				else{
					celula *aux1 = new celula;
					aux1 = temp->primeiro;
					for(int z = 1; z < k; z++){
						aux1 = aux1->proximo;
					}
					celula *aux2 = new celula;
					aux2 = planetas->primeiro;
					for(int z = 1; z < j; z++){
						aux2 = aux2->proximo;
					}
					aux1->t = aux2->t;
					aux1->nome = aux2->nome;
					j++;
					k++;
					aux1 = NULL;
					aux2 = NULL;
					delete aux1;
					delete aux2;
				}
			}
		}
	}
	for(i = inicio; i <= fim; i++){
		celula *aux1 = new celula;
		aux1 = temp->primeiro;
		int q = i - inicio;
		for(int x = 1; x < q;x++){
			aux1 = aux1->proximo;
		}
		celula *aux2 = new celula;
		aux2 = planetas->primeiro;
		for(int x = 1; x < i; x++){
			aux2 = aux2->proximo;
		}
		aux2->t = aux1->t;
		aux2->nome = aux1->nome;
		free(aux1);
		free(aux2);
		delete aux1;
		delete aux2;
	}
	planetas->Print();
	free(temp);
}*/

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

	/*Vector *HelpList = new Vector(planetas->tamanho);
	celula *auxiliar = new celula;
	auxiliar->tempo = 0;
	int i = inicio;
	int j = meio+1;
	int k = 0;//aa
	while(i <= meio && j <= fim){
		if(planetas->celulas[i]->tempo <= planetas->celulas[j]->tempo){
			HelpList->celulas[k]->tempo = planetas->celulas[i]->tempo;
			HelpList->celulas[k]->nome = planetas->celulas[i]->nome;
			k++;//aa
			i++;
		}
		else{
			HelpList->celulas[k]->tempo = planetas->celulas[j]->tempo;
			HelpList->celulas[k]->nome = planetas->celulas[j]->nome;
			k++;//aa
			j++;
		}
	}

	while(i <= meio){
		HelpList->celulas[k]->tempo = planetas->celulas[i]->tempo;
		HelpList->celulas[k]->nome = planetas->celulas[i]->nome;
		k++;//aa
		i++;
	}

	while(j <= fim){
		HelpList->celulas[k]->tempo = planetas->celulas[j]->tempo;
		HelpList->celulas[k]->nome = planetas->celulas[j]->nome;
		k++;//aa
		j++;
	}

	for(i = inicio; i <= fim; i++){
		planetas->celulas[i]->tempo = HelpList->celulas[i-inicio]->tempo;
		planetas->celulas[i]->nome = HelpList->celulas[i-inicio]->nome;
	}
	delete HelpList;*/
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


void ChangeStruct(Lista *lista, int nrPlanetas,int nrCaracteres){
	celula *atual = new celula;
	Vector *vetor = new Vector(lista->size());
	atual = lista->primeiro;
	vetor->celulas[0] = atual;
	for(int i = 1; i < nrPlanetas; i++){
		atual = atual->proximo;
		vetor->celulas[i] = atual;
	}
	vetor->totalMeses = lista->totalMeses;
	vetor->OrdenaChar(nrPlanetas,nrCaracteres);
	vetor->Print();
	atual = NULL;
	delete atual;
	delete vetor;
}

void OrdenaChar(Vector *planetas,int nrPlanetas, int nrCaracteres){
	/*size_t k = planetas->celulas[0]->nome.size();

	for(size_t c = k; c > 0; c--){
		ContaChar(planetas,nrPlanetas, c-1);
	}

	planetas->Print();
	delete planetas;*/
}

void ContaChar(Vector *planetas, int totalPlanetas, size_t sizeChar){
	/*Vector *auxiliar = new Vector(totalPlanetas);
	int i,j;
	int base = 257;
	int *c = new int[base];
	for(i = 0; i < base; i++){
		c[i] = 0;
	}

	for(j = 0; j < totalPlanetas; j++ ){
		c[sizeChar-1<planetas->celulas[j]->nome.size() ? (int)(unsigned char)planetas->celulas[j]->nome[sizeChar-1]+1 : 0]++;
	}
	for(int k = 0; k < base; k++){
		c[k] += c[k-1];
	}

	for(int a = totalPlanetas-1; a>=0; a--){
		auxiliar->celulas[c[sizeChar-1<planetas->celulas[a]->nome.size() ? (int)(unsigned char)planetas->celulas[a]->nome[sizeChar-1]+1 : 0] -1 ] = planetas->celulas[a];
		c[sizeChar-1<planetas->celulas[a]->nome.size() ? (int)(unsigned char)planetas->celulas[a]->nome[sizeChar-1]+1 : 0]--;
	}

	for(int r = 0; r < totalPlanetas; r++){
		planetas->celulas[r] = auxiliar->celulas[r];
	}

	delete []c;
	delete auxiliar;*/
}


