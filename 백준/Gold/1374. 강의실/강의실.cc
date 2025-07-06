#include<iostream>
#include<queue>
#include<vector> 
#include<algorithm>
using namespace std;

int N,A,B,C;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;

    priority_queue<int,vector<int>,greater<>> pq;
    vector<pair<int,int>> Class;

    for(int i=0;i<N;i++){
        cin>>A>>B>>C;

        Class.push_back({B,C});
    }

    sort(Class.begin(),Class.end());

    for(int i=0;i<N;i++){
        int s=Class[i].first,e=Class[i].second;

        if(!pq.empty()&&pq.top()<=s){
            pq.pop();
        }
        pq.push(e);
    }

    cout<<pq.size();
}