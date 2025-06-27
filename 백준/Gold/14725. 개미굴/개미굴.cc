#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

struct Node{
    map<string,Node*> child;
};

void dfs(Node* node,int l){
    for(auto c:node->child){
        for(int i=0;i<l;i++){
            cout<<"--";
        }
        cout<<c.first<<"\n";
        dfs(c.second,l+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N;

    Node* root=new Node();

    while(N--){
        int k;
        cin>>k;
        vector<string> arr(k);

        for(int i=0;i<k;i++)cin>>arr[i];
    
        Node* tmp=root;

        for(const auto& str:arr){
            if(tmp->child.count(str)==0)tmp->child[str]=new Node();
            tmp=tmp->child[str];
        }
    }

    dfs(root,0);
}