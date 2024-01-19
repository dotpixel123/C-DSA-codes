#include <stdio.h>
#include <string.h>
struct Student
{
    char name[50]; 
    int age; 
    float gpa; 
};


int main(){
    struct Student student1; 
    student1.age = 19;
    student1.gpa = 8.5;
    strcpy(student1.name, "Shourya");
    
    return 0;
}