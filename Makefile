# Makefile

CXX = g++
CXXFLAGS = -std=c++11
SRC_DIR = src

all: programa

programa: $(SRC_DIR)/cell/Cell.o $(SRC_DIR)/Lattice/Lattice.o $(SRC_DIR)/main.o $(SRC_DIR)/FactoryCell/FactoryCell.o $(SRC_DIR)/Position/Position.o
	$(CXX) $(CXXFLAGS) -o programa $(SRC_DIR)/cell/Cell.o $(SRC_DIR)/Lattice/Lattice.o $(SRC_DIR)/main.o -pthread

$(SRC_DIR)/cell/Cell.o: $(SRC_DIR)/cell/Cell.cc $(SRC_DIR)/cell/Cell.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/cell/Cell.cc -o $(SRC_DIR)/cell/Cell.o

$(SRC_DIR)/Lattice/Lattice.o: $(SRC_DIR)/Lattice/Lattice.cc $(SRC_DIR)/Lattice/Lattice.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Lattice/Lattice.cc -o $(SRC_DIR)/Lattice/Lattice.o

$(SRC_DIR)/FactoryCell/FactoryCell.o: $(SRC_DIR)/FactoryCell/FactoryCell.cc $(SRC_DIR)/FactoryCell/FactoryCell.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/FactoryCell/FactoryCell.cc -o $(SRC_DIR)/FactoryCell/FactoryCell.o

$(SRC_DIR)/Position/Position.o: $(SRC_DIR)/Position/Position.cc $(SRC_DIR)/Position/Position.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Position/Position.cc -o $(SRC_DIR)/Position/Position.o

$(SRC_DIR)/main.o: $(SRC_DIR)/main.cc
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/main.cc -o $(SRC_DIR)/main.o

clean:
	# rm -f $(SRC_DIR)/*.o programa
	# rm -f $(SRC_DIR)/cell/*.o $(SRC_DIR)/Lattice/*.o $(SRC_DIR)/*.o programa $(SRC_DIR)/FactoryCell/*.o $(SRC_DIR)/Position/*.o
	rm -f $(SRC_DIR)/*/*.o $(SRC_DIR)/*.o programa