#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "manager.h"

int main(int argc, char *argv[])
{
    if(argc != 5) exit(-1);

    int    age        = atoi(argv[2]);
    double reg_number = atof(argv[3]);
    float  cre        = atof(argv[4]);

    profile *student = MANAGER_createStudentProfile("Adam", 14, 20231200, 0.0);

    MANAGER_printStudentProfile(student);
    MANAGER_deleteStudentProfile(student);

    printf("\n");
    return 0;
}