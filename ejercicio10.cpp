#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

//declaro
int K, cantCols;
int valor[26];
bool usado[10];
bool noPuedeSer0[26];
int letraSumando[5][10];   // 5 sumandos, 10 letras max cada sumando
int letraResultadoColumna[10];  // resultado max 10 letras
bool hayMejor;
string palabras[6];
string resultado;
long long mejor[6];

int letraActual(int sumando, int col) {
    if (sumando < K) return letraSumando[sumando][col];
    return letraResultadoColumna[col];
}

bool esSolucion(int col, int acarreo) {
    return col == cantCols && acarreo == 0;
}


bool puedoAplicarMovimiento(int sumando, int col, int suma, int acarreo, int d) {
    if (col == cantCols) return false;
    int L = letraActual(sumando, col);
    if (sumando == K && d != (suma + acarreo) % 10) return false;
    if (L == -1) return d == 0;
    if (valor[L] != -1) return valor[L] == d;
    if (usado[d]) return false;
    if (d == 0 && noPuedeSer0[L]) return false;
    return true;
}

void aplicarMovimiento(int L, int d) {
    valor[L] = d;
    usado[d] = true;
}

void deshacerMovimiento(int L, int d) {
    valor[L] = -1;
    usado[d] = false;
}

long long numero(string p) {         
    long long n = 0;
    for (int i = 0; i < p.size(); i++) {
        n = n * 10 + valor[p[i] - 'A'];
    }
    return n;
}

bool esMenor(long long actual[]) {
    if (actual[K] != mejor[K]) return actual[K] < mejor[K];  
    for (int i = 0; i < K; i++) {
        if (actual[i] != mejor[i]) return actual[i] < mejor[i];  
    }
    return false;                                                
}

// Función principal de backtracking
void backtracking(int sumando, int col, int suma, int acarreo) {
    if (esSolucion(col, acarreo)) {
        long long actual[6];
        for (int j = 0; j < K; j++) actual[j] = numero(palabras[j]);
        actual[K] = numero(resultado);
        if (!hayMejor || esMenor(actual)) {
            for (int i = 0; i <= K; i++) mejor[i] = actual[i];
            hayMejor = true;
        }
    } else {
        for (int d = 0; d <= 9; d++) {
            if (puedoAplicarMovimiento(sumando, col, suma, acarreo, d)) {
                int L = letraActual(sumando, col);
                bool nueva = (L != -1 && valor[L] == -1);
                if (nueva) aplicarMovimiento(L, d);
                if (sumando < K) backtracking(sumando + 1, col, suma + d, acarreo);
                else backtracking(0, col + 1, 0, (suma + acarreo) / 10);
                if (nueva) deshacerMovimiento(L, d);
            }
        }
    }
}


int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> K;
        for (int i = 0; i < K; i++) {
            cin >> palabras[i];
        }
        cin >> resultado;   
        for (int j = 0; j < K; j++) {                    // cada sumando
            string palabra = palabras[j];
            for (int i = 0; i < resultado.size(); i++) { // cada columna
                if (i < palabra.size()) {
                    letraSumando[j][i] = palabra[palabra.size() - 1 - i] - 'A';
                } else {
                    letraSumando[j][i] = -1;                     // la palabra no llega a esta columna
                }
            }
        }
        for (int i = 0; i < resultado.size(); i++) {
            letraResultadoColumna[i] = resultado[resultado.size() - 1 - i] - 'A';
        }


        for (int l = 0; l < 26; l++) {
            valor[l] = -1;     
            noPuedeSer0[l] = false;
        }
        for (int j = 0; j < K; j++) {
            if (palabras[j].size() > 1) {
                noPuedeSer0[palabras[j][0] - 'A'] = true;   // primera letra del sumando
            }
        }
        if (resultado.size() > 1) {
            noPuedeSer0[resultado[0] - 'A'] = true;         // primera letra del resultado
        }
        for (int d = 0; d < 10; d++) usado[d] = false;

        bool imposible = false;
        for (int j = 0; j < K; j++) {
            if (palabras[j].size() > resultado.size()) imposible = true;
        }
        cantCols = resultado.size();
        hayMejor = false;
        if (!imposible) backtracking(0, 0, 0, 0);
        if (!hayMejor) {
            cout << "imposible" << endl;
        } else {
            for (int i = 0; i < K; i++) {
                if (i > 0) cout << " + ";
                cout << mejor[i];
            }
            cout << " = " << mejor[K] << endl;
        }
    }
    return 0;

}