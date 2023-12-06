#include <iostream>

using namespace std;

/*
*
* s문자열의 모든 모음만 뒤집어서 반환합니다.
* 모음 :: 'a', 'e', 'i', 'o', 'u'

Input: s = "hello"
Output: "holle"

Input: s = "leetcode"
Output: "leotcede"

intput "aA"
Output "Aa"

Input  "race car"
Output "race car"

*/

class reverseVowels
{
public:
	bool reversCheck(char c) {
		switch (tolower(c))
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return true;
		default:
			return false;
		}

		return false;
	}
	string getReverseVowels(string s) {

		int strIndx = 0;
		int endIndx = s.size();

		while (strIndx < endIndx)
		{
			bool bst = reversCheck(s[strIndx]);
			bool bend = reversCheck(s[endIndx]);

			if (!bst)
			{
				strIndx++;
			}

			if (!bend)
			{
				endIndx--;
			}

			if (bst && bend)
			{
				char temp = s[strIndx];
				s[strIndx] = s[endIndx];
				s[endIndx] = temp;
				strIndx++;
				endIndx--;
			}
		}

		return s;
	}

	string getReverseVowels2(string s) {
		for (int i = 0; i < s.size(); i++)
		{
			if (reversCheck(s[i]))
			{
				char temp = s[i];
				for (int j = i + 1; j < s.size(); j++)
				{
					if (reversCheck(s[j]))
					{
						s[i] = s[j];
						s[j] = temp;
						break;
					}
				}
			}
		}
		return s;
	}
};
