//============================================================================
// Name        : Ring.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ring.h"

using namespace std;

int main() {

	ring<string> textring(3);

	textring.add("one");
	textring.add("two");
	textring.add("three");
	textring.add("four");
	textring.add("five");

	for(int i=0; i<textring.size(); i++){
		cout << textring.get(i) << endl;
	}


	return 0;
}
