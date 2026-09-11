#include <string>
#include <vector>
#include<algorithm>

using namespace std;


int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    sort(data.begin(),data.end(),[col](const vector<int> &a,const vector<int> &b)
         {
        if(a[col-1]==b[col-1])return a[0]>b[0];
             return a[col-1]<b[col-1];
    });
    for(int i=row_begin-1;i<row_end;i++){
        int res=0;
        for(int j=0;j<data[0].size();j++)res+=data[i][j]%(i+1);
        answer^=res;
    }
    return answer;
}