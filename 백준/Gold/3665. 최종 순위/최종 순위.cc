#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int t,n,m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;

    while(t--){
        cin>>n;
        vector<int> arr(n);
        vector<int> pos(n+1,0);
        vector<vector<int>> board(n+1);
        vector<int> Rank(n+1,0);

        for(int i=0;i<n;i++){
            cin>>arr[i];
            pos[arr[i]]=i;
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                board[arr[i]].push_back(arr[j]);
                Rank[arr[j]]++;
            }
        }

        cin>>m;
        if(m==0){
            for(int i=0;i<n;i++)cout<<arr[i]<<" ";
            cout<<"\n";
            continue;
        }

        while(m--){
            int a,b;
            cin>>a>>b;

            if(pos[a]>pos[b])swap(a,b);

            auto &v=board[a];

            v.erase(find(v.begin(),v.end(),b));
            Rank[b]--;
            board[b].push_back(a);
            Rank[a]++;
        }

        queue<int> q;
        for(int i=1;i<=n;i++)if(Rank[i]==0)q.push(i);

        vector<int> answer;
        bool ambi=false;
        for(int i=0;i<n;i++){
            if(q.empty()){
                answer.clear();
                break;
            }
            if(q.size()>1){
                ambi=true;
                break;
            }

            int cur=q.front();
            q.pop();
            answer.push_back(cur);

            for(auto next:board[cur])if(--Rank[next]==0)q.push(next);
        }

        if(answer.empty())cout<<"IMPOSSIBLE\n";
        else if(ambi)cout<<"?\n";
        else{
            for(auto cur:answer)cout<<cur<<" ";
            cout<<"\n";
        }
    }   
}