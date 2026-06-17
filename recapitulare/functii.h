#pragma once
#include <iostream>
using namespace std;

//todo: functie ce returneaza nuamrul de cifre al lui n

//f(x)=2x+1   f(3)=7  

int   contorCifre(int n) {
	 
	int ct = 0;
	while (n != 0) {
		
		ct++;
		n = n / 10;

	}

	return ct;
  }

int contorCifrePare(int n) {
	int ct=0;
	while (n != 0) {
		int cif = n % 10;
		if (cif % 2 == 0) {
			ct++;
		}
		n = n / 10;
	}

	return ct;
}

int contorCifreImpare(int n) {
	
	return contorCifre(n)-contorCifrePare(n);
}


void solutie1() {
	int numar = 0;
	cout << "numar=";
	cin >> numar;
	int total = contorCifre(numar);
	int totalPare = contorCifrePare(numar);
	int totalImpare = contorCifreImpare(numar);
	cout << " nr de cifre este "<<total<<" cu "<<totalPare<<" cifre pare si "<<totalImpare<<" cifre impare";
}


bool vfNumar(int n,int x) {
	while (n != 0) {
		int cif = n % 10;
		if (x == cif) {
			return true;
		}
		n = n / 10;
	}

	return false;

}

void solutie2() {
	int numar = 0;
	int x = 0;
	cout << "nr=";
	cin >> numar;
	cout << "x=";
	cin >> x;
	int vf = vfNumar(numar, x);
	
	vf ? cout << "contine" : cout << "nu contine";
}


bool vfNrIdentice(int n) {
	int x = n % 10;

	while (n != 0) {
		int cif = n % 10;
		if (cif != x) {
			return false;
		}
		n = n / 10;
	}
	return true;

}

void solutie3() {
	int nr = 0;
	cout << "nr=";
	cin >> nr;
	bool vf = vfNrIdentice(nr);

	vf ? cout << "nr identice" : cout << "nr nu sunt identice";

}


int cifMax(int n) {
	int max = -1;
	while (n != 0) {
		int cif = n % 10;
		if (cif > max) {
			max = cif;
		}
		n = n / 10;
	}
	return max;
}

int cifMin(int n) {
	int min = 10;

	while (n != 0) {
		int cif = n % 10;
		if (cif < min) {
			min = cif;
		}
		n = n / 10;
	}
	return min;
}

void solutie4() {
	int n = 0;
	cout << "nr=";
	cin >> n;
	
	int maxim = cifMax(n);
	int minim = cifMin(n);

	cout << "Cifra maxima a nr este " << maxim << ", iar cifra minima este " << minim << endl;
}