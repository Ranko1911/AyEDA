g++ -std=c++11 -c src/dispersion.cc -o obj/dispersion.o
g++ -std=c++11  -c src/exploration.cc -o obj/exploration.o
g++ -std=c++11  -c src/dispersionTable.cc -o obj/dispersionTable.o
g++ -std=c++11  -c src/test_main.cc -o obj/test_main.o
g++ obj/dispersion.o obj/exploration.o obj/dispersionTable.o obj/test_main.o -o programa
