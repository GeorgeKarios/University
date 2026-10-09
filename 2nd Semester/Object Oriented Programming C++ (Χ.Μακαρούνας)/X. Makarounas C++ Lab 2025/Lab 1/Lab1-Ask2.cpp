// Example 2 for classes
// Include GradeBook class file for use in main.
#include "GradeBook.h"
using namespace std;
int main()
{
    // function main begins program execution
    GradeBook gradeBook1("CS101 Introduction to C++ Programming");
    GradeBook gradeBook2("CS102 Data Structures in C++");
    // create two GradeBook objects
    // display initial value of courseName for each GradeBook
    cout << "gradeBook1 created for course: " << gradeBook1.getCourseName()
         << "\ngradeBook2 created for course: " << gradeBook2.getCourseName()
         << endl;
    return 0; // indicate successful termination
} 
