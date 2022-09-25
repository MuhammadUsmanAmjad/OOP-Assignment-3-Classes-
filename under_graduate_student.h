#pragma once
#include<iostream>
#include"student.h"
using namespace std;
class under_graduate:public student
{
	char fyp_name[20];
	public:
		
		under_graduate(const char*f,const char*l,int a,double c,const char*n):student(f,l,a,c)
		{
			cout<<"under_graduate() called\n";
			int k=strlen(n);
			int i=0;
			for(;i<k;i++)
			{
				fyp_name[i]=n[i];
			}
			fyp_name[i]=0;
		}
		void print_undergraduate_student()
		{
			student::print_student();
			cout<<" has a final year project of"<<fyp_name<<endl;
		}
		virtual ~under_graduate()
		{
			cout<<"~under_graduate() called\n";
		}
};