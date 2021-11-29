#include<school.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;


//School::School()
//{

//}

//School::School(char *)
//{

//}

//void School::addStudent(Student &)
//{

//}

void School::printStudentBody()
{
    std::ifstream f("studentBody.txt");

      if(f.is_open())
       std::cout << f.rdbuf();

}

//float School::getBill()
//{
//    return totalBill;
//}

//char *School::getSchoolName()
//{
//    return schoolName;
//}
