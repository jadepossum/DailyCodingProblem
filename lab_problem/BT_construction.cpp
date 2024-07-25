#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left = NULL;
        TreeNode* right = NULL;
        TreeNode(int x){
            val =x;
        }
};

//construct binary tree from the given inorder and postorder sequene of the required tree
TreeNode* tree_construction(vector<int>& ino,vector<int>& posto,int in_start,int in_end,int post_start,int post_end){
    if(in_start>in_end){
        // cout<<"\nreturning NULL"<<endl;
        return NULL;
    }
    // if(post_start>post_end){
    //     return NULL;
    // }
    TreeNode* root = (TreeNode*)malloc(1*sizeof(TreeNode));
    if(in_start==in_end){
        root->val = ino[in_start];
        // cout<<"\nreturning "<<root->val;
    }
    // if(post_start==post_end){
    //     root->val = posto[post_start];
        // cout<<"\nreturning "<<root->val;
    // }

    root->val = posto[post_end];
    // cout<<"\nnew root "<<root->val<<endl;
    // cout<<in_start<<" "<<in_end<<" "<<post_start<<" "<<post_end<<endl;
    int count = 0;
    for(int i = in_start;i<=in_end;i++){
        if(ino[i]==posto[post_end]) break;
        count++;
    }
    root->left = tree_construction(ino,posto,in_start,in_start+count-1,post_start,post_start+count-1);
    root->right = tree_construction(ino,posto,in_start+count+1,in_end,post_start+count,post_end-1);
    return root;
}

int main(){
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode* root = tree_construction(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    cout<<"constructed tree in given format is :["<<root->val;
    vector<TreeNode*> bfs;
    
    //printing level order traversal of the constructed tree
    int count = 1;
    bfs.push_back(root);
    int len  = bfs.size();
    int i = 0;
    int z = 0;
    while(i<len&&z<10){
        if(bfs[i]!=NULL&&count<inorder.size()){
            if(bfs[i]->left!=NULL){
                cout<<" ,"<<bfs[i]->left->val;
                count++;
            }
            else cout<<" ,NULL";
            if(bfs[i]->right!=NULL){
                cout<<" ,"<<bfs[i]->right->val;
                count++;
            }
            else cout<<" ,NULL";
            bfs.push_back(bfs[i]->left);
            bfs.push_back(bfs[i]->right);
            len+=2;
        }
        i++;
        z++;
    }
    cout<<"]";
    return 0;
}