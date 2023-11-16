#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y, z;

    // Constructor to initialize a point
    Point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

Point bottom_most(0, 0, 0); // Initializing with default values

// Utility function to find the next to top in a stack
Point nextToTop(stack<Point> &S) {
    Point top = S.top();
    S.pop();
    Point next_top = S.top();
    S.push(top);
    return next_top;
}

// Utility function to swap two points
void swap(Point &p1, Point &p2) {
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

// Function to find orientation of ordered triplet (p, q, r)
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0; // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or counterclockwise
}

// Comparator function for sorting points with reference to the bottom-most point
bool compare(Point p1, Point p2) {
    int orient = orientation(bottom_most, p1, p2);
    if (orient == 0)
        return ((bottom_most.x - p1.x) * (bottom_most.x - p1.x) +
                (bottom_most.y - p1.y) * (bottom_most.y - p1.y) +
                (bottom_most.z - p1.z) * (bottom_most.z - p1.z)) <=
               ((bottom_most.x - p2.x) * (bottom_most.x - p2.x) +
                (bottom_most.y - p2.y) * (bottom_most.y - p2.y) +
                (bottom_most.z - p2.z) * (bottom_most.z - p2.z));

    return (orient == 2);
}

// Function to compute the Convex Hull of a set of 3D points
void convexHull(vector<Point> points) {
    // Find the bottom-most point
    int min_idx = 0;
    for (int i = 1; i < points.size(); i++) {
        if (points[i].y < points[min_idx].y || (points[i].y == points[min_idx].y &&
                                                points[i].x < points[min_idx].x)) {
            min_idx = i;
        }
    }

    swap(points[0], points[min_idx]);
    bottom_most = points[0];

    sort(points.begin() + 1, points.end(), compare);

    // Remove duplicates if any
    int m = 1;
    for (int i = 1; i < points.size(); i++) {
        while (i < points.size() - 1 && orientation(bottom_most, points[i], points[i + 1]) == 0)
            i++;

        points[m] = points[i];
        m++;
    }

    if (m < 3) return; // Convex hull not possible

    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    for (int i = 3; i < m; i++) {
        while (orientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }

    // Print the points in the convex hull
    cout << "The points in the Convex Hull are:\n";
    while (!S.empty()) {
        Point p = S.top();
        cout << "(" << p.x << ", " << p.y << ", " << p.z << ")\n";
        S.pop();
    }
}

int main() {
    vector<Point> points = {
            Point(0, 3, 0),
            Point(2, 2, 2),
            Point(1, 1, 1),
            Point(2, 1, 3),
            Point(3, 0, 2),
            Point(3, 2, 1)
    };

    convexHull(points);

    return 0;
}