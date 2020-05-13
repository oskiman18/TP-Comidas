#ifndef FUNCIONES_CLIENTES_H_INCLUDED
#define FUNCIONES_CLIENTES_H_INCLUDED

struct cliente;
struct fecha;
void menu_clientes();
bool nuevo_cliente(cliente*);
int contar_clientes();

bool guardar_cliente(cliente);
void listar_cliente(cliente);
int buscar_cliente(int id);
cliente leer_cliente (int pos);
bool modificar_cliente (cliente *p);
bool confirmar_cliente(cliente aux);
bool cambio_cliente(cliente,int);

void cliente_1();
void cliente_2();
void cliente_3();
void cliente_4();
void cliente_5();



struct fecha{
        int dia,mes, anio;
    };


struct cliente
{
    int id, cp;
    char nombre[50], apellido[50], mail[50], domicilio[100];
    bool estado;
    fecha nacimiento;
};


void menu_clientes(){
    cls();
cout<<"MENÚ CLIENTES"<<endl;
cout<<"------------------"<<endl;
cout<<"1) NUEVO CLIENTE"<<endl;
cout<<"2) MODIFICAR CLIENTE"<<endl;
cout<<"3) LISTAR CLIENTE POR ID"<<endl;
cout<<"4) LISTAR TODOS LOS CLIENTES"<<endl;
cout<<"5) ELIMINAR CLIENTE"<<endl;
cout<<"--------------------------------"<<endl;
cout<<"0) VOLVER AL MENÚ PRINCIPAL"<<endl;
cout<<endl;
cout<<"Pulse la opción de plato deseada: ";
}


bool nuevo_cliente(cliente *p)
{ cls();
cout<<"Por favor ingrese los datos del cliente nuevo: "<<endl;

    p->id=contar_clientes()+1;

    cout<<"Apellido: ";
    cin.ignore();
    cin.getline(p->apellido,50);
    if(strlen(p->apellido)==0) return false;

    cout<<"Nombre: ";
    cin.ignore();
    cin.getline(p->nombre,50);
    if(strlen(p->nombre)==0) return false;

    cout<<"Mail: ";
    cin.ignore();
    cin.getline(p->mail,50);
     if(strlen(p->mail)==0) return false;
    //falta verificaciones

    cout<<"Domicilio: ";
    cin.ignore();
    cin.getline(p->domicilio,100);
    if(strlen(p->domicilio)==0) return false;

    cout<<"Codigo Postal: ";
    cin>>p->cp;
    if ((p->cp <1000) || (p->cp>9999)) return false;

    cout<<"Fecha de Nacimiento: "<<endl;
    cout<<"Dia: ";
    cin>>p->nacimiento.dia;
    if (p->nacimiento.dia<1 || p->nacimiento.dia >31) return false;
    cout<<"Mes: ";
    cin>>p->nacimiento.mes;
    if (p->nacimiento.mes<1 || p->nacimiento.mes >12) return false;


    switch (p->nacimiento.mes)
{
case 2: if(p->nacimiento.dia>28) return false; break;
case 4:
case 6:
case 9:
case 11: if (p->nacimiento.dia>30) return false;break;}
 cout<<"Año: ";
cin>>p->nacimiento.anio;
    if ((p->nacimiento.anio<1920) || (p->nacimiento.anio>2010)) return false;
    p->estado=true;


     return true;}




int contar_clientes()
{   int tam;
    FILE *p;
    p=fopen(CLIENTES,"rb");
    if (p==NULL) return 0;
    fseek(p,0,SEEK_END);
    tam=ftell(p)/sizeof(cliente);

    return tam;
    fclose(p);
}

bool guardar_cliente(cliente aux)
{   bool guardo=true;
    FILE *p;
    p=fopen(CLIENTES,"ab");
    if (p==NULL)
   return false;

    fwrite(&aux,sizeof(aux),1,p);


    fclose(p);

return guardo;
}

void cliente_1()
{    cls();
    cliente aux;
    if (nuevo_cliente(&aux))
   {if (guardar_cliente(aux))
    cout<<"Registrado correctamente."<<endl;}

else {cout<<"El Cliente no ha podido regitrarse, reintente."<<endl;}
 anykey();}


 void listar_cliente(cliente aux)
{
    cout<<endl;
    cout<<"| ID del Cliente        | "<<aux.id<<endl;
    cout<<"| Nombre                | "<<aux.nombre<<endl;
    cout<<"| Apellido              | "<<aux.apellido<<endl;
    cout<<"| Mail                  | "<<aux.mail<<endl;
    cout<<"| Domicilio             | "<<aux.domicilio<<endl;
    cout<<"| Código Postal         | "<<aux.cp<<endl;
    cout<<"| Fecha de Nacimiento   | ";
    cout<<aux.nacimiento.dia<<"/";
    cout<<aux.nacimiento.mes<<"/";
    cout<<aux.nacimiento.anio<<endl;
    cout<<"| Estado del plato      | ";

    if(aux.estado)
    { setColor(GREEN);

    }
    else setColor(RED);
    cout<<aux.estado<<endl;
    cout<<endl;
    setColor(YELLOW);

}

int buscar_cliente(int id)
{   cliente aux;
    int pos=0;
    FILE *p;
    p=fopen(CLIENTES,"rb");
    if (p==NULL) return -1;
    while (fread(&aux,sizeof(cliente),1,p))
    {   if (id==aux.id) return pos;

         pos++;
    }

    fclose(p);
    return -1;
    }

cliente leer_cliente (int pos)
{   cliente aux;
    FILE *p;
    p=fopen(CLIENTES,"rb");
    if (p==NULL) return {-1};
    fseek(p,pos*sizeof(cliente),SEEK_SET);
    fread(&aux,sizeof(cliente),1,p);
    fclose(p);
    return aux;
}


void cliente_3()
{   cls();

    cliente aux;
    int pos,id;
    cout<<"Por favor, ingrese el ID del Cliente buscado: "<<endl;
    cin>>id;
    pos=buscar_cliente(id);
    if (pos>=0)
    { aux=leer_cliente(pos);
    listar_cliente(aux);

    }
    else cout<<"El ID no existe!"<<endl;
    anykey();
}


void cliente_4()
{
      cls();
    cliente aux;
    FILE *p;
   p=fopen(CLIENTES,"rb");
   if(p==NULL)
   {
       cout<<"El archivo no existe";
   }
    while (fread(&aux,sizeof(cliente),1,p))
    {
        listar_cliente(aux);
        for(int x=0;x<75;x++)
        {
            cout<<"=";
        }cout<<endl;
    }
    fclose(p);
    anykey();

}


bool modificar_cliente (cliente *p)
{  cout<<"Ingrese el nuevo Domicilio: ";
    cin.ignore();
    cin.getline(p->domicilio,100);
     if(strlen(p->domicilio)==0) return false;

    return true;
}

bool cambio_cliente(cliente aux,int pos)
{   bool guardo=true;
    FILE *p;
    p=fopen(CLIENTES,"rb+");
    if (p==NULL) return false;
    fseek(p,pos*sizeof(cliente),SEEK_SET);
    fwrite(&aux,sizeof(aux),1,p);


    fclose(p);

return guardo;
}



void cliente_2()
{
    cls();
    int id, pos;
    cliente aux;
    cout<<"Por favor ingrese el ID del Cliente buscado: ";
    cin>>id;
    pos=buscar_cliente(id);
    if(pos>=0)
    {
    aux=leer_cliente(pos);
    listar_cliente(aux);
    if(modificar_cliente(&aux))
    {cambio_cliente(aux,pos);
    cout<<"Cambio realizado exitosamente!";
    }
    else cout<<"El cambio no ha podido realizarse, reintente.";
    }
    else cout<<"El id no existe, reintente.";

    anykey();
    }






bool confirmar_cliente(cliente aux)
{   bool respuesta,continuar=true;
    int opcion;


    while (continuar)
    {cls();
    listar_cliente(aux);
        cout<<"Seguro que quiere dar de baja el Cliente? "<<endl;
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

void cliente_5()
{   cls();
    int id, pos;
    cliente aux;
    cout<<"Por favor ingrese el ID del Cliente a dar de baja: ";
    cin>>id;
    pos=buscar_cliente(id);
    if (pos>=0)
    {
        aux=leer_cliente(pos);
        if (aux.estado)
        {if(confirmar_cliente(aux))
        {cout<<"Cliente dado de baja!";
        aux.estado=false;
        cambio_cliente(aux,pos);
        } else cout<<"Acción cancelada!"; }
        else cout<<"El Cliente ya esta dado de baja.";

    }
    else cout<<"El ID no existe, intente nuevamente.";
    anykey();

}

#endif // FUNCIONES_CLIENTES_H_INCLUDED
