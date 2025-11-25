#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,num=1,Max=100000000;
typedef pair<int,int> pii;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin>>n){
        if(n==0)return 0;

        vector<vector<int>> board(n,vector<int>(n));
        vector<vector<int>> dis(n,vector<int>(n,Max));
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>board[i][j];

        dis[0][0]=board[0][0];
        priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<>> pq;
        pq.push({dis[0][0],{0,0}});

        while(!pq.empty()){
            auto[w,cur]=pq.top();
            auto[x,y]=cur;
            pq.pop();

            if(dis[x][y]<w)continue;

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0||ny<0||nx>=n||ny>=n)continue;

                int nextW=w+board[nx][ny];
                if(dis[nx][ny]<=nextW)continue;
                dis[nx][ny]=nextW;
                pq.push({nextW,{nx,ny}});
            }
        }

        cout<<"Problem "<<num<<": "<<dis[n-1][n-1]<<"\n";
        num++;
    }
}