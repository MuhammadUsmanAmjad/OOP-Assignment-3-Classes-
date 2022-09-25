//#include<iostream>
//#include"person.h"
//#include"student.h"
//#include"faculty.h"
//#include"graduate_student.h"
//#include"under_graduate_student.h"
//using namespace std;
//int main()
//{
//	student s("Ted", "Thompson", 22, 3.91);
//	faculty f("Richard", "Karp", 45, 2, "420");
//	//here the number of courses is 2
//	//and the extension number is 420
//	s.print_student();
//	f.print_faculty();
//
//
//	//output:1
//
//   /*person() called
//	Student() called
//	person() called
//	faculty() called
//	Ted  Thompson is 22 years old.cgpa is 3.91
//	Richard  Karp is 45 years old.has a course count of 2 andextension no is 420
//	~faculty() called
//	~person() called
//	~student() called
//	~person() called*/
//
//
//	/*under_graduate u("Ted", "Thompson", 22, 3.91, "The Event Locator");
//	graduate g("Arnold", "Gates", 25, 3.01, "Distributed Algorithms");
//	u.print_undergraduate_student();
//	g.print_graduate_student();
//	u.print_student();*/
//
//
//	//output:2
//
// /*person() called
//	 Student() called
//	 under_graduate() called
//	 person() called
//	 Student() called
//	 graduate() student called
//	 Ted  Thompson is 22 years old.cgpa is 3.91
//	 has a final year project ofThe Event Locator
//	 Arnold  Gates is 25 years old.cgpa is 3.01
//	 has a thesis topic Distributed Algorithms
//	 Ted  Thompson is 22 years old.cgpa is 3.91
//	 ~graduate() called
//	 ~student() called
//	 ~person() called
//	 ~under_graduate() called
//	 ~student() called
//	 ~person() called*/
//
//	under_graduate u("Ted", "Thompson", 22, 3.91, "The Event Locator");
//	graduate g("Arnold", "Gates", 25, 3.01, "Distributed Algorithms");
//	u.print_undergraduate_student();
//	g.print_graduate_student();
//	u.print_student();
//
//
//	//output:3
//
////there is an error in print_student() function because it is protected function undergraduate
////because the inheritance type is protected so it is inaccessible in main();
////same is the case with private inheritance type.....!
//
//	system("PAUSE");
//	return 0;
//}