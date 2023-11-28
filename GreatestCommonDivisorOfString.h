#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//Example 1:
//
//Input: str1 = "ABCABC", str2 = "ABC"
//Output : "ABC"
//Example 2 :
//
//	Input : str1 = "ABABAB", str2 = "ABAB"
//	Output : "AB"
//	Example 3 :
//
//	Input : str1 = "LEET", str2 = "CODE"
//	Output : ""

//문자열의 최대 공약수
//1 <= str1.length, str2.length <= 1000
//str1 and str2 consist of English uppercase letters.

/*
*  솔루션 보고 가져온 코드
*/

class StringDivision
{
public:
    string joinWords(string str, int k) {
        string ans = "";
        for (int i = 0; i < k; ++i) {
            ans += str;
        }
        cout << "return ans :: " << ans << endl;
        return ans;
    }

    bool valid(string str1, string str2, int k) {
        int len1 = str1.size(), len2 = str2.size();
        cout << "len1 :: " << len1 << "len2 :: " << len2 << endl;
        if (len1 % k > 0 || len2 % k > 0) {
            cout << "return false" << endl;
            return false;
        }
        else {
            string base = str1.substr(0, k);
            int n1 = len1 / k, n2 = len2 / k;
            cout << "base :: " << base << " n1 :: " << n1 << " n2 :: " << n2 << endl;
            return str1 == joinWords(base, n1) && str2 == joinWords(base, n2);
        }
    }

    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length(), len2 = str2.length();
        for (int i = min(len1, len2); i >= 1; --i) {
            if (valid(str1, str2, i)) {
                return str1.substr(0, i);
            }
        }
        return "";
    }

    void test()
    {
        string str1, str2;

        int len1 = str1.size(), len2 = str2.size();

        if (len1 >= len2)
        {

            if (str1.substr(0, len2) == str2)
            {
                cout << str1.substr(0, len2);
            }

        }
        else
        {
            if (str2.substr(0, len1) == str1)
            {
                cout << str2.substr(0, len1);
            }
        }

    }
};