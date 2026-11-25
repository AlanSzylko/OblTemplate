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


bool esSolucion(/* parámetros de estado */) {
    // Verifica si llegamos a una solución
}

bool puedoAplicarMovimiento(/* estado, movimiento */) {
    // Valida si el movimiento es legal
}

void aplicarMovimiento(/* estado, movimiento */) {
    // Modifica el estado aplicando el movimiento
}

void deshacerMovimiento(/* estado, movimiento */) {
    // Revierte el movimiento (BACKTRACK!)
}



// Función principal de backtracking
// void backtracking(int sumando, int col, int suma, int acarreo) {
   // if (esSolucion(/* estado */)) {
        // Procesar solución encontrada
   // } else {
        // Para cada movimiento posible
       // for (/* cada movimiento candidato */) {
          //  if (puedoAplicarMovimiento(/* estado, movimiento */)) {
            //    aplicarMovimiento(/* estado, movimiento */);
          //      backtracking(/* nuevo estado, ... */);
        //        deshacerMovimiento(/* estado, movimiento */);
      //      }
    //    }
  //  }
//}


int main()
{
    cin >> K;
    string palabras[6];
    for (int i = 0; i < K; i++) {
        cin >> palabras[i];
    }
    string resultado;
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

    return 0;
}