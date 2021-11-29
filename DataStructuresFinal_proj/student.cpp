#include "student.h"

Student::Student(char *, char *, int, char *, char *)
{

}

Student::~Student()
{

}

Student::Student()
{

}

Student::Student(const Student &)
{
    //StudentName =
}

void Student::SetStudentName(char *name)
{
    for(int i = 0; i<35; i++)
    {
        name=name+1;
        SchoolName[i] = *(name);
    }
}

char *Student::getStudentName()
{
    return StudentName;
}

void Student::SetSchoolName(const char * school)
{

    for(int i = 0; i<30; i++)
    {
        school=school+1;
        SchoolName[i] = *(school);
    }

}

char *Student::getSchoolName()
{
    return SchoolName;
}

void Student::SetOuncesSalad(int OZ)
{
    OuncesSalad = OZ;
}

int Student::getOuncesSalad()
{
    return  OuncesSalad;
}

void Student::SetEntreeName(char *a)
{

    for(int i = 0; i<15; i++)
    {
        a=a+1;
        EntreeName[i] = *(a);
    }
}

char *Student::getEntreeName()
{
    return EntreeName;
}

void Student::SetDessertName(char * d)
{
    for(int i = 0; i < 20; i++)
    {
        d=d+1;
        DessertName[i] = *(d);
    }
}

char *Student::getDessertName()
{
    return DessertName;
}
