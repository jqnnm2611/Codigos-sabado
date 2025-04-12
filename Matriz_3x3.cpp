#include <iostream>
using namespace std;

const int N = 3;

void imprimirMatriz(int (*matriz)[3]) {
    int* p = *matriz;
    int contador = 0;
    while (p < *matriz + N * N) {
        if (*p == 0)
            cout << "   ";
        else
            cout << *p << (*p < 10 ? "  " : " ");
        p++;
        contador++;
        if (contador % N == 0) cout << endl;
    }
    cout << endl;
}

int* encontrarBlanco(int (*matriz)[3]) {
    int* p = *matriz;
    while (p < *matriz + N * N) {
        if (*p == 0)
            return p;
        p++;
    }
    return nullptr;
}

void moverArriba(int* blanco, int (*matriz)[3]) {
    int* filaInicio = *matriz;
    while (filaInicio + N <= blanco) filaInicio += N;
    if (filaInicio == *matriz) {
        cout << "Movimiento inválido: no puedes subir" << endl;
        return;
    }
    int* destino = blanco - N;
    int temp = *blanco;
    *blanco = *destino;
    *destino = temp;
}

void moverAbajo(int* blanco, int (*matriz)[3]) {
    int* filaInicio = *matriz;
    while (filaInicio + N <= blanco) filaInicio += N;
    if (filaInicio + N * 2 > *matriz + N * N) {
        cout << "Movimiento inválido: no puedes bajar" << endl;
        return;
    }
    int* destino = blanco + N;
    int temp = *blanco;
    *blanco = *destino;
    *destino = temp;
}

void moverIzquierda(int* blanco, int (*matriz)[3]) {
    int* filaInicio = *matriz;
    while (filaInicio + N <= blanco) filaInicio += N;
    if (blanco == filaInicio) {
        cout << "Movimiento inválido: no puedes mover a la izquierda" << endl;
        return;
    }
    int* destino = blanco - 1;
    int temp = *blanco;
    *blanco = *destino;
    *destino = temp;
}

void moverDerecha(int* blanco, int (*matriz)[3]) {
    int* filaInicio = *matriz;
    while (filaInicio + N <= blanco) filaInicio += N;
    if (blanco == filaInicio + N - 1) {
        cout << "Movimiento inválido: no puedes mover a la derecha" << endl;
        return;
    }
    int* destino = blanco + 1;
    int temp = *blanco;
    *blanco = *destino;
    *destino = temp;
}

int main() {
    int matriz[N][N] = {
        {3, 4, 7},
        {6, 2, 8},
        {1, 0, 5}
    };

    int* blanco = encontrarBlanco(matriz);
    imprimirMatriz(matriz);

    char input;
    while (true) {
        cout << "¿A donde quieres ir? (w = arriba, s = abajo, a = izquierda, d = derecha, q = salir): ";
        cin >> input;

        switch (input) {
            case 'w': moverArriba(blanco, matriz); break;
            case 's': moverAbajo(blanco, matriz); break;
            case 'a': moverIzquierda(blanco, matriz); break;
            case 'd': moverDerecha(blanco, matriz); break;
            case 'q': return 0;
            default: cout << "Tecla inválida. Usa w, a, s, d o q" << endl;
        }

        blanco = encontrarBlanco(matriz);
        imprimirMatriz(matriz);
    }

    return 0;
}
