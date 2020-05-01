#ifndef PROTOS_H_INCLUDED
#define PROTOS_H_INCLUDED



void proto_plato()
{   system("cls");
int opcion;
bool continuar=true;
while (continuar)
{   menuplato();
cin>>opcion;
switch(opcion)
 {  case 1: nuevo_plato();break;
   // case 2: break;
    case 3: punto_3();break;
   // case 4: break;
    case 5: listar_todo();break;
   // case 6: break;
    case 0: continuar=false; break;
    default:{ cout<<"Opcion incorrecta! Intente nuevamente."; }break;


 }


}

}


#endif // PROTOS_H_INCLUDED
