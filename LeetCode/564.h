#ifndef _564_H_
#define _564_H_
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
namespace Sansan
{
    class Solution_564
    {
    public:
        string nearestPalindromic(string n)
        {
          set<long> palindromeList;
          int len = n.length();
          palindromeList.insert(pow(10,len)+1);
          palindromeList.insert(pow(10,len-1)-1);
          string subStr = n.substr(0,(len+1)/2);
          long val = stol(subStr);
          for (long i=-1;i<=1;i++)
          {
             string p=to_string(val+i);
             string pp = p + string(p.rbegin()+(len&1),p.rend());
             palindromeList.insert(stol(pp));
          }
          long num = stol(n),minDiff = LONG_MAX,diff,minVal;
          palindromeList.erase(num);
          for(long v:palindromeList)
          {
              diff =abs(v-num);
              if(diff<minDiff)
              {
                  minDiff = diff;
                  minVal = v;
              }
              if(diff == minDiff)
              {
                  minVal = min(minVal,v);
              }
           }
          return to_string(minVal);
        }
        static void test()
        {
            Solution_564 solved;
            string str1="10";
            cout<<solved.nearestPalindromic(str1)<<endl;
        }
    };
}
#endif/* _546_H_*/
