/*

Problem : 
On a busy road, multiple cars are passing by. A simulation is run 
to see what happens if brakes fail for all cars on the road. The 
only way for them to be safe is if they don't collide and pass by 
each other. The goal is to identify whether any of the given cars 
would collide or pass by each other safely around a Roundabout. 
Think of this as a reference point O ( Origin with coordinates 
(0,0) ), but instead of going around it, cars pass through it.

Considering that each car is moving in a straight line towards the 
origin with individual uniform speed. Cars will continue to travel 
in that same straight line even after crossing origin. Calculate 
the number of collisions that will happen in such a scenario.

Note : - Calculate collisions only at origin. Ignore the other 
collisions. Assume that each car continues on its respective path 
even after the collision without change of direction or speed for 
an infinite distance.

Constraints
1<=C<=10^5
-10^9 <= x,y <= 10^9
0 < v < 10^9.

Input Format
The first line contains an integer C, denoting the number of cars 
being considered that are passing by around the origin.

Next C lines contain 3 space delimited values, first two of them 
being for position coordinates (x,y) in 2D space and the third one 
for speed (v).

Output
A single integer Q denoting the number of collisions at origin 
possible for given set of cars.

Timeout
1


Test Case
Example 1
Input
5
5 12 1
16 63 5
-10 24 2
7 24 2
-24 7 2

Output
4

Explanation
Let the 5 cars be A, B, C, D, and E respectively.
4 Collisions are as follows -
1) A & B.
2) A & C.
3) B & C.
4) D & E.
*/

// Attempt 1 - vector
// Sample passed, maybe TLE in private, or overflow
// initially was int, now long and long long 
// for tle, sorted times first and checked if next element is same
// but lose ordering of cars, counting number of duplicate pairs
// time went from 7.905 seconds to 3.084
#include<bits/stdc++.h>
using namespace std;

int distance(long long x, long long y) {
    return (int)sqrt((x*x)+(y*y));
}

int main() {
    long cars;
    cin>>cars;
    vector<long long> times;
    for(int i=0;i<cars;i++) {
        long long x,y,speed;
        cin>>x>>y>>speed;
        long long time = distance(x,y)/speed;
        times.push_back(time);
    }

    int count = 0;
    sort(times.begin(), times.end());
    for (long i=0;i<cars;i++) {
        if (times[i+1]==times[i]) {
            count++;
        }
    }
    if (times[cars-1]==times[cars-2]) {
        count++;
    }
    cout<<count<<"\n";
    return 0;
}

// Attempt 2 - hashmap, hoping constant access time * n^2 is better
// went from 3.084 to 7.175
int main() {
    long cars;
    cin>>cars;
    unordered_map<int, long long> times;
    for(int i=0;i<cars;i++) {
        long long x,y,speed;
        cin>>x>>y>>speed;
        long long time = distance(x,y)/speed;
        times[i] = time;
    }

    int count = 0;
    for(int i=0; i<cars; i++) {
        for (int j=i+1; j<cars; j++ ) {
            if (times[i]==times[j]) {
                count++;
            }
        }
    }
    cout<<count<<"\n";
    return 0;
}