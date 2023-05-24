//Alexis Urias
//CSE 310 Spring 23

#include <iostream>
#include <string>


using namespace std;

void selectionAction(int); // menu selection function

int addCityTail(string cityName, int cityPopulation, int householdIncome); // forward declaration, add city to the tail of the list
int addCityHead(string cityName, int cityPopulation, int householdIncome); // add city to the head of the list
void displayLargestPopulation();										// display the city with the largest population
void displayAllCityRecords();											// display the record for every city in the list

struct cityList {			// struct for the list of cities
	struct city* city;
	struct cityList* next;
};

struct city {				// struct for the city itself
	string name;			// include name of the city, the population of the city, and the median household income of the city
	int population = 0;
	int income = 0;
};

struct cityList* head = NULL;		// set both head pointer and tail pointer to NULL
struct cityList* tail = NULL;

int main() {

	int value = 0;

	do {	// menu selections to add city (head or tail), display largest city and display all cities
		
		cout << "\n1. Add city record to the tail.\n";
		cout << "2. Add city record at the head.\n";
		cout << "3. Display the city with largest population.\n";
		cout << "4. Display all the city records.\n";
		cout << "5. Exit\n";
		cin >> value;			// read in selection value from the user
		cin.ignore();
		selectionAction(value);

	} while (value != 5);

	return 0;
}

void selectionAction(int val) {

	string cityName;
	int cityPopulation, householdIncome, output = 0;

	switch (val)		// switch executes certain functions based on what the user selects
	{
	case 1:

		cout << "\nEnter city name: "; // gets values from the user
		getline(cin, cityName);
		cout << "Enter city population: ";
		cin >> cityPopulation;
		cin.ignore();
		cout << "Enter city median income: ";
		cin >> householdIncome;
		cin.ignore();

		output = addCityTail(cityName, cityPopulation, householdIncome); // calls the function which adds the city to the tail
		if (output == 0) {
			cout << "\nCity added to the tail of the list.\n";
		}
		else {
			cout << "\n The city was not added to the list.\n"; // Should never get here since the function will always return zero but if the program was larger...
		}
		break;

	case 2:

		cout << "\nEnter city name: ";  // gets user input
		getline(cin, cityName);
		cout << "Enter city population: ";
		cin >> cityPopulation;
		cin.ignore();
		cout << "Enter city median income: ";
		cin >> householdIncome;
		cin.ignore();

		output = addCityHead(cityName, cityPopulation, householdIncome);  // calls the function that adds the city to the head
		if (output == 0) {
			cout << "\nCity added to the head of the list.\n";			// displays that the city was added to the list
		}
		else {
			cout << "\n The city was not added to the list.\n";			// again the function will return 0 always but for readability....
		}
		break;
	case 3:
		displayLargestPopulation();  // calls the function that displays the city with the largest population
		break;
	case 4:
		cout << endl;
		displayAllCityRecords();	// calls the function that displays all the city records
		break;
	case 5:
		break;
	}


}

int addCityTail(string cityName, int cityPopulation, int householdIncome) {

	struct cityList* newCityNode = new cityList();		// memory for the city to be added
	newCityNode->city = new city();						

	newCityNode->city->name = cityName;					// pass values from user into the new city node
	newCityNode->city->population = cityPopulation;
	newCityNode->city->income = householdIncome;
	newCityNode->next = NULL;		// set the next node to NULL

	if (head == NULL) {			// if the head is NULL set both the head and tail to the new node
		head = newCityNode;
		tail = newCityNode;
	}
	else {
		struct cityList* tempList = head;  // to iterate through the list
		while (tempList->next != NULL) {
			tempList = tempList->next;
		}
		tempList->next = newCityNode;		// add the new city node at the current place
		tail = newCityNode;					// insert at the tail
	}

	return 0;
}



int addCityHead(string cityName, int cityPopulation, int householdIncome) {

	struct cityList* newCityNode = new cityList();		// memory for new city
	newCityNode->city = new city();
	
	newCityNode->city->name = cityName;					// get the user input and add it to the new city node
	newCityNode->city->population = cityPopulation;
	newCityNode->city->income = householdIncome;

	newCityNode->next = head;		// insert the new node at the head of the list
	head = newCityNode;


	return 0;
}



void displayLargestPopulation() {

	if (head == NULL) {					// if the list is empty display so and return
		cout << "\nNo city records.\n";
		return;
	}

	struct cityList* tempList = head;		// set tempList to the head
	int largestPopulation = tempList->city->population;		// set largest population variable using tempList

	struct city* cityLP = tempList->city;


	while (tempList != NULL) {								// iterate through the tempList to find the largest population
		if (tempList->city->population > largestPopulation) {
			largestPopulation = tempList->city->population;  // find the max value for population
			cityLP = tempList->city;		// assign that specific city to the largest population city
		}
		tempList = tempList->next;			// go to the next record
	}

	cout << "\n";		// display the output format
	cout << cityLP->name;
	cout << ", " << cityLP->population;
	cout << ", $" << cityLP->income << "." << endl;
	cout << endl;

}



void displayAllCityRecords() {

	struct cityList* tempList = head;

	if (head == NULL) {				// if the list is empty display so and return
		cout << "\nNo city records.\n";
		return;
	}

	while (tempList != NULL) {	// iterate through tempList and display each record

		cout << tempList->city->name;		// display the city in proper format
		cout << ", " << tempList->city->population;
		cout << ", $" << tempList->city->income << "." << endl;
		cout << endl;

		tempList = tempList->next;
	}

}