#include <iostream>
#include <fstream>
#include "pa2Functions.h"

using namespace std;

bool writeBool = false;
extern ofstream* fileStream; 

void helperWriteToFile(double result){
    /*
    helper function to determine if pointer is set to null 
    if file stream not open: just cout
    if file stream is open: cout and write to file

    when passing double, means calling in loop --> separate by spaces
    */

    if (fileStream != NULL){
        // fileStream should be opened
        cout << result << endl;
        *fileStream << result << ' ';
    } else{
        cout << result << endl;
    }

    // if (filename == ""){
    //     // no filename passed, just cout
    //     cout << result << endl;
    // } else {
    //     writeDataToFile(filename.c_str()); //this opens the filestream
    //     cout << result << endl;
    //     *fileStream << result << endl;
    //     (*fileStream).close(); // close the filestream
    // }

    return;
}

//overload to accept int type result
void helperWriteToFile(int result){

    if (fileStream != NULL){
        // fileStream should be opened
        cout << result << endl;
        *fileStream << result << endl;
    } else{
        cout << result << endl;
    }

    // if (filename == ""){
    //     // no filename passed, just cout
    //     cout << result << endl;
    // } else {
    //     writeDataToFile(filename.c_str()); //this opens the filestream
    //     cout << result << endl;
    //     *fileStream << result << endl;
    //     (*fileStream).close(); // close the filestream
    // }

    return;
}


// function to execute in loop
void executeInLoop(double first, double last, double delta, double(*fn_ptr)(double)){
    if (delta <= 0 || first > last) {
        cout << "No computation needed." << endl;
        return;
    }

    int count = 0;
    double fnVal = first; //initially = first
    while (count < ENTRIES && fnVal <= last){
        double result = fn_ptr(fnVal); // call fn with pointer

        helperWriteToFile(result);

        fnVal += delta; //step up fn_val
        count++;
    }

    if (fnVal > last && (count+1) < ENTRIES){
        //if a delta increment exceeds the last value, use last for the final computation
        fnVal = last;
        double result = fn_ptr(fnVal); // call fn with pointer
        helperWriteToFile(result);
    }
    
    if (fileStream != NULL){
        //need newline at end of loop exection
        (*fileStream) << endl;
    }

    return;
}

void executeInLoopDoMath(double first, double last, double delta, char operation){
    if (delta <= 0 || first > last) {
        cout << "No computation needed." << endl;
        return;
    }

    int count = 0;
    double fnVal = first; //initially = first
    while (count < ENTRIES && fnVal <= last){
        double result = doMath(fnVal, operation);

        helperWriteToFile(result);

        fnVal += delta; //step up fn_val
        count++;
    }

    if (fnVal > last && (count+1) < ENTRIES){
        //if a delta increment exceeds the last value, use last for the final computation
        fnVal = last;
        double result = doMath(fnVal, operation); // call fn with pointer
        helperWriteToFile(result);
    }
    
    if (fileStream != NULL){
        //need newline at end of loop exection
        (*fileStream) << endl;
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

            // if writeDataToFile has been called, record the codes on each line
            if (fileStream != NULL){
                // fileStream should be opened
                *fileStream << code << endl;
            }

            // convert code to capital if necessary
            if (code > 96){
            //char is ascii lowercase
                code = code - 32; //adjust
            }

            //need to get additional parameters
            cout << "Please enter command parameters: ";


            // should add check for entered parameters that are chars --> break !!!!!!!!!!!!!!!!!!!!!!


            int num;
            // initialize filename to empty string, will be changed if user uses 'O' cmd
            string filename = ""; // string type bc file stuff takes in const char*
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
                    executeInLoop(doubFirst, doubLast, delta, &lucky);
                    break;

                case 'S':
                    //sine
                    executeInLoopDoMath(doubFirst, doubLast, delta, 'S');
                    break;

                case 'N':
                    //cosine
                    executeInLoopDoMath(doubFirst, doubLast, delta, 'C');
                    break;

                case 'X':
                    //exponential
                    executeInLoopDoMath(doubFirst, doubLast, delta, 'E');
                    break;

                case 'L':
                    //natural log
                    executeInLoop(doubFirst, doubLast, delta, &naturalLog);
                    break;

                case 'Y':
                    // nyanCat
                    executeInLoop(doubFirst, doubLast, delta, &findNyanCatValue);
                    break;

                case 'D':
                    // special case
                    break;

                case 'I':
                    readDataFromFile(filename.c_str());
                    break;

                case 'O':
                    writeBool = true;
                    writeDataToFile(filename.c_str());
                    break;

                default:
                    cout << "error" << endl;
                    cout << "code: " << code << endl; //debug
                    break;

            }
            
        }
    
    }

    if (fileStream != NULL){
        // close the filestream before exiting
        (*fileStream).close();
    }

    return 0; // for main()
}