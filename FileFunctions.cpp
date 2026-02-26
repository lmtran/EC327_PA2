#include <iostream>
#include <fstream> // for reading & writing to file
#include <ctime> // for random

using namespace std;

void WriteRandomData(int N, int M, const char *filename){
    /*
    generates N random integers from 0 to M (inclusive) and 
    writes them to a text file named data.txt, one number per line
    */

    ofstream output;
    output.open(filename);

    srand(time(0)); //seed
    int number;

    for (int i = 0; i < N; i++) {
        number = rand() % (M+1); // rand number 0-M inclusive
        //cout << number << endl; // debug
        output << number << endl;
        
    }

    output.close();
    return;
}

void ReadData(const char *filename, int &size, int myArray[]){
    /*
    reads the data from the specified text file, and
    also finds the size (number of data elements)
    */

    ifstream input(filename);
    int numElems = 0;
    int num;

    /*
    originally had while (!input.eof()) but that was iterating an extra time
    
    */
    while (input >> num){
        // save value on line as elem in array
        myArray[numElems] = num;
        numElems++; //increment element counter
    }

    /*
    save num Elems to passed size var
    size is already a referenced var, don't need
    * because that would dereference
    */
    size = numElems;

    // close the file and return nothing
    input.close();
    return;
}

