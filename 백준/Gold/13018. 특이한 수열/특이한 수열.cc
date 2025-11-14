#include<iostream>
using namespace std;

int n,k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;

    if(n==k||k==1){
        cout<<"Impossible";
        return 0;
    }

    cout<<n-k<<" ";
    for(int i=1;i<n-k;i++)cout<<i<<" ";
    for(int i=n-k+1;i<=n;i++)cout<<i<<" "; 
}