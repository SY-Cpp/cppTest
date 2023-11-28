#include <iostream>
#include <string>
#include <algorithm>

#include <vector>

using namespace std;

#include "GreatestCommonDivisorOfString.h"

/*
����� �Ϻ� �÷��� �ɾ����� �Ϻδ� �ɾ����� ���� �� ȭ���� �ֽ��ϴ�. �׷��� ������ ��ȹ ���� ���� ���� �� �����ϴ� .

' �� '(���⼭ ��� ������ �ǹ��ϰ� ��� ���� ������ �ǹ���) �� 
flowerbed�����ϴ� ���� �迭�� �־� ���� ���� �� ���� ��Ģ�� �������� �ʰ� 
�� ���� ���� �� �ִ��� ���� �� ��ȯ �ϰ� �׷��� ������ �� ��ȯ�մϴ� .
0101ntrue  n flowerbed false


�Է�: ȭ�� = [1,0,0,0,1], n = 1
 ���: true

�Է�: ȭ�� = [1,0,0,0,1], n = 2
 ���: false

1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length

input 
	1,0,0,0,1,0,0		/  2
	0	/	1
	0,0,1,0,0	/	1

*/

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
	bool check = false;

	for (int i = 0; i < flowerbed.size(); i++)
	{
		if (flowerbed[i])
		{
			check = true;
		}
		else if (!check && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))
		{
			n--;
			check = true;
		}
		else
		{
			check = false;
		}
	}

	return (n <= 0);
}

int main(void) {



	return 0;
}
