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
        
        
        map<int,map<int, multiset<int>>> map;
        queue<pair<TreeNode*,pair<int,int>>> q;
        
        q.push({root,{0,0}});
        
        
        while(!q.empty())
        {
            auto t = q.front();
            TreeNode* add = t.first;
            int lvl = t.second.second;
            int x= t.second.first;
            q.pop();
            
            map[x][lvl].insert(add->val);
            
            
            if(add->left)
                q.push({add->left,{x-1,lvl+1}});
            if(add->right)
                q.push({add->right,{x+1,lvl +1}});
        }
        
        
        vector<vector<int>> ans;
        
        for(auto it:map)
        {
            vector<int> v;
            
            for(auto q:it.second)
            {
                v.insert(v.end(), q.second.begin(), q.second.end());
            }
            
            ans.push_back(v);
        }
        
        return ans;
        
        
    }
};