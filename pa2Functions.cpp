#include <iostream>
#include <fstream> // for reading & writing to file
#include <vector> // for checkCode
#include <iterator> // for checkCode
#include <string> // for readFile fn (reading whole line at a time)
#include <cmath>
#include <ctime> // for lucky
#include "pa2Functions.h"

#define PI 3.14159

using namespace std;

// both defined as extern in header file
ofstream* fileStream = NULL; 
extern const int ENTRIES = 10;


int factorial(int); // prototype for recursion
int fibonacci(int); // prototype for recursion

void initialize(){
/*
(Header Sample)
EC327: Introduction to Software Engineering
Fall 2026
Programming Assignment 2
Value of Entries is: 10

ENTRIES must be obtained from Q1.cpp
*/
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Spring 2026" << endl;
    cout << "Programming Assignment 2" << endl;
    cout << "Value of Entries is: " << ENTRIES << endl;
}

bool checkCode(char code){
/*
This function should return true if the command code in 
parameter “code” is a legal code character; otherwise, 
the function should return false. You have to use this 
function to check your user input. 
This function is called from main().
*/
    // convert to upper case if relevant
    if (code > 96){
        //char is ascii lowercase
        code = code - 32; //adjust
    }

    // vector dynamically allocates, array is static length
    vector<char> valid_codes = {'F', 'B', 'R', 'U', 'C', 'E', 'K',
        'S', 'N', 'X', 'L', 'Y', 'D', 'I', 'O', 'Q'};

    
    if (find(valid_codes.begin(), valid_codes.end(), code) != valid_codes.end()) {
        return true;
    } else {
        return false;
    }
    
}

void writeDataToFile(const char* filename){
/*
This function will write the output of the program to a file 
specified by user input. This only works for input provided 
AFTER this command has been provided. The output being written to a
file should also be displayed to the console as well. Writing to 
a file ends when the quit command is provided
*/
    // create ofstream object on the heap
    fileStream = new ofstream(filename);

}

void readDataFromFile(const char * filename){
/*
The function will read commands from a file specified by user 
input. This function is called from main(). The commands in this 
file should be formatted each on two lines consistent with how
the user would enter them from the command line.

e.g.
f
10
R
10 20 .2
*/

    ifstream input(filename);
    string line;
    /*
    using get line function in <string> lib lets us read a whole line at a time
    so that loop execution displays on one line like in the file
    */
   
    while (getline(input, line)){
        cout << line << endl;
    }
    input.close();
}

int factorial(int num){
    if (num==0){ // base case
        return 1; 
    } else { // recursive call
        return factorial(num - 1) * num; 
    }
}

int fibonacci(int index){
/*
returns the Fibonacci number at the 
index given by the provided argument
*/

    // define first and second term in sequence
    int fib_first = 0;
    int fib_second = 1;

    // check for each of the cases
    if (index == 0) { // first base case
        return fib_first;
    } else if (index == 1){ // second base case
        return fib_second;
    } else { // recursive call - sum the 2 previous terms
        return fibonacci(index - 1) + fibonacci(index - 2);
    }
}

double findSqrtValue (double num){
    return sqrt(num);
}

double naturalLog(double num){
// returns the natural log of the provided argument
    return naturalLog(num);
}

double areaCircle(double radius){
    return PI * radius * radius;
}

double areaSquare(double side_len){
    return side_len * side_len;
}

int findNextOddValue(int num){
/*
returns an odd number closest and higher to the provided number

assumes 0 is even
*/
    double check_odd;
    check_odd = num % 2;
    if (check_odd == 1) {
        // num is odd
        return num;
    } else {
        return num + 1;
    }
}

int findNextEvenValue(int num){
/*
returns an even number closest and higher to the provided number

assumes 0 is even
*/
    int check_even;
    check_even = num %2;
    if (check_even == 0){
        // num is even
        return num;
    } else {
        return num +1;
    }
}

double findNyanCatValue(double num){
/*
returns (4 * num)^num + num + 10
*/
    double inner_paren = 4 * num;
    double first_term = pow(inner_paren, num);
    return first_term + num + 10;
}

double doMath(double num, char operation){
/*
performs either sin, cosine, or the exponential function for 
the value provided. The operation to perform is based on the 
char that is provided

operation arguments:
's/S': sine
'c/C': cosine
'e/E': exponential

sine and cosine assume radian input
*/

    if (operation > 96){
        //char is ascii lowercase
        operation = operation - 32; //adjust
    }

    if (operation == 'S'){
        //return sine value
        return sin(num);
    } else if (operation == 'C') {
        //return cosine value
        return cos(num);
    } else if (operation == 'E'){
        //return value of exponential fn
        return exp(num);
    } else {
        // NEED TO THROW ERROR?
        return 0.0;
    }
}

double lucky(double seed_num){
/* 
returns a random number using the system 
time and the argument as a seed

range of lucky nums: 0-999
*/
    srand(time(0) + seed_num);
    return rand() %1000;
}
