#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

class Worker {

	static int idCounter;
	int id;
	string name;
	string surname;
	int age;
	int pageCount;

public:

	Worker() {
		id = idCounter++;
		name = "";
		surname = "";
		age = 0;
		pageCount = 0;
	}

	Worker(string name, string surname, int age, int pageCount) {
		id = idCounter++;
		SetName(name);
		SetSurname(surname);
		SetAge(age);
		SetPCount(pageCount);
	}

#pragma region SetGet
	void SetName(string name) {
		this->name = name;
	}
	void SetSurname(string surname) {
		this->surname = surname;
	}
	void SetAge(int age) {
		this->age = age;
	}
	void SetPCount(int pg) {
		this->pageCount = pg;
	}
	string GetName()const {
		return this->name;
	}
	string GetSurname()const {
		return this->surname;
	}
	int GetAge()const {
		return this->age;
	}
	int GetPCount()const {
		return this->pageCount;
	}
#pragma endregion


	void Show() {
		cout << "Id: " << id << "\nName: " << GetName() << "\nSurname: " << GetSurname() << "\nAge: " << GetAge() << "\nPageCount: " << GetPCount() << endl;
	}
};
int Worker::idCounter = 100;

class WorkerQueue {
public:
	vector<Worker> workers;

	bool IsEmpty() const { return workers.empty(); }

	void Push(const Worker worker) {
		workers.push_back(worker);
	}

	void Pop() {
		if (!workers.empty())
			workers.erase(workers.begin());
	}

	Worker& Front() {
		return workers.front();
	}

};

class Printer {
public:
	WorkerQueue queue;

	void AddWorker(const Worker worker) {
		queue.Push(worker);
	}

	void Start() {
		while (!queue.IsEmpty()) {
			Worker worker = queue.Front();
			while (worker.GetPCount() > 0)
			{
				system("cls");
				worker.Show();
				Sleep(1000);
				worker.GetPCount()--;
			}
			queue.Pop();
		}

	}

};

void main() {
	Printer p;
	p.AddWorker(Worker("Rasul", "10Line", 20, 4));
	p.AddWorker(Worker("Nizami", "All", 20, 6));
	p.AddWorker(Worker("Yuhennas", "Yura", 19, 4));
	p.AddWorker(Worker("Enver", "Dream", 14, 10));

	p.Start();
}


