HOME=.
SRC=$(HOME)/src
OBJ=$(HOME)/obj
LIB=$(HOME)/lib
BIN=$(HOME)/bin
INCLUDE=$(HOME)/include
###############################################################################

all : $(BIN)/main clean final

$(BIN)/main : $(OBJ)/main.o $(OBJ)/Secuencia.o
	g++ -o $(BIN)/main $(OBJ)/main.o $(OBJ)/Secuencia.o
$(OBJ)/main.o : $(SRC)/main.cpp
	g++ -c -o $(OBJ)/main.o $(SRC)/main.cpp -I$(INCLUDE)
$(OBJ)/Secuencia.o : $(SRC)/Secuencia.cpp
	g++ -c -o $(OBJ)/Secuencia.o $(SRC)/Secuencia.cpp -I$(INCLUDE)


###############################################################################
clean :
	-rm $(OBJ)/*

mr.proper : clean
	-rm $(BIN)/*

final :
	@echo
	@echo Terminado
	@echo