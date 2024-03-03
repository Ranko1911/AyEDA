# Makefile

CXX = g++
CXXFLAGS = -std=c++11
SRC_DIR = src

all: programa

programa: $(SRC_DIR)/cell/Cell.o $(SRC_DIR)/Lattice/Lattice.o $(SRC_DIR)/main.o $(SRC_DIR)/FactoryCell/FactoryCell.o $(SRC_DIR)/Position/Position.o $(SRC_DIR)/cell/CellACE.o $(SRC_DIR)/cell/CellLife.o $(SRC_DIR)/Lattice/Lattice1D.o $(SRC_DIR)/Lattice/Lattice2D.o
	$(CXX) $(CXXFLAGS) -o programa $(SRC_DIR)/cell/Cell.o $(SRC_DIR)/Lattice/Lattice.o $(SRC_DIR)/main.o $(SRC_DIR)/FactoryCell/FactoryCell.o $(SRC_DIR)/Position/Position.o $(SRC_DIR)/cell/CellACE.o $(SRC_DIR)/cell/CellLife.o $(SRC_DIR)/Lattice/Lattice1D.o $(SRC_DIR)/Lattice/Lattice2D.o

$(SRC_DIR)/cell/Cell.o: $(SRC_DIR)/cell/Cell.cc $(SRC_DIR)/cell/Cell.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/cell/Cell.cc -o $(SRC_DIR)/cell/Cell.o

$(SRC_DIR)/cell/CellACE.o: $(SRC_DIR)/cell/CellACE.cc $(SRC_DIR)/cell/CellACE.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/cell/CellACE.cc -o $(SRC_DIR)/cell/CellACE.o

$(SRC_DIR)/cell/CellLife.o: $(SRC_DIR)/cell/CellLife.cc $(SRC_DIR)/cell/CellLife.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/cell/CellLife.cc -o $(SRC_DIR)/cell/CellLife.o

$(SRC_DIR)/Lattice/Lattice.o: $(SRC_DIR)/Lattice/Lattice.cc $(SRC_DIR)/Lattice/Lattice.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Lattice/Lattice.cc -o $(SRC_DIR)/Lattice/Lattice.o

$(SRC_DIR)/Lattice/Lattice1D.o: $(SRC_DIR)/Lattice/Lattice1D.cc $(SRC_DIR)/Lattice/Lattice1D.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Lattice/Lattice1D.cc -o $(SRC_DIR)/Lattice/Lattice1D.o

$(SRC_DIR)/Lattice/Lattice2D.o: $(SRC_DIR)/Lattice/Lattice2D.cc $(SRC_DIR)/Lattice/Lattice2D.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Lattice/Lattice2D.cc -o $(SRC_DIR)/Lattice/Lattice2D.o

$(SRC_DIR)/FactoryCell/FactoryCell.o: $(SRC_DIR)/FactoryCell/FactoryCell.cc $(SRC_DIR)/FactoryCell/FactoryCell.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/FactoryCell/FactoryCell.cc -o $(SRC_DIR)/FactoryCell/FactoryCell.o

$(SRC_DIR)/Position/Position.o: $(SRC_DIR)/Position/Position.cc $(SRC_DIR)/Position/Position.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Position/Position.cc -o $(SRC_DIR)/Position/Position.o

$(SRC_DIR)/main.o: $(SRC_DIR)/main.cc
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/main.cc -o $(SRC_DIR)/main.o

clean:
	rm -f $(SRC_DIR)/*/*.o $(SRC_DIR)/*.o programa