#ifndef _556_H__
#define _556_H__
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
/*******************************************************
  *  @Copyright (c) 2017, Zugzwang, All rights reserved. 

  *  @file     : 556.h 
  *  @version  : ver 1.0 
 
  *  @author   : Zugzwang
  *  @date     : 2017/04/11 10:43 
  *  @brief    : Leetcode 556题 Next Greater Element III
*******************************************************/
namespace Sansan
{
	class solution_556
	{
	public:
        /*
         *	1、首先把n转化为字符串
		    2、从后往前找到第一个可以被替换的字符。即出现str[idx] < curMax，即curPos
			3、把str从curPos以后的数字有小到大排序
			4、把swapPos1位置的字符与它位置之后的字符（第一个比它大的字符）交换位置
		    5、越界检查
         */
		int nextGreaterElement(int n) 
		{
			string str = to_string(n);
			int curPos = str.length()-1,curMax=-1;
			for (int idx = curPos; idx >= 0 ; idx--)
			{
				if (str[idx] - '0' >= curMax)
				{
					curMax = str[idx] - '0';
					curPos = idx;
				}
				else
				{
					break;
				}
			}
			if (curPos == 0)
			{
				return -1;
			}
			int swapPos1 = curPos -1;
			sort(str.begin() + curPos,str.end());
			int swapPos2 = str.length()-1;
			while (swapPos2 >=curPos && str[swapPos2] > str[swapPos1])
			{
				swapPos2--;
			}
			char swapChar = str[swapPos2+1];
			str[swapPos2+1] = str[swapPos1];
			str[swapPos1] = swapChar;
			if (str.compare(to_string(INT_MAX))>0)
			{
				return -1;
			}
			return stoi(str);
		}
		static void test()
		{
			solution_556 test;
			cout<<test.nextGreaterElement(1999999999)<<endl;
		}

	};


}

#endif // _556_H__
