#include <iostream>
#include <string>
#include <algorithm>

#include <vector>

#include <sstream>	// stringstream 
#include <float.h>	// DBL_MAX

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

0,1,0,1,1,1,0,1,0,1,1,1,1,0,1
0,1,1,1,1,0,0,0,1,1,1,1,0,1,0
**/

#define INPUT_DATA	{1,1,0,1}
#define INPUT_DATA2 3



int main(void) {
	vector<int> data = INPUT_DATA;
	int k = INPUT_DATA2;
	
	//cout << longestSubarray(data) << endl;

	return 0;
}
 