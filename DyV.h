#ifndef DYV_H
#define DYV_H

#include <vector> // Necesario para std::vector

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
#endif // DYV_H
