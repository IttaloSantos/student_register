#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "manager.h"

int main(int argc, char *argv[])
{
    if(argc != 5) exit(-1);

    int      age        = atoi(argv[2]);
    long int reg_number = atoi(argv[3]);
    float    cre        = atof(argv[4]);

    MANAGER_addStudentOnList(argv[1], age, reg_number, cre);

    printf("\n");
    return 0;
}