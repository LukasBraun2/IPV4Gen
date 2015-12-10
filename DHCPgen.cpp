//*****************
//Project Name: Average
//Project Description: This program calculates the average grade of three different grades
//Project Author: Braun, Lukas
//Is this an extra credit Project:  No
//Date completed: 09/08/2015
//Operating system used: Windows
//IDE Used:  Eclipse
//*****************

/*
 * Definitely switching to Linux, Windows sucks.
 *
 * Average Grade Calculator - Try Not to be grade4
 *
 */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {

	double grade1 = 0, grade2 = 0, grade3 = 0;
	int grade4 = 0;
	int intGrade;

	const int TOTALGRADES = 4;
	string studentID;
	string stuLastName;
	string stuFirstName;
	string stuFullName;
	char ltrGrade;


	cout << "Welcome to my Grade Calculator" << endl;
	cout << "==============================" << endl;


	//
	//enter Personal data
	//

	inputFirst:
		cout << "Enter students first name" << endl;
		getline(cin, stuFirstName);
		if(stuFirstName.length() > 12) {
			cout << "That name is too long, enter a shorter one" << endl;
			goto inputFirst;
		}

	inputLast:
		cout << "Enter students last name" << endl;
		getline(cin, stuLastName);
		if(stuLastName.length() > 20) {
			cout << "That name is too long, enter a shorter one" << endl;
			goto inputLast;
		}

	inputStuID:
		cout << "Student ID needed" << endl;
		getline(cin, studentID);
		if(studentID.length() > 6) {
			cout << "That name is too long, enter a shorter one" << endl;
			goto inputStuID;
		}

	stuFullName = (stuFirstName + ", " + stuLastName + " ");

	//
	//now, ask the user to enter their grades
	//
	Grade1:
		cout << "Please enter Grade #One: " << endl;
		cin >> grade1;
		if(grade1 > 0 && grade1 < 100){
			goto Grade2;
		} else {
			cout << "I'm sorry, the grade should be between 0-100" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			goto Grade1;
		}


	Grade2:
		cout << "Please enter Grade #Two: " << endl;
		cin >> grade2;
		if(grade2 > 0 && grade2 < 100){
			goto Grade3;
		} else {
			cout << "I'm sorry, the grade should be between 0-100" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			goto Grade2;
		}

	Grade3:
		cout << "Please enter Grade #Three: " << endl;
		cin >> grade3;
		if(grade3 > 0 && grade3 < 100){
			goto Continue;
		} else {
			cout << "I'm sorry, the grade should be between 0-100" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			goto Grade3;
		}

	//computer generated grade4 btween 0-100
	Continue:
		srand(time(0));
		grade4 = rand();
		grade4 %= 100;

		//
		//Calculate Avg Grades
		//

		double avgGrade = (grade1 + grade2 + grade3 + grade4) / TOTALGRADES;
		cout << "Grade1 = " << grade1 << endl;
		cout << "Grade2 = " << grade2 << endl;
		cout << "Grade3 = " << grade3 << endl;
		cout << "Grade4 = " << grade4 << endl;
		cout << "Your average grade is: " << avgGrade << endl;

		intGrade = avgGrade;
		switch (intGrade){
			case 0 ... 59:
				ltrGrade = 'F';
				break;
			case 60 ... 69:
				ltrGrade = 'D';
				break;
			case 70 ... 79:
				ltrGrade = 'C';
				break;
			case 80 ... 89:
				ltrGrade = 'B';
				break;
			case 90 ... 100:
				ltrGrade = 'A';
				break;
		}

		//Print report Header

		cout << "Student Grade Report" << endl;
		cout << "---------------------" << endl;
		cout << endl;
		cout << setw(10) << "    Stu-ID" << setw(19) << "Name" << setw(10) << "Grade 1" << setw(10) << "Grade 2" << setw(10) << "Grade 3" << setw(10) << "Grade 4" << setw(13) << "Avg Grades" << setw(8) << "Letter" << endl;
		cout << setw(10) << "    ------" << setw(19) << "----------------" << setw(10) << "-------" << setw(10) << "-------" << setw(10) << "-------" << setw(10) << "-------" << setw(13) << "----------" << setw(8) << "------" <<endl;

		//Print report Data

		cout << setprecision(2) << fixed;
		cout << setw(10) << studentID << setw(19) << stuFullName << setw(10) << grade1 << setw(10) << grade2 << setw(10) << grade3 << setw(10) << grade4 << setw(13) << avgGrade << setw(8) << ltrGrade << endl;

		cout << "\nProgram Ending - Have a nice day!\n";

		return 0;

}
