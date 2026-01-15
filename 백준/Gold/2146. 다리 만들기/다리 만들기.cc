#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
using namespace std;

int n,Min=1e9;
vector<vector<int>> board;
typedef pair<int,int> pii;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
vector<vector<pii>> island(10001);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    board.resize(n,vector<int>(n,0));

    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        cin>>board[i][j];
        if(board[i][j])board[i][j]=-1;
    }

    int cnt=0;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        if(board[i][j]==-1){
            queue<pii> q;
            q.push({i,j});
            cnt++;
            board[i][j]=cnt;

            while(!q.empty()){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                
                bool flag=false;
                for(int k=0;k<4;k++){
                    int nx=x+dx[k];
                    int ny=y+dy[k];

                    if(nx<0||ny<0||nx>=n||ny>=n)continue;
                    if(board[nx][ny]==0)flag=true;
                    if(board[nx][ny]==-1){
                        board[nx][ny]=cnt;
                        q.push({nx,ny});
                    }
                }
                if(flag)island[cnt].push_back({x,y});
            }
        }
    }
    for(int i=1;i<cnt;i++){
        for(int j=i+1;j<=cnt;j++){
            for(auto coord1:island[i]){
                for(auto coord2:island[j]){
                    Min=min(Min,abs(coord1.first-coord2.first)+abs(coord1.second-coord2.second)-1);
                }
            }
        }
    }
    cout<<Min;
}