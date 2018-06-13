#ifndef ABM_H_INCLUDED
#define ABM_H_INCLUDED

typedef struct
{
    int codigo;
    char descripcion[30];
    int isEmpty;
}eProveedor;

typedef struct
{
    int codigoP;
    char descripcionP [30];
    float importe;
    int cantidad;
    int isEmpty;
    int proveedor;
}eProductos;

/** Inicializa en vacio un array de structuras
 *
 * \param array de estructuras
 * \param cantidad de elementos a trabajar
 * \return 1 en estado
 */
void inicializarStruct(eProductos vec[], int tam);

/** Busca el primer indice libre en el array de estructuras
 *
 * \param  comienzo del array de estructuras
 * \param cantidad de elementos a trabajar
 * \return -1 si esta lleno, o el indice del primer elemento libre
 */
int buscarLibre(eProductos vec[], int tam);

/** Compara los nuemero identificadores cargados con lo ingesado por teclado
 *
 * \param  comienzo del array de estructuras
 * \param cantidad de elementos a trabajar
 * \return -1 si no existe, el indice si donde esta cargado si lo encuentra
 *
 */
int buscarProducto(eProductos vec[], int tam, int codigo);

/** Valida si el nuemuero es entero
 *
 * \param cadena de caracteres
 * \return 1 si lo es, 0 si no
 */
int ValueInt(char aux[25]);


/** \brief Imprime un menu de opciones por consola
 */
void MenuAbm();

/** Da de alta a un elemento de manera aleatoria de tipo structura, cargandolo de datos
 *
 * \param array de estructura 1
 * \param array de estructura 2
 * \param cantidad de elementos de la estructura 1
 * \return un elemento de array de estructura cargado
 *
 */
void alta(eProductos vec[],eProveedor prov[], int tam);

/** \brief Muestra los elementos del array 2 de estructuras con elementos relacionados
 *
 * \param comienzo del array de estructuras 1
 * \param comienzo del array de estucturas 2
 * \return
 *
 */
void MostrarProveedor(eProveedor prov[], int tam);

/** \brief imprime por consola  todos los elementos cargados en una estructura
 *
 * \param comienzo del array de estructuras
 * \param cantidad de elementos a trabajar
 * \return
 *
 */
void mostrarProductos(eProductos vec[],eProveedor prov[],int tamPTO, int tamPV);

/** \brief Elimina logicamente un elemento del tipo estructura cargado en un array
 *
 * \param comienzo del array de estructuras 1
 * \param comienzo del array de estructuras 2
 * \param cantidad de elementos a trabajar en array 1
 * \param cantidad de elementos a trabajar en array 1
 * \return
 *
 */
void Baja(eProductos vec[],eProveedor prov[], int tam);

/** \brief Muestra un solo elemento del array de estructuras
 *
 * \param comienzo del array de estructuras 1
 * \param comienzo del array de estructuras 2
 * \param posicion del elemento deseado dentro del array
 * \return
 *
 */
void mostarUnProducto(eProductos vec[],eProveedor prov[],int pos);

/** \brief Modifica los datos cargados en los campos de un tipo de dato estructura a elegir
 *
 * \param comienzo del array de estructuras 1
 * \param comienzo del array de estructuras 2
* \param posicion del elemento deseado dentro del array
 * \return
 *
 */
void Modificar(eProductos vec[], eProveedor prov[],int tamProducto, int tamProveedor);

/** \brief Valida que la parte entera un numero
 *
 * \param numero a verificar
 * \return 0 si no se verifica, 1 si es un entero
 *
 */
int ValidarEntero(float numero);

#endif // ABM_H_INCLUDED
