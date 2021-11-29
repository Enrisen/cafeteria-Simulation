#ifndef SCHOOL_H
#define SCHOOL_H

#include "tree.h"
#include "student.h"

class School
{

public:
    School();
    School(char*);
    ~School();
    void addStudent(Student& );
    void printStudentBody();
    float getBill();
    friend ostream& operator <<(ostream&,  School& );
    char* getSchoolName();


private:
    /* 	static data members belong to the class and not to a specific object of the class.  This means that there
    is only one static data member created per class, regardless of the number of objects created.
*/
    Tree<Student> studentTree;
    static float totalBill;
    static const float fishsticks;
    static const float chicken;
    static const float lasagna;
    static const float cheesecake;
    static const float pudding;
    static const float salad;
    char schoolName[25];

};

#endif

