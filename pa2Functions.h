#ifndef PA2FUNCTIONS_H
#define PA2FUNCTIONS_H
// #include <iostream>
// #include <fstream> // for reading & writing to file
// #include <vector> // for checkCode
// #include <iterator> // for checkCode
// #include <cmath>
// #include <ctime> // for lucky

using namespace std;

extern const int ENTRIES; //in header file, declaration only
extern ofstream* fileStream;

/* 
all the function headers for 
PA2 - defined in pa2Functions.cpp
*/

void initialize();

bool checkCode(char code);

void writeDataToFile(const char *);

void readDataFromFile(const char *);

int factorial(int num);

int fibonacci(int num);

double findSqrtValue (double num);

double naturalLog(double num);

double areaCircle(double radius);

double areaSquare(double side_len);

int findNextOddValue(int num);

int findNextEvenValue(int num);

double findNyanCatValue(double num);

double doMath(double num, char operation);

double lucky(double num);

#endif