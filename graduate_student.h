#pragma once
#include<iostream>
#include"student.h"
using namespace std;
class graduate:public student
{
	char thesis_topic[20];
public:
	graduate(const char*f,const char*l,int a,double c,const char*n):student(f,l,a,c)
		{
			cout<<"graduate() student called\n";
			int k=strlen(n);
			int i=0;
			for(;i<k;i++)
			{
				thesis_topic[i]=n[i];
			}
			thesis_topic[i]=0;
		}
		void print_graduate_student()
		{
			student::print_student();
			cout<<"  has a thesis topic "<<thesis_topic<<endl;
		}
		virtual ~graduate()
		{
			cout<<"~graduate() called\n";
		}
};