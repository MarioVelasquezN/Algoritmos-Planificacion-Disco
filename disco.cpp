#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "disco.h"
#include "algoritmoType.h"

using namespace std;
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
    }


}

