#ifndef MANAGER_H
#define MANAGER_H

typedef struct profile_st profile;

profile *MANAGER_createStudentProfile(const char *name, int name_size, int age, long int rg_number, float cre);
void     MANAGER_deleteStudentProfile(profile *profile_p);
void     MANAGER_printStudentProfile(const profile *profile_p);

#endif