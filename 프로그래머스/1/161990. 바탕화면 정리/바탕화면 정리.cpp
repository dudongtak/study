#include <string>
#include <vector>
#include<algorithm>
using namespace std;
typedef struct mood{
    int x,y;
}mood;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    vector<mood> moods;
    mood s;s.x=wallpaper.size();s.y=wallpaper[0].size();
    mood e;e.x=-1;e.y=-1;
    for(int i=0;i<wallpaper.size();i++){
        for(int j=0;j<wallpaper[0].size();j++){
            if(wallpaper[i][j]=='#'){
                if(s.x>i)s.x=i;
                if(s.y>j)s.y=j;
                if(e.x<i+1)e.x=i+1;
                if(e.y<j+1)e.y=j+1;
            }
        }
    }
    answer.push_back(s.x);
    answer.push_back(s.y);
    answer.push_back(e.x);
    answer.push_back(e.y);
    return answer;
}