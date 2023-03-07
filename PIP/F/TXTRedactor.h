#include <string>

#ifndef TXTREDACTOR_H
#define TXTREDACTOR_H

using namespace std;

class TXTRedactor {
    public:
        TXTRedactor(string filePath);
        ~TXTRedactor();
        bool moveLines(string secondFile, string resultPath);
    private:
        string filePath;
};

#endif