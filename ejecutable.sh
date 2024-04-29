# rm ejecutables/nodo
# rm ejecutables/abb
# rm ejecutables/abe
# rm ejecutables/input
# rm ejecutables/nif_abe
# rm ejecutables/nif_abb
rm int_main
rm nif_main
# g++ test/nodo.cc include/nodo.h -o ejecutables/nodo
# g++ test/abb.cc include/ab.h include/nodo.h -o ejecutables/abb
# g++ test/abe.cc include/ab.h include/abe.h -o ejecutables/abe
# g++ test/input.cc -o ejecutables/input
# g++ test/nif_abe.cc include/ab.h include/abe.h include/nif.h include/nodo.h -o ejecutables/nif_abe
# g++ test/nif_abb.cc include/ab.h include/abe.h include/nif.h include/nodo.h -o ejecutables/nif_abb
g++ src/int_main.cc include/ab.h include/abe.h include/abb.h include/avl.h include/nif.h include/nodo.h -o int_main
g++ src/nif_main.cc include/ab.h include/abe.h include/abb.h include/avl.h include/nif.h include/nodo.h -o nif_main
