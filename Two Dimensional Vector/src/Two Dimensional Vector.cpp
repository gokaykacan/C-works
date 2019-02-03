//============================================================================
// Name        : Two.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {
	//iki boyutlu vector b�yle tan�mlan�yor.
	vector< vector<int> > grid(3, vector<int>(4,7));
	grid[1].push_back(8); // 1. sat�ra 8 eleman�n� ekledik
	grid[2].pop_back(); // 2. sat�rdan son eleman� sildik
	int a = grid[1].back(); // 1. sat�rdaki en sonuncu elemana eri�me

	cout << "a: " << a << endl;

	for(unsigned int raw=0; raw<grid.size(); raw++){
		for(unsigned int col=0; col<grid[raw].size(); col++){
			cout << grid[raw][col] << flush;
		}

		cout << endl;
	}


	return 0;
}
