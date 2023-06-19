#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include<string>

#include <Windows.h>
#include <stdio.h>
// #include <graphics.h>

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

// Class Desination
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
	
	private:
		double price_adult;
		double price_child;
		
	public:
		double get_price_adult() const {return price_adult;}
		double get_price_child() const {return price_child;}
		double get_total() const {return price_adult + price_child;}
		
		void calc_price_adult(int n){
			
			price_adult = n*ADULT;
			
		}
		
		void calc_price_child(int n){
			
			price_child = n*CHILD;
			
		}
		
};

// Class Ticket
class Ticket{
	
	private:
		
		Price *price;
		int num_of_adult;
		int num_of_child;
		
	public:
		Ticket(){
			
			price = new Price;
			
		}
		
		void set_adult(int n){
			
			num_of_adult = n;
			price->calc_price_adult(num_of_adult);
			
		}
		
		void set_child(int n){
			
			num_of_child = n;
			price->calc_price_child(num_of_child);
			
		}
		
		int get_adult() const {return num_of_adult;}
		int get_child() const {return num_of_child;}
		
		void disp_ticket(){
			
			cout << "\t\tNumber of adult -> " << num_of_adult << "\t\tRM " << price->get_price_adult() << endl;
			cout << "\t\tNumber of child -> " << num_of_child << "\t\tRM " << price->get_price_child() << endl;
		
		}
		
		double total_price(){
			
			return (price->get_total());
			
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
			
			cout << "\n\t\tStaff name    :\t" << name << endl;
			cout << "\t\tContact number:\t" << phone << endl;
			cout << "\t\tStaff ID      :\t" << staff_ID << endl;
			
		}
		
		void set_name(){
			
			system("cls");
			
			cout << "\n\n\t\tEnter the new name: ";
			cin.ignore();
			getline(cin,name);
			
		}
		
		void set_phone(){
			
			system("cls");
			
			cout << "\n\n\t\tEnter the new phone number: ";
			cin.ignore();
			getline(cin,phone);
			
		}
		
		void edit_staffID(){
			
			system("cls");
			
			cout << "\n\n\t\tEnter your new staff ID (must begin with character '1'): ";
			cin.ignore();
			getline(cin,staff_ID);
			
			while(staff_ID.at(0) != '1'){
				
				system("cls");
				
				cout << "\n\n\t\tYou enter an invalid staff ID. Please re-enter." << endl;
				cout << "\n\t\tEnter your new staff ID (must begin with character '1'): ";
				getline(cin,staff_ID);
				
			}
			
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
		
		~Customer(){
			delete [] dest;
			delete [] ticket;
		}
		
		void set_name(){
			
			cout << "\n\n\n\n\t\tEnter your name: ";
			cin.ignore();
			getline(cin,name);
			
		}
		
		void set_phone(){
			
			cout << "\n\t\tEnter your phone number: ";
			cin.ignore();
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
			
			string place[20];
			int count = 0;
			
			cout << "\n\n\n\t\tCurrent existing destination:" << endl;
			cout << "\t\t-------------------------------------------" << endl;
			while(d >> place[count]){
				
				cout << "\t\t" << count+1 << ". " << place[count] << endl;
				count++;
				
			}
			
			d.close();
			
			string destination;
			bool valid = false;
			
			cout << "\n\n\t\tEnter the place you want to go: ";
			cin.ignore();
			getline(cin,destination);
			
			for(int i=0; i<count; i++){
				
				if(destination == place[i]){
					
					valid = true;
					break;
					
				}
				
			}
			
			if(!valid){
				
				system("cls");
				
				cout << "\n\n\t\tInvalid destination." << endl;
				cout << "\t\t1. You might enter a non-existing destination" << endl;
				cout << "\t\t2. You might accidentally face a spelling error" << endl;
				cout << "\t\t-------------------------------------------------" << endl;
				
				for(int i=0; i<count; i++){
					
					cout << "\t\t" << i+1 << ". " << place[i] << endl;
					
				}

				cout << "\n\t\tPlease try to re-enter a valid destination -> ";
				getline(cin,destination);
				
			}
			
			dest[num_of_place].set_destination(destination);
			
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
			
			system("cls");
			
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
			cout << "\t\t";
			system("pause");
			system("cls");
			
			cout <<fixed << setprecision(2);
			cout << "\n\n\t\tThe ticket had purchased successfully." << endl;
			cout << "\n\n\t\tTicket to " << dest[num_of_place].get_destination() << endl;
			cout << "\t\t----------------------------------------------------" << endl;
			ticket[num_of_place].disp_ticket();
			
			cout << "\n\n\t\tTotal Price = RM " << ticket[num_of_place].total_price() << endl;
			price += ticket[num_of_place].total_price();
			
			num_of_place++;
			
		}
		
		void print_all() const{
			
			dispDetails();
			
			for(int i=0; i<num_of_place; i++){
				
				cout << "\n\n\t\tTicket to " << dest[i].get_destination() << endl;
				cout << "\t\t---------------------------------------------------" << endl;
				ticket[i].disp_ticket();
				
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
			
			cout << "\n\t\tDriver name   :\t" << name << endl;
			cout << "\t\tContact number:\t" << phone << endl;
			cout << "\t\tDriver ID     :\t" << driver_ID << endl;
		}
		
		void set_name(){
			
			system("cls");
			
			cout << "\n\n\t\tEnter the new name: ";
			cin.ignore();
			getline(cin,name);
			
		}
		
		void set_phone(){
			
			system("cls");
			
			cout << "\n\n\t\tEnter the new phone number: ";
			cin.ignore();
			getline(cin,phone);
			
		}
		
		void edit_driverID(){
			
			system("cls");
			
			cout << "\n\n\t\tEnter your new driver ID (must begin with character '3'): ";
			cin.ignore();
			getline(cin,driver_ID);
			
			while(driver_ID.at(0) != '3'){
				
				system("cls");
				
				cout << "\n\n\t\tYou enter an invalid driver ID. Please re-enter." << endl;
				cout << "\n\t\tEnter your new driver ID (must begin with character '3'): ";
				getline(cin,driver_ID);
				
			}
			
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
					AllocConsole();
					int msgboxID = MessageBox(FindWindowA("ConsoleWindowClass", NULL), "Thanks for visiting. Have a nice day!", "Bus Reservation System", MB_CANCELTRYCONTINUE | MB_ICONASTERISK | MB_DEFBUTTON2 | MB_SYSTEMMODAL);
					if (msgboxID == IDCONTINUE)
					{
						exit(1);
					}
					else if (msgboxID == IDTRYAGAIN)
					{
						system("cls");
						printf("\e[?251");
						
						SetConsoleCP(437);
						SetConsoleOutputCP(437);
						
						int bar1 = 177, bar2 = 219;
						cout << "\n\n\n\t\t\t\taWELCOME BACK!";
						cout << "\n\t\t\t\t";
						cout << "\n\n\n\t\t\t\tLoading...";
						cout << "\n\n\n\t\t\t\t";
						
						for(int i = 0; i < 25; i++)
							cout << (char)bar1;
							
						cout << "\r";
						cout << "\t\t\t\t";
						for(int i = 0; i < 25; i++)
						{
							cout << (char)bar2;
							Sleep(150);
						}
		
						cout << "\n\t\t\t\t" << (char)1 << "!";
						login_page();
					}
					else
						login_page();
			}
			
//			cout << "\n\n\n\t\tThanks for visiting. Have a nice day" << endl;
			
		}
		
};

void admin_login(){
	
	string username;
	string password;
	Login login;

	cout << "\n\n\n\n\t\tEnter username: ";
	cin.ignore();
	getline(cin,username);
	
	if(username == ""){
		
		login.login_page();
		
	}
	
	
	while(username!="staff"){
		
		cout << "\n\t\tWrong username. Try again." << endl;
		cout << "\t\tOR PRESS <ENTER> return to login page" << endl;
		
		cout << "\n\t\tUsername: ";
		getline(cin,username);
		
		if(username == ""){
			
			login.login_page();
			
		}
		
	}
	
	cout << "\t\tEnter password: ";
	getline(cin, password);
	
	if(password == ""){
		
		login.login_page();
		
	}
	
	while(password!="abc123"){
		
		cout << "\n\t\tWrong password. Try again." << endl;
		cout << "\t\tOR PRESS <ENTER> return to login page" << endl;
		
		cout << "\n\t\tEnter password: ";
		getline(cin, password);
		
		if(password == ""){
			
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
	cout << "\t\t5. Exit the program" << endl;
	
	cout << "\n\n\t\tPlease enter your option: ";
	cin >> opt;
	
	while(opt!=1 && opt!=2 && opt!=3 && opt!=4 && opt!=5){
		
		system("cls");
		
		cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
		cout << "\t\t1. Display customer details" << endl;
		cout << "\t\t2. Edit customer profile" << endl;
		cout << "\t\t3. Book a ticket" << endl;
		cout << "\t\t4. Proceed to payment" << endl;
		cout << "\t\t5. Exit the program" << endl;
				
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
		cout << "\t\tPress <1> to stay at customer page." << endl;
		cout << "\t\tPress <0> to exit the program." << endl;
		
		cout << "\n\n\t\tYour option: ";
		cin >> opt;
		
		while(opt!=1 && opt!=0){
			
			cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
			cout << "\t\tPress <1> to stay at customer page." << endl;
			cout << "\t\tPress <0> to exit the program." << endl;
			
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
			cout << "\t\t5. Exit the program" << endl;
			
			cout << "\n\n\t\tPlease enter your option: ";
			cin >> opt;
			
		}else{
			AllocConsole();
			int msgboxID2 = MessageBox(FindWindowA("ConsoleWindowClass", NULL), "Hi, Do you want to exit?", "Bus Reservation System", MB_YESNO| MB_ICONHAND | MB_DEFBUTTON2 | MB_SYSTEMMODAL);
			if (msgboxID2 == IDYES)
			{
				AllocConsole();
				int msgboxID = MessageBox(FindWindowA("ConsoleWindowClass", NULL), "Thanks for visiting. Have a nice day!", "Bus Reservation System", MB_OK | MB_ICONASTERISK | MB_DEFBUTTON2 | MB_SYSTEMMODAL);
				if (msgboxID == IDOK)
				{
					exit(1);
				}
			}
			else
				continue;
		}
		
		while(opt!=1 && opt!=2 && opt!=3 && opt!=4 && opt!=5){
			
			cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
			cout << "\t\t1. Display customer details" << endl;
			cout << "\t\t2. Edit customer profile" << endl;
			cout << "\t\t3. Book a ticket" << endl;
			cout << "\t\t4. Proceed to payment" << endl;
			cout << "\t\t5. Exit the program" << endl;
					
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
	
	cout << "\n\n\n\n\t\tEnter username: ";
	cin.ignore();
	getline(cin,username);
	
	if(username == ""){
		
		login.login_page();
		
	}
	
	while(username!="driver1" && username!="driver2" && username!="driver3"){
		
		cout << "\n\tWrong username. Try again." << endl;
		cout << "\tOR PRESS <ENTER> return to login page" << endl;
		
		cout << "\n\tUsername: ";
		getline(cin,username);
		
		if(username == ""){
			
			login.login_page();
			
		}
		
	}
	
	cout << "\t\tEnter password: ";
	getline(cin,password);
	
	if(password == ""){
		
		login.login_page();
		
	}
	
	while(password!="abc123"){
		
		cout << "\n\tWrong password. Try again." << endl;
		cout << "\tOR PRESS <ENTER> return to login page" << endl;
		
		cout << "\n\tEnter password: ";
		getline(cin,password);
		
		if(password == ""){
			
			login.login_page();
			
		}
		
	}
	
	cout << "\n\n\n\t\tLogged in successfully." << endl;
	
	driver_page(username);
	
	login.login_page();
	
}

void admin_page(){
	
	Admin admin("Ali Akau Mutu","012-34567890","1001");
	Login login;
	
	int opt;
	
		
	do{
		
		system("cls");
	
		cout << "\n\n\n\n\t\tAdmin Menu" << endl;
		cout << "\t\t------------------------------" << endl;
		cout << "\t\t1. Display admin details" << endl;
		cout << "\t\t2. Edit admin profile" << endl;
		cout << "\t\t3. Add bus details" << endl;
		cout << "\t\t4. Delete bus details" << endl;
		cout << "\t\t5. Exit to login page" << endl;
		
		cout << "\n\n\t\tPlease enter your option: ";
		cin >> opt;
		
		while(opt!=1 && opt!=2 && opt!=3 && opt!=4 && opt!=5){
			
			system("cls");
			
			cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
			cout << "\t\t1. Display admin details" << endl;
			cout << "\t\t2. Edit admin profile" << endl;
			cout << "\t\t3. Add bus details" << endl;
			cout << "\t\t4. Delete bus details" << endl;
			cout << "\t\t5. Exit to login page" << endl;
					
			cout << "\n\n\t\tYour option: ";
			cin >> opt;
			
		
		}
		
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
				
			case 5:
				login.login_page();
				return;
						
				
		}
		
		cout << "\n\n\t\tDo you wish to continue your journey?" << endl;
		cout << "\t\tPress <1> to stay at admin page." << endl;
		cout << "\t\tPress <0> to log out." << endl;
		
		cout << "\n\n\t\tYour option: ";
		cin >> opt;
		
		while(opt!=1 && opt!=0){
			
			cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
			cout << "Press <1> to stay at admin page." << endl;
			cout << "Press <0> to log out." << endl;
			
			cout << "\n\n\t\tYour option: ";
			cin >> opt;
			
		}
		
		system("cls");
		
		if(opt == 1){
			
			continue;
			
		}else{
			AllocConsole();
			if (MessageBox(FindWindowA("ConsoleWindowClass", NULL), "Hi, Do you want to exit?", "Bus Reservation System", MB_YESNO| MB_ICONHAND | MB_DEFBUTTON2 | MB_SYSTEMMODAL) == IDYES)
			{
				cout << "\n\n\n\t\tThanks for visiting. Have a nice day" << endl;
				break;
			}
			else
				continue;
		}	
		
	}while(opt != 5);
	
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
		cout << "\t\tPress <1> to stay at Add Trip Menu." << endl;
		cout << "\t\tPress <0> to exit Add Trip Menu." << endl;
		
		cout << "\n\n\t\tYour option: ";
		cin >> opt;
		
		while(opt!=1 && opt!=0){
			
			cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
			cout << "Press <1> to stay at Add Trip Menu." << endl;
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
	
	fstream append("DESTINATION.txt", ios::out | ios::app);
	
	cout << "\n\n\t\tPlace to add -> ";
	cin.ignore();
	getline(cin,place);
	
	if(append.is_open()){
		
		append << place << endl;
		cout << "\t\tThe destination is added successfully." << endl;
		cout << "\n\t\tNow you can add new trip for this destination..." << endl;
		
	}else{
		
		cout << "Unable to oen file";
		
	}

	append.close();
	
}

void add_trip(){
	
	const int infoNum = 11;
	string data;
	
	fstream trip;
	trip.open("TRIP.txt",ios::out | ios::app);
	
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
	
	cout << "\n\n\t Enter the new destination -> ";
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
		cout << "\t\tPress <1> to stay at Delete Trip Menu." << endl;
		cout << "\t\tPress <0> to exit Delete Trip Menu." << endl;
		
		cout << "\n\n\t\tYour option: ";
		cin >> opt;
		
		while(opt!=1 && opt!=0){
			
			cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
			cout << "Press <1> to stay at Delete Trip Menu." << endl;
			cout << "Press <0> to exit Delete Trip Menu." << endl;
			
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
	
	cout << "\n\n\t\tPlace to delete:\t";
	cin.ignore();
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
	Login login;
	
	if(username == "driver1"){
		
		driver = Driver("Mutu","011-11111111","3001");
		
	}else if(username == "driver2"){
		
		driver = Driver("Ah Chong","012-44565678","3002");
		
	}else{
		
		driver = Driver("Muhammad","013-95433300","3003");
		
	}
	
	int opt;
	
	do{
		
		system("cls");
	
		cout << "\n\n\n\n\t\tDriver Menu" << endl;
		cout << "\t\t------------------------------" << endl;
		cout << "\t\t1. Display driver details" << endl;
		cout << "\t\t2. Edit driver name" << endl;
		cout << "\t\t3. Edit driver phone number" << endl;
		cout << "\t\t4. Edit driver ID" << endl;
		cout << "\t\t5. Exit to login page" << endl;
		
		cout << "\n\n\t\tPlease enter your option: ";
		cin >> opt;
		
		while(opt!=1 && opt!=2 && opt!=3 && opt!=4 && opt!=5){
			
			system("cls");
			
			cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
			cout << "\t\t1. Display driver details" << endl;
			cout << "\t\t2. Edit driver name" << endl;
			cout << "\t\t3. Edit driver phone number" << endl;
			cout << "\t\t4. Edit driver ID" << endl;
			cout << "\t\t5. Exit to login page" << endl;
					
			cout << "\n\n\t\tYour option: ";
			cin >> opt;
			
		
		}
		
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
				
			case 5:
				login.login_page();
				return;
						
				
		}
		
		cout << "\n\n\t\tDo you wish to continue your journey?" << endl;
		cout << "\t\tPress <1> to stay at driver page." << endl;
		cout << "\t\tPress <0> to log out." << endl;
		
		cout << "\n\n\t\tYour option: ";
		cin >> opt;
		
		while(opt!=1 && opt!=0){
			
			cout << "\n\t\tYou enter a wrong option. Please re-input:" << endl;
			cout << "Press <1> to stay at driver page." << endl;
			cout << "Press <0> to log out." << endl;
			
			cout << "\n\n\t\tYour option: ";
			cin >> opt;
			
		}
		
		system("cls");
		
		if(opt == 1){
			
			continue;
			
		}else{
			AllocConsole();
			if (MessageBox(FindWindowA("ConsoleWindowClass", NULL), "Hi, Do you want to exit?", "Bus Reservation System", MB_YESNO| MB_ICONHAND | MB_DEFBUTTON2 | MB_SYSTEMMODAL) == IDYES)
			{
				cout << "\n\n\n\t\tThanks for visiting. Have a nice day" << endl;
				break;
			}
			else
				continue;
		}	
		
	}while(opt != 5);
	
	return;
}

int main(){
	
//	initwindow(600, 500, "Bus Reservation System");
	
	system("COLOR 70");
	system("cls");
	printf("\e[?251");
	
	SetConsoleCP(437);
	SetConsoleOutputCP(437);
	
	int bar1 = 177, bar2 = 219;
	cout << "\n\n\n\t\t\t\taWELCOME BACK!";
	cout << "\n\t\t\t\t";
	cout << "\n\n\n\t\t\t\tLoading...";
	cout << "\n\n\n\t\t\t\t";
	
	for(int i = 0; i < 25; i++)
		cout << (char)bar1;
		
	cout << "\r";
	cout << "\t\t\t\t";
	for(int i = 0; i < 25; i++)
	{
		cout << (char)bar2;
		Sleep(150);
	}
	
	cout << "\n\t\t\t\t" << (char)1 << "!";
//	system("Pause");
	
	Login login;
	login.login_page();
	
	return 0;
	
}
