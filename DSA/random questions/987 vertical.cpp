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
       
        map<int,vector<int>>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto& it = q.front();
            q.pop();
            int hd= it.second;
            TreeNode* curr=it.first;
            mp[hd].push_back(curr->val);
            if(curr->left){
                q.push({curr->left,hd-1});
            }
            if(curr->right){
                q.push({curr->right,hd+1});
            }
        }
        vector<vector<int>>res;
        for(auto& it:mp){
            
            res.push_back(it.second);
        }
            for(auto& it:res){
                sort(it.begin(),it.end());
            }
        return res;
    }
};