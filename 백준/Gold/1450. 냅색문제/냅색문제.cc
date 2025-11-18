#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,c;
typedef long long ll;
vector<ll> w;

void dfs(int s,int e,vector<ll> &v,ll sum){
    if(s>e){
        v.push_back(sum);
        return;
    }

    dfs(s+1,e,v,sum);
    dfs(s+1,e,v,sum+w[s]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>c;
    w.resize(n);

    for(int i=0;i<n;i++)cin>>w[i];

    vector<ll> p1,p2;

    dfs(0,n/2-1,p1,0);
    dfs(n/2,n-1,p2,0);
    sort(p2.begin(),p2.end());

    ll answer=0;
    for(int i=0;i<p1.size();i++){
        ll w=c-p1[i];
        int l=0,r=p2.size()-1,m,pos=-1;

        while(l<=r){
            m=(l+r)/2;

            if(p2[m]<=w){
                l=m+1;
                pos=m;
            }
            else{
                r=m-1;
            }
        }
        answer+=(pos+1);
    }
    cout<<answer;
}