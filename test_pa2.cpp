#include <iostream>
using namespace std;

int factorial(int num){
    if (num==0){ // base case
        return 1; 
    } else { // recursive call
        return factorial(num - 1) * num; 
    }
}

double lucky(double seed_num){
/* 
returns a random number using the system 
time and the argument as a seed
*/
    srand(time(0) + seed_num);
    return rand() %1000;
}

int main(){
    int i;
    for (i=0; i<6; i++){
        cout << i << "!: " << factorial(i) << endl;
    }
    cout << "lucky: " << lucky(534) << endl;
}