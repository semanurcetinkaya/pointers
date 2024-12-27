#include<iostream>
#include<string>

using namespace std;
//bölüm türlerini tespit eden enum
enum DEPARTMENT {software,computer,informatics};
//öğrenci bilgilerini tutan struct
struct STUDENT {
	string number;
	string name;
	string surname;
	DEPARTMENT dept;
	float average;
};
int main() {
	int numberOfStudents;
	//kaç öğrenci gireceğimizi soruyoruz
	cout << "enter the number of students:";
	cin >> numberOfStudents;
	//dinamik olarak öğrenci dizisini oluşturuyoruz
	STUDENT** students = new STUDENT * [numberOfStudents];
	for (int i = 0;i < numberOfStudents;i++) {
		students[i] = new STUDENT();
	}
	//ÖĞRENCİ BİLGİLERİNİ KULLANICIDAN ALIYORUZ
	for (int i= 0; i < numberOfStudents; i++) {
		cout << "\nEnter details for student" << i + 1 << endl;
		cout << "NUMBER:";
		cin >> students[i]->number;
		cout << "NAME:";
		cin >> students[i]->name;
		cout << "SURNAME:";
		cin >> students[i]->surname;
		int deptID;
		cout << "department (0:software,1:computer,2:informatics):";
		cin >> deptID;
		students[i]->dept = static_cast<DEPARTMENT>(deptID);
		cout << "AVERAGE:";
		cin >> students[i]->average;
	}

	//öğrenci bilgilerini ekrana yazdırıyoruz
	cout << "\nSTUDENT details:\n";
	for (int i = 0;i < numberOfStudents;i++) {
		cout << "\nStudent" << i + 1 << ":" << endl;
		cout << "NUMBER:" << students[i]->number << endl;
		cout << "NAME:" << students[i]->name << endl;
		cout << "SURNAME:" << students[i]->surname << endl;
		//bölüm adını enum değerine göre yazdırıyoruz
		cout << "DEPARTMENT:";
		if (students[i]->dept == software)
			cout << "software";
		else if (students[i]->dept == computer)
			cout << "computer";
		else if (students[i]->dept == informatics)
			cout << "informatics";
		cout << endl; 
		cout << "average:" << students[i]->average << endl;
	}
	//belleği serbest bırakıyoruz
	for (int i = 0;i < numberOfStudents;i++) {
		delete students[i];
	}
	delete[] students;
	return 0;



}