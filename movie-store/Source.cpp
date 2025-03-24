#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct customer {
	int id;
	string name, rented_Movies[6];
};

struct movie {
	int renting_Count, fees, Overdue_Fees;
	bool is_Rented;
	string name;
	date return_Date, due_Date;
};

struct date {
	int day, month, year;
};


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

}

void add_Movie() {

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
