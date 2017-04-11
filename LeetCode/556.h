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
  *  @brief    : Leetcode 556�� Next Greater Element III
*******************************************************/
namespace Sansan
{
	class solution_556
	{
	public:
        /*
         *	1�����Ȱ�nת��Ϊ�ַ���
		    2���Ӻ���ǰ�ҵ���һ�����Ա��滻���ַ���������str[idx] < curMax����curPos
			3����str��curPos�Ժ��������С��������
			4����swapPos1λ�õ��ַ�����λ��֮����ַ�����һ����������ַ�������λ��
		    5��Խ����
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
