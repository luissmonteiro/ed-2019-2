#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <string>


class celula{
	public:
		int tempo;
		std::string nome;
		int mes;
		celula* proximo;
		celula(int t,std::string nome);
		celula();
		~celula(){};
};

	
class Lista{
	public:
		celula *primeiro = NULL;
		celula *ultimo = NULL;
		int totalMeses = 1;
		Lista();
		int getTempo(int posicao);
		std::string getNome(int posicao);
		void Inserir(int tempo,std::string nome);
		void Substituir(int posicao,int tempo, std::string nome);
		void Remove(std::string nome);
		void Print();
		bool existe(std::string nome);
		bool existe(int posicao);
		void LimparLista();
		int size();
		int searchPos(int n);
		int searchName(std::string nome);
		~Lista(){};
};


class Vector{
	public:
		int tamanho;
		int totalMeses;
		int tamanhoVec = 0;
		celula *celulas[200000];
		Vector();
		Vector(int tamanho);
		void Substituir(int i,int j);
		void Insere(celula *elemento);
		void Insere(int tempo, std::string nome);
		void Remove(int posicao,celula *item);
		void Print();
		void OrdenaChar(int nrPlanetas, int nrCaracteres);
		void ContaChar(int totalPlanetas, size_t sizeChar);
		~Vector(){};
};


#endif