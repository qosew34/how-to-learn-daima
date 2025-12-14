#include <bits/stdc++.h>
using namespace std;

struct Book {
    string isbn;
    string title;
    string author;
    string publisher;
    int year;
    int month;
    int day;
    double price;
};

bool is_leap(int y){
    return (y%4==0 && y%100!=0) || (y%400==0);
}

bool valid_date_components(int y,int m,int d){
    if(m<1 || m>12) return false;
    if(d<1) return false;
    int mdays[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(m==2){
        int lim = 28 + (is_leap(y)?1:0);
        return d<=lim;
    }
    return d<=mdays[m];
}

bool parse_date(const string &s,int &y,int &m,int &d){
    stringstream ss(s);
    string a,b,c;
    if(!getline(ss,a,'/')) return false;
    if(!getline(ss,b,'/')) return false;
    if(!getline(ss,c)) return false;
    try{
        y = stoi(a);
        m = stoi(b);
        d = stoi(c);
    }catch(...){
        return false;
    }
    return valid_date_components(y,m,d);
}

string format_date(int y,int m,int d){
    char buf[32];
    sprintf(buf, "%04d/%02d/%02d", y, m, d);
    return string(buf);
}

string trim_right(string s){
    while(!s.empty() && (s.back()=='\r' || s.back()=='\n')) s.pop_back();
    return s;
}

void show_header(){
    cout << "ISBN--------- Title------------------------- Author-------------- Publisher--------------------- Pub-date-- Price---" << "\n";
}

void show_books(const vector<Book>& books){
    vector<Book> v = books;
    sort(v.begin(), v.end(), [](const Book& a,const Book& b){ return a.isbn < b.isbn; });
    show_header();
    for(const auto &b: v){
        cout << left << setw(13) << b.isbn << " ";
        cout << left << setw(30) << (b.title.size()<=30?b.title:b.title.substr(0,30)) << " ";
        cout << left << setw(20) << (b.author.size()<=20?b.author:b.author.substr(0,20)) << " ";
        cout << left << setw(30) << (b.publisher.size()<=30?b.publisher:b.publisher.substr(0,30)) << " ";
        cout << format_date(b.year,b.month,b.day) << " ";
        cout << right << setw(8) << fixed << setprecision(2) << b.price << "\n";
    }
}

Book input_book(){
    Book b;
    string line;
    cout << "     ISBN: ";
    getline(cin, line);
    line = trim_right(line);
    b.isbn = line;
    cout << "    Title: ";
    getline(cin, line);
    line = trim_right(line);
    if((int)line.size() > 30) line = line.substr(0,30);
    b.title = line;
    cout << "   Author: ";
    getline(cin, line);
    line = trim_right(line);
    if((int)line.size() > 20) line = line.substr(0,20);
    b.author = line;
    cout << "Publisher: ";
    getline(cin, line);
    line = trim_right(line);
    if((int)line.size() > 30) line = line.substr(0,30);
    b.publisher = line;
    while(true){
        cout << " Pub date: ";
        getline(cin, line);
        line = trim_right(line);
        int y,m,d;
        if(parse_date(line,y,m,d)){
            b.year=y; b.month=m; b.day=d;
            break;
        }else{
            while(true){
                cout << "Incorrect date! Please reenter: ";
                getline(cin,line);
                line = trim_right(line);
                int yy,mm,dd;
                if(parse_date(line,yy,mm,dd)){
                    b.year=yy; b.month=mm; b.day=dd;
                    goto date_ok;
                }
            }
        }
    }
date_ok:;
    cout << "    Price: ";
    getline(cin, line);
    line = trim_right(line);
    try{
        b.price = stod(line);
    }catch(...){
        b.price = 0.0;
    }
    return b;
}

int find_by_isbn(const vector<Book>& books,const string &isbn){
    for(size_t i=0;i<books.size();++i) if(books[i].isbn==isbn) return (int)i;
    return -1;
}

vector<Book> find_by_title(const vector<Book>& books,const string &title){
    vector<Book> res;
    for(const auto &b: books) if(b.title==title) res.push_back(b);
    sort(res.begin(), res.end(), [](const Book& a,const Book& b){ return a.isbn < b.isbn; });
    return res;
}

bool ask_yes_no(const string &prompt){
    string line;
    while(true){
        cout << prompt;
        getline(cin, line);
        line = trim_right(line);
        if(line.size()>0){
            char c = line[0];
            if(c=='y' || c=='Y') return true;
            if(c=='n' || c=='N') return false;
        }
        cout << "Incorrect answer!" << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<Book> books;
    string line;
    while(true){
        cout << "Append Find Remove Modify Show Quit > ";
        if(!getline(cin,line)){
            break;
        }
        line = trim_right(line);
        if(line.empty()){
            cout << "Incorrect choice!" << "\n";
            continue;
        }
        char c = toupper(line[0]);
        if(c=='Q'){
            break;
        }
        if(c!='A' && c!='F' && c!='R' && c!='M' && c!='S'){
            cout << "Incorrect choice!" << "\n";
            continue;
        }
        if(c=='A'){
            Book b = input_book();
            books.push_back(b);
            continue;
        }
        if(c=='S'){
            show_books(books);
            continue;
        }
        if(c=='F'){
            cout << "Title: ";
            if(!getline(cin,line)) break;
            line = trim_right(line);
            auto res = find_by_title(books,line);
            if(res.empty()){
                cout << "Not found!" << "\n";
            }else{
                show_books(res);
            }
            continue;
        }
        if(c=='R'){
            cout << "ISBN: ";
            if(!getline(cin,line)) break;
            line = trim_right(line);
            int idx = find_by_isbn(books,line);
            if(idx==-1){
                cout << "Not found!" << "\n";
            }else{
                bool ok = ask_yes_no("Remove(y/n)? ");
                if(ok){
                    books.erase(books.begin()+idx);
                }
            }
            continue;
        }
        if(c=='M'){
            cout << "ISBN: ";
            if(!getline(cin,line)) break;
            line = trim_right(line);
            int idx = find_by_isbn(books,line);
            if(idx==-1){
                cout << "Not found!" << "\n";
            }else{
                bool ok = ask_yes_no("Modify(y/n)? ");
                if(ok){
                    Book nb = input_book();
                    books[idx] = nb;
                }
            }
            continue;
        }
    }
    return 0;
}