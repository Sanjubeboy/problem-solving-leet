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
    
    int helper(TreeNode* root, int &maxi)
    {
        
        if(!root)
            return 0;
        
        int lh = helper(root->left, maxi);
        int rh = helper(root->right, maxi);
        
        int path = root->val + lh + rh;
        maxi = max(maxi, path);
        if(path < 0)
        {
            return 0;
        }
        
        
        return root->val + max(lh, rh);
        
    }
    int maxPathSum(TreeNode* root) {
        
        int maxi=INT_MIN;
        helper(root, maxi);
        return maxi;
        
    }
};