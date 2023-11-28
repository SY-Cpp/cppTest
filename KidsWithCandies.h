#ifndef _KIDS_WITH_CANDIES_H__
#define _KIDS_WITH_CANDIES_H__

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* 아이에게 캔드를 줬을 때, 제일 많으면 true 아니면 false.
* 주어진 캔디는 적용되지 않는다.
* 
Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true]
Explanation: If you give all extraCandies to:
- Kid 1, they will have 2 + 3 = 5 candies, which is the greatest among the kids.
- Kid 2, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
- Kid 3, they will have 5 + 3 = 8 candies, which is the greatest among the kids.
- Kid 4, they will have 1 + 3 = 4 candies, which is not the greatest among the kids.
- Kid 5, they will have 3 + 3 = 6 candies, which is the greatest among the kids.

Input: candies = [4,2,1,1,2], extraCandies = 1
Output: [true,false,false,false,false]
Explanation: There is only 1 extra candy.
Kid 1 will always have the greatest number of candies, even if a different kid is given the extra candy.

Input: candies = [12,1,12], extraCandies = 10
Output: [true,false,true]

*/


class kidsWithCandies
{
public:
    vector<bool> getKidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;

        for_each(candies.begin(), candies.end(), [&](int& n)
            {
                if (*max_element(candies.begin(), candies.end()) <= n + extraCandies)
                {
                    result.push_back(true);
                }
                else
                {
                    result.push_back(false);
                }
            });

        return result;
    }


};

#endif