#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
int n,k;
vector<ll> s,d;
ll ans=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    s.resize(n);d.resize(n-1);

    for(int i=0;i<n;i++)cin>>s[i];

    for(int i=0;i<n-1;i++)d[i]=s[i+1]-s[i];
    sort(d.begin(),d.end());
    for(int i=0;i<n-k;i++)ans+=d[i];

    cout<<ans;
}