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
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> S;
        TreeNode *curr = root;
        while (curr != null || !S.empty())
        {
            while (curr != null)
            {
                S.push(curr);
                curr = curr->left;
            }
            curr = S.top();
            S.pop();
            res.push_back(curr->val);

            curr = curr->right;
        }
        return res;
    }
};

