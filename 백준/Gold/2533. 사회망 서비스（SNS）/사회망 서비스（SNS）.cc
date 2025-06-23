#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<vector<int>> tree(1000001);
vector<vector<int>> v(1000001);
vector<bool> visit(1000001,false);
vector<vector<int>> state(1000001,vector<int>(2,-1));

int dfs(int c,int s){
    if(state[c][s]!=-1)return state[c][s];

    if(s==1){
        state[c][s]=1;
        for(int i=0;i<tree[c].size();i++){
            int next=tree[c][i];
            state[c][s]+=min(dfs(next,0),dfs(next,1));
        }
    }
    if(s==0){
        state[c][s]=0;
        for(int i=0;i<tree[c].size();i++){
            int next=tree[c][i];
            state[c][s]+=dfs(next,1);
        }
    }
    return state[c][s];
}

void make_tree(int cur){
    visit[cur]=true;

    for(int i=0;i<v[cur].size();i++){
        int next=v[cur][i];
        if(!visit[next]){
            tree[cur].push_back(next);
            make_tree(next);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;

    for(int i=0;i<N-1;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    make_tree(1);

    cout<<min(dfs(1,0),dfs(1,1));
}