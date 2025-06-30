#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;

int N,L,R;
int cnt=0;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
vector<vector<int>> board(50,vector<int>(50,-1));
vector<vector<pair<int,int>>> connect;

void move(int idx){
    int sum=0;
    for(int i=0;i<connect[idx].size();i++)sum+=board[connect[idx][i].first][connect[idx][i].second];

    sum/=connect[idx].size();

    for(int i=0;i<connect[idx].size();i++)board[connect[idx][i].first][connect[idx][i].second]=sum;
}

void bfs(int x,int y,vector<vector<bool>> &v){
    if(v[x][y])return;

    queue<pair<int,int>> q;
    vector<pair<int,int>> con;
    con.push_back({x,y});
    q.push({x,y});
    v[x][y]=true;

    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        
        q.pop();

        for(int i=0;i<4;i++){
            int nx=dx[i]+cx;
            int ny=dy[i]+cy;

            if(nx<0||ny<0||nx>=N||ny>=N||v[nx][ny])continue;
            if(abs(board[cx][cy]-board[nx][ny])>=L&&abs(board[cx][cy]-board[nx][ny])<=R){
                v[nx][ny]=true;
                q.push({nx,ny});
                con.push_back({nx,ny});
            }
        }
    }
    connect.push_back(con);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>L>>R;

    for(int i=0;i<N;i++)for(int j=0;j<N;j++)cin>>board[i][j];

    while(true){
        vector<vector<bool>> visit(N,vector<bool>(N,false));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                bfs(i,j,visit);
            }
        }
        if(connect.size()==N*N)break;

        for(int i=0;i<connect.size();i++)move(i);
        cnt++;
        connect.clear();
    }

    cout<<cnt;
}