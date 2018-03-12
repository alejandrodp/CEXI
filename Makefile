CXX = g++ -std=c++11 -Wall
SRC = ./src/
TEMP = ./out/temp/
BIN = ./out/bin/

all: launcher clean

launcher: $(SRC)launcher.cpp
	$(CXX) -c ./src/launcher.cpp -o $(TEMP)launcher.o
	$(CXX) $(TEMP)launcher.o -o $(BIN)launcher

	
.PHONY: clean
clean:
	@rm ./out/temp/*.*
	@echo "Temp files deleted!!"
