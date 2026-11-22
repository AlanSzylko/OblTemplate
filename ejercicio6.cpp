#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int* cantNums = new int[1001]();
    int n;
    int medio = -1;
    cin >> n;
    int* salida = new int[n];
    int posSalida = 0;
    for(int i = 0; i<n; i++){
        int num;
        cin >> num;
        cantNums[num]++;
        salida[i] = -1;
    }
    for(int i = 1000; i>=0; i--){
        while(cantNums[i] >= 2){
            cantNums[i] -= 2;
            salida[posSalida] = i;
            posSalida++;
        }
        if(cantNums[i] == 1 && medio<i) medio = i;
    }
    // Impresion con el separador antes de cada numero (salvo el primero), hecha con
    // Claude: la version anterior ponia el espacio despues y dejaba uno colgando al final.
    bool primero = true;

    for(int i = 0; i < posSalida ;i++){
        if(!primero) cout << " ";
        cout << salida[i];
        primero = false;
    }

    if(medio != -1){
        if(!primero) cout << " ";
        cout << medio;
        primero = false;
    }

    for(int i = posSalida - 1; i >= 0;i--){
        if(!primero) cout << " ";
        cout << salida[i];
        primero = false;
    }
    return 0;
}