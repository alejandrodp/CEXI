CXX = g++ -std=c++11 -Wall
SRC = ./src/
TEMP = ./out/temp/
BIN = ./out/bin/
INCLUDES = -I$(SRC)cexi/compiler/compiler -I$(SRC)cexi/interpreter/interpreter

build_all: compiler.o launcher.o
	@$(CXX) $(TEMP)launcher.o $(TEMP)compiler.o -o $(BIN)launcher
	@echo "Done"

launcher.o: $(SRC)launcher.cpp
	@$(CXX) -c $(INCLUDES) ./src/launcher.cpp -o $(TEMP)launcher.o
	@echo "Launcher class compiled!!"

build_and_run_all: build_all
	@$(BIN)launcher
	@echo ""

compiler.o: $(SRC)cexi/compiler/compiler.cpp $(SRC)cexi/compiler/compiler.h
	@$(CXX) -c $(SRC)cexi/compiler/compiler.cpp -o $(TEMP)compiler.o
	@echo "Compiler class compiled!!"

.PHONY: clean
clean:
	@rm ./out/temp/*.*
	@echo "Temp files deleted!!"

