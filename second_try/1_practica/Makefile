# Makefile

CXX = g++
CXXFLAGS = -std=c++11
SRC_DIR = src

all: programa

programa: $(SRC_DIR)/Cell.o $(SRC_DIR)/Lattice.o $(SRC_DIR)/main.o
	$(CXX) $(CXXFLAGS) -o programa $(SRC_DIR)/Cell.o $(SRC_DIR)/Lattice.o $(SRC_DIR)/main.o -pthread

$(SRC_DIR)/Cell.o: $(SRC_DIR)/Cell.cc $(SRC_DIR)/Cell.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Cell.cc -o $(SRC_DIR)/Cell.o

$(SRC_DIR)/Lattice.o: $(SRC_DIR)/Lattice.cc $(SRC_DIR)/Lattice.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Lattice.cc -o $(SRC_DIR)/Lattice.o

$(SRC_DIR)/main.o: $(SRC_DIR)/main.cc
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/main.cc -o $(SRC_DIR)/main.o

clean:
	rm -f $(SRC_DIR)/*.o programa