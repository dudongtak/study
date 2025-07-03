#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int N;
vector<long long> liq;
vector<int> answer(3);
long long res=3000000001;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;
    liq.resize(N);

    for(int i=0;i<N;i++)cin>>liq[i];

    sort(liq.begin(),liq.end());
    

    for(int i=0;i<N-2;i++){
        int s=i+1,e=N-1;

        while(s<e){
            long long con=liq[i]+liq[s]+liq[e];
            if(abs(con)<res){
                res=abs(con);
                answer[0]=liq[i];
                answer[1]=liq[s];
                answer[2]=liq[e];
            }
            if(con<0)s++;
            else e--;
        }
    }

    cout<<answer[0]<<" "<<answer[1]<<" "<<answer[2];
}