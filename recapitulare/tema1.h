#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

//intrebari: 4,8,14

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

//n!=0     cif     suma     ct     n 
//2345     5        5        1     234
//234      4        9        2     23 
//23       3        12       3     2
//2        2        14       4     =

double medieAritmetica(int n) {
	double medie = 0;
	double suma = 0;   //dc trebuie double aici??
	int ct=0;
	while (n != 0) {
		int cif = n % 10;
		suma = cif + suma;
		ct++;
		n = n / 10;
	}

	medie = suma / ct;
	return medie;

	//cum afisez 2 zecimale??
}

void solutieEx4() {
	int n = 0;

	cout << "nr=";
	cin >> n;

	double med = medieAritmetica(n);
	cout << fixed << setprecision(2);
	cout << "media aritmetica a cifrelor lui n este " << med;

}
  
int suma(int n) {
	int s = 0;
	while (n != 0) {
		int cif = n % 10;
		s = s + cif;
		n = n / 10;
	}
	return s;
}

//nr = 128, suma=11
//i*i<=n         s%i==0     i++
//4<=11 da        nu         3
//9<=11 da        nu         4
//16<=11 nu       -          -

bool vfNumarPrim(int n) {
	int s = suma(n);
	int i = 2;
	while (i * i <= s) {
		if (s % i == 0) {
			return false;
		}
		i++;
	}
	
	return true;
}

void solutie5() {
	int n = 0;
	cout << "nr=";
	cin >> n;

	bool x = vfNumarPrim(n);

	x ? cout << "este prim" : cout << "nu este prim";


}

int maxImpar(int n) {
	int x = -1;

	while (n != 0) {
		int cif = n % 10;
		if (cif % 2 != 0&&cif>x) {
			x = cif;
		}
		n = n / 10;
	}
	return x;
}

void solutie6() {
	int n = 0;
	cout << "nr=";
	cin >> n;

	int rez = maxImpar(n);

	if (rez == -1) {
		cout << "Nu exista cifre impare in numarul introdus" << endl;
	}
	else {
		cout << "Cea mai mare cifra impara este " << rez << endl;
	}
}

int minImpar(int n) {
	int min = 10;

	while (n != 0) {
		int cif = n % 10;
		if (cif % 2 != 0 && cif < min) {
			min = cif;
		}
		n = n / 10;
	}
	return min;
}

void solutie7() {
	int n = 0;
	cout << "nr=";
	cin >> n;
	int rez = minImpar(n);
	if (rez == 10) {
		cout << "Nu exista cifre impare in numarul introdus" << endl;
	}
	else {
		cout << "Cea mai mica cifra impara este " << rez << endl;
	}
}
//n!=0            cif      x!=0     x     cif2  cif==cif2       n
// 12345!=0da     5          da     3234    4       nu         1234
//                           da      323    3       nu
//                           da      32     2       nu         
//                           da      3      3       nu   
//3234!=0 da      4          da     3234

bool vfDistinctie(int n) {
	int x = n;
	while (n != 0) {
		int cif = n % 10;
		while (x != 0) {
			x = x / 10;
			int cif2 = x % 10;
			if (cif == cif2) {
				return false;
			}
		}
		x = n;
		n = n / 10;
	}

	return true;
}

void solutie8() {
	int n = 0;
	cout << "nr=";
	cin >> n;

	int rez = vfDistinctie(n);

	rez ? cout<<"Toate cifrele sunt distincte" : cout << "Exista cifre identice in numar.";
}

//n!=0     cif     nou    p     n
//12345 da   5       0      1     1234
//1234 da    4       4      10    123
//123 da     3       4      10     12
//12  da     2       24     100    1
//1   da     1       24     100    0
int constrPar(int n) {
	int nou = 0;
	int p = 1;

	while (n != 0) {
		int cif = n % 10;
		if (cif % 2 == 0) {
			nou = p * cif + nou;
			p = p * 10;
		}
		
		n = n / 10;
	}
	return nou;
}

void solutie9() {
	int n = 0;
	cout << "nr=";
	cin >> n;
	int nou = constrPar(n);

	cout << "Numarul format doar din cifrele pare este " << nou << endl;

}

//n!=0           cif        nou       p      n
//12345!=0 da    5           5        10    1234
//1234!=0 da     4           5        10    123
//123!=0 da      3           35       100    12
//12!=0 da       2           35       100    1
//1!=0 da        1           135      1000    0
int constrImp(int n) {
	int nou = 0;
	int p = 1;
	while (n != 0) {
		int cif = n % 10;
		if (cif % 2 != 0) {
			nou = p * cif + nou;
			p = p * 10;
		}
		n = n / 10;
		
	}
	return nou;
}

void solutie10() {
	int n = 0;
	cout << "nr=";
	cin >> n;
	int nou = constrImp(n);

	cout << "Nr format din cifrele impare este " << nou << endl;

}

//n!=0          cif      nou      p       n
//2347!=0 da    7        4        10      234
//234!=0 da     4        84       100     23
//23!=0 da      3        684      1000     2
//2!=0 da       2        4684     10000    0
int dubluCif(int n) {
	int nou = 0;
	int p = 1;

	while (n != 0) {
		int cif = n % 10;
		nou = cif * 2 % 10 * p + nou;
		p = p * 10;
		n = n / 10;
	}
	return nou;
}

void solutie11() {
	int n = 0;
	cout << "nr=";
	cin >> n;


	int dublu = dubluCif(n);
	cout << "Dublul fiecarei cifre %10 = " << dublu << endl;

}

//c=3
//n!=0            cif     cif!=c     nou    p     n
//72313!=0 da     3         nu       0      1    7231
// 7231!=0 da     1         da       1      10    723
// 723!=0 da      3         nu       1      10     72
// 72!=0 da       2         da       21     100    7
// 7!=0 da        7         da       721    1000    0  
int elimCif(int n, int c) {
	int nou = 0;
	int p = 1;

	while (n != 0) {
		int cif = n % 10;
		if (cif != c) {
			nou = cif * p + nou;
			p = p * 10;
		}
		n = n / 10;
	}
	return nou;
}

void solutie12() {
	int n = 0;
	cout << "nr=";
	cin >> n;
	int c = 0;
	cout << "cifra=";
	cin >> c;

	int elim = elimCif(n,c);
	cout << "Nr introdus fara cifra "<<c<<" este " << elim << endl;

}

//c1=7, c2=3
//n!=0           cif    cif=c1     nou      p     n
//72717!=0 da     7       da        3       10    7271
//7271!=0 da      1       nu        13      100    727
//727!=0 da       7       da        313     1000    72
//72!=0 da        2       nu        2313    10000    7
//7!=0 da         1       da        32313   100000   0
int inlocuireCif(int n, int c1, int c2) {
	int nou = 0;
	int p = 1;

	while (n != 0) {
		int cif = n % 10;
		if (cif == c1) {
			nou = c2 * p + nou;
			
		}
		else {
			nou = cif * p + nou;
		}
		p = p * 10;
		n = n / 10;
	}
	return nou;
}

void solutie13() {
	int n = 0;
	cout << "nr=";
	cin >> n;
	int c1 = 0;
	cout << "cifra 1 =";
	cin >> c1;
	int c2 = 0;
	cout << "cifra 2 =";
	cin >> c2;


	int x = inlocuireCif(n, c1,c2);
	cout << "Inlocuind cifra 1 cu cifra 2 in nr, noul numar = " << x << endl;

}

//p<=n/10       p         
//1<=234 da     10
//10<=234 da    100
// 100<=234 da  1000

//p!=0           cif     cifAnt!=-1       cif!=cifAnt+1        cifAnt        n         p 
//1000!=0 da      2          nu               --                 2          345       100
//100!=0 da       3          da               nu                 3           45        10
//10!=0 da        4          da               nu                 4           5         5
//1!=0 da         5          da               nu                 5           0         0

bool consecutiv(int n) {
	int p = 1;
	int cifAnterior = -1;

	while (p <= n / 10) {
		p = p * 10;
	}
	
	while (p != 0) {
		int cif = n / p; 
		if (cifAnterior != -1) {
			if (cif != cifAnterior + 1) {
				return false;
			}
		}
		cifAnterior = cif;
		n = n % p;
		p = p / 10;
	}
	return true;
}

void solutie14x() {
	int n = 0;
	cout << "nr=";
	cin >> n;


	int consec = consecutiv(n);
	consec ? cout << "DA" : cout << "NU";

}
// p<=n/10        p         
// 1<=234 da      10
// 10<=234 da     100
// 100<=234 d    1000

//p!=0           cif     k==1   k     n    p
//1000!=0 da     2       nu    2    345   100
//100!=0 da      3       nu    1     34   10

int deterCifra(int n, int k) {
	int p = 1;
	while (p <= n / 10) {
		p = p * 10;
	}

	while (p != 0) {
		int cif = n / p;
		if (k == 1) {
			return cif;
		}
		k--;
		n = n % p;
		p = p / 10;
	}
}

void solutie16() {
	int n = 0;
	cout << "nr=";
	cin >> n;
	int k = 0;
	cout << "k=";
	cin >> k;

	int x = deterCifra(n, k);
	cout << "Cifra pe pozitia " << k << " este " << x;

}


//n!=0         cif    ct    n
//2341!=0 da   1     0     234
//234!=0 da    4     1      23
//23!=0 da     3     2      2
//2!=0 da      2     3      0
int ctCifMin(int n) {
	int ct = 0;
	int x = n % 10;
	while (n != 0) {
		int cif = n % 10;
		if (cif > x) {
			ct++;
		}
		n = n / 10;
	}
	return ct;
}

void solutie17() {
	int n = 0;
	cout << "nr=";
	cin >> n;

	int ct = ctCifMin(n);
	cout <<"nr de cifre strict mai mari decat "<<n%10<<" este "<<ct<< endl;

}

  
//n>9           cif     cif2     ct     n
//2486>9 da     6       8       1      248
//248>9 da      8       4       2      24
//24>9 da       4       2       3       2
int perechiParitate(int n) {
	int ct = 0;
	while (n >9) {
		int cif = n % 10;
		int cif2 = n / 10 % 10;

		if (cif % 2 == cif2 % 2) {
			ct++;
		}

		n = n / 10;
	}
	return ct;

}

void solutie18() {
	int n = 0;
	cout << "nr=";
	cin >> n;
	int ct = perechiParitate(n);
	cout << "Exista " << ct << " perechi de cifre cu aceeasi paritate" << endl;

}



//copie>0        p      copie 
//345>0 da       10      34
//34>0 da        100      3
//3>0 da         1000     0
//nou=12*1000+345=12345

int concatenare(int a, int b) {
	int p = 1;
	int copie = b;

	while (copie>0) {
		p = p * 10;
		copie = copie / 10;
	}

	int nou = a * p + b;
	return nou;
}

void solutie20() {
	int a = 0;
	cout << "a=";
	cin >> a;
	int b = 0;
	cout << "b=";
	cin >> b;
	int con = concatenare(a,b);
	cout << "Ambele nr la un loc=" << con << endl;

}


int ctCif(int n) {
	int ct = 0;
	int cifra = 0;

	while (cifra<=9) {
		int copie = n;
		int ct2 = 0;

		while (copie > 0) {
			int cif = copie % 10;
			if (cif == cifra) {
				ct2++;
			}
			copie = copie / 10;
		}

		if (ct2 >= 2) {
			ct++;
		}

		cifra++;


	}
	return ct;
}

void solutie21() {
	int n = 0;
	cout << "nr=";
	cin >> n;
	int ct = ctCif(n);

	if (ct == 1) {
		cout << ct << " cifra apar de minim 2 ori in nr introdus" << endl;
	}
	else {
		cout << ct << " cifre apar de minim 2 ori in nr introdus" << endl;
	}
	
}


//n!=0          cif    ogl    n
//1221!=0 da    1       1     122
//122!=o da     2       12    12
//12!=0 da      2       122   1
//1!=0 da       1       1221  0
bool palindrom(int n) {
	if (n == 0) {
		return false;
	}
	int ogl = 0;
	int copie = n;

	while (n != 0) {
		int cif = n % 10;
		ogl = ogl*10+cif;
		n = n / 10;
	}

	if (ogl == copie) {
		return true;
	}
	else {
		return false;
	}
}


void solutie22() {
	int n = 1;
	int ct = 1;
	int ct2 = 0;
	cout << "Introduceti numere, ultimul introdus va fi 0" << endl;
	while (n != 0) {
		cout << "Nr" << ct << "=";
		cin >> n;
		ct++;
		bool vf = palindrom(n);
		if (vf == 1) {
			ct2++;
		}

	}
	cout << ct2 << " dintre numerele introduse sunt palindroame" << endl;

}

//corectarea temei


//ex8: n numar natural, verificati daca toate cifrele sunt distincte

//de cate ori apare cifra x in nr introdus

int vfCif(int n, int k) {
	int ct = 0;

	while (n != 0) {
		int cif = n % 10;
		if (cif == k) {
			ct++;
		}
		n = n / 10;
	}

	return ct;

}


bool isCifreDistincte(int numar) {
	int aux = numar;
	while (numar!=0)
	{
		int cifra = numar % 10;
		if (vfCif(aux, cifra) > 1) {
			return false;
		}
		numar = numar / 10;

	}
	return true;
}



void solutie08() {
	int nr = 0;
	cout << "nr=";
	cin >> nr;
	bool cif = isCifreDistincte(nr);

	cif ? cout << "Toate cifrele sunt distincte." : cout << "Exista cifre identice." << endl;

}

//ex14  n nr natural, verificați dacă cifrele lui n sunt consecutive ascendent
//n!=0     cif     cif2     cif2+1!=cif    n
//1234
bool ascendent(int n) {
	int cifPrecedent = n % 10;
	n = n / 10;
	int cif = -1;


	while (n != 0) {
		cif = cifPrecedent;
		cifPrecedent = n % 10;
		if (cifPrecedent+1 != cif) {
			return false;
		}

		n = n / 10;

	}
	return true;
}

void solutie14() {
	int nr = 0;
	cout << "nr=";
	cin >> nr;

	int asc = ascendent(nr);
	asc ? cout << "Nr sunt consecutive ascendent" : cout << "Nr nu sunt consecutive ascendent" << endl;

}


//ex19:a si b nr nat. verificati daca a si b sunt anagrame(au aceleasi cifre)


bool verificaCifreDinAsiInB(int a, int b) {
	

	while (a != 0) {
		int cifra = a % 10;
		if (vfCif(b, cifra) == 0) {
			return false;
		}
		a = a / 10;
	}

	return true;
}


bool isAnagrame(int a, int b) {

	return verificaCifreDinAsiInB(a, b) && verificaCifreDinAsiInB(b, a);
}

