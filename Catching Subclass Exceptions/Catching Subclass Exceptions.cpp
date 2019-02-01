#include <iostream>
#include <exception>
using namespace std;

void goesWrong(){

	bool error1detected = false;
	bool error2detected = true;

	if (error1detected){
		throw exception();
	}
	if (error2detected){
		throw bad_alloc();
	}
}

int main(){

	try{
		goesWrong();
	}
	catch(exception &e){
		cout << "Catching Exception: " << e.what() << endl;
	}
	/*
	   bad_alloc �nce yakalanmaya �al���lmal�, ��nk� exception s�n�f�n�n bir alt s�n�f�d�r.
	   Bu y�zden Yukar�daki catch �nce yakalar.
	   Subclass lar hata yakalamaya �al���rken �stte yakalanmaya �al���lmal�d�r
	*/
	catch(bad_alloc &e){
		cout << "Catching bad_alloc" << e.what() << endl;
	}

	return 0;
}
