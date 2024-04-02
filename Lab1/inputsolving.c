#include "process.h"

void clearScreenAndPrompt()
{
    fflush(stdout); 
    getchar(); // Get only one character
    system("clear || cls"); 
}

bool isNumeric(const char *str) {
    char *endptr;
    strtod(str, &endptr);
    return *endptr == '\0';
}

bool solveInputString(char *input, double *num1, double *num2, char *op)
{
    char num1_str[50], num2_str[50];
    int count = sscanf(input, "%49s %c %49s", num1_str, op, num2_str);

    if (count != 3 || strlen(num1_str) == 0 || strlen(num2_str) == 0 || *op == '\0') {
        return false;
    }

    if ((!isNumeric(num1_str) && strcmp(num1_str, "ANS") != 0) || 
            (!isNumeric(num2_str) && strcmp(num2_str, "ANS") != 0)) {
        return false;
    }

    if (strcmp(num1_str, "ANS") == 0)
        *num1 = getAns();
    else
        *num1 = atof(num1_str);

    if (strcmp(num2_str, "ANS") == 0)
        *num2 = getAns();
    else
        *num2 = atof(num2_str);

    return true;
}

