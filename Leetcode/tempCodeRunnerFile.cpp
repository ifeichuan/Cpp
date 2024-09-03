int main(){
    TreeNode family;
    int val;
    cin>>val;
    family.val = val;
    while(val!=-1){
        cin>>val;
        insert(&family,val);
        vector<vector<int>> result = levelOrder(&family);
        for(auto n : result){
            for(auto c : n){
                cout<<c<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
    }
}
