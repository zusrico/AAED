#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stdlib.h> //new y delete
#include "cronometro.h"
#include "orden.h"
#define TAM_MAX 20000

using namespace std;

int main(){
    cronometro c;
    int *vector, j;
    float tempo;

    for(int j = 1000; j < TAM_MAX; j = j + 1000){
        vector = new int[j];
        for(int i = 0; i<j; i++)
            vector[i] = i+1;
        random_shuffle(vector, vector+j); 

        c.activar();
        intercambioDirectivo(vector, j); //aplicar aqui cualquier metodo de ordenacion
        c.parar();

        tempo = c.tiempo();
        cout<<"Usando medida directa y metodo de ordenacion directo, se ha tardado: "<<tempo<<endl;
    }

    return 0;
}

