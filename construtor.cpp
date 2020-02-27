#include<iostream>
#include<string>
using namespace std;

class infot {
	string name;
	int count;
	public:
		infot(string name) {
			this->name = name;
			count++;
		}
		void play() {
			cout << "the infot" << name << "is playing" <<count<<endl;
		}

};

class car {
	string name;
	infot device;

public:
	car(string name, infot info): device("")  {
		this->name = name;
		device = info;
	}
	void run() {
		device.play();
		cout << "car is in run mode";
	}
};

int main()
{
	infot ent("chad");
	car obj("simp", ent);
	obj.run();
}
