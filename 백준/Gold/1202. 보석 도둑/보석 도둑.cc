#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N,K,m,v,c;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>K;

    vector<pair<int,int>> jewel(N);
    vector<int> bag(K);
    for(int i=0;i<N;i++)cin>>jewel[i].first>>jewel[i].second;
    for(int i=0;i<K;i++)cin>>bag[i];
    
    sort(jewel.begin(),jewel.end());
    sort(bag.begin(),bag.end());

    long long answer=0;
    int j=0;
    priority_queue<int> pq;

    for(int i=0;i<K;i++){
        while(j<N&&jewel[j].first<=bag[i]){
            pq.push(jewel[j].second);
            j++;
        }

        if(!pq.empty()){
            answer+=pq.top();
            pq.pop();
        }
    }
    
    cout<<answer;
}