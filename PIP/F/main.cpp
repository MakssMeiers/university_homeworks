#include <iostream>
#include "TXTRedactor.h"
#include <iostream>

using namespace std;

void chechkPath(string & path) {
    string type = "";
    if (path.size()>4)
        type = path.substr(path.size()-4,4);   
    if ((path.size()<4)  || (type!=".txt"))
        path= path + ".txt";
}

int main() {
    bool test = false; //test will be false only if error occures

    while (!test) {

        //getting file paths from which will be copied lines, and result file path
        string path1, path2, rez;
        cout<<"Enter your first file path: ";
        cin>>path1;
        cout<<"\nEnter your second file path: ";
        cin>>path2;
        cout<<"\nEnter result file path: ";
        cin>>rez;
        cout<<endl;

        //checking whether they contain .txt or not 
        chechkPath(path1);
        chechkPath(path2);
        chechkPath(rez);

        TXTRedactor t(path1);

        test = t.moveLines(path2, rez);
        cout<<"-----------------------------"<<endl<<endl;
    }
    return 0;
}