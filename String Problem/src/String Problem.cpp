//============================================================================
// Name        : String.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*Senaryo:
Elimizde ard arda tekrarlayan harflerin �ok s�k kar��la��ld���, sadece harfler ve bo�luklardan olu�an stringler var.
Bu alfabetik stringlerin i�inde arka arkaya n kere veya daha fazla tekrarlayan harflerin
y�ld�z karakteriyle (�*�) de�i�tirilmi� halini istiyoruz.

�rnek:
String verimiz �abbcccaaeeeeb bfffffca ccab� �eklinde olsun. Program�n�z �al��t���nda�
n = 9 verildi�inde �abbcccaaeeeeb bfffffca ccab�
n = 5 verildi�inde �abbcccaaeeeeb b*****ca ccab�
n = 4 verildi�inde �abbcccaa****b b*****ca ccab�
n = 3 verildi�inde �abb***aa****b b*****ca ccab�
n = 2 verildi�inde �a***********b b*****ca **ab�
�sonu�lar�n� vermesi beklenmektedir.

Soru: Yukar�da anlat�lan �zellikleri ger�ekleyen bir program yaz�n�z.
 * */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<char> myReturnVector (string & kelime, unsigned int n){
	unsigned int m=0;
	unsigned int l =0;
	unsigned int value = 0;
	vector<char> myV;

	//assign string to a char vector for operation
	for(unsigned int i=0; i<kelime.size(); i++){
		myV.push_back(kelime[i]);
	}

	if(myV.size()<n){
		return myV;
	}
	// count same adjacent chars, if equal to given n, keep first and last element number
	for(unsigned int j=0; j<myV.size()-1; j++){
		if(myV[j] == myV[j+1]){
			m=m+1;
			//cout <<"m: " << m << endl;
			if(m == 1){
				value = j;
			}
			if(m >= n-1){
				//cout << "l: " << l << endl;
				l = j+1;
			}
		}
		else{
			//cout << "DEBUG" << endl;
			//assign '*' character to these adjacent values
			if(value != 0 && m>=n-1){
				//cout << "value: " << value << endl;
				for(unsigned int k= value; k<=l; k++){
					myV[k] = '*';
				}
			}
			// set variables to zero new string block compare
			l = 0;
			m = 0;
			value = 0;
		}

	}

	return myV;
}
int main() {
	string kelime = "abbcccaaeeeeb bfffffca ccab";

	vector<char> myV = myReturnVector(kelime, 2);
	for(unsigned p=0; p<myV.size(); p++){
		cout << myV[p];
	}

	return 0;
}
