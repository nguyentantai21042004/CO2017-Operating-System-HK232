#include <stdio.h>
#include <stdlib.h> // for atof
#include <string.h> // for strerror
#include <unistd.h> // for readlink
#include <libgen.h> // for dirname
#include <errno.h>
#include <stdbool.h>

#define ANSFILE "ans.txt"
#define MAX_NUMBER_SIZE 16

void clearScreenAndPrompt();
bool isNumeric(const char *str);
bool solveInputString(char *input, double *num1, double *num2, char *op);

bool isSyntaxError(char *op);
bool isMathError(char *op, double *num2);

double calculationLogic(double *num1, double *num2, char *op);
double addition(double *num1, double *num2);
double subtraction(double *num1, double *num2);
double multiplication(double *num1, double *num2);
double division(double *num1, double *num2);
double modulo(double *num1, double *num2);

void updateAns(double newAns);
double getAns();
