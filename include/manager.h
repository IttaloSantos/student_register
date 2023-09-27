#ifndef MANAGER_H
#define MANAGER_H

typedef struct profile_st profile;

void MANAGER_addStudentOnList(const char *name, int age, long int rg_number, float cre);
void MANAGER_printStudentProfile(const profile *profile_p);
void MANAGER_printStudentList(void);
void MANAGER_removeStudentFromList(long int rg_number);
void MANAGER_destroyStudentList(void);

#endif