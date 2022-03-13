#include <iostream>
#include <unistd.h>
#include "disco.h"

int main () 
{
    int op=0;
    disco d;
    metadata m;
    char name[30]="Disco";

    do{

        cout<<"MENU\n";
        cout<<"1.Crear Disco"<<endl;
        cout<<"2.Algoritmo FIFO"<<endl;
        cout<<"3.Algoritmo SSTF"<<endl;
        cout<<"4.Algoritmo SCAN"<<endl;
        cout<<"5.Algoritmo C-SCAN"<<endl;
        cout<<"6.SALIR"<<endl;
        cout<<"Seleccione su respuesta: ";
        cin>>op;
        cout<<endl;

        if(op==1){
            d.createDisk(name);     
        }else if(op==2){
            d.fifo();
        }else if(op==3){
           d.sstf(); 
        }else if(op==4){
            d.scan();
        }else if(op==5){
            d.cscan();
        }else{
            cout<<"Saliendo con exito!!!"<<endl;
            sleep(1);
        }

    }while(op!=5);
    
}