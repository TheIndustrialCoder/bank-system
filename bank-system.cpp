#include "Validation.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"
#include "FileManager.h"
using namespace std;

//Intializing static members
int Client::idCounter = 1;
int Employee::idCounter = 1;
int Admin::idCounter = 1;
char Parser::delimiter = ',';

int main()
{
	//Client c("Abdelaziz", "1234456789", 3200.0);
	//FileHelper::saveClient(c);
	//string fileName = "ClientsLastIdUsed.txt";
	//FileHelper::saveLast(fileName, 500);
	//cout << FileHelper::getLast(fileName);
	/*vector<Client> data = FileHelper::getClients();
	for (int i = 0; i < data.size(); i++) {
		data[i].display();
	}*/

	FileManager::RemoveAllClients();
   
}



	/*while (true) {
		try {
			string name{ "Mahmoud Amr" }, password{"123456789"};
			double balance{5000};
			getline(cin, name);
			getline(cin, password);
			cin >> balance;
			cin.ignore();
			Client client(1, name, password, balance);
			client.display();
			client.checkBalance();
		
			client.deposit(500);
			cout << "After deposit: " << endl;
			client.display();
		
			client.withdraw(100);
			cout << "After withdrawal: " << endl;
			client.checkBalance();
		
			Client recipient(2, "John Doe", "password123", 1500);
			client.transferTo(recipient, 200);
			cout << "After transfer: " <<  endl;
			client.display();
			cout << "Recipient's balance: " << endl;
			recipient.display();
			break;
		
		} catch (const exception& e) {
			cout << e.what() << endl;
		}
	}
	
	cout << "===========================================================" << endl;*/