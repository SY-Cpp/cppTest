#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/**
Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.

EX
Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].

Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].

Constraints
1 <= nums1.length, nums2.length <= 1000
-1000 <= nums1[i], nums2[i] <= 1000


**/

#define INPUT_DATA	{1,2,3,3}
#define INPUT_DATA2 {1,1,2,2}



class FindDifference
{
public:
	vector<vector<int>> getFindDifference(vector<int>& nums1, vector<int>& nums2) {
		vector<vector<int>> result;

		/* vector distinct step 1 */
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		/* vector distinct step 2 */
		nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());
		nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());

		int i = 0, len = nums1.size();
		while (i < len)
		{
			if (find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end())
			{
				int j = find(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
				nums1.erase(nums1.begin() + i);
				nums2.erase(nums2.begin() + j);
				len--;
			}
			else
				i++;
		}

		cout << endl;
		cout << "nums1 :: ";
		for (int n : nums1)
			cout << n << " ";

		cout << endl;
		cout << "nums2 :: ";
		for (int n : nums2)
			cout << n << " ";

		result.push_back(nums1);
		result.push_back(nums2);

		return result;
	}

	vector<vector<int>> getFindDifference2(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> set1(nums1.begin(), nums1.end());
		unordered_set<int> set2(nums2.begin(), nums2.end());

		vector<int> distinct_nums1, distinct_nums2;
		for (int num : set1) {
			if (set2.count(num) == 0) {
				distinct_nums1.push_back(num);
			}
		}

		for (int num : set2) {
			if (set1.count(num) == 0) {
				distinct_nums2.push_back(num);
			}
		}

		return { distinct_nums1, distinct_nums2 };
	}
};