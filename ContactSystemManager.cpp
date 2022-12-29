#include<iostream>
//include<string>
using namespace std;

# define  Max  50  // Maximum number of people


// Define a contact structure
struct Contacts
{
	string name;		 
	string phone;		
	string email;		 
};

// Define an address book structure
struct addressbook
{
	Contacts contactsArry[Max];	
	int addressBook_count = 0 ;				
};

// show the main menu
void showMenu()
{
	cout << "********************************" << endl;
	cout << " ***** Address Book Management System ***** " << endl;
	cout << "********************************" << endl;
	cout << " ***** 1. Add contacts ***** " << endl;
	cout << " ***** 2. display contacts ***** " << endl;
	cout << " ***** 3. Delete contact ***** " << endl;
	cout << " ***** 4. Find contact ***** " << endl;
	cout << " ***** 5. Modify contacts ***** " << endl;
	cout << " ***** 0. exit address book ***** " << endl;
	cout << "********************************" << endl;

}

// add a contact
void AddContacts(addressbook* abs)
{
	// Check if address book full
	if (abs->addressBook_count == Max)
	{
		cout << "The address book is full and cannot be added! " << endl;
		return;
	}
	else
	{
		string name;
		cout << " Please enter the name: " << endl;
		cin >> name;
		abs->contactsArry[abs->addressBook_count].name = name;
	
		string phone;
		cout << " Please enter the phone number: " << endl;
		cin >> phone;
		abs->contactsArry[abs->addressBook_count].phone = phone;

		string add;
		cout << " Please enter Email: " << endl;
		cin >> add;
		abs->contactsArry[abs->addressBook_count].email = add;

		abs->addressBook_count += 1; // increase counter
		cout << " Added successfully! " << endl;
		system("pause");
		system("cls");
	}

}

// display contacts
void ShowContacts(addressbook* abs)
{
	if (abs->addressBook_count == 0)
	{
		cout << " No contact, please add it first! " << endl;
	}
	else
	{
		// display all contacts
		for (int i = 0; i < abs->addressBook_count; i++)
		{
			cout << " Name: " << abs -> contactsArry [i]. name << " Telephone: " << abs ->contactsArry[i].phone << " Phone:" << abs->contactsArry[i].email << endl;
            cout << "---------------------------------------------------------------------------" << endl;
        }
	}
	system("pause");
	system("cls");
}

// Check if someone exists
int IsExit(addressbook* abs, string name)
{
	for (int i = 0; i < abs->addressBook_count; i++)
	{
		if (abs->contactsArry[i].name == name)
		{
			return i;
		}
	}
	return -1;
}

// delete contact
void DeleteContacts(addressbook* abs)
{
	string name;
	cout << " Please enter the name of the user you want to delete: " << endl;
	cin >> name;
	//Check if the contact exists
	int index = IsExit(abs, name);
	// if the contact exists
	if (index > -1)
	{
		for (int i = index; i < abs->addressBook_count - 1; i++)
		{
			Contacts temp = abs->contactsArry[i];
			abs->contactsArry[i] = abs->contactsArry[i + 1];
			abs->contactsArry[i + 1] = temp;
		}
		// Decrease Counter
		abs->addressBook_count--;
		cout << " Delete successfully! " << endl;
	}
	else 
	{
		cout << " No such person found " << endl;
	}
	system("pause");
	system("cls");
}

// find contacts
void GetContacts(addressbook* abs)
{
	// Record the name entered by the user
	string name;
	cout << " Please enter the name of the user you are looking for " << endl;
	cin >> name;
	//Check if the contact exists
	int index = IsExit(abs, name);
	if (index > -1)
	{
		// exists
		cout << "Name:" << abs->contactsArry[index].name << endl;
		cout << "Phone:" << abs->contactsArry[index].phone << endl;
		cout << "Email:" << abs->contactsArry[index].email << endl;
	}
	else
	{
		// does not exist
		cout << " No such person found " << endl;
	}
	system("pause");
	system("cls");

}

// Modify the contact
void ModifyContacts(addressbook* abs)
{
	// Record the name entered by the user
	string name;
	cout << " Please enter the user name you want to modify " << endl;
	cin >> name;
	//Check if the contact exists
	int index = IsExit(abs, name);
	if (index > -1)
	{
		// exists
		string name;
		cout << " Please enter the modified name: " << endl;
		cin >> name;
		abs->contactsArry[index].name = name;

		string phone;
		cout << " Please enter the modified phone number: " << endl;
		cin >> phone;
		abs->contactsArry[index].phone = phone;

		string add;
		cout << " Please enter the modified address: " << endl;
		cin >> add;
		abs->contactsArry[index].email = add;
		cout << " Modified successfully! " << endl;
	}
	else
	{
		// does not exist
		cout << " No such person found " << endl;
	}
	system("pause");
	system("cls");
}



int main()
{
	// Record the information entered by the user
	int select = 0;
	// Define an address book structure
	addressbook abs;
	// Set the current number of people to zero
	abs.addressBook_count = 0;

	while (true)
	{
		// show the main menu
		showMenu();

		cin >> select;
		switch (select)
		{
		case  1 : // 1. Add a contact
			AddContacts (& abs );	 // Address transfer
			break;
		case  2 : // 2. Display contacts
			ShowContacts (& abs ); // Address transfer
			break;
		case  3 : // 3. Delete the contact
			DeleteContacts(&abs);
			break;
		case  4 : // 4. Find contacts
			GetContacts(&abs);
			break;
		case  5 : // 5. Modify the contact
			ModifyContacts(&abs);
			break;
		case  0 : // 0, exit the address book
			cout << " Thanks for using Contact Management System, goodbye! " << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}


	system ( " pause " ); // press any key to continue
	return 0;
}