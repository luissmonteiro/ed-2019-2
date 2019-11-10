#include "lista.hpp"

celula::celula(int t,std::string nome){
this->tempo = t;
this->nome = nome;
this->mes = 0;
}

celula::celula(){
	this->tempo = 0;
	this->mes = 0;
}



Vector::Vector(){}

Vector::Vector(int tamanho){
	this->tamanho = tamanho;
	for(int i = 0; i < tamanho; i++){
		this->celulas[i] = new celula;
	}
}


void Vector::Remove(int posicao,celula *item){
	if(posicao >= this->tamanho || posicao < 0){
		std::cout << "posicao n existe";
	}
	else{
		item = this->celulas[posicao];
		this->celulas[this->tamanho] = this->celulas[this->tamanho-1];
		for(int i = posicao; i < tamanho; i++){
			this->celulas[i] = this->celulas[i+1];
		}

	}
	this->tamanho--;
	delete item;
}


void Vector::Substituir(int i,int j){
	celula *auxiliar = new celula;
	auxiliar = this->celulas[i];
	this->celulas[i] = this->celulas[j];
	this->celulas[j] = auxiliar;
	auxiliar = NULL;
	delete auxiliar;
}

void Vector::Insere(celula *elemento){
	this->celulas[this->tamanho] = elemento;
	this->tamanho++;

}

void Vector::Insere(int tempo, std::string nome){
	this->celulas[this->tamanho]->tempo = tempo;
	this->celulas[this->tamanho]->nome = nome;
	this->tamanho++;
}


void Vector::Print(){
	int mes;
	for(mes = 1; mes <= this->totalMeses; mes++){
		for(int i = 0; i < this->tamanho; i++){
			if(this->celulas[i]->mes == mes){
				std::cout << this->celulas[i]->mes << " " << this->celulas[i]->nome << " " << this->celulas[i]->tempo;
				std::cout << std::endl;
				this->Remove(i,this->celulas[i]);
				i--;
			}
		}
	}

}

void Vector::RadixSort(int nrPlanetas,int nrCaracteres){
	size_t k = this->celulas[0]->nome.size();

	for(size_t c = k; c > 0; c--){
		this->ContaChar(nrPlanetas, c-1);
	}

}

void Vector::ContaChar( int totalPlanetas, size_t sizeChar){
	Vector *auxiliar = new Vector(totalPlanetas);
	int i,j;
	int base = 257;
	int *c = new int[base];
	for(i = 0; i < base; i++){
		c[i] = 0;
	}

	for(j = 0; j < totalPlanetas; j++ ){
		c[sizeChar<this->celulas[j]->nome.size() ? (int)(unsigned char)this->celulas[j]->nome[sizeChar]+1 : 0]++;
	}
	for(int k = 0; k < base; k++){
		c[k] += c[k-1];
	}

	for(int a = totalPlanetas-1; a>=0; a--){
		auxiliar->celulas[c[sizeChar<this->celulas[a]->nome.size() ? (int)(unsigned char)this->celulas[a]->nome[sizeChar]+1 : 0] -1 ] = this->celulas[a];
		c[sizeChar<this->celulas[a]->nome.size() ? (int)(unsigned char)this->celulas[a]->nome[sizeChar]+1 : 0]--;
	}

	for(int r = 0; r < totalPlanetas; r++){
		this->celulas[r] = auxiliar->celulas[r];
	}

	delete []c;
	delete auxiliar;
}