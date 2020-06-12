typedef struct student
{
    char id[10];
    short birthDay;
    char name[120];
}Student;//para poner un alias

int main()
{
    Student someStudent, students[20];
    Student student1 = 
    {
        "A12345678",
        2000
        "Jiren DBZ"
    };
    Student student2 = 
    {
        .id= "A12345678",
        .year= 2000
    };
}


