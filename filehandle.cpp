#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
class Employee{
	public:
		int empId;
		string name;
		string address;
		Employee(int id, string name, string address){
			empId = id;
			this->name = name;
			this->address = address;
		}
		
		Employee():empId(0),name(""), address(""){
		}
		
		string tostring(){
			string line="";
			string strId = to_string(empId);
			line = strId + ","+name+","+address;
			return line;
			
		}
};

void addnewemp(Employee emp, string csv){
	ofstream file;
	file.open(csv,::ios:app);
	file<<emp.empId<<","<<emp.name<<","<<emp.address<<endl;
	file.close();
}

Employee* getall(string csvfile){
	
	Employee* employee = new Employee[1001];
	ifstream files;
	files.open(csvfile);
	int index = 0;
	string line = "";
	while(files){
		
		getline(files, line);
		stringstream s(line);
		Employee e;
		string word;
		int i=0;
	
		employee[index] = e;
		index++;
	}
	files.close();
	return employee;
}

int main(){
	string file = "D:\kushal 2020 dac\MOCK_DATA.csv";
	Employee* list = getAllEmployees(file);
	for (int i = 0; i < 1050; i++)
		cout << list[i].toString() << endl;
}
