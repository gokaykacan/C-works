//============================================================================
// Name        : Garage.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>

using namespace std;

class Garage{
private:
	bool dolu;
public:
	Garage():dolu(0){

	}
	bool isDolu(){
		return dolu;
	}
	virtual int tekerlekSayisi() =0;
	bool parkEt(){
		bool res =true;

		if(this->dolu){
			cout << "Garaj Dolu, Park Yap�lmaz !" << endl;
			res = false;
		}
		else{
			cout << "Ara� Park Edildi.." << endl;
			dolu = true;
		}

		return res;
	}
	bool parktanAl(){
		bool res = true;
		if(this->dolu){
			this->dolu = 0;
			cout << "Ara� Garajdan Al�nd�" << endl;
		}
		else{
			cout << "Garaj Zaten Bo� !" << endl;
			res = false;
		}
		return res;
	}
	virtual ~Garage(){
		this->dolu = 0;
	}

};

class Araba: public Garage{
private:
	int tekerlek;
public:
	Araba():tekerlek(4){
	}

	int tekerlekSayisi(){
		if(isDolu())
			tekerlek = 4;
		else{
			cout << "Garajda Araba Yok !" << endl;
			tekerlek = 0;
		}
		return tekerlek;
	}
};

class Motosiklet: public Garage{
private:
	int tekerlek;
public:
	Motosiklet():tekerlek(2) {
	}
	int tekerlekSayisi(){
		if(isDolu())
			tekerlek = 2;
		else{
			cout << "Garajda Araba Yok !" << endl;
			tekerlek = 0;
		}
		return tekerlek;
	}
};
int main() {

	Araba ar;
	Motosiklet mot;
	Garage *gar1 = &ar;
	Garage *gar2 = &mot;


	//Garaj Bo�ken Tekerlek Say�s� 0 d�n�yor
	cout << "Araba Teker Say�s�: " << gar1->tekerlekSayisi() << endl;

	//E�er Garaj Bo�sa Park Et, de�ilse Etme
	if(gar1->parkEt())
		//Garaj dolu ve Teker say�s� d�n�yor
		cout << "Araba Teker Say�s�: " << gar1->tekerlekSayisi() << endl;

	//Bir kez park ettik, tekrar deniyoruz
	gar1->parkEt();

	//Garaj� Bo�alt
	//gar1->parktanAl();

	cout << "Garaj �u an dolu mu: " << gar1->isDolu() << endl;

	gar2->parkEt();


	delete gar2;
	delete gar1;


	return 0;
}
