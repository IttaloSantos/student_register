#include <stdio.h>
#include "manager.h"

int main(int argc, char *argv[])
{
    profile *student = MANAGER_createStudentProfile("Adam", 14, 20231200, 0.0);

    MANAGER_printStudentProfile(student);
    MANAGER_deleteStudentProfile(student);

    printf("\n");
    return 0;
}