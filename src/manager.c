#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"
#include "list_handler.h"

static list *student_list = NULL;

/* ######################################################### */
/*                         PROTOTYPES                        */
/* ######################################################### */

static list *createStudentList(void);

/* ######################################################### */
/*                          PUBLIC                           */
/* ######################################################### */

struct profile_st
{
    char     *name;
    int      age;
    long int rg_number;
    float    cre;
};

profile *MANAGER_createStudentProfile(const char *name, int name_size, int age, long int rg_number, float cre)
{
    profile *std_profile = (profile*) calloc(1, sizeof(profile));

    std_profile->name = (char*) calloc(1, name_size*sizeof(char));
    strcpy(std_profile->name, name);
    
    std_profile->age       = age;
    std_profile->rg_number = rg_number;
    std_profile->cre       = cre;

    return std_profile;
}

void MANAGER_deleteStudentProfile(profile *profile_p)
{
    free(profile_p->name);
    free(profile_p);
    profile_p = NULL;
}

void MANAGER_addStudentOnList(profile *profile_p)
{
    if(student_list == NULL) student_list = createStudentList();

    int profile_total_size = sizeof(profile) + strlen(profile_p->name);
    uint8_t *profile_bytes = (uint8_t*) calloc(1, profile_total_size);

    memcpy(profile_bytes, profile_p, profile_total_size);

    LIST_addNodeOnHead(student_list, profile_bytes, profile_total_size);

    free(profile_bytes);
}

void MANAGER_printStudentProfile(const profile *profile_p)
{
    printf("-------- STUDENT PROFILE --------\n");
    printf("Name: %s\n", profile_p->name);
    printf("Age: %d\n", profile_p->age);
    printf("Registration: %ld\n", profile_p->rg_number);
    printf("CRE: %.2f\n", profile_p->cre);
}

/* ######################################################### */
/*                          PRIVATE                          */
/* ######################################################### */

static list *createStudentList(void)
{
    return LIST_createList();
}
