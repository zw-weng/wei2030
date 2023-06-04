#include<iostream>
#include<fstream>

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
		
		virtual void dispDetails() const = 0; // pure virtual function
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
//		Seat() : num_of_seat(0), available(true) {} // Default constructor
//		Seat(int num) : num_of_seat(num){}
//		
//	void reserve(){
//		if(available){
//			available = false;
//        	cout << "Seat " << num_of_seat << " reserved." << endl;
//		}
//		else{
//			cout << "Seat " << num_of_seat << " is already occupied." << endl;
//		}
//	}
//
//	bool isAvailable()const{
//		return available;
//	}
//	
//	int getNumber()const {
//		return num_of_seat;
//	}
//};
//
//// Class Bus
//class Bus {
//    string plate;
//    int capacity;
//    string destination;
//    Seat seats[STANDARD_SIZE];
//    Driver driver;
//
//public:
//    Bus(const string& _plate, int cap, const string& des, const Driver& d)
//        : plate(_plate), capacity(cap), destination(des), driver(d) {}
//
//    void dispSeats() const {
//        cout << "Seat Availability:" << endl;
//        cout << "------------------" << endl;
//        for (int i = 0; i < STANDARD_SIZE; ++i) {
//            cout << "Seat " << seats[i].getNumber() << ": ";
//            if (seats[i].isAvailable()) {
//                cout << "Available" << endl;
//            } else {
//                cout << "Occupied" << endl;
//            }
//        }
//    }
//
//    void disp_driver_details() const {
//        cout << "Driver Details:" << endl;
//        cout << "----------------" << endl;
//        driver.dispDetails();
//    }
//};
//
//// Class Reservation
//class Reservation{
//	Customer *customer;
//	Bus *bus;
//	Seat *seats[STANDARD_SIZE];
//	int numSeats;
//	int const MAX_SEATS = 40;
//	
//	public:
//		Reservation(Customer *cus, Bus *b) : customer(cus), bus(b){}
//		
//		void reserveSeat(Seat *seat){
//			if (seat->isAvailable()) {
//	            if (numSeats < MAX_SEATS) {
//	                seats[numSeats++] = seat;
//	                seat->reserve();
//	            } 
//				else {
//	                cout << "Cannot reserve more seats." << endl;
//	            }
//	        } 
//			else {
//	            cout << "Seat " << seat->getNumber() << " is already occupied." << endl;
//	        }
//		}
//		
//		void disp_Reservation_Detail() const{
//			cout << "Reservation Details:" << endl;
//        	cout << "---------------------" << endl;
//        	// Display customer details
//        	// Display bus details
//       		cout << "Reserved Seats:" << endl;
//        	for (int i = 0; i < numSeats; ++i) {
//            	cout << "Seat " << seats[i]->getNumber() << endl;
//        	}
//		}
//};

void admin_login(){
	string username;
	string password;
	
	system("cls");
	cout << "\n\n\n\n\t\tEnter username: ";
	cin >> username;
	
	while(username!="staff"){
		cout << "\n\t\tWrong username. Try again." << endl;
		cout << "\t\tOR PRESS <ENTER> return to login page" << endl;
		
		cout << "\n\t\tUsername: ";
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
		cout << "\n\t\tWrong password. Try again." << endl;
		cout << "\t\tOR PRESS <ENTER> return to login page" << endl;
		
		cout << "\n\t\tEnter Password: ";
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

void cust_login() {
//
    system("cls");
//
//    Driver driver("John Doe", "011-10112377", "D001");
//    Bus bus("ABC123", STANDARD_SIZE, "Destination", driver);
//    Customer customer("Ali", "012-2201098", "C001");
//
//    int opt;
//    cout << "\n\n\n\n\t\tUser Menu" << endl;
//    cout << "\t\t------------------------------" << endl;
//    cout << "\t\t1. Bus trip" << endl;
//    cout << "\t\t2. Book a trip" << endl;
//    cout << "\t\t3. Exit" << endl;
//
//    cout << "\n\n\t\tPlease enter your option: ";
//    cin >> opt;
//
//    while ((opt != 1 && opt != 2 && opt != 3)) {
//        cout << "\n\t\tYou entered a wrong option. Please re-input:" << endl;
//        cout << "\t\t1. Bus trip" << endl;
//        cout << "\t\t2. Book a trip" << endl;
//        cout << "\t\t3. Exit" << endl;
//
//        cout << "\n\n\t\tYour option: ";
//        cin >> opt;
//    }
//
//    switch (opt) {
//    case 1:
//        bus.disp_driver_details();
//        bus.dispSeats();
//        break;
//    case 2: {
//    Reservation reservation(&customer, &bus);
//    Seat seat1(1);
//    Seat seat2(2);
//
//    reservation.reserveSeat(&seat1);
//    reservation.reserveSeat(&seat2);
//
//    reservation.disp_Reservation_Detail();
//    break;
//}
//    case 3:
//        cout << "\n\n\n\t\tThanks for visiting. Have a nice day" << endl;
//        exit(1);
//    }
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

