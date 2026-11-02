#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

int cantProd, pesoMax;
int* peso;
int* satisfaccion;
int* categoria;
int* cupos;

int mayorSat(int i, int pesoLibre, int* cupos)
{
    if (i >= cantProd) return 0;    
    else{
        if ( peso[i] > pesoLibre || cupos[categoria[i]] == 0 ) return mayorSat(i+1, pesoLibre, cupos);
        else{
            int NoUso = mayorSat(i + 1, pesoLibre , cupos );
            
            cupos[categoria[i]] --;
            int uso = satisfaccion[i] + mayorSat(i + 1, pesoLibre - peso[i], cupos);
            cupos[categoria[i]]++;

            return max(uso, NoUso);
        }
     }
}   






int main()
{
    cin >> cantProd >> pesoMax;

    cupos = new int[4];
    cin >> cupos[0] >> cupos[1] >> cupos[2] >> cupos[3];

    peso = new int[cantProd];
    satisfaccion = new int[cantProd];
    categoria = new int[cantProd];

    for (int i = 0; i < cantProd; i++)
    {
        cin >> peso[i] >> satisfaccion[i] >> categoria[i];
    }

    cout << mayorSat( 0 , pesoMax , cupos );
    return 0;
}