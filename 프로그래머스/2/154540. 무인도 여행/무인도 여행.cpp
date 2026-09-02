#include <string>
#include <vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef pair<int,int> pii;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
vector<vector<bool>> visit(100,vector<bool>(100,false));
int n,m;

void bfs(int x,int y,vector<string> &board,vector<int> &ans){
    queue<pii> q;
    q.push({x,y});
    visit[x][y]=true;
    int date=board[x][y]-'0';
    
    while(!q.empty()){
        auto [cx,cy]=q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m)continue;
            if(board[nx][ny]=='X'||visit[nx][ny])continue;
            
            date+=board[nx][ny]-'0';
            visit[nx][ny]=true;
            q.push({nx,ny});
        }
    }
    ans.push_back(date);
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    n=maps.size();
    m=maps[0].size();
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(!visit[i][j]&&maps[i][j]!='X')bfs(i,j,maps,answer);
    sort(answer.begin(),answer.end());
    if(answer.empty())answer.push_back(-1);
    return answer;
}