#include <iostream>
#include <stdlib.h> //new y delete
#include <ctime>
#include <algorithm>

#include "cronometro.h"
#include "orden.h"

using namespace std;

void formaVector(int *, int);
void copiaVector(int *, int *, int);
void imprimeVector(int *, int);
void menu(int *, int *, int, int);


int main(){

    int *vector; //puntero 
    int *vectorCopia;
    int n, op;
    cronometro c;

    srand(time(nullptr));

    cout<<"Introduce numero de elementos del vector:";
    cin>>n;

    vector = new int[n]; //primera posicion apunta a vector con n elementos
    vectorCopia = new int[n];
    formaVector(vector, n);
    copiaVector(vector, vectorCopia, n);

    cout<<"Introduce 1 para intercambio directo, 2 para seleccion directa y 3 para insercion: ";
    cin>>op;

    cout<<"El vector con el que vamos a trabajar es: "; 
    formaVector(vector, n);
    imprimeVector(vector, n);
    menu(vector, vectorCopia, n, op);
    cout<<"El vector ordenado resultante es: ";
    imprimeVector(vector, n);
    
    return 0;
}

void copiaVector(int vector[], int vectorCopia[], int n){
    for(int i = 0; i<n; i++)
        vectorCopia[i] = vector[i];
}


void formaVector(int vector[], int n){
    for(int i = 0; i<n; i++)
        vector[i] = i + 1;

    random_shuffle(vector, vector+n); 
}

void imprimeVector(int vector[], int n){
    for(int j = 0; j<n; j++)
        cout<<vector[j];

    cout<<endl;
}

void menu(int vector[], int vectorCopia[], int n, int op){
    cronometro c;
    double tempo;
    
    //necesitamos otro vector para ordenarlo

      switch(op){
        case 1:
            c.activar();
            do{
                copiaVector(vectorCopia, vector, n);
                intercambioDirectivo(vector, n); //ordenar la permuta obtenida
            }while(next_permutation(vectorCopia, vectorCopia + n)); //permutar vector
            c.parar();
            tempo = c.tiempo();
            cout<<"Ha tardado: "<<tempo<<" segundos"<<endl;
            break;
        case 2:
            seleccion(vector, n);
            break;
        case 3:
            insercion(vector, n);
        default: break;
    }

}
