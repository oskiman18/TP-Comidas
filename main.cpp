#include <iostream>
using namespace std ;
#include <cstdio>
#include "rlutil.h"
using namespace rlutil;
#include <cstdlib>

#include <cstring>
const char *PLATOS="datos/platos.dat";
const char *CLIENTES="datos/clientes.dat";
const char *PEDIDOS="datos/pedidos.dat";
const char *REPORTES="datos/reportes.dat";
const char *RESTAURANTES="datos/restos.dat";

#include "funciones.h"


#include "protos.h"




int main(){
    setColor(WHITE);
    setBackgroundColor(BLACK);
    int opcion;
    while (true)
    {
        menuprincipal();

    cin>>opcion;
    switch(opcion)
{


    case 1: proto_plato();break;
    case 2:break;
    case 3:break;
    case 4:break;
    case 5:break;

    case 0: system("cls");cout<<"Gracias por utilizar nuestro sistema";return 0;        default: cout<<"la opcion es incorrecta";


    }

}

return 0;
}
