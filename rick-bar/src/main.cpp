#include <iostream>
#include "lista.hpp"
#include "medicao.hpp"

int main() {
  int q;
  char e;
  Lista *recipientes = new Lista();
  Lista *operacoes = new Lista();
  while(scanf("%d %c", &q, &e) != EOF) {
    if (e == 'i')
      recipientes->Inserir(q,1);
    else if(e == 'r'){
      recipientes->RemoveInput(q);//pareo aqui
    }
    else if(e == 'p'){
      operacoes->LimparLista();
      std::cout << bar(recipientes,q,operacoes) << std::endl;
    }
  }
  recipientes->LimparLista();
  operacoes->LimparLista();
  delete recipientes;
  delete operacoes;
  return 0;
}
