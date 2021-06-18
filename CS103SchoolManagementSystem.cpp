//School Information System 
//Group Project - Name: JANIV
//Group Members - Liv & Janelle


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//Janelle's code start
struct Account {
	string username;
	string password;

	//constructor
	Account(string u = "", string p = "") {
		username = u;
		password = p;
	}
};

struct Parent {
	string firstName;
	string lastName;
	string gender;
	string email;
	int contactNum;
	string childName;
	int studentID;
	Account accountDetails;
};

struct Student {
	int id;
	string firstName;
	string lastName;
	int classNum;
	int yearGroup;
	Parent parentDetails;
	Account accountDetails;
	string grade;

	//Constructor
	Student(int i = 100, string fn = "", string ln = "", int y = 0, int c = 0) {
		id = i;
		firstName = fn;
		lastName = ln;
		yearGroup = y;
		classNum = c;
	}
};

struct Admin {
	string firstName;
	string lastName;
	string email;
	Account accountDetails;
};
//Janelle's code end

//Olivia's code start
struct Teacher {
	string firstName;
	string lastName;
	string gender;
	string email;
	int contactNum;
	int classNum;
	int yearTeaching;
	Account accountDetails;
};


struct Classroom {
	string student;
	string student1;
	string student2;
};
//Olivia's code end

//PROTOTYPES
vector<Teacher> storingTeacherCSV(vector<Teacher> teacherVtr, vector<string> teacherData);
vector<Admin> storingAdminCSV(vector<Admin> adminVtr, vector<string> adminData);
vector<Student> storingStudentCSV(vector<Student> studentsVtr, vector<string> emptyData);
vector<Parent> storingParentCSV(vector<Parent> parentVtr, vector<string> parentData);
vector<Teacher> readingTeacherCSV(vector<Teacher> teacherVtr, vector<string> teacherData);
vector<Admin> readingAdminCSV(vector<Admin> adminVtr, vector<string> adminData);
vector<Student> readingStudentCSV(vector<Student> studentsVtr, vector<string> studentDataVtr);
vector<Parent> readingAdminCSV(vector<Parent> parentVtr, vector<string> parentData);

void starLine(int numOfStars);
void schoolTitle();
void introScreen();
void addingStudentCSV(struct Student* studentPtr, vector<Student> studentsVtr, vector<string> studentDataVtr);
void displayRecords(struct Student* studentPtr, vector<Student> studentsVtr, int classRecordChoice);
void displayReport(struct Student* studentPtr, vector<Student> studentsVtr, int displayRprtChoice);
vector<Student> updatingStudentCSV(vector<Student> studentsVtr, vector<string> emptyDataVtr);
void teachClassRecord(struct Teacher* teacherPtr, vector<Teacher> teacherVtr, vector<string> teacherEmpData, struct Student* studentPtr,
	vector<Student> studentsVtr, vector<string> emptyDataVtr);
void teachActions(struct Teacher* teacherPtr, vector<Teacher> teacherVtr, vector<string> teacherEmpData, struct Student* studentPtr,
	vector<Student> studentsVtr, vector<string> emptyDataVtr);
void adminActions(struct Teacher* teacherPtr, struct Admin* adminPtr, struct Student* studentPtr, struct Parent* parentPtr,
	vector<Teacher> teacherVtr, vector<Admin> adminVtr, vector<Student> studentsVtr, vector<Parent> parentVtr,
	vector<string> teacherData, vector<string> adminData, vector<string> studentDataVtr, vector<string> parentData);
void studentParentReportScreen(struct Student* studentPtr, struct Parent* parentPtr, vector<Student> studentsVtr, vector<Parent> parentVtr, int signupOption);
void studentParentNotices(struct Student* studentPtr, struct Parent* parentPtr, vector<Student> studentsVtr, vector<Parent> parentVtr, int signupOption);
void studentParentActions(struct Student* studentPtr, struct Parent* parentPtr, vector<Student> studentsVtr, vector<Parent> parentVtr, int signupOption);
void writingToCSV(struct Teacher* teacherPtr, struct Admin* adminPtr, struct Student* studentPtr, struct Parent* parentPtr,
	vector<Teacher> teacherVtr, vector<Admin> adminVtr, vector<Student> studentsVtr, vector<Parent> parentVtr,
	vector<string> teacherData, vector<string> adminData, vector<string> studentDataVtr, vector<string> parentData, int signupOption);
void login(struct Teacher* teacherPtr, struct Admin* adminPtr, struct Student* studentPtr, struct Parent* parentPtr,
	vector<Teacher> teacherVtr, vector<Admin> adminVtr, vector<Student> studentsVtr, vector<Parent> parentVtr,
	vector<string> teacherData, vector<string> adminData, vector<string> studentDataVtr, vector<string> parentData);


int main()
{
	struct Student s;
	struct Student* studentPtr = &s;
	struct Admin a;
	struct Admin* adminPtr = &a;
	//Olivia's code start
	struct Teacher t;
	struct Teacher* teacherPtr = &t;
	struct Parent p;
	struct Parent* parentPtr = &p;
	//Olivia's code end

	vector<Student> studentsVtr;
	vector<string> studentDataVtr;
	vector<Admin> adminVtr;
	vector<string> adminData;
	vector<Teacher> teacherVtr;
	vector<string> teacherData;
	vector<Parent> parentVtr;
	vector<string> parentData;

	int menuOption, signupOption;
	bool validInput = false;

	schoolTitle();//calling the school name
	introScreen();

	cout << "1. Sign Up\n2. Login\n3. End" << endl;
	cout << "Enter number for chosen option : ";
	cin >> menuOption;

	while (validInput == false) {
		switch (menuOption) {
		case 1:
			cout << "\nSign Up as" << endl;
			starLine(20);
			cout << "1. Teacher\n2. Admin\n3. Student\n4. Parent" << endl;
			cout << "Enter number for chosen option : ";
			cin >> signupOption;
			if (signupOption > 4) {
				cout << "Error : Invalid input" << endl;
			}
			else {
				validInput = true;
				writingToCSV(teacherPtr, adminPtr, studentPtr, parentPtr, teacherVtr, adminVtr, studentsVtr, parentVtr, teacherData, adminData, studentDataVtr, parentData, signupOption);				break;
			}
		case 2:
			cout << "\nLogin" << endl;
			starLine(20);
			login(teacherPtr, adminPtr, studentPtr, parentPtr, teacherVtr, adminVtr, studentsVtr, parentVtr, teacherData, adminData, studentDataVtr, parentData);
			break;
		case 3:
			//Terminate program
			//updatingStudentCSV( studentsVtr, studentDataVtr);
			//storingStudentCSV(studentsVtr, studentDataVtr);
			//cout << studentsVtr.size();
			cout << "Program Terminated" << endl;
			return 0;
		}
	}
}

//Janelle's code start
//storing inputted teacher details into vector
vector<Teacher> storingTeacherCSV(vector<Teacher> teacherVtr, vector<string> teacherData) {
	Teacher tv;

	tv.firstName = teacherData[0];
	tv.lastName = teacherData[1];
	tv.gender = teacherData[2];
	tv.email = teacherData[3];
	tv.contactNum = stoi(teacherData[4]);
	tv.classNum = stoi(teacherData[5]);
	tv.yearTeaching = stoi(teacherData[6]);
	tv.accountDetails.username = teacherData[7];
	tv.accountDetails.password = teacherData[8];

	teacherVtr.push_back(tv);

	return teacherVtr;
}

//storing inputted admin details into vector
vector<Admin> storingAdminCSV(vector<Admin> adminVtr, vector<string> adminData) {
	Admin av;

	av.firstName = adminData[0];
	av.lastName = adminData[1];
	av.email = adminData[2];
	av.accountDetails.username = adminData[3];
	av.accountDetails.password = adminData[4];

	adminVtr.push_back(av);

	//cout << adminData[0];
	//cout << adminData[1];
	//cout << adminData[2];
	//cout << adminData[3];
	//cout << adminData[4];

	//adminVtr.erase(adminVtr.begin() + 4);
	//cout << adminData[0];
	//cout << adminData[1];
	//cout << adminData[2];
	//cout << adminData[3];
	//cout << adminData[4];

	return adminVtr;
}

//storing inputted student details into vector
vector<Student> storingStudentCSV(vector<Student> studentsVtr, vector<string> studentDataVtr) {
	Student sv;

	sv.id = stoi(studentDataVtr[0]);//error
	sv.firstName = studentDataVtr[1];
	sv.lastName = studentDataVtr[2];
	sv.yearGroup = stoi(studentDataVtr[3]);
	sv.classNum = stoi(studentDataVtr[4]);
	sv.parentDetails.firstName = studentDataVtr[5];
	sv.parentDetails.lastName = studentDataVtr[6];
	sv.parentDetails.email = studentDataVtr[7];
	sv.parentDetails.gender = studentDataVtr[8];
	sv.accountDetails.username = studentDataVtr[9];
	sv.accountDetails.password = studentDataVtr[10];

	studentsVtr.push_back(sv);
	//cout << "\ni am in the storingStudentCSV vector function" << endl;
	return studentsVtr;
}

//storing inputted teacher details into vector
vector<Parent> storingParentCSV(vector<Parent> parentVtr, vector<string> parentData) {
	Parent pv;

	pv.firstName = parentData[0];
	pv.lastName = parentData[1];
	pv.gender = parentData[2];
	pv.email = parentData[3];
	pv.contactNum = stoi(parentData[4]);
	pv.childName = parentData[5];
	pv.studentID = stoi(parentData[6]);
	pv.accountDetails.username = parentData[7];
	pv.accountDetails.password = parentData[8];

	parentVtr.push_back(pv);

	return parentVtr;
}

vector<Teacher> readingTeacherCSV(vector<Teacher> teacherVtr, vector<string> teacherData) {
	ifstream readingTeacher;
	string line, currentStr;

	readingTeacher.open("teachers.csv", ios::in);
	while (getline(readingTeacher, line)) {
		stringstream linestream(line);

		while (!linestream.eof()) {
			getline(linestream, currentStr, ',');
			teacherData.push_back(currentStr);
		}
		teacherVtr = storingTeacherCSV(teacherVtr, teacherData);//storing into vector
		teacherData.clear();
	}

	readingTeacher.close();
	return teacherVtr;
}

vector<Admin> readingAdminCSV(vector<Admin> adminVtr, vector<string> adminData) {
	ifstream readingAdmin;
	string line, currentStr;

	readingAdmin.open("admins.csv", ios::in);
	while (getline(readingAdmin, line)) {
		stringstream linestream(line);

		while (!linestream.eof()) {
			getline(linestream, currentStr, ',');
			adminData.push_back(currentStr);
		}
		adminVtr = storingAdminCSV(adminVtr, adminData);//storing into vector
		adminData.clear();
	}

	readingAdmin.close();
	return adminVtr;
}

vector<Student> readingStudentCSV(vector<Student> studentsVtr, vector<string> studentDataVtr) {
	ifstream readingStudentsC1;
	string line, currentStr;

	//cout << "\ni am in readingStudentCSV vector function" << endl;

	readingStudentsC1.open("class1.csv", ios::in);
	while (getline(readingStudentsC1, line)) {
		stringstream linestream(line);

		while (!linestream.eof()) {
			getline(linestream, currentStr, ',');
			studentDataVtr.push_back(currentStr);
		}
		studentsVtr = storingStudentCSV(studentsVtr, studentDataVtr);//storing into vector
		studentDataVtr.clear();
		//cout << "\ni am going through class1 file" << endl;
	}
	readingStudentsC1.close();

	ifstream readingStudentsC2;
	string line2, currentStr2;

	readingStudentsC2.open("class2.csv", ios::in);
	while (getline(readingStudentsC2, line2)) {
		stringstream linestream(line2);

		while (!linestream.eof()) {
			getline(linestream, currentStr2, ',');
			studentDataVtr.push_back(currentStr2);
		}
		studentsVtr = storingStudentCSV(studentsVtr, studentDataVtr);//storing into vector
		studentDataVtr.clear();
		//cout << "\ni am going through class2 file" << endl;
	}
	readingStudentsC2.close();

	return studentsVtr;
}

vector<Parent> readingParentCSV(vector<Parent> parentVtr, vector<string> parentData) {
	ifstream readingParent;
	string line, currentStr;

	readingParent.open("parents.csv", ios::in);
	while (getline(readingParent, line)) {
		stringstream linestream(line);

		while (!linestream.eof()) {
			getline(linestream, currentStr, ',');
			parentData.push_back(currentStr);
		}
		parentVtr = storingParentCSV(parentVtr, parentData);//storing into vector
		parentData.clear();
	}

	readingParent.close();
	return parentVtr;
}
//Janelle's code end

//Olivia's code start
void starLine(int numOfStars) { // Output for Star Lines
	int i;
	for (i = 0; i < numOfStars; i++) {
		cout << "*";
	}
	cout << endl;
}

void schoolTitle() {
	//system("CLS");// clears console
	cout << "\n\t\t\tEVABEE SCHOOL" << endl;//Title output
	starLine(66);
}

void introScreen() {
	//Contact Output
	cout << "<-Contact->" << endl;
	cout << "Phone: 08-947-3759" << endl;
	cout << "Email: Evabee.school@gmail.co.nz" << endl;
	cout << "Address: 678 Lansley Road, 8908, Wellington" << endl;
	starLine(66);
	//Events Output
	cout << "<-Upcoming Events->" << endl;
	cout << "1/06/2021: Pride Month(SchoolLunch)" << endl;
	cout << "10/06/2021: Sports Day" << endl;
	cout << "15/06/2021: Sports Day Prize Giving" << endl;
	cout << "22/06/2021: Big Assembly" << endl;
	starLine(66);
	//Term Output
	cout << "<-Term Dates->" << endl;
	cout << "1/02/2021: Start Of Term 1" << endl;
	cout << "1/05/2021: Start Of Term 2" << endl;
	cout << "1/08/2021: Start Of Term 3" << endl;
	cout << "1/10/2021: Start Of Term 4" << endl;
	starLine(66);
}
//Olivia's code end

//Janelle's code start
void addingStudentCSV(struct Student* studentPtr, vector<Student> studentsVtr, vector<string> studentDataVtr) {
	//int id = 100;
	cout << "\nEnter student details" << endl;
	cout << "First name : ";
	cin >> studentPtr->firstName;
	cout << "Last name : ";
	cin >> studentPtr->lastName;
	cout << "Year group : ";
	cin >> studentPtr->yearGroup;
	cout << "Class Number : ";
	cin >> studentPtr->classNum;
	cout << "Parent/guardian first name : ";
	cin >> studentPtr->parentDetails.firstName;
	cout << "Parent/guardian last name : ";
	cin >> studentPtr->parentDetails.lastName;
	cout << "Parent/guardian email : ";
	cin >> studentPtr->parentDetails.email;
	cout << "Parent/guardian gender : ";
	cin >> studentPtr->parentDetails.gender;
	cout << "Username : ";
	cin >> studentPtr->accountDetails.username;
	cout << "Password : ";
	cin >> studentPtr->accountDetails.password;
	studentPtr->id++;

	if (studentPtr->classNum == 1) {
		ofstream class1File;
		//opening csv file
		class1File.open("class1.csv", ios::app);
		class1File << studentPtr->id << "," << studentPtr->firstName << "," << studentPtr->lastName << "," << studentPtr->yearGroup << ","
			<< studentPtr->classNum << "," << studentPtr->parentDetails.firstName << "," << studentPtr->parentDetails.lastName << ","
			<< studentPtr->parentDetails.email << "," << studentPtr->parentDetails.gender << "," << studentPtr->accountDetails.username
			<< "," << studentPtr->accountDetails.password << endl;//writing to csv file

		class1File.close();
	}
	else if (studentPtr->classNum == 2) {
		ofstream class2File;
		//opening csv file
		class2File.open("class2.csv", ios::app);
		class2File << studentPtr->id << "," << studentPtr->firstName << "," << studentPtr->lastName << "," << studentPtr->yearGroup << ","
			<< studentPtr->classNum << "," << studentPtr->parentDetails.firstName << "," << studentPtr->parentDetails.lastName << ","
			<< studentPtr->parentDetails.email << "," << studentPtr->parentDetails.gender << "," << studentPtr->accountDetails.username
			<< "," << studentPtr->accountDetails.password << endl;//writing to csv file

		class2File.close();
	}
	readingStudentCSV(studentsVtr, studentDataVtr);
}
//Janelle's code end

//display student records
//
//vector function name() {
//	get all student details in csv
//vector<student> vectStudent
//	return vector
//}



void displayRecords(struct Student* studentPtr, vector<Student> studentsVtr, int classRecordChoice) {
	int i;

	//displays the old name of the student and makes vector size 2;
	cout << "i am in the displayRecords function and studentsVtr.size() " << studentsVtr.size() << endl;
	for (i = 0; i < studentsVtr.size(); i++) { //goes through student vector and will only print the student record if classNum = 1
		if (studentsVtr[i].classNum == classRecordChoice) {
			cout << "\nID : " << studentsVtr[i].id << "\nFull Name : " << studentsVtr[i].firstName << " " << studentsVtr[i].lastName
				<< "\nYear Group : " << studentsVtr[i].yearGroup << "\nClass Number : " << studentsVtr[i].classNum
				<< "\nParent/Guardian Full Name : " << studentsVtr[i].parentDetails.firstName << " " << studentsVtr[i].parentDetails.lastName
				<< "\nParent/Guardian Email : " << studentsVtr[i].parentDetails.email << "\nParent/Guadian Gender : " << studentsVtr[i].parentDetails.gender
				<< "\nUsername : " << studentsVtr[i].accountDetails.username << "\nPassword : " << studentsVtr[i].accountDetails.password << endl;
		}
	}
}

void displayReport(struct Student* studentPtr, vector<Student> studentsVtr, int displayRprtChoice) {
	int i;

	for (i = 0; i < studentsVtr.size(); i++) {
		starLine(20);
		if (studentsVtr[i].classNum == displayRprtChoice) {
			cout << "\nID : " << studentsVtr[i].id << "\nFull Name : " << studentsVtr[i].firstName << " " << studentsVtr[i].lastName
				<< "\nYear Group : " << studentsVtr[i].yearGroup << "\nClass Number : " << studentsVtr[i].classNum << endl;
		}
	}
}

//Janelle's code start
vector<Student> updatingStudentCSV(vector<Student> studentsVtr, vector<string> studentDataVtr) {
	string firstName, lastName, guardianFirstName, guardianLastName, guardianEmail, guardianGender, username, password, newFirstName, newLastName, newGuardianFirstName, newGuardianLastName, newGuardianEmail, newGuardianGender, newUsername, newPassword;
	char choice;
	bool found = false;
	int id, editChoice, yearGroup, classNumber, newYearGroup, newClassNumber, i, k;

	schoolTitle();

	studentsVtr = readingStudentCSV(studentsVtr, studentDataVtr);
	//cout << "studentsVtr.size() = " << studentsVtr.size() << endl;

	cout << "\nEnter id of student record you would like to edit : ";
	cin >> id;

	for (i = 0; i < studentsVtr.size(); i++) {
		if (studentsVtr[i].id == id) {
			found = true;
			cout << "\nStudent record found : " << studentsVtr[i].firstName << " " << studentsVtr[i].lastName << endl;
			cout << "\nWhat would you like to edit?\n1. First name\n2. Last name\n3. Year group\n4. Class Number\n5. Parent/guardian first name\n6. Parent/guardian last name\n7. Parent/guardian email\n8. Parent/guardian gender\n9. Username\n10. Password" << endl;
			cout << "Enter number for chosen option : ";
			cin >> editChoice;
			schoolTitle();
			if (editChoice == 1) {
				//enter new first name for found student
				cout << "\nEnter new first name for " << studentsVtr[i].firstName << " " << studentsVtr[i].lastName << "(ID " << studentsVtr[i].id << ") : ";
				cin >> newFirstName;
				studentsVtr[i].firstName = newFirstName;
			}
			else if (editChoice == 2) {
				//enter new last name for found student
				cout << "\nEnter updated last name for " << studentsVtr[i].firstName << " " << studentsVtr[i].lastName << "(ID " << studentsVtr[i].id << ") : ";
				cin >> newLastName;
				studentsVtr[i].lastName = newLastName;
			}
			else if (editChoice == 3) {
				//enter new year group for found student
				cout << "\nEnter updated year group for " << studentsVtr[i].firstName << " " << studentsVtr[i].lastName << "(ID " << studentsVtr[i].id << ") : ";
				cin >> newYearGroup;
				studentsVtr[i].yearGroup = newYearGroup;
			}
			else if (editChoice == 4) {
				//enter new class for found student
				cout << "\nEnter updated class number group for " << studentsVtr[i].firstName << " " << studentsVtr[i].lastName << "(ID " << studentsVtr[i].id << ") : ";
				cin >> newClassNumber;
				studentsVtr[i].classNum = newClassNumber;
			}
			else if (editChoice == 5) {
				//enter new parent first name for found student
				cout << "\nEnter updated parent/guardian first name for " << studentsVtr[i].firstName << " " << studentsVtr[i].lastName << "(ID " << studentsVtr[i].id << ") : ";
				cin >> newGuardianFirstName;
				studentsVtr[i].parentDetails.firstName = newGuardianFirstName;
			}
			else if (editChoice == 6) {
				//enter new parent last name for found student
				cout << "\nEnter updated parent/guardian last name for " << studentsVtr[i].firstName << " " << studentsVtr[i].lastName << "(ID " << studentsVtr[i].id << ") : ";
				cin >> newGuardianLastName;
				studentsVtr[i].parentDetails.lastName = newGuardianLastName;
			}
			else if (editChoice == 7) {
				//enter new parent email for found student
				cout << "\nEnter updated parent/guardian email for " << studentsVtr[i].firstName << " " << studentsVtr[i].lastName << "(ID " << studentsVtr[i].id << ") : ";
				cin >> newGuardianEmail;
				studentsVtr[i].parentDetails.email = newGuardianEmail;
			}
			else if (editChoice == 8) {
				//enter new parent gender for found student
				cout << "\nEnter updated parent/guardian email for " << studentsVtr[i].firstName << " " << studentsVtr[i].lastName << "(ID " << studentsVtr[i].id << ") : ";
				cin >> newGuardianGender;
				studentsVtr[i].parentDetails.gender = newGuardianGender;
			}
			else if (editChoice == 9) {
				//enter new username for found student
				cout << "\nEnter updated username for " << studentsVtr[i].firstName << " " << studentsVtr[i].lastName << "(ID " << studentsVtr[i].id << ") : ";
				cin >> newUsername;
				studentsVtr[i].accountDetails.username = newUsername;
			}
			else if (editChoice == 10) {
				//enter new password for found student
				cout << "\nEnter updated password for " << studentsVtr[i].firstName << " " << studentsVtr[i].lastName << "(ID " << studentsVtr[i].id << ") : ";
				cin >> newPassword;
				studentsVtr[i].accountDetails.password = newPassword;
			}
			else {
				cout << "\nInvalid input : Please enter a number from 1 to 10" << endl;
			}
			break;
		}
		else {
			found = false;
		}
	}
	//studentDataVtr.clear();

	if (!found) {
		cout << "no students found" << endl;
	}
	else if (found == true) {
		//updating students csv to account for changes made
		cout << "Student record succesfully updated" << endl;
		for (k = 0; k < studentsVtr.size(); k++) {
			/*if (studentsVtr[k].classNum == 1) {
				ofstream updateCSVClass1("class1.csv", ios::out);
				updateCSVClass1 << studentsVtr[i].id << "," << studentsVtr[i].firstName << "," << studentsVtr[i].lastName << "," << studentsVtr[i].yearGroup
					<< "," << studentsVtr[i].classNum << "," << studentsVtr[i].parentDetails.firstName << "," << studentsVtr[i].parentDetails.lastName
					<< "," << studentsVtr[i].parentDetails.email << "," << studentsVtr[i].parentDetails.gender << "," << studentsVtr[i].accountDetails.username
					<< "," << studentsVtr[i].accountDetails.password << endl;
				updateCSVClass1.close();
			}
			else if (studentsVtr[k].classNum == 2) {
				ofstream updateCSVClass2("class2.csv", ios::out);
				updateCSVClass2 << studentsVtr[i].id << "," << studentsVtr[i].firstName << "," << studentsVtr[i].lastName << "," << studentsVtr[i].yearGroup
					<< "," << studentsVtr[i].classNum << "," << studentsVtr[i].parentDetails.firstName << "," << studentsVtr[i].parentDetails.lastName
					<< "," << studentsVtr[i].parentDetails.email << "," << studentsVtr[i].parentDetails.gender << "," << studentsVtr[i].accountDetails.username
					<< "," << studentsVtr[i].accountDetails.password << endl;
				updateCSVClass2.close();
			}*/
			if (studentsVtr[k].classNum == 1) {
				ofstream class1File;
				//opening csv file
				class1File.open("class1.csv", ios::app);
				class1File << studentsVtr[i].id << "," << studentsVtr[i].firstName << "," << studentsVtr[i].lastName << "," << studentsVtr[i].yearGroup << ","
					<< studentsVtr[i].classNum << "," << studentsVtr[i].parentDetails.firstName << "," << studentsVtr[i].parentDetails.lastName << ","
					<< studentsVtr[i].parentDetails.email << "," << studentsVtr[i].parentDetails.gender << "," << studentsVtr[i].accountDetails.username
					<< "," << studentsVtr[i].accountDetails.password << endl;//writing to csv file

				class1File.close();
				//studentsVtr.clear();
			}
			else if (studentsVtr[k].classNum == 2) {
				ofstream class2File;
				//opening csv file
				class2File.open("class2.csv", ios::app);
				class2File << studentsVtr[i].id << "," << studentsVtr[i].firstName << "," << studentsVtr[i].lastName << "," << studentsVtr[i].yearGroup << ","
					<< studentsVtr[i].classNum << "," << studentsVtr[i].parentDetails.firstName << "," << studentsVtr[i].parentDetails.lastName << ","
					<< studentsVtr[i].parentDetails.email << "," << studentsVtr[i].parentDetails.gender << "," << studentsVtr[i].accountDetails.username
					<< "," << studentsVtr[i].accountDetails.password << endl;//writing to csv file

				class2File.close();
			}
			//readingStudentCSV(studentsVtr, studentDataVtr);

		}
	}
	//readingStudentCSV(studentsVtr, studentDataVtr);
	//cout << "Updated student file\n" << endl;
	//cout << "\nstudentsVtr.size() = " << studentsVtr.size() << endl;
	//for (int m = 0; m < studentsVtr.size(); m++) {
	//	cout << "Updated student details" << endl;
	//	cout << studentsVtr[m].id << "," << studentsVtr[m].firstName << "," << studentsVtr[m].lastName << "," << studentsVtr[m].yearGroup
	//		<< "," << studentsVtr[m].classNum << "," << studentsVtr[m].parentDetails.firstName << "," << studentsVtr[m].parentDetails.lastName
	//		<< "," << studentsVtr[m].parentDetails.email << "," << studentsVtr[m].parentDetails.gender << "," << studentsVtr[m].accountDetails.username
	//		<< "," << studentsVtr[m].accountDetails.password << endl;
	//}
	return studentsVtr;
}
//Janelle's code end

//Livs Code Start
void teachClassRecord(struct Teacher* teacherPtr, vector<Teacher> teacherVtr, vector<string> teacherEmpData, struct Student* studentPtr,
	vector<Student> studentsVtr, vector<string> emptyDataVtr) {
	schoolTitle();

	cout << "\n\t\t\t<-Signed In As Teacher->" <<  endl;//Teacher Name output
	cout << "\n\t\t\tClassRoom 1 Records" << endl;
	cout << "\n3. Student 1(students Name)" << endl;
	cout << "\n4. Student 2(students Name)" << endl;
	cout << "\n5. Student 3(students Name)" << endl;

	cout << "\n\n2. Main Menu" << endl;
	cout << "\n4. Exit" << endl;

}
//Livs Code End

//Livs Code Start
//Teacher options output (to access the chosen choice, e.g student 1, main menu or to exit the program.
void teachActions(struct Teacher* teacherPtr, vector<Teacher> teacherVtr,vector<string> teacherEmpData, struct Student* studentPtr,
	vector<Student> studentsVtr,vector<string> emptyDataVtr ) {

	int teacherChoice = 0, recordChoice, studRecChoice, classRecordChoice, displayRprtChoice;
	starLine(66);
	cout << "\nEnter Number For Chosen Option" << endl;
	cin >> teacherChoice;

	switch (teacherChoice) {
	case 3: //Accessing Student 1
		cout << "\naccessing student 1" << endl;
		break;
	case 4: //Accessing Student 2
		cout << "\naccessing student 2" << endl;
		break;
	case 5: //Accessing Student 3
		cout << "\naccessing student 3" << endl;
		break;
	case 2: // Accessing Back to Main menu
		cout << "\naccessing Back to Main menu" << endl;
		break;
	case 6: //Accessing the Exit
		cout << "\nExitting" << endl;
		break;

	}

}
//Livs Code End

//Janelle's code start
void adminActions(struct Teacher* teacherPtr, struct Admin* adminPtr, struct Student* studentPtr, struct Parent* parentPtr,
	vector<Teacher> teacherVtr, vector<Admin> adminVtr, vector<Student> studentsVtr, vector<Parent> parentVtr,
	vector<string> teacherData, vector<string> adminData, vector<string> studentDataVtr, vector<string> parentData) {

	int choice = 0, recordChoice, studRecChoice, rprtChoice, classRecordChoice, displayRprtChoice, editRprtChoice, i, j;
	schoolTitle();
	cout << "Signed in as admin" << endl;
	while (choice != 3) {
		cout << "\nAdmin actions" << endl;
		cout << "1. Access Records\n2. Access Reports\n3. Sign Out" << endl;
		cout << "\nEnter number for chosen option: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "\nRecords" << endl;
			cout << "1. Student Records\n2. Class Records" << endl;
			cout << "\n Enter number for chosen option : ";
			cin >> recordChoice;
			//Student Records start
			if (recordChoice == 1) {
				cout << "\nRecords" << endl;
				cout << "1. Add new student\n2. Edit student record\n3. Delete student record" << endl;
				cout << "\nEnter number for chosen option : ";
				cin >> studRecChoice;
				if (studRecChoice == 1) {
					cout << "\n\t\t\t<-New Student Record->" << endl;
					addingStudentCSV(studentPtr, studentsVtr, studentDataVtr);
				}
				else if (studRecChoice == 2) {
					cout << "\n\t\t\t<-Edit existing student record->" << endl;
					studentsVtr = updatingStudentCSV(studentsVtr, studentDataVtr);
				}
				else if (studRecChoice == 3) {
					//delete student record
				}
				else {
					cout << "Invalid Input : Please enter a number from 1 to 3" << endl;
				}
			}//Student Records end
			//Class Records start
			else {
				cout << "1. Display Class 1 records\n2. Display Class 2 records" << endl;
				cout << "\nEnter number for chosen option : ";
				cin >> classRecordChoice;
				//Print class records
				if (classRecordChoice == 1) {
					//Print class 1 records
					cout << "Class 1" << endl;
					displayRecords(studentPtr, studentsVtr, classRecordChoice);
				}
				else {
					//Print class 2 records
					cout << "Class 2" << endl;
					displayRecords(studentPtr, studentsVtr, classRecordChoice);
				}
			}//Class Records end
			break;
		case 2:
			cout << "\nReports" << endl;
			cout << "\n1. Display reports\n2. Edit reports" << endl;
			cout << "\nEnter number for chosen option : ";
			cin >> rprtChoice;
			if (rprtChoice == 1) { //display reports
				cout << "Which class reports would you like to view?";
				cout << "\n1. Class 1 reports\n2. Class 2 reports" << endl;
				cout << "\nEnter number for chosen option : ";
				cin >> displayRprtChoice;
				if (displayRprtChoice == 1) { //display class 1 reports
					cout << "Class 1" << endl;
					displayReport(studentPtr, studentsVtr, displayRprtChoice);
				}
				else if (displayRprtChoice == 2) { //display class 2 reports
					cout << "Class 2" << endl;
					displayReport(studentPtr, studentsVtr, displayRprtChoice);
				}
				else {
					cout << "\nInvalid Input : Please enter 1 or 2" << endl;
				}
			}
			else if (rprtChoice == 2) { //edit reports
				//cout << "\nEdit Student Report" << endl;
				// starLine(20);
				//cout << "\nEnter I.D. a student's number";
			}
			else {
				cout << "\nInvalid Input : Please enter 1 or 2" << endl;
			}
			break;
		case 3:
			cout << "\nYou have successfully signed out" << endl;
			return;
		}
	}
}
//Janelle's code end

//Livs Code
void studentParentReportScreen(struct Student* studentPtr, struct Parent* parentPtr, vector<Student> studentsVtr, vector<Parent> parentVtr, int signupOption) { /*Parents Report Screen is so the parent is able to see the current reports
									or notes on their child academically and behaviour wise */
	schoolTitle();
	//Title output
	cout << "\n\t\t\t<-Signed in as ";
	if (signupOption == 3) {
		cout << "student->";
	}
	else {
		cout << "parent->";
	}

	cout << "\nJacks Current Report"; //Will replace with the s->studentusername for the name
	cout << "\n<-2. View Exclusive School Notices->" << endl;
	cout << "\n<-3. Settings->" << endl;
}

//Livs Code
void studentParentNotices(struct Student* studentPtr, struct Parent* parentPtr, vector<Student> studentsVtr, vector<Parent> parentVtr, int signupOption) { /*this current codes main use is "parent* pn" but also pulling from parent account
											which is parent* a as hoping to connect with the parent account username??*/

	schoolTitle();
	//name output beside school name
	cout << "\t\t\t<-Signed in as ";
	if (signupOption == 3) {
		cout << "student->";
	}
	else {
		cout << "parent->";
	}
	cout << "\nSchool Notices: Monday" << endl;
	cout << "\n\n8.30am: Show And Tell" << endl;
	cout << "\nMake Sure Your Child Has Brought Something Awesome To Share! :)" << endl;
	cout << "\n12.30: School Lunch" << endl;
	cout << "\nShared Lunch! Bring Something Scrumtious! :P" << endl;
	cout << "\n1pm: Sports" << endl;
	starLine(66);
	cout << "\n\n\n<-1. View Your Childs Reports->" << endl;
	cout << "\n<-3. Settings->" << endl;
}

//Livs Code
//PARENT/STUDENT SCREEN
void studentParentActions(struct Student* studentPtr, struct Parent* parentPtr, vector<Student> studentsVtr, vector<Parent> parentVtr, int signupOption) { /*Parents Account, So Where she/he is able to find information about school or her child.*/
	schoolTitle();
	cout << "\n\t\t\t<-Signed in as ";
	if (signupOption == 3) {
		cout << "student->";
	}
	else {
		cout << "parent->";
	}

	cout << "\n\n\n<-1. View Your Childs Reports->" << endl;
	cout << "\n<-2.View Exclusive School Notices->" << endl;
	cout << "\n<-3. Settings->" << endl;//what is settings for?

	cout << "\n\t\t\t\t\t\t\t\t1.End" << endl;
	starLine(66);

}

//SIGNING UP INPUT DETAILS
void writingToCSV(struct Teacher* teacherPtr, struct Admin* adminPtr, struct Student* studentPtr, struct Parent* parentPtr,
	vector<Teacher> teacherVtr, vector<Admin> adminVtr, vector<Student> studentsVtr, vector<Parent> parentVtr,
	vector<string> teacherData, vector<string> adminData, vector<string> studentDataVtr, vector<string> parentData, int signupOption) {

	//livs code start & Teacher SignUp
	schoolTitle();//Olivia's code

	if (signupOption == 1) {
		cout << "\n\t\t\t<-Teacher Signup->" << endl;//Title output
		//Entering Signup information for output
		cout << "\nPlease Enter Your FirstName: ";
		cin >> teacherPtr->firstName;
		cout << "\nPlease Enter Your LastName: ";
		cin >> teacherPtr->lastName;
		cout << "\nPlease Enter Your Gender: ";
		cin >> teacherPtr->gender;
		cout << "\nPlease Enter Your Email: ";
		cin >> teacherPtr->email;
		cout << "\nPlease Enter Your Contact Number: ";
		cin >> teacherPtr->contactNum;
		cout << "\nPlease Enter Your Classroom Number: ";
		cin >> teacherPtr->classNum;
		cout << "\nPlease Enter The Year Group Your Teaching: ";
		cin >> teacherPtr->yearTeaching;
		cout << "\nPlease Enter A Username: ";
		cin >> teacherPtr->accountDetails.username;
		cout << "\nPlease Enter A Password: ";
		cin >> teacherPtr->accountDetails.password;

		cout << "\n\t\t\t1. Confirm SignUp" << endl;//Bottom Footer output

		//Janelle's code start
		ofstream teacherFile;
		teacherFile.open("teachers.csv", ios::app);

		teacherFile << teacherPtr->firstName << "," << teacherPtr->lastName << "," << teacherPtr->gender << "," << teacherPtr->email << ","
			<< teacherPtr->contactNum << "," << teacherPtr->classNum << "," << teacherPtr->yearTeaching << "," << adminPtr->accountDetails.username
			<< "," << adminPtr->accountDetails.password << endl; //writing user input into csv file
		teacherFile.close();

		//call teacher ClassRoom screen
		teachClassRecord(teacherPtr, teacherVtr, teacherEmpData, studentPtr, studentsVtr, emptyDataVtr);
		teachActions(teacherPtr, teacherVtr, teacherEmpData, studentPtr, studentsVtr, emptyDataVtr);
		//Janelle's code end
	}//livs code end

	else if (signupOption == 2) {
		//Janelle's code start
		cout << "\n\t\t\t<-Admin Signup->" << endl;
		cout << "\nEnter admin details" << endl;
		cout << "First name : ";
		cin >> adminPtr->firstName;
		cout << "Last name : ";
		cin >> adminPtr->lastName;
		cout << "Email : ";
		cin >> adminPtr->email;
		cout << "Username : ";
		cin >> adminPtr->accountDetails.username;
		cout << "Password : ";
		cin >> adminPtr->accountDetails.password;
		//opening csv file
		ofstream adminFile;
		adminFile.open("admins.csv", ios::app);

		adminFile << adminPtr->firstName << "," << adminPtr->lastName << "," << adminPtr->email << "," << adminPtr->accountDetails.username << "," << adminPtr->accountDetails.password << endl; //writing user input into csv file
		adminFile.close();

		adminActions(teacherPtr, adminPtr, studentPtr, parentPtr, teacherVtr, adminVtr, studentsVtr, parentVtr, teacherData, adminData, studentDataVtr,
			parentData);
	}
	else if (signupOption == 3) {
		cout << "\n\t\t\t<-Student Signup->" << endl;

		addingStudentCSV(studentPtr, studentsVtr, studentDataVtr);

		studentParentActions(studentPtr, parentPtr, studentsVtr, parentVtr, signupOption);//call parent/student welcome screen
		//Janelle's code end
	}
	else {
		//Olivia's code start
		cout << "\n\t\t\t<-Parents Signup->" << endl;//Title output
		//Entering Signup information for parent information output
		cout << "Please Enter Your FirstName: ";
		cin >> parentPtr->firstName;
		cout << "Please Enter Your LastName: ";
		cin >> parentPtr->lastName;
		cout << "Please Enter Your Gender: ";
		cin >> parentPtr->gender;
		cout << "Please Enter Your Email: ";
		cin >> parentPtr->email;
		cout << "Please Enter Your Contact Number: ";
		cin >> parentPtr->contactNum;
		cout << "Please Enter Your Child's Name : ";
		cin >> parentPtr->childName;
		cout << "Please Enter Your Child's Student ID: ";
		cin >> parentPtr->studentID;
		cout << "Please Enter A Username: ";
		cin >> parentPtr->accountDetails.username;
		cout << "Please Enter A Password: ";
		cin >> parentPtr->accountDetails.password;

		cout << "\n\t\t\t1. Confirm SignUp" << endl;//Bottom Footer output

		//Janelle's code start
		ofstream parentFile;
		parentFile.open("parents.csv", ios::app);

		parentFile << parentPtr->firstName << "," << parentPtr->lastName << "," << parentPtr->gender << "," << parentPtr->email << ","
			<< parentPtr->contactNum << "," << parentPtr->childName << "," << parentPtr->studentID << "," << parentPtr->accountDetails.username
			<< "," << parentPtr->accountDetails.password << endl; //writing user input into csv file
		parentFile.close();
		//call parent/student welcome screen
		//Janelle's code end
		studentParentActions(studentPtr, parentPtr, studentsVtr, parentVtr, signupOption);//call parent/student welcome screen
	}
	//Olivia's code end
}
//Janelle's code end

//Janelle's code start
void login(struct Teacher* teacherPtr, struct Admin* adminPtr, struct Student* studentPtr, struct Parent* parentPtr,
	vector<Teacher> teacherVtr, vector<Admin> adminVtr, vector<Student> studentsVtr, vector<Parent> parentVtr,
	vector<string> teacherData, vector<string> adminData, vector<string> studentDataVtr, vector<string> parentData) {
	int vectorSize;
	string username, password;
	char choice;
	bool usernameFound = false, passwordFound = false;
	int passwordAttempt = 0, i, j, k, l, m, n, p, q;
	string positionType;

	cout << "Enter username : ";
	cin >> username;

	//checking admin vector for matching username
	teacherVtr = readingTeacherCSV(teacherVtr, teacherData);
	adminVtr = readingAdminCSV(adminVtr, adminData);
	studentsVtr = readingStudentCSV(studentsVtr, studentDataVtr);
	parentVtr = readingParentCSV(parentVtr, parentData);
	//cout << adminVtr.size() << endl;
	//checking teacher vector for matching username
	for (i = 0; i < teacherVtr.size(); i++) {
		if (teacherVtr[i].accountDetails.username == username) {
			usernameFound = true;
			positionType = "teacher";
			break;
		}
	}
	//checking admin vector for matching username
	for (j = 0; j < adminVtr.size(); j++) {
		if (adminVtr[j].accountDetails.username == username) {
			usernameFound = true;
			//vectorSize = adminVtr.size();
			positionType = "admin";
			break;
		}
	}
	//checking student vector for matching username
	for (k = 0; k < studentsVtr.size(); k++) {
		if (studentsVtr[k].accountDetails.username == username) {
			usernameFound = true;
			positionType = "student";
			break;
		}
	}
	//checking parent vector for matching username
	for (l = 0; l < parentVtr.size(); l++) {
		if (parentVtr[l].accountDetails.username == username) {
			usernameFound = true;
			positionType = "parent";
			break;
		}
	}

	if (!usernameFound) {
		cout << "Error : No account under that user name was found" << endl;
	}
	else {
		while (passwordAttempt < 3) {
			cout << "Enter password : ";
			cin >> password;
			if (positionType == "teacher") {
				for (m = 0; m < teacherVtr.size(); m++) {
					if (teacherVtr[m].accountDetails.password == password) {
						passwordFound = true;
						break;
					}
				}
			}
			else if (positionType == "admin") {
				for (n = 0; n < adminVtr.size(); n++) {
					if (adminVtr[n].accountDetails.password == password) {
						passwordFound = true;
						break;
					}
				}
			}
			else if (positionType == "student") {
				for (p = 0; p < studentsVtr.size(); p++) {
					if (studentsVtr[p].accountDetails.password == password) {
						passwordFound = true;
						break;
					}
				}
			}
			else {
				for (q = 0; q < parentVtr.size(); q++) {
					if (parentVtr[q].accountDetails.password == password) {
						passwordFound = true;
						break;
					}
				}
			}
			if (!passwordFound) {
				passwordAttempt++;
				if (passwordAttempt == 3) {
					cout << "Password entered incorrectly 3 times. Please try again later." << endl;
					break;
				}
				else {
					cout << "Password entered incorrectly. " << 3 - passwordAttempt << " attempt(s) left." << endl;
				}
			}
			else {
				adminActions(teacherPtr, adminPtr, studentPtr, parentPtr, teacherVtr, adminVtr, studentsVtr, parentVtr, teacherData, adminData, studentDataVtr,
					parentData);
				break;
			}
		}
	}
}
//Janelle's code end
