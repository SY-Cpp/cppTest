#ifndef _TWO_SUM_H__
#define _TWO_SUM_H__

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TwoSum
{
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> resultVc = {};
		int num1, num2;
		for (int i = 0; i < nums.size(); i++)
		{
			num1 = nums[i];
			for (int j = 1; j < nums.size(); j++)
			{
				num2 = nums[j];

				if (i == j)
				{
					cout << i << " == " << j << endl;
					break;
				}

				if (target == (num1 + num2))
				{
					resultVc.push_back(i);
					resultVc.push_back(j);
					return resultVc;
				}
			}
		}

		return resultVc;
	}
	void test()
	{
		vector<int> vc = { 1,1,3,4 };

		cout << "for_each vector" << endl;

		for_each(vc.begin(), vc.end(), [&](int& n)
			{
				cout << n << endl;
			});

		TwoSum tvc;

		vector<int> result = tvc.twoSum(vc, 5);

		for_each(result.begin(), result.end(), [&](int& n)
			{
				cout << n;
			});
		cout << endl;
		vector<int>::iterator itr = vc.begin();

		cout << "using iterator for" << endl;

		for (itr; itr != vc.end(); itr++)
		{
			cout << *itr << endl;
		}

		vector<int>::reverse_iterator itr2 = vc.rbegin();

		cout << "using reverse_iterator for" << endl;

		for (itr2; itr2 != vc.rend(); itr2++)
		{
			cout << *itr2 << endl;
		}

		cout << endl;

		cout << vc.front() << endl;
		cout << vc.back() << endl;
		cout << endl;
		cout << vc.at(0) << endl;
		cout << vc.at(1) << endl;
		cout << vc.at(2) << endl;
		cout << vc.at(3) << endl;
		cout << endl;
		cout << vc[0] << endl;
		cout << vc[1] << endl;
		cout << vc[2] << endl;
		cout << vc[3] << endl;
		cout << endl;

		cout << "vector size :: " << vc.size() << endl;

		for (int i = 0; i < vc.size(); i++)
		{
			cout << vc[i] << endl;
		}
	}
};

#endif