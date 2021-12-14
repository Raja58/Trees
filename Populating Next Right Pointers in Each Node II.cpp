// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        14 Dec 2021
//  @Detail  :        Populating Next Right Pointers in Each Node II (LeetCode)
//  ============================
//  -->

class Solution {
public:
    Node* connect(Node* root) {
        Node *parent = root, *childHead = NULL, *child = NULL;
        while(parent)
        {
            while(parent)
            {
                if(parent -> left)
                {
                    if(childHead == NULL)
                        childHead = parent -> left;
                    else
                        child -> next = parent -> left;
                    child = parent -> left;
                }
                
                if(parent -> right)
                {
                    if(childHead == NULL)
                        childHead = parent -> right;
                    else
                        child -> next = parent -> right;
                    child = parent -> right;
                }
                parent = parent -> next;
            }
            parent = childHead;
            childHead = child = NULL;
        }
        return root;
    }
};
