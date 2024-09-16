void solve(Node* root, int input,int &ans){
    if(root==NULL)return ;
    if(root->data>input){
        ans=root->data;
    }
    if(root->data==input){
        ans=root->data;
        return;
    }
    if(root->data<input)solve(root->right,input,ans);
    else solve(root->left,input,ans);
    
}

int findCeil(Node* root, int input) {
    if (root == NULL) return -1;

    // Your code here
    int ans=-1;
    solve(root,input,ans);
    return ans;
    
}