#ifndef REQUESTSTRUCT_H
#define REQUESTSTRUCT_H
#include <string>
using namespace std;


struct RequestStruct {
    string ipIn;
    string ipOut;
    int processTime;

    RequestStruct(string in, string out, int time) : ipIn(in), ipOut(out), processTime(time) {}
};

#endif