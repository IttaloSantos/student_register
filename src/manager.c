#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"
#include "list_handler.h"

#define STUDENT_NAME_MAX_LEN 100

static list *student_list = NULL;

/* ######################################################### */
/*                         PROTOTYPES                        */
/* ######################################################### */

static list    *createStudentList(void);
static profile *createStudentProfile(const char *name, int age, long int rg_number, float cre);
static void     deleteStudentProfile(profile *profile_p);

/* ######################################################### */
/*                          PUBLIC                           */
/* ######################################################### */

struct profile_st
{
    char     name[STUDENT_NAME_MAX_LEN];
    int      age;
    long int rg_number;
    float    cre;
};

void MANAGER_addStudentOnList(const char *name, int age, long int rg_number, float cre)
{
    profile *profile_p = createStudentProfile(name, age, rg_number, cre);

    if(student_list == NULL) student_list = createStudentList();

    //! TODO: Create a private function to do the memcpy
    uint8_t *profile_bytes = (uint8_t*) calloc(1, sizeof(profile));

    memcpy(profile_bytes, profile_p, sizeof(profile) );

    LIST_addNodeOnTail(student_list, profile_bytes, sizeof(profile));

    deleteStudentProfile(profile_p);
    free(profile_bytes);
}

void MANAGER_printStudentProfile(const profile *profile_p)
{
    //! TODO: change the print student profile to get a specific profile from the list
    printf("\n-------- STUDENT PROFILE --------\n");
    printf("Name: %s\n", profile_p->name);
    printf("Age: %d\n", profile_p->age);
    printf("Registration: %ld\n", profile_p->rg_number);
    printf("CRE: %.2f\n", profile_p->cre);
}

void MANAGER_printStudentList(void)
{
    if(student_list == NULL) return;

    uint8_t *value     = NULL;
    profile *profile_p = (profile*) calloc(1, sizeof(profile));

    for(int i = 0; i < LIST_getListSize(student_list); i++)
    {
        value = LIST_getNodeValue(student_list, i);

        if(value == NULL) break;

        memcpy(profile_p, value, sizeof(profile));
        MANAGER_printStudentProfile(profile_p);
    }
}

/* ######################################################### */
/*                          PRIVATE                          */
/* ######################################################### */

static list *createStudentList(void)
{
    return LIST_createList();
}

static profile *createStudentProfile(const char *name, int age, long int rg_number, float cre)
{
    profile *std_profile = (profile*) calloc(1, sizeof(profile));

    strcpy(std_profile->name, name);
    
    std_profile->age       = age;
    std_profile->rg_number = rg_number;
    std_profile->cre       = cre;

    return std_profile;
}

static void deleteStudentProfile(profile *profile_p)
{
    free(profile_p);
    profile_p = NULL;
}