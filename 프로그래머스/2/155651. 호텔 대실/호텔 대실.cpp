#include <string>
#include <vector>
#include<map>
#include<queue>
using namespace std;

struct compare{
    bool operator()(const vector<int> &a,const vector<int> &b){
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]>b[0];
    }
};

int solution(vector<vector<string>> book_time) {
    vector<vector<int>> room;
    priority_queue<vector<int>,vector<vector<int>>,compare> pq;
    for(int i=0;i<book_time.size();i++){
        int s=stoi(book_time[i][0].substr(0,2))*60+stoi(book_time[i][0].substr(3,2));
        int e=stoi(book_time[i][1].substr(0,2))*60+stoi(book_time[i][1].substr(3,2));
        vector<int> tmp;
        tmp.push_back(s);
        tmp.push_back(e);
        pq.push(tmp);
    }
    while(!pq.empty()){
        vector<int> tmp=pq.top();
        pq.pop();
        if(room.size()==0){
            room.push_back(tmp);
            continue;
        }
        int i=0;
        int e=10000000;
        int j=1001;
        for(i;i<room.size();i++){
            if(room[i][1]+10<=tmp[0]){
                if(e>room[i][1]){
                    j=i;
                    e=room[i][1];
                }
            }
        }
        if(j>=room.size()){
            room.push_back(tmp);
        }
        else{
            room[j][1]=tmp[1];
        }
    }
    return room.size();
}