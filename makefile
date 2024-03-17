CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11
INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

all: programa

programa: $(OBJ_DIR)/main.o $(OBJ_DIR)/dispersion.o $(OBJ_DIR)/exploracion.o
	$(CXX) $(CXXFLAGS) -o programa $(OBJ_DIR)/main.o $(OBJ_DIR)/dispresion.o $(OBJ_DIR)/exploracion.o

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cc $(INC_DIR)/dispersion.h $(INC_DIR)/exploracion.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/main.cc $(INC_DIR)/dispersion.h $(INC_DIR)/exploracion.h  -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/dispersion.o: $(INC_DIR)/dispersion.h
	$(CXX) $(CXXFLAGS) -c $(INC_DIR)/dispersion.h -o $(OBJ_DIR)/dispersion.o

$(OBJ_DIR)/exploracion.o:  $(INC_DIR)/exploracion.h
	$(CXX) $(CXXFLAGS) -c $(INC_DIR)/exploracion.h -o $(OBJ_DIR)/exploracion.o

clean:
	rm -f $(OBJ_DIR)/*.o programa
