#include <iostream>
#include <string>
#include <algorithm>

#include <vector>

using namespace std;

#include "GreatestCommonDivisorOfString.h"

/*
당신은 일부 플롯이 심어지고 일부는 심어지지 않은 긴 화단이 있습니다. 그러나 인접한 구획 에는 꽃을 심을 수 없습니다 .

' 및 '(여기서 비어 있음을 의미하고 비어 있지 않음을 의미함) 을 
flowerbed포함하는 정수 배열이 주어 지면 인접 꽃 없음 규칙을 위반하지 않고 
새 꽃을 심을 수 있는지 여부 를 반환 하고 그렇지 않으면 을 반환합니다 .
0101ntrue  n flowerbed false


입력: 화단 = [1,0,0,0,1], n = 1
 출력: true

입력: 화단 = [1,0,0,0,1], n = 2
 출력: false

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
