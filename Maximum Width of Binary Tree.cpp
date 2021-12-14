// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        14 Dec 2021
//  @Detail  :        Maximum Width of Binary Tree (LeetCode)
//  ============================
//  -->

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int result = 0;
        queue<pair<TreeNode *, int>> cache;
        cache.push({root, 0});
        while(!cache.empty())
        {
            int minId = cache.front().second, size = cache.size();
            int start, end;
            for(int i = 0; i < size; i++)
            {
                auto temp = cache.front();  cache.pop();
                int curId = temp.second - minId;
                if(i == 0)
                    start = curId;
                if(i == size - 1)
                    end = curId;
                if(temp.first -> left)
                    cache.push({temp.first -> left, 2 * curId + 1});
                if(temp.first -> right)
                    cache.push({temp.first -> right, 2 * curId + 2});
            }
            if(result < end - start + 1)
                result = end - start + 1;
        }
        return result;
    }
};
