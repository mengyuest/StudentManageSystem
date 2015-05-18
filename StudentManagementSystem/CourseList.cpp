#include "CourseList.h"
#include "Course.h"
#include "Student.h"
#include <map>
#include <iostream>
#include <string>

using namespace std;

CCourseList::CCourseList(void)
{
}

void CCourseList::SetLevel(Level& theLevel)
{
	level = theLevel;
}

Feedback CCourseList::CheckLevel()
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
	
void CCourseList::AddCourse()
{
	if((CheckLevel()) == success)
	{
	int order = 0;
	int newID;
	string newName;


	CCourse* newCourse = new CCourse(); 
	while(order <= 2)
	{
		switch (order)
		{
		case 0:
			cout << "Please input the ID of the new course" << endl;
			cin >> newID;
			if(this->CourseList.find(newID) == this->CourseList.end())
			{
				newCourse->SetID(newID);
				order++;
			}
			else
			{
				cout << "The ID of course already exists" << endl;
			}
			break;
		case 1:
			cout << "Please input the name of the new course" << endl;
			cin >> newName;
			if(newName == " " || newName == "\n")
			{
				cout << "The name of course should be Chinese or English!" << endl;
			}
			else
			{
				newCourse->SetName(newName);
				order++;
			}
			break;
		case 2:
			cout << "Successfully add the course to the list!" << endl;
			order++;
			this->CourseList.insert(make_pair(newID, (*newCourse)));
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

void CCourseList::UpdateCourse()
{
	if((CheckLevel()) == success)
	{
	int theID;
	cout << "Please input the ID of the course" << endl;
	cin >> theID;
	if(this->CourseList.find(theID) == this->CourseList.end())
	{
		cout << "The student isn't in the student list. Please check the ID." << endl;
		return;
	}
	else
	{
		int order;
		string newName;

		cout << "Please input the new name of the course" << endl;
		cin >> newName;
		if(newName == " " || newName == "\n")
		{
			cout << "The name of course should be Chinese or English!" << endl;	
		}
		else
		{
			this->CourseList[theID].SetName(newName);
		}
		
	}
	}

	else
	{

	}
}

void CCourseList::DeleteCourse()
{
	if((CheckLevel()) == success)
	{
	int theID;
	cout << "Please input the ID of the course" << endl;
	cin >> theID;
	if(this->CourseList.find(theID) == this->CourseList.end())
	{
		cout << "The course isn't in the course list. Please check the ID." << endl;
		return;
	}
	else
	{
		
		this->CourseList.erase(theID);
		cout << "The course has been successfully deleted!" << endl;
		return;
	}
	}

	else
	{

	}
}

void CCourseList::ShowCourse(const int& theID)
{
	if((CheckLevel()) == success)
	{
	int theID;
	cout << "Please input the ID of the course" << endl;
	cin >> theID;
	if(this->CourseList.find(theID) == this->CourseList.end())
	{
		cout << "The course isn't in the course list. Please check the ID." << endl;
		return;
	}
	else
	{
		map<int, int>::iterator it;

		CCourse & theCourse = this->CourseList[theID];
		cout << "CourseID: " << theCourse.getID() << endl;
		cout << "Name: " << theCourse.getName() << endl;
		cout << "GradeList----------- " << endl;
		cout << "StuID" << "Mark" << endl;
		for(it = theCourse.gradeList.begin(); it != theCourse.gradeList.end(); it++)
		{
			cout << it->first << " " << it->second << endl;
		}

		return;
	}
	}

	else
	{

	}
}

CCourseList::~CCourseList(void)
{
}
