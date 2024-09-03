#include<bits/stdc++.h>
#include "tree.cpp"
using namespace std;


    // T.left = buildTree(inorder[0:index],postorder[0:index])
    // T.right = buildTree(inorder[index+1:],postorder[index:-1])

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(postorder.size()==0) return NULL;
    int val = postorder[postorder.size()-1];
    int index = distance(inorder.begin(),find(inorder.begin(),inorder.end(),val));
    TreeNode* Tree;
    Tree->val = val;
    vector<int> leftInOrder(inorder.begin(),inorder.begin()+index);
    vector<int> rightInOrder(inorder.begin()+index+1,inorder.end());
    vector<int> leftPostOrder(postorder.begin(),postorder.begin()+index);
    vector<int> rightPostOrder(postorder.begin()+index,postorder.end()-1);
    Tree->left = buildTree(leftInOrder,leftPostOrder);
    Tree->right = buildTree(rightInOrder,rightPostOrder);
    return Tree;
}

int main(){
vector<int> inorder = {9,3,15,20,7};
vector<int> postorder = {9,15,7,20,3};
TreeNode *T = buildTree(inorder,postorder);
vector<vector<int>> result = levelOrder(T);
for(auto nums : result){
    for(auto n : nums){
        printf("%d",n);
    }
    printf("\n");
}
}

