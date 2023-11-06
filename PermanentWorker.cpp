#include <iostream>
#include <cstring>
using namespace std;

class PermanentWorker {
private:
	char name[100];
	int salary;	// ±Þ¿©¾×
public:
	PermanentWorker(char* name, int money)
		: salary(money) {
		strcpy(this->name, name);
	}
	int GetPay() const {
		return salary;
	}
	void ShowSalarInfo() const {
		cout << "name: " << name << endl;
		cout << "salary: " << GetPay() << endl << endl;
	}

};

class EmployeeHandler {
private:
	PermanentWorker* empList[50];
	int empNum;
public:
	EmployeeHandler() :empNum(0) {}
	void AddEmployee(PermanentWorker* emp) {
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const {

	}
};