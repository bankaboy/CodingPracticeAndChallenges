#include<bits/stdc++.h>
using namespace std;

void displayQueries(vector<pair<char,pair<int,int>>> queries) {
    for (pair<char,pair<int,int>> query: queries) {
        cout<<query.first<<" "<<query.second.first<<" "<<query.second.second;
        cout<<"\n";
    }
}

int main() {
    vector<pair<char,pair<int,int>>> queries;
    char queryChar;
    int queryNum1, queryNum2, queryCount;
    cin>>queryCount;
    for (int k=0;k<queryCount;k++) {
        cin>>queryChar>>queryNum1>>queryNum2;
        queries.push_back(make_pair(queryChar,make_pair(queryNum1, queryNum2)));
    }
    displayQueries(queries);
}