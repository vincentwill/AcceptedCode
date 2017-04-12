#ifndef _554_H__
#define _554_H__
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
namespace Sansan
{
	class solution_554
	{
	public:
    int leastBricks(vector<vector<int> >& wall)
	{
	   unordered_map<int,int>weigh2cnt;
	   int totalWeight = 0,height=wall.size();
	   for (int i = 0; i < wall.size(); i++)
	   {
		   int rowSum=0;
		   for (int j = 0; j < wall[i].size(); j++)
		   {
			   rowSum += wall[i][j];
			   weigh2cnt[rowSum]++;
		   }
		   totalWeight = rowSum;
	   }
	   auto ptr = weigh2cnt.begin();
	   int curCnt=0;
	   while (ptr != weigh2cnt.end())
	   {
		   if (ptr->first != totalWeight && ptr->second > curCnt)
		   {
			   curCnt = ptr->second;
		   }
		   ptr++;
	   }
	   return height-curCnt;
	}

    static void test()
	{
		int a0[] = {1,2,2,1};vector<int>b0(a0,a0+4);
		int a1[] = {3,1,2};vector<int>b1(a1,a1+3);
		int a2[] = {1,3,2};vector<int>b2(a2,a2+3);
		int a3[] = {2,4};vector<int>b3(a3,a3+2);
		int a4[] = {3,1,2};vector<int>b4(a4,a4+3);
		int a5[] = {1,3,1,1};vector<int>b5(a5,a5+4);
		vector<vector<int>>wall;
		wall.push_back(b0);
		wall.push_back(b1);
		wall.push_back(b2);
		wall.push_back(b3);
		wall.push_back(b4);
		wall.push_back(b5);
		solution_554 test;
		cout<<test.leastBricks(wall)<<endl;
	}
	};

}

#endif // _554_H__
