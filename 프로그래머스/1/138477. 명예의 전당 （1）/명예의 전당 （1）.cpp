#include <string>
#include <vector>
#include<queue>
using namespace std;

struct compare{
    bool operator()(const int &a,const int &b){
        return a>b;
    }
};

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int,vector<int>,compare> pq;
    for(int i=0;i<score.size();i++){
        if(pq.size()<k||pq.top()<=score[i]){
            if(pq.size()==k){
                pq.pop();
            }
            pq.push(score[i]);
        }
        answer.push_back(pq.top());
    }
    return answer;
}