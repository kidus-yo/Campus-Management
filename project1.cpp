#include <iostream>     //preprocessor directives
#include <string>
using namespace std;

//Global Arrays to be accessed everywhere
int ID[150];
string name[150];
string department[150];
string title[150];
string author[150];
int quantity[150];
int bookID[150];
int borrowerID[150];
string borrowerName[150];
int borrowedID[150];
string status[150];
string course[150];
int courseID[150];
double score[150];

//Counters variables that can be accessed globally 
int studentCount = 0;
int bookCount = 0;
int lendCount = 0;
int attendanceCount = 0;
int registrationCount = 0;
int gradeCount = 0;

int main (){

int choice = 0;

while(choice != 7){
//Main menu 
cout << "==Campus Management Portal=="<<endl;
cout << "1. Student Management"<<endl;
cout << "2. Library Management"<<endl;
cout << "3. Attendance Management"<<endl;
cout << "4. Course Registration"<<endl;
cout << "5. Grade Management"<<endl;
cout << "6. Show Students Information"<<endl;
cout << "7. Exit"<<endl;

cout << "Enter your choice: ";
cin >> choice;

//Student Management
if(choice == 1){

int studentChoice = 0;

while(studentChoice != 5){
 //Main menu for the student Managment system
cout<<"--Welcome to the Student Management System--"<<endl;
cout << "1. Add Student"<<endl;
cout << "2. Update Student"<<endl;
cout << "3. Delete Student"<<endl;
cout << "4. Search Student"<<endl;
cout << "5. Exit"<<endl;

cout << "Enter your choice: ";
cin >> studentChoice;

//Add Student
if(studentChoice == 1){

cout << "Enter Name: ";
cin >> name[studentCount];

cout << "Enter ID: ";
cin >> ID[studentCount];

cout << "Enter Department: ";
cin >> department[studentCount];

studentCount++;

cout << "Student Added Successfully!"<<endl;
}

//Update Student
else if(studentChoice == 2){

int searchID;
bool found = false;

cout << "Enter Student ID to update: ";
cin >> searchID;

for(int i = 0; i < studentCount; i++){

if(ID[i] == searchID){

found = true;

cout << "Enter New Name: ";
cin >> name[i];

cout << "Enter New Department: ";
cin >> department[i];

cout << "Student Updated Successfully!"<<endl;
}
}

if(found == false){
cout << "Student Not Found!"<<endl;
}
}

//Delete Student
else if(studentChoice == 3){

int deleteID;
bool found = false;

cout << "Enter Student ID to delete: ";
cin >> deleteID;

for(int i = 0; i < studentCount; i++){

if(ID[i] == deleteID){

found = true;
//loop to delete
for(int j = i; j < studentCount - 1; j++){

ID[j] = ID[j + 1];
name[j] = name[j + 1];
department[j] = department[j + 1];
}

studentCount--;

cout << "Student Deleted Successfully!"<<endl;

break;
}
}

if(found == false){
cout << "Student Not Found!"<<endl;
}
}

//Search Student
else if(studentChoice == 4){

int searchID;
bool found = false;

cout << "Enter Student ID to search: ";
cin >> searchID;

for(int i = 0; i < studentCount; i++){

if(ID[i] == searchID){

found = true;

cout << "Name: "<<name[i]<<endl;
cout << "ID: "<<ID[i]<<endl;
cout << "Department: "<<department[i]<<endl;
}
}

if(found == false){
cout << "Student Not Found!"<<endl;
}
}
}
}

//Library Management
else if(choice == 2){

int libraryChoice = 0;

while(libraryChoice != 5){

cout <<"==Welcome to the Library Management System=="<<endl;
cout << "1. Add Book"<<endl;
cout << "2. Search Book"<<endl;
cout << "3. Delete Book"<<endl;
cout << "4. Lend Book"<<endl;
cout << "5. Exit"<<endl;

cout << "Enter your choice: ";
cin >> libraryChoice;

//Add Book
if(libraryChoice == 1){

cout << "Enter Book Title: ";
cin >> title[bookCount];

cout << "Enter Book ID: ";
cin >> bookID[bookCount];

cout << "Enter Author Name: ";
cin >> author[bookCount];

cout << "Enter Quantity: ";
cin >> quantity[bookCount];

bookCount++;

cout << "Book Added Successfully!"<<endl;
}

//Search Book
else if(libraryChoice == 2){

int searchBook;
bool found = false;

cout << "Enter Book ID: ";
cin >> searchBook;

for(int i = 0; i < bookCount; i++){

if(bookID[i] == searchBook){

found = true;

cout << "Title: "<<title[i]<<endl;
cout << "Author: "<<author[i]<<endl;
cout << "Quantity: "<<quantity[i]<<endl;
}
}

if(found == false){
cout << "Book Not Found!"<<endl;
}
}

//Delete Book
else if(libraryChoice == 3){

int deleteID;
bool found = false;

cout << "Enter Book ID to delete: ";
cin >> deleteID;

for(int i = 0; i < bookCount; i++){

if(bookID[i] == deleteID){

found = true;

for(int j = i; j < bookCount - 1; j++){

bookID[j] = bookID[j + 1];
title[j] = title[j + 1];
author[j] = author[j + 1];
quantity[j] = quantity[j + 1];
}

bookCount--;

cout << "Book Deleted Successfully!"<<endl;

break;
}
}

if(found == false){
cout << "Book Not Found!"<<endl;
}
}

//Lend Book
else if(libraryChoice == 4){

int lendID;
bool found = false;

cout << "Enter Student ID: ";
cin >> borrowerID[lendCount];

cout << "Enter Student Name: ";
cin >> borrowerName[lendCount];

cout << "Enter Book ID: ";
cin >> lendID;

for(int i = 0; i < bookCount; i++){

if(bookID[i] == lendID){

found = true;

if(quantity[i] > 0){

quantity[i]--;

borrowedID[lendCount] = lendID;

lendCount++;

cout << "Book Lent Successfully!"<<endl;
}

else{
cout << "Book Out Of Stock!"<<endl;
}
}
}

if(found == false){
cout << "Book Not Found!"<<endl;
}
}
}
}

//Attendance Management
else if(choice == 3){

int attendanceChoice = 0;

while(attendanceChoice != 6){

cout << "==Welcome to the Attendance Management System=="<<endl;
cout << "1. Add Attendance"<<endl;
cout << "2. Show Attendance"<<endl;
cout << "3. Update Attendance"<<endl;
cout << "4. Delete Attendance"<<endl;
cout << "5. Attendance Report"<<endl;
cout << "6. Exit"<<endl;

cout << "Enter your choice: ";
cin >> attendanceChoice;

//Add Attendance
if(attendanceChoice == 1){

cout << "Enter Student Name: ";
cin >> name[attendanceCount];

cout << "Enter Student ID: ";
cin >> ID[attendanceCount];

cout << "Enter Status(Present/Absent): ";
cin >> status[attendanceCount];

attendanceCount++;

cout << "Attendance Added Successfully!"<<endl;
}

//Show Attendance
else if(attendanceChoice == 2){

int searchID;
bool found = false;

cout << "Enter Student ID: ";
cin >> searchID;

for(int i = 0; i < attendanceCount; i++){

if(ID[i] == searchID){

found = true;

cout << "Name: "<<name[i]<<endl;
cout << "Status: "<<status[i]<<endl;
}
}

if(found == false){
cout << "Student Not Found!"<<endl;
}
}

//Update Attendance
else if(attendanceChoice == 3){

int updateID;
bool found = false;

cout << "Enter Student ID: ";
cin >> updateID;

for(int i = 0; i < attendanceCount; i++){

if(ID[i] == updateID){

found = true;

cout << "Enter New Status: ";
cin >> status[i];

cout << "Attendance Updated!"<<endl;
}
}

if(found == false){
cout << "Student Not Found!"<<endl;
}
}

//Delete Attendance
else if(attendanceChoice == 4){

int deleteID;
bool found = false;

cout << "Enter Student ID: ";
cin >> deleteID;

for(int i = 0; i < attendanceCount; i++){

if(ID[i] == deleteID){

found = true;

for(int j = i; j < attendanceCount - 1; j++){

ID[j] = ID[j + 1];
name[j] = name[j + 1];
status[j] = status[j + 1];
}

attendanceCount--;

cout << "Attendance Deleted Successfully!"<<endl;

break;
}
}

if(found == false){
cout << "Student Not Found!"<<endl;
}
}

//Attendance Report
else if(attendanceChoice == 5){

for(int i = 0; i < attendanceCount; i++){

cout << "Name: "<<name[i]<<endl;
cout << "ID: "<<ID[i]<<endl;
cout << "Status: "<<status[i]<<endl;
cout << "-------------------"<<endl;
}
}
}
}

//Course Registration
else if(choice == 4){

int courseChoice = 0;

while(courseChoice != 6){
//Main Menu for the course registration system
cout << "==Welcome to the Course Registration System=="<<endl;
cout << "1. Add Course"<<endl;
cout << "2. Display Registration"<<endl;
cout << "3. Exit"<<endl;

cout << "Enter your choice: ";
cin >> courseChoice;

//Add Course
if(courseChoice == 1){

cout << "Enter Student Name: ";
cin >> name[registrationCount];

cout << "Enter Student ID: ";
cin >> ID[registrationCount];

cout << "Enter Course Name: ";
cin >> course[registrationCount];

cout << "Enter Course ID: ";
cin >> courseID[registrationCount];

registrationCount++;

cout << "Course Registered Successfully!"<<endl;
}

//Display Registration
else if(courseChoice == 2){

for(int i = 0; i < registrationCount; i++){

cout << "Name: "<<name[i]<<endl;
cout << "ID: "<<ID[i]<<endl;
cout << "Course: "<<course[i]<<endl;
cout << "Course ID: "<<courseID[i]<<endl;
cout << "-------------------"<<endl;
}
}
}
}

//Grade Management
else if(choice == 5){

int gradeChoice = 0;

while(gradeChoice != 5){
//Main Menu for the Grade Managment System
cout << "==Welcome to the Grade Management System=="<<endl;
cout << "1. Add Grade"<<endl;
cout << "2. Grade Report"<<endl;
cout << "3. Exit"<<endl;

cout << "Enter your choice: ";
cin >> gradeChoice;

//Add Grade
if(gradeChoice == 1){

cout << "Enter Student Name: ";
cin >> name[gradeCount];

cout << "Enter Student ID: ";
cin >> ID[gradeCount];

cout << "Enter Score: ";
cin >> score[gradeCount];

if(score[gradeCount] >= 85){
cout << "Grade = A"<<endl;
}

else if(score[gradeCount] >= 70){
cout << "Grade = B"<<endl;
}

else if(score[gradeCount] >= 60){
cout << "Grade = C"<<endl;
}

else if(score[gradeCount] >= 50){
cout << "Grade = D"<<endl;
}

else{
cout << "Grade = F"<<endl;
}

gradeCount++;
}

//Grade Report
else if(gradeChoice == 2){

for(int i = 0; i < gradeCount; i++){

cout << "Name: "<<name[i]<<endl;
cout << "ID: "<<ID[i]<<endl;
cout << "Score: "<<score[i]<<endl;
cout << "-------------------"<<endl;
}
}
}
}

//Show Students Information
else if(choice == 6){

for(int i = 0; i < studentCount; i++){

cout << "Name: "<<name[i]<<endl;
cout << "ID: "<<ID[i]<<endl;
cout << "Department: "<<department[i]<<endl;
cout << "-------------------"<<endl;
}
}

else if(choice != 7){

cout << "Please Enter A Valid Number!"<<endl;
}
}

cout << "Program Ended Successfully!"<<endl;

return 0;
}

/*
   Members:
    1. Kidus Yonas UGR/7375/18
    2. Eldana Getachew UGR/9112/18
    3. Hlina Teklemariam UGR/5555/18
    4. Eyasu Mathewos UGR/7181/18
    5. Gemechis Girma UGR 8646/18
*/