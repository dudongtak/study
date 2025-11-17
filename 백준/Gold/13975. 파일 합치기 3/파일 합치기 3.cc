#include<iostream>
#include<queue>
using namespace std;

int t,k;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    while(t--){
        cin>>k;
        priority_queue<ll,vector<ll>,greater<>> pq;

        int n;
        for(int i=0;i<k;i++){
            cin>>n;
            pq.push(n);
        }

        ll answer=0;
        while(pq.size()!=1){
            ll n1=pq.top();
            pq.pop();
            ll n2=pq.top();
            pq.pop();

            ll n3=n1+n2;
            answer+=n3;
            pq.push(n3);
        }
        cout<<answer<<"\n";
    }
}