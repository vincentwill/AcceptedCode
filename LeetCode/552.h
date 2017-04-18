#ifndef _552_H_
#define _552_H_
#include <iostream>
#include <vector>
using namespace std;
/**
 * Leetcode Student Attendance Record II
 * @param  n:开会次数
 * @return 总共受奖励的总数
 */
namespace Sansan
{

            class Solution_552
            {
            public:
                //函数使用动态规划dp[i][j][k]表示前i次会议受奖励的次数
                //其中j表示前i次会议的中‘A’的次数,即j可以有0,1.
                //k表示前i次会议中'L'的次数，即前i次会议中尾部最多迟到k次，k=0,1,2.
                int checkRecord(int n)
                {
                   vector<vector<long> > dp(2,vector<long>(3,0));
                   long remain=1e9+7;
                   dp[0][0]=1;dp[0][1]=1;dp[0][2]=0;
                   dp[1][0]=1;dp[1][1]=0;dp[1][2]=0;//初始状态即n=1时
                   long ret=0;
                   for (size_t idx = 2; idx <= n; idx++)
                   {
                       vector<vector<long> > temp(2,vector<long>(3,0));
                       for (size_t j = 0; j < 2; j++)
                       {//前i次会议中'A'出现次数
                          for (size_t k = 0; k < 3; k++)
                          {
                              if(k==0 && j==0)
                              {
                                  temp[0][0]=(dp[0][0]+dp[0][1]+dp[0][2])%remain;
                              }
                              if(k==0 && j==1)
                              {
                                  temp[1][0]=(dp[1][0] + dp[1][1] + dp[1][2] + dp[0][0] + dp[0][1]+dp[0][2])%remain;
                              }
                              if(k > 0)
                              {
                                  temp[j][k] = (dp[j][k-1])%remain;
                              }
                          }

                       }
                       dp = temp;
                   }
                   for (size_t i = 0; i < 2; i++)
                   {
                       for (size_t j = 0; j < 3; j++)
                       {
                           ret += (dp[i][j])%remain;
                       }
                   }
                   return ret%remain;
                }
                static void test()
                {
                    Solution_552 test;
                    cout << test.checkRecord(100) <<endl;
                    return;
                }
            };
}
#endif
