CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11
INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

all: programa

programa: $(OBJ_DIR)/test_main.o $(OBJ_DIR)/dispersion.o $(OBJ_DIR)/exploracion.o
	$(CXX) $(CXXFLAGS) -o programa $(OBJ_DIR)/test_main.o $(OBJ_DIR)/dispresion.o $(OBJ_DIR)/exploracion.o

$(OBJ_DIR)/test_main.o: $(SRC_DIR)/test_main.cc $(INC_DIR)/dispersion.h $(INC_DIR)/exploracion.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/test_main.cc -o $(OBJ_DIR)/test_main.o

$(OBJ_DIR)/dispersion.o: $(SRC_DIR)/dispersion.cc $(INC_DIR)/dispersion.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/dispersion.cc -o $(OBJ_DIR)/dispersion.o

$(OBJ_DIR)/exploracion.o: $(SRC_DIR)/exploracion.cc $(INC_DIR)/exploracion.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/exploracion.cc -o $(OBJ_DIR)/exploracion.o

clean:
	rm -f $(OBJ_DIR)/*.o programa
