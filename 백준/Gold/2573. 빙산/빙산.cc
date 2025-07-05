#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int N,M;
vector<vector<int>> board(300,vector<int>(300,0));
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int answer=0;

void dfs(vector<vector<bool>> &v,int x,int y){
    stack<pair<int,int>> s;
    s.push({x,y});

    while(!s.empty()){
        int cx=s.top().first;
        int cy=s.top().second;
        s.pop();
        if(v[cx][cy])continue;
        v[cx][cy]=true;

        for(int i=0;i<4;i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];

            if(nx<0||ny<0||nx>=N||ny>=M||v[nx][ny]||board[nx][ny]==0)continue;
            s.push({nx,ny});
        }
    }
}

void melt(){
    vector<vector<int>> m(N,vector<int>(M,0));

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<4;k++){
                int nx=i+dx[k];
                int ny=j+dy[k];

                if(nx<0||ny<0||nx>=N||ny>=M)continue;
                if(board[nx][ny]==0)m[i][j]++;
            }
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            board[i][j]-=m[i][j];
            if(board[i][j]<0)board[i][j]=0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>M;

    for(int i=0;i<N;i++)for(int j=0;j<M;j++){
        cin>>board[i][j];
    }

    while(true){
        melt();
        vector<vector<bool>> visit(N,vector<bool>(M,false));
        
        int cnt=0;
        int z_cnt=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(board[i][j]==0){
                    z_cnt++;
                    continue;
                }
                if(visit[i][j])continue;
                cnt++;
                dfs(visit,i,j);
            }
        }
        if(z_cnt==N*M){
            cout<<0;
            return 0;
        }
        answer++;
        if(cnt!=1)break;
    }
    cout<<answer;
}