#ifndef _538_H_
#define _538_H_
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 namespace Sansan
 {
	 class Solution_542
	  {
	 public:
	     TreeNode* convertBST(TreeNode* root)
	 	 {
	         stack<TreeNode*>nodeContain;
			 TreeNode* ptr = root;
			 std::vector<int> array;
			 while (ptr || !nodeContain.empty())
			 {
				while (ptr)
				{
                    nodeContain.push(ptr);
					ptr = ptr->left;
				}
				ptr = nodeContain.top();
				nodeContain.pop();
				array.push_back( ptr->val );
				ptr=ptr->right;
			 }
			 int sum=0;
			 for (int i = array.size()-1; i>=0; i-- )
			 {
				 sum += array[i];
				 array[i] = sum;
			 }
			 ptr = root;
			 int cnt=0;
			 while (ptr || !nodeContain.empty())
			 {
				while (ptr)
				{
					nodeContain.push(ptr);
					ptr = ptr->left;
				}
				ptr = nodeContain.top();
				nodeContain.pop();
			    ptr->val = array[cnt++];
				ptr=ptr->right;
			 }
			 return root;
	     }
		void preOrderTree(TreeNode* root)
		{
			if(root)
			{
			    preOrderTree(root->left);
				cout<< root->val << endl;
				preOrderTree(root->right);
			}
		}
	 	static void test()
	 	{
             Solution_542 solved;
			 TreeNode* root = new TreeNode(5);
			 root->left = new TreeNode(2);
			 root->right = new TreeNode(13);
			 root->left->left = new TreeNode(1);
			 root->left->right = new TreeNode(3);
			 root->right->left = new TreeNode(14);
			 root->right->right = new TreeNode(15);
			 TreeNode* ret = solved.convertBST(root);
			 solved.preOrderTree(ret);

	 	}
	 };
 }
#endif//_538_H_
