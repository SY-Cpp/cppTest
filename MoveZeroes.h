#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

EX
	Input: nums = {0,1,0,3,12}
	Output: {1,3,12,0,0}

	Input: nums = {0}
	Output: {0}

Constraints
	1 <= nums.length <= 104
	-231 <= nums[i] <= 231 - 1

input [0,0,1]
expec [1,0,0]
*/


class MoveZeroes {
public:
	void getMoveZeroes(vector<int>& nums) {

		int cnt = 0;
		for (int n : nums)
		{
			if (n == 0)
				cnt++;
		}

		nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());

		while (cnt > 0)
		{
			nums.push_back(0);
			cnt--;
		}
	}

	void getMoveZeroes2(vector<int>& nums) {

		int j = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != 0) {
				nums[j++] = nums[i];
			}
		}

		for (; j < nums.size(); j++) {
			nums[j] = 0;
		}
	}
};