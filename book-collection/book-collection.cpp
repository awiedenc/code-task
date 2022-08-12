#include "Book.h"
#include "Collection.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>


using namespace std;

int menu(); //menu of choice
int reports(); //menu of reports
void add_book(); //adding new book
void delete_book(); //deleting book
void saving(); //saving to file
void reading(); //reading from file

Collection <Book> collection_of_books;

int menu()
{
    string option = "";
    int number = 0;
    bool ok = false;
    do
    {
        cout << endl << "==========================================================" << endl;
        cout << "Menu:" << endl;
        cout << "1) Add a book." << endl;
        cout << "2) Delete a book." << endl;
        cout << "3) Reports..." << endl;

        cout << "Choose option: ";
        getline(cin, option);
        cout << endl;
        number = atoi(option.c_str());
        if (number > 0 and number <= 3)
        {
            ok = true;
        }
        else
        {
            throw string("Wrong number");
        }
    } while (!(ok));
    return number;
}



int reports() 
{
    string option = "";
    int number = 0;
    bool ok = false;
    do
    {
        cout << endl << "==========================================================" << endl;
        cout << "Menu:" << endl;
        cout << "1) Show all books by the same author." << endl;
        cout << "2) Show all books of a given genre." << endl;
        cout << "3) Show all books of a given publisher." << endl;
        cout << "4) Show the name of the publisher with the maximum quantity of the books." << endl;
        cout << "5) Show TOP-3 genres." << endl;

        cout << "Choose option: ";
        getline(cin, option);
        cout << endl;
        number = atoi(option.c_str());
        if (number > 0 and number <= 5)
        {
            ok = true;
        }
        else
        {
            throw string("Wrong number");
        }
    } while (!(ok));
    return number;
}

void add_book()
{
    string option;
    string name;
    string author;
    string genre;
    int year_of_issue;
    string publisher;
    int number_of_pages;

    cout << "Write title: ";
    getline(cin, name);
    cout << endl;
    cout << "Write author: ";
    getline(cin, author);
    cout << endl;
    cout << "Write genre: ";
    getline(cin, genre);
    cout << endl;
    cout << "Write year of issue: ";
    getline(cin, option);
    year_of_issue = atoi(option.c_str());
    cout << endl;
    cout << "Write publisher: ";
    getline(cin, publisher);
    cout << endl;
    cout << "Write number of pages: ";
    getline(cin, option);
    number_of_pages = atoi(option.c_str());
    cout << endl;

    Book book01(name, author, genre, year_of_issue, publisher, number_of_pages);
    collection_of_books.add_last(book01);
}

void delete_book()
{
    string option = "";
    int number = 0;
    bool ok = false;
    do
    {
        cout << "Choose book you want to delete: " << endl;
        collection_of_books.write();
        cout << "Choose option: ";
        getline(cin, option);
        cout << endl;
        number = atoi(option.c_str());
        if (number > 0 and number <= 3)
        {
            ok = true;
        }
        else
        {
            throw string("Wrong number");
        }
    } while (!(ok));
    
    collection_of_books.delete_from(number - 1);
    cout << endl << "Book deleted." << endl;
}

void saving()
{
    string stream;
    stream = "./saved_data.txt";
    ofstream saved_data;
    saved_data.open(stream);
    if (saved_data.bad())
    {
        throw string("Error");
    }
    else
    {
        saved_data << collection_of_books;
    }
    saved_data.close();
}

void reading()
{
    string stream;

    stream = "./saved_data.txt";
    ifstream saved_data;
    saved_data.open(stream);
    if (saved_data.bad())
    {
        throw string("Error");
    }
    else
    {
        saved_data >> collection_of_books;
    }
    saved_data.close();
}



int main()
{
    int option;
    int numer;
    int numer1;
    int numer2;
    //reading();
    do
    {
        try
        {
            option = menu();
        }
        catch (string note)
        {
            cout << note << endl;
        }
       
        switch (option)
        {
        case 1:
            add_book();
            break;

        case 2:
            try
            {
                delete_book();
            }
            catch (string note)
            {
                cout << note << endl;
            }
            break;

        case 3:
            try
            {
                int choice = reports();
            }
            catch (string note)
            {
                cout << note << endl;
            }

            break;
        }
    } while (option != 3);

    saving();
}