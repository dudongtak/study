#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> board(50001);
vector<int> parent(50001);
vector<bool> check(50001);
vector<int> depth(50001);

int n,m,a,b;

int LCA(int a,int b){
    if(depth[a]>depth[b])swap(a,b);
    while(depth[a]!=depth[b])b=parent[b];

    while(a!=b){
        a=parent[a];
        b=parent[b];
    }
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        board[a].push_back(b);
        board[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    check[1]=true;
    depth[1]=1;
    while(!q.empty()){
        int cur=q.front();
        q.pop();

        for(int i=0;i<board[cur].size();i++){
            int next=board[cur][i];
            if(!check[next]){
                depth[next]=depth[cur]+1;
                check[next]=true;
                parent[next]=cur;
                q.push(next);
            }
        }
    }

    cin>>m;
    while(m--){
        cin>>a>>b;
        cout<<LCA(a,b)<<'\n';
    }
}