#pragma once
#include <iostream>
using namespace std;

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

//n!=0          cif     vf(cif=ultimCif)       n
//3333!=0 da     3      1                     333
//333!=0  da     3      1                     33
//33!=0 da       3      1                     3
//3!=0 da        3      1                     0
void ex3poza() {
	int n = 2222;
	bool vf = true;
	int ultimCif = n % 10;

	while (n != 0&&vf==true) {
		int cif = n % 10;
		if (cif != ultimCif) {
			vf = false;
		}
		n = n / 10;
	}

	if (vf == true) {
		cout << "cifre identice" << endl;
	}
	else {
		cout << "cifre diferite" << endl;
	}

}

//n!=0       cif     min       max     n
//40285 da    5       5         5      4028
//4028 da     8       5         8      402
//402 da      2       2         8      40
//40  da      0       0        
void ex4poza() {
	int n = 40285;
	int max = -1;
	int min = 9;

	while (n != 0) {
		int cif = n % 10;
		if (min > cif) {
			min = cif;
		}
		if (max < cif) {
			max = cif;
		}
		n = n / 10;
	}

	cout << "cifra maxima = " << max << ", cifra minima = " << min << endl;
}

//n!=0           cif      min     max     n
//4251!=0 da      1        9       -1     425
//425!=0 da       5        9       -1     42
//42!=0 da        2        2        2     4
// 4!=0 da        4        2        4     0

void ex5poza() {
	int n = 4251;
	int min = 9;
	int max = -1;

	while (n != 0) {
		int cif = n % 10;
		if (min > cif && cif % 2 == 0) {
			min = cif;
		}
		if (max < cif && cif % 2 == 0) {
			max = cif;
		}
		n = n / 10;
	}
   
	if (min == 9 && max == -1) {
		cout << "Numarul nu contine nr pare" << endl;
	}
	else {
		cout << "nr min par = " << min << ", nr maxim par = " << max << endl;
	}

}


//n!=0        cif     nou    p     n
//2759!0=da    9       9     10    275
//275!=0 da    5       59    100   27
//27!=0 da     7       759   1000  2
//2!=0 da      2       2759  10000 0
void ex6poza() {
	int n = 2759;
	int nou = 0;
	int p = 1;

	while (n != 0) {
		int cif = n % 10;
		nou = cif * p + nou;
		cout << nou << ",";
		p = p * 10;
		n = n / 10;
	}



}
//   n!=0          uc       nou       n    
//  2345!=0 da      5        5       234
//  234!=0 da       4        54       23
//   23!=0 da       3        543       2
//    2!=0 da       2       5432       0
void algRasturnatNumar() {
	

	int n = 2345;
	int nou = 0;
	while (n != 0) {
		int uc = n % 10;
		nou = nou * 10 + uc;
		n = n / 10;

	}

	cout << nou << endl;


}

//n!=0          uc     nou      p       n
//2345!=0 da    5       5       10     234
//234!=0 da     4       45      100     23
//23!=0 da      3       345     1000     2
//2!=0 da       2       2345    10000    0
void algParcurgereNumar() {


	int n = 2345;
	int nou = 0;
	int p = 1;
	while (n != 0) {
		int uc = n % 10;
		nou = uc *p + nou;
		p = p * 10;
		n = n / 10;

	}

	cout << nou << endl;


}




// p<=n/10        p         
// 1<=234 da      10
// 10<=234 da     100
// 100<=234 da    1000

//p!=0           cif      n       p
//1000!=0 da      2       345    100
//100!=0 da       3       45      10
//10!=0 da        4        5       1
//1!=0 da         5        0      0

void ex7poza() {
	int n = 2345;
	int p = 1;

	while (p <= n/10) {
		p = p * 10;
	}

	while (p !=0) {
		int cif = n / p;
		cout << cif << ",";
		n = n % p;
		p=p / 10;
	}

}