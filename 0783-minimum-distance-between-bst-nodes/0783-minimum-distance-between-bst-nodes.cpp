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
    
    void helper(TreeNode* root, vector<int> &inorder)
    {
        if(!root)
            return;
        
        helper(root->left, inorder);
        inorder.push_back(root->val);
        
        helper(root->right, inorder);
        
    }
    int minDiffInBST(TreeNode* root) {
        
        vector<int> inorder;
        helper(root,inorder);
        int res=INT_MAX;
        
        for(int i=1; i<inorder.size(); i++)
        {
            res=min( res, abs(inorder[i] - inorder[i-1]));
        }
        
        return res;
        
    }
};