#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


typedef pair<int,int> pii;
struct cmp{
    bool operator ()(pii &a,pii &b){
        if(a.first==b.first)return a.second>b.second;
        return a.first>b.first;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n,m,a,b;
        cin>>n>>m;
        vector<bool> books(n+1,true);

        priority_queue<pii,vector<pii>,cmp> pq;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            pq.push({b,a});
        }
        int cnt=0;
        while(!pq.empty()){
            pii cur=pq.top();
            pq.pop();

            for(int i=cur.second;i<=cur.first;i++){
                if(books[i]){
                    books[i]=false;
                    cnt++;
                    break;
                }
            }
        }
        cout<<cnt<<"\n";
    }
}