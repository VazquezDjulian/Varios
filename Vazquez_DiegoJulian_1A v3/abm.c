#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "abm.h"
#include "listados.h"

#define TAMPROV 5
#define TAMPROD 50

void inicializarStruct(eProductos vec[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        vec[i].isEmpty = 1; //esta vacio? SI
    }
}

int buscarLibre(eProductos vec[], int tam)
{
    int i;
    int indice = -1;
    for(i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 1)//si esta vacio el elemento, lo devuelvo para cargar sobre el
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarProducto(eProductos vec[], int tam, int codigo)
{
    int i;
    int esta = -1;
    for(i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].codigoP == codigo)
        {
            esta = i; //me devuelva la posicion si lo encuenta
            break;
        }
    }
    return esta; // me reotorna -1 si no hay nada

}

int ValueInt(char aux[25])
{
    int flag = 0;
    if(atoi(aux) != 0)
    {
       flag = 1;
       return flag;
    }
    else
    {
        printf("Debe ingresar un numero\n");
        return flag;
    }
}

void MenuAbm()
{
    fflush(stdin);
    system("cls");
    printf("--MENU--\n");
    printf("1-Alta de Producto\n");
    printf("2-Modificar Producto\n");
    printf("3-Baja de Producto\n");
    printf("4-Informar total/promedio/stock\n");
    printf("5-Listados\n");
    printf("6-Mostrar todo\n");
    printf("7-SALIR\n");

    printf("\nIndique opcion: ");
    //fflush(stdin);
}

void alta(eProductos vec[],eProveedor prov[], int tam)
{
    int posi;
    int esta;
    eProductos producto;
    int legInt;
    char nombreAux[150];
    int longitudNombre;
    char secChar[5];
    int secInt;
    char cantAux[5];
    int cantidad;


    system("cls");
    printf("--ALTA DE PRODCUTO--\n");
    posi = buscarLibre(vec,tam);
    if(posi == -1)
    {
        printf("No hay espacio en sistema\n");
    }
    else
    {
        /*do
        {
            printf("Ingrese el Legajo: ");
            scanf("%s",&legChar);
        }while(ValueInt(legChar) != 1);
        legInt = atof(legChar); //validando que se ingresen numeros y convirtiendolos
        */
        legInt = posi + 1;

        esta = buscarProducto(vec,tam,legInt); //validamos que no este ese legajo numerico ya cargado
        if(esta != -1)//si ya esta cargado
        {
            printf("Ese codigo esta cargado y pertenece a : \n");
            //mostaria el empleado en el indice vec[esta]
        }
        else
        {
            producto.codigoP = legInt;
            producto.isEmpty = 0; //esta vacio? falso, ya hay algo

            do
            {
                printf("Ingrese Nombre de producto: ");
                fflush(stdin);
                //scanf("%[^\n]",nombreAux);
                gets(nombreAux);
                longitudNombre = strlen(nombreAux);
                }while(longitudNombre>=29);// lo que queremos es que se pida siempre que supere nuestro maximo de 24 en estructura

            strcpy(producto.descripcionP,nombreAux);


            printf("Ingrese precio individual: ");
            scanf("%f", &producto.importe);

            do
            {
                printf("Ingrese la cantidad a comprar: ");
                scanf("%s",&cantAux);
            }while(ValueInt(cantAux) != 1);
            cantidad = atof(cantAux); //validando que se ingresen numeros y convirtiendolos

            producto.cantidad = cantidad;


            MostrarProveedor(prov,TAMPROV);

            do
            {
                printf("Ingrese el numero de identificacion del Proveedor al que pertenece: \n");
                fflush(stdin);
                scanf("%c",&secChar);
            }while(ValueInt(secChar) != 1);

            secInt = atof(secChar);
            producto.proveedor = secInt;

            vec[posi] = producto;
        }
    }
}

void MostrarProveedor(eProveedor prov[], int tam)
{
    int i;
    for(i=0; i<tam; i ++)
    {
        if(prov[i].isEmpty == 0)
        {
            printf("\n\n%d-->%s\n",prov[i].codigo,prov[i].descripcion);
        }
    }
}

void mostrarProductos(eProductos vec[],eProveedor prov[],int tamPTO, int tamPV)
{
    int i;
    int j;
    system("cls");
    printf("CODIGO\t DESCRIPCION\t PRECIO  CANTIDAD  PROVEEDOR\n");
    for(i=0;i<tamPTO; i++)
    {
       for(j=0; j<tamPV; j++)
       {
           if(vec[i].proveedor == prov[j].codigo)
           {
               if(vec[i].isEmpty == 0)
                {
                    printf("%4d %15s %8.2f %4d %10s\n",vec[i].codigoP,vec[i].descripcionP,vec[i].importe,vec[i].cantidad,prov[j].descripcion);
                }
           }
       }
    }
}

void Baja(eProductos vec[],eProveedor prov[], int tam)
{
    char legAux[20];
    int legajo;
    int esta;
    char confirmar;

    printf("--BAJA DE PRODUCTO--\n");
    mostrarProductos(vec,prov,tam,TAMPROV);
    printf("\n");

    do
        {
            printf("Ingrese el codigo correspondiente del producto a dar de baja\n");
            scanf("%s",&legAux);

        }while(ValueInt(legAux) != 1);

        legajo = atof(legAux);
        esta = buscarProducto(vec,tam,legajo);
        if(esta == -1)//si NO esta cargado
        {
            printf("Ese no esta en sistema\n");
        }
        else
        {
            printf("El codigo pertenece a : \n");
            mostarUnProducto(vec,prov,esta);

            do
            {
                printf("Confirmar baja de producto [S // N]");
                fflush(stdin);
                scanf("%c",&confirmar);
                confirmar = tolower(confirmar);
            }while(confirmar == 'n' && confirmar == 's'); //por que no OR

            if(confirmar == 's')
            {
                vec[esta].isEmpty = 1;//POR QUE NO LO ELIMINO?
                printf("Baja realizada\n");
            }
            else
            {
                printf("Baja cancelada\n");
            }
        }
}

void mostarUnProducto(eProductos vec[],eProveedor prov[],int pos)
{
     int i;
     int posP;
     for(i=0; i<TAMPROV; i++)
     {
         if(vec[pos].proveedor == prov[i].codigo)
         {
             posP = i;
         }
     }

     printf("CODIGO\t DESCRIPCION\t PRECIO  CANTIDAD  PROVEEDOR\n");
     printf("%4d %15s %8.2f %4d %10s\n",vec[pos].codigoP,vec[pos].descripcionP,vec[pos].importe,vec[pos].cantidad,prov[i].descripcion);
}

void Modificar(eProductos vec[], eProveedor prov[],int tamProducto, int tamProveedor)
{
    char legAux[20];
    int legajo;
    int esta;
    int seguir = 0;
    char opcion;

    char nuevaCantidadChar[20];
    int nuevaCantidad;
    char nombreAux[100];
    int tamNombre;
    float nuevoPrecio;
    int esFlotante;

    printf("--MODIFICACION DE EMPLEADO--\n");
    mostrarProductos(vec,prov,tamProducto,tamProveedor);
    do
        {
            printf("Ingrese el codigo correspondiente del producto a modificar\n");
            scanf("%s",&legAux);

        }while(ValueInt(legAux) != 1);

    legajo = atof(legAux);
    esta = buscarProducto(vec,tamProducto,legajo);
    if(esta == -1)//si NO esta cargado
    {
        printf("Ese no esta en sistema\n");
    }
    else
    {
        printf("El legajo pertenece a : \n");
        mostarUnProducto(vec,prov,esta);
        printf("\n");

        do
        {
            MenuModificar();
            fflush(stdin);
            scanf("%c",&opcion);
            switch(opcion)
            {


                case '1':
                    do
                    {
                        printf("Ingrese la nueva descripcion :");
                        gets(nombreAux);
                        tamNombre = strlen(nombreAux);
                    }while(tamNombre >=29);//HASTA QUE ESTO NO SEA ASI
                    strcpy(vec[esta].descripcionP,nombreAux);
                    printf("Cambio realizado! \n");
                break;

                case '2':
                    do
                    {
                        printf("Ingrese el nuevo precio: ");
                        scanf("%f",&nuevoPrecio);
                        esFlotante = ValidarEntero(nuevoPrecio);
                    }while(esFlotante == 0);
                    vec[esta].importe = nuevoPrecio;
                    printf("Cambio realizado! \n");

                break;

                case '3':
                     do
                    {
                        printf("Ingrese la nueva cantidad: ");
                        scanf("%s",&nuevaCantidadChar);
                    }while(ValueInt(nuevaCantidadChar) != 1);
                    nuevaCantidad = atof(nuevaCantidadChar);
                    vec[esta].cantidad = nuevaCantidad;
                    printf("Cambio realizado! \n");
                break;

                case '4':
                    seguir = 1;
                break;
            }

        }while(seguir != 1);
    }
}

void MenuModificar()
{

    system("cls");
    printf("---Modificar Productos---\n\n");
    printf("1-Descripcion\n");
    printf("2-Importe\n");
    printf("3-Cantidad\n");
    printf("4-Salir\n");
    printf("\n");
}

int ValidarEntero(float numero)
{
    int ParteEntera = (int) numero;

    if(numero - ParteEntera > 0)
    {
       return 0;
    }
    else
    {
       return 1;
    }
}
