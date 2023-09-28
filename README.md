# Simple Platform for registration of students

The student structure properties:

- name;

- age;

- registration number;

- CRE.

The platform is able to:

- Create a student profile;

- Create a profile list;

- Add a student profile in the list;

- Remove a profile from the list;

- Show all profiles in the list.

The project contains four library modules:

- list.c (manager of the structure data doubly linked list, the base module);

- stack.c (stack manager);

- queue.c (queue manager);

- manager.c (layer module to manage student list using the list.c module).

How it works:

The main app waits for the user to input the student information listed above until the user exits menu.

Some tests are performed at the app modules using those three library modules.
