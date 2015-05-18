#pragma once
class CStudentList
{
private:
	Level level;
	map<int, CStudent& > StudentList;

public:
	
	CStudentList(void);

	void SetLevel(Level& theLevel);
	Feedback CheckLevel();
	
	void AddStudent();
	void UpdateStudent();
	void DeleteStudent();
	void ShowStudent(const int& theID);
	
	~CStudentList(void);
};

