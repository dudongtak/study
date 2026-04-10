#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> v,lis;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    v.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        if(lis.size()==0||lis[lis.size()-1]<v[i])lis.push_back(v[i]);
        else{
            int l=0,r=lis.size()-1;
            while(l+1<r){
                int m=(l+r)/2;

                if(v[i]>lis[m]){
                    l=m;
                }
                else if(v[i]<=lis[m]){
                    r=m;
                }
            }
            if(lis[l]>=v[i])lis[l]=v[i];
            else lis[r]=v[i];
        }
    }
    
    cout<<lis.size();
}