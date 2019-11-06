#include <iostream> 
#include <string>
#include "lista.hpp"
#include "ordena.hpp"

int main() {
  	int T;//tempo total em minutos para visitas
  	int p;//numero total de planetas
  	int c;//nr de caracteres para nome de planeta
  	std::cin >> T >> p >> c;
  	Vector *planetas = new Vector(p);
  	celula *auxiliar = new celula;
  	int tempo;
  	std::string nome;
  	for(int i = 0; i < p; i++){
  		std::cin >> tempo >> nome;
  		auxiliar->tempo = tempo;
  		auxiliar->nome = nome;
  		planetas->celulas[i]->tempo = auxiliar->tempo;
  		planetas->celulas[i]->nome = auxiliar->nome;
    }
  	mergeSort(planetas,0,planetas->tamanho-1);
  	OrdenaMes(planetas, T);
  	planetas->OrdenaChar(p,c);
  	planetas->Print();
  	delete planetas;
  	delete auxiliar;
  	return 0;
}
