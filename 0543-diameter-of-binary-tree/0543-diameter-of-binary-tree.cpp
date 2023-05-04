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
    
    int helper(TreeNode* root, int &ans)
    {
        if(!root)
            return 0;
        
        int left_height = helper(root->left, ans);
        
        int right_height = helper(root->right, ans);
        
        
        ans = max(ans, left_height + right_height);
        
        return 1 + max(left_height, right_height);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
        
    }
};