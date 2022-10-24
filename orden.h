#include <iostream>
#include <stdlib.h> //new y delete
#include <ctime>
#include <algorithm>

using namespace std;

void intercambioDirectivo(int *, int );
void seleccion(int *, int);
void insercion(int *, int);

void intercambioDirectivo(int vector[], int n){
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(vector[j]>vector[j+1])
                swap(vector[j], vector[j+1]);
        }
       
    }
}

void seleccion(int vector[], int n){
    int posicion;
    for(int i = 0; i < n-1; i++){
        int *pos = min_element(vector+i, vector+n); //puntero al elemento mas pequeño del vector, por tanto almacena la dirección del vector con el elemento mas pequeño
        posicion = distance(vector, pos); //distancia entre primer elemento y el mas pequeño, providing us el iterador
        swap(vector[i], vector[posicion]);
    }
}

void insercion(int vector[], int n){
    int aux, posicion;
    for(int i = 0; i<n; i++){
        posicion = i;
        aux = vector[i];
        while((posicion > 0) && (vector[posicion-1]>aux)){
            vector[posicion] = vector[posicion-1];
            posicion--;
        }
        vector[posicion] = aux;
    }
}
