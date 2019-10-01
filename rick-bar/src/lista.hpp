#ifndef LISTA_H
#define LISTA_H

#include <iostream>


class celula{
	public:
		int chave,operacoes;
		celula* proximo;
		celula();
		~celula();
};

	
class Lista{
	public:
		celula *primeiro = NULL;
		celula *ultimo = NULL;
		Lista();
		void Inserir(int elemento,int operations);
		void Remove(int elemento,int operations);
		void Print();
		void RemoveInput(int elemento);
		bool existe(int elemento);
		void LimparLista();
		void CopiaLista(Lista* exemplo);
		int size();
		~Lista();
};



#endif