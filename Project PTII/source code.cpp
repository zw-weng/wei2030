#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include<string>

#define MAX_PLACE 13
#define ADULT 22.22
#define CHILD 11.11

using namespace std;

/*
	List of class
	------------------
	1. Destination
	2. Price
	3. Ticket
	4. Person
	5. Admin
	6. Customer
	7. Driver
	8. Login
*/

// Function prototype
void admin_login();
void cust_login();
void driver_login();
void admin_page();
void add_bus_details();
void add_destination();
void add_trip();
void delete_bus_details();
void delete_destination();
void delete_trip();
void driver_page(string);

// Class Destination use for aggregation in class Customer
class Destination{
	private:
		string destination;
		
	public:
		Destination(string dest="") : destination(dest){}
		
		void set_destination(string dest){
			destination.assign(dest);
		}
		
		string get_destination() const {return destination;}
};

// Class Price
class Price{
	protected:
		double price_adult;
		double price_child;
		
	public:
		double get_price_adult() const {return price_adult;}
		double get_price_child() const {return price_child;}
		double get_total() const {return price_adult + price_child;}
};

// Class Ticket
class Ticket : public Price{
	private:
		int num_of_adult;
		int num_of_child;
		
	public:
		void set_adult(int n){
			num_of_adult = n;
			calc_price_adult();
		}
		
		void set_child(int n){
			num_of_child = n;
			calc_price_child();
		}
		
		int get_adult() const {return num_of_adult;}
		int get_child() const {return num_of_child;}
		
		void calc_price_adult(){
			price_adult = num_of_adult*ADULT;
		}
		
		void calc_price_child(){
			price_child = num_of_child*CHILD;
		}
};

// Class Person
class Person{
	protected:
		string name;
		string phone;
	
	public:
		Person(string n, string p) : name(n), phone(p){}
		
		virtual void set_name() = 0; // pure virtual function
		virtual void set_phone() = 0; // pure virtual function
		virtual void dispDetails() const = 0; // pure virtual function
		
};

// Class Admin inherit Person
class Admin : public Person{
	private:
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
		
		void set_name(){
			cout << "\n\n\t\tEnter the new name: ";
			getline(cin,name);
		}
		
		void set_phone(){
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
	private:
		int num_of_place;
		Destination *dest;
		Ticket *ticket;
		double price;
		
	public:
		Customer(string n="", string p="") : Person(n,p){
			num_of_place = 0;
			dest = new Destination[MAX_PLACE]; // max 13 destination (13 state) in Malaysia
			ticket = new Ticket[MAX_PLACE];
			set_name();
			set_phone();
		}
		
		void set_name(){
			cout << "\n\n\n\n\t\tEnter your name: ";
			getline(cin,name);
		}
		
		void set_phone(){
			cout << "\n\n\t\tEnter your phone number: ";
			getline(cin,phone);
		}
		
		void place_to_go(){
			
			fstream d;
			d.open("DESTINATION.txt", ios::in);
			
			if(!(d.is_open())){
				cout << "Error to open <DESINATION.txt> file" << endl;
				exit(-1);
			}
				
			system("cls");
			
			string place;
			int count = 0;
			
			cout << "\n\n\n\t\tCurrent existing destination:" << endl;
			cout << "\t\t-------------------------------------------" << endl;
			while(d >> place){
				cout << "\t\t" << count+1 << ". " << place << endl;
				count++;
			}
			
			d.close();
			
			cout << "\n\n\t\tEnter the place you want to go: ";
			getline(cin,place);
			dest[num_of_place].set_destination(place);
			
		}
		
		void set_total_customer(){
			
			int adult;
			int child;
			
			system("cls");
			
			cout << "\n\n\t\tTicket to " << dest[num_of_place].get_destination() << endl;
			cout << "\t\t------------------------------------" << endl;
			
			cout << "\n\t\tNumber of adult -> ";
			cin >> adult;
			
			while(adult < 0){
				cout << "\n\n\t\tYou enter an invalid value. Please re-enter!" << endl;
				cout << "\n\t\tNumber of adult -> ";
				cin >> adult;
			}
			
			cout << "\n\n\t\tTicket to " << dest[num_of_place].get_destination() << endl;
			cout << "\t\t------------------------------------" << endl;
			cout << "\n\t\tNumber of adult -> " << adult << endl;
			
			cout << "\n\t\tNumber of child -> ";
			cin >> child;
			
			while(child < 0){
				cout << "\n\n\t\tYou enter an invalid value. Please re-enter!" << endl;
				cout << "\n\t\tNumber of child -> ";
				cin >> child;
			}
			
			ticket[num_of_place].set_adult(adult);
			ticket[num_of_place].set_child(child);
			
			cout << "\n\n\t\tCalculating price..." << endl;
			system("pause");
			system("cls");
			
			cout <<fixed << setprecision(2);
			cout << "\n\n\t\tThe ticket had purchased successfully." << endl;
			cout << "\n\n\t\tTicket to " << dest[num_of_place].get_destination() << endl;
			cout << "\t\t----------------------------------------------------" << endl;
			cout << "\t\tNumber of adult -> " << ticket[num_of_place].get_adult() << "\t\tRM " << ticket[num_of_place].get_price_adult() << endl;
			cout << "\t\tNumber of child -> " << ticket[num_of_place].get_child() << "\t\tRM " << ticket[num_of_place].get_price_child() << endl;
			
			cout << "\n\n\t\tTotal Price = RM " << ticket[num_of_place].get_total() << endl;
			price += ticket[num_of_place].get_total();
			
			num_of_place++;
		}
		
		void print_all() const{
			
			dispDetails();
			
			for(int i=0; i<num_of_place; i++){
				cout << "\n\n\t\tTicket to " << dest[i].get_destination() << endl;
				cout << "\t\t------------------------------------" << endl;
				cout << "\t\tNumber of adult -> " << ticket[i].get_adult() << "\t\tRM " << ticket[i].get_price_adult() << endl;
				cout << "\t\tNumber of child -> " << ticket[i].get_child() << "\t\tRM " << ticket[i].get_price_child() << endl;
			}
			
			cout << "\n\n\t\tTotal Payment = RM " << price << endl;
			cout << "\t\tThank you and byebye" << endl;
			exit(0);
		}
		
		void dispDetails() const{
			
			system("cls");
			
			cout << "\n\n\n\t\tCustomer Detail" << endl;
			cout << "\t\t--------------------------------" << endl;
			
			cout << "\n\t\tCustomer name : " << name << endl;
			cout << "\t\tContact number: " << phone << endl;
		}
		
		
};

// Class Driver inherit Person
class Driver : public Person{
	private:
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
		
		void set_name(){
			cout << "\n\n\t\tEnter the new name: ";
			getline(cin,name);
		}
		
		void set_phone(){
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
			
			system("cls");
			
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
			
			cin.ignore();
			
			switch(opt){
				case 1:
					system("cls");
					admin_login();
					break;
					
				case 2:
					system("cls");
					cust_login();
					break;
				
				case 3:
					system("cls");
					driver_login();
					break;
					
				case 4:
					cout << "\n\n\n\t\tThanks for visiting. Have a nice day" << endl;
					exit(1);
			}
		}
};

void admin_login(){
	string username;
	string password;
	Login login;

	cout << "\n\n\n\n\t\tEnter username: ";
	getline(cin,username);
	
	while(username!="staff"){
		cout << "\n\t\tWrong username. Try again." << endl;
		cout << "\t\tOR PRESS <ENTER> return to login page" << endl;
		
		cout << "\n\t\tUsername: ";
		getline(cin,username);
		cin.ignore();
		
		if(username == ""){
			login.login_page();
		}
	}
	
	cout << "\t\tEnter Password: ";
	cin >> password;
	
	while(password!="abc123"){
		cout << "\n\t\tWrong password. Try again." << endl;
		cout << "\t\tOR PRESS <ENTER> return to login page" << endl;
		
		cout << "\n\t\tEnter Password: ";
		cin >> password;
		cin.ignore();
		
		if(password==""){
			login.login_page();
		}
	}
	
	cout << "\n\n\n\t\tLogged in successfully." << endl;
	
	admin_page();
	
	login.login_page();
}

void cust_login() {
	
	Login login;
	int opt;
	Customer cust;
	
	system("cls");
	
	cout << "\n\n\n\n\t\tCustomer Menu" << endl;
	cout << "\t\t------------------------------" << endl;
	cout << "\t\t1. Display customer details" << endl;
	cout << "\t\t2. Edit customer profile" << endl;
	cout << "\t\t3. Book a ticket" << endl;
	cout << "\t\t4. Proceed to payment" << endl;
	cout << "\t\t5. Exit" << endl;
	
	cout << "\n\n\t\tPlease enter your option: ";
	cin >> opt;
	
	while(opt!=1 && opt!=2 && opt!=3 && opt!=4 && opt!=5){
		
		system("cls");
		
		cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
		cout << "\t\t1. Display customer details" << endl;
		cout << "\t\t2. Edit customer profile" << endl;
		cout << "\t\t3. Book a ticket" << endl;
		cout << "\t\t4. Proceed to payment" << endl;
		cout << "\t\t5. Exit" << endl;
				
		cout << "\n\n\t\tYour option: ";
		cin >> opt;
	}
	
	while(opt != 5){
		switch(opt){
			case 1:
				cust.dispDetails();
				break;
				
			case 2:
				system("cls");
				
				int edit;
				cout << "\n\n\n\t\tWhich detail would you like to edit?" << endl;
				cout << "\t\t------------------------------" << endl;
				cout << "\t\t1. Edit name" << endl;
				cout << "\t\t2. Edit phone number" << endl;
				cout << "\t\t3. Exit" << endl;
	
				cout << "\n\n\t\tPlease enter your option: ";
				cin >> edit;
				
				while(opt!=1 && opt!=2 && opt!=3){
		
					system("cls");
					
					cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
					cout << "\t\t1. Edit name" << endl;
					cout << "\t\t2. Edit phone number" << endl;
					cout << "\t\t3. Exit" << endl;
							
					cout << "\n\n\t\tYour option: ";
					cin >> edit;
				}
				
				cin.ignore();
				
				switch(edit){
					case 1:
						cust.set_name();
						cout << "\t\tEdit successfully..." << endl;
						break;
						
					case 2:
						cust.set_phone();
						cout << "\t\tEdit successfully..." << endl;
						break;
				}
				break;
				
			case 3: 
				cust.place_to_go();
				cust.set_total_customer();
				break;
				
			case 4: 
				cust.print_all();
				break;
		}
		
		cout << "\n\n\t\tDo you wish to continue your journey?" << endl;
		cout << "\t\tPress <1> to continue." << endl;
		cout << "\t\tPress <0> to exit customer page." << endl;
		
		cout << "\n\n\t\tYour option: ";
		cin >> opt;
		
		while(opt!=1 && opt!=0){
			cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
			cout << "Press <1> to continue." << endl;
			cout << "Press <0> to exit customer page." << endl;
			
			cout << "\n\n\t\tYour option: ";
			cin >> opt;
		}
		
		system("cls");
		
		if(opt == 1){
			cout << "\n\n\n\n\t\tCustomer Menu" << endl;
			cout << "\t\t------------------------------" << endl;
			cout << "\t\t1. Display customer details" << endl;
			cout << "\t\t2. Edit customer profile" << endl;
			cout << "\t\t3. Book a ticket" << endl;
			cout << "\t\t4. Proceed to payment" << endl;
			cout << "\t\t5. Exit" << endl;
			
			cout << "\n\n\t\tPlease enter your option: ";
			cin >> opt;
		}else{
			break;
		}
		
		cin.ignore();
		
		while(opt!=1 && opt!=2 && opt!=3 && opt!=4 && opt!=5){
			cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
			cout << "\t\t1. Display customer details" << endl;
			cout << "\t\t2. Edit customer profile" << endl;
			cout << "\t\t3. Book a ticket" << endl;
			cout << "\t\t4. Proceed to payment" << endl;
			cout << "\t\t5. Exit" << endl;
					
			cout << "\n\n\t\tYour option: ";
			cin >> opt;
		}
	}
	
	return;
}

void driver_login(){
	
	string username;
	string password;
	Login login;
	
	cout << "\n\n\n\n\t\tEnter Username: ";
	getline(cin,username);
	
	while(username!="driver1" && username!="driver2" && username!="driver3"){
		cout << "\n\tWrong username. Try again." << endl;
		cout << "\tOR PRESS <ENTER> return to login page" << endl;
		
		cout << "\n\tUsername: ";
		getline(cin,username);
		cin.ignore();
		
		if(username==""){
			login.login_page();
		}
	}
	
	cout << "\t\tEnter Password: ";
	cin >> password;
	
	while(password!="abc123"){
		cout << "\n\tWrong password. Try again." << endl;
		cout << "\tOR PRESS <ENTER> return to login page" << endl;
		
		cout << "\n\tEnter Password: ";
		cin >> password;
		cin.ignore();
		
		if(password==""){
			login.login_page();
		}
	}
	
	cout << "\n\n\n\t\tLogged in successfully." << endl;
	
	driver_page(username);
	
	login.login_page();
}

void admin_page(){
	Admin admin("Ali Akau Mutu","012-34567890","1001");
	
	int opt;
	
	system("cls");
	
	cout << "\n\n\n\n\t\tAdmin Menu" << endl;
	cout << "\t\t------------------------------" << endl;
	cout << "\t\t1. Display admin details" << endl;
	cout << "\t\t2. Edit admin profile" << endl;
	cout << "\t\t3. Add bus details" << endl;
	cout << "\t\t4. Delete bus details" << endl;
	cout << "\t\t5. Exit" << endl;
	
	cout << "\n\n\t\tPlease enter your option: ";
	cin >> opt;
	
	while(opt!=1 && opt!=2 && opt!=3 && opt!=4 && opt!=5){
		
		system("cls");
		
		cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
		cout << "\t\t1. Display admin details" << endl;
		cout << "\t\t2. Edit admin profile" << endl;
		cout << "\t\t3. Add bus details" << endl;
		cout << "\t\t4. Delete bus details" << endl;
		cout << "\t\t5. Exit" << endl;
				
		cout << "\n\n\t\tYour option: ";
		cin >> opt;
	}
	
	while(opt != 5){
		switch(opt){
			case 1:
				admin.dispDetails();
				break;
				
			case 2:
				system("cls");
				
				int edit;
				cout << "\n\n\n\t\tWhich detail would you like to edit?" << endl;
				cout << "\t\t------------------------------" << endl;
				cout << "\t\t1. Edit name" << endl;
				cout << "\t\t2. Edit phone number" << endl;
				cout << "\t\t3. Edit staff ID" << endl;
				cout << "\t\t4. Exit" << endl;
	
				cout << "\n\n\t\tPlease enter your option: ";
				cin >> edit;
				
				while(opt!=1 && opt!=2 && opt!=3 && opt!=4){
		
					system("cls");
					
					cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
					cout << "\t\t1. Edit name" << endl;
					cout << "\t\t2. Edit phone number" << endl;
					cout << "\t\t3. Edit staff ID" << endl;
					cout << "\t\t4. Exit" << endl;
							
					cout << "\n\n\t\tYour option: ";
					cin >> edit;
				}
				
				cin.ignore();
				
				switch(edit){
					case 1:
						admin.set_name();
						cout << "\t\tEdit successfully..." << endl;
						break;
						
					case 2:
						admin.set_phone();
						cout << "\t\tEdit successfully..." << endl;
						break;
						
					case 3:
						admin.edit_staffID();
						cout << "\t\tEdit successfully..." << endl;
						break;
				}
				break;
				
			case 3: // add trip
				add_bus_details();
				break;
				
			case 4: // delete trip
				delete_bus_details();
				break;
		}
		
		cout << "\n\n\t\tDo you wish to continue your journey?" << endl;
		cout << "\t\tPress <1> to continue." << endl;
		cout << "\t\tPress <0> to exit admin page." << endl;
		
		cout << "\n\n\t\tYour option: ";
		cin >> opt;
		
		while(opt!=1 && opt!=0){
			cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
			cout << "Press <1> to continue." << endl;
			cout << "Press <0> to exit admin page." << endl;
			
			cout << "\n\n\t\tYour option: ";
			cin >> opt;
		}
		
		system("cls");
		
		if(opt == 1){
			cout << "\n\n\n\n\t\tAdmin Menu" << endl;
			cout << "\t\t------------------------------" << endl;
			cout << "\t\t1. Display admin details" << endl;
			cout << "\t\t2. Edit admin profile" << endl;
			cout << "\t\t3. Add bus details" << endl;
			cout << "\t\t4. Delete bus details" << endl;
			cout << "\t\t5. Exit" << endl;
			
			cout << "\n\n\t\tPlease enter your option: ";
			cin >> opt;
		}else{
			break;
		}
		
		cin.ignore();
		
		while(opt!=1 && opt!=2 && opt!=3 && opt!=4 && opt!=5){
			cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
			cout << "\t\t1. Display admin details" << endl;
			cout << "\t\t2. Edit admin profile" << endl;
			cout << "\t\t3. Add bus details" << endl;
			cout << "\t\t4. Delete bus details" << endl;
			cout << "\t\t5. Exit" << endl;
					
			cout << "\n\n\t\tYour option: ";
			cin >> opt;
		}
	}
	
	return;
}

void add_bus_details(){
	int opt;
	
	system("cls");
	
	cout << "\n\n\n\t\tAdd Trip Menu" << endl;
	cout << "\t\t------------------------------" << endl;
	cout << "\t\t1. Add destination" << endl;
	cout << "\t\t2. Add trip" << endl;
	cout << "\t\t3. Exit" << endl;
	
	cout << "\n\n\t\tPlease enter your option: ";
	cin >> opt;
	
	while(opt!=1 && opt!=2 && opt!=3){
		
		system("cls");
		
		cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
		cout << "\t\t1. Add destination" << endl;
		cout << "\t\t2. Add trip" << endl;
		cout << "\t\t3. Exit" << endl;
				
		cout << "\n\n\t\tYour option: ";
		cin >> opt;
	}
	
	while(opt != 3){
		switch(opt){
			case 1:
				add_destination();
				break;
				
			case 2:
				add_trip();
				break;
		}
		
		cout << "\n\n\t\tDo you wish to continue your journey?" << endl;
		cout << "\t\tPress <1> to continue." << endl;
		cout << "\t\tPress <0> to exit Add Trip Menu." << endl;
		
		cout << "\n\n\t\tYour option: ";
		cin >> opt;
		
		while(opt!=1 && opt!=0){
			cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
			cout << "Press <1> to continue." << endl;
			cout << "Press <0> to exit Add Trip Menu." << endl;
			
			cout << "\n\n\t\tYour option: ";
			cin >> opt;
		}
		
		system("cls");
		
		if(opt == 1){
			cout << "\n\n\n\t\tAdd Trip Menu" << endl;
			cout << "\t\t------------------------------" << endl;
			cout << "\t\t1. Add destination" << endl;
			cout << "\t\t2. Add trip" << endl;
			cout << "\t\t3. Exit" << endl;
			
			cout << "\n\n\t\tPlease enter your option: ";
			cin >> opt;
		}else{
			break;
		}
		
		cin.ignore();
		
		while(opt!=1 && opt!=2 && opt!=3 && opt!=4 && opt!=5){
			cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
			cout << "\t\t1. Add destination" << endl;
			cout << "\t\t2. Add trip" << endl;
			cout << "\t\t3. Exit" << endl;
					
			cout << "\n\n\t\tYour option: ";
			cin >> opt;
		}
	}
	
	return;
}

void add_destination(){
	
	fstream dest;
	dest.open("DESTINATION.txt", ios::in);
	
	if(!(dest.is_open())){
		cout << "Error to open <DESINATION.txt> file" << endl;
		exit(-1);
	}
		
	system("cls");
	
	int count=0;
	string place;
	
	cout << "\n\n\n\t\tCurrent existing destination:" << endl;
	cout << "\t\t-------------------------------------------" << endl;
	while(dest >> place){
		cout << "\t\t" << ++count << ". " << place << endl;
	}
	
	dest.close();
	
	dest.open("DESTINATION.txt", ios::app);
	
	cin.ignore();
	
	cout << "\n\n\t\tPlace to add:\t";
	getline(cin,place);
	dest << place << endl;
	
	dest.close();
	
	cout << "\t\tThe destination is added successfully." << endl;
	cout << "\n\t\tNow you can add new trip for this destination..." << endl;
}

void add_trip(){
	const int infoNum = 11;
	string data;
	
	fstream trip;
	trip.open("TRIP.txt",ios::app);
	
	if(!trip.is_open()){
		cout << "Error to open <TRIP.txt> file" << endl;
		exit(-1);
	}
	
	system("cls");
	
	cout << endl;
	cout << "\n\t ---------------------------------------------------";
	cout << "\n\t| Format:                                           |";
	cout << "\n\t| --------                                          |";
	cout << "\n\t| <DESTINATION>                                     |";
	cout << "\n\t| |DATE|TIME|                                       |";
	cout << "\n\t| |DATE|TIME|                                       |";
	cout << "\n\t| |DATE|TIME|                                       |";
	cout << "\n\t| |DATE|TIME|                                       |";
	cout << "\n\t| |DATE|TIME|                                       |";
	cout << "\n\t| |DATE|TIME|                                       |";
	cout << "\n\t| |DATE|TIME|                                       |";
	cout << "\n\t| |DATE|TIME|                                       |";
	cout << "\n\t| |DATE|TIME|                                       |";
	cout << "\n\t| |DATE|TIME|                                       |";
	cout << "\n\t ---------------------------------------------------";
	cout << endl;	
	
	cout << "\n\n\t Enter the new destination:";
	cin.ignore();
	getline(cin,data);
	trip << data << endl;
	
	cout << "\n\n\tEnter Date and Time(|DD.MM.YYYY|HHMM) -> without any spacing" << endl;
	cout << "\t------------------------------------------------------------" << endl;
	for(int i=0; i<infoNum-1; i++){
		cout << "\t#" << i+1 << ": ";
		cin >> data;
		trip << data << endl;
	}
	
	trip.close();
	
	cout << "\n\t\tThe trip and its departure time is added successfully." << endl;
}

void delete_bus_details(){
	int opt;
	
	system("cls");
	
	cout << "\n\n\n\t\tDelete Trip Menu" << endl;
	cout << "\t\t------------------------------" << endl;
	cout << "\t\t1. Delete destination" << endl;
	cout << "\t\t2. Delete trip" << endl;
	cout << "\t\t3. Exit" << endl;
	
	cout << "\n\n\t\tPlease enter your option: ";
	cin >> opt;
	
	while(opt!=1 && opt!=2 && opt!=3){
		
		system("cls");
		
		cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
		cout << "\t\t1. Delete destination" << endl;
		cout << "\t\t2. Delete trip" << endl;
		cout << "\t\t3. Exit" << endl;
				
		cout << "\n\n\t\tYour option: ";
		cin >> opt;
	}
	
	while(opt != 3){
		switch(opt){
			case 1:
				delete_destination();
				break;
				
			case 2:
				delete_trip();
				break;
		}
		
		cout << "\n\n\t\tDo you wish to continue your journey?" << endl;
		cout << "\t\tPress <1> to continue." << endl;
		cout << "\t\tPress <0> to exit Add Trip Menu." << endl;
		
		cout << "\n\n\t\tYour option: ";
		cin >> opt;
		
		while(opt!=1 && opt!=0){
			cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
			cout << "Press <1> to continue." << endl;
			cout << "Press <0> to exit Add Trip Menu." << endl;
			
			cout << "\n\n\t\tYour option: ";
			cin >> opt;
		}
		
		system("cls");
		
		if(opt == 1){
			cout << "\n\n\n\t\tAdd Trip Menu" << endl;
			cout << "\t\t------------------------------" << endl;
			cout << "\t\t1. Delete destination" << endl;
			cout << "\t\t2. Delete trip" << endl;
			cout << "\t\t3. Exit" << endl;
			
			cout << "\n\n\t\tPlease enter your option: ";
			cin >> opt;
		}else{
			break;
		}
		
		cin.ignore();
		
		while(opt!=1 && opt!=2 && opt!=3 && opt!=4 && opt!=5){
			cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
			cout << "\t\t1. Delete destination" << endl;
			cout << "\t\t2. Delete trip" << endl;
			cout << "\t\t3. Exit" << endl;
					
			cout << "\n\n\t\tYour option: ";
			cin >> opt;
		}
	}
	
	return;
}

void delete_destination(){
	
	fstream dest;
	dest.open("DESTINATION.txt", ios::in);
	
	if(!(dest.is_open())){
		cout << "Error to open <DESINATION.txt> file" << endl;
		exit(-1);
	}
		
	system("cls");
	
	int count=0;
	string place[20];
	string delete_place;
	
	cout << "\n\n\n\t\tCurrent existing destination:" << endl;
	cout << "\t\t-------------------------------------------" << endl;
	while(dest >> place[count]){
		cout << "\t\t" << count+1 << ". " << place[count] << endl;
		count++;
	}
	
	dest.close();
	
	dest.open("DESTINATION.txt", ios::out);
	
	cin.ignore();
	
	cout << "\n\n\t\tPlace to delete:\t";
	getline(cin,delete_place);
	
	for(int i=0; i<count; i++){
		if(delete_place == place[i]){
			continue;
		}
		dest << place[i] << endl;
	}
	
	dest.close();
	
	cout << "\t\tThe destination is deleted successfully." << endl;
}

void delete_trip(){
	const int infoNum = 11;
	int count = 0;
	int place = 0;
	string data[200];
	string delete_trip;
	
	fstream trip;
	trip.open("TRIP.txt",ios::in);
	
	if(!trip.is_open()){
		cout << "Error to open <TRIP.txt> file" << endl;
		exit(-1);
	}
	
	system("cls");
	
	cout << "\n\n\n\t\tCurrent existing trip:" << endl;
	cout << "\t\t-------------------------------------------" << endl;
	while(!(trip.eof())){
		trip >> data[count];
		cout << "\t\t" << place++ << ". " << data[count] << endl;
		count++;
		
		for(int i=0; i<10; i++){
			trip >> data[count];
			cout << "\t\t" << data[count] << endl;
			count++;
		}
	}
	
	trip.close();
	
	trip.open("TRIP.txt",ios::out);
	
	cout << "\n\n\t Enter the trip to delete:";
	cin.ignore();
	getline(cin,delete_trip);
	trip << delete_trip << endl;
	
	for(int i=0; i<count; i++){
		if(delete_trip == data[i]){
			i += 10;
			continue;
		}
		trip << data[i] << endl;
	}
	
	trip.close();
	
	cout << "\n\t\tThe trip and its departure time is deleted successfully." << endl;
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
				driver.set_name();
				cout << "\t\tEdit successfully..." << endl;
				break;
				
			case 3:
				driver.set_phone();
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
