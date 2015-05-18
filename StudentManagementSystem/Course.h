#pragma once
class CCourse
{
private:
	static Level level;
	static int userid;
	int id;
	string name;
	

public:

	CCourse(void);

	map<int, int> gradeList;
	void SetLevel(Level& theLevel);
	Feedback CheckLevel();
	Feedback CheckLevelNoWarning();

	void SetUserID(int& theUserID);

	void SetID(int& theID);
	void SetName(string& theName);

	const int getID();
	const string getName();

	int AskGrade(int theId);

	void AddGrade(int theID, int theScore);
	void DeleteGrade(int theID);
	void UpdateGrade(int theID, int theScore);

	~CCourse(void);
};

