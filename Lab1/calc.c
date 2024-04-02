#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "process.h"

#define MAX_LENGTH 200

int main()
{
    while (1)
    {
        printf(">> ");

        // Input Processing
        char input[MAX_LENGTH];
        fgets(input, MAX_LENGTH, stdin);
        if (input[strlen(input) - 1] == '\n') // If have a newline character at the last => remove
            input[strlen(input) - 1] = '\0';

        // OUT POINT of the while loop
        if (strcmp(input, "EXIT") == 0)
            return 0;

        if (strcmp(input, "ANS") == 0)
        {
            printf("%.2lf\n", getAns());
            clearScreenAndPrompt();
            continue;
        }

        // Solve Input String
        double num1, num2;
        char op;
        if (!solveInputString(input, &num1, &num2, &op))
        {
            printf("SYNTAX ERROR\n");
            clearScreenAndPrompt();
            continue;
        }

        // Check cases
        if (isMathError(&op, &num2))
        {
            printf("MATH ERROR\n");
            clearScreenAndPrompt();
            continue;
        }
        if (isSyntaxError(&op))
        {
            printf("SYNTAX ERROR\n");
            clearScreenAndPrompt();
            continue;
        }

        // Here, Math is VALID ==> calutate
        double ans = calculationLogic(&num1, &num2, &op);

        // Print ans to screen
        printf("%.2lf\n", ans);

        // Update this success math answer to ans.txt
        updateAns(ans);

        // Wait for another input ==> Clear the screen
        clearScreenAndPrompt();
    }

    return 0;
}