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

date getCurrentDate();

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

    cout << "Enter movie name" << endl;
    getline(cin, movies[movies_count].name);

    string choice;
    cout << "Is the movie rented ?" << endl;
    cin >> choice;
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
        cout << "No customers found" << endl;
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
    for (int i = 0; i <= movies_count; i++) {

        if (movies[i].name == movie_name) { // movie found

            if (movies[i].is_Rented == true) { // movie found but rented
                cout << "Sorry the movie is already rented !" << endl;
                break;
            }

            else { // movie found at position i and not rented --> now rent it

                if (customer_count < 0) { // check if there are NO customers already
                    cout << "No customers found in the system please register customers first !" << endl;
                    Sleep(2000);
                    break;
                }

                string customer_name;
                cout << "Enter the customer you want to rent the movie to" << endl;
                getline(cin, customer_name);
                
                for (int j = 0; j < customer_count; j++) {
                    if (customers[j].name == customer_name) { // customer found in the system ----> rent the movie to this customer
                        for (int k = 0; k < 6; k++) {
                            if (customers[j].rented_Movies[k] == "") {
                                customers[j].rented_Movies[k] = movie_name;
                                cout << "Succefully Added" << endl;
                                break;
                            }
                            else {
                                cout << "Can't rent any movie to this customer as he reached maximum rented please return any movie first" << endl;
                                break;
                            }
                        }
                    }
                }
                date today_date = getCurrentDate();
                movies[i].due_Date.day = today_date.day + 7;
                movies[i].due_Date.month = today_date.month;
                movies[i].due_Date.year = today_date.year;
                movies[i].fees = 100;
                movies[i].Overdue_Fees = 200;
                movies[i].is_Rented = true;
                movies[i].renting_Count++;
                cout << "Movie succesfully rented" << endl;
                Sleep(2000);
                break;
            }
        }
        else { // movie not found
            cout << "Movie not found\nRedirecting to main menu" << endl;
            Sleep(2000);
            break;
        }
    }
    Sleep(2000);
    main_menu();
}

void return_RentedMovies() {

}

void overdue_Accounts() {

}

void display_MostRented() {

}

date getCurrentDate() {
    time_t now = time(nullptr);
    tm localTime;
    localtime_s(&localTime, &now); // Safe function

    int year = localTime.tm_year + 1900;
    int month = localTime.tm_mon + 1;
    int day = localTime.tm_mday;
    return { day, month, year };
}