#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int mINF=-100000000;
vector<vector<int>> board(1001,vector<int>(1001,0));
vector<vector<vector<int>>> dp(1001,vector<vector<int>>(1001,vector<int>(3,mINF)));
vector<vector<bool>> visit(1001,vector<bool>(1001,false));
int dx[3]={1,0,0};
int dy[3]={0,1,-1};
int n,m;

int dfs(int x,int y,int dir){
    if(x==n&&y==m)return board[x][y];
    if(dp[x][y][dir]!=mINF)return dp[x][y][dir];

    visit[x][y]=true;
    int Max=mINF;
    for(int i=0;i<3;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<1||nx>n)continue;
        if(ny<1||ny>m)continue;
        if(visit[nx][ny])continue;
        Max=max(Max,dfs(nx,ny,i));
    }
    visit[x][y]=false;
    dp[x][y][dir]=board[x][y]+Max;
    return dp[x][y][dir];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>board[i][j];
        }
    }
    cout<<dfs(1,1,0);
}