//
//  main.cpp
//  Gallegos_Michael_Lab4
//
//  Created by Michael Gallegos on 9/12/18.
//  Copyright © 2018 Michael Gallegos. All rights reserved.
//
/* Create a class called Point with two private data members, a public print function, and constructors as well as a destructor that prints a message when it is called.
 Create an array of 10 Points on the stack, initialize them with non-zero data, and print them.  Verify that that the destructor is called for all 10 points when your program exits.
 Create an array of 10 Points on the heap, initialize them with non-zero data, and print them.
 Do not delete the array and verify the destructor is not called (you have created a memory leak).
    Now write your program to delete the array at the end.
 Verify that only one destructor is called and your program crashes (you have created a memory leak and a bug).
 Now write your program to delete[] the array at the end.
 Verify that all destructors are called.
*/

#include <iostream>
using namespace std;
class Point {
private:
    int x;
    int y;
public:
    Point(){}
    Point(int _x, int _y) {
        cout << "constructor being made" << endl;
        x = _x;
        y = _y;
    } // default constructor
    void printPoint(){
        cout << x << ", " << y << endl << "---------" << endl;
    };
    ~Point() {cout << "this is the destuctor" << endl;} // deconstruct it
};


int main(int argc, const char * argv[]) {
    // insert code here...
    // On the stack means no pointer
    Point arrayOfPoint[10] = {{2,2}, {2,3}, {2,4}, {2,5}, {2,6}, {2,7}, {2,8}, {2,9}, {2,10}, {2,11}};
    for (int i = 0; i<10 ; i++){
        arrayOfPoint[i].printPoint();
    }
    
    // on the heap means pointer
    Point *pointsForStuff = new Point[10]{
        {1,2}, {1,3}, {1,4}, {1,5}, {1,6}, {1,7}, {1,8}, {1,9}, {1,10}, {1,11}
    };
    
    for (int i = 0; i < 10; i++){
        pointsForStuff[i].printPoint();
    }
    //delete pointsForStuff; //error
    delete[] pointsForStuff;
    
    std::cout << "Hello, World!\n";
    return 0;
}
