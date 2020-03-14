/*
Consider a class student having roll number and supporting methods to get and print the roll number, 
this class will be inherited by two different classes: 
test and score that gives the marks in two subjects and marks in sports category respectively. 

In final class result (inherits class test and score) find the total marks and 
print all the data (roll number, marks in two subjects, marks in sports and total marks). 
Use the concept of virtual base class.
*/
#include <iostream>

using namespace std;

class student;
class test;
class score;
class result;

class student
{
    public:
    int rollno
};