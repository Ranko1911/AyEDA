rm int_programa
rm long_programa
rm nif_programa
# g++ -std=c++11 -c src/dispersion.cc -o obj/dispersion.o
# g++ -std=c++11  -c src/exploration.cc -o obj/exploration.o
# g++ -std=c++11  -c src/dispersionTable.cc -o obj/dispersionTable.o
# g++ -std=c++11  -c src/test_main.cc -o obj/test_main.o
# g++ obj/dispersion.o obj/exploration.o obj/dispersionTable.o obj/test_main.o -o programa
# g++ src/main.cc include/dispersion.h include/exploration.h include/hashtable.h include/sequence.h include/nif.h -o programa
# g++ src/main_mod.cc include/dispersion.h include/exploration.h include/hashtable.h include/sequence.h include/libro.h -o programa2
# g++ src/test_main.cc include/nif.h -o test
# g++ src/main.cc include/sorting.h -o programa
g++ src/main.cc include/sequence.h include/sorting.h -o int_programa
g++ src/main_long.cc include/sequence.h include/sorting.h -o long_programa
g++ src/main_nif.cc include/sequence.h include/sorting.h -o nif_programa