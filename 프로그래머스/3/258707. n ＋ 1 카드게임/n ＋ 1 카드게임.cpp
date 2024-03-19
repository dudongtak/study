#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;

bool find(vector<int> &c,int n,int &coin,int size){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(c[i]+c[j]==c.size()+1&&c[i]!=0&&c[j]!=0){
                if(i>=size)coin--;
                if(j>=size)coin--;
                if(coin<0){
                    if(i>=size)coin++;
                    if(j>=size)coin++;
                    continue;
                }
                c[i]=0;
                c[j]=0;
                return true;
            }
        }
    }
    return false;
}

int solution(int coin, vector<int> cards) {
    int answer = 0;
    int n=cards.size()/3;
    int size=n;
    
    while(coin>=0){
        n+=2;
        answer++;
        if(n>cards.size())break;
        
        if(!find(cards,n,coin,size))break;
        if(coin<0)break;
    }
    return answer;
}