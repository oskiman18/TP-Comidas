#ifndef FUNCIONES_CLIENTES_H_INCLUDED
#define FUNCIONES_CLIENTES_H_INCLUDED

struct cliente;
struct fecha;
void menu_clientes();
bool nuevo_cliente(cliente*);
int contar_clientes();

bool guardar_cliente(cliente);
void listar_cliente(cliente);
int buscar_cliente(int);
cliente leer_cliente (int);
bool modificar_cliente (cliente *p);
bool confirmar_cliente(cliente aux);
bool cambio_cliente(cliente,int);
bool verificar_mail(char*);
bool verificar_dom(char*);

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
    primera_mayus(p->apellido);
    if (!solo_letras(p->apellido)) return false;



    cout<<"Nombre: ";
    cin.getline(p->nombre,50);
    if(strlen(p->nombre)==0) return false;
    primera_mayus(p->nombre);
    if(!solo_letras(p->nombre)) return false;

    cout<<"Mail: ";
    cin.getline(p->mail,50);
    if(strlen(p->mail)==0) return false;
    if (!verificar_mail(p->mail)) return false;

    //falta verificaciones

    cout<<"Domicilio: ";
    cin.getline(p->domicilio,100);
    if(strlen(p->domicilio)==0) return false;
    primera_mayus(p->domicilio);
    if (!verificar_dom(p->domicilio)) return false;

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

void primera_mayus(char*cadena)

{
    if (cadena[0]>90) cadena[0]-=32;
}

bool solo_letras (char*cadena)
{   int i=0;
    while (cadena[i]!='\0')
    {
        if (cadena[i]<32) return false;
        if ((cadena[i]>32)&&(cadena[i]<65)) return false;
        if ((cadena[i]>90)&&(cadena[i]<97)) return false;
        if (cadena[i]>122) return false;
        i++;
    }
    return true;
}

bool verificar_dom(char*dom)
{   int i=0;
    while (dom[i]!='\0')
    {
        if (dom[i]<32) return false;
        if ((dom[i]>32)&&(dom[i]<48)) return false;
        if ((dom[i]>57)&&(dom[i]<65)) return false;
        if ((dom[i]>90)&&(dom[i]<97)) return false;
        if (dom[i]>122) return false;
        i++;
    }
    return true;
}

bool verificar_mail(char*mail)
{   int i=0, arroba=0;
    if((mail[0]=='@')|| (mail[0]=='.')) return false;
    while (mail[i]!='\0')
    {   if (mail[i]<46) return false;
        if (mail[i]==47) return false;
        if ((mail[i]>57)&&(mail[i]<64)) return false;
        if ((mail[i]>90)&&(mail[i]<95)) return false;
        if ((mail[i]>95)&&(mail[i]<97)) return false;
        if (mail[i]>122) return false;
        if (mail[i]=='@') arroba++;
        if ((mail[i]=='.') &&(mail[i+1]=='.')) return false;
        i++;
    }
    i=strlen(mail);
    if ((mail[i-1]=='@') || (mail[i-1]=='.'))return false;
    if (arroba!=1) return false;

return true;
}
#endif // FUNCIONES_CLIENTES_H_INCLUDED

