#ifndef LISTADOS_H_INCLUDED
#define LISTADOS_H_INCLUDED

/** \brief
 *
 * \param comienzo del array de estructuras 1
 * \param comienzo del array de estructuras 2
 * \param cantidad de elementos conscutivos que se trabajan del array 1
 * \return
 *
 */
void Informes(eProductos vec[],eProveedor prov[],int tampp, int tampv);

/** \brief imprime por consola un menu con las opciones a mostrar
 *
 */
void menuInformes();

/** \brief imprime por consola importes y promedios
 * \param comienzo del array de estructuras
 * \param cantidad de elementos conscutivos que se trabajan del array
 * \return
 *
 */
void informeDeImportes(eProductos vec[],int tam);

/** \brief suma mediante acumuladores elementos del tipo int cargados en una estructura
 *
 * \param comienzo del array de estructuras
 * \param cantidad de elementos conscutivos que se trabajan del array
 *
 * \return la cantidad total acumulada
 */
float sumaImportes(eProductos vec[], int tam);

/** \brief cuenta la cantidad de elementos iguales cargados dentro de un tipo de dato estructura
 *
 * \param comienzo del array de estructuras
 * \param cantidad de elementos conscutivos que se trabajan del array
 *
 * \return la cantidad total contada
 */
float contador(eProductos vec[], int tam);

/** \brief realiza la operacion promedio entre una variable contadora y otra acumuladora dentro de los elementos de un array
 *
 * \param comienzo del array de estructuras
 * \param cantidad de elementos conscutivos que se trabajan del array
 *
 * \return el promedio obtenido
 */
float promedioImportes(eProductos vec[], int tam);

/** \brief muestra los elementos cargados cuya cantidad es <10 dentro de un mismo elemento en un array de estructuras
 *
 * \param comienzo del array de estructuras 1
 * \param comienzo del array de estructuras 2
 * \param cantidad de elementos conscutivos que se trabajan del array 1
 *
 * \return
 */
void ordenCantidadMenor(eProductos vec[], eProveedor prov[], int tam);

/** \brief muestra los elementos cargados cuya cantidad es >10 dentro de un mismo elemento en un array de estructuras
 *
 * \param comienzo del array de estructuras 1
 * \param comienzo del array de estructuras 2
 * \param cantidad de elementos conscutivos que se trabajan del array 1
 *
 */
void ordenCantidadMayor(eProductos vec[], eProveedor prov[], int tam);


/** \brief muestra los elementos cuyos datos son superiores a una cantidad determinada
 *
 * \param comienzo del array de estructuras 1
 * \param comienzo del array de estructuras 2
 * \param cantidad de elementos conscutivos que se trabajan del array 1
 *
 */
void productosSuperiorPromedio(eProductos vec[], eProveedor prov[], int tam);

/** \brief muestra los elementos cuyos datos son inferiores a una cantidad determinada
 *
 * \param comienzo del array de estructuras 1
 * \param comienzo del array de estructuras 2
 * \param cantidad de elementos conscutivos que se trabajan del array 1
 *
 */
void productosInferiorPromedio(eProductos vec[], eProveedor prov[], int tam);


/** \brief Busca el elemento cargado dentro de un dato estructural que sea el mayor dentro de todo el array de ese mismo tipo
 *
 * \param comienzo del array de estructuras 1
 * \param cantidad de elementos conscutivos que se trabajan del array 1
 *
 * \return el indice donde se encuentra ese elemento
 */
int buscarMayor(eProductos vec[], int tam);


/** \brief Busca el elemento cargado dentro de un dato estructural que sea el menor dentro de todo el array de ese mismo tipo
 *
 * \param comienzo del array de estructuras 1
 * \param cantidad de elementos conscutivos que se trabajan del array 1
 *
 * \return el indice donde se encuentra ese elemento
 */
int buscarMenor(eProductos vec[], int tam);

/** \brief Imprime el elemento cargado dentro de un dato estructural que sea el mayor dentro de todo el array de ese mismo tipo
 *
 * \param comienzo del array de estructuras 1
 * \param comienzo del array de estructuras 2
 * \param cantidad de elementos conscutivos que se trabajan del array 1
 * \param cantidad de elementos conscutivos que se trabajan del array 2
 */
void productoMasCaro(eProductos vec[],eProveedor prov[], int tampp, int tampv);

/** \brief Muestra los elementos relacionados a una estructura mediante la eleccion del elemento por parte del usuario
 *
 * \param comienzo del array de estructuras 1
 * \param comienzo del array de estructuras 2
 * \param cantidad de elementos conscutivos que se trabajan del array 1
 * \param cantidad de elementos conscutivos que se trabajan del array 2
 *
 */
void mostrarProductosXproveedor(eProductos vec[],eProveedor prov[],int tampp, int tampv);

/** \brief muestra los elementos numericos cargados en un array de estructuras ordenados segun un criterio
 *
 * \param comienzo del array de estructuras 1
 * \param comienzo del array de estructuras 2
 * \param cantidad de elementos conscutivos que se trabajan del array 1
 * \param criterio: 0 ascendente; 1 descendente
 *
 */
void ordenarNumeros(eProductos vec[],eProveedor prov[],int tam, int criterio);

/** \brief muestra los elementos string cargados en un array de estructuras ordenados segun un criterio alfabetico
 *
 * \param comienzo del array de estructuras 1
 * \param comienzo del array de estructuras 2
 * \param cantidad de elementos conscutivos que se trabajan del array 1
 * \param criterio de ordenamiento 0 para ascendente; 1 descendente
 *
 */
void ordenarCadenas(eProductos vec[],eProveedor prov[],int tam, int criterio);

/** \brief gestiona el ordenamiento de un array de estructuras, encapsula funciones
 *
 * \param comienzo del array de estructuras 1
 * \param comienzo del array de estructuras 2
 * \param cantidad de elementos conscutivos que se trabajan del array 1
 *
 */
void ordenamientosPuntoA(eProductos vec[],eProveedor prov[],int tam);

/** \brief imprime por cosola solo un campo del tipo de dato structural
 *
 * \param comienzo del array de estructuras 1
 * \param comienzo del array de estructuras 2
 * \param cantidad de elementos conscutivos que se trabajan del array 1
 *
 */
void soloProductos(eProductos vec[], int tam, int index);

/** \brief imprime por cosola el elemento del array cuyo campo a comprar es mayor que los demas
 *
 * \param comienzo del array de estructuras 1
 * \param comienzo del array de estructuras 2
 * \param cantidad de elementos conscutivos que se trabajan del array 1
 * \param cantidad de elementos conscutivos que se trabajan del array 2
 *
 */
void proveedorMayor(eProductos vec[],eProveedor prov[], int tampp, int tampv);


/** \brief imprime por cosola el elemento del array cuyo campo a comprar es menor que los demas
 *
 * \param comienzo del array de estructuras 1
 * \param comienzo del array de estructuras 2
 * \param cantidad de elementos conscutivos que se trabajan del array 1
 * \param cantidad de elementos conscutivos que se trabajan del array 2
 *
 */
void proveedorMenor(eProductos vec[],eProveedor prov[], int tampp, int tampv);

/** \brief imprime por cosola el elemento del array cuyo campo a comprar es mayor que los demas
 *
 * \param comienzo del array de estructuras 1
 * \param comienzo del array de estructuras 2
 * \param cantidad de elementos conscutivos que se trabajan del array 1
 * \param cantidad de elementos conscutivos que se trabajan del array 2
 *
 */
void productoMasCaro(eProductos vec[],eProveedor prov[], int tampp, int tampv);

/** \brief imprime por cosola el elemento del array cuyo campo a comprar es menor que los demas
 *
 * \param comienzo del array de estructuras 1
 * \param comienzo del array de estructuras 2
 * \param cantidad de elementos conscutivos que se trabajan del array 1
 * \param cantidad de elementos conscutivos que se trabajan del array 2
 *
 */
void productoMasBarato(eProductos vec[],eProveedor prov[], int tampp, int tampv);


/** \brief imprime por cosola los elementos del array que cumplay con el criterio de tener menos de 10 datos
 *
 * \param comienzo del array de estructuras 1
 * \param comienzo del array de estructuras 2
 * \param cantidad de elementos conscutivos que se trabajan del array 1
 * \param cantidad de elementos conscutivos que se trabajan del array 2
 * \return
 *
 */
void proveedorMenorDiez(eProductos vec[], eProveedor prov[], int tampp, int tampv);

#endif // LISTADOS_H_INCLUDED


