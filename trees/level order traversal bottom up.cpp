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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr)
            return{};
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            vector<int>node;
            int n=q.size();
            while(n>0)
            {
                TreeNode*front=q.front();
                node.push_back(front->val);
                q.pop();
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
                //q.pop();
                //node.push_back(front->val);
                n--;
            }
            ans.push_back(node);
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
