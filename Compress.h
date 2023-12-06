#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:
							-- 연속적으로 반복되는 문자

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

EX
	Input: chars = {'a','a','b','b','c','c','c'}
	Output: Return 6, and the first 6 characters of the input array should be: {'a','2','b','2','c','3'}
	Explanation: The groups are 'aa', 'bb', and 'ccc'. This compresses to 'a2b2c3'.

	Input: chars = {'a'}
	Output: Return 1, and the first character of the input array should be: {'a'}
	Explanation: The only group is 'a', which remains uncompressed since it's a single character.


	Input: chars = {'a','b','b','b','b','b','b','b','b','b','b','b','b'}
	Output: Return 4, and the first 4 characters of the input array should be: {'a','b','1','2'}.
	Explanation: The groups are 'a' and 'bbbbbbbbbbbb'. This compresses to 'ab12'.

Constraints
	1 <= chars.length <= 2000
	chars[i} is a lowercase English letter, uppercase English letter, digit, or symbol.


*/


class compress
{
public:
	int gCompress(vector<char>& chars) {
		vector<char> result;
		char temp = chars[0];
		int cnt = 0, len = chars.size();

		if (len == 1) {
			result.push_back(temp);
		}
		else {
			for (int i = 0; i < chars.size(); i++)
			{
				if (temp == chars[i]) {
					cnt++;
				}
				else {
					result.push_back(temp);
					if (cnt > 1)
					{
						for (char c : to_string(cnt))
						{
							result.push_back(c);
						}
					}
					temp = chars[i];
					cnt = 1;
				}

				if (i == chars.size() - 1)
				{
					result.push_back(temp);
					if (cnt > 1)
					{
						for (char c : to_string(cnt))
						{
							result.push_back(c);
						}
					}
				}
			}
		}

		chars = result;

		return result.size();
	}

	// clean code
	int gCompress2(vector<char>& chars) {
		int ans = 0;

		// iterate through input vector using i pointer
		for (int i = 0; i < chars.size();) {
			const char letter = chars[i];		// current character being compressed
			int count = 0;						// count of consecutive occurrences of letter

			// count consecutive occurrences of letter in input vector
			while (i < chars.size() && chars[i] == letter) {
				++count;
				++i;
			}

			// write letter to compressed vector
			chars[ans++] = letter;

			// if count is greater than 1, write count as string to compressed vector
			if (count > 1) {
				// convert count to string and iterate over each character in string
				for (const char c : to_string(count)) {
					chars[ans++] = c;
				}
			}
		}

		// return length of compressed vector
		return ans;
	}
};