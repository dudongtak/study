#include<iostream>
#include<vector>
using namespace std;

int n;
vector<vector<char>> board(7,vector<char>(7,'X'));
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
typedef pair<int,int> pii;
vector<pii> t;
bool ans=false;

bool check(){
    for(auto[x,y]:t){
        for(int j=0;j<4;j++){
            int cnt=1;
            while(true){
                int nx=x+dx[j]*cnt;
                int ny=y+dy[j]*cnt;
                if(nx<1||ny<1||nx>n||ny>n)break;
                if(board[nx][ny]=='O')break;
                if(board[nx][ny]=='S')return false;
                cnt++;
            }
        }
    }
    return true;
}

void dfs(int depth){
    if(ans)return;
    if(depth==3){
        if(check())ans=true;
        return;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(board[i][j]=='X'){
                board[i][j]='O';
                dfs(depth+1);
                board[i][j]='X';
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        cin>>board[i][j];
        if(board[i][j]=='T')t.push_back({i,j});
    }

    dfs(0);
    if(ans)cout<<"YES";
    else cout<<"NO";
}