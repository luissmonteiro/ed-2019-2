#include "lista.hpp"

celula::celula(){
	this->chave = 0;
	this->proximo = NULL;
}

celula::~celula(){
	this->proximo = NULL;
}

Lista::Lista(){
	this->primeiro = NULL;
	this->ultimo = NULL;
}

Lista::~Lista(){}

bool Lista::existe(int elemento){
	if(elemento <=0){
		return -1;
	}
	celula *atual = new celula();
	atual = this->primeiro;
	while(atual != NULL){
		if(atual->chave == elemento){
			return 1;
		}
		atual = atual->proximo;
	}
	delete atual;
	return 0;
}


//alguns algoritmos para operações básicas das listas foram retirados do site codementor.io
//com algumas modificações para as especificidades do TP
void Lista::Inserir(int elemento,int operations){
	if(this->existe(elemento) == 0) {
		celula *temp = new celula;
		temp->chave = elemento;
		temp->operacoes = operations;
		temp->proximo = NULL;

		if(this->primeiro == NULL){
			this->primeiro = temp;
			this->ultimo = temp;
			this->primeiro->proximo = NULL;
			temp = NULL;
		}
		else{
			this->ultimo->proximo = temp;
			this->ultimo = temp;
		}
	}
}

void Lista::RemoveInput(int elemento){
	celula *aux = this->primeiro;
	if(aux->chave == elemento){
		this->primeiro = aux->proximo;
		delete aux;
	}
	else{
		celula *terceiro = new celula();
		terceiro = aux->proximo->proximo;
		while(terceiro != NULL){
			if(aux->proximo->chave == elemento){
				celula *aux2 = aux->proximo;
				aux->proximo = aux2->proximo;
				delete aux2;
				return;
			}
			aux = aux->proximo;
			terceiro = aux->proximo->proximo;
		}
		if(aux->proximo->chave == elemento){
			this->ultimo = aux;
			aux->proximo = NULL;
		}
	}

}

void Lista::Print(){
	celula *atual = new celula;
	atual = this->primeiro;
	while(atual != NULL){
		std::cout << atual->chave << " ";
		atual = atual->proximo;
	}
	delete atual;
}

int Lista::size(){
	int aux = 0;
	celula *atual = new celula;
	atual = this->primeiro;
	while(atual != NULL){
		aux++;
		atual = atual->proximo;
	}

	delete atual;
	return aux;
}

void Lista::LimparLista(){
	int tamanho = Lista::size();
	for(int aux = 0; aux < tamanho; aux++){
		RemoveInput(this->primeiro->chave);
	}
}

void Lista::CopiaLista(Lista *exemplo){
	//remover todos q tiverem operacoes>1 e o proprio elemento

	Lista::LimparLista();
	celula *auxiliar = new celula();
	celula *principal = new celula();
	auxiliar = exemplo->primeiro;
	Lista::Inserir(auxiliar->chave,1);
	principal = auxiliar->proximo;
	while(principal != NULL){
		Lista::Inserir(principal->chave,1);
		auxiliar = auxiliar->proximo;
		principal = auxiliar;
	}
	delete auxiliar;
	delete principal;
}