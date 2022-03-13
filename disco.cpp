#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>
#include <bits/stdc++.h>
#include "disco.h"
#include "algoritmoType.h"

using namespace std;

#define limite 5
metadata m;
int size=8;
int disk_size=200;

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

        
        strcpy(m.name,nombre);
        m.pistas;
        m.tam_pista;
        archivo.write(reinterpret_cast<const char*>(&m),sizeof(metadata));
        cout<<"Disco creado con exito!!!";
        archivo.close();
    }

}

void disco::insertarfifo(char datos[], int tiempo[], int l){
    srand(time(NULL));
    for(int i = 0; i < (l); i++){
        cout << "inserte el tiempo en el proceso [" << datos[i] << "]: ";
        tiempo[i]=1+rand()%limite+1;
        cout<<tiempo[i]<<endl;
        sleep(1);
        
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
    sleep(1);
    cout<<"\nEl tiempo de las entradas son: "<<tiempoReturn;
}

void disco::fifo(){
    while(true){
    cout<<"\t\t\tSimulacion de FIFO"<<endl;
    cout<<"\t\t_______________________________________\n"<<endl;
    char datos[limite] = {'a','b','c','d','e'};
    int tiempo[limite];
    fifof(datos,tiempo,limite);
    sleep(2);
    }
}

void disco::calculatediference(int request[],int head, int diff[][2],int n){
    for (int i = 0; i < n; i++)
    {
        diff[i][0]=abs(head-request[i]);
    }
    
}

int disco::findMin(int diff[][2],int n){
    int index=-1;
    int minimo=1e9;

    for (int i = 0; i < n; i++)
    {
        if(!diff[i][1] && minimo > diff[i][0]){
            minimo=diff[i][0];
            index=i;
        }
    }
    return index;
    
}

void disco::shortestSeekTimeFirst(int request[],int head,int n){
    if(n==0){
        return;
    }

    int diff[n][2]={{0,0}};
    int seekcount=0;
    int seeksequence[n+1]={0};

    for (int i = 0; i < n; i++)
    {
        seeksequence[i]=head;
        calculatediference(request,head,diff,n);
        int index = findMin(diff,n);
        diff[index][1]=1;
        seekcount+=diff[index][0];
        head=request[index];
    }
    seeksequence[n]=head;

    cout<<"Total number of seek operations= "<<seekcount<<endl;
    cout<<"Seek sequence is: "<<"\n";

    for (int i = 0; i < n; i++)
    {
        cout<<seeksequence[i]<<"\n";
    }   
}

void disco::sstf(){
    while(true){
    srand(time(NULL));
    int proc[8];
    for (int i = 0; i < 8; i++)
    {
        proc[i]=1+rand()%limite+1;
        shortestSeekTimeFirst(proc,50,8);
    }
    sleep(3);
    }
    
}

void disco::cscan(int arr[],int head){
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;
 
    
    left.push_back(0);
    right.push_back(disk_size - 1);
 
    
    for (int i = 0; i < size; i++) {
        if (arr[i] < head)
            left.push_back(arr[i]);
        if (arr[i] > head)
            right.push_back(arr[i]);
    }
 
    
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
 
    
    for (int i = 0; i < right.size(); i++) {
        cur_track = right[i];
        
        seek_sequence.push_back(cur_track);
 
        
        distance = abs(cur_track - head);
 
        
        seek_count += distance;
 
        
        head = cur_track;
    }
 
    
    head = 0;
 
    
    seek_count += (disk_size - 1);
 
    
    for (int i = 0; i < left.size(); i++) {
        cur_track = left[i];
 
        
        seek_sequence.push_back(cur_track);
 
        
        distance = abs(cur_track - head);
 
        
        seek_count += distance;
 
        
        head = cur_track;
    }
 
    cout << "Total number of seek operations = "
         << seek_count << endl;
 
    cout << "Seek Sequence is" << endl;
 
    for (int i = 0; i < seek_sequence.size(); i++) {
        cout << seek_sequence[i] << endl;
    }

}

void disco::cscan(){
    while(true){
    int arr[size];
    int head;
     srand(time(NULL));

    for (int i = 0; i <= size; i++)
    {
        head=1+rand()%limite+1;
        arr[size]=1+rand()%+1;
    }
    
 
    cout << "Initial position of head: " << head << endl;
    cscan(arr, head);
    sleep(2);
    }
}

void disco::scan(int arr[], int head, string direction)
{
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;
 
    
    if (direction == "left")
        left.push_back(0);
    else if (direction == "right")
        right.push_back(disk_size - 1);
 
    for (int i = 0; i < size; i++) {
        if (arr[i] < head)
            left.push_back(arr[i]);
        if (arr[i] > head)
            right.push_back(arr[i]);
    }
 
   
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
 
   
    int run = 2;
    while (run--) {
        if (direction == "left") {
            for (int i = left.size() - 1; i >= 0; i--) {
                cur_track = left[i];
 
                
                seek_sequence.push_back(cur_track);
 
                
                distance = abs(cur_track - head);
 
               
                seek_count += distance;
 
               
                head = cur_track;
            }
            direction = "right";
        }
        else if (direction == "right") {
            for (int i = 0; i < right.size(); i++) {
                cur_track = right[i];
                
                seek_sequence.push_back(cur_track);
 
                
                distance = abs(cur_track - head);
 
                
                seek_count += distance;
 
                
                head = cur_track;
            }
            direction = "left";
        }
    }
 
    cout << "Total number of seek operations = "
         << seek_count << endl;
 
    cout << "Seek Sequence is" << endl;
 
    for (int i = 0; i < seek_sequence.size(); i++) {
        cout << seek_sequence[i] << endl;
    }
}

void disco::scan(){
    while(true){
    int arr[size];
    int head;
    string direction = "left";
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        arr[size]=1+rand()%limite+1;
        head=1+rand()%limite+1;
    }
    
    scan(arr, head, direction);
    sleep(2);
    }
}