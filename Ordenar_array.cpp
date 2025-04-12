#include <iostream>
using namespace std;

void ordenar(int* inicio, int* fin){
    for(int* i = inicio; i < fin - 1; i++){
        for(int* j = i + 1; j < fin; j++){
            if(*i > *j){
                int temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
}

int main() {
    int A[] = {15, 3, 27, 49, 77, 48, 2, 34, 56, 98};
    int n = sizeof(A) / sizeof(A[0]);

    int* inicio = A;
    int* fin = A + n;

    cout << "Array original" << endl;
    for(int* p = A; p < A + n; p++){
        cout << *p << " ";
    }
    cout << endl;

    ordenar(inicio, fin);

    cout << "Array ordenado" << endl;
    for(int* p = A; p < A + n; p++){
        cout << *p << " ";
    }
    cout << endl;

    return 0;
}
