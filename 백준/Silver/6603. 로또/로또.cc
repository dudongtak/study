#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        int K;
        cin>>K;
        if(K==0)break;
        vector<int> arr(K);
        for(int i=0;i<K;i++)cin>>arr[i];

        vector<int> flag(K,0);
        for(int i=0;i<6;i++)flag[i]=1;

        do{
            for(int i=0;i<K;i++)if(flag[i])cout<<arr[i]<<" ";
            cout<<"\n";
        }while(prev_permutation(flag.begin(),flag.end()));
        cout<<"\n";
    }
}