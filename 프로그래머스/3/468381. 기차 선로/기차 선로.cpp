#include <string>
#include <vector>

using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int re[]={1,0,3,2};
int n,m,answer=0;
int nd[4][4]={
    {1,0,7,4},
    {0,1,6,5},
    {5,4,2,0},
    {6,7,0,2}
};

void dfs(int x,int y, int d,vector<vector<int>> &ori,vector<vector<int>> &tmp){
    if(tmp[x][y]!=0&&tmp[x][y]!=1&&tmp[x][y]!=2)return;
    
    if(x==n-1&&y==m-1){
        int check=0;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++){
            if(ori[i][j]!=0&&ori[i][j]!=-1&&ori[i][j]!=tmp[i][j]){
                if(i==n-1&&j==m-1){
                    if((ori[i][j]==1&&d!=0)||(ori[i][j]==2&&d!=2))check++;
                }
                else check++;
            }
        }
        if(check==0)answer++;
        return;
    }
    
    for(int i=0;i<4;i++){
        if(re[d]==i)continue;
        
        int nx=dx[i]+x;
        int ny=dy[i]+y;
        int rail=nd[d][i];
        int num=tmp[x][y];
        
        if(nx<0||nx>=n||ny<0||ny>=m)continue;
        if(ori[x][y]!=rail&&ori[x][y]!=0&&!(ori[x][y]==3&&(rail==1||rail==2)))continue;
        if(ori[nx][ny]==-1)continue;
        
        if(tmp[x][y]==1||tmp[x][y]==2){
            if(rail==1||rail==2)tmp[x][y]=3;
            else continue;
        }else{
            tmp[x][y]=rail;
        }
        dfs(nx,ny,i,ori,tmp);
        tmp[x][y]=num;
    }
}

int solution(vector<vector<int>> grid) {
    n=grid.size();
    m=grid[0].size();
    
    vector<vector<int>> tmp(n,vector<int>(m,0));
    tmp[0][0]=1;
    
    dfs(0,1,0,grid,tmp);
    return answer;
}