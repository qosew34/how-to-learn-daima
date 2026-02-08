#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>
using namespace std;
struct date {
	int year;
	int month;
	int day;
};
struct book {
	string isbn;
	string title;
	string author;
	string publisher;
	date pubdate;
	double price;
};
vector<book> books;
bool leap(int y) {
	return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}
bool validdate(int y, int m, int d) {
	if (y <= 0 || m < 1 || m > 12 || d < 1) return false;
	int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if (m == 2 && leap(y)) days[2] = 29;
	return d <= days[m];
}
date readdate() {
	date t;
	while (true) {
		char c;
		cin >> t.year >> c >> t.month >> c >> t.day;
		if (validdate(t.year, t.month, t.day)) break;
		cout << "Incorrect date! Please reenter: ";
	}
	return t;
}
void appendbook() {
	book b;
	cout << "     ISBN: ";
	cin >> b.isbn;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "    Title: ";
	getline(cin, b.title);
	cout << "   Author: ";
	getline(cin, b.author);
	cout << "Publisher: ";
	getline(cin, b.publisher);
	cout << " Pub date: ";
	b.pubdate = readdate();
	cout << "    Price: ";
	cin >> b.price;
	books.push_back(b);
}
void printbook(const book& b) {
	cout << left
	<< setw(14) << b.isbn
	<< setw(31) << b.title
	<< setw(21) << b.author
	<< setw(31) << b.publisher
	<< right << setfill('0')
	<< setw(4) << b.pubdate.year << "/"
	<< setw(2) << b.pubdate.month << "/"
	<< setw(2) << b.pubdate.day
	<< setfill(' ')
	<< setw(9) << fixed << setprecision(2) << b.price
	<< "\n";
}
void showbooks() {
	sort(books.begin(), books.end(),
		 [](const book& a, const book& b) {
			 return a.isbn < b.isbn;
		 }
		 );
	cout << "ISBN--------- Title------------------------- Author-------------- Publisher--------------------- Pub-date-- Price---\n";
	for (auto& b : books) {
		printbook(b);
	}
}
void findbook() {
	string title;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Title: ";
	getline(cin, title);
	bool whether = false;
	for (auto& b : books) {
		if (b.title == title) {
			if (!whether) {
				cout << "ISBN--------- Title------------------------- Author-------------- Publisher--------------------- Pub-date-- Price---\n";
			}
			printbook(b);
			whether = true;
		}
	}
	if (whether == false) {
		cout << "Not found!" << endl;
	}
}
/*bool askuserremove() {
string whether;
cout << "Remove(y/n)? ";
getline(cin, whether);
if (whether == "y" || whether == "Y") {
return 1;
}
else if (whether == "n" || whether == "N") {
return 0;
}
else {
return askuserremove();
}
}*/
bool askuserremove() {
	while (true) {
		string whether;
		cout << "Remove(y/n)? ";
		getline(cin >> ws, whether);
		if (whether == "y" || whether == "Y") return true;
		if (whether == "n" || whether == "N") return false;
		cout << "Incorrect answer!\n";
	}
}
void removebook() {
	string isbn;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "ISBN: ";
	getline(cin, isbn);
	bool found = false;
	for (auto it = books.begin(); it != books.end();) {
		if (it->isbn == isbn) {
			found = true;
			if (askuserremove()) {
				it = books.erase(it);
				break;
			}
		} else {
			++it;
		}
	}
	if (!found) {
		cout << "Not found!" << endl;
	}
}
/*bool askusermodify() {
string whether;
cout << "Modify(y/n)? ";
getline(cin, whether);
if (whether == "y" || whether == "Y") {
return 1;
}
else if (whether == "n" || whether == "N") {
return 0;
}
else {
return askusermodify();
}
}*/
bool askusermodify() {
	while (true) {
		string whether;
		cout << "Modify(y/n)? ";
		getline(cin >> ws, whether);
		if (whether == "y" || whether == "Y") return true;
		if (whether == "n" || whether == "N") return false;
		cout << "Incorrect answer!\n";
	}
}
void modifybook() {
	string isbn;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "ISBN: ";
	getline(cin, isbn);
	bool found = false;
	for (auto& b : books) {
		if (b.isbn == isbn) {
			found = true;
			if (askusermodify()) {
				cout << "     ISBN: ";
				cin >> b.isbn;
				cin.ignore();
				cout << "    Title: ";
				getline(cin, b.title);
				cout << "   Author: ";
				getline(cin, b.author);
				cout << "Publisher: ";
				getline(cin, b.publisher);
				cout << " Pub date: ";
				b.pubdate = readdate();
				cout << "    Price: ";
				cin >> b.price;
				break;
			}
		}
	}
	if (!found) {
		cout << "Not found!" << endl;
	}
}
int main() {
	while (true) {
		cout << "Append Find Remove Modify Show Quit > ";
		char cmd;
		cin >> cmd;
		switch (cmd) {
			case 'A': case 'a': appendbook(); break;
			case 'F': case 'f': findbook(); break;
			case 'R': case 'r': removebook(); break;
			case 'M': case 'm': modifybook(); break;
			case 'S': case 's': showbooks(); break;
			case 'Q': case 'q': return 0;
		default:
			cout << "Incorrect choice!\n";
		}
	}
}

