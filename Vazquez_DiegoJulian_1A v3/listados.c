#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "abm.h"
#include "listados.h"

#define TAMPROV 5
#define TAMPROD 50

void informeDeImportes(eProductos vec[],int tam)
{
    float acumuladorTotal = 0;
    int contadorPromedio = 0;
    float promedio;
    int contadorSuperador = 0;
    int contadorInferior = 0;
    int contadorStockMas = 0;
    int contadorStockMenos = 0;

    int i;

    printf("\n\nINFORME DE TOTAL Y PROMEDIO\n");

    for(i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            if(vec[i].cantidad <= 10)
            {
                contadorStockMenos++;
            }
            else
            {
                contadorStockMas ++;
            }
        }
    }

    acumuladorTotal = sumaImportes(vec,tam);
    contadorPromedio = contador(vec,tam);
    printf("\nEl total la compra es: %.2f\n\n",acumuladorTotal);
    promedio = promedioImportes(vec,tam);
    printf("\nEl promedio de los productos es: %.2f\n\n",promedio);

    for(i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
          if(vec[i].importe >= promedio)
            {
                contadorSuperador ++;
            }
            else
            {
                contadorInferior++;
            }
        }

    }
    printf("La cantidad de productos que valen MAS de $%.2f es  %d\n\n",promedio,contadorSuperador);
    printf("La cantidad de productos que valen MENOS de $%.2f es  %d\n",promedio,contadorInferior);

    printf("\nCONTADOR DE STOCK\n");
    printf("La cantidad de productos cuyo stock es MAYOR a 10: %d \n\n",contadorStockMas);
    printf("La cantidad de productos cuyo stock es MENOR a 10: %d\n \n",contadorStockMenos);

}


float sumaImportes(eProductos vec[], int tam)
{
    int i;
    float total = 0;

    for(i=0; i<tam; i++)
    {
        if(vec[i].isEmpty ==0 )
        {
            total = (vec[i].importe * vec[i].cantidad) + total;
        }
    }

    return total;
}

float contador(eProductos vec[], int tam)
{
    int i;
    int contador = 0;

    for(i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            contador = vec[i].cantidad + contador;
        }
    }

    return contador;
}

float promedioImportes(eProductos vec[], int tam)
{
    int i;
    float promedio = 0;

    promedio = (sumaImportes(vec,tam) / contador(vec,tam));

    return promedio;

}

void Informes(eProductos vec[],eProveedor prov[],int tampp, int tampv)
{
    char opcion;
    int seguir = 1;

    printf("MENU  DE INFORMES\n");

    do
    {
        menuInformes();
        fflush(stdin);
        scanf("%c",&opcion);
        opcion = toupper(opcion);

        switch(opcion)
        {
            case 'A':
                ordenamientosPuntoA(vec,prov,tampp);//Orden de importe Descendente / descripcion Ascendente
                system("pause");
                system("cls");
                break;

            case 'B':
                ordenCantidadMenor(vec,prov,tampp);//productos que en cantidad son MENORES o igual a 10 unidades
                 system("pause");
                system("cls");
                break;

            case 'C':
                ordenCantidadMayor(vec,prov,tampp);//Productos que en cantidad son MAYOR a 10 unidades
                 system("pause");
                system("cls");
                break;

            case 'D':
                productosSuperiorPromedio(vec,prov,tampp);//Todos los productos que SUPERAN el promedio de los importes\n"
                 system("pause");
                system("cls");
                break;

            case 'E':
                productosInferiorPromedio(vec,prov,tampp);//Todos los productos que NO SUPERAN el promedio de los importes
                 system("pause");
                system("cls");
                break;

            case 'F':
                proveedorMenorDiez(vec,prov,tampp,tampv); //Todos los proveedores cuya cantidad de productos es MENOR o igual a 10
                 system("pause");
                system("cls");
                break;

            case 'G':
                productosDeProveedores(vec,prov,tampp,tampv);//Todos los productos provistos por cada proveedor\n");
                 system("pause");
                system("cls");
                break;

            case 'H':
                mostrarProductosXproveedor(vec,prov,tampp,tampv);//Todos los productos provistos por un proveedor determinado
                 system("pause");
                system("cls");
                break;

            case 'I':
                proveedorMayor(vec,prov,tampp,tampv); //El proveedor que provee MAS productos, mostrando los productos
                 system("pause");
                system("cls");
                break;

            case 'J':
                proveedorMenor(vec,prov,tampp,tampv);// El proveedor que provee MENOS productos, mostrando los producto
                 system("pause");
                system("cls");
                break;

            case 'K':
                productoMasCaro(vec,prov,tampp,tampv); // El proveedor que provee el producto mas CARO, mostrando ese producto
                system("pause");
                system("cls");
                break;

            case 'L':
                productoMasBarato(vec,prov,tampp,tampv);// El proveedor que provee el producto mas BARATO, mostrando ese producto
                 system("pause");
                system("cls");
                break;

            case 'X':
                seguir = 0;
                system("pause");
                system("cls");
                break;

        }

    }while(seguir == 1);
}

void menuInformes()
{
    printf("SELECCIONE OPCION: \n\n");
    printf("A. Orden de importe Descendente / descripcion Ascendente \n"); //PROBAR
    printf("B. Productos que en cantidad son MENORES o igual a 10 unidades\n");//BIEN
    printf("C. Productos que en cantidad son MAYOR a 10 unidades\n");//BIEN
    printf("D. Todos los productos que SUPERAN el promedio de los importes\n");//BIEN
    printf("E. Todos los productos que NO SUPERAN el promedio de los importes\n");//BIEN
    printf("F. Todos los proveedores cuya cantidad de productos es MENOR o igual a 10 \n");//bien
    printf("G. Todos los productos provistos por cada proveedor\n");
    printf("H. Todos los productos provistos por un proveedor determinado\n");
    printf("I. El proveedor que provee MAS productos, mostrando los productos\n");
    printf("J. El proveedor que provee MENOS productos, mostrando los productos\n");
    printf("K. El proveedor que provee el producto mas CARO, mostrando ese producto\n");
    printf("L. El proveedor que provee el producto mas BARATO, mostrando ese producto\n");
    printf("\nX. SALIR\n");
}

void ordenamientosPuntoA(eProductos vec[],eProveedor prov[],int tam)
{
    int opcion;
    int seguir = 1;

    system("cls");

    do
    {
        printf("1.Orden por importe Descendente\n");
        printf("2.Orden por descripcion Ascendente\n");
        printf("3.SALIR\n");
        printf("Seleccione opcion\n");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                ordenarNumeros(vec,prov,TAMPROD,1);
                system("pause");
                system("cls");
                break;

            case 2:
                 ordenarCadenas(vec,prov,TAMPROD,0);
                 system("pause");
                 system("cls");
                break;

            case 3:
                seguir = 0;
                break;

            default:
            printf("Opcion no valida\n");
            break;
        }

    }while(seguir == 1);
}

void ordenarNumeros(eProductos vec[],eProveedor prov[],int tam, int criterio)
{
    int i;
    int j;
    eProductos aux;

    // DESCENDENTE
    if(criterio == 0)
    {
      for(i=0; i<tam-1; i++)
        {
            for(j=i+1; j<tam; j++)
            {
              if(vec[i].isEmpty == 0 && (vec[i].importe > vec[j].importe))
              {
                  aux = vec[i];
                  vec[i] = vec[j];
                  vec[j] = aux;
              }
            }
        }
    }

    // ASCENDENTE
    if (criterio ==1)
    {
       for(i=0; i<tam-1; i++)
       {
           for(j=i+1; j<tam; j++)
           {
               if(vec[i].isEmpty == 0 && (vec[i].importe < vec[j].importe))
                {
                  aux = vec[i];
                  vec[i] = vec[j];
                  vec[j] = aux;
                }
           }
       }
    }
    //mostrarProductos(vec,prov,tam,TAMPROV); // error aca
    for(i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostarUnProducto(vec,prov,i);
        }
    }

}

void ordenarCadenas(eProductos vec[],eProveedor prov[],int tam, int criterio)
{
    int i;
    int j;
    eProductos auxiliar;

    if(criterio == 0)
    {
        for(i=0;i< tam-1;i++)
        {
            for(j=i+1;j<tam;j++)
            {
                if(strcmp(vec[i].descripcionP,vec[j].descripcionP)>0 && vec[i].isEmpty == 0)
                {
                    auxiliar = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxiliar;
                }
            }
        }
    }

    if(criterio == 1)
    {
        for(i=0;i< tam-1;i++)
        {
            for(j=i+1;j<tam;j++)
            {
                if(strcmp(vec[i].descripcionP,vec[j].descripcionP)<0 && vec[i].isEmpty == 0)
                {
                    auxiliar = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxiliar;
                }

            }
        }
    }

    for(i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostarUnProducto(vec,prov,i);
        }
    }
}

void mostrarProductosXproveedor(eProductos vec[],eProveedor prov[],int tampp, int tampv)
{

    int proveedor;
    int i;
    int j;
    system("cls");
    MostrarProveedor(prov,tampv);
    printf("\nIngrese el numero de proveedor:  ");
    scanf("%d",&proveedor);
    printf("\n");

    for(i=0;i<tampv;i++)
    {
        if(prov[i].codigo == proveedor)
        {
            //MOSTRAR DATOS DEL PROVEEDOR
            for(j=0;j<tampp;j++)
            {
                if(vec[j].isEmpty == 0)
                {
                    if(prov[i].codigo == vec[j].proveedor)
                    {
                        //MOSTRAR DATOS DEL PRODUCTO
                        mostarUnProducto(vec,prov,j);
                    }
                }
            }
        }
    }
}

void ordenCantidadMenor(eProductos vec[], eProveedor prov[], int tam)
{
    int i;

    for(i=0; i <tam; i++)
    {
        if(vec[i].isEmpty ==0)
            if(vec[i].cantidad <= 10)
        {
            mostarUnProducto(vec,prov,i);
        }
    }
}

void ordenCantidadMayor(eProductos vec[], eProveedor prov[], int tam)
{
    int i;

    for(i=0; i <tam; i++)
    {
        if(vec[i].isEmpty ==0)
        {
            if(vec[i].cantidad > 10)
            {
                mostarUnProducto(vec,prov,i);
            }
        }
    }
}

void productosSuperiorPromedio(eProductos vec[], eProveedor prov[], int tam)
{
    int i;
    float promedio;
    system("cls");
    printf("\nPRODUCTOS CUYO PRECIO ES SUPERIOR AL PROMEDIO: \n");

    promedio = promedioImportes(vec,tam);


    for(i=0; i<tam ;i++)
    {
        if(vec[i].isEmpty ==0)
        {
            if(vec[i].importe >= promedio)
            {
                mostarUnProducto(vec,prov,i);
            }
        }
    }
}

void productosInferiorPromedio(eProductos vec[], eProveedor prov[], int tam)
{
    int i;
    float promedio;
    system("cls");
    printf("\nPRODUCTOS CUYO PRECIO ES INFERIOR AL PROMEDIO: \n");

    promedio = promedioImportes(vec,tam);


    for(i=0; i<tam ;i++)
    {
        if(vec[i].isEmpty == 0)
        {
            if(vec[i].importe < promedio)
            {
                mostarUnProducto(vec,prov,i);
            }
        }
    }
}


int buscarMayor(eProductos vec[], int tam)
{
    int i;
    float max;
    float aux;
    int index;

    max = vec[0].importe;
    index = 0;
    for(i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            if(vec[i].importe > max)
            {
                max = vec[i].importe;
                index = i;
            }
        }
    }
    return index;
}

int buscarMenor(eProductos vec[], int tam)
{
    int i;
    float min;
    float aux;
    int index;

    min = vec[0].importe;
    index = 0;
    for(i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            if(vec[i].importe < min)
            {
                min = vec[i].importe;
                index = i;
            }
        }
    }
    return index;
}

void productoMasCaro(eProductos vec[],eProveedor prov[], int tampp, int tampv)
{
    int i;
    int index;
    float importeMax;
    system("cls");
    printf("\nPRODUCTO MAS CARO: \n");

    index = buscarMayor(vec,tampp);

    for(i=0; i<tampv; i++)
    {
        if(vec[index].proveedor == prov[i].codigo)
        {
            printf("EL MAYOR IMPORTE: %.2f\n\n",vec[index].importe);
            printf("Proveedor: %s\n",prov[i].descripcion);
            printf("%d\t %s\t\t\t %.2f\t\t %d\t %s\n",vec[index].codigoP,vec[index].descripcionP,vec[index].importe,vec[index].cantidad,prov[i].descripcion);

        }
    }
}

void productoMasBarato(eProductos vec[],eProveedor prov[], int tampp, int tampv)
{
    int i;
    int index;
    float importeMin;
    system("cls");
    printf("PRODUCTO MAS BARATO: \n");

    index = buscarMenor(vec,tampp);

    for(i=0; i<tampv; i++)
    {
        if(vec[index].proveedor == prov[i].codigo)
        {
            printf("\nEL MENOR IMPORTE: %.2f\n",vec[index].importe);
            printf("PROVEEDOR: %s",prov[i].descripcion);
            printf("\nCod: %4d %15s %8.2f %4d u. %10s\n",vec[index].codigoP,vec[index].descripcionP,vec[index].importe,vec[index].cantidad,prov[i].descripcion);
        }
    }

}

void productosDeProveedores(eProductos vec[], eProveedor prov[], int tampp, int tampv)
{
    int i;
    int j;
    system("cls");
    printf("\nPRODUCTOS POR PROVEEDOR \n");

    for(i=0; i<tampv; i++)
    {
        if(prov[i].isEmpty == 0)
        {
            printf("\n %s : \n", prov[i].descripcion);
        }

        for(j=0; j<tampp; j ++)
        {
            if(vec[j].isEmpty == 0)
            {
                if(prov[i].codigo == vec[j].proveedor)
                {
                    //soloProductos(vec,tampp,j);
                    printf("Codigo : %4d %15s %8.2f %4d unidades\n",vec[j].codigoP,vec[j].descripcionP,vec[j].importe,vec[j].cantidad);
                }
            }
        }
    }
}

void soloProductos(eProductos vec[], int tam, int index)
{
    printf("%4d %15s %8.2f %4d\n",vec[index].codigoP,vec[index].descripcionP,vec[index].importe,vec[index].cantidad);
}

void proveedorMayor(eProductos vec[],eProveedor prov[], int tampp, int tampv)
{
    int cant = 0;
    int max = -1;
    int provMax =0;
    int i;
    int j;
    system("cls");
    printf("\nPROVEEDOR CON MAYOR CANTIDAD DE PRODUCTOS \n");

    for(i=0; i<tampv; i++)
    {
        for(j=0; j<tampp; j++)
        {
            if(vec[j].isEmpty == 0)
            {
                if(prov[i].codigo == vec[j].proveedor)
                {
                    cant = vec[j].cantidad + cant;
                }
            }
        }

        if(cant>max)
        {
            max = cant;
            provMax = i;
        }

        cant = 0;
    }
    //soloProveedores(prov,provMax);
    printf("PROVEEDOR: %s \n",prov[provMax].descripcion);
}

void proveedorMenor(eProductos vec[],eProveedor prov[], int tampp, int tampv)
{
    int cant = 0;
    int min;
    int provMin =0;
    int i;
    int j;

    system("cls");
    printf("\nPROVEEDOR CON MENOR CANTIDAD DE PRODUCTOS \n");

    min = vec[0].cantidad;

    for(i=0; i<tampv; i++)
    {
        for(j=0; j<tampp; j++)
        {
            if(prov[i].codigo == vec[j].proveedor)
            {
                cant = vec[j].cantidad + cant;
            }
        }

        if(cant<=min)
        {
            min = cant;
            provMin = i;
        }
        cant = 0;
    }
    printf("\nPROVEEDOR:\n %s\n",prov[provMin].descripcion);
}

void soloProveedores(eProveedor prov[],int tampv,int index)
{
    if(prov[index].isEmpty == 0)
    {
        printf("%s\n\n",prov[index].descripcion);
    }
}

void proveedorMenorDiez(eProductos vec[], eProveedor prov[], int tampp, int tampv)
{
    int i;
    int j;
    int cant = 0;
    system("cls");
    printf("\nPROVEEDORES CON MENOS DE 10 PRODUCTOS \n");

    for(i=0; i<tampv;i++)
    {
        for(j=0; j<tampp; j++)
        {
            if(prov[i].codigo == vec[j].proveedor)
            {
                cant++;
            }
        }
        if(cant<=10)
        {
            printf("PROVEEDOR:%s \n\n ",prov[i].descripcion);
        }
    }
    cant = 0;
}
