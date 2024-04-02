#include "process.h"

bool isSyntaxError(char *op){
    if(*op == '+' || *op == '-' || *op == 'x' || *op == '/' || *op == '%')
        return false;
    return true;
}

bool isMathError(char *op, double *num2){
    if((*num2 == 0 && *op == '/') || (*num2 == 0 && *op == '%'))
        return true;
    return false;
}