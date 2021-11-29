
/* Done by: Farshad Rabbani
    Nov 22, 2004
    Purpose: Generate a file of students
*/

#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>//for rand()
#include <time.h>
#include<string.h>
#include<algorithm>
#include<queues.h>
#include<stack>
#include<student.h>
using namespace std;

//IMPORTANT CHECK LINE 136

void GenerateFile(fstream &, string*, const int,
                  string*, string*, string*);
void GenerateFile2(fstream &, char*, const int,
                  string*, string*, string*, string*);

void randomizeNames(string *, const int);

int Rand(int n)
{
    return rand() % n ;
}

int main()
{
    Student Student;

    queues Q;//creates a queues object

    int numRecords = 0;

    srand(time(NULL));

    cout<<"Please enter the number of student records you want in your file: ";
    cin>>numRecords;

    while( numRecords > 120 || numRecords < 1)
    {
        cout<<"You cannot create more than 120 records! "
            <<"\nThat exceeds the number of available trays\n";

        cout<<"Please enter the number of student records you want generated: ";
        cin>>numRecords;

    }


    string Schools[] = {"Eastville","Westburg","Northton","Southport","Jahunga","Podunk"};

    string Entrees[] = {"Chicken","Fishsticks","Lasagna"};

    string Desserts[] = {"Cheesecake","Pudding"};


    char InFile[] = "names.txt";
    char OutFile[] = "Students.txt";


    fstream Input(InFile, ios::in);
    fstream Output(OutFile, ios::out);

    string names[120];
    int i = 0;
    string s;

    while (!Input.eof())
        getline(Input, names[i++]); // Discards newline char


    randomizeNames(names, i);

    GenerateFile(Output, names, numRecords, Schools, Entrees, Desserts);

    Input.close();
    Output.close();

    cout << "The file " << OutFile << " was created for you.\n\n";

    //EVERYTHING AFTER THIS IS TO SEPERATE THE DIFFERENT INFORMATION
    char InFile2[] = "Students.txt";

    fstream INFORMATION(InFile2, ios::in);//reads the student.txt file

    string info[120];
    int b = 0;
    string r;

    while (!INFORMATION.eof())//seperates it into individual lines
        getline(INFORMATION, info[b++]); // Discards newline char

    //ARRAYS TO SEPARATE THE STUDENT'S INFORMATION.
    string names2[120];
    string schools[120];
    string entree[120];
    string dessert[120];
    string salad[120];

    int a=0, c=0, e=0, f=0, g=0;

    for(int i = 1; i < (numRecords*5); i+=5)//reads the names and assigns it to an array for names.
    {
        names2[c]=info[i];
        a++;
    }


    for(int i = 2; i < (numRecords*5); i+=5)//reads the school names and assigns it to an array for schools.
    {
        schools[c]=info[i];
        c++;
    }

    for(int i = 3; i < (numRecords*5); i+=5)//reads the ounces of salad and assigns it to an array for salads.
    {
        salad[e]= info[i];
        e++;
    }

    for(int i = 4; i < (numRecords*5); i+=5)//reads the entrees and assigns it to an array for entrees.
    {
        entree[f] = info[i];
        f++;
    }

    for(int i = 5; i <=(numRecords*5); i+=5)//reads the dessert and assigns it to an array for dessert.
    {
        dessert[g]=info[i];
        g++;
    }
    //END of Splitting studetns inFormation

    //START of assigning to queues

//    Q.assign(names2, numRecords);//ALSO IMPORTANT!! I CAN'T FIGURE OUT TO HOW TO MAKE IT RETURN THE QUEUES
//    Q.getQLeft();               //IF IT CAN'T RETURN IT THEN IT CAN'T BE USED OUTSIDE OF THE CLASS
//                                //AND WE NEED IT TO BE ABLE TO MAKE STUDENTS IN THE QUEUE PICK THEIR TRAYS

    //END of assignin to Queues


    //START OF ASSIGNING AND SHUFFLING TRAY COLORS //IMPORTANT!!!!! from here to line 198
    srand(time(0));                                 //i can't figure out how to make it into a function to place it into
    const int VECTOR_SIZE = 120;                    //a class of its own so that it does not crowd the Main Function

    // Define a template class vector of int
    typedef vector<string, allocator<string> > IntVector;

    //Define an iterator for template class vector of strings
    typedef IntVector::iterator IntVectorIt;
    IntVector Numbers(VECTOR_SIZE);
    IntVectorIt start, end;

    // Initialize vector Numbers

    for(int i = 0; i < 20; i++)
        Numbers[i] = "green";
    for(int i = 20; i < 40; i++)
        Numbers[i] = "blue";
    for(int i = 40; i < 60; i++)
        Numbers[i] = "purple";
    for(int i = 60; i < 80; i++)
        Numbers[i] = "orange";
    for(int i = 80; i < 100; i++)
        Numbers[i] = "red";
    for(int i = 100; i < 120; i++)
        Numbers[i] = "pink";


    start = Numbers.begin();   // location of first
    // element of Numbers
    end = Numbers.end();       // one past the location
    // last element of Numbers

    // shuffle the elements in a random order.
    // the pointer_to_unary_function adapter converts a function to a
    // function object.
    random_shuffle(start, end, pointer_to_unary_function<int, int>(Rand));


    //STACKS ON THE RIGHT QUEUE

    stack<string>qRightStack1;
    stack<string>qRightStack2;

    //STACKS ON THE LEFT QUEUE
    stack<string>qLeftStack1;
    stack<string>qLeftStack2;

    for(int i = 0; i < 120; i++)
    {
        int randomStack = rand()%4;
        if(randomStack == 0)
            qRightStack1.push(Numbers[i]);
        else if(randomStack == 1)
            qRightStack2.push(Numbers[i]);
        else if(randomStack == 2)
            qLeftStack1.push(Numbers[i]);
        else
            qLeftStack2.push(Numbers[i]);

    }

    //END of shuffling colors

    //START OF CREATING FILE WITH PRICES

//    char studentBody[] = "studentBody.txt"; //Error will have to convert to char
//   fstream studentBody1(studentBody, ios::out);
//   // char InFile[] = "names.txt";

//   GenerateFile2(studentBody1, names2, numRecords, schools, entree, dessert, salad);
//   Output.close();

   //END OF CREATING FILE WITH PRICES

    return 0;
}



void GenerateFile(fstream &Out, string* name, const int records,
                  string* School, string* Entree, string* Dessert )
{

    int seed = rand();

    Out<<seed<<endl;

    for(int i = 0; i < records; i++)
    {
        Out << name[i] << endl;
        Out << School[rand() % 6 ] << endl ;  //select a random school
        Out << (rand() % 10) << endl; //select a random number of ounces between 0-10
        Out << Entree[rand() % 3 ] << endl;   //select random entree
        Out << Dessert[rand() % 2 ] << endl;  //select random dessert
    }
    Out << "Done" << endl;
}

void GenerateFile2(fstream &Out, char* name, const int records,
                  string* School, string* Entree, string* Dessert, string* salad)
{

    int seed = rand();

    Out<<seed<<endl;

    for(int i = 0; i < records; i++)
    {
        //Prices for Entrees
        float chicken = 4.75, fishSticks = 4.00, lasagna = 3.75;
        //Prices for desserts
        float cheesecake = 2.50, pudding = 1.75;
        //price for salad
        float saladP = 2.50;

        Out << name[i] << endl;
        Out << School[i] << endl ;

        string str = salad[i];
        float salad_float = std::stof(str);//converts the string to a float so that it can be multiplied with a float/price.
        Out << salad[i]<<" = $"<<salad_float * saladP << endl;

        //IF FUNCTION TO ADD PRICES TO THE ENTREES
        if(Entree[i] == "Chicken")
        {
        Out << Entree[i]<<"= $"<<chicken << endl;
        }
        else if(Entree[i]=="Fishsticks")
        {
            Out <<Entree[i]<<"= $"<<fishSticks<<endl;
        }
        else
            Out << Entree[i] << " = $"<<lasagna<<endl;

        //IF FUNCTION TO GIVE PRICES FOR THE DESSERTS.
        if(Dessert[i] == "Cheesecake")
        {
        Out << Dessert[i] <<" = $"<<cheesecake<< endl;
        }
        else if(Dessert[i] == "Pudding")
            Out << Dessert[i] << " = $"<<pudding<<endl;

    }
    Out << "Done" << endl;
}


void randomizeNames( string * arrayOfNames, const int arraySize )
{
    string hold;
    int randomPosition;
    for ( int i = 0; i < arraySize; i++)
    {
        randomPosition = rand() % arraySize;
        hold = arrayOfNames[i];
        arrayOfNames[i] = arrayOfNames[randomPosition];
        arrayOfNames[randomPosition] = hold;

    }


}
