#include <algorithm> // for sort
using namespace std;

double getMedian(double arr[], int size){
    // need to order the array
    sort(arr, arr +size);

    /*
    then select the middle term:
    if even: average of the two center terms
    if odd: the center term
    */
    if (size%2 == 0){
        //even
        int centerL, centerR;
        centerR = arr[size/2];
        centerL = arr[(size/2) -1];
        return double(centerR + centerL) / 2;

    } else {
        //odd
        // 5/2 = 2 in C --> index 2 = 3rd term (center of 5)
        return arr[size/2];
    }
}

int getLargest(double arr[], int size){
    int largest = arr[0]; // largest starts as first value

    // i starts at 1 because largest is initially arr[0]
    for (int i = 0; i < size; i++){
        /*
        step through array and if curent value is
        greater than saved largest, it is new largest
        */
        if (arr[i] > largest){
            largest = arr[i];
        }
    }

    return largest;
}