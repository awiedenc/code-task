#include "Book.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Book::Book()
{
	this->name = "";
	this->author = "";
	this->genre = "";
	this->year_of_issue = 2022;
	this->publisher = "";
	this->number_of_pages = 200;
}

Book::Book(string name, string author, string genre, int year_of_issue, string publisher, int number_of_pages)
{
	this->name = name;
	this->author = author;
	this->genre = genre;
	this->year_of_issue = year_of_issue;
	this->publisher = publisher;
	this->number_of_pages = number_of_pages;
}

Book::~Book()
{

}

string Book::get_name() 
{
	return this->name;
}

string Book::get_author()
{
	return this->author;
}

string Book::get_genre()
{
	return this->genre;
}

string Book::get_publisher() 
{
	return this->publisher;
}

void Book::set_name(name) 
{
	
}
void Book::set_author()
{

}
void Book::set_genre()
{

}
void Book::set_year_of_issue()
{

}
void Book::set_publisher()
{

}
void Book::set_number_of_pages()
{

}

void Book::save()
{
	string data;
	data += this->name + ";";
	data += this->author + ";";
	data += this->genre + ";";
	data += to_string(this->year_of_issue) + ";";
	data += this->publisher + ";";
	data += to_string(this->number_of_pages) + ";";
	return napis;
}

void Book::read(string data)
{
	string record;
	vector <string> data_v;
	int i = 0;
	while (i < int(data.size()))
	{
		record = "";
		while (data[i] != ';' && i < int(data.size()))
		{
			record += data[i];
			i++;
		}
		data_v.push_back(record);
		i = i + 1;
	}
	
	this->name = data_v[0]; 
	this->author = data_v[1];
	this->genre = data_v[2];
	this->year_of_issue = atoi(data_v[3].c_str());
	this->publisher = data_v[4];
	this->number_of_pages = atoi(data_v[5].c_str());
}


ostream& operator << (ostream& stream, Book& book)
{
	stream << book.save();
	return stream;
}

istream& operator >> (istream& stream, Book& book)
{
	string data;
	stream >> data;
	book.read(data);
	return stream;
}


