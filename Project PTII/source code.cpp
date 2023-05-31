#include<iostream>
#include<fstream>

#define STANDARD_SIZE 30
using namespace std;

// Function prototype
void admin_login();
void cust_login();
void driver_login();

// Class Person
class Person{
	protected:
		string name;
		string phone;
	
	public:
		Person(string n, string p) : name(n), phone(p){}
		
		virtual void dispDetails() const = 0;
};

// Class Admin inherit Person
class Admin : public Person{
	string staffID;
	
	public:
		Admin(string n, string p, string ID) : Person(n,p), staffID(ID){}
		
		void dispDetails() const{
			cout << "Staff name:\t" << name << endl;
			cout << "Contact number:\t" << phone << endl;
			cout << "Staff ID:\t" << staffID << endl;
		}
		
		
};

// Class Customer inherit Person
class Customer : public Person{
	string customer_ID;
	int num_of_seat;
	int price;
	
	public:
		Customer(string n, string p, string ID) : Person(n,p), customer_ID(ID){}
		
		void dispDetails() const{
			cout << "Customer name:\t" << name << endl;
			cout << "Contact number:\t" << phone << endl;
			cout << "Customer ID:\t" << customer_ID << endl;
		}
};

// Class Driver inherit Person
class Driver : public Person{
	string driver_ID;
	
	public:
		Driver(string n, string p, string ID) : Person(n,p), driver_ID(ID){}
		
		void dispDetails() const{
			cout << "Driver name:\t" << name << endl;
			cout << "Contact number:\t" << phone << endl;
			cout << "Driver ID:\t" << driver_ID << endl;
		}
};

// Class Login
class Login{
	public:
		void login_page(){
			int opt;
			
			cout << "\n\n\n\t\t========Bus Reservation System=======" << endl;
			cout << "\n\n\t\t1. ADMIN" << endl;
			cout << "\t\t2. Customer" << endl;
			cout << "\t\t3. Driver" << endl;
			cout << "\t\t4. Exit" << endl;
			
			cout << "\n\n\t\tYour option: ";
			cin >> opt;
			
			while((opt!=1 && opt!=2 && opt!=3 && opt!=4)){
				cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
				cout << "\n\n\t\t1. ADMIN" << endl;
				cout << "\t\t2. Customer" << endl;
				cout << "\t\t3. Driver" << endl;
				cout << "\t\t4. Exit" << endl;
				
				cout << "\n\n\t\tYour option: ";
				cin >> opt;
			}
			
			switch(opt){
				case 1:
					admin_login();
					break;
					
				case 2:
					cust_login();
					break;
				
				case 3:
					driver_login();
					break;
					
				case 4:
					cout << "\n\n\n\t\tThanks for visiting. Have a nice day" << endl;
					exit(1);
			}
		}
};

//// Class Seat
//class Seat{
//	int num_of_seat;
//	bool available;
//	
//	public:
//		Seat(int num) : num_of_seat(num){}
//		
//		void reserve(){
//			if(available){
//	            available = false;
//	            cout << "Seat " << number << " reserved." << endl;
//	        }else{
//	            cout << "Seat " << number << " is already occupied." << endl;
//	        }
//		}
//		
//		bool isAvailable(){
//			return available;
//		}
//};
//
//// Class Bus
//class Bus{
//	string plate;
//	int capacity;
//	string destination;
//	Seat seats[STANDARD_SIZE];
//	Driver driver;
//	
//	public:
//		Bus(string _plate, int cap, string des, Driver d) : plate(_plate), capacity(cap), destination(des), driver(d){}
//		
//		void dispSeats() const(){
//			
//		}
//		
//		void disp_driver_details() const{
//			cout << "Driver detail:" << endl;
//			cout << "------------------------" << endl;
//			driver.dispDetails(); 
//		}
//	
//};
//
//// Class Reservation
//class Reservation{
//	Customer *customer;
//	Bus *bus;
//	Seat *seats[STANDARD_SIZE];
//	int numSeats;
//	
//	public:
//		Reservation(Customer *cus, Bus *b) : customer(cus), bus(b){}
//		
//		void reserveSeat(Seat *seat){
//			if (seat->isAvailable()) {
//	            if (numSeats < MAX_SEATS) {
//	                seats[numSeats++] = seat;
//	                seat->reserve();
//	            } else {
//	                cout << "Cannot reserve more seats." << endl;
//	            }
//	        } else {
//	            cout << "Seat " << seat->getNumber() << " is already occupied." << endl;
//	        }
//		}
//		
//		void disp_Reservation_Detail() const{}
//};

void admin_login(){
	string username;
	string password;
	
	system("cls");
	cout << "\n\n\n\n\t\tEnter username: ";
	cin >> username;
	
	while(username!="staff"){
		cout << "\n\tWrong username. Try again." << endl;
		cout << "\tOR PRESS <ENTER> return to login page" << endl;
		
		cout << "\n\tUsername: ";
		cin >> username;
		
//		// error here to read "ENTER"
//		if(username=="\0"){
//			Login login;
//			login.login_page();
//		}
	}
	
	cout << "\t\tEnter Password: ";
	cin >> password;
	
	while(password!="abc123"){
		cout << "\n\tWrong password. Try again." << endl;
		cout << "\tOR PRESS <ENTER> return to login page" << endl;
		
		cout << "\n\tEnter Password: ";
		cin >> password;
		
//		// error here to read "ENTER"
//		if(password=="\0"){
//			Login login;
//			login.login_page();
//		}
	}
	
	cout << "\n\n\n\t\tLogged in successfully." << endl;
	
	// continue with pass to another function after successfully login
	// or can continue in this function
}

void cust_login(){
	
	system("cls");
	
	// need to create object here
	
	int opt;
	cout << "\n\n\n\n\t\tUser Menu" << endl;
	cout << "\t\t------------------------------" << endl;
	cout << "\t\t1. Bus trip" << endl;
	cout << "\t\t2. Book a trip" << endl;
	cout << "\t\t3. Exit" << endl;
	
	cout << "\n\n\t\tPlease enter your option: ";
	cin >> opt;
	
	while((opt!=1 && opt!=2 && opt!=3)){
		cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
		cout << "\t\t1. Bus trip" << endl;
		cout << "\t\t2. Book a trip" << endl;
		cout << "\t\t3. Exit" << endl;
				
		cout << "\n\n\t\tYour option: ";
		cin >> opt;
	}
	
	// continue with different function
	switch(opt){
		case 1:
			
		case 2:
		
		case 3:
			cout << "\n\n\n\t\tThanks for visiting. Have a nice day" << endl;
			exit(1);
			
	}
	
}

void driver_login(){
	string username;
	string password;
	
	system("cls");
	
	cout << "\n\n\n\n\t\tEnter username: ";
	cin >> username;
	
	while(username!="driver1" && username!="driver2" && username!="driver3"){
		cout << "\n\tWrong username. Try again." << endl;
		cout << "\tOR PRESS <ENTER> return to login page" << endl;
		
		cout << "\n\tUsername: ";
		cin >> username;
		
//		// error here to read "ENTER"
//		if(username=="\0"){
//			Login login;
//			login.login_page();
//		}
	}
	
	cout << "\t\tEnter Password: ";
	cin >> password;
	
	while(password!="abc123"){
		cout << "\n\tWrong password. Try again." << endl;
		cout << "\tOR PRESS <ENTER> return to login page" << endl;
		
		cout << "\n\tEnter Password: ";
		cin >> password;
		
//		// error here to read "ENTER"
//		if(password=="\0"){
//			Login login;
//			login.login_page();
//		}
	}
	
	cout << "\n\n\n\t\tLogged in successfully." << endl;
	
	// continue with pass to another function after successfully login
	// or can continue in this function
	
}

int main(){
	Login login;
	login.login_page();
	
	return 0;
}











































