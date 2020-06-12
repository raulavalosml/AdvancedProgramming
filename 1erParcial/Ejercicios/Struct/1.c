#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    char id[9];
    short birthYear;
    char name[120];
};
int main()
{
    struct student someStudent, students[20];
    someStudent.birthYear=1990;
    strcpy(someStudent.name,"Apolo");
}
