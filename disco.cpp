#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "disco.h"
#include "algoritmoType.h"

using namespace std;

#define limite 5
metadata m;

void disco::createDisk(char name[30]){
    ofstream archivo(name, ios::in | ios::app| ios::binary);

    if(!archivo){
        cout<<"error al abrir el archivo"<<endl;
    }else{
        cout<<"Ingrese Nombre del Disco: \n";
        char nombre[30];
        cin>>nombre;

        cout<<"Seleccione cantidad de pistas";
        cin>>m.pistas;

        
        strcpy_s(m.name,nombre);
        m.pistas;
        m.tam_pista;
        archivo.write(reinterpret_cast<const char*>(&m),sizeof(metadata));
        cout<<"Disco creado con exito!!!";
        archivo.close();
    }

}

void disco::insertarfifo(char datos[], int tiempo[], int l){
    for(int i = 0; i < (l); i++){
        cout << "inserte el tiempo en el proceso [" << datos[i] << "]: ";
        cin >> tiempo[i];
        system("cls");
    }
}

void disco::fifof(char datos[],int tiempo[], int l){
    int tiempoTotal = 0;
    float tiempoReturn = 0.0f;
    insertarfifo(datos,tiempo, l);
    for(int j = 0;j < l; j++){
        tiempoTotal += tiempo[j];
        tiempoReturn += tiempoTotal;
        cout <<"\n""tiempo de retorno de["<<datos[j]<<"]: "<<tiempoTotal<<"\t";
    }
    tiempoReturn = tiempoReturn / l;
    cout<<"\nEl tiempo de las entradas son: "<<tiempoReturn;
}

void disco::fifo(){
    cout<<"\t\t\tSimulacion de FIFO en C++"<<endl;
    cout<<"\t\t_______________________________________\n"<<endl;
    char datos[limite] = {'a','b','c','d','e'};
    int tiempo[limite];
    fifof(datos,tiempo,limite);
    cin.get();
    cin.get();
}

