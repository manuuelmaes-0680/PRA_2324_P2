#include <iostream>  // Para std::cout
#include <vector>    // Para std::vector
#include "DyV.h"     // Para incluir tu función BusquedaBinaria

using namespace std;


int main() {
    
    // --- Prueba 1: Vector de Enteros (int) ---
    cout << "--- Prueba con Enteros ---" << endl;
    vector<int> v_enteros = {10, 20, 30, 40, 50, 60};
    int fin_enteros = v_enteros.size() - 1;

    // Buscar el 30 (debería estar en la posición 2)
    int pos1 = BusquedaBinaria(30, v_enteros, 0, fin_enteros);
    cout << "Buscando 30: Posicion " << pos1 << endl;

    // Buscar el 35 (no existe)
    int pos2 = BusquedaBinaria(35, v_enteros, 0, fin_enteros);
    cout << "Buscando 35: Posicion " << pos2 << endl;

    // --- Prueba 2: Vector de Flotantes (float) ---
    cout << "\n--- Prueba con Flotantes ---" << endl;
    vector<float> v_flotantes = {1.1f, 2.2f, 3.3f, 4.4f};
    int fin_flotantes = v_flotantes.size() - 1;

    // Buscar 4.4 (debería estar en la posición 3)
    int pos3 = BusquedaBinaria(4.4f, v_flotantes, 0, fin_flotantes);
    cout << "Buscando 4.4: Posicion " << pos3 << endl;

    // --- Prueba 3: Vector de Caracteres (char) ---
    cout << "\n--- Prueba con Caracteres ---" << endl;
    vector<char> v_chars = {'a', 'c', 'd', 'f', 'h'};
    int fin_chars = v_chars.size() - 1;

    // Buscar 'f' (debería estar en la posición 3)
    int pos4 = BusquedaBinaria('f', v_chars, 0, fin_chars);
    cout << "Buscando 'f': Posicion " << pos4 << endl;

    // Buscar 'b' (no existe)
    int pos5 = BusquedaBinaria('b', v_chars, 0, fin_chars);
    cout << "Buscando 'b': Posicion " << pos5 << endl; // Esperado: -1
	
    cout << "\n\n--- PRUEBAS BUSQUEDA DESCENDENTE (INV) ---" << endl;

    // --- Prueba 4: Vector Inverso de Enteros (int) ---
    cout << "\n--- Prueba con Enteros (Descendente) ---" << endl;
    vector<int> v_enteros_inv = {100, 90, 80, 70, 60};
    int fin_enteros_inv = v_enteros_inv.size() - 1;

    // Buscar 70 (en medio)
    int pos6 = BusquedaBinaria_INV(70, v_enteros_inv, 0, fin_enteros_inv);
    cout << "Buscando 70: Posicion " << pos6 << endl; // Esperado: 3

    // Buscar 100 (primero)
    int pos7 = BusquedaBinaria_INV(100, v_enteros_inv, 0, fin_enteros_inv);
    cout << "Buscando 100: Posicion " << pos7 << endl; // Esperado: 0

    // Buscar 40 (no existe)
    int pos8 = BusquedaBinaria_INV(40, v_enteros_inv, 0, fin_enteros_inv);
    cout << "Buscando 40: Posicion " << pos8 << endl; // Esperado: -1

    // --- Prueba 5: Vector Inverso de Caracteres (char) ---
    cout << "\n--- Prueba con Caracteres (Descendente) ---" << endl;
    vector<char> v_chars_inv = {'z', 'x', 'w', 'v', 'a'};
    int fin_chars_inv = v_chars_inv.size() - 1;

    // Buscar 'w' (en medio)
    int pos9 = BusquedaBinaria_INV('w', v_chars_inv, 0, fin_chars_inv);
    cout << "Buscando 'w': Posicion " << pos9 << endl; // Esperado: 2

    // Buscar 'y' (no existe)
    int pos10 = BusquedaBinaria_INV('y', v_chars_inv, 0, fin_chars_inv);
    cout << "Buscando 'y': Posicion " << pos10 << endl; // Esperado: -1

    return 0;
}
