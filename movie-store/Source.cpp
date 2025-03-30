#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <algorithm>
using namespace std;

struct customer {
	int id;
    bool isOverDue;
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

const int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int customer_count = 0;
int movies_count = 0;

void main_menu();

//main functions
void add_Customer();
void add_Movie();
void list_Customers();
void list_allMovies();
void list_RentedMovies();
void rent_Movies();//should set the due date, fees and overdue fees
void return_RentedMovies();//should calculate the final fees
void overdue_Accounts();
void display_MostRented();

// helper functions
date getCurrentDate();
date validate_DueDate(int day, int month, int year);
int calculate_returnFees(int due_day, int due_month, int due_year, int index_ofMovie);
int days_before_Duedate(int due_day, int due_month, int due_year);

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
    //char answer;
    cin.ignore();

    cout << "Enter customer name" << endl;
    getline(cin, customers[customer_count].name);

    cout << "Enter customer ID" << endl;
    cin >> customers[customer_count].id;

    /*int i = 0;
    do {
        cout << "Is there any rented movies ?\ny/n" << endl;
        cin >> answer;
        cin.ignore();
        if (answer == 'n') break;
        cout << "Enter book number : " << i + 1 << endl;
        getline(cin, customers[customer_count].rented_Movies[i]);
        i++;
    } while (i < 6);*/
    cout << "DONE!" << endl;
    Sleep(2000);
    customer_count++;
    main_menu();
}

void add_Movie() {
    cin.ignore();
    int fees, overdue_fees;
    string movie_name;
    cout << "Enter movie name" << endl;
    getline(cin, movie_name);
    for (int i = 0; i <= movies_count; i++) {
        if (movies[i].name == movie_name) {
            cout << "Movie already exists" << endl;
            main_menu();
        }
    }
    movies[movies_count].name = movie_name;
    movies[movies_count].is_Rented = false;
    cout << "Enter renting fees" << endl;
    cin >> fees;
    movies[movies_count].fees = fees;
    cout << "Enter overdue fees (per day)" << endl;
    cin >> overdue_fees;
    movies[movies_count].Overdue_Fees = overdue_fees;
    movies_count++;
    cout << "movies_count = " << movies_count << endl;
    main_menu();
}


void list_Customers(){
    if (customer_count > 0) {
        for (int i = 0; i < customer_count; i++) {
            cout << "Customer " << i + 1 << ":" << endl;
            cout << customers[i].name << endl;
            cout << customers[i].id << endl;
            cout << customers[i].rented_Movies << endl;
        }
        Sleep(2000);
    }
    else {
        cout << "No customers found" << endl;
        Sleep(2000);
    }
    main_menu();
}

void list_allMovies() {
    if (movies_count > 0) {
        for (int i = 0; i < movies_count; i++) {
            cout << "Movie " << i + 1 << ":" << endl;
            cout << "Name : " << movies[i].name << endl;
            cout << "Rented times : " << movies[i].renting_Count << endl;
        }
        Sleep(2000);
    }
    else {
        cout << "No movies found" << endl;
        Sleep(2000);
    }
    main_menu();
}

void list_RentedMovies() {
    if (movies_count > 0) {
        for (int i = 0; i < movies_count; i++) {
            if (movies[i].is_Rented == true) {
                cout << "Movie " << i + 1 << ":" << endl;
                cout << "Name : " << movies[i].name << endl;
                cout << "Rented times : " << movies[i].renting_Count << endl;
            }
            else {
                cout << "No movies rented" << endl;
                Sleep(2000);
                break;
            }
        }
    }
    else {
        cout << "No movies rented" << endl;
        Sleep(2000);
    }
    main_menu();
}

void rent_Movies() {
    string movie_name;
    cin.ignore();
    cout << "Enter the movie name you want to rent" << endl;
    getline(cin, movie_name);
    for (int i = 0; i < movies_count; i++) {

        if (movies[i].name == movie_name) { // movie found

            if (movies[i].is_Rented == true) { // movie found but rented
                cout << "Sorry the movie is already rented !" << endl;
                Sleep(2000);
                main_menu();
            }

            else { // movie found at position i and not rented --> now rent it

                if (customer_count == 0) { // check if there are NO customers already
                    cout << "No customers found in the system please register customers first !" << endl;
                    Sleep(2000);
                    main_menu();
                }

                string customer_name;
                cout << "Enter the customer you want to rent the movie to" << endl;
                getline(cin, customer_name);
                
                for (int j = 0; j < customer_count; j++) { // loop searching for customer in the system
                    if (customers[j].name == customer_name) { // customer found in the system ----> rent the movie to this customer

                        for (int k = 0; k < 6; k++) { // loop over rented movies array in customer

                            if (customers[j].rented_Movies[k] == "") {
                                customers[j].rented_Movies[k] = movie_name; // ---------------------- linked movie to the customer rented_Movies array ------------------------
                                main_menu();
                            }

                            else {
                                cout << "Can't rent any movie to this customer as he reached maximum rented please return any movie first" << endl;
                                Sleep(2000);
                                main_menu();
                            }
                        }
                    }
                    else {
                        cout << "Can't find the customer with the name provided\nPlease try again !" << endl;
                        Sleep(2000);
                        main_menu();
                    }
                }
                date today_date = getCurrentDate();
                movies[i].due_Date.day = today_date.day + 7;
                movies[i].due_Date.month = today_date.month;
                movies[i].due_Date.year = today_date.year;
                movies[i].is_Rented = true;
                movies[i].renting_Count++;
                date validated_date = validate_DueDate(movies[i].due_Date.day, movies[i].due_Date.month, movies[i].due_Date.year);
                cout << "Movie succesfully rented" << endl;
                cout << "Due Date :" << validated_date.day << "-" << validated_date.month << "-" << validated_date.year << endl;
                Sleep(2000);
                main_menu();
            }
        }
        else { // movie not found
            cout << "Movie not found\nRedirecting to main menu" << endl;
            Sleep(2000);
            main_menu();
        }
    }
    Sleep(2000);
    main_menu();
}

void return_RentedMovies() {
    cin.ignore();
    cout << "Enter name of the movie to be returned" << endl;
    string movie_name;
    getline(cin, movie_name);
    int total_fees = 0;
    for (int i = 0; i <= movies_count; i++) { // search for the movie

        if (movies[i].name == movie_name && movies[i].is_Rented == true) { // movie exists and is rented

            for (int j = 0; j <= customer_count; j++) { // search for the customer rented the movie

                for (int k = 0; k < 6; k++) { // search for the movie in the rented movies

                    if (customers[j].rented_Movies[k] == movie_name) { // found the customer renting the movie now return it

                        date return_date = getCurrentDate(); // returning today
                        total_fees = calculate_returnFees(return_date.day, return_date.month, return_date.year, i);
                        cout << "Total Charge = " << total_fees << endl;
                        movies[i].is_Rented = false;
                        customers[j].rented_Movies[k] = "";
                        cout << "Movie returned ... Thanks for using our store" << endl;
                        Sleep(2000);
                        main_menu();
                    }
                }
            }
        }
        else {
            cout << "Movie Not Found" << endl;
            Sleep(2000);
            main_menu();
        }
    }
}


void overdue_Accounts() {
    date return_date = getCurrentDate();
    for (int i = 0; i < movies_count; i++) {
        for (int j = 0; j < customer_count; j++) {
            for (int k = 0; k < 6; k++) {
                if (movies[i].name == customers[j].rented_Movies[k]) {
                    if (movies[i].is_Rented == true) {
                        if (movies[i].due_Date.month < return_date.month) {
                            customers[j].isOverDue = true;
                        }
                        if (movies[i].due_Date.month == return_date.month) {
                            if (movies[i].due_Date.day < return_date.month) {
                                customers[j].isOverDue = true;
                            }
                        }
                    }
                }

            }
        }
    }
    cout << "Overdue Accounts : " << endl;
    for (int i = 0; i < customer_count; i++) {
        if (customers[i].isOverDue == true) {
            cout << "Customer " << i + 1 << " " << customers[i].name << endl;
            cout << "id : " << customers[i].id << endl;
        }
    }
    main_menu();
}

void display_MostRented() {
    int rented_times = -1;
    string most_rented_name;
    for (int i = 0; i < movies_count; i++) {
        if (movies[i].renting_Count > rented_times) {
            rented_times = movies[i].renting_Count;
            most_rented_name = movies[i].name;
        }
    }
    cout << "Most Rented Movie : " << most_rented_name << endl;
    cout << "Rented " << rented_times << "times" << endl;
}

// helpers

date getCurrentDate() {
    time_t now = time(nullptr);
    tm localTime;
    localtime_s(&localTime, &now);

    int year = localTime.tm_year + 1900;
    int month = localTime.tm_mon + 1;
    int day = localTime.tm_mday;
    return { day, month, year };
}

date validate_DueDate(int day, int month, int year) { 
    for (int i = 0; i < 12; i++) {
        if (month == (i + 1) && month < 12) {
            if (day > months[i]) {
                cout << months[i] << endl;
                int diffrence = day - months[i];
                month++;
                day = diffrence;
                break;
            }
        }
        else { // december
            if (day > months[i]) {
                int diffrence = day - months[i];
                month++;
                month %= 12;
                day = diffrence;
                year++;
            }
        }
    }
    return { day, month, year };
}

int calculate_returnFees(int due_day, int due_month, int due_year, int index_ofMovie) { // takes due date ex:  2 - 4 - 2025   ----------   1 - 2 - 2025   ----------  29 - 3 - 2025 ----- 20 - 3 - 2025      
    date return_date = getCurrentDate();
    for (int i = 0; i < 12; i++) {
        if (due_year > return_date.year) { // 2 down 9 to go
            return movies[index_ofMovie].fees;
        }
        else if(due_year == return_date.year){

            if (due_month > return_date.month) { // 2 down 7 to go
                return movies[index_ofMovie].fees;
            }

            else if (due_month == return_date.month) { // month = month , year = year

                if (due_day >= return_date.day) { // year == year, month == month, day >= day --------- 2 down 5 to go
                    return movies[index_ofMovie].fees;
                }

                else { // due_day < return_date.day and month == month, year == year ------> start calculating overdue <------------ 1 down 4 to go
                    int overdue_days = return_date.day - due_day;
                    return movies[index_ofMovie].fees + (movies[index_ofMovie].Overdue_Fees * overdue_days);
                }
            }

            else if (due_month < return_date.month) { // year == year, due_month < return_month -------> calculate overdue

                if (due_day <= return_date.day) { // year == year, month < month, day <=> day ---- 1 down 2 to go (year < year)
                    int overdue_days = days_before_Duedate(due_day, due_month, due_year);
                    return movies[index_ofMovie].fees + (movies[index_ofMovie].Overdue_Fees * overdue_days);
                }
            }

        }
    }
     return 0;
}
int days_before_Duedate(int due_day, int due_month, int due_year) {
    date return_date = getCurrentDate();
    int total_overDue = 0;
    int days_before_month = 0;
    if (due_year == return_date.year) {

        if (due_month < return_date.month) {
            int days_before_dueMonth_end = months[due_month - 1] - due_day;

            for (int j = return_date.month; j > due_month; j--) {
                days_before_month += months[j];
            }
            total_overDue = days_before_dueMonth_end + return_date.day + days_before_month;
            return  total_overDue;
        }
        
    }
    return 0;
}