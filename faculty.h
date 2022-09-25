#pragma once
#include<iostream>
#include"person.h"
using namespace std;
class faculty:public person
{
	int course_count;
	char extension_no[20];
	public:
		faculty(const char*n,const char*l,int c,double cc,const char* ex):person(n,l,c)
		{
			cout<<"faculty() called\n";
			course_count=cc;
			int k=strlen(ex);
			int i=0;
			for(;i<k;i++)
			{
				extension_no[i]=ex[i];
			}
				extension_no[i]=0;
		}
		void print_faculty()
		{
			person::print_information();
			cout<<"has a course count of "<<course_count<<" and";
			cout<<"extension no is "<<extension_no<<endl;
		}
		virtual ~faculty()
		{
			cout<<"~faculty() called\n";
		}
};
