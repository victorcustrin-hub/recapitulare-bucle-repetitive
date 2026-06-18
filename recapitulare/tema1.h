#pragma once
#include <iostream>
using namespace std;

//ex1

//n!=0            cif     produs     n
 //2345!=0da      5         5        234
//234!=0 da       4         20        23
//23!=0 da        3         60        2
//2!=0 da         2         123       0
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

	cout << "produsul cifrelor lui n este " << produs<<endl;
}

//n!=0      cif       n%2==0     p     n
//1234       4          da       4     123
//123        3           nu      4     12
//12         2           da      8     1
//1          1           nu      8     0
int produsCifPare(int n) {
	int p = 1;

	while (n != 0) {
		int cif = n % 10;
		if (n % 2 == 0) {
			p = p * cif;
		}
		n = n / 10;
	}
	return p;
}

void solutieEx2() {
	int nr = 0;
	cout << "nr=";
	cin >> nr;

	int prod = produsCifPare(nr);

	if (prod == 1) {
		cout << "Nu exista cifre pare" << endl;
	}
	else
	{
		cout << "Produsul cifrelor pare este " << prod;
	}

}
//n!=0       cif     ct     n
//15732       2      1      1573
//1573        3      2       157
//157         7      3       15
//15          5      4       1
//1           1      4       0
int cifPrime(int n) {
	int ct = 0;

	while (n != 0) {
		int cif = n % 10;
		if (cif == 2 || cif == 3 || cif == 5 || cif == 7) {
			ct++;
		}
		n = n / 10;
	}
	return ct;
	//ct nu e 4 in cazul 15732???
}

void solutieEx3() {
	int n = 0;

	cout << "nr=";
	cin >> n;

	int prim = cifPrime(n);

	cout << "nr de cifre prime este " << prim;

}