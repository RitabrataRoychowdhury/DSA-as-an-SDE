#include <iostream>
#include <vector>

using namespace std;

//will get TLE even wit memorisation
class Solution {
public:
    unordered_map<TreeNode*, int> memo;
    int rob(TreeNode* root) {
        if(!root) return 0;
        //check if we've visited this node before
        if(memo.find(root) != memo.end()) {
            return memo[root];
        }
        int curr = root->val;
        if(root->left){
            curr += rob(root->left->left) + rob(root->left->right);
        }
        if(root->right){
            curr += rob(root->right->left) + rob(root->right->right);
        }
        int notRob = rob(root->left) + rob(root->right);
        return max(notRob, curr);
    }
};

class Solution{
    public:
    pair<int,int> dfs(TreeNode* root){
        if(!root) return {0,0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int robRoot = root->val + left.second + right.second;
        int notRobRoot =max(left.first, left.second) + max(right.first, right.second);
        return {robRoot, notRobRoot};    
    }

    int rob(TreeNode* root){
        if(!root) return 0;
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int main() {
    Solution solution;

    // Create a sample binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    // Calculate the maximum amount of money that can be robbed
    int maxRobbed = solution.houseRobber3(root);
    cout << "Maximum amount that can be robbed: " << maxRobbed << endl;

    // Clean up memory
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}