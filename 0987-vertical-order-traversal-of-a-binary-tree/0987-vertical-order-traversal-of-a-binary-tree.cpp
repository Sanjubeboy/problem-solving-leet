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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> ds;
        
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        q.push({root,{0,0}});
        
        while(!q.empty())
        {
            
            auto t = q.front();
            TreeNode* node = t.first;
            int lvl = t.second.first;
            int vert = t.second.second;
            q.pop();
            
            ds[vert][lvl].insert(node->val);
            
            
            if(node->left)
            {
                q.push({node->left, {lvl+1, vert-1}});
            }
            
            if(node->right)
            {
                q.push({node->right, {lvl+1, vert+1}});
            }
            
        }
        
        
        for(auto it:ds)
        {
            vector<int> temp;
            for(auto i:it.second)
            {
                temp.insert(temp.end(), i.second.begin(), i.second.end());
            }
            
            ans.push_back(temp);
            
        }
        
        
        return ans;
    }
};