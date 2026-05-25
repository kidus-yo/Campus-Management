#include <iostream>
#include <string>
using namespace std;

//Function declerations
void studentManagment();
void libraryManagment();
void attendanceManagment();
void courseRegistration();
void gradeManagment();
void showStudent();


//Global Counters and arrys
int ID[150];
string name[150];
string department[150];
string title[150];
int quantity[150];
string author[150];
int bookID[150];
int borrowerID[150];
string borrowerName[150];
int borrowedID[150];
string status[150];
string course[150];
int courseID[150];
double score[150];
int lendCount = 0;
int attendanceCount = 0;
int registrationCount = 0;
int gradeCount = 0;
int studentCount = 0;
int bookCount = 0;


//Main Function 
int main (){

int choice; //intilization

while(choice != 7){

    //Main menu 
cout << "==Campus Management Portal=="<<endl;
cout << "1. Student Managment"<<endl;
cout << "2. Library Managment"<<endl;
cout << "3. Attendance Management"<<endl;
cout << "4. Course Registration"<<endl;
cout << "5. Grade Managment"<<endl; 
cout << "6. Show Students information"<<endl;
cout << "7. Exit"<<endl;

cout<< "Please Enter your choice: ";
cin>> choice;

//Calling function based on user choice
if(choice == 1){
    studentManagment();
}
else if(choice == 2){
    libraryManagment();
}
else if(choice == 3){
    attendanceManagment();
}
else if(choice == 4){
    courseRegistration();
}
else if(choice == 5){
    gradeManagment();
}
else if(choice == 6){
    showStudent();
}
else{
    cout<< "Please Enter a valid number"<<endl;
}
}
    return 0;  //Exit code Fucntion
}
//Student Managment Function
void studentManagment(){ 

    int choice;

while(choice != 5){

    //Main menu for student Managmnet System
cout<<"--Welcome to the Student Managment System--"<<endl;
cout << "1. Add a Student"<<endl;
cout << "2. Update Student"<<endl;
cout << "3. Delete Student"<<endl;
cout << "4. Search Student"<<endl;
cout << "5. Exit"<<endl;
 
cout << "Please Enter your choce: ";
cin>> choice;
cout << endl;

//Add Student
if(choice == 1){
    cout<<"Name: ";
   cin>>name[studentCount];
    cout<<"ID: ";
    cin>> ID[studentCount];
    cout << "Department: ";
    cin>> department[studentCount];

    studentCount++;
}
//Update Student
else if(choice == 2){
  int searchID;
  bool found = false;

cout << "Enter the ID of the student you want to update: ";
cin >> searchID;

for(int i = 0; i < studentCount; i++){
    if(searchID == ID[i]){
        found = true;
        cout << "Enter a new name: ";
        cin >> name[i];
       cout << "Enter new Department: ";
       cin>> department[i];

       cout<< "Student Updated Successfully!"<<endl;
    }
}

}
//Delete Student
else if(choice == 3){
 int deleteID;
 bool found = false;

 cout << "Enter the ID of the student you want to delete: ";
 cin >> deleteID;

 for(int i = 0; i < studentCount; i ++){
    if(ID[i] == deleteID){
        found = true;
        for(int j = i ; j < studentCount - 1; j++){
            ID[j] = ID[j + 1];
            name[j] = name[j + 1];
            department[j] = department[j + 1];
        }
        studentCount--;
        break;
}
    
 }
 cout<< "Student Deleted Successfully!"<<endl;
}

//Search Student 
else if(choice == 4){
int searchID;
bool found = false;

cout << "Enter the ID of the student you want to search: ";
cin >> searchID;

for(int i = 0; i < studentCount; i++){
    if(ID[i] == searchID){
        found = true;
         cout <<"Name: "<< name[i]<<endl;
         cout<< "ID: "<< ID[i]<<endl;
         cout << "department: "<< department[i]<<endl;
    }
}
if(found == false){
    cout << "Student not found!"<<endl;
}
}
}
}
//Library Managmnet Function
void libraryManagment(){
int choice;


while(choice != 5){

cout <<"==Welcome to the Library Managment Sysyem=="<<endl;
cout << "1. Add a book"<<endl;
cout << "2. Search book"<<endl;
cout << "3. Delete book"<<endl;
cout << "4. Lend Book"<<endl;
cout << "5. Exit"<<endl;

cout << "Please Enter your choice: ";
cin>> choice;

//Add Book 
if(choice == 1){
    cout << "Enter the title of the book you want to add: ";
    cin >> title[bookCount];
    cout << "Enter the ID of the book: ";
    cin >> bookID[bookCount];
    cout << "The author of the book: ";
    cin >> author[bookCount];
    cout << "Enter the quantity you want to add: ";
    cin >> quantity[bookCount];
    bookCount++;

    cout << "Book added Successfully"<<endl;
}
//Search Book 
else if(choice == 2){
int searchBook;
bool found = false;

cout << "Enter the ID of the book you want to search: ";
cin >> searchBook;
//
for(int i = 0; i < bookCount; i ++ ){
    if(bookID[i] == searchBook){
         found = true;
        cout << "Title: "<< title[i]<<endl;
        cout<<  "Author: "<<author[i]<<endl;
        cout << "Quantity "<<quantity[i]<<endl;
    }
 
}
 if(found == false){
        cout << "Book not found!"<<endl;
    }
}

//Delete Book 
else if(choice == 3){
int deleteID;
cout << "Enter the ID of the book you want to delete: ";
cin>> deleteID;
bool found = false;

for(int i = 0; i < bookCount; i++){
    if(bookID[i] == deleteID){
        found = true;
       
       //Shift Book Records
        for(int j = i; j < bookCount - 1; j++){
            bookID[j] = bookID[ j + 1 ];
            title[j] = title[j + 1];
            author[j] = author[j + 1];
            quantity[j] = quantity[ j + 1];
        }
        bookCount--;
    }
    
}
  if(found == false){
        cout << "ID NOT FOUND!"<<endl;
    }
cout << "Book Deleted Successfully!"<<endl;
}
//Lend Book 
else if(choice ==4){
    int lendID;
    bool found = false;

cout << "Enter Student ID: ";
cin >> borrowerID[lendCount];
cout << "Enter Student Name: ";
cin >> borrowerName[lendCount];
cout << "Enter Book ID to lend: ";
cin>>lendID;

for(int i = 0; i < bookCount; i++){
    if(bookID[i] == lendID){
        found = true;
        if(quantity[i] > 0){
            quantity[i]--;
            borrowedID[lendCount] = lendID;
            lendCount++;
        cout << "Book Lent Successfullt!"<<endl;
        }
        else{
            cout << "Book out of number"<<endl;
        }
         
    }
    
}
 if(found == false){
        cout << "Book not Found"<<endl;
    }
}      
}
}
//Attendance Managment Function
void attendanceManagment(){
    int choice;

while(choice != 6){
cout << "==Welcome to the Attendance managment system=="<<endl;
cout << "1. Add attendance"<<endl;
cout << "2. Show attendance"<<endl;
cout << "3. Update Attendance"<<endl;
cout << "4. Delete Attendance"<<endl;
cout << "5. Attendace Report"<<endl;
cout << "6. Exit"<<endl;

cout<< "Please Enter your choice: ";
cin >> choice;
 
//Add Attendance
if(choice == 1){
    cout << "Enter the name of the student: ";
    cin >> name[attendanceCount];
    cout << "Enter the ID of the student: ";
    cin >> ID[attendanceCount];
    cout << "Enter Status of the student(Present/Abscent): ";
    cin >> status[attendanceCount];
    attendanceCount++;
    cout << "Attendace added Successfully!"<<endl;
}

//Show Attendace
else if(choice == 2){
int attendanceID;
bool found = false;

cout << "Please Enter the ID of the studednt: ";
cin>> attendanceID;

for(int i = 0; i < attendanceCount; i++){
    if(ID[i] == attendanceID){
        found = true;
        cout<< "Name: "<<name[i]<<endl;
        cout <<"Status of the student: "<<status[i]<<endl;
    }
}
if(found == false){
    cout <<"ID NOT FOUND!"<<endl;
}
}
//Update Attendnce
else if(choice == 3){
  int updID;
  bool found = false;

  cout<< "Enter the ID of the student you want to update: ";
  cin>>updID;

  for(int i = 0; i < attendanceCount; i++){
    if(ID[i] == updID){
        found = true;
        cout << "Enter a new name: ";
        cin>> name[i];
        cout<< "Enter a new Status(presnet/abscent): ";
        cin>>status[i];
    }
   
  }
  if(found == false){
        cout << "Student Not Found!"<<endl;
    }
}
//Delete Attendance
else if (choice == 4){ 
int removeID;
bool found = false;

cout << "Enter the ID of the student you want to delete: ";
cin>> removeID;
for(int i = 0; i < attendanceCount; i++){
    if(ID[i] == removeID){
        bool found = true;
        for(int j = i; j < attendanceCount - 1; j++){
            ID[j] = ID[j + 1];
            name[j] = name[j + 1];
            status[j] = status[j + 1];
        }
        attendanceCount--;
    }
}
if(found == false){
    cout << "ID NOT FOUND!"<<endl;
}
cout<< "Student Deleted Succesfully"<<endl;
}
//Attendance Report
else if(choice == 5){
for(int i = 0; i < attendanceCount; i++){
    cout <<"Name: "<<name[i]<<endl;
    cout <<"ID: "<<ID[i]<<endl;
    cout << "Status(present/abscent): "<< status[i] <<endl;

}
}
else{
    cout<< "Please Enter a valid number"<<endl;
}
}
}
//Course Registration Function 
void courseRegistration (){
    int choice;
 
    while(choice != 6){
//MAin Menu Function for course registration  
 cout << "==Welcome to the Course Registration System=="<<endl;
 cout << "1. Add Course"<<endl;
 cout << "2. Drop Course"<<endl;
 cout << "3. Display registration"<<endl;
 cout << "4. Search Registration"<<endl;
 cout << "5. Update Registration"<<endl;
 cout << "6. Exit"<<endl;

 cout<<"Please Enter your choice: ";
 cin >> choice;

 //Add Course Registration
 if(choice == 1){
    cout <<"Enter the name of the student: ";
    cin >> name[registrationCount];
    cout << "Enter an ID: ";
    cin >> ID[registrationCount];
    cout << "Enter the course name you want to register: ";
    cin >> course[registrationCount];
    cout << "Enter Course ID: ";
    cin>>courseID[registrationCount];
    registrationCount++;
 }
 //Drop Course Registration
 else if(choice == 2){
   int dropID;
   bool found = false;
   
   cout<< "Enter the ID of the student: ";
   cin>>dropID;
   
   for(int i = 0; i < registrationCount; i++){
     if(dropID == ID[i]){
         found = true;
        for(int j = i; j < registrationCount - 1; j++){
             
             course[j] = course[j+1];
             courseID[j] = courseID[j+1]; 
        }
        registrationCount--;
     }
    
   }
     if(found == false){
        cout<<"ID Not Found!"<<endl;
     }
   cout<<"Course deleted Successfully!"<<endl;
 }
 //Display Course Registration
 else if (choice == 3){
  for(int i = 0; i < registrationCount; i++){
    cout << "Name: "<<name[i]<<endl;
    cout << "ID: "<<ID[i]<<endl;
    cout << "Course Name: "<<course[i]<<endl;
    cout << "Course ID: "<<courseID[i]<<endl;
}
 }
 //Search Course Registration
else if(choice == 4){
  int searchID;
  bool found = false;

  cout << "Enter the ID of the student: ";
  cin>> searchID;

  for(int i = 0; i < registrationCount; i ++ ){
    if(ID[i] == searchID){
        found = true;
      cout<< "Name: "<<name[i]<<endl;
      cout << "ID: "<<ID[i]<<endl;
      cout<< "Course Name: "<<course[i]<<endl;
      cout<< "Course ID: "<<courseID[i]<<endl; 
    }
 
  }
    if(found == false){
        cout<<"ID Not Found!"<<endl;
     }
}
//Update Course Registration
else if (choice == 5){
    int updID;

    cout << "Enter the ID of the student: ";
    cin>>updID;
    bool found = false;

    for(int i = 0; i < registrationCount; i ++){
        if(ID[i] == updID){
            found = true;
            cout << "Enter a new Course Name: ";
            cin >> course[i];
            cout << "Enter a new Course ID: ";
            cin >> courseID[i];
        }
        
    }
      if (found == false){
          cout<<"ID Not Found"<<endl;
        }
}
else{
cout << "Please enter a valid number"<<endl;
}
}
}
//Grade Managment Function
void gradeManagment(){
    int choice;
   

    while(choice != 5){
    //Main menu for Grade managment 
cout << "==Welcome to the Grade Managment System=="<<endl;
cout << "1. Add Grade"<<endl;
cout << "2. Upadate Grade"<<endl;
cout << "3. Remove Grade"<<endl;
cout << "4. Grade Report"<<endl;
cout << "5. Exit"<<endl;

cout << "Please Enter your choice: ";
cin>> choice;
//Add Grade
if(choice == 1){
        cout << "Enter the Name of the Student: ";
        cin>> name[gradeCount];
        cout << "Enter StudentID: ";
        cin >> ID[gradeCount];
        cout<<"Enter the grade of the Student: ";
        cin>> score[gradeCount];

        if((score[gradeCount] >= 85) && (score[gradeCount] <=100)){
        cout << "Grade = A"<<endl;
    } 
    else if((score[gradeCount] >=80) &&(score[gradeCount] < 85)){
        cout << "Grade = A-" <<endl;
    }
    else if ((score[gradeCount] >= 70) && (score[gradeCount] < 80)){
        cout << "Grade = B" <<endl;
    }
    else if ((score[gradeCount] >= 60) && (score[gradeCount] < 70)){
        cout << "Grade = C"<<endl;
    }
    else if ((score[gradeCount] >= 50) && (score[gradeCount] < 60)){
        cout << "Grade = D"<<endl;
    } 
    else if ((score[gradeCount] >=0 ) && (score[gradeCount] < 50)){
        cout << "Grade = F"<<endl;
    }
    else {
        cout << "Something went wrong!"<<endl;
    }
    gradeCount++;
   }
   //Update Grade
else if(choice == 2){
int updID;
cout << "Enter the ID of Student you want to update: ";
cin >> updID;
bool found = false;

for(int i = 0; i < gradeCount; i++){
    if(ID[i] == updID){
         found = true;
        cout << "Enter a new Grade: ";
        cin>>score[i];

        if((score[i] >= 85) && (score[i] <=100)){
        cout << "Grade = A"<<endl;
    } 
    else if((score[i] >=80) &&(score[i] < 85)){
        cout << "Grade = A-" <<endl;
    }
    else if ((score[i] >= 70) && (score[i] < 80)){
        cout << "Grade = B" <<endl;
    }
    else if ((score[i] >= 60) && (score[i] < 70)){
        cout << "Grade = C"<<endl;
    }
    else if ((score[i] >= 50) && (score[i] < 60)){
        cout << "Grade = D"<<endl;
    } 
    else if ((score[i] >=0 ) && (score[i] < 50)){
        cout << "Grade = F"<<endl;
    }
    else {
        cout << "Something went wrong!"<<endl;
    }
    }

 }
   if(found == false ){
    cout << "ID not Found!"<<endl;
}
}
//Delete Grade
else if(choice == 3){
   int deleteID;
   bool found = false;

   cout << "Enter the ID of student: ";
   cin>> deleteID;

   for (int i = 0; i < gradeCount; i++){
      if(ID[i] == deleteID){
         found = true;
         for(int j = i; j < gradeCount - 1; j++){
            score[j] = score[j+1];
         }
         gradeCount--;
      }
    
   }
 if(found == false){
    cout<< "ID NOT FOUND!"<<endl;
      }
   cout << "Deleted Successfully!"<<endl;
}
//Grade Report  
else if(choice == 4){ 
    for(int i = 0; i < gradeCount; i++){
        cout << "Name: "<<name[i]<<endl;
        cout << "ID: "<<ID[i]<<endl;
        cout << "Score: "<<score[i]<<endl;
    }
}
else{
    cout << "Please enter a valid number"<<endl;
} 
}
}
 
//show Student Function
void showStudent(){
  //Loop to Show every Students
    for(int i = 0; i < studentCount; i++){
        cout << "Name: "<<name[i]<<endl;
        cout << "ID: "<<ID[i]<<endl;
        cout << "Department: "<<department[i]<<endl;
    }
    cout << "____________________________"<<endl;
}


/*
Members
 1. Kidus Yonas UGR/7375/18
 2. Eldana Getachew UGR/9112/18 
 3. Hlina Teklemariam UGR/5555/18
 4. Gemechis Girma UGR 8646/18
 5. 
*/

//6/25/2026