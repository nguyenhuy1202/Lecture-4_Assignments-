#include <iostream>
#include <map>
#include <string>
#include <sstream>

struct Student {
    int ID;
    std::string Name;
    std::string Class;
};

class University {
public:
    void Insert(int ID, std::string Name, std::string Class) {
        Student newStudent = {ID, Name, Class};
        students[ID] = newStudent;
    }

    void Delete(int ID) {
        students.erase(ID);
    }

    std::string Infor(int ID) {
        if (students.find(ID) != students.end()) {
            return students[ID].Name + "," + students[ID].Class;
        } else {
            return "NA,NA";
        }
    }

private:
    std::map<int, Student> students;
};

int main() {
    University university;
    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::string command;
        iss >> command;
        if (command == "Insert") {
            int ID;
            char comma;
            std::string Name, Class;
            iss.ignore(1); // ignore the opening parenthesis
            iss >> ID >> comma >> Name >> comma >> Class;
            Class.pop_back(); // remove the closing parenthesis from the Class string
            university.Insert(ID, Name, Class);
        } else if (command == "Delete") {
            int ID;
            iss.ignore(1); // ignore the opening parenthesis
            iss >> ID;
            university.Delete(ID);
        } else if (command == "Infor") {
            int ID;
            iss.ignore(1); // ignore the opening parenthesis
            iss >> ID;
            std::cout << university.Infor(ID) << std::endl;
        }
    }
    return 0;
}
