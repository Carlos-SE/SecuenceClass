HOME=.
SRC=$(HOME)/src
OBJ=$(HOME)/obj
LIB=$(HOME)/lib
BIN=$(HOME)/bin
INCLUDE=$(HOME)/include
###############################################################################

all : intro $(BIN)/main clean final

$(BIN)/main : $(OBJ)/main.o $(OBJ)/Secuencia.o
	g++ -o $(BIN)/main $(OBJ)/main.o $(OBJ)/Secuencia.o
$(OBJ)/main.o : $(SRC)/main.cpp
	g++ -c -o $(OBJ)/main.o $(SRC)/main.cpp -I$(INCLUDE)
$(OBJ)/Secuencia.o : $(SRC)/Secuencia.cpp
	g++ -c -o $(OBJ)/Secuencia.o $(SRC)/Secuencia.cpp -I$(INCLUDE)


###############################################################################
intro :
	@echo 
	@echo " _____                                    "
	@echo "/  ___|                                    "
	@echo "\\  --.  ___  ___ _   _  ___ _ __   ___ ___ "
	@echo "  --. \\/ _ \\/ __| | | |/ _ \\ '_ \\ / __/ _ \\"
	@echo "/\\__/ /  __/ (__| |_| |  __/ | | | (_|  __/"
	@echo "\\____/ \\___|\\___|\\__,_|\\___|_| |_|\\___\\___|"

clean :
	-rm $(OBJ)/*

mr.proper : clean
	-rm $(BIN)/*

final :
	@echo
	@echo Terminado
	@echo