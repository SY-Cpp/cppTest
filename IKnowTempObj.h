#include <iostream>

using namespace std;

class Temporary {
private:
	int num;
public:
	Temporary(int n) : num(n) {
		//cout << "create obj :" << num << endl;
		cout << "New Object :" << this << endl;
	}
	Temporary(const Temporary& copy) : num(copy.num) {
		cout << "New Copy Object :" << this << endl;
	}
	~Temporary() {
		//cout << "Destroy obj:" << num << endl;
		cout << "Destroy obj:" << this << endl;

	}

	void ShowTempInfo() {
		cout << "My num is " << num << endl;
	}
};

Temporary TemporaryFuncObj(Temporary ob) {
	cout << "Param ADR:" << &ob << endl;
	return ob;
}



