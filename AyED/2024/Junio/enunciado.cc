#include <iostream>
#include <vector>
#include <cassert>

#include "../vector_t.h"
#include "../sll_node_t.h"
#include "../sll_t.h"
#include "../vector_t.h"
#include "../matrix_t.h"
#include "../queue_l_t.h"
#include "../stack_l_t.h"
#include "../stack_v_t.h"

// 1. Desarrollar el destructor de la lista sll_t de forma recursiva implementando un método privado void sll_t<T>::destroy_(sll_node_t<T>*) que será llamado por el destructor:
// 2. Dentro de la clase sll_t<T>, desarrollar de forma recursiva el siguiente método que invierte los elementos sobre la misma lista, sin usar estructuras auxiliares. Por ejemplo, dada la lista [1]→[2]→[3]→[4]–||, el resultado esperado sería [4]→[3]→[2]→[1]–||.
// 3. Desarrollar el procedimiento que sume dos números enteros positivos representados en las listas A y B de la clase dll_t<unsigned>, y devuelva el resultado en la lista C. Por ejemplo:
// 4. Considérese el problema de determinar si una cadena de paréntesis, corchetes y llaves está o no balanceada. Impleméntese una función booleana que determine si una cadena de caracteres, en términos de un tipo string o un vector de caracteres, conteniendo únicamente los símbolos ()[]{} está balanceada o no. Para tal fin, debe hacerse uso de una estructura de datos con organización LIFO.
// 5. Impleméntese el método int rsearch(int i, int d, const T& x) de la clase vector_t anteriormente especificada, que efectúa la búsqueda lineal recursiva en un vector no ordenado, devolviendo la posición del elemento encontrado y -1 si no lo encuentra.
// 6. Diseñar e implementar una clase, que denominaremos vector_t, que simule el comportamiento de un vector, del tipo especificado por una plantilla, indexado dentro del rango especificado en la definición del objeto. En el siguiente ejemplo se puede apreciar la creación de los objetos v y w, indexados en los rangos especificados en el constructor.

// a) Diseñe la clase vector_t, a partir de los atributos necesarios para el almacenamiento de los datos y el acceso correcto a los mismos utilizando los índices en el rango apropiado.

// b) Implemente el constructor, el método constante size(), que devuelve el tamaño del vector, la función de acceso at(i), que devuelve una referencia al elemento correspondiente al índice i.

// c) Implemente el método void suma(const vector_t<T> &v, const vector_t<T> &w), que hace que el vector invocante contenga la suma de los dos vectores pasado por parámetro. Nótese que dicho vector invocante deberá ser redimensionado al rango apropiado.
