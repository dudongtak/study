#include <string>
#include <vector>
#include<queue>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
typedef struct mood{
    int x,y;
}mood;

int bfs(vector<string> m,mood &s,char c,vector<vector<int>> v){
    queue<mood> q;
    q.push(s);
    int dis=0;
    v[s.x][s.y]=1;
    bool flag=false;
    while(!q.empty()){
        int size=q.size();
        dis++;
        for(int i=0;i<size;i++){
            mood mo=q.front();
            q.pop();
            for(int j=0;j<4;j++){
                int nx=dx[j]+mo.x;
                int ny=dy[j]+mo.y;
                if(nx>=0&&nx<m.size()&&ny>=0&&ny<m[0].length()&&m[nx][ny]!='X'&&v[nx][ny]==0){
                    if(m[nx][ny]==c){
                        s.x=nx;
                        s.y=ny;
                        flag=true;
                        break;
                    }
                    v[nx][ny]++;
                    mood tmp;
                    tmp.x=nx;
                    tmp.y=ny;
                    q.push(tmp);
                }
            }
        }
        if(flag==true)break;
    }
    if(flag==false)return -1;
    return dis;
}

int solution(vector<string> maps) {
    mood s;
    for(int i=0;i<maps.size();i++){
        bool flag=false;
        for(int j=0;j<maps[0].length();j++){
            if(maps[i][j]=='S'){
                s.x=i;
                s.y=j;
                flag=true;
                break;
            }
        }
        if(flag==true)break;
    }
    int dis=0;
    vector<vector<int>> v(maps.size(),vector<int>(maps[0].length(),0));
    //레버 찾기
    dis=bfs(maps,s,'L',v);
    if(dis==-1)return -1;
    //마지막으로
    int d=bfs(maps,s,'E',v);
    if(d==-1)return -1;
    dis+=d;
    return dis;
}