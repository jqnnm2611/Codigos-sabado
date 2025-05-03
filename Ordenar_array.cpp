#include <iostream>
using namespace std;

void ordenar_mitad(int* inicio, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if(inicio[i] > inicio[j]) {
                swap(inicio[i], inicio[j]);
            }
        }
    }
}

void ordenar(int* inicio_par, int* inicio_impar) {
    int size_par = inicio_impar - inicio_par;
    int size_impar = size_par;
    
    bool hubo_cambio;
    do {
        ordenar_mitad(inicio_par, size_par);
        ordenar_mitad(inicio_impar, size_impar);
        
        int max_par = inicio_par[size_par - 1];
        int min_impar = inicio_impar[0];
        
        hubo_cambio = false;
        
        if(max_par > min_impar) {
            swap(inicio_par[size_par - 1], inicio_impar[0]);
            hubo_cambio = true;
        }
        
    } while(hubo_cambio);
}

int main() {
    int A[] = {2, 42, 18, 57, 1, 23};
    int n = sizeof(A) / sizeof(A[0]);

    int* inicio_par = A;
    int* inicio_impar = A + n/2;

    cout << "Array inicial: {";
    for(int i = 0; i < n; i++) {
        if(i > 0) cout << ", ";
        cout << A[i];
    }
    cout << "}" << endl;

    ordenar(inicio_par, inicio_impar);

    cout << "Array ordenado: {";
    for(int i = 0; i < n; i++) {
        if(i > 0) cout << ", ";
        cout << A[i];
    }
    cout << "}" << endl;

    return 0;
}
