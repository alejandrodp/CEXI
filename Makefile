COMPILER = g++ -std=c++11 -Wall
TEMP = ./out/temp
BIN = ./out/bin

#Build all modules
all : ./src/launcher.cpp
	@$(COMPILER) ./src/launcher.cpp -o $(TEMP)/launcher.o
	@$(COMPILER) -o $(BIN)/launcher $(TEMP)/launcher.o