#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1. Función para llenar matrices 3x3 con valores aleatorios
void llenarMatriz(int (*matriz)[3]) {
    int *ptr = &matriz[0][0];
    for(int i = 0; i < 9; i++) {
        *ptr++ = rand() % 10;
    }
}

// 2. Función para multiplicar matrices 3x3
void multiplicarMatrices(int (*A)[3], int (*B)[3], int (*resultado)[3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            *(*(resultado + i) + j) = 0;
            for(int k = 0; k < 3; k++) {
                *(*(resultado + i) + j) += *(*(A + i) + k) * *(*(B + k) + j);
            }
        }
    }
}

// 3. Función para llenar matriz 3D con las 3 matrices
void llenarArray3D(int (*array3D)[3][3], int (*matrizA)[3], int (*matrizB)[3], int (*resultado)[3]) {
    int (*Capa0)[3] = array3D[0];
    int (*Capa1)[3] = array3D[1];
    int (*Capa2)[3] = array3D[2];
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            *(*(Capa0 + i) + j) = *(*(matrizA + i) + j);
            *(*(Capa1 + i) + j) = *(*(matrizB + i) + j);
            *(*(Capa2 + i) + j) = *(*(resultado + i) + j);
        }
    }
}

int main() {
    srand(time(NULL));

    // Reservar memoria
    int (*matrizA)[3] = new int[3][3];
    int (*matrizB)[3] = new int[3][3];
    int (*resultado)[3] = new int[3][3];
    int (*array3D)[3][3] = new int[3][3][3];

    // Llenar matrices
    llenarMatriz(matrizA);
    llenarMatriz(matrizB);
    
    // Multiplicar matrices
    multiplicarMatrices(matrizA, matrizB, resultado);
    
    // Llenar array 3D
    llenarArray3D(array3D, matrizA, matrizB, resultado);

    // Impresión (se mantiene igual)
    cout << "Matriz A:" << endl;
    int (*A)[3] = array3D[0];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << *(*(A + i) + j) << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Matriz B:" << endl;
    int (*B)[3] = array3D[1];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << *(*(B + i) + j) << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Resultado de multiplicación:" << endl;
    int (*Res)[3] = array3D[2];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << *(*(Res + i) + j) << " ";
        }
        cout << endl;
    }

    // Liberar memoria
    delete[] matrizA;
    delete[] matrizB;
    delete[] resultado;
    delete[] array3D;

    return 0;
}
