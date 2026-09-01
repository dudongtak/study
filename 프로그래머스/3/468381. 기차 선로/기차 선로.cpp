#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;

typedef pair<int,int> pii;
//up,left,down,right 1,2,3,4
int n,m;
int last;
vector<vector<int>> visit(8,vector<int>(8,0));

bool check(vector<vector<int>> &board){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]!=3&&board[i][j]>=1&&board[i][j]<=7&&visit[i][j]!=1)return false;
            if(board[i][j]==3&&visit[i][j]<2)return false;
        }
    }
    return true;
}

void dfs(vector<vector<int>> &board,int dir,int x,int y,int &answer){
    if(x==n-1&&y==m-1){
        if((last==1&&dir==4)||(last==2&&dir==3)){
            visit[x][y]++;
            if(check(board))answer++;
            visit[x][y]--;
        }
        return;
    }
    
    if(x<0||y<0||x>=n||y>=m)return;
    int rail=board[x][y];
    if(rail==-1)return;
    
    if(rail!=0&&rail!=3){
        if(visit[x][y])return;
        visit[x][y]++;
        if(rail==1){if(dir==4)dfs(board,4,x,y+1,answer);if(dir==2)dfs(board,2,x,y-1,answer);}
        if(rail==2){if(dir==1)dfs(board,1,x-1,y,answer);if(dir==3)dfs(board,3,x+1,y,answer);}
        if(rail==4){if(dir==4)dfs(board,1,x-1,y,answer);if(dir==3)dfs(board,2,x,y-1,answer);}
        if(rail==5){if(dir==3)dfs(board,4,x,y+1,answer);if(dir==2)dfs(board,1,x-1,y,answer);}
        if(rail==6){if(dir==1)dfs(board,4,x,y+1,answer);if(dir==2)dfs(board,3,x+1,y,answer);}
        if(rail==7){if(dir==1)dfs(board,2,x,y-1,answer);if(dir==4)dfs(board,3,x+1,y,answer);}
        visit[x][y]--;
        return;
    }
    if(rail==3){
        if(visit[x][y]==2)return;
        visit[x][y]++;
        if(dir==1)dfs(board,1,x-1,y,answer);
        if(dir==2)dfs(board,2,x,y-1,answer);
        if(dir==3)dfs(board,3,x+1,y,answer);
        if(dir==4)dfs(board,4,x,y+1,answer);
        visit[x][y]--;
        return;
    }
    if(visit[x][y]!=0)return;
    visit[x][y]++;
    if(dir==1){
        board[x][y]=2;dfs(board,1,x-1,y,answer);
        board[x][y]=3;dfs(board,1,x-1,y,answer);
        board[x][y]=6;dfs(board,4,x,y+1,answer);
        board[x][y]=7;dfs(board,2,x,y-1,answer);
    }
    if(dir==2){
        board[x][y]=1;dfs(board,2,x,y-1,answer);
        board[x][y]=3;dfs(board,2,x,y-1,answer);
        board[x][y]=5;dfs(board,1,x-1,y,answer);
        board[x][y]=6;dfs(board,3,x+1,y,answer);
    }
    if(dir==3){
        board[x][y]=2;dfs(board,3,x+1,y,answer);
        board[x][y]=3;dfs(board,3,x+1,y,answer);
        board[x][y]=4;dfs(board,2,x,y-1,answer);
        board[x][y]=5;dfs(board,4,x,y+1,answer);
    }
    if(dir==4){
        board[x][y]=1;dfs(board,4,x,y+1,answer);
        board[x][y]=3;dfs(board,4,x,y+1,answer);
        board[x][y]=4;dfs(board,1,x-1,y,answer);
        board[x][y]=7;dfs(board,3,x+1,y,answer);
    }
    visit[x][y]--;
    board[x][y]=0;
    return;
}

int solution(vector<vector<int>> grid) {
    int answer = 0;
    n=grid.size();
    m=grid[0].size();
    last=grid[n-1][m-1];
    visit[0][0]=1;
    dfs(grid,4,0,1,answer);
    
    return answer;
}