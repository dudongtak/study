#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int v,e;
int Max=1000000000;
vector<vector<int>> board;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>v>>e;
    board.resize(v,vector<int>(v,Max));

    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        board[a-1][b-1]=c;
    }

    for(int i=0;i<v;i++)for(int j=0;j<v;j++)for(int k=0;k<v;k++){
        if(board[i][k]==Max||board[j][i]==Max)continue;
        board[j][k]=min(board[j][k],board[j][i]+board[i][k]);
    }
    int answer=Max;

    for(int i=0;i<v;i++)answer=min(answer,board[i][i]);
    if(answer==Max)cout<<-1;
    else cout<<answer;
}