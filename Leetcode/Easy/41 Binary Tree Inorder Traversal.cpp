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
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> v;
        stack <TreeNode*> st;
        while (root!=0 || st.size()!=0)
        {
            if (root!=0)
            {
                st.push(root);
                root=root->left;
            }
            else
            {
                root= st.top();
                st.pop();
                v.push_back(root->val);
                root=root->right;
            }
        }
        return v;
    }
};
