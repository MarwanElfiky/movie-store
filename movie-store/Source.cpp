#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

struct customer {
	int id;
	string name, rented_Movies[6];
};

struct date {
	int day, month, year;
};

struct movie {
	int renting_Count, fees, Overdue_Fees;
	bool is_Rented;
	string name;
	date return_Date, due_Date;
};

customer customers[5];
movie movies[10];

int customer_count = 0;
int movies_count = 0;

void main_menu();

void add_Customer();
void add_Movie();
void list_Customers();
void list_allMovies();
void list_RentedMovies();
void rent_Movies();//should set the due date, fees and overdue fees
void return_RentedMovies();//should calculate the final fees
void overdue_Accounts();
void display_MostRented();

int main() {
	main_menu();
}

void main_menu() {
    int MainMenuChoice;
    cout << "==================================" << endl;
    cout << endl;
    cout << "Welcome to our Store" << endl;
    cout << "" << endl;
    cout << "press 1 to ADD A NEW CUSTOMER " << endl;
    cout << "press 2 to ADD A NEW MOVIE" << endl;
    cout << "press 3 to LIST ALL CUSTOMERS" << endl;
    cout << "press 4 to LIST ALL MOVIES" << endl;
    cout << "press 5 to LIST ALL RENTED MOVIES" << endl;
    cout << "press 6 to RENT A MOVIE" << endl;
    cout << "press 7 to RETURN A MOVIE" << endl;
    cout << "press 8 to CREATE A SUMMARY OF OVERDUE ACCOUNTS" << endl;
    cout << "press 9 to DISPLAY THE MOST RENTED MOVIE" << endl;
    cout << "press 0 to exit" << endl;
    cout << endl;
    cout << "==================================" << endl;
    cin >> MainMenuChoice;

    switch (MainMenuChoice) {
    case 1:
        add_Customer();
        break;
    case 2:
        add_Movie();
        break;
    case 3:
        list_Customers();
        break;
    case 4:
        list_allMovies();
        break;
    case 5:
        list_RentedMovies();
        break;
    case 6:
        rent_Movies();
        break;
    case 7:
        return_RentedMovies();
        break;
    case 8:
        overdue_Accounts();
        break;
    case 9:
        display_MostRented();
        break;
    case 0:
        break;
    default:
        cout << "choose one of the options above please" << endl;
        break;
    }
}


void add_Customer(){
    char answer;
    cin.ignore();

    cout << "Enter customer name" << endl;
    getline(cin, customers[customer_count].name);

    cout << "Enter customer ID" << endl;
    cin >> customers[customer_count].id;

    int i = 0;
    do {
        cout << "Is there any rented movies ?\ny/n" << endl;
        cin >> answer;
        cin.ignore();
        if (answer == 'n') break;
        cout << "Enter book number : " << i + 1 << endl;
        getline(cin, customers[customer_count].rented_Movies[i]);
        i++;
    } while (i < 6);
    cout << "DONE!" << endl;
    Sleep(2000);
    customer_count++;
    main_menu();
}

void add_Movie() {

    cout << "Enter movie name" << endl;
    getline(cin, movies[movies_count].name);

    string choice;
    cout << "Is the movie rented ?" << endl;
    if (choice == "yes") {
        movies[movies_count].is_Rented = TRUE;

        cout << "Enter renting count" << endl;
        cin >> movies[movies_count].renting_Count;

        cout << "Enter due data\nday: " << endl;
        cin >> movies[movies_count].due_Date.day;
        cout << "Enter due data\nmonth: " << endl;
        cin >> movies[movies_count].due_Date.month;
        cout << "Enter due data\nyear: " << endl;
        cin >> movies[movies_count].due_Date.year;

        cout << "Enter returning data\nday: " << endl;
        cin >> movies[movies_count].return_Date.day;
        cout << "Enter returning data\nmonth: " << endl;
        cin >> movies[movies_count].return_Date.month;
        cout << "Enter returning data\nyear: " << endl;
        cin >> movies[movies_count].return_Date.year;

        cout << "Enter renting fee" << endl;
        cin >> movies[movies_count].fees;

        cout << "Enter overdue fees" << endl;
        cin >> movies[movies_count].Overdue_Fees;
    }
    else
        movies[movies_count].is_Rented = FALSE;
    movies_count++;
}


void list_Customers(){

}

void list_allMovies() {

}

void list_RentedMovies() {

}

void rent_Movies() {

}

void return_RentedMovies() {

}

void overdue_Accounts() {

}

void display_MostRented() {

}