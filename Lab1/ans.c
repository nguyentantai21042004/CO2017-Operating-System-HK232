#include "process.h"

#define DIRECTORY "ans.txt"
#define MAX_NUMBER_SIZE 16
#define MAX_PATH_LENGTH 1024

char *current_working_directory_with_file()
{
    // Get the current folder directory in flexible machine
    char *cwd = getcwd(NULL, 0);

    if (cwd != NULL)
    {
        size_t cwd_len = strlen(cwd);
        size_t dir_len = strlen(DIRECTORY);

        // Allocate memory for the full path
        char *full_path = (char *)malloc(cwd_len + dir_len + 2);
        if (full_path != NULL)
        {
            // Copy the current working directory to the full path
            strcpy(full_path, cwd);

            if (cwd[cwd_len - 1] != '/')
                strcat(full_path, "/");

            strcat(full_path, DIRECTORY);

            free(cwd);
            return full_path;
        }
        else
        {
            free(cwd);
            return NULL;
        }
    }
    else
        return NULL;
}

double getAns()
{
    double ans = 0;

    char *fullPath = current_working_directory_with_file();
    if (fullPath == NULL)
        return ans;

    FILE *ansFile = fopen(fullPath, "r");
    if (ansFile != NULL)
    {
        char ans_str[MAX_NUMBER_SIZE];
        if (fscanf(ansFile, "%s", ans_str) != EOF)
        {
            ans = atof(ans_str);
        }
        fclose(ansFile);
    }

    return ans;
}

void updateAns(double newAns)
{
    char *fullPath = current_working_directory_with_file();
    if (fullPath == NULL)
        return;

    FILE *ansFile = fopen(fullPath, "w");
    if (ansFile != NULL)
    {
        fprintf(ansFile, "%f", newAns);
        fclose(ansFile);
    }
}
