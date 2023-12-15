#include <iostream>
#include <vector>

using namespace std;

class PivotIndex
{
public:
    int getPivotIndex(vector<int>& nums) {
        int len = nums.size();
        int indx = 0;

        while (indx < len)
        {
            int left = 0, right = 0;
            for (int i = 0; i < indx; i++)
                left += nums[i];

            for (int j = len - 1; j > indx; j--)
                right += nums[j];

            if (left == right)
                return indx;

            indx++;

        }

        return -1;
    }

	int getPivotIndex2(vector<int> nums)
	{
		int total = 0, left = 0;

		for (int n : nums)
			total += n;

		for (int i = 0; i < nums.size(); left += nums[i++])
		{
			if (left * 2 == total - nums[i])
				return i;
		}

		return -1;
	}



};