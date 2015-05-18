#pragma once
class CLogin
{
private:
	int userid;
	string keyword;
public:

	CLogin(void);
	
	void SetUserID(int& theID);
	void SetKeyword(string& theKey);

	Level AnalysisLevel();

	~CLogin(void);
};

