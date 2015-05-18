#include "Student.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

CStudent::CStudent(void)
{
}

void CStudent::SetLevel(Level& theLevel)
{
	level = theLevel;
}

Feedback CStudent::CheckLevel()
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

void CStudent::SetName(string& theName)
{
	if((CheckLevel()) == success)
		name = theName;
}

void CStudent::SetID(int& theID)
{
	if((CheckLevel()) == success)
		id = theID; 
}

void CStudent::SetGender(Gender theGender)
{
	if((CheckLevel()) == success)
		gender = theGender;
}

void CStudent::SetAge(int& theAge)
{
	if((CheckLevel()) == success)
		age = theAge;
}

void CStudent::SetNation(string& theNation)
{
	if((CheckLevel()) == success)
		nation = theNation;
}

const string CStudent::getName()
{
	return name;
}
const int CStudent::getID()
{
	return id;
}

const Gender CStudent::getGender()
{
	return gender;
}

const int CStudent::getAge()
{
	return age;
}

const string CStudent::getNation()
{
	return nation;
}

void CStudent::SelectNewCourse(string courseName)
{
	//int courseID;
	//cout << "please input the course id you want to pick for the next semester:" << endl;
	//cin >> courseID;
	selectedCourse.insert(selectedCourse.end(),courseName);
}

void CStudent::DeleteCourse(string courseName)
{
	vector<string>::iterator it;
	for(it = selectedCourse.begin(); it != selectedCourse.end(); it++)
	{
		if(*it == courseName)
		{
			selectedCourse.erase(it);
			cout << "Successfully deleted course: " << courseName << endl;
			break;
		}
	}
	
}

void CStudent::ShowSelectedCourse()
{
	vector<string>::iterator it;
	cout << "Next Semester Course List -----" << endl;
	for(it = selectedCourse.begin(); it != selectedCourse.end(); it++)
	{
		cout << *it << endl;
	}
	cout << endl;
}

void CStudent::ShowInformation()
{
	cout << "Student Information" << endl;
	cout << "Student ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Gender: " ;
	if(gender == female)
	{
		cout << "female" << endl;
	}
	else
	{
		cout << "male" << endl;
	}
	cout << "Age: " << endl;
	cout << "Nation: " << endl;

	ShowSelectedCourse();
}

CStudent::~CStudent(void)
{
}
