#pragma once
#include<iostream>
#include"person.h"
using namespace std;
class student:public person
{
 double cgpa;
public:
	student(const char* fname,const char* lname,int age,double c):person(fname,lname,age)
{
		cgpa=c;

cout << "Student() called\n";
}
void print_student()
{
	person::print_information();
	cout<<"cgpa is "<<cgpa<<endl;
}
virtual ~student()
{
	cout<<"~student() called\n";
}
};