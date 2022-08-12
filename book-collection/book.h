#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Book {
private:
	string name; 
	string author;
	string genre;
	int year_of_issue;
	string publisher;
	int number_of_pages;

public:
	Book();
	Book(string name, string author, string genre, int year_of_issue, string publisher, int number_of_pages);
	~Book();
	string get_name();
	string get_author();
	string get_genre();
	string get_publisher();

	void set_name();
	void set_author();
	void set_genre();
	void set_year_of_issue();
	void set_publisher();
	void set_number_of_pages();

	void save();
	void read(string data);
	
	friend ostream& operator << (ostream& stream, Book& book);
	
	friend istream& operator >> (istream& stream, Book& book);
};
ostream& operator << (ostream& stream, Book& book);
istream& operator >> (istream& stream, Book& book);

