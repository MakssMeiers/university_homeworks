#include "TXTRedactor.h"
#include <iostream>
#include <fstream>

using namespace std;

TXTRedactor::TXTRedactor(string filePath) {
    this->filePath = filePath;
    cout << "Redactor object is created"<<endl;
}

TXTRedactor::~TXTRedactor() {
    cout << "Redactor object is deleted"<<endl;
}

bool TXTRedactor::moveLines(string secondFile, string resultPath) {
    //opening files;
    ifstream file1(filePath); //read mode
    ifstream file2(secondFile); //rm
    ofstream result(resultPath); //writing mode

    //if both file are opened
    if (file1.is_open() && file2.is_open()) {
        string line1, line2;
        //as long as we do not reach one of files end
        while(!(file1.eof() && file2.eof())) {
            //reading lines from files
            //even if we reached EOF, error will not occur
            getline(file1, line1); 
            getline(file2, line2);
            //writing both lines in file
            result << line1 + line2<<"\n";
        }
    }
    else {
        cout << "One of files does not exist"<<endl;
        file1.close();
        file2.close();
        result.close();
        return  false;
    }
    //closing all files
    file1.close();
    file2.close();
    result.close();
    return true;
}