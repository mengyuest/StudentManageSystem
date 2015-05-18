#pragma once

enum Gender
{
	male,
	female
};

enum Feedback
{
	success,
	invalid,
	error
};

enum Level
{
	Admin,
	Student
};

class CStudent
{
private:

	static Level level;

	string name;
	int id;
	Gender gender;
	int age;
	string nation;

	vector<string> selectedCourse; 

public:

	CStudent(void);

	void SetLevel(Level& theLevel);
	Feedback CheckLevel();

	void SetName(string& theName);
	void SetID(int& theID);
	void SetGender(Gender theGender);
	void SetAge(int& theAge);
	void SetNation(string& theNation);

	const string getName();
	const int getID();
	const Gender getGender();
	const int getAge();
	const string getNation();

	void SelectNewCourse(string courseName);
	void DeleteCourse(string courseName);
	void ShowSelectedCourse();
	void ShowInformation();

	~CStudent(void);
};

