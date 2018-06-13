#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "abm.h"
#include "listados.h"

#define TAMPROV 5
#define TAMPROD 50

int main()
{
    eProductos productos[TAMPROD];
    eProveedor proveedores[TAMPROV] = { {1,"Arcor",0},
                                        {2,"Serenisima",0},
                                        {3,"Molto",0},
                                        {4,"Pepsico",0},
                                        {5,"Manaos",0}  };

    char opcion;
    int seguir = 1;

    inicializarStruct(productos,TAMPROD);

    do
    {
        MenuAbm();
        fflush(stdin);
        fflush(stdin);
        scanf("%c",&opcion);
        switch(opcion)
               {
                    case '1':
                        alta(productos,proveedores,TAMPROD);
                        system("pause");
                        system("cls");
                        break;

                    case '2':
                        Modificar(productos,proveedores,TAMPROD,TAMPROV);
                        system("pause");
                        system("cls");
                        break;

                    case '3':
                        Baja(productos,proveedores,TAMPROD);
                        system("pause");
                        system("cls");
                        break;

                    case '4':
                        informeDeImportes(productos,TAMPROD);
                        system("pause");
                        system("cls");
                        break;

                    case '5':
                        Informes(productos,proveedores,TAMPROD,TAMPROV);
                        system("pause");
                        system("cls");
                        break;

                    case '6':
                        mostrarProductos(productos,proveedores,TAMPROD,TAMPROV);
                        system("pause");
                        system("cls");
                        break;

                    case '7':
                        seguir = 0;
                        break;

                    default:
                        system("cls");
                        printf("Opcion no valida\n");
                        break;

               }

    }while(seguir == 1);


    return 0;
}
