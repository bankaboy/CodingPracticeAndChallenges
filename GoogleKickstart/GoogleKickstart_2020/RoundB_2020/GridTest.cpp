#include<iostream>
#include<vector>
using namespace std;

void dispVector(vector<vector<int>> v) {
    int l = v.size(), w = v[0].size();
    for(int i=0;i<l;i++) {
        for (int j=0;j<w;j++) {
            cout<<v[i][j];
        }
        cout<<endl;
    }
}
double testCase(int W,int H,int L,int U,int R,int D) {
    vector<vector<int>> grid(H,vector<int>(W,0));
    auto inside = [&](int row, int col) {
            return 0 <= row && row < H && 0 <= col && col < W;
    };
    double total = 0, actual = 0;
    for(int i=U-1;i<D;i++) {
        for(int j=L-1;j<R;j++) {
            grid[i][j] = -1;
        }
    }
    dispVector(grid);
}

int main() {
    testCase(2,2,2,2,2,2);
}