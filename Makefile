CXX = g++ -std=c++11 -Wall
SRC = ./src/
TEMP = ./out/temp/
BIN = ./out/bin/
INCLUDES =  -I$(SRC)cexi/interpreter/interpreter

all: interpreter.o launcher.o calculator.o
	@$(CXX) $(TEMP)launcher.o $(TEMP)interpreter.o -o $(BIN)executable
	@echo ""
	@$(BIN)executable

interpreter.o: $(SRC)cexi/interpreter/interpreter.cpp $(SRC)cexi/interpreter/interpreter.h
	@$(CXX) -c $(INCLUDES) $(SRC)cexi/interpreter/interpreter.cpp -o $(TEMP)interpreter.o
	@echo "Interpeter compiled!!"	

calculator.o: $(SRC)cexi/interpreter/calculator.cpp $(SRC)cexi/interpreter/calculator.h
	@$(CXX) -c $(INCLUDES) $(SRC)cexi/interpreter/calculator.cpp -o $(TEMP)calculator.o 
	@echo "Calculator compiled!!"

launcher.o: $(SRC)launcher.cpp
	@$(CXX) -c $(INCLUDES) ./src/launcher.cpp -o $(TEMP)launcher.o
	@echo "Launcher compiled!!"

.PHONY: clean
clean:
	@rm ./out/temp/*.*
	@echo "Temp files deleted!"
	@echo ""

