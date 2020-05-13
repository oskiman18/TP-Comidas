#include <iostream>
#include <locale>
using namespace std ;
#include <ctime>
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
#include "funciones_clientes.h"
#include "protos.h"




int main(){
    setlocale(LC_CTYPE,"Spanish");
    setColor(YELLOW);
    setBackgroundColor(BLACK);
    int opcion;
    inicio();
    anykey();

    while (true)
    {
        menuprincipal();

    cin>>opcion;
    switch(opcion)
{


    case 1: proto_plato();break;
    case 2: proto_cliente();break;
    case 3:break;
    case 4:break;
    case 5:break;

    case 0: cls();cout<<"Gracias por utilizar nuestro sistema";return 0;
    default: cout<<"la opcion es incorrecta";anykey();


    }

}

return 0;
}
