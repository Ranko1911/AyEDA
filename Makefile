# Makefile

CXX = g++
CXXFLAGS = -std=c++11
SRC_DIR = src
INC_DIR = include

all: programa

programa:   $(SRC_DIR)/Position.o $(SRC_DIR)/Cell.o  $(SRC_DIR)/FactoryCell.o $(SRC_DIR)/CellACE.o $(SRC_DIR)/CellLife.o $(SRC_DIR)/Lattice.o $(SRC_DIR)/Lattice1D.o $(SRC_DIR)/Lattice2D.o $(SRC_DIR)/main.o
	$(CXX) $(CXXFLAGS) -o programa $(SRC_DIR)/Cell.o $(SRC_DIR)/Lattice.o $(SRC_DIR)/main.o $(SRC_DIR)/FactoryCell.o $(SRC_DIR)/Position.o $(SRC_DIR)/CellACE.o $(SRC_DIR)/CellLife.o $(SRC_DIR)/Lattice1D.o $(SRC_DIR)/Lattice2D.o

$(SRC_DIR)/Cell.o: $(SRC_DIR)/Cell.cc $(INC_DIR)/Cell.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Cell.cc -o $(SRC_DIR)/Cell.o

$(SRC_DIR)/CellACE.o: $(SRC_DIR)/CellACE.cc $(INC_DIR)/CellACE.h $(SRC_DIR)/Cell.o
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/CellACE.cc -o $(SRC_DIR)/CellACE.o

$(SRC_DIR)/CellLife.o: $(SRC_DIR)/CellLife.cc $(INC_DIR)/CellLife.h $(SRC_DIR)/Cell.o
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/CellLife.cc -o $(SRC_DIR)/CellLife.o

$(SRC_DIR)/Lattice.o: $(SRC_DIR)/Lattice.cc $(INC_DIR)/Lattice.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Lattice.cc -o $(SRC_DIR)/Lattice.o

$(SRC_DIR)/Lattice1D.o: $(SRC_DIR)/Lattice1D.cc $(INC_DIR)/Lattice1D.h  $(SRC_DIR)/Lattice.o
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Lattice1D.cc -o $(SRC_DIR)/Lattice1D.o

$(SRC_DIR)/Lattice2D.o: $(SRC_DIR)/Lattice2D.cc $(INC_DIR)/Lattice2D.h  $(SRC_DIR)/Lattice.o
	$(CXX) $(CXXFLAGS) -c  $(SRC_DIR)/Lattice2D.cc -o $(SRC_DIR)/Lattice2D.o

$(SRC_DIR)/FactoryCell.o: $(SRC_DIR)/FactoryCell.cc $(INC_DIR)/FactoryCell.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/FactoryCell.cc -o $(SRC_DIR)/FactoryCell.o

$(SRC_DIR)Position.o: $(SRC_DIR)/Position.cc $(INC_DIR)/Position.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Position.cc -o $(SRC_DIR)/Position.o

$(SRC_DIR)/main.o: $(SRC_DIR)/main.cc
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/main.cc -o $(SRC_DIR)/main.o

clean:
	rm -f $(SRC_DIR)/*.o $(INC_DIR)/*.o programa