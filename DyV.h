#ifndef DYV_H
#define DYV_H

#include <vector> // Necesario para std::vector
#include <utility> // Para poder usar std::swap
#include <stdlib.h> //para rand() (n aleatorio)
#include <time.h> // para time()

template<typename T>
int BusquedaBinaria(const T& x, const std::vector<T>& v, int ini, int fin)
{
    // --- CASO BASE (FALLO) ---
    // Si el índice inicial supera al final, el rango de búsqueda está vacío.
    // El elemento no existe.
    if (ini > fin) {
        return -1; // Valor para "no encontrado"
    }

    // --- PASO 1: DIVIDIR ---
    // Calculamos la posición media.
    int mid = ini + (fin - ini) / 2;

    // --- PASO 2: VENCER (RESOLVER) ---
    
    // Caso Base (Éxito): ¡Encontrado!
    if (v[mid] == x) {
        return mid;
    }
    
    // Caso Recursivo 1: x es más pequeño, buscar en la mitad izquierda
    else if (v[mid] > x) {
        // El nuevo rango es [ini, mid - 1]
        return BusquedaBinaria(x, v, ini, mid - 1);
    }
    
    // Caso Recursivo 2: x es más grande, buscar en la mitad derecha
    else { // v[mid] < x
        // El nuevo rango es [mid + 1, fin]
        return BusquedaBinaria(x, v, mid + 1, fin);
    }
}

template<typename T>
int BusquedaBinaria_INV(const T& x, const std::vector<T>& v, int ini, int fin)
{
    // Caso Base (Fallo): Rango vacío
    if (ini > fin) {
        return -1;
    }

    // 1. Dividir
    int mid = ini + (fin - ini) / 2;

    // 2. Vencer

    // Caso Base (Éxito): Encontrado
    if (v[mid] == x) {
        return mid;
    }

    // Si v[mid] > x, el valor x (que es más pequeño) está a la DERECHA
    else if (v[mid] > x) {
        return BusquedaBinaria_INV(x, v, mid + 1, fin);
    }

    // Si v[mid] < x, el valor x (que es más grande) está a la IZQUIERDA
    else { // v[mid] < x
        return BusquedaBinaria_INV(x, v, ini, mid - 1);
    }
}


template<typename T>
int Partition(std::vector<T>& v, int ini, int fin) {
    
    // 1. Elegir el pivote (el último elemento)
    T pivote = v[fin];
    
    // 'i' es el índice del último elemento que es <= al pivote.
    // Empieza "fuera" del sub-vector, a la izquierda.
    int i = ini - 1;

    // 2. Recorrer el sub-vector excepto el pivote
    for (int j = ini; j < fin; ++j) {
        
        // Si encontramos elemento <= al pivote...
        if (v[j] <= pivote) {
            // ...avanzar frontera 'i'
            i++;
            // ...e intercambiar el elemento v[j] para traerlo
            // a la "zona de menores" (delimitada por 'i').
	    std::swap(v[i], v[j]);
        }
    }

    // 3. colocar el pivote en su sitio.
    std::swap(v[i + 1], v[fin]);
    
    // 4. Devolver la posición final del pivote.
    return i + 1;
}


template <typename T>
void QuickSort(std::vector<T>& v, int ini, int fin){
	// --- Caso Base ---
    // Si el rango es de 0 o 1 elemento, está ordenado.
    if (ini < fin) {

        // --- 1. Dividir ---
        int pos_pivote = Partition(v, ini, fin);

        // --- 2. Vencer (Recursión) ---
	// Llamar recursivamente a QuickSort para la parte izquierda
        QuickSort(v, ini, pos_pivote - 1);

        // Llamar recursivamente a QuickSort para la parte derecha
        QuickSort(v, pos_pivote + 1, fin);
    }
}

template<typename T>
void QuickSort_PivoteIni(std::vector<T>& v, int ini, int fin){
	if(ini<fin){

	//cambiamos ini por fin para q ahora Partition coja el ini
	
	std::swap(v[ini],v[fin]);
	
	int pos_pivote = Partition(v, ini, fin);

	QuickSort_PivoteIni(v, ini, pos_pivote - 1);
	
	QuickSort_PivoteIni(v, pos_pivote + 1, fin);
	
	}
}

template<typename T>
void QuickSort_PivoteCentral(std::vector<T>& v, int ini, int fin) {
    if (ini < fin) {

        // El único cambio está aquí 
        // 1. Calculamos la posición central
        int pos_central = ini + (fin - ini) / 2;
        // 2. Intercambiamos el elemento central con el último (fin).
        std::swap(v[pos_central], v[fin]);
                
        int pos_pivote = Partition(v, ini, fin);

        
        QuickSort_PivoteCentral(v, ini, pos_pivote - 1);
        QuickSort_PivoteCentral(v, pos_pivote + 1, fin);
    }
}

template<typename T>
void QuickSort_PivoteRandom(std::vector<T>& v, int ini, int fin) {
    if (ini < fin) {

        // El único cambio está aquí
        // 1. Calculamos una posición aleatoria entre [ini, fin]
        int pos_aleatoria = ini + rand() % (fin - ini + 1);
        // 2. Intercambiamos el elemento aleatorio con el último (fin).
        std::swap(v[pos_aleatoria], v[fin]);
        
        int pos_pivote = Partition(v, ini, fin);

        QuickSort_PivoteRandom(v, ini, pos_pivote - 1);
        QuickSort_PivoteRandom(v, pos_pivote + 1, fin);
    }
}
#endif // DYV_H
