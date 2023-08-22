#pragma once
class Student {
private:
    string name;
    string surname;
    string email;
    int age;
    string group;
    list<int> marks;
    
public:
    string getName() const {
        return name;
    }
    string getSurname() const {
        return surname;
    }
    string getEmail() const {
        return email;
    }
    string getGroup() const {
        return group;
    }
    int getAge() const {
        return age;
    }
    list<int> getMarks() const {
        return marks;
    }
    void displayMarks() const{
        for(int mark : marks) {
                cout << mark <<", ";
            }
    }
    
    void setName(string data) {
        if(data.length()>0)
            name = data;
        else throw(invalid_argument("Bos qala bilmez name."));
    }
    
    void setSurname(string data) {
        if(data.length()>0)
            surname = data;
        else throw(invalid_argument("Bos qala bilmez surname."));
    }
    
    
    void setEmail(string data) {
        if(data.length()>0 && data.find("@itstep.edu.az") != -1)
            email = data;
        else throw(invalid_argument("Bos qala bilmez email ve @itstep.edu.az icermelidir"));
    }
    
    
    void setAge(int data) {
        if(data>=18)
            age = data;
        else throw(invalid_argument("yas 18 den asagi ola bilmez."));
    }
    
    
    void setGroup(string data) {
        if(data.length()>0)
            group = data;
        else throw(invalid_argument("Bos qala bilmez group."));
    }
    void display() const {
        cout << endl << "Name: " << name;
        cout << endl << "Surname: " << surname;
        cout << endl << "Email: " << email;
        cout << endl << "Age: " << age;
        cout << endl << "Group: " << group;
        cout << endl << "Marks:" << endl;
        displayMarks();
    }
    void addMark(int mark) {
        if(mark >= 0 && 12>=mark){
            marks.push_back(mark);
            return;
        }
        throw invalid_argument("MArk 0-12 araliginda olmalidir");
    }
    double getAvg() const {
        double sum = 0;
        double average = 0;
        if (!marks.empty()) {
            for(auto item:marks) {
                sum+=item;
            }
            average = sum/marks.size();
        }
        return average;
    }
    void addMarks(string str) {
            stringstream ss(str);
            string item;
            while (getline(ss, item, ',')) {
                marks.push_back(stoi(item));
            }
        }
    Student() = delete;
    Student(string _name, string _surname, string _email, int _age, string _group) {
        setName(_name);
        setSurname(_surname);
        setEmail(_email);
        setAge(_age);
        setGroup(_group);
    }
};
