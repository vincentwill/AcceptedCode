#ifndef _555_H_
#define _555_H_
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
namespace Sansan
{

	class Solution_555
	{
	public:
		//循环切割字符串
		string splitLoopedString(vector<string>& strs)
		{
			string temp0;
			for (int i=0;i<strs.size();i++)
			{
				string temp=strs[i];
				reverse(temp.begin(),temp.end());
				strs[i]=max(strs[i],temp);
				temp0+=strs[i];
			}
			string ret;
			for (int j=0;j<temp0.length();j++)
			{
				string temp2=temp0.substr(j)+temp0.substr(0,j);
				ret = max(ret,temp2);
			}
			return ret;
		}
		static void test()
		{
			string arr[]={"abc","xyz"};
			vector<string>str(arr,arr+2);
			Solution_555 solved;

			string ret=solved.splitLoopedString(str);
			cout << ret <<endl;
			return 0;
		}
	};
}
#endif
