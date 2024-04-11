rm nodo
rm abb
rm abe
rm input
g++ test/nodo.cc include/nodo.h -o nodo
g++ test/tree.cc include/ab.h include/nodo.h -o abb
g++ test/abe.cc include/ab.h include/abe.h -o abe
g++ test/input.cc -o input
