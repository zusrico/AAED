#include <iostream>
#include "pilapseudo.h"

using namespace std;

int main(){
    int n;
    bool capacidad;
    cout<<"Introduce el numero de cartas que tendra la baraja: ";
    cin>>n;
      Pila<int> baraja(n);

    capacidad = baraja.vacia();
    cout<<"La baraja de cartas esta vacia: "<<capacidad<<endl;
    for(int i = 0; i<n; i++){
        baraja.push(i+1);
    }

    capacidad = baraja.vacia();
    cout<<"La baraja de cartas esta vacia: "<<capacidad<<endl;

    cout<<"Elementos de la baraja: ";
    
    for(int t = 0; t<n; t++){
        cout<<baraja.tope();
        baraja.pop();
        cout<<" ";
    }

    cout<<endl;

    for(int j = 0; j<n; j++){
        baraja.pop();
    }

    capacidad = baraja.vacia();
    cout<<"La baraja de cartas esta vacia: "<<capacidad<<endl;



    return 0;
}

