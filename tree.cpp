//This file includes some test or interesing algorithm for tree.

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Binary Tree Inorder Traversal
//Recursive method
class RecursiveInorder {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
    void helper(TreeNode* root, vector<int> &res) {
        if (!root) return;
        helper(root->left, res);
        res.push_back(root->val);
        helper(root->right, res);
    }
};

//stack method
class StackInorder {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodeStack;
        vector<int> res;
        TreeNode* node = root;
        while(!nodeStack.empty() || node) {
            while(node) {
                nodeStack.push(node);
                node = node->left;
            }
            node = nodeStack.top();
            nodeStack.pop();
            res.push_back(node->val);
            node = node->right;
        }
        return res;
    }
};

//Given a binary tree, return the preorder traversal of its nodes' values.
class PreOrderTrever {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode* > nodeStack;
        TreeNode *node = root;
        while(node || !nodeStack.empty()){
            while(node){
                //res.push_back(node->val);
                nodeStack.push(node);
                node = node->left;
            }
            node = nodeStack.top();
            nodeStack.pop();
            //res.push_back(node->val);
            node = node->right;
        }
        return res;
    }
};


//Given preorder and inorder traversal of a tree, construct the binary tree.
class RebuildTree {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,0,preorder.size(),inorder,0,inorder.size());
    }
    TreeNode* helper(vector<int>& preorder,int i,int j,vector<int>& inorder,int ii,int jj){
        if(i >= j || ii >= jj)
            return NULL;

        int mid = preorder[i];
        auto f = find(inorder.begin() + ii,inorder.begin() + jj,mid);

        int dis = f - inorder.begin() - ii;

        TreeNode* root = new TreeNode(mid);
        root -> left = helper(preorder,i + 1,i + 1 + dis,inorder,ii,ii + dis);
        root -> right = helper(preorder,i + 1 + dis,j,inorder,ii + dis + 1,jj);
        return root;
    }
};

//Given a binary tree, find its minimum depth.
class MinDepthByNoRecur {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> nodeQueue;
        TreeNode* node = root;
        nodeQueue.push(node);
        int res = 0;
        while(!nodeQueue.empty()) {
            int size = nodeQueue.size();
            res++;
            for(int i = 0; i < size; i++) {
                node = nodeQueue.front();
                nodeQueue.pop();
                if(!node->left && !node->right) return res;
                if(node->left) nodeQueue.push(node->left);
                if(node->right) nodeQueue.push(node->right);
            }
        }
        return res;
    }
};

class MinDepthByRecur  {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left&&!root->right) return 1;
        if(!root->left) return 1+minDepth(root->right);
        if(!root->right) return 1+minDepth(root->left);
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
};

//Given a binary tree, find its maximum depth.
class MaxDepthByRecur {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return 1 + maxDepth(root->left) +maxDepth(root->right);
    }
};

//Invert a binary tree.
class InvertTree {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode *temp = invertTree(root->left);
        root->left = root->right;
        root->right = temp;
        return root;
    }
};



//Given a non-empty binary tree, find the maximum path sum.
class findMaxPathSum {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        helper(root, res);
        return res;
    }
    int helper(TreeNode* root, int &res) {
        if (!root) return 0;
        int l = max(0, helper(root->left, res));
        int r = max(0, helper(root->right, res));
        res = max(res, root->val + l + r);
        return root->val + max(l, r);
    }
    
};

//Given a binary tree, flatten it to a linked list in-place.
class FlattenABinaryTree {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        while(root->right)
            root = root->right;
        root->right = temp;
    }
};