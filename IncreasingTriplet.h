#include <iostream>
#include <string>
#include <algorithm>

#include <vector>

using namespace std;

/*
 Given an integer array nums, return true
	if there exists a triple of indices (i, j, k) such that i < j < k
	and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

EX
	Input: nums = [1,2,3,4,5]
	Output: true
	Explanation: Any triplet where i < j < k is valid.

	Input: nums = [5,4,3,2,1]
	Output: false
	Explanation: No triplet exists.

	Input: nums = [2,1,5,0,4,6]
	Output: true
	Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.

Constraints
	1 <= nums.length <= 5 * 105
	-231 <= nums[i] <= 231 - 1

input [20,100,10,12,5,13]
Expected	true

input [2,4,-2,-3]
Runtime Error
Expected	false

input [0,4,2,1,0,-1,-3]
Expected	false

intput [1,5,0,4,1,3]
Expected true

intput
Time Limit Exceeded

*/

class IncreasingTriplet
{
public:
	// submit
	bool getIncreasingTriplet3(vector<int>& nums) {
		int num1 = INT_MAX, num2 = INT_MAX;
		int ind1 = INT_MAX, ind2 = INT_MAX;
		for (int n : nums)
		{
			if (n <= num1)
			{
				num1 = n;
				ind1 = n;
			}
			else if (n <= num2 || ind1 > ind2)		// n > num1 , 
			{
				num2 = n;
				ind2 = n;
			}
			else
			{
				return true;
			}
		}

		return false;
	}

	bool getIncreasingTriplet(vector<int>& nums) {
		int len = nums.size();
		int min = *min_element(nums.begin(), nums.end());
		if (len < 3)
		{
			return false;
		}
		else
		{
			for (int i = 0; i < len; i++)
			{
				int f = nums[i];
				for (int j = i + 1; j < len; j++)
				{
					int s = nums[j];
					if (f < s)
					{
						for (int k = j + 1; k < len; k++)
						{
							int t = nums[k];
							if (s < t)
								return true;
						}
					}
				}
				if (f == min)
					break;
			}
		}
		return false;
	}
	bool getIncreasingTriplet2(vector<int>& nums) {
		int len = nums.size();
		if (len < 3)
		{
			return false;
		}
		else
		{
			int i = 0, j = i + 1, k = j + 1;
			int min = *min_element(nums.begin(), nums.end());
			while (i <= len)
			{
				if (j >= len)
				{
					if (nums[i] == min || i >= len - 2)
						return false;
					i++;
					j = i + 1;
					k = j + 1;
				}
				int f = nums[i], s = nums[j];
				if (f < s)
				{
					if (k >= len)
					{
						j++;
						k = j + 1;
						continue;
					}
					int t = nums[k];
					cout << "k (" << k << ") : " << t << endl;
					if (s < t)
						return true;
					else
					{
						k++;

					}
				}
				else
				{
					j++;
				}

			}
		}
		return false;
	}


};
