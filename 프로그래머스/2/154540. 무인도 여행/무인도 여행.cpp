#include <string>
#include <vector>
#include<queue>
#include<algorithm>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
typedef struct mood{
    int x,y;
}mood;
int bfs(vector<string> maps,int sx,int sy,vector<vector<int>> &v){
    int result=0;
    mood s;
    s.x=sx;
    s.y=sy;
    queue<mood> q;
    q.push(s);
    v[sx][sy]++;
    while(!q.empty()){
        mood tmp=q.front();
        result+=maps[tmp.x][tmp.y]-'0';
        q.pop();
        for(int i=0;i<4;i++){
            int nx=tmp.x+dx[i];
            int ny=tmp.y+dy[i];
            if(nx<0||ny<0||nx>=maps.size()||ny>=maps[0].length())continue;
            if(maps[nx][ny]!='X'&&v[nx][ny]==0){
                v[nx][ny]=1;
                s.x=nx;
                s.y=ny;
                q.push(s);
            }
        }
    }
    return result;
}
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    vector<vector<int>> v(maps.size(),vector<int>(maps[0].length(),0));
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[0].length();j++){
            if(maps[i][j]=='X'||v[i][j]==1)continue;
            answer.push_back(bfs(maps,i,j,v));
        }
    }
    if(answer.empty())answer.push_back(-1);
    sort(answer.begin(),answer.end());
    return answer;
}