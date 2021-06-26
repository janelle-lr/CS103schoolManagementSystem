//School Information System
//Group Project - Name: JANIV
//Group Members - Liv & Janelle

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include "csv.h"
#include <Windows.h>

using namespace std;

//Janelle's code
struct Account {
    string username;
    string password;

    //constructor
    Account(string u = "", string p = "") {
        username = u;
        password = p;
    }
};

//Liv's code
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

//Janelle's code
struct Student {
    int id;
    string firstName;
    string lastName;
    int classNum;
    int grade;
    int yearGroup;
    Parent parentDetails;
    Account accountDetails;

    //Constructor
    Student(int i = 0, string fn = "", string ln = "", int c = 0, int g = 0, int y = 0) {
        id = i;
        firstName = fn;
        lastName = ln;
        classNum = c;
        grade = g;
        yearGroup = y;
    }
};

//Janelle's code
struct Admin {
    string firstName;
    string lastName;
    string email;
    Account accountDetails;
};

//Liv's code
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

//----------------------------------PROTOTYPES----------------------------------
void starLine(int numOfStars);
void schoolTitle();
void introScreen();
bool usernameCheck(struct Teacher* teacherPtr, struct Admin* adminPtr, struct Student* studentPtr, struct Parent* parentPtr,
    vector<Teacher> teacherVtr, vector<Admin> adminVtr, vector<Student> studentVtr, vector<Parent> parentVtr,
    vector<string> teacherDataVtr, vector<string> adminDataVtr, vector<string> studentDataVtr, vector<string> parentDataVtr, string username);
void signUp(struct Teacher* teacherPtr, struct Admin* adminPtr, struct Student* studentPtr, struct Parent* parentPtr,
    vector<Teacher> teacherVtr, vector<Admin> adminVtr, vector<Student> studentVtr, vector<Parent> parentVtr,
    vector<string> teacherDataVtr, vector<string> adminDataVtr, vector<string> studentDataVtr, vector<string> parentDataVtr, int positionType);
void login(struct Teacher* teacherPtr, struct Admin* adminPtr, struct Student* studentPtr, struct Parent* parentPtr,
    vector<Teacher> teacherVtr, vector<Admin> adminVtr, vector<Student> studentVtr, vector<Parent> parentVtr,
    vector<string> teacherDataVtr, vector<string> adminDataVtr, vector<string> studentDataVtr, vector<string> parentDataVtr, int positionType);
//----------------------------------TEACHER SECTION----------------------------------
vector<Teacher> storeTeacherVtr(vector<Teacher> teacherVtr, vector<string> teacherDataVtr);
vector<Teacher> readingTeacherCSV(vector<Teacher> teacherVtr, vector<string> teacherDataVtr);
void teachActions(struct Teacher* teacherPtr, struct Student* studentPtr,
    vector<Teacher> teacherVtr, vector<Student> studentVtr,
    vector<string> teacherDataVtr, vector<string> studentDataVtr);
//----------------------------------ADMIN SECTION----------------------------------
vector<Admin> storeAdminVtr(vector<Admin> adminVtr, vector<string> adminDataVtr);
vector<Admin> readingAdminCSV(vector<Admin> adminVtr, vector<string> adminDataVtr);
void adminActions(struct Teacher* teacherPtr, struct Admin* adminPtr, struct Student* studentPtr, struct Parent* parentPtr,
    vector<Teacher> teacherVtr, vector<Admin> adminVtr, vector<Student> studentVtr, vector<Parent> parentVtr,
    vector<string> teacherDataVtr, vector<string> adminDataVtr, vector<string> studentDataVtr, vector<string> parentDataVtr);
//----------------------------------ADMIN/STUDENT SECTION----------------------------------
void writingStudentCSV(struct Teacher* teacherPtr, struct Admin* adminPtr, struct Student* studentPtr, struct Parent* parentPtr,
    vector<Teacher> teacherVtr, vector<Admin> adminVtr, vector<Student> studentVtr, vector<Parent> parentVtr,
    vector<string> teacherDataVtr, vector<string> adminDataVtr, vector<string> studentDataVtr, vector<string> parentDataVtr);
vector<Student> storeStudentVtr(vector<Student>/* studentVtr*/, vector<string> /*studentDataVtr*/);
vector<Student> readingStudentCSV(vector<Student> studentVtr, vector<string> studentDataVtr);
vector<Student> updateStudentCSV(vector<Student> /*studentVtr*/, vector<string> /*studentDataVtr*/);
void DeleteStudentRecord();
void printStudentList(vector<Student>  studentVtr, vector<string> studentDataVtr);
void printClassReports(vector<Student> studentVtr, vector<string> studentDataVtr, int classNo);
//----------------------------------PARENT SECTION----------------------------------
vector<Parent> storeParentVtr(vector<Parent> parentVtr, vector<string> parentDataVtr);
vector<Parent> readingParentCSV(vector<Parent> parentVtr, vector<string> parentDataVtr);
//----------------------------------STUDENT/PARENT SECTION----------------------------------
void studentParentActions(struct Student* studentPtr, struct Parent* parentPtr,
    vector<Student> studentVtr, vector<Parent> parentVtr,
    vector<string> studentDataVtr, vector<string> parentDataVtr, int id, int signupOption);
void studentParentNotices(struct Student* studentPtr, struct Parent* parentPtr,
    vector<Student> studentVtr, vector<Parent> parentVtr,
    vector<string> studentDataVtr, vector<string> parentDataVtr, int id, int signupOption);
void studentParentReportScreen(struct Student* studentPtr, struct Parent* parentPtr,
    vector<Student> studentVtr, vector<Parent> parentVtr, vector<string> studentDataVtr,
    vector<string> parentDataVtr, int id, int signupOption);

int main()
{
    //Janelle's code start
    struct Teacher teacherStruct;
    struct Teacher* teacherPtr = &teacherStruct;
    vector<Teacher> teacherVtr;
    vector<string> teacherDataVtr;

    struct Admin adminStruct;
    struct Admin* adminPtr = &adminStruct;
    vector<Admin> adminVtr;
    vector<string> adminDataVtr;

    struct Student studentStruct;
    struct Student* studentPtr = &studentStruct;
    vector<Student> studentVtr;
    vector<string> studentDataVtr;
    //Janelle's code end

    // Liv's code
    struct Parent parentStruct;
    struct Parent* parentPtr = &parentStruct;
    vector<Parent> parentVtr;
    vector<string> parentDataVtr;

    //Declarations
    int menuOption, positionTypeSignUp, positionTypeLogin;
    bool validInput = false;


    //Janelle's code start
    while (validInput == false) {
        schoolTitle();//calling the school name
        introScreen();
        cout << "1. Sign Up\n2. Login\n3. End" << endl;
        cout << "Enter number for chosen option : ";
        cin >> menuOption;

        switch (menuOption) {
        case 1:
            //sign up
            schoolTitle();
            cout << "\nSign Up as" << endl;
            cout << "1. Teacher\n2. Admin\n3. Parent\n\nTo return enter 4\n" << endl;
            cout << "Enter number for chosen option : ";
            cin >> positionTypeSignUp;
            if (positionTypeSignUp > 4) {
                cout << "Error : Invalid input please enter a number from 1 to 4" << endl;
                Sleep(800);
            }
            else if (positionTypeSignUp == 4) {
                cout << endl;
                break;
            }
            else {
                validInput = true;
                signUp(teacherPtr, adminPtr, studentPtr, parentPtr, teacherVtr, adminVtr, studentVtr, parentVtr, teacherDataVtr, adminDataVtr, studentDataVtr, parentDataVtr, positionTypeSignUp);
            }
            break;
        case 2:
            //login
            schoolTitle();
            cout << "\nLogin as" << endl;
            cout << "1. Teacher\n2. Admin\n3. Student\n4. Parent\n\nTo return enter 5\n" << endl;
            cout << "Enter number for chosen option : ";
            cin >> positionTypeLogin;
            if (positionTypeLogin > 5) {
                cout << "Error : Invalid input, Please enter a number from 1 to 5" << endl;
                Sleep(800);
            }
            else if (positionTypeLogin == 5) {
                cout << endl;
                break;
            }
            else {
                validInput = true;
                login(teacherPtr, adminPtr, studentPtr, parentPtr, teacherVtr, adminVtr, studentVtr, parentVtr, teacherDataVtr, adminDataVtr, studentDataVtr, parentDataVtr, positionTypeLogin);
            }
            break;
        case 3:
            //terminate program
            cout << "\nBye Bye\nProgram ended" << endl;
            validInput = true;
            break;
        default:
            cout << "\nInvalid Input : Please enter a number from 1 to 3" << endl;
            Sleep(1000);
        }
    }

    return 0;
    //Janelle's code end
}

//Liv's code
void starLine(int numOfStars) { // Output for Star Lines
    int i;
    for (i = 0; i < numOfStars; i++) {
        cout << "*";
    }
    cout << endl;
}

//Liv's code
void schoolTitle() {
    system("CLS");// clears console
    cout << "\n\t\tEVABEE SCHOOL INFORMATION SYSTEM" << endl;//Title output
    starLine(66);
}

//Liv's code
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

//Janelle's code
bool usernameCheck(struct Teacher* teacherPtr, struct Admin* adminPtr, struct Student* studentPtr, struct Parent* parentPtr,
    vector<Teacher> teacherVtr, vector<Admin> adminVtr, vector<Student> studentVtr, vector<Parent> parentVtr,
    vector<string> teacherDataVtr, vector<string> adminDataVtr, vector<string> studentDataVtr, vector<string> parentDataVtr, string username) {

    bool usernameFound = false;
    //checking against teacherVtr to see if entered username already exists
    teacherVtr = readingTeacherCSV(teacherVtr, teacherDataVtr);
    for (int i = 0; i < teacherVtr.size(); i++) {
        if (teacherVtr[i].accountDetails.username == username) {
            usernameFound = true;
            return usernameFound;
        }
        else {
            usernameFound = false;
        }
    }

    //checking against adminVtr to see if entered username already exists
    adminVtr = readingAdminCSV(adminVtr, adminDataVtr);
    for (int j = 0; j < adminVtr.size(); j++) {
        if (adminVtr[j].accountDetails.username == username) {
            usernameFound = true;
            return usernameFound;
        }
        else {
            usernameFound = false;
        }
    }

    //checking against studentVtr to see if entered username already exists
    studentVtr = readingStudentCSV(studentVtr, studentDataVtr);
    for (int k = 0; k < studentVtr.size(); k++) {
        if (studentVtr[k].accountDetails.username == username) {
            usernameFound = true;
            return usernameFound;
        }
        else {
            usernameFound = false;
        }
    }

    //checking against studentVtr to see if entered username already exists
    parentVtr = readingParentCSV(parentVtr, parentDataVtr);
    for (int l = 0; l < parentVtr.size(); l++) {
        if (parentVtr[l].accountDetails.username == username) {
            usernameFound = true;
            return usernameFound;
        }
        else {
            usernameFound = false;
        }
    }
    return usernameFound;
}

//Janelle's code
void signUp(struct Teacher* teacherPtr, struct Admin* adminPtr, struct Student* studentPtr, struct Parent* parentPtr,
    vector<Teacher> teacherVtr, vector<Admin> adminVtr, vector<Student> studentVtr, vector<Parent> parentVtr,
    vector<string> teacherDataVtr, vector<string> adminDataVtr, vector<string> studentDataVtr, vector<string> parentDataVtr, int positionType) {

    bool studentFound = false, usernameFound;
    int id = 0, classNum = 0;
    string username;

    schoolTitle();

    //Liv's code start
    //teacher sign up
    if (positionType == 1) {
        //Entering Signup information for teacher information output
        cout << "\n\t\t\t<-Teacher Signup->" << endl;
        cout << "\nEnter Teacher details" << endl;
        cout << "First Name : ";
        cin >> teacherPtr->firstName;
        cout << "Last Name : ";
        cin >> teacherPtr->lastName;
        cout << "Gender : ";
        cin >> teacherPtr->gender;
        cout << "Email : ";
        cin >> teacherPtr->email;
        cout << "Contact Number : ";
        cin >> teacherPtr->contactNum;
    reenterClassNum:
        cout << "Class Number (1 or 2) : ";
        cin >> classNum;
        if (classNum != 1 && classNum != 2) {
            cout << "\nError : There are no classes under that number. Please enter 1 or 2" << endl;
            Sleep(800);
            goto reenterClassNum;
        }
        else {
            teacherPtr->classNum = classNum;
        }
        cout << "Year Group You're Teaching : ";
        cin >> teacherPtr->yearTeaching;
    newTeacherUsername:
        cout << "Username : ";
        cin >> username;
        usernameFound = usernameCheck(teacherPtr, adminPtr, studentPtr, parentPtr, teacherVtr, adminVtr, studentVtr,
            parentVtr, teacherDataVtr, adminDataVtr, studentDataVtr, parentDataVtr, username);

        if (usernameFound == false) {
            teacherPtr->accountDetails.username = username;
            cout << "Password : ";
            cin >> teacherPtr->accountDetails.password;
        }
        else {
            cout << "That username is taken. Please enter a different username.\n" << endl;
            Sleep(1200);
            goto newTeacherUsername;
        }

        //Janelle's code start
        ofstream teacherFile;
        teacherFile.open("teacher.csv", ios::app);

        teacherFile << teacherPtr->firstName << "," << teacherPtr->lastName << "," << teacherPtr->gender << "," << teacherPtr->email << ","
            << teacherPtr->contactNum << "," << teacherPtr->classNum << "," << teacherPtr->yearTeaching << "," << teacherPtr->accountDetails.username
            << "," << teacherPtr->accountDetails.password << endl; //writing user input into csv file
        teacherFile.close();

        readingTeacherCSV(teacherVtr, teacherDataVtr); //read from teacher csv file and write into vector
        //Janelle's code end
        //call teacher ClassRoom screen
        teachActions(teacherPtr, studentPtr, teacherVtr, studentVtr, teacherDataVtr, studentDataVtr);
    }//Liv's code end
    //Janelle's code start
    //admin sign up
    else if (positionType == 2) {
        cout << "\n\t\t\t<-Admin Signup->" << endl;
        cout << "\nEnter admin details" << endl;
        cout << "First name : ";
        cin >> adminPtr->firstName;
        cout << "Last name : ";
        cin >> adminPtr->lastName;
        cout << "Email : ";
        cin >> adminPtr->email;
    newAdminUsername:
        cout << "Username : ";
        cin >> username;
        usernameFound = usernameCheck(teacherPtr, adminPtr, studentPtr, parentPtr, teacherVtr, adminVtr, studentVtr,
            parentVtr, teacherDataVtr, adminDataVtr, studentDataVtr, parentDataVtr, username);

        if (usernameFound == false) {
            adminPtr->accountDetails.username = username;
            cout << "Password : ";
            cin >> adminPtr->accountDetails.password;
        }
        else {
            cout << "That username is taken. Please enter a different username.\n" << endl;
            Sleep(1200);
            goto newAdminUsername;
        }

        //opening csv file
        ofstream adminFile;
        adminFile.open("admin.csv", ios::app);

        adminFile << adminPtr->firstName << "," << adminPtr->lastName << "," << adminPtr->email << "," << adminPtr->accountDetails.username << "," << adminPtr->accountDetails.password << endl; //writing user input into csv file
        adminFile.close();
        readingAdminCSV(adminVtr, adminDataVtr);
        adminActions(teacherPtr, adminPtr, studentPtr, parentPtr, teacherVtr, adminVtr, studentVtr, parentVtr, teacherDataVtr, adminDataVtr, studentDataVtr, parentDataVtr);
    }//Janelle's code end
    //Liv's code start
    //parent sign up
    else {
        cout << "\n\t\t\t<-Parent Signup->" << endl;
        //Entering Signup information for parent information output
        cout << "\nEnter Parent Details" << endl;
        cout << "First Name: ";
        cin >> parentPtr->firstName;
        cout << "Last Name: ";
        cin >> parentPtr->lastName;
        cout << "Gender: ";
        cin >> parentPtr->gender;
        cout << "Email: ";
        cin >> parentPtr->email;
        cout << "Contact Number: ";
        cin >> parentPtr->contactNum;
        cout << "Child's Last Name : ";
        cin >> parentPtr->childName;
        cout << "Child's Student ID: ";
        cin >> parentPtr->studentID;
        //Liv's code end
        //Janelle's code start
        id = parentPtr->studentID;

        //check to see if student exists
        studentVtr = readingStudentCSV(studentVtr, studentDataVtr);

        for (int i = 0; i < studentVtr.size(); i++) {
            if (studentVtr[i].id == id) {
                studentFound = true;
            newParentUsername:
                cout << "Username : ";
                cin >> username;
                usernameFound = usernameCheck(teacherPtr, adminPtr, studentPtr, parentPtr, teacherVtr, adminVtr, studentVtr,
                    parentVtr, teacherDataVtr, adminDataVtr, studentDataVtr, parentDataVtr, username);

                if (usernameFound == false) {
                    parentPtr->accountDetails.username = username;
                    cout << "Password : ";
                    cin >> parentPtr->accountDetails.password;
                }
                else {
                    cout << "That username is taken. Please enter a different username.\n" << endl;
                    Sleep(1200);
                    goto newParentUsername;
                }

                ofstream parentFile;
                parentFile.open("parent.csv", ios::app);

                parentFile << parentPtr->firstName << "," << parentPtr->lastName << "," << parentPtr->gender << "," << parentPtr->email << ","
                    << parentPtr->contactNum << "," << parentPtr->childName << "," << parentPtr->studentID << "," << parentPtr->accountDetails.username
                    << "," << parentPtr->accountDetails.password << endl; //writing user input into csv file
                parentFile.close();
                readingParentCSV(parentVtr, parentDataVtr);

                //call parent/student welcome screen
                studentParentActions(studentPtr, parentPtr, studentVtr, parentVtr, studentDataVtr, parentDataVtr, id, 4); //Liv's code
                break;
            }
            else {
                studentFound = false;
            }
        }

        if (studentFound == false) {
            cout << "\nError : The student ID you entered does not exist. Please try again later." << endl;
            main();
        }
    }
    //Janelle's code end
}

//Janelle's code
void login(struct Teacher* teacherPtr, struct Admin* adminPtr, struct Student* studentPtr, struct Parent* parentPtr,
    vector<Teacher> teacherVtr, vector<Admin> adminVtr, vector<Student> studentVtr, vector<Parent> parentVtr,
    vector<string> teacherDataVtr, vector<string> adminDataVtr, vector<string> studentDataVtr, vector<string> parentDataVtr, int positionType) {
    int vectorSize;
    string username, password;
    char choice;
    bool usernameFound, passwordFound = false;
    int passwordAttempt = 0, i, j, k, l, m, n, p, q, id = 0;

    schoolTitle();
    cout << "\n\t\t\t<-Login->" << endl;

reenterUsername:
    cout << "\nEnter Username : ";
    cin >> username;

    usernameFound = usernameCheck(teacherPtr, adminPtr, studentPtr, parentPtr, teacherVtr, adminVtr, studentVtr,
        parentVtr, teacherDataVtr, adminDataVtr, studentDataVtr, parentDataVtr, username);

    if (usernameFound == true) {
    reenterPassword:
        cout << "Enter Password : ";
        cin >> password;
        if (positionType == 1) {
            //check if password exists in teacher records
            teacherVtr = readingTeacherCSV(teacherVtr, teacherDataVtr);
            for (m = 0; m < teacherVtr.size(); m++) {
                if (teacherVtr[m].accountDetails.password == password) {
                    passwordFound = true;
                    cout << "passwordFound = " << passwordFound << endl;
                    break;
                }
            }
        }
        else if (positionType == 2) {
            //check if password exists in admin records
            adminVtr = readingAdminCSV(adminVtr, adminDataVtr);
            for (n = 0; n < adminVtr.size(); n++) {
                if (adminVtr[n].accountDetails.password == password) {
                    passwordFound = true;
                    break;
                }
            }
        }
        else if (positionType == 3) {
            //check if password exists in student records
            studentVtr = readingStudentCSV(studentVtr, studentDataVtr);
            for (p = 0; p < studentVtr.size(); p++) {
                if (studentVtr[p].accountDetails.password == password) {
                    passwordFound = true;
                    id = studentVtr[p].id;
                    break;
                }
            }
        }
        else {
            //check if password exists in parent records
            parentVtr = readingParentCSV(parentVtr, parentDataVtr);
            for (q = 0; q < parentVtr.size(); q++) {
                if (parentVtr[q].accountDetails.password == password) {
                    passwordFound = true;
                    id = parentVtr[q].studentID;
                    break;
                }
            }
        }
    }
    else {
        cout << "There is no account existing under that username, please enter another username.\n" << endl;
        goto reenterUsername;
    }

    if (!passwordFound) {
        passwordAttempt++;
        if (passwordAttempt == 3) {
            cout << "Password entered incorrectly 3 times. Please try again later." << endl;
            main();
        }
        else {
            cout << "Password entered incorrectly. " << 3 - passwordAttempt << " attempt(s) left." << endl;
            goto reenterPassword;
        }
    }
    else {
        if (positionType == 1) {
            //call teacher scree
            teachActions(teacherPtr, studentPtr, teacherVtr, studentVtr, teacherDataVtr, studentDataVtr);
        }
        else if (positionType == 2) {
            //call admin screen
            adminActions(teacherPtr, adminPtr, studentPtr, parentPtr, teacherVtr, adminVtr, studentVtr, parentVtr, teacherDataVtr, adminDataVtr, studentDataVtr, parentDataVtr);
        }
        else if (positionType == 3) {
            //call student/parent screen
            studentParentActions(studentPtr, parentPtr, studentVtr, parentVtr, studentDataVtr, parentDataVtr, id, 3);
        }
        else {
            //call student/parent screen
            studentParentActions(studentPtr, parentPtr, studentVtr, parentVtr, studentDataVtr, parentDataVtr, id, 4);
        }
    }
}


//----------------------------------TEACHER SECTION----------------------------------
//Janelle's code
vector<Teacher> storeTeacherVtr(vector<Teacher> teacherVtr, vector<string> teacherDataVtr) {
    Teacher tchr;

    tchr.firstName = teacherDataVtr[0];
    tchr.lastName = teacherDataVtr[1];
    tchr.gender = teacherDataVtr[2];
    tchr.email = teacherDataVtr[3];
    tchr.contactNum = stoi(teacherDataVtr[4]);
    tchr.classNum = stoi(teacherDataVtr[5]);
    tchr.yearTeaching = stoi(teacherDataVtr[6]);
    tchr.accountDetails.username = teacherDataVtr[7];
    tchr.accountDetails.password = teacherDataVtr[8];

    teacherVtr.push_back(tchr);

    return teacherVtr;
}

//Janelle's code
vector<Teacher> readingTeacherCSV(vector<Teacher> teacherVtr, vector<string> teacherDataVtr) {
    string line, currentStr;

    ifstream readingFromTeacherCSV;
    readingFromTeacherCSV.open("teacher.csv", ios::in);

    while (getline(readingFromTeacherCSV, line)) {
        stringstream ss(line);

        while (!ss.eof()) {
            getline(ss, currentStr, ',');
            teacherDataVtr.push_back(currentStr);//storing current data being read to studentDataVtr
        }
        teacherVtr = storeTeacherVtr(teacherVtr, teacherDataVtr);

        teacherDataVtr.clear();
    }
    readingFromTeacherCSV.close();
    return teacherVtr;
}

//Liv's code
void teachActions(struct Teacher* teacherPtr, struct Student* studentPtr,
    vector<Teacher> teacherVtr, vector<Student> studentVtr,
    vector<string> teacherDataVtr, vector<string> studentDataVtr) {

    int teacherChoice = 0, recordChoice, studRecChoice, classRecordChoice, displayRprtChoice, reportChoice;

    while (teacherChoice != 3) {
        schoolTitle();
        cout << "\n\t\t\t<-Signed in as Teacher->" << endl;
        cout << "\Teacher actions" << endl;
        cout << "\n1. View Student Records\n2. View Student Reports\n3. Sign Out" << endl;
        cout << "\nEnter Number For Chosen Option : ";
        cin >> teacherChoice;

        switch (teacherChoice) {
        case 1:
            //Student records
            schoolTitle();
            cout << "\n\t\t\t<-Student List->" << endl;
            printStudentList(studentVtr, studentDataVtr);
            break;
        case 2:
            schoolTitle();
            cout << "\n\t\t\t<-Student Reports->" << endl;
            cout << "1. View Class 1 records\n2. View Class 2 records\n3. Back" << endl;
            cout << "\nEnter number for chosen option : ";
            cin >> reportChoice;
            cout << endl;
            if (reportChoice == 1) {
                cout << "\n\t\t\t<-Class 1 Records->" << endl;
                printClassReports(studentVtr, studentDataVtr, 1);
            }
            else if (reportChoice == 2) {
                cout << "\n\t\t\t<-Class 2 Records->" << endl;
                printClassReports(studentVtr, studentDataVtr, 2);
            }
            else if (reportChoice == 3) {
                break;
            }
            else {
                cout << "\nInvalid input: Please enter a number from 1 to 2" << endl;
                Sleep(1000);
                break;
            }
            break;
        case 3:
            cout << "\nSuccessfully Signed Out, See You Next Time!" << endl;
            main();
            break;
        default:
            cout << "\nInvalid Input : Please enter a number from 1 to 3" << endl;
            Sleep(1000);
        }
    }

}

//----------------------------------ADMIN SECTION----------------------------------
//Janelle's code
vector<Admin> storeAdminVtr(vector<Admin> adminVtr, vector<string> adminDataVtr) {
    Admin adm;

    adm.firstName = adminDataVtr[0];
    adm.lastName = adminDataVtr[1];
    adm.email = adminDataVtr[2];
    adm.accountDetails.username = adminDataVtr[3];
    adm.accountDetails.password = adminDataVtr[4];

    adminVtr.push_back(adm);

    return adminVtr;
}

//Janelle's code
vector<Admin> readingAdminCSV(vector<Admin> adminVtr, vector<string> adminDataVtr) {

    string line, currentStr;

    ifstream readingFromAdminCSV;
    readingFromAdminCSV.open("admin.csv", ios::in);

    while (getline(readingFromAdminCSV, line)) {
        stringstream ss(line);

        while (!ss.eof()) {
            getline(ss, currentStr, ',');
            adminDataVtr.push_back(currentStr);//storing current data being read to adminDataVtr
        }
        adminVtr = storeAdminVtr(adminVtr, adminDataVtr);

        adminDataVtr.clear();
    }
    readingFromAdminCSV.close();

    return adminVtr;
}

//Janelle's code
void adminActions(struct Teacher* teacherPtr, struct Admin* adminPtr, struct Student* studentPtr, struct Parent* parentPtr,
    vector<Teacher> teacherVtr, vector<Admin> adminVtr, vector<Student> studentVtr, vector<Parent> parentVtr,
    vector<string> teacherDataVtr, vector<string> adminDataVtr, vector<string> studentDataVtr, vector<string> parentDataVtr) {

    int actionChoice = 0, recordChoice = 0, reportChoice = 0;

    while (actionChoice != 3) {
        schoolTitle();
        cout << "\n\t\t\t<-Signed in as Admin->" << endl;
        cout << "\nAdmin actions" << endl;
        cout << "\n1. Access Student Records\n2. Access Student Reports\n3. Sign Out" << endl;
        cout << "\nEnter number for chosen option: ";
        cin >> actionChoice;

        switch (actionChoice) {
        case 1:
            //student records
            schoolTitle();
            cout << "\nStudent Records" << endl;
            cout << "1. Add new student\n2. Edit student record\n3. Delete student record\n4. Back" << endl;
            cout << "\nEnter number for chosen option : ";
            cin >> recordChoice;
            cout << endl;
            if (recordChoice == 1) {
                schoolTitle();
                cout << "\n\t\t\t<-New Student Record->" << endl;
                writingStudentCSV(teacherPtr, adminPtr, studentPtr, parentPtr, teacherVtr, adminVtr, studentVtr, parentVtr,
                    teacherDataVtr, adminDataVtr, studentDataVtr, parentDataVtr);
            }
            else if (recordChoice == 2) {
                schoolTitle();
                cout << "\n\t\t\t<-Edit Student Record->" << endl;
                updateStudentCSV(studentVtr, studentDataVtr);
            }
            else if (recordChoice == 3) {
                schoolTitle();
                DeleteStudentRecord();
            }
            else if (recordChoice == 4) {
                break;
            }
            else {
                cout << "\nInvalid input: Please enter a number from 1 to 3" << endl;
                Sleep(1000);
                break;
            }
            break;
        case 2:
            //student reports
            schoolTitle();
            cout << "\nStudent Reports" << endl;
            cout << "1. Display Class 1 Reports\n2. Display Class 2 Reports" << endl;
            cout << "\nEnter number for chosen option : ";
            cin >> reportChoice;
            cout << endl;
            if (reportChoice == 1) {
                schoolTitle();
                cout << "\n\t\t\t<-Class 1 Reports->" << endl;
                printClassReports(studentVtr, studentDataVtr, 1);
            }
            else if (reportChoice == 2) {
                schoolTitle();
                cout << "\n\t\t\t<-Class 2 Reports->" << endl;
                printClassReports(studentVtr, studentDataVtr, 2);
            }
            else {
                cout << "\nInvalid input: Please enter a number from 1 to 2" << endl;
                Sleep(1000);
                break;
            }
            break;
        case 3:
            schoolTitle();
            cout << "\nSuccessfully Signed Out, See You Next Time!" << endl;
            main();
            break;
        default:
            cout << "\nInvalid Input : Please enter a number from 1 to 3" << endl;
            Sleep(1000);
        }
    }

}
//----------------------------------ADMIN/STUDENT SECTION----------------------------------
// //Janelle's code
//write into CSV file
void writingStudentCSV(struct Teacher* teacherPtr, struct Admin* adminPtr, struct Student* studentPtr, struct Parent* parentPtr,
    vector<Teacher> teacherVtr, vector<Admin> adminVtr, vector<Student> studentVtr, vector<Parent> parentVtr,
    vector<string> teacherDataVtr, vector<string> adminDataVtr, vector<string> studentDataVtr, vector<string> parentDataVtr) {
    int classNum;
    string username;
    bool usernameFound;

    schoolTitle();
    cout << "\n\t\t\t<-Add new Student Record->" << endl;
    cout << "\nEnter student details" << endl;
    cout << "First name : ";
    cin >> studentPtr->firstName;
    cout << "Last name : ";
    cin >> studentPtr->lastName;
    cout << "Year group : ";
    cin >> studentPtr->yearGroup;
reenterClassNum:
    cout << "Class Number (1 or 2) : ";
    cin >> classNum;
    if (classNum != 1 && classNum != 2) {
        cout << "\nError : There are no classes under that number. Please enter 1 or 2" << endl;
        Sleep(700);
        goto reenterClassNum;
    }
    else {
        studentPtr->classNum = classNum;
    }
    cout << "Average overall grade (% and solid numbers only) : ";
    cin >> studentPtr->grade;
    cout << "Parent/guardian first name : ";
    cin >> studentPtr->parentDetails.firstName;
    cout << "Parent/guardian last name : ";
    cin >> studentPtr->parentDetails.lastName;
    cout << "Parent/guardian email : ";
    cin >> studentPtr->parentDetails.email;
    cout << "Parent/guardian gender : ";
    cin >> studentPtr->parentDetails.gender;
    //cout << "Student Username : ";
    //cin >> studentPtr->accountDetails.username;
newStudentUsername:
    cout << "Student Username : ";
    cin >> username;
    usernameFound = usernameCheck(teacherPtr, adminPtr, studentPtr, parentPtr, teacherVtr, adminVtr, studentVtr,
        parentVtr, teacherDataVtr, adminDataVtr, studentDataVtr, parentDataVtr, username);

    if (usernameFound == false) {
        studentPtr->accountDetails.username = username;
        cout << "Password : ";
        cin >> studentPtr->accountDetails.password;
    }
    else {
        cout << "That username is taken. Please enter a different username.\n" << endl;
        Sleep(1200);
        goto newStudentUsername;
    }

newId:
    srand(time(NULL));
    studentPtr->id = rand() % 100 + 1;
    studentVtr = readingStudentCSV(studentVtr, studentDataVtr);

    for (int i = 0; i < studentVtr.size(); i++) {
        if (studentVtr[i].id == studentPtr->id) {
            goto newId; // if student from file is already assigned to a student then assign new id
        }
    }

    cout << "Student's assigned ID number : " << studentPtr->id << endl;
    Sleep(1500);
    if (studentPtr->classNum == 1) {
        ofstream writingToClass1CSV("class1.csv", ios::app);
        writingToClass1CSV << studentPtr->id << "," << studentPtr->firstName << "," << studentPtr->lastName << "," << studentPtr->yearGroup << ","
            << studentPtr->classNum << "," << studentPtr->grade << "," << studentPtr->parentDetails.firstName << "," << studentPtr->parentDetails.lastName << ","
            << studentPtr->parentDetails.email << "," << studentPtr->parentDetails.gender << "," << studentPtr->accountDetails.username
            << "," << studentPtr->accountDetails.password << endl;//writing to csv file
        writingToClass1CSV.close();
    }
    else if (studentPtr->classNum == 2) {
        ofstream writingToClass2CSV("class2.csv", ios::app);
        writingToClass2CSV << studentPtr->id << "," << studentPtr->firstName << "," << studentPtr->lastName << "," << studentPtr->yearGroup << ","
            << studentPtr->classNum << "," << studentPtr->grade << "," << studentPtr->parentDetails.firstName << "," << studentPtr->parentDetails.lastName << ","
            << studentPtr->parentDetails.email << "," << studentPtr->parentDetails.gender << "," << studentPtr->accountDetails.username
            << "," << studentPtr->accountDetails.password << endl;//writing to csv file
        writingToClass2CSV.close();
    }
    else {
        cout << "\nThere are no classes under that number" << endl;
    }
    readingStudentCSV(studentVtr, studentDataVtr);
}

//Janelle's code
//store data into vector
vector<Student> storeStudentVtr(vector<Student> studentVtr, vector<string> studentDataVtr) {
    Student stdnt;

    stdnt.id = stoi(studentDataVtr[0]);
    stdnt.firstName = studentDataVtr[1];
    stdnt.lastName = studentDataVtr[2];
    stdnt.yearGroup = stoi(studentDataVtr[3]);
    stdnt.classNum = stoi(studentDataVtr[4]);
    stdnt.grade = stoi(studentDataVtr[5]);
    stdnt.parentDetails.firstName = studentDataVtr[6];
    stdnt.parentDetails.lastName = studentDataVtr[7];
    stdnt.parentDetails.email = studentDataVtr[8];
    stdnt.parentDetails.gender = studentDataVtr[9];
    stdnt.accountDetails.username = studentDataVtr[10];
    stdnt.accountDetails.password = studentDataVtr[11];

    studentVtr.push_back(stdnt);
    return studentVtr;
}

//Janelle's code
//read from csv file and store into vector
vector<Student> readingStudentCSV(vector<Student> studentVtr, vector<string> studentDataVtr) {

    string line, currentStr, line2, currentStr2;

    //CLASS 1
    ifstream readingFromClass1CSV;
    readingFromClass1CSV.open("class1.csv", ios::in);

    while (getline(readingFromClass1CSV, line)) {
        stringstream ss(line);

        while (!ss.eof()) {
            getline(ss, currentStr, ',');
            studentDataVtr.push_back(currentStr);//storing current data being read to studentDataVtr
        }
        studentVtr = storeStudentVtr(studentVtr, studentDataVtr);
        studentDataVtr.clear();
    }
    readingFromClass1CSV.close();

    //CLASS 2
    ifstream readingFromClass2CSV;
    readingFromClass2CSV.open("class2.csv", ios::in);

    while (getline(readingFromClass2CSV, line2)) {
        stringstream ss2(line2);

        while (!ss2.eof()) {
            getline(ss2, currentStr2, ',');
            studentDataVtr.push_back(currentStr2);//storing current data being read to studentDataVtr
        }
        studentVtr = storeStudentVtr(studentVtr, studentDataVtr);
        studentDataVtr.clear();
    }
    readingFromClass2CSV.close();

    return studentVtr;
}

//Janelle's code
vector<Student> updateStudentCSV(vector<Student> studentVtr, vector<string> studentDataVtr) {

    string firstName, lastName, guardianFirstName, guardianLastName, guardianEmail, guardianGender, username, password, newFirstName, newLastName, newGuardianFirstName, newGuardianLastName, newGuardianEmail, newGuardianGender, newUsername, newPassword;
    char choice;
    bool found = false;
    int id, editChoice, yearGroup, classNumber, newYearGroup, newGrade, newClassNumber, i, j;

    schoolTitle();

    studentVtr = readingStudentCSV(studentVtr, studentDataVtr);

    cout << "\n\t\t\t<-Update Student Record->" << endl;
    cout << "\nPlease enter Student id : ";
    cin >> id;

    //loop through vector Student
    for (i = 0; i < studentVtr.size(); i++) {
        //check if user input is equal to existing Student id
        if (studentVtr[i].id == id) {
            cout << "\nStudent ID : " << studentVtr[i].id
                << "\nStudent First Name : " << studentVtr[i].firstName
                << "\nStudent Last Name : " << studentVtr[i].lastName
                << "\nStudent Class Number : " << studentVtr[i].yearGroup
                << "\nStudent Class Number : " << studentVtr[i].classNum
                << "\nStudent Overall Grade : " << studentVtr[i].grade
                << "\nParent/Guardian First Name : " << studentVtr[i].parentDetails.firstName
                << "\nParent/Guardian Last Name : " << studentVtr[i].parentDetails.lastName
                << "\nParent/Guardian Email : " << studentVtr[i].parentDetails.email
                << "\nParent/Guardian Gender : " << studentVtr[i].parentDetails.gender
                << "\nStudent Username : " << studentVtr[i].accountDetails.username
                << "\nStudent Password : " << studentVtr[i].accountDetails.password << endl;

            cout << "\nStudent found : Would you like to change student details (y/n)? : ";
            cin >> choice;
            if (tolower(choice) == 'y') {
                found = true;
                cout << "\nWhich student detail would you like to change?\n1. First Name\n2. Last Name\n3. Year Group\n4. Class Number\n5. Grade\n6. Parent/Guardian first name\n7. Parent/Guardian last name\n8. Parent/Guardian email\n9. Parent/Guardian gender\n10. Student Username\n11. Student Password" << endl;
                cout << "Enter number for chosen option : ";
                cin >> editChoice;
                cout << endl;
                switch (editChoice) {
                case 1:
                    //change student first name
                    cout << "Enter new student first name : ";
                    cin >> newFirstName;
                    studentVtr[i].firstName = newFirstName;
                    cout << "\nStudent first name has been successfully updated\n";
                    break;
                case 2:
                    //change student last name
                    cout << "Enter new student last name : ";
                    cin >> newLastName;
                    studentVtr[i].lastName = newLastName;
                    cout << "\nStudent last name has been successfully updated\n";
                    break;
                case 3:
                    //change student year group
                    cout << "Enter new student year group : ";
                    cin >> newYearGroup;
                    studentVtr[i].yearGroup = newYearGroup;
                    cout << "\nStudent year group has been successfully updated\n";
                    break;
                case 4:
                    //change student class number
                    cout << "Enter new student class number : ";
                    cin >> newClassNumber;
                    studentVtr[i].classNum = newClassNumber;
                    cout << "\nStudent class number has been successfully updated\n";
                    break;
                case 5:
                    //change student grade
                    cout << "Enter new student grade (% and solid numbers only) : ";
                    cin >> newGrade;
                    studentVtr[i].grade = newGrade;
                    cout << "\nStudent student grade has been successfully updated\n";
                    break;
                case 6:
                    //change parent first name
                    cout << "Enter new parent/guardian first name : ";
                    cin >> newGuardianFirstName;
                    studentVtr[i].parentDetails.firstName = newGuardianFirstName;
                    cout << "\nParent/guardian first name has been successfully updated\n";
                    break;
                case 7:
                    //change parent last name
                    cout << "Enter new parent/guardian last name : ";
                    cin >> newGuardianLastName;
                    studentVtr[i].parentDetails.lastName = newGuardianLastName;
                    cout << "\nParent/guardian last name has been successfully updated\n";
                    break;
                case 8:
                    //change parent email
                    cout << "Enter new parent/guardian email : ";
                    cin >> newGuardianEmail;
                    studentVtr[i].parentDetails.email = newGuardianEmail;
                    cout << "\nParent/guardian email has been successfully updated\n";
                    break;
                case 9:
                    //change parent gender
                    cout << "Enter new parent/guardian gender : ";
                    cin >> newGuardianGender;
                    studentVtr[i].parentDetails.gender = newGuardianGender;
                    cout << "\nParent/guardian gender has been successfully updated\n";
                    break;
                case 10:
                    //change student username
                    cout << "Enter new student username : ";
                    cin >> newUsername;
                    studentVtr[i].accountDetails.username = newUsername;
                    cout << "\nStudent username has been successfully updated\n";
                    break;
                case 11:
                    //change student password
                    cout << "Enter new student password : ";
                    cin >> newPassword;
                    studentVtr[i].accountDetails.password = newPassword;
                    cout << "\nStudent password has been successfully updated\n";
                    break;
                default:
                    cout << "\nInvalid input : please enter a number from 1 to 11" << endl;
                    Sleep(1000);
                }
            }
            else {
                cout << "\nChanges cancelled" << endl;
                /*break;*/
            }
            break;
        }
        else {
            found = false;
        }
    }

    ofstream clearClass1CSV("class1.csv", ios::trunc);//clearing current class1.csv file to get ready for rewriting
    clearClass1CSV.close();
    ofstream clearClass2CSV("class2.csv", ios::trunc);//clearing current class1.csv file to get ready for rewriting
    clearClass2CSV.close();

    if (!found) {
        cout << "\n\tStudent not found\n\n";
    }
    else {
        ////print Student again to show the changes
        //printStudentList(studentVtr, studentDataVtr);

        for (i = 0; i < studentVtr.size(); i++) {
            //delete csv file and rewrite using app
            if (studentVtr[i].classNum == 1) {
                //ofstream updateClass1CSV("class1.csv", ios::in);
                ofstream updateClass1CSV("class1.csv", ios::app);
                updateClass1CSV << studentVtr[i].id << "," << studentVtr[i].firstName << "," << studentVtr[i].lastName << "," << studentVtr[i].yearGroup << ","
                    << studentVtr[i].classNum << "," << studentVtr[i].grade << "," << studentVtr[i].parentDetails.firstName << "," << studentVtr[i].parentDetails.lastName << ","
                    << studentVtr[i].parentDetails.email << "," << studentVtr[i].parentDetails.gender << "," << studentVtr[i].accountDetails.username
                    << "," << studentVtr[i].accountDetails.password << endl;//writing to csv file
                updateClass1CSV.close();
            }
            else if (studentVtr[i].classNum == 2) {
                ofstream updateClass2CSV("class2.csv", ios::app);
                updateClass2CSV << studentVtr[i].id << "," << studentVtr[i].firstName << "," << studentVtr[i].lastName << "," << studentVtr[i].yearGroup << ","
                    << studentVtr[i].classNum << "," << studentVtr[i].grade << "," << studentVtr[i].parentDetails.firstName << "," << studentVtr[i].parentDetails.lastName << ","
                    << studentVtr[i].parentDetails.email << "," << studentVtr[i].parentDetails.gender << "," << studentVtr[i].accountDetails.username
                    << "," << studentVtr[i].accountDetails.password << endl;//writing to csv file
                updateClass2CSV.close();

            }
        }
    }
    return studentVtr;
}

//Scott's code
void DeleteStudentRecord() {
    cout << "\n\t\t\t<-Delete Student Record->\n" << endl;
    //Scott Code start
    cin.ignore();

    cout << "Please Enter The Number Of The Class That The Student You Want To Delete Is In (6 Chars MAX): ";
    string str1;
    int classid = 0;
classchoice:
    getline(cin, str1);
    if (!str1.empty()) {
        if (str1.length() > 6) {
            cout << "Value Needs To Be Less Than 6 Chars Long" << endl;
            goto classchoice;
        }
        classid = stoi(str1);

        string filename = "class";
        filename += to_string(classid);
        filename += ".csv";

        ifstream test(filename);

        if (test.is_open()) {
            test.close();
            cout << "Please Enter The ID Of The Student You Want To Delete (6 Chars MAX): ";
            string str;
            int id = 0;
        deletestudentchoice:

            getline(cin, str);
            if (!str.empty())
            {
                if (str.length() > 6) {
                    cout << "Value Needs To Be Less Than 6 Chars Long" << endl;
                    goto deletestudentchoice;
                }
                id = stoi(str);

                if (id == 0 || id > 100) {
                    cout << "Please Enter A ID Between The Values Of 1 And 100" << endl;
                    goto deletestudentchoice;
                }

                vector<string>Students;

                io::CSVReader<12> in(filename);
                int a, d, e;
                int count = 0;
                float f;
                string b, c, g, h, i, j, k, l;
                string name;
                while (in.read_row(a, b, c, d, e, f, g, h, i, j, k, l)) {
                    string student = to_string(a) + "," + b + "," + c + "," + to_string(d) + "," + to_string(e) + "," + to_string(f) + "," + g + "," + h + "," + i + "," + j + "," + k + "," + l;
                    if (id == a) {
                        count++;
                        name = b;
                    }
                    else {
                        Students.push_back(student);
                    }
                }
                if (Students.size() > 0) {
                    ofstream write(filename, ofstream::out | ofstream::trunc);
                    write.clear();
                    for (int i = 0; i < Students.size(); i++) {
                        write << Students[i] << endl;
                    }
                    cout << "Student: " << name << " Has Been Deleted" << endl;
                    Sleep(1500);
                }
                if (count == 0) {
                    cout << "No Students Were Found That Are Matching The ID In The Class You Gave. Please Try Again: ";
                    goto classchoice;
                }
            }
            else {
                cout << "Please Enter A Value" << endl;
                goto deletestudentchoice;
            }
        }
        else {
            cout << "There Are No Classes That Match The Value You Have Given. Please Try Again: ";
            goto classchoice;
        }

    }
    else {
        cout << "Please Enter A Value" << endl;
        goto classchoice;
    }
    //scott's code end
}

//Janelle's code
void printStudentList(vector<Student> studentVtr, vector<string> studentDataVtr) {
    int returnChoice;

    studentVtr = readingStudentCSV(studentVtr, studentDataVtr);
    for (int i = 0; i < studentVtr.size(); i++) {
        cout << "\nStudent ID : " << studentVtr[i].id
            << "\nStudent First Name : " << studentVtr[i].firstName
            << "\nStudent Last Name : " << studentVtr[i].lastName
            << "\nStudent Class Number : " << studentVtr[i].yearGroup
            << "\nStudent Class Number : " << studentVtr[i].classNum
            << "\nStudent Overall Grade : " << studentVtr[i].grade
            << "\nParent/Guardian First Name : " << studentVtr[i].parentDetails.firstName
            << "\nParent/Guardian Last Name : " << studentVtr[i].parentDetails.lastName
            << "\nParent/Guardian Email : " << studentVtr[i].parentDetails.email
            << "\nParent/Guardian Gender : " << studentVtr[i].parentDetails.gender
            << "\nStudent Username : " << studentVtr[i].accountDetails.username
            << "\nStudent Password : " << studentVtr[i].accountDetails.password << endl;
    }

    cout << "\nEnter 1 to return to main screen : ";
    cin >> returnChoice;
    if (returnChoice == 1) {
        return;
    }
}

//Janelle's code
void printClassReports(vector<Student> studentVtr, vector<string> studentDataVtr, int classNo) {
    bool belowPass = false;
    int returnChoice;

    schoolTitle();
    studentVtr = readingStudentCSV(studentVtr, studentDataVtr);

    for (int i = 0; i < studentVtr.size(); i++) {
        if (studentVtr[i].classNum == classNo) {
            if (studentVtr[i].grade < 50) {
                belowPass = true;
            }
            cout << "\nStudent ID : " << studentVtr[i].id
                << "\nStudent Name : " << studentVtr[i].firstName << " " << studentVtr[i].lastName
                << "\nStudent overall grade average: " << studentVtr[i].grade << "%" << endl;
            Sleep(400);
        }
    }

    //the following will only print if there are students with grades below 50%
    if (belowPass == true) {
        cout << "\n\nThe following student(s) have achieved overall grades below 50% and may be in need of extra help" << endl;
        Sleep(1000);
        for (int j = 0; j < studentVtr.size(); j++) {
            if (studentVtr[j].classNum == classNo && studentVtr[j].grade < 50) {
                cout << "\nStudent ID : " << studentVtr[j].id
                    << "\nStudent Name : " << studentVtr[j].firstName << " " << studentVtr[j].lastName
                    << "\nStudent overall grade average : " << studentVtr[j].grade << "%" << endl;
                Sleep(400);
            }
        }
    }

    cout << "\nEnter 1 to return to main screen : ";
    cin >> returnChoice;
    if (returnChoice == 1) {
        return;
    }
}

//----------------------------------PARENT SECTION----------------------------------
//Janelle's code
vector<Parent> storeParentVtr(vector<Parent> parentVtr, vector<string> parentDataVtr) {
    Parent prnt;

    prnt.firstName = parentDataVtr[0];
    prnt.lastName = parentDataVtr[1];
    prnt.gender = parentDataVtr[2];
    prnt.email = parentDataVtr[3];
    prnt.contactNum = stoi(parentDataVtr[4]);
    prnt.childName = parentDataVtr[5];
    prnt.studentID = stoi(parentDataVtr[6]);
    prnt.accountDetails.username = parentDataVtr[7];
    prnt.accountDetails.password = parentDataVtr[8];

    parentVtr.push_back(prnt);

    return parentVtr;
}

//Janelle's code
vector<Parent> readingParentCSV(vector<Parent> parentVtr, vector<string> parentDataVtr) {
    string line, currentStr;
    ifstream readingFromParentCSV;
    readingFromParentCSV.open("parent.csv", ios::in);

    while (getline(readingFromParentCSV, line)) {
        stringstream ss(line);

        while (!ss.eof()) {
            getline(ss, currentStr, ',');
            parentDataVtr.push_back(currentStr);//storing current data being read to parentDataVtr
        }
        parentVtr = storeParentVtr(parentVtr, parentDataVtr);

        parentDataVtr.clear();
    }
    readingFromParentCSV.close();
    return parentVtr;
}

//----------------------------------STUDENT/PARENT SECTION----------------------------------
//Livs Code
//PARENT/STUDENT SCREEN
void studentParentActions(struct Student* studentPtr, struct Parent* parentPtr,
    vector<Student> studentVtr, vector<Parent> parentVtr, vector<string> studentDataVtr,
    vector<string> parentDataVtr, int id, int signupOption) { /*Parents Account, So Where she/he is able to find information about school or her child.*/

    int parentChoice = 0, recordChoice, studRecChoice, displayRprtChoice, reportChoice;

    while (parentChoice != 3) {
        schoolTitle();
        //Janelle's code start
        cout << "\n\t\t\t<-Signed in as ";
        if (signupOption == 3) {
            cout << "Student->";
        }
        else {
            cout << "Parent->";
        }
        //Janelle's code end
        //Janelle's code start
        if (signupOption == 3) {
            cout << "\nStudent ";
        }
        else {
            cout << "\nParent ";
        }
        cout << "Actions" << endl;
        //Janelle's code end
        cout << "\n1. View Student Report\n2. View School Notices\n3. Sign Out" << endl;
        cout << "\nEnter Number For Chosen Option : ";
        cin >> parentChoice;

        if (parentChoice == 1) {
            schoolTitle();
            cout << "\n\n\n<-Student Report->" << endl;
            studentParentReportScreen(studentPtr, parentPtr, studentVtr, parentVtr, studentDataVtr, parentDataVtr, id, signupOption);
        }
        else if (parentChoice == 2) {
            cout << "\n<-School Notices->" << endl;
            studentParentNotices(studentPtr, parentPtr, studentVtr, parentVtr, studentDataVtr, parentDataVtr, id, signupOption);
        }
        else if (parentChoice == 3) {
            cout << "\nSuccessfully Signed Out, See You Next Time!" << endl;
            parentChoice = 3;
            main();
        }
        else {
            cout << "\nInvalid Input : Please enter a number from 1 to 3" << endl;
            Sleep(1000);
        }
    }
}

//Livs Code
void studentParentNotices(struct Student* studentPtr, struct Parent* parentPtr,
    vector<Student> studentVtr, vector<Parent> parentVtr,
    vector<string> studentDataVtr, vector<string> parentDataVtr, int id, int signupOption) { /*this current codes main use is "parent* pn" but also pulling from parent account
                                            which is parent* a as hoping to connect with the parent account username??*/
    int choice;

    schoolTitle();

    cout << "\nToday's School Event Notices" << endl;
    cout << "\n\n8.30am: Show And Tell" << endl;
    cout << "\nMake Sure Your Child Has Brought Something Awesome To Share! :)" << endl;
    cout << "\n12.30pm: School Lunch" << endl;
    cout << "\nShared Lunch! Bring Something Scrumtious! :P" << endl;
    cout << "\n1pm: Sports" << endl;
    cout << "\nEnter 1 to return to main screen : ";
    cin >> choice;
    if (choice == 1) {
        studentParentActions(studentPtr, parentPtr, studentVtr, parentVtr, studentDataVtr, parentDataVtr, id, signupOption);
    }
    starLine(66);


}

//Livs Code
void studentParentReportScreen(struct Student* studentPtr, struct Parent* parentPtr,
    vector<Student> studentVtr, vector<Parent> parentVtr, vector<string> studentDataVtr,
    vector<string> parentDataVtr, int id, int signupOption) { /*Parents Report Screen is so the parent is able to see the current reports
                                    or notes on their child academically */

    int choice;
    for (int i = 0; i < studentVtr.size(); i++) {
        if (studentVtr[i].id == id) {
            cout << "Report For " << studentVtr[i].firstName << " " << studentVtr[i].lastName << endl;

            cout << studentVtr[i].firstName << "\'\s Student ID is " << studentVtr[i].id << endl;

            cout << studentVtr[i].firstName << "\'\s Overall Grade Average is " << studentVtr[i].grade << "%" << endl;

            if (studentVtr[i].grade < 50) {
                cout << "\n<-Feedback->" << endl;
                cout << "\n" << studentVtr[i].firstName << " may be in need of required help please contact school office for more information" << endl;
            }
        }

    }
    cout << "\nEnter 1 to return to main screen : ";
    cin >> choice;
    if (choice == 1) {
        studentParentActions(studentPtr, parentPtr, studentVtr, parentVtr, studentDataVtr, parentDataVtr, id, signupOption);
    }
    starLine(66);

}
