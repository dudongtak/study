#include<iostream>
#include<queue>
using namespace std;

int t;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    while(t--){
        int m;
        cin>>m;

        vector<int> ans;
        priority_queue<int> pq;
        priority_queue<int,vector<int>,greater<>> npq;

        for(int i=0;i<m;i++){
            int num;
            cin>>num;
            if(pq.size()==0)pq.push(num);
            else{
                if(pq.size()==npq.size()){
                    if(npq.top()<num){
                        int tmp=npq.top();
                        npq.pop();
                        npq.push(num);
                        pq.push(tmp);
                    }
                    else{
                        pq.push(num);
                    }
                }
                else{
                    if(pq.top()<num)npq.push(num);
                    else{
                        int tmp=pq.top();
                        pq.pop();
                        pq.push(num);
                        npq.push(tmp);
                    }
                }
            }
            if(i%2==0)ans.push_back(pq.top());
        }

        cout<<ans.size()<<'\n';
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<'\n';
    }
}