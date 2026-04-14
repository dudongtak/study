#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++)cin>>arr[i];
    vector<int> lis;

    for(int i=0;i<n;i++){
        if(lis.size()==0||lis[lis.size()-1]<arr[i]){
            lis.push_back(arr[i]);
        }
        else{
            int l=0,r=lis.size()-1,m;

            while(l<r){
                m=(l+r)/2;

                if(lis[m]<arr[i]){
                    l=m+1;
                }
                else r=m;
            }
            lis[l]=arr[i];
        }
    }

    cout<<n-lis.size();
}