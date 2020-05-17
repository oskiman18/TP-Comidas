#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED


void realizar();
void restaurar();

bool copiar_plato();
bool copiar_cliente();
bool copiar_pedido();
bool restaurar_plato();
bool restaurar_cliente();
bool restaurar_pedido();
void menu_confi();


void menu_confi()
{   cls();
    cout<<"MENÚ CONFIGURACIÓN"<<endl;
    cout<<"------------------"<<endl;
    cout<<"1) REALIZAR COPIA DE SEGURIDAD"<<endl;
    cout<<"2) RESTAURAR COPIA DE SEGURIDAD"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"0) VOLVER AL MENÚ PRINCIPAL"<<endl;
    cout<<endl;
    cout<<"Ingrese la opción deseada: ";
}


void realizar()
{   cls();
    bool opcion;
    cout<<"Seguro que quiere realizar una copia de seguridad?"<<endl;
    cout<<"Sus datos anteriores seran sobreescritos"<<endl;
    cout<<endl;
    setColor(LIGHTRED);cout<<"Presione 0 para Cancelar"<<endl;
    setColor(LIGHTGREEN);cout<<"Presione 1 para Aceptar"<<endl;
    setColor(YELLOW);
    cout<<endl;
    cout<<"Elija la opcion deseada: ";
    cin>>opcion;
    cout<<endl;
    if (opcion)
    {setColor(LIGHTMAGENTA);
    cout<<"ESTA SEGURO DE SOBREESCRIBIR LOS ARCHIVOS?"<<endl;
    cout<<"LA ACCION NO SE PUEDE DESHACER!!!"<<endl;
    cout<<endl;
    setColor(LIGHTRED);cout<<"Presione 0 para Cancelar"<<endl;
    setColor(LIGHTGREEN);cout<<"Presione 1 para Aceptar"<<endl;
    cout<<endl;
    setColor(YELLOW);
    cout<<"Elija la opcion deseada: ";
    cin>>opcion;
    cout<<endl;
    if (opcion)
  { if (!copiar_plato()) {cout<<"Error con el archivo de Platos";anykey(); return;}
    if (!copiar_cliente())  {cout<<"Error con el archivo de Clientes"; anykey();return;}
    if (!copiar_pedido())  {cout<<"Error con el archivo de Pedidos"; anykey();return;}
    cout<<"Copia realizada correctamente, Backup Sobreescritos"<<endl;}
    else cout<<"La copia ha sido Cancelada!"<<endl;

}

else cout<<"La copia ha sido Cancelada!";
  anykey();
}

void restaurar()
{   cls();
    bool opcion;
    cout<<"Seguro que quiere restaurar sus datos con los de la copia de seguridad?"<<endl;
    cout<<"Sus datos actuales seran sobreescritos"<<endl;
    cout<<endl;
    setColor(LIGHTRED);cout<<"Presione 0 para Cancelar"<<endl;
    setColor(LIGHTGREEN);cout<<"Presione 1 para Aceptar"<<endl;
    setColor(YELLOW);
    cout<<endl;
    cout<<"Elija la opcion deseada: ";
    cin>>opcion;
    cout<<endl;
    if (opcion)
    {setColor(LIGHTMAGENTA);
    cout<<"ESTA SEGURO DE RESTAURAR LOS ARCHIVOS?"<<endl;
    cout<<"LA ACCION NO SE PUEDE DESHACER!!!"<<endl;
    cout<<endl;
    setColor(LIGHTRED);cout<<"Presione 0 para Cancelar"<<endl;
    setColor(LIGHTGREEN);cout<<"Presione 1 para Aceptar"<<endl;
    cout<<endl;
    setColor(YELLOW);
    cout<<"Elija la opcion deseada: ";
    cin>>opcion;
    cout<<endl;
    if (opcion)
  { if (!restaurar_plato()) {cout<<"Error con el archivo de Platos"; anykey();return;}
    if (!restaurar_cliente())  {cout<<"Error con el archivo de Clientes"; anykey();return;}
    if (!restaurar_pedido())  {cout<<"Error con el archivo de Pedidos"; anykey();return;}
    cout<<"Copia realizada correctamente, Backup Sobreescritos"<<endl;}
    else cout<<"La copia ha sido Cancelada!"<<endl;

}

else cout<<"La copia ha sido Cancelada!";
  anykey();
}


//platos.dat->platos.bkp
bool copiar_plato()
{   int cant;
    plato *vec;
    cant=contar_platos();
    vec =(plato *) malloc(cant * sizeof(plato));
    if(vec==NULL)
    {free(vec);cout<<"No hay memoria suficiente";return false;}

    FILE *p;
    p=fopen(PLATOS,"rb");
    if (p==NULL) {free (vec);return false;}
    fread(vec,sizeof(plato),cant,p);
    fclose(p);

    p=fopen(BKP_PLATOS,"wb");
    if (p==NULL) {free (vec);return false;}
    fwrite(vec,sizeof(plato),cant,p);
    fclose(p);

    free(vec);
    return true;
}

//cliente.dat->cliente.bkp
bool copiar_cliente()
{   int cant;
    cliente *vec;
    cant=contar_clientes();
    vec =(cliente *) malloc(cant * sizeof(cliente));
    if(vec==NULL)
    {free(vec);cout<<"No hay memoria suficiente";return false ;}

    FILE *p;
    p=fopen(CLIENTES,"rb");
    if (p==NULL) {free (vec);return false;}
    fread(vec,sizeof(cliente),cant,p);
    fclose(p);

    p=fopen(BKP_CLIENTES,"wb");
    if (p==NULL) {free (vec);return false;}
    fwrite(vec,sizeof(cliente),cant,p);
    fclose(p);
    free(vec);
    return true;
}

//pedido.dat->pedido.bkp
bool copiar_pedido()
{   int cant;
    pedido *vec;
    cant=contar_pedidos();
    vec =(pedido *) malloc(cant * sizeof(pedido));
    if(vec==NULL)
    {free(vec);cout<<"No hay memoria suficiente";return false;}

    FILE *p;
    p=fopen(PEDIDOS,"rb");
    if (p==NULL) {free (vec);return false;}
    fread(vec,sizeof(pedido),cant,p);
    fclose(p);

    p=fopen(BKP_PEDIDOS,"wb");
    if (p==NULL) {free (vec);return false;}
    fwrite(vec,sizeof(pedido),cant,p);
    fclose(p);
    free(vec);

    return true;
}

//plato.bkp->plato.dat
bool restaurar_plato()
{   int cant;
    plato *vec;
    cant=contar_platos_bkp();
    vec =(plato *) malloc(cant * sizeof(plato));
    if(vec==NULL)
    {free(vec);cout<<"No hay memoria suficiente";return false;}

    FILE *p;
    p=fopen(BKP_PLATOS,"rb");
    if (p==NULL) {free (vec);return false;}
    fread(vec,sizeof(plato),cant,p);
    fclose(p);

    p=fopen(PLATOS,"wb");
    if (p==NULL) {free (vec);return false;}
    fwrite(vec,sizeof(plato),cant,p);
    fclose(p);
    free(vec);
    return true;
}

//cliente.bkp->cliente.dat
bool restaurar_cliente()
{   int cant;
    cliente *vec;
    cant=contar_clientes_bkp();
    vec =(cliente *) malloc(cant * sizeof(cliente));
    if(vec==NULL)
    {free(vec);cout<<"No hay memoria suficiente";return false ;}

    FILE *p;
    p=fopen(BKP_CLIENTES,"rb");
    if (p==NULL) {free (vec);return false;}
    fread(vec,sizeof(cliente),cant,p);
    fclose(p);

    p=fopen(CLIENTES,"wb");
    if (p==NULL) {free (vec);return false;}
    fwrite(vec,sizeof(cliente),cant,p);
    fclose(p);
    free(vec);
    return true;
}

//pedido.bkp->pedido.dat
bool restaurar_pedido()
{   int cant;
    pedido *vec;
    cant=contar_pedidos_bkp();
    vec =(pedido *) malloc(cant * sizeof(pedido));
    if(vec==NULL)
    {free(vec);cout<<"No hay memoria suficiente";return false;}

    FILE *p;
    p=fopen(BKP_PEDIDOS,"rb");
    if (p==NULL) {free (vec);return false;}
    fread(vec,sizeof(pedido),cant,p);
    fclose(p);

    p=fopen(PEDIDOS,"wb");
    if (p==NULL) {free (vec);return false;}
    fwrite(vec,sizeof(pedido),cant,p);
    fclose(p);
    free(vec);

    return true;
}









#endif // CONFIGURACION_H_INCLUDED
