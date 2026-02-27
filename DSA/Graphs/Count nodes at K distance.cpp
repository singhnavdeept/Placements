/*

class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>mp;
    void build(TreeNode* node , TreeNode prev){
        if(!node)return ;
        mp[node]=prev;
        build(node->left,node);
        build(node->right,node);
        return ;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        build(root,NULL);
        queue<TreeNode*>q;
        q.push(target);
        int distance=k;
        int co
        while(!q.empty()){
            

        }

    }
};
*/