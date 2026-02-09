#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<memory.h>
using namespace std;

int n,m;
typedef struct bead{
    int x,y,cnt=0;
}bead;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bead b,r;
vector<string> board;
typedef pair<bead,bead> pbb;

bead move(int dis,bead b){
    while(true){
        int nx=b.x+dx[dis];
        int ny=b.y+dy[dis];

        if(board[nx][ny]=='#')break;
        b.x=nx;b.y=ny;
        if(board[nx][ny]=='O')break;
    }
    b.cnt++;
    return b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    board.resize(n);
    bool visit[n][m][n][m];
    memset(visit, false, sizeof(visit));

    for(int i=0;i<n;i++){
        cin>>board[i];
        for(int j=0;j<m;j++){
            if(board[i][j]=='R'){
                r.x=i;r.y=j;
                board[i][j]='.';
            }
            if(board[i][j]=='B'){
                b.x=i;b.y=j;
                board[i][j]='.';
            }
        }
    }
    
    visit[r.x][r.y][b.x][b.y]=true;
    queue<pbb> q;
    q.push({r,b});

    int ans=1e9;

    while(!q.empty()){
        auto[cr,cb]=q.front();
        q.pop();

        if(cr.cnt>=10)continue;

        for(int i=0;i<4;i++){
            bead nr=move(i,cr);
            bead nb=move(i,cb);

            if(board[nr.x][nr.y]=='O'&&board[nb.x][nb.y]=='O')continue;
            if(board[nb.x][nb.y]=='O')continue;
            
            if (nr.x == nb.x && nr.y == nb.y) {
                int rDist = abs(nr.x - cr.x) + abs(nr.y - cr.y);
                int bDist = abs(nb.x - cb.x) + abs(nb.y - cb.y);

                if (rDist > bDist) {
                    nr.x -= dx[i];
                    nr.y -= dy[i];
                } else {
                    nb.x -= dx[i];
                    nb.y -= dy[i];
                }
            }

            if(visit[nr.x][nr.y][nb.x][nb.y])continue;
            visit[nr.x][nr.y][nb.x][nb.y]=true;

            if(board[nr.x][nr.y]=='O')ans=min(ans,nr.cnt);
            q.push({nr,nb});
        }
    }

    if(ans==1e9)cout<<-1;
    else cout<<ans;
}