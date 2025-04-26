#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL));

    int (*matrizA)[3] = new int[3][3];
    int (*matrizB)[3] = new int[3][3];
    int (*resultado)[3] = new int[3][3];

    int *llenar = &matrizA[0][0];
    for(int i = 0; i < 9; i++) {
        *llenar++ = rand() % 10;
    }
    
    llenar = &matrizB[0][0];
    for(int i = 0; i < 9; i++) {
        *llenar++ = rand() % 10;
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            *(*(resultado + i) + j) = 0;
            for(int k = 0; k < 3; k++) {
                *(*(resultado + i) + j) += *(*(matrizA + i) + k) * *(*(matrizB + k) + j);
            }
        }
    }

    int (*array3D)[3][3] = new int[3][3][3];

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

    delete[] matrizA;
    delete[] matrizB;
    delete[] resultado;
    delete[] array3D;

    return 0;
}
