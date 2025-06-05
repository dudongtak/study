#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int V,E,K,u,v,w;
int INF=2000000000;
vector<vector<pair<int,int>>> board(20001);
vector<bool> visit(20001,false);
vector<int> dis(20001,INF);

void dijkstra(int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,s});
    
    while(!pq.empty()){
        int cur=pq.top().second;
        int d=pq.top().first;
        pq.pop();

        if(visit[cur])continue;
        visit[cur]=true;

        for(int i=0;i<board[cur].size();i++){
            int next=board[cur][i].first;
            int nextd=board[cur][i].second;
            dis[next]=min(d+nextd,dis[next]);

            pq.push({dis[next],next});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>V>>E>>K;

    for(int i=0;i<E;i++){
        cin>>u>>v>>w;
        board[u].push_back({v,w});
    }

    dis[K]=0;
    dijkstra(K);
    for(int i=1;i<=V;i++){
        if(dis[i]==INF)cout<<"INF\n";
        else cout<<dis[i]<<"\n";
    }
}