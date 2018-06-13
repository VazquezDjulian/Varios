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
 * \param cantidad
 * \return 1 en estado
 */
void inicializarStruct(eProductos vec[], int tam);

/** Busca el primer indice libre en el array de estructuras
 *
 * \param array de estructuras
 * \param cantidad
 * \return -1 si esta lleno, o el indice del primer elemento libre
 */
int buscarLibre(eProductos vec[], int tam);

/** Compara los nuemero identificadores cargados con lo ingesado por teclado
 *
 * array de estructuras
 * cantidad
 * \return -1 si no existe, el indice si donde esta cargado si lo encuentra
 *
 */
int buscarProducto(eProductos vec[], int tam, int codigo);

/** Valida si el nuemuero es entero
 *
 * \param cadena de caracteres
 * \1 si lo es, 0 si no
 *
 */
int ValueInt(char aux[25]);

void MenuAbm();

/** Da de alta a un elemento de manera aleatoria de tipo structura, cargandolo de datos
 *
 * \param array de estructura principal
 * \param array de estructura secundaria
 * \param cantidad de elementos de la estructura principal
 * \return un elemento de array de estructura cargado
 *
 */
void alta(eProductos vec[],eProveedor prov[], int tam);
void MostrarProveedor(eProveedor prov[], int tam);
void mostrarProductos(eProductos vec[],eProveedor prov[],int tamPTO, int tamPV);
void Baja(eProductos vec[],eProveedor prov[], int tam);
void mostarUnProducto(eProductos vec[],eProveedor prov[],int pos);
void Modificar(eProductos vec[], eProveedor prov[],int tamProducto, int tamProveedor);
int ValidarEntero(float numero);

#endif // ABM_H_INCLUDED
