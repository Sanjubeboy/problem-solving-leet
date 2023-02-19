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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(!root)
            return {};
            
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> temp(size);
            int i=0,s=size;
            
            while(size--)
            {
                
                auto t = q.front();
                q.pop();
                
                if(flag == 0)
                {
                    temp[i]=t->val;
                    i++;
                }
                
                else
                {
                    temp[s-i-1] = t->val;
                    i++;
                }
                
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
                          
            }
            
            ans.push_back(temp);
            flag = !flag;
        }
        
        
        return ans;
    }
};