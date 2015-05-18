#pragma once
class CCourseList
{
private:
	Level level;
	map<int, CCourse > CourseList;

public:
	
	CCourseList(void);

	void SetLevel(Level& theLevel);
	Feedback CheckLevel();
	
	void AddCourse();
	void UpdateCourse();
	void DeleteCourse();
	void ShowCourse(const int& theID);
	
	~CCourseList(void);
};

