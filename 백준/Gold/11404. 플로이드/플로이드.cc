#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N,M,a,b,c;

vector<vector<pair<int,int>>> board(101);
vector<vector<int>> dis(101,vector<int>(101,10000001));

void dijkstra(int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.push({0,s});
    dis[s][s]=0;

    while(!pq.empty()){
        int cur=pq.top().second;
        int w=pq.top().first;
        pq.pop();

        if(dis[s][cur]<w)continue;

        for(int i=0;i<board[cur].size();i++){
            int next=board[cur][i].first;
            int nextW=board[cur][i].second;
            if(dis[s][next]>dis[s][cur]+nextW){
                dis[s][next]=dis[s][cur]+nextW;
                pq.push({dis[s][next],next});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>M;

    for(int i=0;i<M;i++){
        cin>>a>>b>>c;
        board[a].push_back({b,c});
    }

    for(int i=1;i<=N;i++)dijkstra(i);

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(dis[i][j]==10000001)cout<<0<<" ";
            else cout<<dis[i][j]<<" ";
        }
        cout<<"\n";
    }
}