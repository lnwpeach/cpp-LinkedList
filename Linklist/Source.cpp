#include "Header.h"
string line(50, '*');

int mainMenu();
int menuInsert();
int main() {
	List<int> a;
	ListItr<int> b;

	int choose, choose2, number, temp, position;
	do {
		b = a.zeroth();
		choose = mainMenu();
		switch (choose)
		{
		case 1:
			do {
				b = a.zeroth();
				choose2 = menuInsert();
				switch (choose2)
				{
				case 1:
					cout << "Enter Number : ";
					cin >> number;
					a.insert(number, b);
					break;
				case 2:
					cout << "Enter Number : ";
					cin >> number;
					b = a.findback();
					a.insert(number, b);
					break;
				case 3:
					b = a.zeroth();
					cout << "Enter Number : ";
					cin >> number;
					cout << "Enter Position : ";
					cin >> position;
					if (position <= a.findcount()) {
						for (int i = 1; i < position; i++) {
							b.advance();
						}
						a.insert(number, b);
					}
					else
						cout << "---Data not found" << endl;
					// system("pause");
					break;
				default:
					break;
				}
			} while (choose2 != 0);
			break;
		case 2:printList(a);
			// system("pause");
			break;
		case 3:
			cout << line << endl;
			cout << "\tFind Number" << endl;
			cout << line << endl;
			cout << "Enter Number find : ";
			cin >> number;
			cout << line << endl;
			b = a.find(number);

			if (b.retrieve() == 0)
				cout << "\t----Data not Found ----" << endl;
			else
				cout << "\t Position is 1 : " << b.retrieve() << " is element of List" << endl;
			cout << line << endl;
			// system("pause");
			break;
		case 4:
			cout << line << endl;
			cout << "\t\tRemove data form list" << endl;
			cout << line << endl;
			cout << "Enter Number remove : ";
			cin >> number;
			cout << line << endl;
			b = a.find(number);
			temp = b.retrieve();
			if (temp == 0)
				cout << "\t----Data not Found ----" << endl;
			else {
				a.remove(temp);
				cout << "\t Remove : " << temp << " success" << endl;
			}
			cout << line << endl;
			// system("pause");
			break;
		default:
			break;
		}
	} while (choose != 0);
	return 0;
}

int mainMenu() {
	int choice;
	// system("clear");
	cout << line << endl;
	cout << "\tAssignment Linked List" << endl;
	cout << line << endl;
	cout << "\t1. -> Insert Linked List" << endl;
	cout << "\t2. -> Print Linked List " << endl;
	cout << "\t3. -> Find Linked List" << endl;
	cout << "\t4. -> Remove Linked List" << endl;
	cout << "\t0. -> Exit" << endl;
	cout << line << endl;
	cout << "Enter choice : ";
	cin >> choice;
	return choice;
}

int menuInsert() {
	int choice;
	// system("clear");
	cout << line << endl;
	cout << "\tMenu Insert linked List" << endl;
	cout << line << endl;
	cout << "\t1. -> Insert front" << endl;
	cout << "\t2. -> Insert back" << endl;
	cout << "\t3. -> Insert position" << endl;
	cout << "\t0. -> Back Mainmenu" << endl;
	cout << line << endl;
	cout << "Enter your choose : ";
	cin >> choice;
	return choice;
}