#ifndef _MERGE_STRING_ALTERNATELY_H__
#define _MERGE_STRING_ALTERNATELY_H__

#include <iostream>
#include <string>

using namespace std;

//1 <= word1.length, word2.length <= 100
//word1 and word2 consist of lowercase English letters.

class MergeString 
{
public:
	string mergeAlternately(string word1, string word2) {
		string result;

		int len = (word1.size() >= word2.size()) ? word1.size() : word2.size();

		for (int i = 0; i < len; i++)
		{
			if (word1.size() > i)
			{
				result += word1.at(i);
			}
			if (word2.size() > i)
			{
				result.push_back(word2[i]);
			}
		}


		return result;
	}
};

#endif