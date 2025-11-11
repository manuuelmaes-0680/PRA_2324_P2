#include <iostream>  // Para std::cout
#include <vector>    // Para std::vector
#include "DyV.h"     // Para incluir tu función BusquedaBinaria
#include <chrono>	// Para medir el tiempo
#include <stdlib.h>	//para srand
#include <time.h>	//para time


using namespace std;


template<typename T>
void imprimirVector(const std::string& mensaje, const std::vector<T>& v) {
    std::cout << mensaje << "{ ";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << (i < v.size() - 1 ? ", " : "");
    }
    std::cout << " }" << std::endl;
}



int main() {
	srand(time(NULL));
    
    // --- Prueba 1: Vector de Enteros (int) ---
    cout << " Prueba con Enteros " << endl;
    vector<int> v_enteros = {10, 20, 30, 40, 50, 60};
    imprimirVector("Vector de busqueda: ", v_enteros);
    int fin_enteros = v_enteros.size() - 1;

    int pos1 = BusquedaBinaria(30, v_enteros, 0, fin_enteros);
    cout << "Buscando 30: Posicion " << pos1 << endl;

    int pos2 = BusquedaBinaria(35, v_enteros, 0, fin_enteros);
    cout << "Buscando 35: Posicion " << pos2 << endl;

    // --- Prueba 2: Vector de Flotantes (float) ---
    cout << "\n Prueba con Flotantes " << endl;
    vector<float> v_flotantes = {1.1f, 2.2f, 3.3f, 4.4f};
    imprimirVector("Vector de busqueda: ", v_flotantes);
    int fin_flotantes = v_flotantes.size() - 1;

    int pos3 = BusquedaBinaria(4.4f, v_flotantes, 0, fin_flotantes);
    cout << "Buscando 4.4: Posicion " << pos3 << endl;

    //  Prueba 3: Vector de Caracteres (char) 
    cout << "\n Prueba con Caracteres " << endl;
    vector<char> v_chars = {'a', 'c', 'd', 'f', 'h'};
    imprimirVector("Vectro de busqueda: ", v_chars);
    int fin_chars = v_chars.size() - 1;

    int pos4 = BusquedaBinaria('f', v_chars, 0, fin_chars);
    cout << "Buscando 'f': Posicion " << pos4 << endl;

    int pos5 = BusquedaBinaria('b', v_chars, 0, fin_chars);
    cout << "Buscando 'b': Posicion " << pos5 << endl;
	
    cout << "\n\n--- PRUEBAS BUSQUEDA DESCENDENTE (INV) ---" << endl;

    // --- Prueba 4: Vector Inverso de Enteros (int) ---
    cout << "\n Prueba con Enteros (Descendente) " << endl;
    vector<int> v_enteros_inv = {100, 90, 80, 70, 60};
    imprimirVector("Vector de busqueda: ", v_enteros_inv);
    int fin_enteros_inv = v_enteros_inv.size() - 1;

    int pos6 = BusquedaBinaria_INV(70, v_enteros_inv, 0, fin_enteros_inv);
    cout << "Buscando 70: Posicion " << pos6 << endl;

    int pos7 = BusquedaBinaria_INV(100, v_enteros_inv, 0, fin_enteros_inv);
    cout << "Buscando 100: Posicion " << pos7 << endl;

    int pos8 = BusquedaBinaria_INV(40, v_enteros_inv, 0, fin_enteros_inv);
    cout << "Buscando 40: Posicion " << pos8 << endl;

    // --- Prueba 5: Vector Inverso de Caracteres (char) ---
    cout << "\n Prueba con Caracteres (Descendente) " << endl;
    vector<char> v_chars_inv = {'z', 'x', 'w', 'v', 'a'};
    imprimirVector("Vector: ", v_chars_inv);
    int fin_chars_inv = v_chars_inv.size() - 1;

    int pos9 = BusquedaBinaria_INV('w', v_chars_inv, 0, fin_chars_inv);
    cout << "Buscando 'w': Posicion " << pos9 << endl; // Esperado: 2

    int pos10 = BusquedaBinaria_INV('y', v_chars_inv, 0, fin_chars_inv);
    cout << "Buscando 'y': Posicion " << pos10 << endl; // Esperado: -1

    

    //--- PRUEBAS QUICKSORT ---



    // --- Prueba 1: Vector de Enteros (int) ---
    cout << "\nPruebas de QuickSort" << endl;
    vector<int> v_int_qs = {56, 12, 91, 2, 38, 23, 72, 8, 16, 5};
    
    cout << "Vector (Antes):  { ";
    for (size_t i = 0; i < v_int_qs.size(); ++i) {
        cout << v_int_qs[i] << (i < v_int_qs.size() - 1 ? ", " : "");
    }
    cout << " }" << endl;
   
    QuickSort(v_int_qs, 0, v_int_qs.size() - 1);
    
    cout << "Vector (Despues): { ";
    for (size_t i = 0; i < v_int_qs.size(); ++i) {
        cout << v_int_qs[i] << (i < v_int_qs.size() - 1 ? ", " : "");
    }
    cout << " }" << endl;


    // --- Prueba 2: Vector de Flotantes (float) ---
    vector<float> v_float_qs = {9.81f, 3.14f, 1.1f, 100.2f, 2.5f};
    
    cout << "Vector (Antes):  { ";
    for (size_t i = 0; i < v_float_qs.size(); ++i) {
        cout << v_float_qs[i] << (i < v_float_qs.size() - 1 ? ", " : "");
    }
    cout << " }" << endl;

    QuickSort(v_float_qs, 0, v_float_qs.size() - 1);
    
    cout << "Vector (Despues): { ";
    for (size_t i = 0; i < v_float_qs.size(); ++i) {
        cout << v_float_qs[i] << (i < v_float_qs.size() - 1 ? ", " : "");
    }
    cout << " }" << endl;


    // --- Prueba 3: Vector de Caracteres (char) ---
    
    vector<char> v_char_qs = {'z', 'f', 'h', 'a', 'k', 'c', 'd'};
    
    
    cout << "Vector (Antes):  { ";
    for (size_t i = 0; i < v_char_qs.size(); ++i) {
        cout << v_char_qs[i] << (i < v_char_qs.size() - 1 ? ", " : "");
    }
    cout << " }" << endl;

    QuickSort(v_char_qs, 0, v_char_qs.size() - 1);
    
    
    cout << "Vector (Despues): { ";
    for (size_t i = 0; i < v_char_qs.size(); ++i) {
        cout << v_char_qs[i] << (i < v_char_qs.size() - 1 ? ", " : "");
    }
    cout << " }" << endl;

    //PRUEBAS (Tiempos de QuickSort)

    cout << "\n\n PRUEBAS DE TIEMPO QUICKSORT " << endl;

    vector<int> v_maestro = {56, 12, 91, 2, 38, 23, 72, 8, 16, 5, 88, 65, 3, 29, 50};
    imprimirVector("Vector maestro (desordenado): ", v_maestro);
    cout << "Probando con " << v_maestro.size() << " elementos..." << endl;

    vector<int> v_copia;
    
    chrono::duration<float, milli> duration; 

    // PRUEBA 1: QuickSort (Pivote Final)
    cout << "\n1. QuickSort (Pivote Final):" << endl;
    v_copia = v_maestro; 
    auto start1 = chrono::system_clock::now(); 
    
    QuickSort(v_copia, 0, v_copia.size() - 1);
    
    auto end1 = chrono::system_clock::now(); 
    duration = end1 - start1; // 
    imprimirVector("   Resultado: ", v_copia);
    cout << "   Tiempo: " << duration.count() << " ms" << endl;

    // --- PRUEBA 2: QuickSort_FirstPivot (Pivote Inicial) ---
    cout << "\n2. QuickSort (Pivote Inicial):" << endl;
    v_copia = v_maestro; // Reiniciamos la copia
    auto start2 = chrono::system_clock::now();
    
    QuickSort_PivoteIni(v_copia, 0, v_copia.size() - 1);
    
    auto end2 = chrono::system_clock::now();
    duration = end2 - start2;
    imprimirVector("   Resultado: ", v_copia);
    cout << "   Tiempo: " << duration.count() << " ms" << endl;

    // --- PRUEBA 3: QuickSort_CentralPivot (Pivote Central) ---
    cout << "\n3. QuickSort (Pivote Central):" << endl;
    v_copia = v_maestro; // Reiniciamos la copia
    auto start3 = chrono::system_clock::now();
    
    QuickSort_PivoteCentral(v_copia, 0, v_copia.size() - 1);
    
    auto end3 = chrono::system_clock::now();
    duration = end3 - start3;
    imprimirVector("   Resultado: ", v_copia);
    cout << "   Tiempo: " << duration.count() << " ms" << endl;

    // --- PRUEBA 4: QuickSort_RandomPivot (Pivote Aleatorio) ---
    cout << "\n4. QuickSort (Pivote Aleatorio):" << endl;
    v_copia = v_maestro;
    auto start4 = chrono::system_clock::now();
    
    QuickSort_PivoteRandom(v_copia, 0, v_copia.size() - 1);
    
    auto end4 = chrono::system_clock::now();
    duration = end4 - start4;
    imprimirVector("   Resultado: ", v_copia);
    cout << "   Tiempo: " << duration.count() << " ms" << endl;

    return 0;
}
