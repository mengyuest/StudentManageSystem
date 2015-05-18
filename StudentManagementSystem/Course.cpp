#include "Course.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

CCourse::CCourse(void)
{
}

void CCourse::SetLevel(Level& theLevel)
{
	level = theLevel;
}

Feedback CCourse::CheckLevel()
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

Feedback CCourse::CheckLevelNoWarning()
{
	if(level != Admin)
	{
		return invalid;
	}
	else
	{
		return success;
	}
}


void CCourse::SetUserID(int& theUserID)
{
	userid = theUserID;
}

void CCourse::SetID(int& theID)
{
	if((CheckLevel()) == success)
		id = theID;
}

void CCourse::SetName(string& theName)
{
	if((CheckLevel()) == success)
		name = theName;
}

const int CCourse::getID()
{
	return id;
}
const string CCourse::getName()
{
	return name;
}

int CCourse::AskGrade(int theId)
{
	if((CheckLevelNoWarning()) == success)
	{
		if(gradeList.find(theId) != gradeList.end())
			return gradeList[theId];
		else
		{
			cout << "No student in this id took the course."<< endl;
			return -1;
		}
	}

	else
	{
		if(userid == theId)
		{
			if(gradeList.find(theId) != gradeList.end())
				return gradeList[theId];
			else
			{
				cout << "No student in this id took the course."<< endl;
				return -1;
			}
		}

		else
			return -2;
	}
}

void CCourse::AddGrade(int theID, int theScore)
{
	if((CheckLevel()) == success)
	{
		if(gradeList.find(theID)!=gradeList.end())
		{
			if(theScore >= 0 && theScore <= 100)
			{
				gradeList.insert(theID,theScore);
				cout << "successfully add the record of the grade of " << theID << endl;
				return;
			}
			else
			{
				cout << "the score is out of range[0,100]. Please check!" << endl;
			}
		}

		else
		{
			cout << "this student has already took the course" << endl;
			return;
		}
	}

	else
	{
		return;
	}

}

void CCourse::DeleteGrade(int theID)
{
	if((CheckLevel()) == success)
	{
		if(gradeList.find(theID) == gradeList.end())
		{
			cout << "this student didn't choose the course" << endl;
			return;
		}

		else
		{
			gradeList.erase(theID);
			cout << "clear the certain record of the grade with ID: " << theID << endl;
			return;
		}
	}

	else
	{
		return;
	}

}

void CCourse::UpdateGrade(int theID, int theScore)
{
	if((CheckLevel()) == success)
	{
		if(gradeList.find(theID) == gradeList.end())
		{
			cout << "this student didn't choose the course" << endl;
			return;
		}

		else
		{
			if(theScore >= 0 && theScore <= 100)
			{
				gradeList[theID] = theScore;
				cout << "successfully update the record of the grade of " << theID << endl;
				return;
			}
			else
			{
				cout << "the score is out of range[0,100]. Please check!" << endl;
				return;
			}
		}
	}

	else
	{
		return;
	}
}

CCourse::~CCourse(void)
{
}
