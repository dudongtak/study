#include <string>
#include <vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef pair<int,int> pii;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void crane(vector<string> &s,vector<vector<bool>> &e,char c){
    for(int i=0;i<s.size();i++)
        for(int j=0;j<s[0].size();j++){
            if(e[i][j])continue;
            if(s[i][j]==c)e[i][j]=true;
        }
}
void fork(vector<string> &s,vector<vector<bool>> &e,char c,vector<pii> &a){
    for(int i=0;i<a.size();i++){
        auto[x,y]=a[i];
        if(s[x][y]==c)e[x][y]=true;
    }
}
void is_acc(vector<vector<bool>> &e,vector<pii> &a,int n,int m){
    vector<pii> tmp;
    queue<pii> q;
    vector<vector<bool>> v(n,vector<bool>(m,false));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(i==0||j==0||i==n-1||j==m-1){
                if(e[i][j])q.push({i,j});
                tmp.push_back({i,j});
                v[i][j]=true;
            }
        }
    
    while(!q.empty()){
        auto[x,y]=q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx<0||ny<0||nx>=n||ny>=m)continue;
            if(v[nx][ny])continue;
            v[nx][ny]=true;
            tmp.push_back({nx,ny});
            if(e[nx][ny])q.push({nx,ny});
        }
    }
    a=tmp;
}
int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    int n=storage.size(),m=storage[0].size();
    vector<vector<bool>> is_empty(n,vector<bool>(m,false));
    vector<pii> can_acc;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(i==0)can_acc.push_back({i,j});
            else if(j==0)can_acc.push_back({i,j});
            else if(i==n-1)can_acc.push_back({i,j});
            else if(j==m-1)can_acc.push_back({i,j});
        }
    
    for(int i=0;i<requests.size();i++){
        if(requests[i].size()==2){
            crane(storage,is_empty,requests[i][0]);
        }
        else{
            fork(storage,is_empty,requests[i][0],can_acc);
        }
        is_acc(is_empty,can_acc,n,m);
    }
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(!is_empty[i][j])answer++;
    return answer;
}