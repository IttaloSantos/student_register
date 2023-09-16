#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "manager.h"

int main()
{
    char     name[50]   = {0};
    int      age        = 0;
    long int reg_number = 0;
    float    cre        = 0.0;

    while(name[0] != '/')
    {
        printf("\nType the student's name (type '/' to exit):\n");
        scanf("%s", name);
        fflush(stdin);
        if(name[0] == '/') break;

        printf("\nType the student's age, register number and CRE separated by space:\n");
        scanf("%d %ld %f", &age, &reg_number, &cre);
        fflush(stdin);

        MANAGER_addStudentOnList(name, age, reg_number, cre);
    }

    MANAGER_printStudentList();

    printf("\n");
    return 0;
}