#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



struct plato;
void menuprincipal();
void menuplato();
bool cargar_plato(plato);
bool guardar_plato(plato);
void nuevo_plato();
void listar(plato) ;
void listar_todo();
void listar_idplato(int);
int buscar_posicion (int);
void punto_1();
void punto_2();
void punto_3();
void punto_4();
void punto_5();
void punto_6();
plato leer_plato (int);
bool guardar_cambio(plato, int);
bool modificar_plato (plato*);
bool  confirmar(plato);
bool baja_logica(plato*);
bool listar_resto(int);


//Estructura
struct plato
{int idplato, tiempo, idresto, comision, idcate;
float costo, venta;
bool estado;
char nombre[50];
};


//Muestra el Menu Principal
void menuprincipal(){

    cls();
cout<<"MENÚ PRINCIPAL"<<endl;
cout<<"--------------"<<endl;
cout<<"1) PLATOS"<<endl;
cout<<"2) CLIENTES"<<endl;
cout<<"3) PEDIDOS"<<endl;
cout<<"4) REPORTES"<<endl;
cout<<"5) CONFIGURACIÓN"<<endl;
cout<<"----------------------"<<endl;
cout<<"0) SALIR DEL PROGRAMA"<<endl;
cout<<endl;
 cout<<"Elija la opcion para continuar: ";
};

//Muestra menu para los platos
void menuplato()
{
  cls();
cout<<"    MENÚ PLATOS"<<endl;
cout<<"------------------"<<endl;
cout<<"1) NUEVO PLATO"<<endl;
cout<<"2) MODIFICAR PLATO"<<endl;
cout<<"3) LISTAR PLATO POR ID"<<endl;
cout<<"4) PLATOS POR RESTAURANT"<<endl;
cout<<"5) LISTAR TODOS LOS PLATOS"<<endl;
cout<<"6) ELIMINAR PLATO"<<endl;
cout<<"--------------------------------"<<endl;
cout<<"0) VOLVER AL MENÚ PRINCIPAL"<<endl;
cout<<endl;
cout<<"Pulse la opción de plato deseada: ";
}

//busca de ID en archivo
int buscar_posicion(int id)
{   plato aux;
    int pos=0;
    FILE *p;
    p=fopen(PLATOS,"rb");
    if (p==NULL) return -1;
    while (fread(&aux,sizeof(plato),1,p))
    {   if (id==aux.idplato) return pos;

         pos++;
    }

    fclose(p);
    return -1;
    }


//Carga manual de platos
bool cargar_plato(plato *p)
{   cls();
int pos;
cout<<"Por favor ingrese los datos del plato nuevo: "<<endl;
    cout<<"ID del plato: ";
    cin>>p->idplato;
    pos=(buscar_posicion(p->idplato));
    if((pos>=0)||(p->idplato<1)) return false;

    cout<<"Nombre: ";
    cin.ignore();
    cin.getline(p->nombre,50);
    if(strlen(p->nombre)==0) return false;

    cout<<"Costo de preparación: ";
    cin>>p->costo;
    if (p->costo<0) return false;

    cout<<"Valor de venta: ";
    cin>>p->venta;
    if (p->costo >= p->venta) return false;

    cout<<"Tiempo de preparación en minutos: ";
    cin>>p->tiempo;
    if(p->tiempo<=0) return false;

    cout<<"ID del restaurante: ";
    cin>>p->idresto;
    if(p->idresto<=0) return false;

    cout<<"Comisión del restaurante: ";
    cin>>p->comision;
    if((p->comision>=100)|| (p->comision<=0)) return false;

    cout<<"Categoría del plato: ";
    cin>>p->idcate;
    if(p->idcate<=0) return false;

    p->estado=true;
     return true;
}

//Grabado en archivo del plato
bool guardar_plato(plato aux)
{   bool guardo=true;
    FILE *p;
    p=fopen(PLATOS,"ab");
    if (p==NULL)
   return false;

    fwrite(&aux,sizeof(aux),1,p);


    fclose(p);

return guardo;
}

//Grabado de modificacion en archivo
bool guardar_cambio(plato aux,int pos)
{   bool guardo=true;
    FILE *p;
    p=fopen(PLATOS,"rb+");
    if (p==NULL) return false;
    fseek(p,pos*sizeof(plato),SEEK_SET);
    fwrite(&aux,sizeof(aux),1,p);


    fclose(p);

return guardo;
}

//Carga y guardado de nuevo platos
void punto_1()
{    cls();
    plato aux;
    if (cargar_plato(&aux))
   {if (guardar_plato(aux))
    cout<<"Guardado correctamente."<<endl;}

else {cout<<"El producto no ha podido guardarse, reintente."<<endl;}
 anykey();
 }


//visual de platos
void listar(plato aux)
{
    cout<<endl;
    cout<<"| ID del plato                     | "<<aux.idplato<<endl;
    cout<<"| Nombre del plato                 | "<<aux.nombre<<endl;
    cout<<"| Costo de preparación             | $"<<aux.costo<<endl;
    cout<<"| Valor de venta                   | $"<<aux.venta<<endl;
    cout<<"| Tiempo de preparación en minutos | "<<aux.tiempo<<endl;
    cout<<"| ID del restaurante               | "<<aux.idresto<<endl;
    cout<<"| Comisión del restaurante         | "<<aux.comision<<"%"<<endl;
    cout<<"| Categoría del plato              | "<<aux.idcate<<endl;
    cout<<"| Estado del plato                 | ";

    if(aux.estado)
    { setColor(GREEN);

    }
    else setColor(RED);
    cout<<aux.estado<<endl;
    cout<<endl;
    setColor(WHITE);
}

//Muestra de plato buscado por ID
void punto_5()
{
      cls();
    plato aux;
    FILE *p;
   p=fopen(PLATOS,"rb");
   if(p==NULL)
   {
       cout<<"El archivo no existe";
   }
    while (fread(&aux,sizeof(plato),1,p))
    {
        listar(aux);
        for(int x=0;x<50;x++)
        {
            cout<<"=";
        }cout<<endl;
    }
    fclose(p);
    anykey();

}


//Muestra del plato buscado por ID en archivo
void punto_3()
{   cls();

    plato aux;
    int pos,id;
    cout<<"Por favor, ingrese el ID del plato buscado: "<<endl;
    cin>>id;
    pos=buscar_posicion(id);
    if (pos>=0)
    { aux=leer_plato(pos);
    listar(aux);

    }
    else cout<<"El ID no existe!"<<endl;
    anykey();

}


void punto_2()
{
    cls();
    int id, pos;
    plato aux;
    cout<<"Por favor ingrese el ID del plato a modificar: ";
    cin>>id;
    pos=buscar_posicion(id);
    if(pos>=0)
    {
    aux=leer_plato(pos);
    listar(aux);
    if(modificar_plato(&aux))
    {guardar_cambio(aux,pos);
    cout<<"Cambio realizado exitosamente!";
    }
    else cout<<"El cambio no ha podido realizarse, reintente.";
    }
    else cout<<"El id no existe, reintente.";

    anykey();
    }


    //Busca posicion en el archivo
bool modificar_plato (plato *p)
{  cout<<"Ingrese el nuevo valor de venta: ";
    cin>>p->venta;
    if (p->costo >= p->venta) return false;

    cout<<"Ingrese el nuevo tiempo de preparación en minutos: ";
    cin>>p->tiempo;
    if(p->tiempo<=0) return false;
    return true;
}

//Muestra el archivo buscado en caso de existir
plato leer_plato (int pos)
{   plato aux;
    FILE *p;
    p=fopen(PLATOS,"rb");
    if (p==NULL) return {-1};
    fseek(p,pos*sizeof(plato),SEEK_SET);
    fread(&aux,sizeof(plato),1,p);
    fclose(p);
    return aux;
}

//Baja Logica del Plato
void punto_6()
{   cls();
    int id, pos;
    plato aux;
    cout<<"Por favor ingrese el ID del plato a dar de baja: ";
    cin>>id;
    pos=buscar_posicion(id);
    if (pos>=0)
    {
        aux=leer_plato(pos);
        if(confirmar(aux))
        {cout<<"Producto dado de baja!";
        aux.estado=false;
        guardar_cambio(aux,pos);
        }
        else {cout<<"Acción cancelada!"; }
    }
    else cout<<"El ID no existe, intente nuevamente.";
    anykey();

}

void punto_4()
{   int id;
    cls();
    cout<<"Por favor ingrese el id del restaurante buscado:" ;
    cin>>id;
    if(listar_resto(id));

    else cout<<"ID equivocado, reintente.";

    anykey();

}


bool listar_resto(int id)
{   plato aux;
    bool respuesta=false;
    FILE *p;
    p=fopen(PLATOS,"rb");
    if(p==NULL) cout<<"El archivo no existe";
    while(fread(&aux,sizeof(plato),1,p))
    {   if (id==aux.idresto)
        {listar(aux);
    respuesta=true;}
    }

    fclose(p);
    return respuesta;
}


//confirma la accion de baja
bool confirmar(plato aux)
{   bool respuesta,continuar=true;
    int opcion;


    while (continuar)
    {cls();
    listar(aux);
        cout<<"Seguro que quiere dar de baja el producto? "<<endl;
        cout<<endl;
        cout<<"Pulse 1 para confirmar"<<endl;
        cout<<"Pulse 0 para cancelar"<<endl;
        cout<<endl;
    cin>>opcion;
     switch (opcion)
    {
        case 1: respuesta=true;continuar=false;break;
        case 0: respuesta=false;continuar=false;break;
        default: cout<<"Opción incorrecta intente nuevamente";break;

    }
    }
    return respuesta;
    }



#endif // FUNCIONES_H_INCLUDED
