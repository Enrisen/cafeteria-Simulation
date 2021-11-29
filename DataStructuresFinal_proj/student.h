#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <fstream>
#include<string>
using std::ostream;
using std::istream;
using std::fstream;

class Student {

public:

        Student(char*,char*,int,char*,char*);
        Student();
        Student(const Student&);
        ~Student();

      void SetStudentName(char*);
      char* getStudentName();
      void SetSchoolName(const char*);
      char* getSchoolName();
      void SetOuncesSalad(int);
      int getOuncesSalad();
      void SetEntreeName(char*);
      char* getEntreeName();
      void SetDessertName(char*);
      char* getDessertName();

      friend ostream& operator << (ostream& out, const Student& );
      friend istream& operator >> (istream& in,  Student& );
      friend fstream& operator >> (fstream& Fin, Student& s);
      Student& operator =(const Student&);
      bool operator <(const Student& s);
      bool operator >(const Student& s);
      bool operator ==(const Student& s);


private:


    char StudentName[35];
    char SchoolName[30];
    int OuncesSalad;
    char EntreeName[15];
    char DessertName[20];
};
#endif
