#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class R_Random {

public:
	
	R_Random(int s, char b, int e);  // This is the constructor
	void setSize(int s);
	int getSize(void);
	void setBegin(char b);
	char getBegin(void);
	void setEnd(int e);
	int getEnd(void);
	void Param(void);

private:
	int size,end;
	char begin;
};


// Member functions definitions including constructor
R_Random::R_Random(int s, char b, int e) {
	size = s;
	begin = b;
	end = e;
}

void R_Random::setSize(int s) {
	size = s;
}

int R_Random::getSize(void) {
	return size;
}

void R_Random::setBegin(char b) {
	begin = b;
}

char R_Random::getBegin(void) {
	return begin;
}

void R_Random::setEnd(int e) {
	end = e;
}
int R_Random::getEnd(void) {
	return end;
}

void R_Random::Param(void) {
	char* tab = new char;
	srand(time(NULL));

	for(int i=0; i<size; i++) {
		tab[i] = begin + rand()%end;
		cout << tab[i];
	}
	cout << endl;
}


// Main function for the program
int main(int argc, char* argv[]) {

	int MySize;
	char kind;
	cout << "/* Password Generator */" << endl << endl;
	cout << "How long is the password supposed to be?" << endl;
	cin >> MySize;
	cout << "What kind of password do you wish?" << endl;
	cout << "Big letter - b, Small letters - s, No limits - n" << endl;
	cin >> kind;

	cout << endl;
	
	R_Random obj(MySize, 'a', 25);

	switch(kind) {
		case 'b' : obj.setBegin('A'); break;
		case 'n' : obj.setBegin('!'); obj.setEnd(74); break;
	}

	obj.Param();	
	cout << endl;
	return 0;
}
