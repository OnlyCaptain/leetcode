/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTreeSub(vector<int>& preorder, int pre_i, vector<int>& inorder, int in_i, int in_num) {
        if (in_num == 0) return nullptr;
        cout << pre_i << " " << in_i << " " << in_num << endl;
        TreeNode* root = new TreeNode(preorder[pre_i]);
        if (in_num == 1) return root;
        int sub_num = 0, sub_i = in_i;
        if (in_i + in_num - 1 > preorder.size()) {
            cout << "error ";
            cout << pre_i << " " << in_i << " " << in_num << endl;
        }
        for (int i = in_i; i < in_i + in_num; i ++) {
            if (inorder[i] == preorder[pre_i]) {
                sub_num = i - in_i;
                sub_i = i + 1;
                break;
            }
        }
        root->left = buildTreeSub(preorder, pre_i + 1, inorder, in_i, sub_num);
        if (pre_i + sub_num + 1 > preorder.size()) return root;
        root->right = buildTreeSub(preorder, pre_i+sub_num+1, inorder, sub_i, in_num-sub_num-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        int in_num = inorder.size();
        if (!in_num) return root;
        root = buildTreeSub(preorder, 0, inorder, 0, in_num);
        return root; 
    }
};