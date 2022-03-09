#ifndef DISCO_H
#define DISCO_H

#include "algoritmoType.h"
#include <fstream>
#include <string>
using namespace std;

const int N = 10;
//simular los algoritmos

struct metadata
{
	char name[30];
	int tam_pista=524288;
    int pistas;
    //int cola_orden_llegada;
    //int cola_planeacion;
};

struct fifo{
	int entrada=0;
	int salida=0;
	int n =0;
	int datos[N];

	int cola_orden_llegada;
    int cola_planeacion;
};

struct sstf{
	int entrada=0;
	int salida=0;
	int n =0;
	int datos[N];

	int cola_orden_llegada;
    int cola_planeacion;
};

struct scan{

};

class disco{
	public:
	void createDisk(char name[30]);
	void fifo();
	void insertarfifo(char datos[],int tiempo[],int l);
	void fifof(char datos[],int tiempo[],int l);

	void sstf();
	void scan();
	void scan2();
};

#endif // !DISCO_H