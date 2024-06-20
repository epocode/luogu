#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode
{
    int index;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int index)
    {
        this->index = index;
        this->left = NULL;
        this->right = NULL;
    }
};

unordered_map<int, pair<int, int>> map;
TreeNode *biuldTree()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *curNode = root;
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(curNode);

    while (!nodeQueue.empty())
    {
        TreeNode *curNode = nodeQueue.front();
        nodeQueue.pop();
        int index = curNode->index;
        auto pair = map[index];
        if (pair.first)
        {
            TreeNode *left = new TreeNode(pair.first);
            curNode->left = left;
            nodeQueue.push(left);
        }
        if (pair.second)
        {
            TreeNode *right = new TreeNode(pair.second);
            curNode->right = right;
            nodeQueue.push(right);
        }
    }
    return root;
}

int findDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(findDepth(root->left), findDepth(root->right));
}

int main()
{
    int n;
    cin >> n;
    int i = 1;

    while (n--)
    {
        int left, right;
        cin >> left >> right;
        map[i++] = make_pair(left, right);
    }
    TreeNode* root = biuldTree();
    cout << findDepth(root);
    return 0;
}