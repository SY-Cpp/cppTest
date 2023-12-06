#include <iostream>
#include <string>
#include <algorithm>

#include <vector>

#include <sstream>	// stringstream 

using namespace std;

/*
입력 문자열이 주어지면 단어의 순서를 반대로 바꾼다.
단어는 공백이 아닌 일련의 문자로 정의. 최소 하나의 공백으로 구분.

EX
	Input: s = "the sky is blue"
	Output: "blue is sky the"

	Input: s = "  hello world  "
	Output: "world hello"
	Explanation: Your reversed string should not contain leading or trailing spaces.

	Input: s = "a good   example"
	Output: "example good a"
	Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

Constraints
	1 <= s.length <= 104
	s contains English letters (upper-case and lower-case), digits, and spaces ' '.
	There is at least one word in s.

input
" s       pokEfM9Smb     CkB   I YR6mlSb  NMUjwXO1zT      1jYFIj5     3yKuOFv   VUgEc     SDj4      X9 yxJ7m1MFQ3     2czWYkN   mcn7t UQB      0uz   gWR  6cqWMJTboG  kc     qvpXw   Vemp     ckiI8Gnj GDgyIK7e    kJ       HNuW      G6axXAKZ     mrdlIlUz    1ei  4uriBAE       uBq     iP3V       tgn1 tcp4    OQkssUH3     Cu       JRvD YUUr0K   5NfLPJLii    EBWEJ    99q    Gw    f AkEwlaJJ12  NjygVYQxZt       o GWxAguB    gBxLKLnO   Fz2y    B   Exih2X  Ob9Z6m8o  Ko   t6      QBR     a1Lq  AU35   QN  UIRFK   PEOn4      5JQvOh jmOL42    Xd9lK1  Rmh D    PzSeb   MPh     7 b5tC6     niT    54w3VPhy  h3w5esv  5       B     gUQ     Ggi2T 4IIX84       MUfe      sgzWdNZ      yYIKbONI8U    uvZOd4d  ne0oMp     LJTF       p  6       Tu6BaSwM AUFHHl       H    kimskH9s      VdwSz     b  6M xVeFv6DNN       5M64     aT9x5LF9     vO   epjgc     isAROwj2A      0hAFVXt  nyZd5ISv  XKcRG      71J    7e9K 4P9dpRW       VAfA Rmy4M9sF       GX7Cv  k8      8yilzwDHO   J   Ljq3C      CP5096AS       Fw8  0FARKi6x1v      LUT5UeJeU  GBjxE LpF1cyNa   X9ceJx  Q2YX3r dMpdX       K Ij  Q2cOu     wg   PBvcVYz  93zgWnXC       0u   of7mdXO     I6xRvT     Ao Y9e   4l  TVi   s    1tckz5O     oJAM8y bI6ppw    h   ICtUeokj  hNooLvzq Edx1I      o   yJ0ebu   V7 60h      clMtNMYjx yuIxtWb     6    94YHa8c    YT1aXn  je06     6xV5eVX7ug  z6r   U1   6x  ss  0PZAfLVjEi  pdZJmxA9   Qy17QwX MA     Nv   j Fap3X    Lme1mm rlusXgLD     f7aX0mEs0n   RkB    tA       h8   Dli FxsVvNgq  qAb8qUO"
*/

class ReverseWords
{
public:
	string getReverseWords(string s) {

		vector<string> words;
		string temp, result;

		stringstream ss(s);

		while (getline(ss, temp, ' '))	// Split string on space
		{
			if (temp.length() > 0)		// except space
				words.push_back(temp);
		}

		int st = 0;
		int ed = words.size() - 1;
		string spc = " ";

		while (st < ed)
		{
			temp = words[st];
			words[st] = words[ed];
			words[ed] = temp;

			st++;
			ed--;
		}
		temp.clear();
		for (int i = 0; i < words.size(); i++)
		{

			temp.append(words[i]);
			if (i != (temp.size() - 1))
			{
				cout << i << " / " << words.size() << endl;
				temp.append(spc);
			}
		}
		return temp;
	}

	string getReverseWords2(string s) {
		vector<string> words;
		stringstream ss(s);
		string tmp;
		while (ss >> tmp) {
			cout << tmp << endl;
			words.push_back(tmp);
		}

		string ans;
		for (int i = words.size() - 1; i >= 0; --i) {
			if (i != words.size() - 1) ans += " ";
			ans += words[i];
		}
		return ans;
	}
	string getReverseWords3(string s) {
		reverse(s.begin(), s.end());
		int l = 0, r = 0, i = 0, n = s.size();
		while (i < n) {
			while (i < n && s[i] != ' ')
				s[r++] = s[i++];

			if (l < r) { // if we can find a non-empty word then
				reverse(s.begin() + l, s.begin() + r); // reverse current word
				if (r == n) break;
				s[r++] = ' '; // set empty space
				l = r;
			}
			++i; // now i == n or s[i] == ' ', so we skip that character!
		}
		if (r > 0 && s[r - 1] == ' ') --r; // skip last empty character if have
		s.resize(r);
		return s;
	}
};