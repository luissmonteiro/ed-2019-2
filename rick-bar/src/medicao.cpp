#include "medicao.hpp"


int bar(Lista *recipientes,int volume,Lista *operacoes) {
	int NumeroElementos = recipientes->size();
	int contador = 1;
	if(volume == 0){
		return 0;
	}
	else{
		celula *auxiliar = new celula();
		celula *celula2 = new celula();	
		auxiliar = recipientes->primeiro;
		int operacaoInicial = 1;
		//caso de 1 operação apenas ser suficiente
		for(contador = 1; contador <= NumeroElementos; contador++){
			if(auxiliar->chave == volume){
				auxiliar = NULL;
				celula2 = NULL;
				return 1;
			}
			operacoes->Inserir(auxiliar->chave,1);
			auxiliar = auxiliar->proximo;
			
		}
		celula2 = operacoes->primeiro;
		//resto dos casos
		while(true){
			contador = 1;
			operacaoInicial++;
			auxiliar = recipientes->primeiro;
			while(contador <= NumeroElementos){
				if(celula2->chave + auxiliar->chave == volume){
					return celula2->operacoes+auxiliar->operacoes;
				}
				else if(operacoes->existe(celula2->chave+auxiliar->chave)==0){	
					operacoes->Inserir(celula2->chave+auxiliar->chave,celula2->operacoes+auxiliar->operacoes);
				}
				if(celula2->chave - auxiliar->chave == volume){
					return celula2->operacoes+1;
				}
				else if(operacoes->existe(celula2->chave - auxiliar->chave)== 0){
					operacoes->Inserir(celula2->chave-auxiliar->chave,celula2->operacoes+1);
				}
				auxiliar = auxiliar->proximo;
				contador++;
			}
			if(celula2->proximo == NULL){
				celula2 = operacoes->primeiro;
			}
			else{
				celula2 = celula2->proximo;
			}

		}
	}
}

