#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"

struct student_profile
{
    char     *name;
    int      age;
    long int rg_number;
    float    cre;
};

profile *MANAGER_createStudentProfile(const char *name, int age, long int rg_number, float cre)
{
    profile *std_profile = (profile*) calloc(1, sizeof(profile));

    std_profile->name = (char*) calloc(1, sizeof(char));
    strcpy(std_profile->name, name);
    
    std_profile->age       = age;
    std_profile->rg_number = rg_number;
    std_profile->cre       = cre;

    return std_profile;
}

void MANAGER_deleteStudentProfile(profile *profile_p)
{
    free(profile_p);
    profile_p = NULL;
}

void MANAGER_printStudentProfile(const profile *profile_p)
{
    printf("-------- STUDENT PROFILE --------\n");
    printf("Name: %s\n", profile_p->name);
    printf("Age: %d\n", profile_p->age);
    printf("Registration: %ld\n", profile_p->rg_number);
    printf("CRE: %.2f\n", profile_p->cre);
}

