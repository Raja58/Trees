// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        18 Dec 2021
//  @Detail  :        Binary Tree Vertical Order Traversal (LeetCode)
//  ============================
//  -->

vector<vector<int>> verticalOrder(TreeNode *root) {
        map<int, vector<int>> table;
        vector<vector<int>> result;
        if(!root)
            return result;
        queue<pair<TreeNode *, int>> cache;
        cache.push({root, 0});
        while(!cache.empty())
        {
            pair<TreeNode *, int> temp = cache.front(); cache.pop();
            table[temp.second].push_back(temp.first -> val);
            if(temp.first -> left)
                cache.push({temp.first -> left, temp.second - 1});
            if(temp.first -> right)
                cache.push({temp.first -> right, temp.second + 1});
        }
        for(auto &x : table)
            result.push_back(x.second);
        return result;
    }
