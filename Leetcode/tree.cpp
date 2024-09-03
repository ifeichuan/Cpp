#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define MaxSize 1000
#define ElemType int

typedef struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  }TreeNode;

// 有序树的插入
void insert(TreeNode *root, int val)
{
    if (root->val > val)
    {
        if (root->left == NULL)
        {
            root->left = new TreeNode(val);
        }
        else
        {
            insert(root->left, val);
        }
    }
    else if (root->val < val)
    {
        if (root->right == NULL)
        {
            root->right = new TreeNode(val);
        }
        else
        {
            insert(root->right, val);
        }
    }
}

// 树的递归遍历

bool compare(TreeNode *left, TreeNode *right)
{
    // 首先排除空结点的情况
    if (left == NULL && right != NULL)
        return false;
    else if (left != NULL && right == NULL)
        return false;
    else if (left == NULL && right == NULL)
        return true;
    // 排除数值不同的情况
    else if (left->val != right->val)
        return false;
    // 开始递归
    bool outSide = compare(left->left, right->right);
    bool inSide = compare(left->right, right->left);
    bool isSame = outSide && inSide;
    return isSame;
}


// 前序遍历
void traversal(TreeNode *root, vector<int> &result)
{
    if (root == NULL)
        return;
    result.push_back(root->val);
    traversal(root->left, result);
    traversal(root->right, result);
}

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> result;
    traversal(root, result);
    return result;
}

// 树的迭代遍历
vector<int> 迭代前序遍历(TreeNode *root)
{
    stack<TreeNode *> st;
    vector<int> result;
    if (root == NULL)
        return result;
    st.push(root);
    // 栈不为空，即未遍历完
    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();
        result.push_back(node->val);
        if (node->left)
            st.push(node->left);
        if (node->right)
            st.push(node->right);
    }
    return result;
}

// 迭代中序遍历
vector<int> 迭代中序遍历(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode *> st;
    TreeNode *cur = root;
    while (cur != NULL || !st.empty())
    {
        if (cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = st.top();
            st.pop();
            result.push_back(cur->val);
            cur = cur->right;
        }
    }
    return result;
}

vector<int> 迭代后序遍历(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode *> st;
    if (root == NULL)
        return result;
    st.push(root);
    while (!st.empty())
    {
        // 中左右
        // 中右左
        // 左右中
        TreeNode *node = st.top();
        st.pop();
        result.push_back(node->val);
        if (node->left)
            st.push(node->left);
        if (node->right)
            st.push(node->right);
    }
    reverse(result.begin(), result.end());
    return result;
}
// 层序遍历
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    queue<TreeNode *> que;
    if (root != NULL)
        que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = que.front();
            que.pop();
            vec.push_back(node->val);
            if (node->left != NULL)
                que.push(node->left);
            if (node->right != NULL)
                que.push(node->right);
        }
        result.push_back(vec);
    }
    return result;
}

// LeetCode 199.二叉树的右视图
vector<int> rightSideView(TreeNode *root)
{
    vector<int> result;
    queue<TreeNode *> st;
    if (root != NULL)
        st.push(root);
    TreeNode *node;
    while (!st.empty())
    {
        int size = st.size();
        for (; size > 0; size--)
        {
            node = st.front();
            st.pop();
            if (size - 1 == 0)
                result.push_back(node->val);
            if (node->left != NULL)
                st.push(node->left);
            if (node->right != NULL)
                st.push(node->right);
        }
    }
    return result;
}

// LeetCode 637.二叉树的层平均值
vector<double> averageOfLevels(TreeNode *root)
{
    vector<double> result;
    if (root == NULL)
        return result;
    double sum;
    queue<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        int size = st.size();
        sum = 0;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = st.front();
            st.pop();
            sum += node->val;
            if (node->left != NULL)
                st.push(node->left);
            if (node->right != NULL)
                st.push(node->right);
        }
        result.push_back(((double)sum / size * 100000.0) / 100000.0);
    }
    return result;
}

// LeetCode 104.二叉树的最大深度
int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int maxDepth = 1;
    queue<TreeNode *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        int size = Q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = Q.front();
            Q.pop();
            // if(node->left==NULL&&node->right==NULL){

            // }
            if (node->left != NULL)
                Q.push(node->left);
            if (node->right != NULL)
                Q.push(node->right);
        }
        // 深度+1
        maxDepth++;
    }
    return maxDepth;
}

// LeetCode 226.翻转二叉树
TreeNode *invertTree(TreeNode *root)
{
    // 采用递归的方式,将每个二叉树的左右孩子反转
    if (root == NULL)
        return root;
    swap(root->left, root->right); // 中
    invertTree(root->left);        // 左
    invertTree(root->right);       // 右
    return root;
}

// LeetCode 101.对称二叉树
bool isSymmetric(TreeNode *root)
{
    if (!root)
        return true;
    return compare(root->left, root->right);
}



// LeetCode 110.平衡二叉树
int getHeight(TreeNode *root)
{
    if (!root)
        return 0;
    int left = getHeight(root->left);
    if (left == -1)
        return -1;
    int right = getHeight(root->right);
    if (right == -1)
        return -1;
    int result = abs(left - right);
    if (result <= 1)
        return 1 + max(left, right);
    else
        return -1;
    return result;
}

bool isBalnced(TreeNode *root)
{
    return getHeight(root);
}
// 先序遍历求二叉树结点路径
void getBinaryTreePaths(TreeNode *root, vector<string> &result, vector<int> &num)
{
    if (root->left == NULL && root->right == NULL)
    {
        string temp = "";
        for (int i = 0; i < num.size(); i++)
        {
            temp += to_string(num[i]);
            temp += "->";
        }
        temp += to_string(root->val);
        result.push_back(temp);
        return;
    }
    num.push_back(root->val);
    getBinaryTreePaths(root->left, result, num);
    getBinaryTreePaths(root->right, result, num);
    num.pop_back();
    return;
}
// 第二种写法
void getBinaryTreePaths_secondMethod(TreeNode *root, string path, vector<string> &result)
{
    if (!root)
        return;
    path += to_string(root->val);
    if (root->left == NULL && root->right == NULL)
    {
        result.push_back(path);
        return;
    }
    // 左
    getBinaryTreePaths_secondMethod(root->left, path + "->", result);
    // 右
    getBinaryTreePaths_secondMethod(root->right, path + "->", result);
}

// 层序遍历求法
vector<string> binaryTreePaths_LevelOrder(TreeNode *root)
{
    stack<TreeNode *> treeSt;
    stack<string> pathSt;
    vector<string> result;
    if (!root)
        return result;
    treeSt.push(root); // 添加根结点
    pathSt.push(to_string(root->val));
    while (!treeSt.empty())
    {
        TreeNode *node = treeSt.top();
        treeSt.pop();
        string path = pathSt.top();
        pathSt.pop();
        if (!node->left && !node->right)
        {
            result.push_back(path);
        }
        if (node->left)
        {
            treeSt.push(node->left);
            pathSt.push(path + "->" + to_string(node->left->val));
        }
        if (node->right)
        {
            treeSt.push(node->right);
            pathSt.push(path + "->" + to_string(node->right->val));
        }
    }
    return result;
}

// LeetCode 257.二叉树的所有路径
vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> result;
    //     vector<int> num;
    //     getBinaryTreePaths(root, result, num);
    string path = "";
    getBinaryTreePaths_secondMethod(root, path, result);
    return result;
}

int getLeftNodeSum(TreeNode* root,TreeNode* parent){
    if(!root) return 0;
    if(!root->left&&!root->right&&parent->left==root){
        return root->val;
    }
    return getLeftNodeSum(root->left,root)+getLeftNodeSum(root->right,root);
}

// LeetCode 404.左叶子之和
int sumOfLeftLeaves(TreeNode *root)
{
    // 可能出现同一层两个左节点都没有孩子
    // 可以前序遍历并且每次携带父节点
    int sum = 0;
    if(root) return sum;
    sum = getLeftNodeSum(root,root);
    return 0;
}

// LeetCode 513.找树左下角的值
int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> S;
    int result = root->val;
    if(!root) return result;
    S.push(root);
    while(!S.empty()){
        int size = S.size();
        result = S.front()->val;
        while(size--){
            TreeNode* node = S.front(); S.pop();
            if(node->left) S.push(node->left);
            if(node->right) S.push(node->right);
        }
    }
    return result;
}

void getPathSumTwo(TreeNode* root,int targetSum,vector<vector<int>>& result,vector<int>& path){
    if(!root) return;
    // 如果遇到叶子结点且符合
    if(root->val==targetSum&&!root->left&&!root->right){
        path.push_back(root->val);
        result.push_back(path);
        path.pop_back();
        return;
    }
    if(root->left){
        path.push_back(root->val);
        getPathSumTwo(root->left,targetSum-root->val,result,path);
        path.pop_back();
    }
    if(root->right){
        path.push_back(root->val);
        getPathSumTwo(root->right,targetSum-root->val,result,path);
        path.pop_back();
    }
}

// LeetCode 113.路径总和Ⅱ
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> result;
    vector<int> path;
    if(!root) return result;
    getPathSumTwo(root,targetSum-root->val,result,path);
    return result;
}
// TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//     if(postorder.size()==0) return NULL;
//     int val = postorder[postorder.size()-1];
//     int index = distance(inorder.begin(),find(inorder.begin(),inorder.end(),val));
//     TreeNode* Tree = new TreeNode(val);
//     // Tree->val = val;
//     vector<int> leftInOrder(inorder.begin(),inorder.begin()+index);
//     vector<int> rightInOrder(inorder.begin()+index+1,inorder.end());
//     vector<int> leftPostOrder(postorder.begin(),postorder.begin()+index);
//     vector<int> rightPostOrder(postorder.begin()+index,postorder.end()-1);
//     Tree->left = buildTree(leftInOrder,leftPostOrder);
//     Tree->right = buildTree(rightInOrder,rightPostOrder);
//     return Tree;
// }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      if(preorder.size()==0) return NULL;
      int val = preorder[0];
      printf("val = %d\n",val);
      TreeNode* T = new TreeNode(val);
      int index=0;
      for(index = 0;index<inorder.size();index++){
        if(inorder[index]==val) break;
      }
      vector<int> leftPre(preorder.begin()+1,preorder.begin()+1+index);
      vector<int> leftIn(inorder.begin(),inorder.begin()+index);
      vector<int> rightPre(preorder.begin()+1+index,preorder.end());
      vector<int> rightIn(inorder.begin()+1+index,inorder.end());
      T->left = buildTree(leftPre,leftIn);
      T->right = buildTree(rightPre,rightIn);
      return T;
    }






int main(){
vector<int> inorder = {9,3,15,20,7};
vector<int> postorder = {3,9,20,15,7};
TreeNode *T = buildTree(postorder,inorder);
vector<vector<int>> result = levelOrder(T);
for(vector<int>  nums : result){
    for(int n : nums){
        printf("%d ",n);
    }
    printf("\n");
}
}


// int main()
// {
//     TreeNode family;
//     int val;
//     cin >> val;
//     family.val = val;
//     while (val != -1)
//     {
//         cin >> val;
//         insert(&family, val);
//     }
// }

//  C++ 重载运算符
// class Tree{
//     private:
//         TreeNode *T;
//     public:
//         Tree operator+(const Tree& T2){
//             Tree T1;
//             TreeNode *Head = new TreeNode;
//             T1.T = Head;
//             Head->left = T2.T;
//             Head->right = this->T;
//             return T1;
//         }
// };