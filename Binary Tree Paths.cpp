// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        17 Dec 2021
//  @Detail  :        Binary Tree Paths (LeetCode)
//  ============================
//  -->

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return {};
        if(!root -> left && !root -> right)
            return {to_string(root -> val)};
        vector<string> result;
        
        vector<string> lTree = binaryTreePaths(root -> left);
        vector<string> rTree = binaryTreePaths(root -> right);
        
        for(string &x : lTree)
        {
            x = to_string(root -> val) + "->" + x;
            result.push_back(x);
        }
        
        for(string &x : rTree)
        {
            x = to_string(root -> val) + "->" + x;
            result.push_back(x);
        }
        return result;
    }
};
