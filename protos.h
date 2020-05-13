#ifndef PROTOS_H_INCLUDED
#define PROTOS_H_INCLUDED



void proto_plato()
{ int opcion;
bool continuar=true;
while (continuar)
{   menuplato();
cin>>opcion;
switch(opcion)
 {  case 1: punto_1();break;
    case 2: punto_2();break;
    case 3: punto_3();break;
    case 4: punto_4();break;
    case 5: punto_5();break;
    case 6: punto_6();break;
    case 0: continuar=false; break;
    default:{ cout<<"Opcion incorrecta! Intente nuevamente.";anykey(); }break;


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
cin>>opcion;
switch(opcion)
 {  case 1: cliente_1();break;
    case 2: cliente_2();break;
    case 3: cliente_3();break;
    case 4: cliente_4();break;
    case 5: ;break;

    case 0: continuar=false; break;
    default:{ cout<<"Opcion incorrecta! Intente nuevamente.";anykey(); }break;


 }
}}


#endif // PROTOS_H_INCLUDED
