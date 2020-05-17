#ifndef PROTOS_H_INCLUDED
#define PROTOS_H_INCLUDED



void proto_plato()
{ int opcion;
bool continuar=true;
while (continuar)
{   menuplato();
cin.ignore();
cin>>opcion;
switch(opcion)
 {  case 1: punto_1();break;
    case 2: punto_2();break;
    case 3: punto_3();break;
    case 4: punto_4();break;
    case 5: punto_5();break;
    case 6: punto_6();break;
    case 0: continuar=false; break;
    default:{ cout<<"Opción incorrecta! Intente nuevamente.";anykey(); }break;


 }


}

}



void proto_cliente()
{

int opcion;
bool continuar=true;
while (continuar)

{

menu_clientes();
cin.ignore();
cin>>opcion;
switch(opcion)
 {  case 1: cliente_1();break;
    case 2: cliente_2();break;
    case 3: cliente_3();break;
    case 4: cliente_4();break;
    case 5: cliente_5();break;

    case 0: continuar=false; break;
    default:{ cout<<"Opcion incorrecta! Intente nuevamente.";anykey(); }break;


 }
}}


void proto_pedido()
{   int opcion;
    bool continuar=true;
    while (continuar)

{    menupedido();
    cin.ignore();
    cin>>opcion;
    switch(opcion)
 {  case 1: pedido_1();break;
    case 2: pedido_2();break;
    case 3: pedido_3();break;
    case 4: pedido_4();break;

    case 0: continuar=false; break;
    default:{ cout<<"Opcion incorrecta! Intente nuevamente.";anykey(); }break;


 }
}}


void proto_configuracion()
{   int opcion;
    bool continuar=true;
    while (continuar)

{   menu_confi();
    cin.ignore();
    cin>>opcion;
    switch(opcion)
 {  case 1: realizar();break;
    case 2: restaurar();break;
    case 0: continuar=false; break;
    default:{ cout<<"Opcion incorrecta! Intente nuevamente.";anykey(); }break;


 }
}}


#endif // PROTOS_H_INCLUDED
