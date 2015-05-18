#include "Login.h"
#include <string>
#include "Student.h"
using namespace std;

CLogin::CLogin(void)
{
	userid = 2013011;
	keyword = "keyword";
}
void CLogin::SetUserID(int& theID)
{
	userid = theID;
}

void CLogin::SetKeyword(string& theKey)
{
	keyword = theKey;
}

Level CLogin::AnalysisLevel()
{
	if(userid == 888888 && keyword == "sixeight")
	{
		return Level(Admin);
	}

	else
	{
		return Level(Student);
	}
}

CLogin::~CLogin(void)
{
}
