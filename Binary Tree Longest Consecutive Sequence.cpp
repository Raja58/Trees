// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        18 Dec 2021
//  @Detail  :        Binary Tree Longest Consecutive Sequence (LeetCode)
//  ============================
//  -->

void getCon(TreeNode *root, int prev, int cur, int &result)
    {
        if(!root)
            return;

        
        if(root -> val == prev + 1)
        {
            result = max(result, cur + 1);
            getCon(root -> left, root -> val, cur + 1, result);
            getCon(root -> right, root -> val, cur + 1, result);
        }
        else{
            result = max(result, cur);
            getCon(root -> left, root -> val, 1, result);
            getCon(root -> right, root -> val, 1, result);
        }
    }
    int longestConsecutive(TreeNode * root) {
        int result = 0;
        if(!root)
            return result;
        getCon(root -> right, root -> val, 1, result);
        getCon(root -> left, root -> val, 1, result);
        return result;
    }
