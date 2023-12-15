#include <iostream>
#include <vector>

using namespace std;

/**
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.


EX
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

Input: nums = [0,1,1,1,0,1,1,0,1]
0 indx :: 0 / 4 / 7
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.

Constraints
1 <= nums.length <= 105
nums[i] is either 0 or 1.

**/

class LongestSubarray
{
public:
    int getLongestSubarray(vector<int>& nums) {
        int result = INT_MIN, left = 0, right = 0;
        bool zeroCheck = false;

        for (int i = 0; i < nums.size(); i++)
        {

            if (nums[i] == 0)
            {
                if (zeroCheck)
                {
                    result = max(result, (left + right));
                    left = right;
                    right = 0;
                }
                else
                    zeroCheck = true;
            }
            else
            {
                if (zeroCheck)
                {
                    right++;
                }
                else
                {
                    left++;
                }
            }

        }

        result = max(result, (left + right));

        if (!zeroCheck)
        {
            result -= 1;
        }

        return result;
    }


    int getLongestSubarray2(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int zeros = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) {
                zeros++;
            }
            while (zeros > 1) {
                if (nums[left] == 0) {
                    zeros--;
                }
                left++;
            }
            ans = max(ans, right - left + 1 - zeros);
        }
        return (ans == n) ? ans - 1 : ans;
    }

};