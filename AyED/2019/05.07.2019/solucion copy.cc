#include <iostream>
#include <cmath>
using namespace std;

// 1. Considérese el tipo de datos matrix_t definido anteriormente. Considérese también que el objeto invocado es una matriz cuadrada de elementos tipo double. Impleméntese cuatro métodos que sumen los elementos de las siguientes submatrices, recorriendo únicamente la submatriz especificada.

// (a) (0.5) Submatriz triangular superior incluyendo la diagonal principal.


// (b) (0.5) Submatriz triangular superior sin incluir la diagonal principal 


// (c) (0.5) Submatriz triangular inferior incluyendo la diagonal principal.


// d) (0.5) Submatriz triangular inferior sin incluir la diagonal principal.


// 2. (1.0) Considérese un vector de números enteros v, definido por los extremos i (izquierdo) y d (derecho). Como premisa sabemos que los elementos de v están ordenados en orden no decreciente. Se desea obtener la posición de una ocurrencia del valor x dentro del vector. Impleméntese una función que efectúe una búsqueda binaria recursiva en un vector ordenado, y que devuelva la posición de una ocurrencia del elemento buscado, o -1 en caso de no encontrarse.


// 3. (1.0) Considérese un vector de números enteros v, definido por los extremos i (izquierdo) y d (derecho). Los elementos del vector no siguen ningún orden. Se desea obtener la posición de una ocurrencia del valor x dentro del vector. Impleméntese una función que efectúe una búsqueda binaria recursiva, y que devuelva la posición de una ocurrencia del elemento buscado, o -1 en caso de no encontrarse.


// 4. (1.0) Considérese la clase sll_t. Impleméntese un procedimiento recursivo que imprima los elementos de la lista simplemente enlazada en orden inverso. Con este fin, el método debe recibir como parámetro un puntero a un nodo, y un stream de salida. Este método debe comprobar si el nodo es nulo o no. En caso de que fuera nulo debe retornar, si no es nulo, debe llamarse nuevamente con el nodo siguiente, e imprimir el contenido del nodo.

// 5. La función que calcula el número de pasos totales en el problema de las Torres de Hanoi se define como:

// (a) Desarrollar la función recursiva: unsigned int hanoi(unsigned int i)

// 6. Sobre la clase sll_t, desarrollar los siguientes apartados:
// (a) (0.8) Fusión en orden ascendente de dos listas ordenadas, cuyo resultado se almacena en el objeto que invoca al método:
// void sll_t<T>::fusion_asc(sll_t<T>& a, sll_t<T>&b)
// Por ejemplo, si A=1→3→5→7, y B=2→4→6, la llamada a C.fusion_asc(A, B) daría como resultado: C=1→2→3→4→5→6→7


// (b) (1.2) ¿Qué código habría que añadir al desarrollado en (a) para poder hacer una fusión en orden descendente? ¿Usarías algún TAD auxiliar? En tal caso, ¿cuál sería? Añadir el código necesario para hacer dicha fusión en orden descendente para crear el siguiente método:

// void sll_t<T>::fusion_desc(sll_t<T>& a, sll_t<T>&b)

// Usando las listas del ejemplo anterior, una llamada a C.fusion_desc(A, B) daría como resultado: C=7→6→5→4→3→2→1

// Respuesta: No habría que añadir ningún código adicional, más bien habría que quitar la pila que se usa en (a). No habría que usar ninguna TAD auxiliar porque el orden descendente se consigue simplemente usando el insert_head del objeto invocante.

// 7. (2.0) Desarrollar el producto escalar recursivo de un vector disperso invocante por otro vector denso pasado por parámetro. La cabecera del método sería:

// double sparse_vector_t::scal_prod(const vector_t<double>& b, const int i = 0);

// Pista: usar el parámetro i que por defecto empieza en 0.