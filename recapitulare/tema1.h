#pragma once
#include <iostream>
using namespace std;

//ex1


int produsCifre(int n) {
	int produs = 1;
	while (n != 0) {

		int cif = n % 10;
		produs = cif * produs;
		n = n / 10;
	}
	return produs;
}

void solutieEx1() {
	int n = 0;
	cout << "nr=";
	cin >> n;

	int produs = produsCifre(n);

	cout << "produsul cifrelor lui n este" << produs<<endl;
}