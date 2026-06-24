#pragma once
#include <iostream>
using namespace std;



int sumaDivizori(int n) {
    int suma = 0;

    for (int i = 1;i <= n;i++) {
        if (n % i == 0) {
            suma = suma + i;
        }

    }

    return suma;

}

void solutie376() {
    int n = 0;
    cout << "nr=";
    cin >> n;
    int rez = sumaDivizori(n);
    cout << "Suma divizorilor lui " << n << " este " << rez << endl;

}


int suma(int n) {
    int s = 0;

    for (;n > 0;n = n / 10) {
        s = n % 10;
    }
    return s;

}


bool asociate(int suma) {

    if (suma % 2 == 0 || suma % 3 == 0 || suma % 5 == 0) {
        return true;
    }
    return false;

}

void solutie4867() {

}