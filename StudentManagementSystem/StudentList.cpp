#include "StudentList.h"
#include "Student.h"
#include <string>
#include <map>
#include <iostream>

using namespace std;


CStudentList::CStudentList(void)
{
}

void CStudentList::SetLevel(Level& theLevel)
{
	level = theLevel;
}

Feedback CStudentList::CheckLevel()
{
	if(level != Admin)
	{
		cout<<"Not enough authority to this behavior. Please log in with higher authority" << endl;
		return invalid;
	}
	else
	{
		return success;
	}
}

void CStudentList::AddStudent()
{
	if((CheckLevel()) == success)
	{
	int order = 0;
	int newID;
	char newChar;
	string newName;
	Gender newGender;
	int newAge;
	string newNation;


	CStudent* newStudent = new CStudent(); 
	while(order <= 5)
	{
		switch (order)
		{
		case 0:
			cout << "Please input the ID of the new student" << endl;
			cin >> newID;
			if(this->StudentList.find(newID) == this->StudentList.end())
			{
				newStudent->SetID(newID);
				order++;
			}
			else
			{
				cout << "The ID of student already exists" << endl;
			}
			break;
		case 1:
			cout << "Please input the name of the new student" << endl;
			cin >> newName;
			if(newName == " " || newName == "\n")
			{
				cout << "The name of student should be Chinese or English!" << endl;
			}
			else
			{
				newStudent->SetName(newName);
				order++;
			}
			break;
		case 2:
			cout << "Please input the gender(F/M). F for Female and M for Male." << endl;
			cin >> newChar;
			if(newChar == 'F')
			{
				newStudent->SetGender(female);
				order++;
			}
			else if(newChar == 'M')
			{
				newStudent->SetGender(male);
				order++;
			}
			else
			{
				cout << "The input is out of value. Please just input F or M" << endl;
			}
			break;
		case 3:
			cout << "Please input the age of the new student" << endl;
			cin >> newAge;
			if(newAge>0 && newAge < 100)
			{
				newStudent->SetAge(newAge);
				order++;
			}
			else
			{
				cout << "The age is out of range(0,100)" << endl ;
			}
			break;
		case 4:
			cout << "Please input the nationality of the new student" << endl;
			cin >> newNation;
			if(newNation == " " || newNation == "\n")
			{
				cout << "The nationality of student should not be empty or non-charcter!" << endl;
			}
			else
			{
				newStudent->SetNation(newNation);
				order++;
			}
			break;
		case 5:
			cout << "Successfully add the student to the list!" << endl;
			order++;
			this->StudentList.insert(make_pair(newID, (*newStudent)));
			break;
		default:
			cout << "Something wrong happen! Please contact to the author!" << endl;
			order = 100;
			break;
		}
	}
	}
	
	
	else
	{

	}
}

void CStudentList::UpdateStudent()
{
	if((CheckLevel()) == success)
	{
	int theID;
	cout << "Please input the ID of the student" << endl;
	cin >> theID;
	if(this->StudentList.find(theID) == this->StudentList.end())
	{
		cout << "The student isn't in the student list. Please check the ID." << endl;
		return;
	}
	else
	{
		int order;
		string newName;
		char newChar;
		int newAge;
		string newNation;

		cout << "Choose the order to change the following:" << endl;
		cout << "1 Name" << endl;
		cout << "2 Gender" << endl;
		cout << "3 Age" << endl;
		cout << "4 Nation" << endl;

		cin >> order;
		switch (order)
		{
		case 1:
			cout << "Please input the name of the new student" << endl;
			cin >> newName;
			if(newName == " " || newName == "\n")
			{
				cout << "The name of student should be Chinese or English!" << endl;
			}
			else
			{
				this->StudentList[theID].SetName(newName);
			}
			break;
		case 2:
			cout << "Please input the gender(F/M). F for Female and M for Male." << endl;
			cin >> newChar;
			if(newChar == 'F')
			{
				this->StudentList[theID].SetGender(female);
			}
			else if(newChar == 'M')
			{
				this->StudentList[theID].SetGender(male);
			}
			else
			{
				cout << "The input is out of value. Please just input F or M" << endl;
			}
			break;
		case 3:
			cout << "Please input the age of the new student" << endl;
			cin >> newAge;
			if(newAge>0 && newAge < 100)
			{
				this->StudentList[theID].SetAge(newAge);
			}
			else
			{
				cout << "The age is out of range(0,100)" << endl ;
			}
			break;
		case 4:
			cout << "Please input the nationality of the new student" << endl;
			cin >> newNation;
			if(newNation == " " || newNation == "\n")
			{
				cout << "The nationality of student should not be empty or non-charcter!" << endl;
			}
			else
			{
				this->StudentList[theID].SetNation(newNation);
				order++;
			}
			break;
		default:
			cout << "Something wrong happen! Please contact to the author!" << endl;
			break;
		}
	}
	}

	else
	{

	}
}

void CStudentList::DeleteStudent()
{
	if((CheckLevel()) == success)
	{
	int theID;
	cout << "Please input the ID of the student" << endl;
	cin >> theID;
	if(this->StudentList.find(theID) == this->StudentList.end())
	{
		cout << "The student isn't in the student list. Please check the ID." << endl;
		return;
	}
	else
	{
		this->StudentList.erase(theID);
		cout << "The student has been successfully deleted!" << endl;
		return;
	}
	}

	else
	{

	}
}

void CStudentList::ShowStudent(const int& theID)
{
	if((CheckLevel()) == success)
	{
	int theID;
	cout << "Please input the ID of the student" << endl;
	cin >> theID;
	if(this->StudentList.find(theID) == this->StudentList.end())
	{
		cout << "The student isn't in the student list. Please check the ID." << endl;
		return;
	}
	else
	{
		CStudent & refStu = this->StudentList[theID];
		cout << "StudentID: " << refStu.getID() << endl;
		cout << "Name: " << refStu.getName() << endl;
		cout << "Gender: " ;
		if(refStu.getGender() == female)
		{
			cout << "female" << endl;
		}
		else
		{
			cout << "male" << endl;
		}
		cout << "Age: " << refStu.getAge() << endl;
		cout << "Nation: " << refStu.getNation() << endl;
		cout << endl;
		return;
	}
	}

	else
	{

	}
}

CStudentList::~CStudentList(void)
{
}
