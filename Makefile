# == VARIAVEIS ===
# ================
#
# Podemos declarar algumas variaveis dentro do Makefile (sintaxe similar a bash)
# Isso facilita o seu trabalho caso voce opte trocar alguma versao do
# compilador ou flag para seu processo de compilacao
# Uma variavel com nome VAR eh declarada da seguinte maneira:
# 	VAR=conteudo
# e eh chamada atraves do comando $(VAR)

CC=g++ # compilador, troque para gcc se preferir utilizar C
CFLAGS=-Wall -Wextra # compiler flags, troque o que quiser, exceto bibliotecas externas
EXEC=./tp1 # nome do executavel que sera gerado, nao troque
TMPOUT=tp1.testresult


$(EXEC): src/main.cpp medicao.o lista.o
	$(CC) $(CFLAGS) src/main.cpp medicao.o lista.o -o $(EXEC)

medicao.o: src/medicao.cpp # esse eh um exemplo, nao utilize esse tipo de nome (rick.cc, rick.h, rick.o) para seus arquivos
	$(CC) $(CFLAGS) -c src/medicao.cpp -o medicao.o

lista.o: src/lista.cpp
	$(CC) $(CFLAGS) -c src/lista.cpp -o lista.o

test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf medicao.o lista.o

# === OUTROS =====
# ================
# 
# Para mais informacoes sobre o Makefile, procure os monitores ou consulte
# outras referencias disponiveis na internet como:
# https://opensource.com/article/18/8/what-how-makefile
