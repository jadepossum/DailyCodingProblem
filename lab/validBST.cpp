#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode(int a){
        data = a;
    }
};
bool is_valid_bst(TreeNode* root,int min ,int max){
    if(root==NULL) return true;
    bool valid = true;
    if(root->data<min || root->data > max) return false;
    if(root->left!=NULL){
        if(root->left->data>root->data){
            return false;
            }
        valid = is_valid_bst(root->left,min,root->data);
    }
    if(!valid) return valid;
    if(root->right!=NULL){
        if(root->right->data<root->data){
            return false;
        }
        valid = is_valid_bst(root->right,root->data,max);
    }
    return valid;
}
int main(){
    //representing NULL as '-1'
    TreeNode a(5);
    TreeNode b(1);
    TreeNode c(7);
    TreeNode d(8);
    TreeNode e(9);
    a.left = &b;
    a.right = &c;
    c.left = &d;
    c.right = &e;
    bool valid = is_valid_bst(&a,INT_MIN,INT_MAX);
    if(valid) cout<<"Given Tree is a valid BST"<<endl;
    else cout<<"Given Tree is not a  valid BST"<<endl;
    return 0;
}