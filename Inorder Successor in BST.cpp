// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        18 Dec 2021
//  @Detail  :        Inorder Successor in BST (LeetCode)
//  ============================
//  -->

TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        TreeNode *result = NULL;
        while(root)
        {
            if(root -> val <= p -> val)
                root = root -> right;
            else {
                result = root;
                root = root -> left;
            }
        }
        return result;
    }
