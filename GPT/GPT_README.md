# Ejercicios GPT

> [!IMPORTANT]
> Ten en cuenta que estos ejercicios han sido propuestos por ChatGPT, **no son ejercicios de convocatorias oficiales**.

---

## Ejercicios

### 1. Insertar nodo en una lista enlazada

- [x] Escribe una función para insertar un nodo en una lista enlazada simple en una posición específica. La función debe tener la siguiente cabecera:

```cpp
  template <class T>
  void insert_at(sll_t<T>& list, sll_node_t<T>* new_node, int position);
```

### 2. Recorrer una matriz en espiral

- [ ] Escribe una función que recorra una matriz en espiral y devuelva los elementos en un vector. La función debe tener la siguiente cabecera:

```cpp
  template <class T>
  vector<T> spiral_traverse(const matrix_t<T>& matrix);
```

### 3. Fusionar dos listas dobles

- [ ] Escribe una función que fusione dos listas dobles ordenadas en una nueva lista doble ordenada. La función debe tener la siguiente cabecera:

```cpp
  template <class T>
  dll_t<T> merge_dll(const dll_t<T>& list1, const dll_t<T>& list2);
```

### 4. Invertir un vector usando recursión

- [ ] Escribe una función recursiva que invierta un vector. La función debe tener la siguiente cabecera:

```cpp
  template <class T>
  void reverse_vector(vector_t<T>& vec, int start = 0);
```

### 5. Comprobar balanceo de paréntesis

- [ ] Escribe una función que compruebe si una cadena de caracteres tiene los paréntesis balanceados. La función debe tener la siguiente cabecera:

```cpp
  bool is_balanced(const string& expression);
```

### 6. Algoritmo de la Mochila (0/1 Knapsack)

- [ ] Escribe una función que resuelva el problema de la mochila utilizando programación dinámica. La función debe tener la siguiente cabecera:

```cpp
  int knapsack(const vector<int>& weights, const vector<int>& values, int max_weight);
```

### 7. Búsqueda binaria en un vector de pares

- [ ] Escribe una función que realice una búsqueda binaria en un vector de pares `(clave, valor)` y devuelva el valor correspondiente a la clave buscada. La función debe tener la siguiente cabecera:

```cpp
  template <class T, class U>
  U binary_search(const vector<pair<T, U>>& vec, const T& key);
```

### 8. Generar permutaciones de un vector

- [ ] Escribe una función recursiva que genere todas las permutaciones de un vector. La función debe tener la siguiente cabecera:

```cpp
  template <class T>
  void generate_permutations(vector_t<T>& vec, int start = 0);
