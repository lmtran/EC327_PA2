#include <iostream>
#include <fstream>
#include "pa2Functions.h"

using namespace std;


void helperWriteToFile(ofstream* file_pointer, double result){
    /*
    helper function to determine if pointer is set to null 
    if file_pointer = null: just cout
    if file_pointer != null: cout and write to file
    */
    if (file_stream.is_open()){
        //just cout
        cout << result << endl;
    } else {
        cout << result << endl;
        file_stream << result << endl;
    }
    return;
}

//overload to accept int type result
void helperWriteToFile(int result){
    if (file_stream.is_open()){
    //just cout
        cout << result << endl;
    } else {
        cout << result << endl;
        //cout << file_pointer << endl; 
        file_stream << result << endl;
    }
    return;
}

// function to execute in loop
void executeInLoop(double first, double last, double delta, double(*fn_ptr)(double)){
    if (delta <= 0 || first > last) {
        cout << "No computation needed." << endl;
        return;
    }

    int count = 0;
    double fn_val = first; //initially = first
    while (count < ENTRIES && fn_val <= last){
        double result = fn_ptr(fn_val); // call fn with pointer
       cout << result << endl; 

       // write to file if filepointer exists
    //    if (file_pointer != nullptr){
    //            *file_pointer << result << endl;
    //        }

        helperWriteToFile(result);

        fn_val += delta; //step up fn_val
        count++;
    }
    return;
}

int main(){
    // print the header
    initialize();

    while (true){

        // get code
        char code;
        cout << "Please enter command code: ";
        cin >> code;

        if (!checkCode(code)) {
            // if code invalid
            cout << "Invalid command code" << endl;
        } else if (code == 'Q' || code == 'q') {
            return 0; // exit whole program
        } else {
            // at this point we have a valid code

            // convert code to capital if necessary
            if (code > 96){
            //char is ascii lowercase
                code = code - 32; //adjust
            }

            //need to get additional parameters
            cout << "Please enter command parameters: ";


            // should add check for entered parameters that are chars --> break !!!!!!!!!!!!!!!!!!!!!!


            int num;
            string filename; //bc file stuff takes in const char*
            int intFirst, intLast;
            double doubFirst, doubLast, delta;

            if (code == 'F' || code =='B') {
                //single integer
                cin >> num;
            } else if (code == 'I' || code == 'O') {
                // filename is extra param
                cin >> filename;
            } else if (code == 'D' || code == 'E'){
                cin >> intFirst >> intLast;
            } else if (checkCode(code)) {
                // any other valid code
                cin >> doubFirst >> doubLast >> delta;
            }

            // make switch cases for all
            int ans;
            switch (code) {
                case 'F':
                    ans = factorial(num);
                    //cout << ans << endl;
                    helperWriteToFile(ans);
                    break;

                case 'B':
                    ans = fibonacci(num);
                    //cout << ans << endl;
                    helperWriteToFile(ans);
                    break;

                case 'R':
                    executeInLoop(doubFirst, doubLast, delta, &findSqrtValue);
                    break;

                case 'U':
                    executeInLoop(doubFirst, doubLast, delta, &areaSquare);
                    break;

                case 'C':
                    executeInLoop(doubFirst, doubLast, delta, &areaCircle);
                    break;

                case 'E':
                    //special case
                    break;

                case 'K':
                    break;

                case 'S':
                    break;

                case 'N':
                    break;

                case 'X':
                    break;

                case 'L':
                    break;

                case 'Y':
                    break;

                case 'D':
                    // special case
                    break;

                case 'I':
                    readDataFromFile(filename.c_str());
                    break;

                case 'O':
                    writeDataToFile(filename.c_str());
                    break;

                default:
                    cout << "error" << endl;
                    cout << "code: " << code << endl; //debug
                    break;

            }
            
        }
    
    }


    return 0; // for main()
}