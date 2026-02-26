#include <iostream>
using namespace std;


int getLargest(double arr[], int size){
    int largest = arr[0]; // largest starts as first value

    // get number of elements
    size_t length = sizeof(*arr) / sizeof(arr[0]);
    // size_t = unsigned int type used for sizes of objects/counts of elements in containers

    // i starts at 1 because largest is initially arr[0]
    for (int i = 1; i < int(length); i++){
        /*
        step through array and if curent value is
        greater than saved largest, it is new largest
        */
        if (arr[i] > largest){
            largest = arr[i];
            cout << largest << endl;
            cout << "i: " << i << endl;
        }
    }
    return largest;
}

int main(){
    double arr[5] = {1.5, 4.8, 9.3, 16.2, 0.0 };
    cout << getLargest(arr, 5) << endl;
}