#include<iostream>
#include<algorithm>
using namespace std;

int N;
double p[4];
bool visit[30][30];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

double dfs(int x,int y,int cnt){
    if(cnt==N)return 1;

    visit[x][y]=true;

    double r=0;

    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(visit[nx][ny])continue;
        r+=p[i]*dfs(nx,ny,cnt+1);
    }
    visit[x][y]=false;
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;
    for(int i=0;i<4;i++){
        cin>>p[i];
        p[i]/=100;
    }

    cout.precision(10);
    cout<<dfs(15,15,0);
}