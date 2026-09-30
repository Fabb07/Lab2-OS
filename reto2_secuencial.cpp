//reto2_secuencial.cpp
#include <iostream>

using namespace std;

int main() {
    int numero = 5;
    long long factorial = 1;

    for (int i = 1; i <= numero; i++) {
        factorial *= i;
    }

    cout << "[Secuencial] El factorial de " << numero << " es: " << factorial << endl;

    return 0;
}