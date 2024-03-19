#include<string>
#include<vector>
#include<iostream>
using namespace std;

typedef struct people{
    int name;
    int give=0;
    int take=0;
    int point;
    int nextGift=0;
}people;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int n=friends.size();
    vector<people> h;
    int i;
    int j;
    int k;
    for(i=0;i<n;i++){
        people human;
        human.name=i;
        h.push_back(human);
    }
    vector<vector<int>> p(n,vector<int>(n,0));
    for(i=0;i<gifts.size();i++){
        string str=gifts[i];
        string give="";
        string take="";
        for(j=0;j<str.length();j++){
            if(str[j]==' '){
                break;
            }
            give+=str[j];
        }
        for(j+=1;j<str.length();j++){
            take+=str[j];
        }
        for(j=0;j<n;j++){
            if(give==friends[j]){
                break;
            }
        }
        for(k=0;k<n;k++){
            if(take==friends[k]){
                break;
            }
        }
        p[j][k]++;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                continue;
            }
            h[i].give+=p[i][j];
            h[j].take+=p[i][j];
        }
    }
    for(i=0;i<n;i++){
        h[i].point=h[i].give-h[i].take;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                continue;
            }
            if(p[i][j]>p[j][i]){
                h[i].nextGift++;
            }
            else if(p[i][j]==p[j][i]){
                if(h[i].point>h[j].point){
                    h[i].nextGift++;
                }
            }
        }
    }
    for(i=0;i<n;i++){
        if(answer<h[i].nextGift){
            answer=h[i].nextGift;
        }
    }
    return answer;
}