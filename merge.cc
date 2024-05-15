#include <iostream>

void Mezcla(int sec[], int ini, int cen, int fin, int aux[]){
    int i = ini;
    int j = cen + 1;
    for (int k = ini; k <= fin; k++){
      std::cout << "i: " << i << " j: " << j << std::endl;
        if (i <= cen && (j > fin || sec[i] <= sec[j])){
            std::cout << "Cambio de i: " << i << " con sec[i]:" << sec[i] <<" por k: " << k  <<std::endl;
            aux[k] = sec[i];
            i++;
        } else {
            std::cout << "Cambio de j: " << j << " con sec[j]:" << sec[j] <<" por k: " << k  <<std::endl;
            aux[k] = sec[j];
            j++;
        }
    }
    for (int k = ini; k <= fin; k++){
        sec[k] = aux[k];
    }
    //imprimir el array con el que se trabaja
    for(int i = ini; i <= fin; i++){
        std::cout << sec[i] << " ";
    }
    std::cout << std::endl;
}


void Msort(int sec[], int ini, int fin, int aux[]){
    if(ini == fin){
      std::cout << "Valores iguales --> Es un valor unitario" << std::endl;
    }

        
    if (ini < fin){
        int cen = (ini + fin) / 2;
        std::cout << "ini: " << ini << " cen: " << cen << " fin: " << fin << std::endl;
        std::cout << "Llamada a Msort 1 con ini: " << ini << " cen: " << cen << std::endl;
        Msort(sec, ini, cen, aux);
        std::cout << "Llamada a Msort 2 con cen + 1: " << cen + 1 << " fin: " << fin << std::endl;
        Msort(sec, cen + 1, fin, aux);
        std::cout << "Llamada a Mezcla con ini: " << ini << " cen: " << cen << " fin: " << fin << std::endl;
        Mezcla(sec, ini, cen, fin, aux);
    }
}


void MergeSort(int sec[], int n){
    int aux[n];
    Msort(sec, 0, n - 1, aux);
}

int main (){

    int n = 10;
    int sec[] = {95, 16, 28, 34, 41, 77, 8, 90, 12, 25};
    //rellenar sec con valores aleatorios
    // for (int i = 0; i < n; i++)
    //     sec[i] = rand() % 100;

    MergeSort(sec, n);

    std::cout << "\nArray ordenado: " << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << sec[i] << " ";
    return 0;
}