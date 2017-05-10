#ifndef _566_H_
#define _566_H_
#include <iostream>
#include <vector>
using namespace std;
namespace Sansan
{
    class Solution_566
    {
    public:
        vector<vector<int> > matrixReshape(vector<vector<int> >& nums, int r, int c)
        {
           int rows = nums.size();
           int cols = nums[0].size();
           if( rows*cols != r*c)
               return nums;
           vector<vector<int> >res(r,vector<int>(c,0));
           int rs=0,cs=0;
           for(int i=0;i<rows;i++)
           {
               for(int j=0;j<cols;j++)
               {
                   res[rs][cs]=nums[i][j];
                   cs++;
                   if(cs==c)
                   {
                       rs++;
                       cs=0;
                   }
               }
           }
           return res;
        }
        static void test()
        {
            Solution_566 solved;
            vector<vector<int> > maj{{1,2,3,4}};
            vector<vector<int> > ret= solved.matrixReshape(maj,2,2);
            solved.show(ret);
        }
        void show(vector<vector<int> >& nums)
        {
            int row = nums.size();
            int colum = nums[0].size();
            for (size_t i = 0; i < row; i++)
            {
              for(int j=0;j<colum;j++)
              {
                if(j==0)
                {
                    cout<<nums[i][j];
                }
                else
                {
                    cout<<","<<nums[i][j];
                }
              }
              cout<<endl;
            }
        }
    };
}
#endif
