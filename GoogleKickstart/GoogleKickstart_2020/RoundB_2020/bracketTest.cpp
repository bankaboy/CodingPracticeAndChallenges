#include<iostream>
using namespace std;

pair<int,int> deepestIndex (string program) {
    pair<int,int> indices{-1,-1};
    int max = 0, count = 0, last, n=program.length();
    for(int i=0;i<n;i++) {
        if (program[i]=='(') {
            last = i;
            count++;
        }
        if (program[i]==')') {
            if  (count>max) {
                indices = {last,i};
                max = count;
            }
            count--;
        }
    }
    return indices;
}

string parseProgram(string program) {
    bool nobrackets = true;
    string actual = "";
    int n = program.length();
    for (char c:program) {
        if (c=='(') {
            nobrackets = false;
            break;
        }
    }
    if (nobrackets) {
        return program;
    }
    pair<int,int> deepest = deepestIndex(program);
    for (int i=0;i<deepest.first-1;i++) {
        actual.push_back(program[i]);
    }
    int times = program[deepest.first-1]-'0';
    for(int i=0;i<times;i++) {
        actual.append(program.substr(deepest.first+1,deepest.second-deepest.first+1));
    }
    return parseProgram(actual);      
}

int main() {
    string program = "N3(S)N2(E)N";
    cout<<parseProgram(program)<<endl;
}