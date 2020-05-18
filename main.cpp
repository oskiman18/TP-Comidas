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
const char *BKP_PLATOS="backup/platos.bkp";
const char *BKP_CLIENTES="backup/clientes.bkp";
const char *BKP_PEDIDOS="backup/pedidos.bkp";


#include "funciones.h"
#include "funciones_clientes.h"
#include "f_pedidos.h"
#include "configuracion.h"
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
    case 3: proto_pedido();break;
    case 4: copiar_plato();break;
    case 5: proto_configuracion();break;
    case 6: ordenar_archivo();break;
    case 0: cls();cout<<"Gracias por utilizar nuestro sistema"<<endl;return 0;
    default: cout<<"La opción es incorrecta";anykey();


    }

}
cout<<endl;
return 0;
}
