#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;

int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;

    vector<pair<double,double>> star(N);
    vector<vector<double>> dis(N,vector<double>(N,0));
    vector<bool> visit(N);

    for(int i=0;i<N;i++){
        double x,y;
        cin>>x>>y;
        star[i]={x,y};
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j)continue;
            double xdiff=abs(star[i].first-star[j].first);
            double ydiff=abs(star[i].second-star[j].second);
            dis[i][j]=sqrt(pow(xdiff,2)+pow(ydiff,2));
            dis[j][i]=dis[i][j];
        }
    }

    priority_queue<pair<double,int>,vector<pair<double,int>>,greater<>> pq;

    pq.push({0,0});

    double answer=0;

    while(!pq.empty()){
        int cur=pq.top().second;
        double w=pq.top().first;
        pq.pop();

        if(visit[cur])continue;
        visit[cur]=true;
        answer+=w;

        for(int i=0;i<N;i++){
            if(visit[N])continue;
            double nextW=dis[cur][i];
            pq.push({nextW,i});
        }
    }

    cout.precision(3);
    cout<<answer;
}