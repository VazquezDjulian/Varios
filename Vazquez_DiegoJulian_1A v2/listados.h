#ifndef LISTADOS_H_INCLUDED
#define LISTADOS_H_INCLUDED

void Informes(eProductos vec[],eProveedor prov[],int tampp, int tampv);
void menuInformes();

void informeDeImportes(eProductos vec[],int tam);
float sumaImportes(eProductos vec[], int tam);
float contador(eProductos vec[], int tam);
float promedioImportes(eProductos vec[], int tam);

void ordenCantidadMenor(eProductos vec[], eProveedor prov[], int tam);
void ordenCantidadMayor(eProductos vec[], eProveedor prov[], int tam);

void productosSuperiorPromedio(eProductos vec[], eProveedor prov[], int tam);
void productosInferiorPromedio(eProductos vec[], eProveedor prov[], int tam);

int buscarMayor(eProductos vec[], int tam);
void productoMasCaro(eProductos vec[],eProveedor prov[], int tampp, int tampv);

void mostrarProductosXproveedor(eProductos vec[],eProveedor prov[],int tampp, int tampv);
void ordenarNumeros(eProductos vec[],eProveedor prov[],int tam, int criterio);
void ordenarCadenas(eProductos vec[],eProveedor prov[],int tam, int criterio);
void ordenamientosPuntoA(eProductos vec[],eProveedor prov[],int tam);

void soloProductos(eProductos vec[], int tam, int index);
void proveedorMayor(eProductos vec[],eProveedor prov[], int tampp, int tampv);

int buscarMenor(eProductos vec[], int tam);

void proveedorMenor(eProductos vec[],eProveedor prov[], int tampp, int tampv);

void productoMasCaro(eProductos vec[],eProveedor prov[], int tampp, int tampv);
void productoMasBarato(eProductos vec[],eProveedor prov[], int tampp, int tampv);

void proveedorMenorDiez(eProductos vec[], eProveedor prov[], int tampp, int tampv);

#endif // LISTADOS_H_INCLUDED
