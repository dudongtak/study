#include<iostream>
#include<vector>
using namespace std;

int N,x,y,d,g;
vector<vector<int>> board(101,vector<int>(101,0));
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
typedef pair<int,int> pii;
vector<int> dir;

void make_dir(){
    int s=dir.size();
    for(int i=s-1;i>=0;i--){
        int nd=(dir[i]+1)%4;
        x+=dx[nd];
        y+=dy[nd];
        board[y][x]=1;

        dir.push_back(nd);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;

    while(N--){
        cin>>x>>y>>d>>g;
        dir.clear();
        dir.push_back(d);
        board[y][x]=1;
        y+=dy[d];
        x+=dx[d];
        board[y][x]=1;

        for(int i=0;i<g;i++)make_dir();
    }

    int answer=0;
    for(int i=0;i<100;i++)for(int j=0;j<100;j++)if(board[i][j]==1&&board[i+1][j]==1&&board[i][j+1]==1&&board[i+1][j+1]==1)answer++;
    cout<<answer;
}