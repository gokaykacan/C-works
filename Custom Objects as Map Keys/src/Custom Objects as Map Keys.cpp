//============================================================================
// Name        : Custom.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
using namespace std;

class Person{
private:
	string name;
	int age;

public:
	Person(): name(""), age(0){
	}
	Person(string name, int age):
		name(name), age(age){
	}
	void print() const {
		cout << name << ": " << age << endl;
	}
	//operator overload yapmasayd�k, compile a�a��daki for d�ng�s�nde
	//�nce hangisini yazd�raca��n� bilemezdi, ��nk� hangi s�raya g�re
	//yazd�raca��n� bilmiyor.! Burada < (k���kt�r) operatorunu overload yapt�k
	bool operator<(const Person &other) const{
		if(name == other.name)//e�er isimler ayn�ysa ya�a g�re
			return age < other.age;
		else // isimler ayn� de�ilse alfabetik duruma g�re
			return name < other.name;
	}
};

int main() {
	map<Person, int> people;
	people[Person("Andy", 40)] = 40;
	people[Person("Andy", 40)] = 50; // ayn�s�n� tan�mlad�k, art�k bu ge�erli
	//burada bunu da art�k yazd�racak, isim ayn� ya� s�ras�na g�re !
	//��nk� yukarda overload tan�mlad�k
	people[Person("Andy", 440)] = 120;
	people[Person("Sue", 30)] = 30;
	people[Person("Gokay", 27)] = 27;

	for(map<Person, int>::iterator it = people.begin(); it != people.end(); it++){
		cout << it->second << ": " << flush;
		it->first.print();
	}

	return 0;
}
