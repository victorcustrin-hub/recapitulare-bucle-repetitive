#pragma once
#include <iostream>
using  namespace std;

// numar!=0     uc  suma numar
// 8559!=0 da   9   9   855
//855!=0 da     5   14   85
//85!=0 da      5   19    8
//8!=0 da       8   27    0


void ex1() {
	int numar = 8559;
	int suma = 0;
	while (numar != 0) {
		int uc = numar % 10;
		suma += uc;
		numar = numar / 10;

	}
	cout << "Suma cifrelor este " << suma << endl;
}


//n!=0           cif  par   imp   ct
//123456!=0 da   6    1      0     1
//12345!=0 da    5    1      1     2
//1234!=0 da     4    2      1     3
//123!=0 da      3    2      2     4
//12!=0 da       2    3      2     5
//1!=0 da        1    3      3 
 

void ex1poza() {
	int n = 123456;
	int ct = 0;
	int par = 0;
	int imp = 0;

	while (n != 0) {
		int cif = n % 10;
		if (cif % 2 == 0) {
			par++;
		}
		else {
			imp++;
		}
		ct++;
		n = n / 10;
	}

	cout << "n are " << ct << " cifre dintre care " << par << " pare si " << imp << " impare." << endl;

}




//n!=0            cif    vf(cif=x?)    n
//1954!=0 da       4        1         195
//195!=0 da        5        1          19
//19!=0 da         9        1          1
//1!=0 da          1        1          0


void ex2poza() {
	int n = 1954;
	int x = 6;
	bool vf = false;

	while (n != 0) {
		int cif = n % 10;
		if (cif == x) {
			vf = true;
		}
		n = n / 10;
	}
	if (vf == true) {
		cout << "n contine cifra x" << endl;
	}
	else {
		cout << "n nu contine cifra x" << endl;
	}
}