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


Lista::Lista(){
	this->primeiro = NULL;
	this->ultimo = NULL;
}

int Lista::getTempo(int posicao){
	int i;
	if(posicao > this->size()){
		return -1;
	}
	celula *temporaria = new celula;
	temporaria = this->primeiro;
	for(i = 0; i < posicao; i++){
		temporaria = temporaria->proximo;
	}
	i = temporaria->tempo;
	temporaria = NULL;
	free(temporaria);
	delete temporaria;
	return i;

}

std::string Lista::getNome(int posicao){
	int i;
	if(posicao >= this->size()){
		return "erro";
	}
	celula *temporaria = new celula;
	temporaria = this->primeiro;
	for(i = 0; i < posicao; i++){
		temporaria = temporaria->proximo;
	}
	std::string planet;
	planet = temporaria->nome;
	temporaria = NULL;
	free(temporaria);
	delete temporaria;
	return planet;
}

void Lista::Inserir(int tempo,std::string nome){
	celula *temp = new celula(tempo,nome);
	if(this->primeiro == NULL){
		this->primeiro = temp;
		this->ultimo = temp;
		this->primeiro->proximo = NULL;
		temp = NULL;
		delete temp;
	}
	else{
		this->ultimo->proximo = temp;
		this->ultimo = temp;
		temp = NULL;
		delete temp;
	}
}



void Lista::Remove(std::string nome){
	celula *temp = this->primeiro;
	if(temp->nome == nome){
		this->primeiro = temp->proximo;
		delete temp;
	}
	else{
		celula *terceiro = new celula();
		terceiro = temp->proximo->proximo;
		while(terceiro != NULL){
			if(temp->proximo->nome == nome){
				celula *aux = temp->proximo;
				temp->proximo = aux->proximo;
				delete aux;
				return;
			}
			temp = temp->proximo;
			terceiro = temp->proximo->proximo;
		}
		if(temp->proximo->nome == nome){
			this->ultimo = temp;
			temp->proximo = NULL;
			delete temp->proximo;
		}
	}
}
void Lista::Print(){
	celula *atual = new celula;
	atual = this->primeiro;
	while(atual != NULL){
		std::cout << atual->mes << " " << atual->nome << " " << atual->tempo;
		atual = atual->proximo;
	}
	atual = NULL;
	delete atual;
}
bool Lista::existe(std::string nome){
	nome = nome;
	return 1;
}

bool Lista::existe(int posicao){
	if(posicao > this->size()){
		return 0;
	}
	return 1;
}

int Lista::size(){
	int aux = 0;
	celula *atual = new celula();
	atual = this->primeiro;
	while(atual != NULL){
		aux++;
		atual = atual->proximo;
	}
	atual = NULL;
	delete atual;
	return aux;
}

void Lista::LimparLista(){
	int tamanho = this->size();
	for(int contador = 0; contador < tamanho; contador++){
		this->Remove(this->primeiro->nome);
	}
}

int Lista::searchPos(int n){
	if(n > this->size() || n < 0){
		std::cout << "posicao n existe\n";
		return -1;
	}
	celula *auxiliar = new celula;
	auxiliar = this->primeiro;
	for(int i = 0; i < n; i++){
		auxiliar = auxiliar->proximo;
	}
	std::cout << auxiliar->nome;
	auxiliar = NULL;
	delete auxiliar;
	return 0;
}

int Lista::searchName(std::string nome){
	celula *auxiliar = new celula;
	auxiliar = this->primeiro;
	for(int i = 0; i < this->size(); i++){
		if(auxiliar->nome == nome){
			return i;
		}
	}
	return -1;
}

void Lista::Substituir(int posicao,int tempo,std::string nome){
	int i;
	if(this->existe(posicao) == 0){
		std::cout << "\nreplacing error\n";
	}
	else{
		celula *temp = new celula;
		temp = this->primeiro;
		for(i = 0; i < posicao; i++){
			temp = temp->proximo;
		}
		//std::cout << " " << temp->tempo << " - " << tempo << std::endl; 
		temp->tempo = tempo;
		temp->nome = nome;
		temp = NULL;
		free(temp);
		delete temp;
	}

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
	int contador = 0;
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


	/*int contadorAuxiliar = 0;
	int tamanhoVetor = this->tamanho;
	int tamanhoVetor2 = tamanhoVetor;
	Vector auxiliar = Vector(this->tamanho);
	for(mes = 1; mes <= this->totalMeses; mes++){
		if(mes == 1){

			for(int i = 0; i < tamanhoVetor; i++){
				if(this->celulas[i]->mes == mes){
					tamanhoVetor2--;
					std::cout << this->celulas[i]->mes << " " << this->celulas[i]->nome << " " << this->celulas[i]->tempo;
					std::cout << std::endl;
				}
				else{
					auxiliar.celulas[contadorAuxiliar]->mes = this->celulas[i]->mes;
					auxiliar.celulas[contadorAuxiliar]->nome = this->celulas[i]->nome;
					auxiliar.celulas[contadorAuxiliar]->tempo = this->celulas[i]->tempo;
				}
			}
		}
		else{
			int k = 0;
			tamanhoVetor = tamanhoVetor2;
			for(int i = 0 ; i < tamanhoVetor2; i++){
				if(auxiliar.celulas[i]->mes == mes){
					tamanhoVetor--;
					std::cout << auxiliar.celulas[i]->mes << " " << auxiliar.celulas[i]->nome << " " << auxiliar.celulas[i]->tempo;
					std::cout << std::endl;
					auxiliar.celulas[i]->mes = 0;

				}
				else{
					auxiliar.celulas[k]->mes = auxiliar.celulas[i]->mes;
					auxiliar.celulas[k]->nome = auxiliar.celulas[i]->nome;
					auxiliar.celulas[k]->tempo = auxiliar.celulas[i]->tempo;
					k++;
				}
			}
		}
	}*/
}

void Vector::OrdenaChar(int nrPlanetas,int nrCaracteres){
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