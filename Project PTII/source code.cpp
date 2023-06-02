#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>

#define STANDARD_SIZE 30
using namespace std;

// Function prototype
void admin_login();
void cust_login();
void driver_login();
void driver_page(string);

// Class Person
class Person{
	protected:
		string name;
		string phone;
	
	public:
		Person(string n, string p) : name(n), phone(p){}
		
		virtual void dispDetails() const = 0;
		virtual void edit_name() = 0;
		virtual void edit_phone() = 0;
};

// Class Admin inherit Person
class Admin : public Person{
	string staff_ID;
	
	public:
		Admin(string n, string p, string ID) : Person(n,p), staff_ID(ID){}
		
		void dispDetails() const{
			
			system("cls");
			
			cout << "\n\n\n\t\tStaff Detail" << endl;
			cout << "\t\t--------------------------------" << endl;
			
			cout << "\n\t\tStaff name  :\t" << name << endl;
			cout << "\t\tContact number:\t" << phone << endl;
			cout << "\t\tStaff ID      :\t" << staff_ID << endl;
		}
		
		void edit_name(){
			cout << "\n\n\t\tEnter the new name: ";
			getline(cin,name);
		}
		
		void edit_phone(){
			cout << "\n\n\t\tEnter the new phone number: ";
			getline(cin,phone);
		}
		
		void edit_staffID(){
			cout << "\n\n\t\tEnter your new staff ID: ";
			getline(cin,staff_ID);
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
			
			cout << "Customer name :\t" << name << endl;
			cout << "Contact number:\t" << phone << endl;
			cout << "Customer ID   :\t" << customer_ID << endl;
		}
		
		void edit_name(){
			cout << "\n\n\t\tEnter your name: ";
			getline(cin,name);
		}
		
		void edit_phone(){
			cout << "\n\n\t\tEnter your phone number: ";
			getline(cin,phone);
		}
};

// Class Driver inherit Person
class Driver : public Person{
	string driver_ID;
	
	public:
		Driver(string n, string p, string ID) : Person(n,p), driver_ID(ID){}
		
		void dispDetails() const{
			
			system("cls");
			
			cout << "\n\n\n\t\tDriver Detail" << endl;
			cout << "\t\t--------------------------------" << endl;
			
			cout << "\n\t\tDriver name :\t" << name << endl;
			cout << "\t\tContact number:\t" << phone << endl;
			cout << "\t\tDriver ID     :\t" << driver_ID << endl;
		}
		
		void edit_name(){
			cout << "\n\n\t\tEnter the new name: ";
			getline(cin,name);
		}
		
		void edit_phone(){
			cout << "\n\n\t\tEnter the new phone number: ";
			getline(cin,phone);
		}
		
		void edit_driverID(){
			cout << "\n\n\t\tEnter your new driver ID: ";
			getline(cin,driver_ID);
		}
};

// Class Login
class Login{
	public:
		void login_page(){
			
			system("cls");
			
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
	cout << "\n\n\n\n\t\tEnter Username: ";
	cin >> username;
	
	while(username!="staff"){
		cout << "\n\tWrong username. Try again." << endl;
		cout << "\tOR PRESS <ENTER> return to login page" << endl;
		
		cout << "\n\tUsername: ";
		getline(cin,username);
		
//		// error here to read "ENTER"
//		if(username.empty()){
//			Login login;
//			login.login_page();
//			return;
//		}
	}
	
	cout << "\t\tEnter Password: ";
	getline(cin,password);
	
	while(password!="abc123"){
		cout << "\n\tWrong password. Try again." << endl;
		cout << "\tOR PRESS <ENTER> return to login page" << endl;
		
		cout << "\n\tEnter Password: ";
		cin >> password;
		
		// error here to read "ENTER"
//		if(password.empty()){
//			Login login;
//			login.login_page();
//			return;
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
	Login login;
	
	system("cls");
	
	cout << "\n\n\n\n\t\tEnter Username: ";
	cin >> username;
	
	while(username!="driver1" && username!="driver2" && username!="driver3"){
		cout << "\n\tWrong username. Try again." << endl;
		cout << "\tOR PRESS <ENTER> return to login page" << endl;
		
		cout << "\n\tUsername: ";
		cin >> username;
		
//		// error here to read "ENTER"
//		if(username=="\0"){
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
//			login.login_page();
//		}
	}
	
	cout << "\n\n\n\t\tLogged in successfully." << endl;
	
	// continue with pass to another function after successfully login
	// or can continue in this function
	
	driver_page(username);
	
	login.login_page();
}

void driver_page(string username){
	Driver driver("","","");
	
	if(username == "driver1"){
		driver = Driver("Mutu","011-11111111","3001");
	}else if(username == "driver2"){
		driver = Driver("Ah Chong","012-44565678","3002");
	}else{
		driver = Driver("Muhammad","013-95433300","3003");
	}
	
	int opt;
	
	system("cls");
	
	cout << "\n\n\n\n\t\tDriver Menu" << endl;
	cout << "\t\t------------------------------" << endl;
	cout << "\t\t1. Display driver details" << endl;
	cout << "\t\t2. Edit driver name" << endl;
	cout << "\t\t3. Edit driver phone number" << endl;
	cout << "\t\t4. Edit driver ID" << endl;
	cout << "\t\t5. Exit" << endl;
	
	cout << "\n\n\t\tPlease enter your option: ";
	cin >> opt;
	
	while(opt!=1 && opt!=2 && opt!=3 && opt!=4 && opt!=5){
		
		system("cls");
		
		cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
		cout << "\t\t1. Display driver details" << endl;
		cout << "\t\t2. Edit driver name" << endl;
		cout << "\t\t3. Edit driver phone number" << endl;
		cout << "\t\t4. Edit driver ID" << endl;
		cout << "\t\t5. Exit" << endl;
				
		cout << "\n\n\t\tYour option: ";
		cin >> opt;
	}
	
	while(opt != 5){
		switch(opt){
			case 1:
				driver.dispDetails();
				break;
				
			case 2:
				driver.edit_name();
				cout << "\t\tEdit successfully..." << endl;
				break;
				
			case 3:
				driver.edit_phone();
				cout << "\t\tEdit successfully..." << endl;
				break;
				
			case 4:
				driver.edit_driverID();
				cout << "\t\tEdit successfully..." << endl;
				break;
		}
		
		cout << "\n\n\t\tDo you wish to continue your journey?" << endl;
		cout << "\t\tPress <1> to continue." << endl;
		cout << "\t\tPress <0> to exit driver page." << endl;
		
		cout << "\n\n\t\tYour option: ";
		cin >> opt;
		
		while(opt!=1 && opt!=0){
			cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
			cout << "Press <1> to continue." << endl;
			cout << "Press <0> to exit driver page." << endl;
			
			cout << "\n\n\t\tYour option: ";
			cin >> opt;
		}
		
		system("cls");
		
		if(opt == 1){
			cout << "\n\n\n\n\t\tDriver Menu" << endl;
			cout << "\t\t------------------------------" << endl;
			cout << "\t\t1. Display driver details" << endl;
			cout << "\t\t2. Edit driver name" << endl;
			cout << "\t\t3. Edit driver phone number" << endl;
			cout << "\t\t4. Edit driver ID" << endl;
			cout << "\t\t5. Exit" << endl;
			
			cout << "\n\n\t\tPlease enter your option: ";
			cin >> opt;
		}else{
			break;
		}
		
		cin.ignore();
		
		while(opt!=1 && opt!=2 && opt!=3 && opt!=4 && opt!=5){
			cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
			cout << "\t\t1. Display driver details" << endl;
			cout << "\t\t2. Edit driver name" << endl;
			cout << "\t\t3. Edit driver phone number" << endl;
			cout << "\t\t4. Edit driver ID" << endl;
			cout << "\t\t5. Exit" << endl;
					
			cout << "\n\n\t\tYour option: ";
			cin >> opt;
		}
	}
	
	return;
}

int main(){
	Login login;
	login.login_page();
	
	return 0;
}
