#ifndef _553_h__
#define _553_h__
#include <iostream>
#include <vector>
#include <string>
using namespace std;
namespace Sansan
{
	class Solution_553
	{
	public:
		/*
           假如nums中有n个数，只要在2~n加括号即可
		   即nums[0]/(nums[1]/nums[2]/..../nums[n-1])即可得到最大值
		*/
		string optimalDivision(vector<int>& nums)
		{
			int len = nums.size();
			string ret;
			if (len==1)
			{
				return to_string(static_cast<long long>(nums[0]));
			}
			if (len==2)
			{
				return to_strings(tatic_cast<long long>(nums[0]))+"/"+to_string(static_cast<long long>(nums[1]));
			}
			for (int i=0;i<len;i++)
			{
				if (i==0)
				{
					ret+=to_string(static_cast<long long>(nums[i]));
					ret+="/(";
				}
				else
				{
					ret+=to_string(static_cast<long long>(nums[i]));
					ret+="/";
				}
			}
			ret.pop_back();
			ret+=")";
			return ret;
		}
		static void test()
		{
			Solution_553 solv;
			int arr[]={1000,100,10,2};
			vector<int> nums(arr,arr+4);
			cout<< solv.optimalDivision(nums)<<endl;
		}
	};
}

#endif // _554_h__
