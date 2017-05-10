#ifndef _567_H__
#define _567_H__
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
namespace Sansan
{
	class Solution_567
	{
	public:
		/*
		  采用滑动窗口
		*/
		bool checkInclusion(string s1, string s2)
		{
			vector<int> v1(256,0),v2(256,0);
			int n = s1.size();
			if(n>s2.size()) return false;
			for(int i = 0; i < n; ++i)
			{
				++v1[s1[i]];
				++v2[s2[i]];
			}
			if(v1==v2) return true;
			for(int i = n; i < s2.size(); ++i)
			{
				++v2[s2[i]];
				--v2[s2[i-n]];
				if(v1 == v2) return true;
			}
			return false;
		}
		static void test()
		{
			Solution_567 solved;
			string s1="abc";
			string s2="a";
			cout<<solved.checkInclusion(s1,s2)<<endl;
		}
	};
}
#endif // _567_H__
