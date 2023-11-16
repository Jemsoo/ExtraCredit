# ExtraCredit
Convex Hull Computation 


This C++ program computes the Convex Hull of a set of 3D points using the Graham Scan algorithm. The Convex Hull is the smallest convex polygon that encloses all the given points.

Overview

The program implements the Graham Scan algorithm to find the Convex Hull for a set of 3D points in space. It includes the following:

Point struct: Represents a point in 3D space, with x, y, and z coordinates.
convexHull() function: Computes the Convex Hull of a vector of Point objects using the Graham Scan method.
main() function: Demonstrates the usage by creating a set of 3D points and computing their Convex Hull.

Usage

To use this program:

Ensure you have a C++ compiler installed.
Clone the repository or copy the code into your C++ development environment.
Modify the points vector in the main() function to include your set of 3D points.
Compile and run the program.

File Structure

main.cpp: Contains the C++ code for the Convex Hull computation.
README.md: This file, providing an overview of the project.

Example

A simple example of usage:

vector<Point> points = {
    Point(0, 3, 0),
    Point(2, 2, 2),
    Point(1, 1, 1),
    Point(2, 1, 3),
    Point(3, 0, 2),
    Point(3, 2, 1)
};

convexHull(points);

