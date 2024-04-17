rm nodo
rm abb
rm abe
rm input
rm nif_abe
rm nif_abb
g++ test/nodo.cc include/nodo.h -o nodo
g++ test/abb.cc include/ab.h include/nodo.h -o abb
g++ test/abe.cc include/ab.h include/abe.h -o abe
g++ test/input.cc -o input
g++ test/nif_abe.cc include/ab.h include/abe.h include/nif.h include/nodo.h -o nif_abe
g++ test/nif_abb.cc include/ab.h include/abe.h include/nif.h include/nodo.h -o nif_abb
g++ src/main.cc include/ab.h include/abe.h include/abb.h include/nif.h include/nodo.h -o main