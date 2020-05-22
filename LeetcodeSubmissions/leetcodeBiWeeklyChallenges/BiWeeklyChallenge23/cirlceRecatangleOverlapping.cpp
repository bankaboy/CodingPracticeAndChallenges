/*
Problem Statement - 

Given a circle represented as (radius, x_center, y_center) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.
Return True if the circle and rectangle are overlapped otherwise return False.
In other words, check if there are any point (xi, yi) such that belongs to the circle and the rectangle at the same time.

Input: radius = 1, x_center = 0, y_center = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
Output: true
Explanation: Circle and rectangle share the point (1,0) 

Input: radius = 1, x_center = 0, y_center = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
Output: true

Input: radius = 1, x_center = 1, y_center = 1, x1 = -3, y1 = -3, x2 = 3, y2 = 3
Output: true

Input: radius = 1, x_center = 1, y_center = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
Output: false

MY TRY - 

    double give_dist(int x1,int y1, int x2, int y2) {
        return sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
    }
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        if ((x_center+radius>x1 || x_center-radius<x2) && (y_center+radius>y1 || y_center-radius<y2)) 
            return true;
        int rec_x = (x1+x2)/2, rec_y = (y1+y2)/2;
        double dist = give_dist(rec_x,rec_y,x_center,y_center);
        if ((dist/2)<=(double)radius)
            return true;
        return false;
    }

FROM DISCUSSION - 

We first check whether the circle is within the rectangle.
If not, we check whether any point on the ractanble border is within the circle.
*/

#include<iostream>
using namespace std;

bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
    auto inside = [&](int x, int y) {
        return abs(x - xc) * abs(x - xc) + abs(y - yc) * abs(y - yc) <= r * r; };
    if (x1 <= xc && xc <= x2 && y1 <= yc && yc <= y2)
        return true;
    for (auto x = x1; x <= x2; ++x) {
        if (inside(x, y1) || inside(x, y2))
            return true;
    }
    for (auto y = y1; y <= y2; ++y) {
        if (inside(x1, y) || inside(x2, y))
            return true;                             
    }
    return false;
}