#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



struct plato;
void menuprincipal();
void menuplato();
bool buscar_indice();
bool cargar_plato();
bool guardar_plato();
void nuevo_plato();
void listar();
void listar_todo();
void listar_id();

//Estructura
struct plato
{int idplato, tiempo, idresto, comision, idcate;
float costo, valor;
bool estado;
char nombre[50];
};
//Muestra el Menu Principal
void menuprincipal(){

system("cls");
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
system("cls");
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
cout<<"Pulse la opcion de plato deseada: ";
}

//busca en el archivo existe el ID;
bool buscar_indice(int id)
{ FILE *p;
plato aux;
bool respuesta=true;
    p=fopen(PLATOS,"rb");
    if (p==NULL)
    {
        return respuesta=false;
    }
    while(fread(&aux,sizeof(aux),1,p))
    { if(id==aux.idplato) respuesta=false;

    }
    return respuesta;
    fclose(p);
}

//Carga manual de platos
bool cargar_plato(plato *p)
{ system("cls");
cout<<"Por favor ingrese los datos del plato nuevo: "<<endl;
    cout<<"ID del plato: ";
    cin>>p->idplato;
    if((buscar_indice(p->idplato)==false)||(p->idplato<1)) return false;

    cout<<"Nombre: ";
    cin.ignore();
    cin.getline(p->nombre,50);
    if(strlen(p->nombre)==0) return false;

    cout<<"Costo de preparacion: ";
    cin>>p->costo;
    if (p->costo<0) return false;

    cout<<"Valor de venta: ";
    cin>>p->valor;
    if (p->costo >= p->valor) return false;

    cout<<"Tiempo de preparacion en minutos: ";
    cin>>p->tiempo;
    if(p->tiempo<=0) return false;

    cout<<"ID del restaurante: ";
    cin>>p->idresto;
    if(p->idresto<=0) return false;

    cout<<"Comision del restaurante: ";
    cin>>p->comision;
    if((p->comision>=100)|| (p->comision<=0)) return false;

    cout<<"Categoria del plato: ";
    cin>>p->idcate;
    if(p->idcate<=0) return false;

    p->estado=true;
     return true;
}

//Grabado en archivo del plato
bool guardar_plato(plato aux)
{   bool guardo;
    FILE *p;
    p=fopen(PLATOS,"ab");
    if (p==NULL)
   return false;

    guardo=fwrite(&aux,sizeof(aux),1,p);


    fclose(p);

return guardo;
}

//Opcion 1 del menu de platos
void nuevo_plato()
{   system("cls");
    plato aux;
    if (cargar_plato(&aux))
   {if (guardar_plato(aux))
    cout<<"Guardado correctamente."<<endl;}

else {cout<<"el producto no ha podido guardarse, reintente."<<endl;}
system("pause");}


//visual de platos
void listar(plato aux)
{
    cout<<endl;
    cout<<"| ID del plato                     |  "<<aux.idplato<<endl;
    cout<<"| Nombre del plato                 |  "<<aux.nombre<<endl;
    cout<<"| Costo de preparacion             | $"<<aux.costo<<endl;
    cout<<"| Valor de venta                   | $"<<aux.valor<<endl;
    cout<<"| Tiempo de preparacion en minutos |  "<<aux.tiempo<<endl;
    cout<<"| ID del restaurante               |  "<< aux.idresto<<endl;
    cout<<"| Comision del restaurante         | %"<< aux.comision<<endl;
    cout<<"| Categoria del plato              |  "<< aux.idcate<<endl;
    cout<<"| Estado del plato                 |  "<<aux.estado<<endl;
    cout<<endl;

}

//opcion 5 menu de platos
void listar_todo()
{
    system("cls");
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
    }
    fclose(p);
   system("pause");

}

void listar_idplato(int id)

{   plato aux;
    FILE *p;
    p=fopen(PLATOS,"rb");
    if (p==NULL)
    {
        cout<<"El archivo no existe";

    }
    while (fread(&aux,sizeof (plato),1,p))
        {
            if (id==aux.idplato)
            {
               listar(aux);
            }

        }
        fclose(p);
    }

void punto_3()
{   system("cls");
    int id;
    cout<<"Por favor, ingrese el ID del plato buscado: "<<endl;
    cin>>id;
    if (!buscar_indice(id))
    { listar_idplato(id);

    }
    else cout<<"El ID no existe!"<<endl;
    system("pause");
}



#endif // FUNCIONES_H_INCLUDED
