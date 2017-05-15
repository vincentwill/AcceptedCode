#ifndef _560_H_
#define _560_H_
#include <iostream>
#include <vector>
#include <map>
using namespace std;
namespace Sansan
{
    class Solution_560
    {
    public:
        int subarraySum(vector<int>& nums, int k)
        {
            int cum=0;
            map<int,int> rec;
            int cnt = 0;
            rec[0]++;
            for(int i=0;i<nums.size();i++){
                cum += nums[i];
                cnt += rec[cum-k];
                rec[cum]++;
            }
            return cnt;
        }
        static void test()
        {
            Solution_560 solved;
            vector<int> nums={1,2,1,3,4,-1,5};
            cout<<solved.subarraySum(nums,3)<<endl;
        }
    };
}
#endif
