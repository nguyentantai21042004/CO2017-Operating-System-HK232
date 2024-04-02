#include "process.h"

double calculationLogic(double *num1, double *num2, char *op)
{
    double ans = 0;

    switch (*op)
    {
    case '+':
        ans = addition(num1, num2);
        break;
    case '-':
        ans = subtraction(num1, num2);
        break;
    case 'x':
        ans = multiplication(num1, num2);
        break;
    case '/':
        ans = division(num1, num2);
        break;
    case '%':
        ans = modulo(num1, num2);
        break;
    default:
        break;
    }

    return ans;
}


double addition(double *num1, double *num2)
{
    return *num1 + *num2;
}

double subtraction(double *num1, double *num2)
{
    return *num1 - *num2;
}

double multiplication(double *num1, double *num2)
{
    return *num1 * *num2;
}

double division(double *num1, double *num2)
{
    // Do not need to check here one more time
    return *num1 / *num2;
}

double modulo(double *num1, double *num2)
{
    // Do not need to check here one more time
    return (int)(*num1) % (int)(*num2);
}
