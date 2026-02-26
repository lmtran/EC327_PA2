#include <iostream>

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

int* ReverseMultiply(int *list, int size){
    // initialize a new array
    int* newArray = new int[(2 * size) +1];
    newArray = DoubleAndReverse(list, size);

    // now add final term that is product of all
    int prod = 1;
    for (int i = 0; i < (2*size); i++){
        prod = prod * newArray[i];
    }

    //set prod as last term
    newArray[2*size] = prod;

    return newArray;

}

int* ReverseAdd(int *list, int size){
    // initialize a new array
    int* newArray = new int[(2 * size) +1];
    newArray = DoubleAndReverse(list, size);

    // now add final term that is product of all
    int sum = 0;
    for (int i = 0; i < (2*size); i++){
        sum = sum + newArray[i];
    }

    //set prod as last term
    newArray[2*size] = sum;

    return newArray;
}

int main(){
    // get user inputs
    int size;
    cout << "Enter the number of entries: ";
    cin >> size;

    // initialize array based on amt entries
    int array[size];

    for (int i = 0; i < size; i++){
        // get term from user
        int term;
        cout << "Entry " << i << " is: ";
        cin >> term;
        // save term in array
        array[i] = term;
    }

    cout << "*****" << endl; //spacer

    cout << "Original array is: ";
    // print each term of array, separated by spaces
    for (int i = 0; i < size; i++){
        cout << array[i] << ' ';
    }
    cout << "and the address of the zero element is: " << &array[0] << endl; // can also do 'array' (see below)

    // Reverse and Multiply
    int* multArray;
    multArray = ReverseMultiply(array, size);
    cout << "One array is: ";
    for (int i = 0; i < (size*2 + 1); i++){
        cout << multArray[i] << ' ';
    }
    cout << "and the address of the zero element is: " << multArray << endl;

    //Reverse and Add
    int* sumArray;
    sumArray = ReverseAdd(array, size);
    cout << "Two array is: ";
    for (int i = 0; i < (size*2 + 1); i++){
        cout << sumArray[i] << ' ';
    }
    cout << "and the address of the zero element is: " << sumArray << endl;


    return 0;
}