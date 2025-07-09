#include<iostream>
#include<vector>
using namespace std;

int N,M;

vector<vector<int>> board(2001);
vector<bool> visit(2001,false);
bool possible=false;

void dfs(int depth,int cur){
    if(possible)return;
    if(depth==4){
        possible=true;
        return;
    }
    visit[cur]=true;
    for(int i=0;i<board[cur].size();i++){
        int next=board[cur][i];
        if(visit[next])continue;
        dfs(depth+1,next);
    }
    visit[cur]=false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>M;

    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;

        board[a].push_back(b);
        board[b].push_back(a);
    }

    for(int i=0;i<N;i++){
        if(possible)break;
        dfs(0,i);
    }

    if(possible)cout<<1;
    else cout<<0;
}