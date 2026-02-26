#include <iostream>
#include <fstream> // for file stuff

#include "FileFunctions.h"
#include "Statistics.h"

using namespace std;

int * DoubleAndReverse (int *list, int size){
    /*
    doubles the size of an integer array and fills the
    second half with a copy of the first half in reverse order

    The function should return a pointer to an integer array that 
    has a size equal to 2*size. The values in the new array at 
    indices from 0 to size-1 should have the same values as in the 
    original input array in the same order. The rest of the values 
    in the new array should be the reverse order of the original array.
    */

    // initialize a new array
    int* newArray = new int[2 * size];

    for (int i =0; i< size; i++){
        // fill newArray with initial array
        newArray[i] = list[i];
    }

    // fill second half of array with reversed original array
    for (int i = 0; i<size; i++){
        newArray[size + i] = list[(size-1)-i];
    }

    return newArray;
}


int main() {

    // create data.txt file
    string filename = "data.txt";
    
    cout << "Writing file: " << filename << endl;
    cout << "Reading file: " << filename << endl;

    int arrSize = 5;
    int maxVal = 20;
    int theArray[arrSize];

    //write array to file
    WriteRandomData(arrSize, maxVal, filename.c_str());

    // read file and get size of array
    ReadData(filename.c_str(), arrSize, theArray);

    // call DoubleAndReverse & print
    int* newArray;
    newArray = DoubleAndReverse(theArray, arrSize);
    cout << "Doubled and reversed is [ ";
    for (int i = 0; i < arrSize*2; i++){
        cout << *(newArray+i) << ' ';
    }
    cout << ']' << endl;

    // calculate statistics
    double median;
    int largest;

    // need to convert array to double[] for fns
    double doubArray[arrSize*2];
    for(int i=0; i < arrSize*2; i++){
        doubArray[i] = double(newArray[i]);
    }

    // call the functions and save the values
    median = getMedian(doubArray, arrSize*2);
    largest = getLargest(doubArray, arrSize*2);

    //print out results
    cout << "Median is: " << median << endl;
    cout << "Largest is: " << largest << endl;

    return 0;
}