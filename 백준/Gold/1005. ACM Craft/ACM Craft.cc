#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int T,N,K,W;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>T;

    while(T--){
        cin>>N>>K;

        vector<int> d(N+1);
        vector<int> rank(N+1,0);
        vector<int> time(N+1,0);
        vector<vector<int>> board(N+1);

        for(int i=1;i<=N;i++)cin>>d[i];

        for(int i=0;i<K;i++){
            int x,y;
            cin>>x>>y;
            rank[y]++;
            board[x].push_back(y);
        }

        queue<int> q;
        for(int i=1;i<=N;i++)
            if(rank[i]==0){
                q.push(i);
                time[i]=d[i];
            }

        int t=0;
        while(!q.empty()){
            int cur=q.front();
            q.pop();

            for(int i=0;i<board[cur].size();i++){
                int next=board[cur][i];
                time[next]=max(time[next],time[cur]+d[next]);
                if(--rank[next]==0)q.push(next);
            }
        }

        cin>>W;
        cout<<time[W]<<"\n";
    }
}