#include <iostream>
#include <exception>
#include<list>
#include<string>
#include<map>
#include<fstream>
#include <sstream>

using namespace std;
#include"Student.h"



static int _ID = 1;
map<int,Student*> students;


void fileRead() {
    ifstream file("students.txt");
        if(file.is_open()) {
                string name;
                string surname;
                string age;
                string email;
                string marks;
                string group;
                while (getline(file, name, ' ') && getline(file, surname, ' ') &&
                       getline(file, email, ' ') &&
                       getline(file, age, ' ') &&
                       getline(file, group, ' ') &&
                       getline(file, marks, '\n')) {
                    Student * newS = (new Student(name, surname, email, stoi(age), group));
                    students[_ID++] = newS;
                    newS->addMarks(marks);
                }
                file.close();
            }
};
void writeFile() {
        ofstream file("students.txt");
        if (file.is_open()) {
                for (auto item : students) {
                    string mark_string = "";
                    for(auto mark:item.second->getMarks()){
                        mark_string+=to_string(mark)+",";
                    }
                    file << item.second->getName() << " ";
                    file << item.second->getSurname() << " ";
                    file << item.second->getEmail() << " ";
                    file << item.second->getAge() << " ";
                    file << item.second->getGroup() << " ";
                    file << mark_string << '\n';
                }
                file.close();
            } else {
                cout << "FIle not opened";
            }
};
void startup(char selection);

void menu_display() {
    cout << "\n\t 1. Create and Append new Student" << endl;
    cout << "\t 2. Show all students" << endl;
    cout << "\t 3. Delete student for key" << endl;
    cout << "\t 4. Delete student for email" << endl;
    cout << "\t 5. File yazmaq" << endl;
    cout << "\t 6. Email daxil edilmis telebeye qiymet elave etmek" << endl;
    cout << "\t 7. Email daxil edilmis telebenin ortalamsi" << endl;
    cout << "\t 0. Exit" << endl;
    
    char selection;
    cin >> selection;
    startup(selection);
}
void startup(char selection) {
    if(selection == '1') {
        bool _check = true;
        while(_check) {
            cout << "Enter name: ";
            cin.ignore();
            string name;
            cin >> name;
            
            cout << "Enter surname: ";
            cin.ignore();
            string surname;
            cin >> surname;
            
            
            cout << "Enter email: ";
            cin.ignore();
            string email;
            cin >> email;
            
            
            cout << "Enter group: ";
            cin.ignore();
            string group;
            cin >> group;
            
            cout << "Enter age: ";
            cin.ignore();
            string age;
            cin >> age;
            try {
                Student * newS = new Student(name,surname,email,stoi(age),group);
                students[_ID++] = newS;
                break;
            }catch(exception &e) {
                cout << e.what();
            }
        }
        menu_display();
    } else if( selection == '2') {
        cout << endl << "Students: " << endl;
        for (int i = 1; i <= students.size(); ++i) {
                students[i]->display();
        }
        cout << endl;
        menu_display();
    }
    else if( selection == '3') {
        bool _bool = true;
        while(_bool) {
            cout << endl;
            int key;
            cout << "Enter key to delete the student: ";
            cin >> key;
            
            int deleted = students.erase(key);
            if(deleted == 0)
                cout << ("Duzgun key daxil edin ");
            else break;
        }
        menu_display();
    }
    else if( selection == '4') {
        bool _bool = true;
        while(_bool) {
            cout << endl;
            string email;
            cout << "Enter email to delete the student: ";
            cin >> email;
            
            for (auto it = students.begin(); it != students.end();++it) {
                    if (it->second->getEmail() == email) {
                        students.erase(it);
                        _bool = false;
                    }
            }
        }
        menu_display();
    }
    else if( selection == '5') {
        writeFile();
        menu_display();
    }
    else if( selection == '6') {
        bool _bool = true;
        while(_bool) {
            cout << endl;
            
            string email;
            cout << "Enter email: ";
            cin >> email;
            
            cin.ignore();
            cout << endl;
            int mark;
            cout << "Enter mark: ";
            cin >> mark;
            
            for (auto it = students.begin(); it != students.end(); it++) {
                    if (it->second->getEmail() == email) {
                        try {
                            it->second->addMark(mark);
                            _bool = false;
                        }catch(exception &e) {
                            cout << e.what();
                        }
                    }
                
            }
        }
        menu_display();
    }
    else if( selection == '7') {
        bool _bool = true;
        while(_bool) {
            cout << endl;
            string email;
            cout << "Enter email to get avg: ";
            cin >> email;
            
            for (auto it = students.begin(); it != students.end();++it) {
                    if (it->second->getEmail() == email) {
                        cout << "Average of this student is: " << it->second->getAvg() << endl;
                        _bool = false;
                    }
            }
        }
        menu_display();
    }
    else if( selection == '0') {
        cout << "Exited the prgram" << endl;
        return;
    }
}

int main() {
    fileRead();
    menu_display();
    return 0;
}
