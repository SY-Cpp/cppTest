#include <iostream>
#include <cstring>
using namespace std;

class Data
{
private:
	int data;
public:
	Data(int num) : data(num) {}
	void ShowData() {cout << "Data :" << data << endl; }
	void Add(int num) { data += num; }
};