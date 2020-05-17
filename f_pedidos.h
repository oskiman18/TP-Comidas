#ifndef F_PEDIDOS_H_INCLUDED
#define F_PEDIDOS_H_INCLUDED

struct pedido;


void menupedido();
bool guardar_pedido(pedido);
bool ingresar_pedido(pedido*);
int contar_pedidos();
pedido leer_pedido(int);
void listar_pedido(pedido);
int buscar_pedido(int);
bool modificar_pedido(pedido*);
bool cambio_pedido(pedido,int);
void pedido_1();
void pedido_2();
void pedido_3();
void pedido_4();




struct pedido{
int idpedido, idcliente,idplato,cantidad,estado;
float precio,valoracion;
fecha fpedido;};

//menu
void menupedido()
{
    cls();
cout<<"MENÚ PEDIDOS"<<endl;
cout<<"------------------"<<endl;
cout<<"1) NUEVO PEDIDO"<<endl;
cout<<"2) MODIFICAR PEDIDO"<<endl;
cout<<"3) LISTAR PEDIDO POR ID"<<endl;
cout<<"4) LISTAR TODOS LOS PEDIDOS"<<endl;
cout<<"--------------------------------"<<endl;
cout<<"0) VOLVER AL MENÚ PRINCIPAL"<<endl;
cout<<endl;
cout<<"Seleccione la opción de pedido deseada: ";
}

//conteo de pedidos
int contar_pedidos()
{   int tam;
    FILE *p;
    p=fopen(PEDIDOS,"rb");
    if (p==NULL) return 0;
    fseek(p,0,SEEK_END);
    tam=ftell(p)/sizeof(pedido);

    return tam;
    fclose(p);
}

//cuenta pedidos del backup
int contar_pedidos_bkp()
{   int tam;
    FILE *p;
    p=fopen(BKP_PEDIDOS,"rb");
    if (p==NULL) return 0;
    fseek(p,0,SEEK_END);
    tam=ftell(p)/sizeof(pedido);

    return tam;
    fclose(p);}

//ingreso de datos de pedido nuevo
bool ingresar_pedido(pedido *p)
{   cls();
    plato aux;
    cliente aux2;
    int pos;
    cout<<"Por favor ingrese los datos del pedido nuevo: "<<endl;

    p->idpedido=contar_pedidos()+1;

    cout<<"Por favor Número de cliente: "<<endl;
    cin>>p->idcliente;
    pos=buscar_cliente(p->idcliente);
    if (pos<0) return false;
    aux2=leer_cliente(pos);
    if(!aux2.estado) return false;


    cout<<"Ingrese ID del plato: ";
    cin>>p->idplato;
    pos=(buscar_posicion(p->idplato));
    if(pos<0) return false;
    aux=leer_plato(pos);
    if(!aux.estado) return false;

    cout<<"Ingrese cantidad: ";
    cin>>p->cantidad;
    if (p->cantidad<1) return false;

    p->precio=aux.venta;

    cout<<"Fecha del pedido: "<<endl;
    cout<<"Dia: ";
    cin>>p->fpedido.dia;
    if (p->fpedido.dia<1 || p->fpedido.dia >31) return false;
    cout<<"Mes: ";
    cin>>p->fpedido.mes;
    switch (p->fpedido.mes)
   {case 2: if(p->fpedido.dia>28) return false; break;
    case 4:
    case 6:
    case 9:
    case 11: if (p->fpedido.dia>30) return false;break;}

    cout<<"Año: ";
    cin>>p->fpedido.anio;
    if (p->fpedido.anio>2020) return false;


    cout<<"Valoración: ";
    cin>>p->valoracion;
    if ((p->valoracion<0) || (p->valoracion>10)) return false;


    p->estado=1;
     return true;
}


//grabado de pedidos nuevos
bool guardar_pedido(pedido aux)
{   bool guardo=true;
    FILE *p;
    p=fopen(PEDIDOS,"ab");
    if (p==NULL) return false;

    fwrite(&aux,sizeof(aux),1,p);


    fclose(p);

return guardo;
}

void pedido_1()
{    cls();
    pedido aux;
    if (ingresar_pedido(&aux))
   {if (guardar_pedido(aux))
    cout<<"Registrado correctamente."<<endl;}

else {cout<<"El Pedido no ha podido regitrarse, reintente."<<endl;}
 anykey();}

 //detalles del pedido buscado
void listar_pedido(pedido aux)
{

    cout<<endl;
    cout<<"| ID del Pedido             | "<<aux.idpedido<<endl;
    cout<<"| ID del Cliente            | "<<aux.idcliente<<endl;
    cout<<"| ID del Plato              | "<<aux.idplato<<endl;
    cout<<"| Cantidad                  | "<<aux.cantidad<<endl;
    cout<<"| Precio Unitario           | "<<aux.precio<<endl;
    cout<<"| Fecha del Pedido          | ";
    cout<<aux.fpedido.dia<<"/";
    cout<<aux.fpedido.mes<<"/";
    cout<<aux.fpedido.anio<<endl;
    cout<<"| Valoración                | "<<aux.valoracion<<endl;
    cout<<"| Estado del plato          | ";

    switch (aux.estado)
    {case 1: setColor(LIGHTBLUE);cout<<"En curso"<<endl;break;
    case 2: setColor(LIGHTGREEN);cout<<"Completado"<<endl;break;
    case 3: setColor(LIGHTRED);cout<<"Cancelado"<<endl;break;}
    cout<<endl;

    setColor(YELLOW);

}


void pedido_4()
{
      cls();
    pedido aux;
    FILE *p;
   p=fopen(PEDIDOS,"rb");
   if(p==NULL)
   {
       cout<<"El archivo no existe";
   }
    while (fread(&aux,sizeof(pedido),1,p))
    {
        listar_pedido(aux);
        for(int x=0;x<75;x++)
        {
            cout<<"=";
        }cout<<endl;
    }
    fclose(p);
    anykey();
}

//busqueda de la existencia del pedido en el archivo
int buscar_pedido(int id)
{   pedido aux;
    int pos=0;
    FILE *p;
    p=fopen(PEDIDOS,"rb");
    if (p==NULL) return -1;
    while (fread(&aux,sizeof(pedido),1,p))
    {   if (id==aux.idpedido) return pos;

         pos++;
    }

    fclose(p);
    return -1;
    }

void pedido_2()
{
    cls();
    int id, pos;
    pedido aux;
    cout<<"Por favor ingrese el ID del Cliente buscado: ";
    cin>>id;
    pos=buscar_pedido(id);
    if(pos>=0)
    {
    aux=leer_pedido(pos);
    listar_pedido(aux);
    if(modificar_pedido(&aux))
    {cambio_pedido(aux,pos);
    cout<<"Cambio realizado exitosamente!";
    }
    else cout<<"El cambio no ha podido realizarse, reintente.";
    }
    else cout<<"El id no existe, reintente.";

    anykey();
    }


void pedido_3()
{
    cls();
    pedido aux;
     int pos,id;
    cout<<"Por favor, ingrese el ID del plato buscado: "<<endl;
    cin>>id;
    pos=buscar_pedido(id);
    if (pos>=0)
    { aux=leer_pedido(pos);
    listar_pedido(aux);    }
    else cout<<"El ID no existe!"<<endl;
    anykey();
}

//obtencion de datos
pedido leer_pedido(int pos)
{   pedido aux;
    FILE *p;
    p=fopen(PEDIDOS,"rb");
    if (p==NULL) return {-1};
    fseek(p,pos*sizeof(pedido),SEEK_SET);
    fread(&aux,sizeof(pedido),1,p);
    fclose(p);
    return aux;
}


//modificacion de datos en archivo
bool modificar_pedido (pedido *p)
{  cout<<"Ingrese el nuevo Estado: ";
    cin>>p->estado;
    if((p->estado<1) || (p->estado>3)) return false;
    return true;
}

//grabado de pedido editado
bool cambio_pedido(pedido aux,int pos)
{
    bool guardo=true;
    FILE *p;
    p=fopen(PEDIDOS,"rb+");
    if (p==NULL) return false;
    fseek(p,pos*sizeof(pedido),SEEK_SET);
    fwrite(&aux,sizeof(aux),1,p);


    fclose(p);

return guardo;
}


#endif // F_PEDIDOS_H_INCLUDED
