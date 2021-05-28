/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root, bool & isbal) {
        int lh,rh;
        if (root==nullptr)
            return 0;
        if(isbal==false)
            return 0;
        
        lh=maxDepth(root->left,isbal);
        rh=maxDepth(root->right,isbal);
        if (abs(lh-rh)>1)
            isbal=false;
      
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        bool isbal = true;
        int ht= maxDepth(root,isbal);
        return isbal;
    }
};
