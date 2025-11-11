#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n,m,a,b;
vector<int> Rank;
vector<vector<int>> student;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    Rank.resize(n,0);
    student.resize(n);

    for(int i=0;i<m;i++){
        cin>>a>>b;
        student[a-1].push_back(b-1);
        Rank[b-1]++;
    }

    priority_queue<int> pq;

    for(int i=0;i<n;i++)if(Rank[i]==0)pq.push(i);

    while(!pq.empty()){
        int cur=pq.top();
        pq.pop();

        cout<<cur+1<<" ";

        for(auto next:student[cur]){
            Rank[next]--;
            if(Rank[next]==0)pq.push(next);
        }
    }
}