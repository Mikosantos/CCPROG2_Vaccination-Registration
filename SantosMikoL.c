#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <windows.h> 
#include <conio.h> 
#include <time.h>
#include <wchar.h>

#define STR10 11
#define MAX 100
#define MAX_USERS 100
#define MAX_APPOINTMENTS 100
#define MAX_FAQS 100
#define MAX_STRINGLEN 80
#define MAX_ENTRIES 100

typedef char str10[STR10]; //@typedef: new data type for strings that have a size of 10
typedef char str80[81];

struct User 
{
	int userID; //userID: variable for user ID
	long long int contact; //contact: variable for user contact number
	char fullName[21]; //fullName: variable for user name (maximum of 20)
	char address[31]; //address: variable for user address (maximum of 30)
	str10 password;	//password: variable for user password
	str10 sex;	
	str10 string[11]; //string: variable for strings (maximum of 10)
};

struct Appointment
{
	int appID; //appID: variable for appointment ID
	char customerName[21]; //customerName: variable for customer name (maximum of 20)
	char time[7]; //time: varaible for time (maximum of 6)
	str10 string[5]; //string: variable for strings (maximum of 10)
};

struct Chatbot
{
	str80 questions;
	str80 answers;
};

void displayHeader();
void displayPlainLines();
void displayMain(struct User userRegistrant[], struct Appointment userAppointment[], struct Chatbot FAQ[], int* i, int* j, int *k);
void mainFeatures();

void displayVaccRegMenu(struct User userRegistrant[], struct Appointment userAppointment[], int* i, int* j);
void register_user(struct User userRegistrant[], int* i);

void displayVaccAppointment(struct User userRegistrant[], struct Appointment appointmentRequest[], int* i, int* j);
int loginVaccAppointment(struct User userRegistrant[], int* i);
int CheckUserCredentials(struct User userRegistrant[], int userID, char password[], int *i);
void apptReq(struct User userRegistrant[], struct Appointment userAppointment[], int *i, int* j);
void displayApptAccs(struct Appointment userAppointment[], int* j);
void displayRegAccs(struct User userRegistrant[], int* i);
void manageAppointment(struct User userRegistrant[], struct Appointment userAppointment[], int* i, int* j);
void cancelAppt(struct User userRegistrant[], struct Appointment userAppointment[], int* i, int* j);
void reschedDT(struct User userRegistrant[], struct Appointment userAppointment[], int* i, int* j);
void swapStrings(char *str1, char *str2);
void changeVLVT(struct User userRegistrant[], struct Appointment userAppointment[], int* i, int* j);

int apptIDCheckingDuplication(struct Appointment userAppointment[], int newAppID, int* j);
int userIDCheckingDuplication(struct User userRegistrant[], int newUserID, int* i);

void exitPrompt(struct User userRegistrant[], struct Appointment userAppointment[], struct Chatbot FAQ[]);
void chatbotFAQ();

int loginDataMananagement(struct User userRegistrant[], int *i);
void displayDataManMenu(struct User userRegistrant[], struct Appointment userAppointment[], struct Chatbot FAQ[], int* i, int* j, int* k);
void DataManMenu(struct User userRegistrant[], struct Appointment userAppointment[], struct Chatbot FAQ[], int *i, int* j, int* k);

void userManagementMenu(struct User userRegistrant[], int* i);

void deleteNewUser(struct User userRegistrant[], int *i);
int compareUsers(const void *a, const void *b);
void addNewUser(struct User userRegistrant[], int *i);
void viewAllUser(struct User userRegistrant[], int* i);
char* get_first_word(char* input, int width);
void editNewUser(struct User userRegistrant[], int *i);


void appointmentManagemantMenu(struct Appointment userAppointment[], int *j);
void addNewAppointment(struct Appointment userAppointment[], int *j);
void viewAllAppointment(struct Appointment userAppointment[], int *j);
void editNewAppointment(struct Appointment userAppointment[], int *j);
void deleteNewAppointment(struct Appointment userAppointment[], int *j);

void chatbotManagemanetMenu(struct Chatbot FAQ[], int *k);
void addNewFAQ(struct Chatbot FAQ[], int *k);
void viewAllFAQ (struct Chatbot FAQ[], int *k);
void gotoxy(int x, int y);
void editNewFAQ (struct Chatbot FAQ[], int *k);
void deleteNewFAQ (struct Chatbot FAQ[], int *k);

void ExportMenu(struct User userRegistrant[], struct Appointment userAppointment[], struct Chatbot FAQ[], int* i, int* j,int* k); 
void importMenu(struct User userRegistrant[], struct Appointment userAppointment[], struct Chatbot FAQ[], int* i, int* j,int* k);

/*
displayHeader - displays the header of the vaccination registration with chatbot app
@return void
Precondition: None
*/
void
displayHeader()
{
	printf("\n\n\n\n\n\n");
    printf("\t\t\t\t\t            _____________________________________________________________________   \n");
    printf("\t\t\t\t\t    _______|                                                                     |________ \n");
    printf("\t\t\t\t\t    \\      |           V A C C I N A T I O N  R E G I S T R A T I O N            |       / \n");
    printf("\t\t\t\t\t     \\     |                   W I T H  C H A T  B O T  A P P                    |      /  \n");
    printf("\t\t\t\t\t     /     |_____________________________________________________________________|      \\  \n");
    printf("\t\t\t\t\t    /______)                                                                   (_________\\ \n");
}

/* displayPlainLines() : for interface single plain line
@return void
Precondition: None 
*/
void
displayPlainLines()
{
	printf("============================================================================================================================================================================\n");
}
/*
	displayMain: displays the main menu of the vaccination appointment system and allows the user to select from different options.
	@param userRegistrant: array of struct User containing information about registered users.
	@param userAppointment: array of struct Appointment containing information about users' appointment schedules.
	@param FAQ: array of struct Chatbot containing frequently asked questions and answers.
	@param i: pointer to an integer representing the index of the last registered user.
	@param j: pointer to an integer representing the index of the last scheduled appointment.
	@param k: pointer to an integer representing the index of the last frequently asked question.
	@return void
	Precondition: The arrays userRegistrant, userAppointment, and FAQ must be initialized with valid data. The pointers i, j, and k must be initialized with valid values.
*/
void
displayMain(struct User userRegistrant[], 
			struct Appointment userAppointment[], 
			struct Chatbot FAQ[], 
			int *i, 
			int *j, 
			int *k)
{
	int check; //@check: initiate the start of a loop
	int nChoice; //@int choice: variable for user's choice
	int repeat = 1; 

	do
	{
		system("cls");
		//This loop ensures that the user chooses any of the given choices (1, 2, or 3).
		do
		{ 
			check=0;
			mainFeatures(); 
			scanf("%d" ,&nChoice);
			if (nChoice!=1 && nChoice!=2 && nChoice!=3)
			{
				system("cls");
				check=1;	   //if none of the given choice is selected, loop it back
			}
		}while(check);
		//This switch case statement executes different actions depending on the user's choice.
		switch (nChoice)
		{
			case 1 : displayVaccRegMenu(userRegistrant,userAppointment,i,j);      //user chooses Vaccine Registration Menu
					break;
			case 2 :displayDataManMenu(userRegistrant,userAppointment,FAQ,i,j,k); //user chooses Data Management Menu
					break;
			case 3: system("cls");
					repeat = 0;
					exitPrompt(userRegistrant, userAppointment, FAQ);
					break;
			default : 
					break;
		}
	}while (repeat);
}
/*  mainFeatures() : displaying first options when program was run	*/
void
mainFeatures()
{
    system("cls");
	displayHeader(); //Will display the header
	printf("\n\n \t\t\t\t\t\t\t\t\t     H O M E  M E N U ");
    printf ("\n\n \t\t\t\t\t\t\t\t      1) ");
    printf ("Vaccination Registration Menu");
    printf("\n \t\t\t\t\t\t\t\t      2) ");
    printf("Data Management Menu");
    printf("\n \t\t\t\t\t\t\t\t      3) ");
    printf("Exit");
    printf("\n\n \t\t\t\t\t\t\t\t      Choose command: ");
}

/*
displayVaccRegMenu - Displays the menu for vaccine registration
@param userRegistrant - Array of User structures containing user registration details
@param userAppointment - Array of Appointment structures containing user appointment details
@param i - Pointer to an integer variable containing the index of the last registered user
@param j - Pointer to an integer variable containing the index of the last set vaccination appointment
@return None
Precondition: None
*/
void 
displayVaccRegMenu(struct User userRegistrant[],
                struct Appointment userAppointment[],
                int* i,
                int* j)
{
    int nChoice = 0, check = 1;
	do{
        system("cls");
        displayHeader(); //Will display the header

		//Display the Vaccine Registration Menu options and prompt the user to choose a command.
		printf("\n\n \t\t\t\t\t\t\t\t\t     H O M E  M E N U ");
		printf ("\n\n\t\t\t\t\t\t\t\t      1) ");
		printf("User Registration");
		printf ("\n \t\t\t\t\t\t\t\t      2) ");
		printf("Set Vaccination Appointment");
		printf ("\n \t\t\t\t\t\t\t\t      3) ");
		printf("Chatbot FAQ's");
		printf ("\n \t\t\t\t\t\t\t\t      4) ");
		printf("Back");
        printf ("\n\n \t\t\t\t\t\t\t\t      Choose command: ");
        scanf("%d", &nChoice);
		fflush(stdin);
        //This switch case statement executes different actions depending on the user's choice.
        switch (nChoice)
		{
            case 1: //User chooses User Registration
                register_user(userRegistrant, i); 
				break;
            case 2: //User chooses Set Vaccination Appointment
                displayVaccAppointment(userRegistrant, userAppointment, i, j); 
                break;
            case 3: //User chooses Chatbot FAQ's
                system("cls");  
                chatbotFAQ();
                break;
            case 4:  //User chooses to go Back
                check = 0;
				break;
			default:  //If user chooses a wrong input, then loop it back to the menu
				check = 1;
                break;
        }
	}while(check);
}

/*
	register_user: registers a new user in the system and stores user information such as userID, password, full name, address, contact number, and sex.
	@param userRegistrant[] array of struct User that contains user information
	@param i pointer to the index of the array
	@return void
	Precondition: struct User must be defined with userID, password, fullName, address, contact, and sex as its fields.
*/
void
register_user(struct User userRegistrant[],
			  int* i)
{
	char input[12]; // allocate enough space to store 11-digit number and null terminator
	int check, len; 
	int index;
	char password[11];
	char ch;

	do  // do-while loop to ask for user input until valid userID is entered
	{
		check = 0;
		do  // nested do-while loop to ask for valid 4 digit userID
		{
			check = 0;
			system("cls");
			displayHeader();
			printf("\n\n \t\t\t\t\t\t\t\t  R E G I S T R A T I O N  S I G N - U P");
			 printf("\n\n\t\t\t\t\t\t\t\t    Preferred userID :    ");
			scanf("%d", &userRegistrant[*i].userID);
			fflush(stdin);

			if(userRegistrant[*i].userID < 1000 || userRegistrant[*i].userID > 9999)
			{
				check = 1;
				printf("\n\t\t\t\t\t\t\t\t\tUser ID must be 4 digit numbers");
				getch();
			}
		} while (check==1);
		 // check if userID already exists
		if(userIDCheckingDuplication(userRegistrant, userRegistrant[*i].userID, i)==1)
		{
			check = 1;
			printf("\n\t\t\t\t\t\t\t\t\tThis userID already exists. Please type another.");
			getch();
		}
	}while(check);
	// do-while loop to ask for valid password input
    do {
        
        printf("\t\t\t\t\t\t\t\t\t    Password :    ");
        index = 0;
        ch = ' ';   
        while (ch != '\r' && ch != '\n') 
		{ 
			ch = getch();
            if (ch == '\b') // Handle backspace
			{ 
                if (index > 0) 
				{
                    index--;
                    putchar('\b');
                    putchar(' ');
                    putchar('\b');
                }
            }
            else if (index < 10 && ch != '\r' && ch != '\n') { // Handle regular input
                password[index] = ch;
				putchar('*');
				index++;
            }
			
        }
        password[index] = '\0';
		

        // Copy masked input to userRegistrant
        strcpy(userRegistrant[*i].password, password);
		userRegistrant[*i].password[strlen(userRegistrant[*i].password)] = '\0';
        len = strlen(password);
        if (len == 0 || len > 10)
		{
            
            printf("\n\t\t\t\t\t\t\t\t\t(Error)\n");
            check = 1;
        }
        else
		{
            check = 0;
        }
    } while (check);
	// do-while loop to ask for valid full name input
    do {
        
        printf("\n\t\t\t\t\t\t\t\t\t   Full Name :    ");
        scanf(" %[^\n]s", userRegistrant[*i].fullName);
        fflush(stdin);
        if (strlen(userRegistrant[*i].fullName) > 20 || strlen(userRegistrant[*i].fullName) == 0) {
            
            printf("\n\t\t\t\t\t\t\t\t\t(Error)\n");
            check = 1;
        }
        else {
            check = 0;
        }
    } while (check);
	// do-while loop to ask for valid home address input
	do { 
		check = 0;
		printf("\t\t\t\t\t\t\t\t\tHome Address :    ");
		scanf("%30[^\n]%*c", userRegistrant[*i].address);
		fflush(stdin);
		if (strlen(userRegistrant[*i].address) == 0 || strlen(userRegistrant[*i].address) > 30) {
			check = 1;
			printf("\n\t\t\t\t\t\t\t\t\t(Error)\n");
		}
	} while (check);
	// do-while loop to ask for valid contact number input
	
	do {
        check = 0;
        printf("\t\t\t\t\t\t\t\t       Contact number:    ");
        if (fgets(input, 12, stdin) != NULL) { // read input as string with max length 11
            input[strcspn(input, "\n")] = 0; // remove trailing newline character
            if (strlen(input) == 11) { // check if input is 11 characters long
                userRegistrant[*i].contact = strtoll(input, NULL, 10); // convert string to long long integer
            } else if (strlen(input) != 11 )
			{
                check = 1;
                printf("\t\t\t\t\t\t\t\t(Error)\n");
            }
        }
    } while (check);

	do 
		{
			//do-while loop to ask for sex of the user
			check = 0;
			printf("\t\t\t\t\t\t\t\t\t\t Sex :    ");
			scanf(" %[^\n]s", userRegistrant[*i].sex);
			fflush(stdin);
			if (strlen(userRegistrant[*i].sex) == 0 || strlen(userRegistrant[*i].sex) > 10) 
			{
				check = 1;
				printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		} while (check);

	do { // do-while loop to ask for date input of the first dose
	    fflush(stdin);
		check = 0;
		printf("\t\t\t\t\t\t      Date of First Dose (YYYY-MM-DD):    ");
		fgets(userRegistrant[*i].string[0], sizeof(userRegistrant[*i].string[0]), stdin);
		userRegistrant[*i].string[0][strcspn(userRegistrant[*i].string[0], "\n")] = '\0';
		fflush(stdin);
		if (strlen(userRegistrant[*i].string[0]) > 10) {
			check = 1;
			printf("\n\t\t\t\t\t\t\t\t\t(Error)\n");
		}
	} while (check);

	do {  // do-while loop to ask for first dose vaccine type input
		check = 0;
		printf("\t\t\t\t\t\t\t     First Dose Vaccine Type :    ");
		fgets(userRegistrant[*i].string[1], sizeof(userRegistrant[*i].string[1]), stdin);
		userRegistrant[*i].string[1][strcspn(userRegistrant[*i].string[1], "\n")] = '\0';
		fflush(stdin);
		if (strlen(userRegistrant[*i].string[1]) > 10) {
			check = 1;
			printf("\n\t\t\t\t\t\t\t\t\t(Error)\n");
		}
	} while (check);

	do { // do-while loop to ask for valid location input of first vaccination
		check = 0;
		printf("\t\t\t\t\t\t\t      Location of First Dose :    ");
		fgets(userRegistrant[*i].string[2], sizeof(userRegistrant[*i].string[2]), stdin);
		userRegistrant[*i].string[2][strcspn(userRegistrant[*i].string[2], "\n")] = '\0';
		fflush(stdin);
		if (strlen(userRegistrant[*i].string[2]) > 10) {
			check = 1;
			printf("\n\t\t\t\t\t\t\t\t\t(Error)\n");
		}
	} while (check);

	do // do-while loop to ask for date input of second vaccination
	{
		check=0;
		printf("\t\t\t\t\t\t     Date of Second Dose (YYYY-MM-DD):    ");
		fgets(userRegistrant[*i].string[3], sizeof(userRegistrant[*i].string[3]), stdin);
		userRegistrant[*i].string[3][strcspn(userRegistrant[*i].string[3], "\n")] = '\0';
		fflush(stdin);
		if (strlen(userRegistrant[*i].string[3]) > 10)
		{
			check=1;
			printf("\n\t\t\t\t\t\t\t\t\tError)\n");
		}
	} while(check);

	do // do-while loop to ask for vaccine type input of second vaccination
	{
		check=0;
		printf("\t\t\t\t\t\t\t    Second Dose Vaccine Type :    ");
		fgets(userRegistrant[*i].string[4], sizeof(userRegistrant[*i].string[4]), stdin);
		userRegistrant[*i].string[4][strcspn(userRegistrant[*i].string[4], "\n")] = '\0';
		fflush(stdin);
		if (strlen(userRegistrant[*i].string[4]) > 10)
		{
			check=1;
			printf("\t\t\t\t\t\t\t\t\t(Error)\n");
		}
	} while (check);

	do  // do-while loop to ask for location of second vaccination
	{
		check=0;
		printf("\t\t\t\t\t\t\t     Location of Second Dose :    ");
		fgets(userRegistrant[*i].string[5], sizeof(userRegistrant[*i].string[5]), stdin);
		userRegistrant[*i].string[5][strcspn(userRegistrant[*i].string[5], "\n")] = '\0';
		fflush(stdin);
		if (strlen(userRegistrant[*i].string[5]) > 10)
		{
			check=1;
			printf("\n\t\t\t\t\t\t\t\t\t(Error)\n");
		}
	} while (check);
	// do-while loop to ask for date input of booster vaccination
	do 
	{
		check = 0;
		 printf("\t\t\t\t\t\t   Date of Booster Dose (YYYY-MM-DD) :    ");
		fgets(userRegistrant[*i].string[6], sizeof(userRegistrant[*i].string[6]), stdin);
		userRegistrant[*i].string[6][strcspn(userRegistrant[*i].string[6], "\n")] = '\0';
		fflush(stdin);
		if (strlen(userRegistrant[*i].string[6]) > 10)
		{
			check = 1;
			printf("\n\t\t\t\t\t\t\t\t\tInvalid date format. Please enter the date in the format YYYY-MM-DD.\n");
		}
	} while (check);

	do  
	{  // do-while loop to ask for vaccine input of booster vaccination
		check = 0;
		printf("\t\t\t\t\t\t\t   Booster Dose Vaccine Type :    ");
		fgets(userRegistrant[*i].string[7], sizeof(userRegistrant[*i].string[7]), stdin);
		userRegistrant[*i].string[7][strcspn(userRegistrant[*i].string[7], "\n")] = '\0';
		fflush(stdin);
		if (strlen(userRegistrant[*i].string[7]) > 10)
		{
			check = 1;
			printf("\n\t\t\t\t\t\t\t\t\tThe vaccine type should be no more than 10 characters long.\n");
		}
	} while (check);

	do  // do-while loop to ask for location input of booster vaccination
	{
		check = 0;
		printf("\t\t\t\t\t\t\t    Location of Booster Dose :    ");
		fgets(userRegistrant[*i].string[8], sizeof(userRegistrant[*i].string[8]), stdin);
		userRegistrant[*i].string[8][strcspn(userRegistrant[*i].string[8], "\n")] = '\0';
		fflush(stdin);
		if (strlen(userRegistrant[*i].string[8]) > 10)
		{
			check = 1;
			printf("\n\t\t\t\t\t\t\t\t\tThe location should be no more than 10 characters long.\n");
		}
	} while (check);

	 printf ("\n\n\t\t\t\t\t\t\t\t    Account Registered Successfully !");
	 getch();

}

void
displayVaccAppointment(struct User userRegistrant[],
					   struct Appointment userAppointment[],
					   int *i,
					   int *j)
{
	int nChoice='\0';
	int repeat = 1;

	while (repeat)
	{
		system("cls");
		displayHeader();
		// Display appointment menu
		printf("\n\n\t\t\t\t\t\t\t\t\t   A P P O I N T M E N T");
		printf ("\n\n\n \t\t\t\t\t\t\t\t      1) ");
		printf("Appointment Request");
		printf ("\n \t\t\t\t\t\t\t\t      2) ");
		printf("Management Appointment Request");
		printf ("\n \t\t\t\t\t\t\t\t      3) ");
		printf("Exit Menu");
		printf ("\n\n \t\t\t\t\t\t\t\t       Choose command: ");
		scanf("	%d" ,&nChoice); // Get user input for menu option

		switch (nChoice) // Check the user's selected menu option
		{
			case 1 : // If user selects option 1, call the apptReq function
				apptReq(userRegistrant,userAppointment,i, j);
				break;
			case 2 : // If user selects option 2, call the manageAppointment function
				manageAppointment(userRegistrant, userAppointment, i, j);
				break;
			case 3 : // If user selects option 3, exit the menu loop
				repeat = 0;
				break;
			default :  // If user selects any other option, repeat the loop
				repeat = 1;
				break;
		}
	}
}
/*
	loginVaccAppointment - Function for user login
	@param userRegistrant[] an array of User structures representing the user data
	@param i a pointer to an integer representing the index of the last user registered
	@return an integer representing the login status (0 if unsuccessful, 1 if successful)
	Precondition: userRegistrant[] must contain valid user data and i must be a valid integer pointer
*/
int
loginVaccAppointment(struct User userRegistrant[], 
					int *i)
{
    int loginStatus = 0;
    int userID, count = 0;;
	int index = 0;
    char ch;
    char password[10 + 1];

	do
	{  // Input validation for userID to ensure it is a 4 digit number
		do{
			fflush(stdin);
			printf("\n\t\t\t\t\t\t\t\t\t      User ID :  ");
			scanf("%d", &userID);
		}while(userID > 9999 || userID < 1000);
		fflush(stdin);
		printf("\t\t\t\t\t\t\t\t\t     Password :  ");
		// mask password input with asterisks
		ch = getch();

		while (ch != '\r') //Will stop when enter key was pressed
		{
			if (ch == '\b') 
			{// handle backspace to erase the password input
				if (index > 0)
				{
					index--;
					putchar('\b');
					putchar(' ');
					putchar('\b');
				}
			}
			else if (index < 10) 
			{
				password[index++] = ch;
				putchar('*');
			}

			ch = getch();
		}
		password[index] = '\0';
		
		// validate password input to ensure it is between 1-10 characters
		int len = strlen(password);
		if (len == 0 || len > 10)
		{
			printf("\n\t\t\t\t\t\t\t\t(Error)\n");
			return loginStatus;
		}
		// Check if the user credentials match any of the registered user in the system
		loginStatus = loginDataMananagement(userRegistrant, i);
	} while (count > 3 && !loginStatus);  // if more than 3 attempts or if login is successful
	
    return loginStatus;
}
/*
	CheckUserCredentials - This function checks the credentials of the user attempting to login.
	@param userRegistrant[] - An array of struct User containing the user data.
	@param userID - An integer representing the user ID of the registrant.
	@param password[] - A character array representing the password entered by the user.
	@param i - A pointer to an integer that holds the index of the last user registered.
	@return int - Returns 1 if login is successful, 0 if login fails.
	Precondition: The userRegistrant array must be populated with valid user data, the userID and password parameters must be valid inputs, and i must hold the index of the last registered user.
*/
int
CheckUserCredentials(struct User userRegistrant[],
					 int userID,
					 char password[],
					 int *i)
{
    int index, userExists = 0, passwordMatch = 0, found = 0;
	printf("\n");
	for (index = 0; index <= *i; index++) // Loop through all registered users
	{
		if (userRegistrant[index].userID == userID)  // Check if the userID exists
		{
			userExists = 1; 
			if (strcmp(userRegistrant[index].password, password) == 0)  // Check if the password matches the userID
			{
				passwordMatch = 1;
				found = 1;
			}
		}
	}
	if (found && passwordMatch && userExists) // Return status based on login credentials
	{
		printf("\n\n\t\t\t\t\t\t\t\t          Status: Login successful.");
		getch();
		return 1;
	}
	if (!passwordMatch && userExists && !found)
	{
		printf("\n\n\t\t\t\t\t\t\t\t          Status: Incorrect password. Try again.");
		return 0;
		
	}
	if (!userExists && !found && !password)
	{ 
		printf("\n\n\t\t\t\t\t\t\t\t          Status: Account does not exist. Try again.");
		return 0;
	}
	else return 0;
}
/*
	apptReq: function that manages the registration of vaccination appointments
	@param userRegistrant: array of structs User, that contains information of registered users
	@param userAppointment: array of structs Appointment, that contains information of all the registered appointments
	@param i: pointer to integer, number of registered users
	@param j: pointer to integer, number of registered appointments
	@return void
	Precondition: userRegistrant and userAppointment arrays have been initialized, i and j are valid pointers.
*/
void 
apptReq(struct User userRegistrant[],
		struct Appointment userAppointment[],
		int *i, 
		int* j)
{
    int check = 0; // initialize variable check to zero
	int loginStatus = -1;  //initialize variable loginStatus to -1
	int counts = 0; //initialize variable counts to zero

	while(loginStatus != 1 && counts != 3) //loop to check if user is logged in or not
	{
		system("cls");
		displayHeader();
		printf ("\n\n\t\t\t\t\t\t\t\t\t      L  O  G  -  I  N ");
		printf("\n\n");
		loginStatus = loginVaccAppointment(userRegistrant, i); //call function to check if user is registered and input user id and password
		fflush(stdin);
		counts++;
		getch();
	}
	//the user proceeds with other details needed for Vaccination Appointment
	switch(loginStatus) // check login status
	{
		case 1: //successful login
			do{
				system("cls");
				check = 0;
				displayHeader();
				printf("\n\n\t\t\t\t\t\t\t\t   A P P O I N T M E N T  S I G N - U P  ");
				printf ("\n\n\n\t\t\t\t\t\t\t\t\t   Appointment ID :   ");
				scanf("%d", &userAppointment[*j].appID);
				fflush(stdin);
				if (userAppointment[*j].appID > 9999 || userAppointment[*j].appID < 1000) //check if appointment ID is a 4-digit number
				{
					check=1;
					printf("\n\t\t\t\t\tUser ID must be 4 digit numbers");
				}
				else if (apptIDCheckingDuplication(userAppointment, userAppointment[*j].appID, j)==1) //check if appointment ID is already taken
				{
					check=1;
					printf("\n\t\t\t\t\tThis userID already exists. Please type another.");
					getch();
				}
			}while(check);

			do
			{
				check=0;
				printf ("\t\t\t\t\t\t\t      Name (Lastname, First Name) :   ");
				scanf("%[^\n]%*c" ,userAppointment[*j].customerName);
				fflush(stdin);
				//check if customer name is not empty and has less than 20 characters
				if (strlen(userAppointment[*j].customerName) > 20 || strlen(userAppointment[*j].customerName) == 0)
				{
					check=1;
					printf("\t\t\t\t\t\t\t      (Error)\n");
				}
			} while (check);

			do
			{
				check=0;
				printf ("\t\t\t\t\t\t\t\t\t\t Location :   ");
				scanf("%[^\n]%*c" ,userAppointment[*j].string[0]);
				fflush(stdin);
				//check if location is not empty and has less than 10 characters
				if (strlen(userAppointment[*j].string[0]) > 10 || strlen(userAppointment[*j].string[0]) == 0)
				{
					check=1;
					printf("\t\t\t\t\t\t\t      (Error)\n");
				}
			} while (check);

			do  // Start of do-while loop for Vaccine Type input
			{
				check=0;
				printf ("\t\t\t\t\t\t\t\t\t     Vaccine Type :   ");
				scanf("%[^\n]%*c" ,userAppointment[*j].string[1]);
				fflush(stdin);
				// Check if Vaccine Type is empty or longer than 10 characters
				if (strlen(userAppointment[*j].string[1]) > 10 || strlen(userAppointment[*j].string[1]) == 0)
				{
					check=1;
					printf("\t\t\t\t\t\t\t      (Error)\n");
				}
			} while (check);

			do // Start of do-while loop for Date input
			{
				check=0;
				printf ("\t\t\t\t\t\t\t\t\tDate (YYYY-MM-DD) :   ");
				scanf("%[^\n]%*c" ,userAppointment[*j].string[2]);
				fflush(stdin);
				 // Check if Date is not exactly 10 characters long
				if (strlen(userAppointment[*j].string[2]) != 10)
				{
					check=1;
					printf("\t\t\t\t\t\t\t      (Error)\n");
				}
			} while (check);

			do // Start of do-while loop for Time input
			{
				check=0;
				printf ("\t\t\t\t\t\t\t\t    Time (24 Hour Format) :   ");
				scanf("%[^\n]%*c" ,userAppointment[*j].time);
				fflush(stdin);
				if (strlen(userAppointment[*j].time) != 5)
				{
					check=1;
					 printf("\t\t\t\t\t\t\t      (Error)\n");
				}
			} while (check);

			do // Start of do-while loop for Vaccine Dose input
			{
				check=0;
				printf ("\t\t\t\t\t\t\t\t\t     Vaccine Dose :   ");
				scanf("%[^\n]%*c" ,userAppointment[*j].string[3]);
				fflush(stdin);
				// Check if Vaccine Dose is empty or longer than 10 characters
				if (strlen(userAppointment[*j].string[3]) > 10 || strlen(userAppointment[*j].string[3]) == 0)
				{
					check=1;
					 printf("\t\t\t\t\t\t\t      (Error)\n");
				}
			} while (check);
			// Output confirmation message after successful appointment input
			printf ("\n\n\n\t\t\t\t\t\t\t\t       Appointment Saved Successfully !");
			printf ("\n\t\t\t\t\t\t\t\t Thank you for booking an appointment! See you!\n\n\n");
			getch();
			break;
		// Switch case for handling login trial errors
		case 0:
			system("cls");
			displayHeader();
			printf("\n\n\n");
			displayPlainLines();
			printf("\n\n\n\t\t\t\t\t\t\tStatus: You have been locked \n\t\t\t\t\t\t\tout due to (3) error trials.\n\n\n");
			displayPlainLines();
			getch();
			break;
	}
}
/*
	displayApptAccs - This function displays the information of user appointments.
	@param userAppointment[] An array of structures representing the user appointments.
	@param j An integer pointer representing the number of appointments in the userAppointment[] array.
	@return void
	Precondition: userAppointment[] must contain valid appointment information, and j must be greater than or equal to zero.
*/
void
displayApptAccs(struct Appointment userAppointment[],
		  		int* j)
{
	int n;
	for(n=0; n < *j; n++) // Loop through the array of appointment structs.
	{
		printf("\n\nUser %d\n------\nAppointment ID: %d", n, userAppointment[n].appID);
		printf("\nName: %s", userAppointment[n].customerName);
		printf("\nTime: %s", userAppointment[n].time);
		printf("\nVaccine Location: %s", userAppointment[n].string[0]);
		printf("\nVaccine Type: %s", userAppointment[n].string[1]);
		printf("\nDate (YYYY-MM-DD) : %s", userAppointment[n].string[2]);
		printf("\nVaccine Dose: %s", userAppointment[n].string[3]);
	}
}
/*
	displayRegAccs - displays information of registered users
	@param userRegistrant An array of User structs containing user information
	@param i A pointer to the number of users in userRegistrant
	@return None
	Precondition: userRegistrant is a valid array of User structs and i points to the number of users in the array
*/
void
displayRegAccs(struct User userRegistrant[],
		  	   int* i)
{
	int n;
	for(n=0; n < (*i); n++)
	{
		// Print out user information	
		printf("\n\nUser %d\n------\nUser ID :  %d", n, userRegistrant[n].userID);
		printf("\nPassword: %s", userRegistrant[n].password);
		printf("\nName:	%s", userRegistrant[n].fullName);
		printf("\nAddress:	%s", userRegistrant[n].address);
		printf("\nContact:	%011lld", userRegistrant[n].contact);
		printf("\nSex :	%s", userRegistrant[n].sex);
		// Print out information about the first dose of vaccine
		printf("\nDate of First Dose:  %s", userRegistrant[n].string[0]);
		printf("\nFirst Dose Vaccine Type:	%s", userRegistrant[n].string[1]);
		printf("\nLocation of First Dose:	%s", userRegistrant[n].string[2]);
		// Print out information about the second dose of vaccine
		printf("\nDate of Second Dose:	%s", userRegistrant[n].string[3]);
		printf("\nSecond Dose Vaccine Dose:	%s", userRegistrant[n].string[4]);
		printf("\nLocation of Second Dose:	%s", userRegistrant[n].string[5]);
		// Print out information about the third dose of vaccine
		printf("\nDate of Third Dose:	%s", userRegistrant[n].string[6]);
		printf("\nThird Dose Vaccine Dose:	%s", userRegistrant[n].string[7]);
		printf("\nLocation of Third Dose:	%s", userRegistrant[n].string[8]);
	}
}
/*
	ManageAppointment - manages user appointments by presenting options for appointment cancellation, rescheduling, and changing vaccination center.
	@param userRegistrant[] an array of struct User containing user information
	@param userAppointment[] an array of struct Appointment containing appointment information
	@param i a pointer to an integer representing the number of registered users
	@param j a pointer to an integer representing the number of scheduled appointments
	@return none
	Precondition: userRegistrant and userAppointment arrays are initialized and i and j pointers are pointing to the number of registered users and scheduled appointments respectively.
*/
void
manageAppointment(struct User userRegistrant[],
				  struct Appointment userAppointment[],
				  int* i,
				  int* j)
{
	int nChoice, repeat = 1;

	do
	{ 
		system("cls");
        displayHeader();
		// display appointment management menu
		printf("\n\n\t\t\t\t\t\t\t\t  A P P O I N T M E N T  M A N A G E M E N T  ");
		printf ("\n\n\n\t\t\t\t\t\t\t\t\t  1) ");
		printf("Cancel Appointment");
		printf ("\n\t\t\t\t\t\t\t\t\t  2) ");
		printf("Reschedule Data and Time");
		printf ("\n\t\t\t\t\t\t\t\t\t  3) ");
		printf("Change Vaccination Center\n\t\t\t\t\t\t\t\t\t     Location and Vaccine Brand");
		printf ("\n\t\t\t\t\t\t\t\t\t  4) ");
		printf("Exit Menu");
		fflush(stdin);
        printf ("\n\n\t\t\t\t\t\t\t\t\t  Choose command: ");
		scanf("%d", &nChoice); // display appointment management menu
		fflush(stdin);

		switch(nChoice) // display appointment management menu
		{
			case 1:  // cancel appointment function
				cancelAppt(userRegistrant, userAppointment, i, j); 
				break;
			case 2 :  // reschedule date and time function
				reschedDT(userRegistrant, userAppointment, i, j);
				break;
			case 3 : // change vaccination center location and vaccine brand function
				changeVLVT(userRegistrant, userAppointment, i, j);
				break;
			case 4: // exit menu
				repeat = 0;
				break;
			default :  // invalid input, repeat menu
				repeat = 1;
				break;
		} 
	}while (repeat == 1);
	return;
}
/*
	cancelAppt - Allows user to cancel their appointment
	@param userRegistrant[] array of User structures containing user data
	@param userAppointment[] array of Appointment structures containing appointment data
	@param i pointer to integer i used as reference to appointment counter
	@param j pointer to integer j used as reference to user counter
	@return void
	Precondition: User and Appointment arrays are initialized with valid data
*/
void
cancelAppt(struct User userRegistrant[],
		   struct Appointment userAppointment[],
		   int* i,
		   int* j)
{
	int userID, k, n, l, reqID, nChoice, len;
	int check = -1;
	int attempts = 0; // counter for attempts to enter password
	int index = 0;
	char password[10 + 1];
	char ch;

	do{
		do
		{
			userID=0;
			system("cls");
			displayHeader();
			printf("\n\n\t\t\t\t\t\t\t\t\t         L O G  - I N ");
			printf("\n\n\n\t\t\t\t\t\t\t\t\t      User ID :  ");
			scanf("%d", &userID);
			fflush(stdin);
		} while (userID > 9999 || userID < 1000);

		
		printf("\t\t\t\t\t\t\t\t\t     Password :  ");


		// mask password input with asterisks
		ch = getch();

		while (ch != '\r')
		{
			if (ch == '\b') // if user presses backspace
			{
				if (index > 0)  // if the input is not empty
				{
					index--;
					putchar('\b'); // move cursor back
					putchar(' ');  // overwrite the last character with a space
					putchar('\b'); // move cursor back again
				}
			}
			else if (index < 10)
			{
				password[index++] = ch;
				putchar('*');  // print an asterisk instead of the actual character
			}

			ch = getch();
		}
		password[index] = '\0';

		// validate input of password
		len = strlen(password);
		if (len == 0 || len > 10)
		{
			
			printf("\n\t\t\t\t\t\t\t\t(Error)\n");
		}
		// find the user with the matching userID and password
		for (k= 0; k <= (*j); k++)
		{
			if (userRegistrant[k].userID == userID)
			{
				if (strcmp(userRegistrant[k].password, password) == 0) // if the password matches
				{
					reqID=0;
					check = 0;
					printf("\n\n\t\t\t\t\t\t\t\t          Status: Login successful.");  // Notify the user that login is successful
					getch();

					system("cls");
					displayHeader();
					printf("\n\n\t\t\t\t\t\t\t\t       C A N C E L  A P P O I N T M E N T \n\n");
					printf("\n\t\t\t\t\t\t\t\t           You are user ID:   %d", userID);
					printf("\n\t\t\t\t\t\t\t\t Enter your Appointment ID:   ");
					scanf("%d", &reqID);
					fflush(stdin);

					for(n=0; n <= (*j); n++)
					{
						if(userAppointment[n].appID == reqID) // Check if the entered appointment ID exists
						{
							system("cls");
							displayHeader();
							printf("\n\n\t\t\t\t\t\t\t\t\t         D E L E T E \n\n");
							printf("\n\n\n\t\t\t\t\t\t\t\t\t    Appointment ID:   %d", userAppointment[n].appID);
							printf("\n\n\t\t\t\t\t\t\t\t\t  Are you sure you want to\n\t\t\t\t\t\t\t\t\t  cancel your Appointment?");
							printf ("\n\n \t\t\t\t\t\t\t\t\t  1) ");
							printf("Yes");
							printf ("\t  2) ");
							printf("No");
							printf ("\n\n \t\t\t\t\t\t\t\t\t  Choose command: ");
							scanf("%d", &nChoice);
							fflush(stdin);

							switch(nChoice)
							{
								case 1:
									 // Delete appointment details at index n
									userAppointment[n].appID = '\0';
									strcpy(userAppointment[n].customerName, "");
									strcpy(userAppointment[n].time,"");
									strcpy(userAppointment[n].string[0],"");
									strcpy(userAppointment[n].string[1],"");
									strcpy(userAppointment[n].string[2],"");
									strcpy(userAppointment[n].string[3],"");

									 // Shift remaining appointments back by one index
									for (l = n; l < (*j)-1; l++)
									{
										userAppointment[l].appID = userAppointment[l+1].appID;
										strcpy(userAppointment[l].customerName, userAppointment[l+1].customerName);
										strcpy(userAppointment[l].time, userAppointment[l+1].time);
										strcpy(userAppointment[l].string[0], userAppointment[l+1].string[0]);
										strcpy(userAppointment[l].string[1], userAppointment[l+1].string[1]);
										strcpy(userAppointment[l].string[2], userAppointment[l+1].string[2]);
										strcpy(userAppointment[l].string[3], userAppointment[l+1].string[3]);
									}
									(*j)--;
									displayPlainLines();
									// Notify the user that the appointment has been cancelled
									printf("\n\t\t\t\t\t\t\t        Status: Appointment ID %d has been cancelled.", reqID); 
									getch();
									return;
		
									displayApptAccs(userAppointment, j);
									getch();
									break;

								case 2: // Display message and return to appointment menu
									displayPlainLines();
									printf("\n\t\t\t\t\t\t\t    Redirecting Back to Appointment Menu");
									getch();
									break;
							}
						}
						if(userAppointment[n].appID != reqID)
						{
							displayPlainLines();
							printf("\n\t\t\t\t\t\t  Status: Appointment ID does not exist.");
							getch();
							return;
						}
					}
				}
			}
			// If the appointment ID does not match, display an error message and return to appointment menu
			if(userRegistrant[k].userID != userID || strcmp(userRegistrant[k].password, password) != 0)
			{
				displayPlainLines();
				printf("\n\t\t\t\t\t\t Status: Incorrrect Credentials. Try again.");
				getch();
				attempts++; // increment attempts counter
			}
		}
	}while (check && attempts<3);
	if (attempts == 3)
	{ // exit loop when user has reached 3 attempts
		system("cls");
		displayPlainLines();
		printf("\n\n\t\t\t\t\t\t\t  Status: Try again later.\n");
		displayPlainLines();
		getch();
		return;
	}
	return;
}
/*
	reschedDT Reschedule the date and time of an appointment for a given user
	@param userRegistrant[] Array of struct User containing registered users
	@param userAppointment[] Array of struct Appointment containing scheduled appointments
	@param i integer pointer pointing to the last index of the userRegistrant[] array
	@param j integer pointer pointing to the last index of the userAppointment[] array
	@return void
	Precondition: userRegistrant[] and userAppointment[] are not empty
*/
void
reschedDT(struct User userRegistrant[],
		  struct Appointment userAppointment[],
		  int *i,
		  int *j)
{
	int userID, k, n, reqID, index, len;
	int check = -1, check2 = -1;
	int attempts = 0; // add attempts counter
	char password[10 + 1];	
	char ch; 
	char newDate[10], newTime[10];
	

	do
	{
		do
		{
			userID=0;
			system("cls");
			displayHeader();
			printf("\n\n\t\t\t\t\t\t\t\t\t         L O G  - I N ");
			printf("\n\n\n\t\t\t\t\t\t\t\t\t      User ID :  ");
			scanf("%d", &userID);
			fflush(stdin);
		} while (userID > 9999 || userID < 1000);

		printf("\t\t\t\t\t\t\t\t\t     Password :  ");

		// mask password input with asterisks
		index = 0;
		ch = getch();

		while (ch != '\r')
		{
			if (ch == '\b') //backspace
			{
				if (index > 0)
				{
					index--;
					putchar('\b');
					putchar(' ');
					putchar('\b');
				}
			}
			else if (index < 10)
			{
				password[index++] = ch;
				putchar('*');
			}

			ch = getch();
		}
		password[index] = '\0';
		fflush(stdin);
		// validate input of password
		len = strlen(password);
		if (len == 0 || len > 10)
		{
			
			printf("\n\t\t\t\t\t\t\t\t(Error)\n");
		}
		// Loop through each user registrant and find the matching user ID and password
		for (k= 0; k <= (*i); k++)
		{
			if (userRegistrant[k].userID == userID)
			{
				// If user ID and password match, proceed to appointment / rescheduling menu
				if (strcmp(userRegistrant[k].password, password) == 0)
				{
					reqID=0;
					check = 0;
					printf("\n\n\n\t\t\t\t\t\t\t\t\t  Status: Login successful.");
					getch();
					system("cls");
					displayHeader(); // display header and request appointment ID from user
					printf("\n\n\t\t\t\t\t\t\t\t     R E S C H E D U L E  D A T E  &  T I M E \n\n");
					printf("\n\t\t\t\t\t\t\t\t           You are user ID:   %d", userID);
					printf("\n\t\t\t\t\t\t\t\t Enter your Appointment ID:   ");
					scanf("%d", &reqID);
					fflush(stdin);
					getch();
					for(n=0; n <= (*j); k++)  // iterate through the appointments to find the one with matching appointment ID
					{
						if(userAppointment[n].appID == reqID)
						{
							system("cls");
							displayHeader(); // display previous appointment details and request new date and time
							printf("\n\n\t\t\t\t\t\t\t\t    R E S C H E D U L E\n\n");
							printf("\n\t\t\t\t\t\t\t             Appointment ID:	%d", userAppointment[n].appID);
							printf("\n\t\t\t\t\t\t\t      Previous Entered date:	%s", userAppointment[n].string[2]);
							printf("\n\t\t\t\t\t\t\t      Previous Entered Time:	%s", userAppointment[n].time);
							// request new date from user and validate the input
							do 
							{
								fflush(stdin);
								check2 = 0;
								printf ("\n\n\t\t\t\t\t\t        ");  
								printf("Enter New Date (YYYY-MM-DD):	");
								scanf("%[^\n]%*c", newDate);
								fflush(stdin);
								if (strlen(newDate) != 10)
								{
									check2=1;
									printf("\n\t\t\t\t\t\t      (Error)\n");
								}
							}while (check2);
							swapStrings(newDate, userAppointment[k].string[2]);
							// request new time from user and validate the input
							do
							{
								fflush(stdin);
								printf ("\t\t\t\t\t\t    ");
								printf("Enter New Time (24-Hour Format):	");
								scanf("%[^\n]%*c", newTime);
								fflush(stdin);
								if (strlen(newTime) != 5)
								{
									check2=1;
									printf("\n\t\t\t\t\t\t      (Error)\n");
								}
							} while (check2);
							swapStrings(newTime, userAppointment[n].time);

							system("cls");
							displayHeader(); // display updated appointment details and exit function
							printf("\n\n\t\t\t\t\t\t\t\t          U P D A T E D  S C H E D U L E");
							printf("\n\n\n\t\t\t\t\t\t\t\tYour Updated Vaccine Appointment Information:\n\n");
							printf("\n\t\t\t\t\t\t\t\t      [ ] Appointment ID:   ");printf("%d", userAppointment[k].appID);
							printf("\n\t\t\t\t\t\t\t\t      [ ] Name:             "); printf("%s", userAppointment[n].customerName);
							printf("\n\t\t\t\t\t\t\t\t      [ ] Vaccine Location: "); printf("%s", userAppointment[n].string[0]);
							printf("\n\t\t\t\t\t\t\t\t      [ ] Vaccine Type:     ");  printf("%s", userAppointment[n].string[1]);
 							printf("\n\t\t\t\t\t\t\t\t      [ ] Vaccination Date: "); printf("%s", userAppointment[n].string[2]);
							printf("\n\t\t\t\t\t\t\t\t      [ ] Vaccination Time: "); printf("%s", userAppointment[n].time);
							printf("\n\t\t\t\t\t\t\t\t      [ ] Vaccine Dose:     "); printf("%s", userAppointment[n].string[3]);

							printf ("\n\n\n\n\t\t\t\t\t\t\t\t      Appointment Updated Successfully !");
							printf ("\n\t\t\t\t\t\t\t\tThank you for booking an appointment! See you!\n\n\n");
							getch();
							return;
						}
						if(userAppointment[n].appID != reqID)
						{
							printf("\n\n\n\t\t\t\t\t\t  Status: Appointment ID does not exist.");
							getch();
							return;
						}
					}
				}
			}
		}
		// If user ID or password does not match, display message and increment attempts counter
		if(userRegistrant[k].userID != userID || strcmp(userRegistrant[k].password, password) != 0)
		{
			printf("\n\n\n");
			printf("\n\n\n\t\t\t\t\t\t\t Status: Incorrrect Credentials. Try again.");
			getch();
			attempts++; // increment attempts counter
		}
	}while (check && attempts<3); // Exit loop when user has reached 3 attempts
	// exit loop when user has reached 3 attempts
	if (attempts == 3)
	{ 
		system("cls");
		printf("\n\n\n\t\t\t\t\t\t\t  Status: Try again later.\n\n\n");
		displayPlainLines();
		getch();
		return;
	}
}
/*
	swapStrings - Swaps two strings.
	@param str1: Pointer to the first string to be swapped.
	@param str2: Pointer to the second string to be swapped.
	@return: This function does not return a value.
	Precondition: The input strings must not be NULL and must have a combined length of less than 100 characters.
*/
void
swapStrings(char *str1, 
			char *str2)
{
    char temp[100];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}
/*
	changeVLVT - allows users to change their appointment location and vaccine brand after logging in
	@param userRegistrant[] an array of User struct that contains registered users' information
	@param userAppointment[] an array of Appointment struct that contains users' appointment information
	@param i a pointer to an integer variable that stores the number of registered users
	@param j a pointer to an integer variable that stores the number of appointments made
	@return void
	Precondition: userRegistrant[] and userAppointment[] should be initialized with valid data and i, j should be greater than or equal to 0.
*/
void
changeVLVT(struct User userRegistrant[],
		  struct Appointment userAppointment[],
		  int *i,
		  int *j)
{
	int check = -1, check2 = -1;
	int userID, k, n, reqID, index, len;
	char password[10 + 1];
	char newLoc[10], newVac[10];
	char ch;
	int attempts = 0; // add attempts counter

	do{
		do
		{
			userID=0;
			system("cls");
			displayHeader();
			printf("\n\t\t\t\t\t\t\t\t\t         L O G  - I N ");
			printf("\n\n\n\t\t\t\t\t\t\t\t\t      User ID :  ");
			scanf("%d", &userID);
		} while (userID > 9999 || userID < 1000); 
		fflush(stdin);
		printf("\t\t\t\t\t\t\t\t\t     Password :  ");

		// mask password input with asterisks
		fflush(stdin);
		index = 0;
		ch = ' ';

		while (ch != '\r')
		{
			if (ch == '\b') //backspace
			{
				if (index > 0)
				{
					index--;
					putchar('\b');
					putchar(' ');
					putchar('\b');
				}
			}
			else if (index < 10)
			{
				password[index++] = ch;
				putchar('*');
			}

			ch = getch();
		}
		password[index] = '\0';

		// validate input of password
		len = strlen(password);
		if (len == 0 || len > 10)
		{
			
			printf("\n\t\t\t\t\t\t\t\t(Error)\n");
		}
		// find the user with the matching userID and password
		for (k= 0; k <= (*i); k++)
		{
			if (userRegistrant[k].userID == userID)
			{
				if (strcmp(userRegistrant[k].password, password) == 0)
				{
					reqID=0;
					check = 0;
					printf("\n\n\t\t\t\t\t\t\t\t          Status: Login successful.");
					getch();
					system("cls");
					displayHeader();			
					// displays change location and dose message		
					printf("\n\n\t\t\t\t\t\t\t\t      C H A N G E  L O C A T I O N  &  D O S E\n\n");					
					printf("\n\t\t\t\t\t\t\t\t          You are user ID:   %d", userID);
					printf("\n\t\t\t\t\t\t\t\tEnter your Appointment ID:   ");
					scanf("%d", &reqID);
					fflush(stdin);
					getch();
					for(n=0; n <= (*j); k++)
					{
						if(userAppointment[n].appID == reqID)
						{
							system("cls");
							displayHeader();
							printf("n\n\t\t\t\t\t\t\t\t\t\t   R E S C H E D U L E\n\n");
							printf("\n\t\t\t\t\t\t\t                Appointment ID:      %d", userAppointment[n].appID);
							printf("\n\t\t\t\t\t\t\t     Previous Entered Location:      %s", userAppointment[n].string[0]);
							printf("\n\t\t\t\t\t\t\tPrevious Entered Vaccine Brand:      %s", userAppointment[n].string[1]);
							
							do
							{
								fflush(stdin);
								check2 = 0;
								printf ("\n\n\t\t\t\t\t\t\t  	     Enter New Locaton:      ");
								scanf("%[^\n]%*c", newLoc);// gets new location from user input
								fflush(stdin);
								if (strlen(newLoc)==0)
								{
									check2=1;
									 printf("\t\t\t\t\t\t\t\t    (Error)\n");
								}
							}while (check2);
							swapStrings(newLoc, userAppointment[n].string[0]); // swaps previous location with new location

							do{
								fflush(stdin);
								printf ("\t\t\t\t\t\t\t       Enter New Vaccine Brand:      ");
								scanf("%[^\n]%*c", newVac); // gets new vaccine brand from user input
								fflush(stdin);
								if (strlen(newVac)==0)
								{
									check2=1;
									printf("\t\t\t\t\t\t\t      (Error)\n");
								}
							} while (check2);
							swapStrings(newVac, userAppointment[n].string[1]);

							system("cls");
							displayHeader();
							printf("\n\n\t\t\t\t\t\t\t\t          U P D A T E D  S C H E D U L E");
							printf("\n\n\n\t\t\t\t\t\t\t\tYour Updated Vaccine Appointment Information:");
							printf("\n\t\t\t\t\t\t\t\t      [ ] Appointment ID:   ");  printf("%d", userAppointment[k].appID);
							printf("\n\t\t\t\t\t\t\t\t      [ ] Name:             ");  printf("%s", userAppointment[n].customerName);
							printf("\n\t\t\t\t\t\t\t\t      [ ] Location:         ");  printf("%s", userAppointment[n].string[0]);
							printf("\n\t\t\t\t\t\t\t\t      [ ] Vaccine Type:     ");  printf("%s", userAppointment[n].string[1]);
							printf("\n\t\t\t\t\t\t\t\t      [ ] Vaccination Date: ");  printf("%s", userAppointment[n].string[2]);
							printf("\n\t\t\t\t\t\t\t\t      [ ] Vaccination Time: ");  printf("%s", userAppointment[n].time);
							printf("\n\t\t\t\t\t\t\t\t      [ ] Vaccine Dose:     ");  printf("%s", userAppointment[n].string[3]);
					
							printf ("\n\n\n\n\n\t\t\t\t\t\t\t\t       Appointment Updated Successfully !");
							printf ("\n\t\t\t\t\t\t\t\tThank you for booking an appointment! See you!\n\n\n");
							getch();
							return;
						}
						if(userAppointment[n].appID != reqID)
						{
							printf("\n\t\t\t\t\t\t\t\t  Status: Appointment ID does not exist.");
							getch();
							return;
						}
					}
				}
			}
		}
		if(userRegistrant[k].userID != userID || strcmp(userRegistrant[k].password, password) != 0)
		{
			printf("\n\n\n\t\t\t\t\t\t\t\t Status: Incorrrect Credentials. Try again.");
			getch();
			attempts++; // increment attempts counter
		}
	}while (check && attempts<3);
	if (attempts == 3)
	{ // exit loop when user has reached 3 attempts
		system("cls");
		printf("\n\n\n\t\t\t\t\t\t\t\t Status: Try again later.\n\n\n");
		getch();
		return;
	}
	return;
}
/*
	apptIDCheckingDuplication - checks if the given appointment ID already exists in the user's appointments array.
	@param userAppointment: an array of struct Appointment containing the user's existing appointments.
	@param newAppID: the appointment ID to check for duplication.
	@param j: a pointer to the number of existing appointments in the userAppointment array.
	@return: 0 if the appointment ID is not a duplicate, 1 if it already exists in the array.
	Precondition: userAppointment is not null, j is not null and points to a valid integer value.
*/
int 
apptIDCheckingDuplication(struct Appointment userAppointment[], 
							  int newAppID, 
							  int* j) {
    int i;
    for (i = 0; i < *j; i++) 
	{
        if (userAppointment[i].appID == newAppID) {
            printf("\n\n\t\t\t\t\t The appointment ID already exists. Please try again.");
            return 1;
        }
    }

    return 0;
}



/*  apptIDCheckingDuplication :  for checking if the entered user ID exist
	@struct User userRegistrant : group of different data types for variable userRegistrant
	@int key : enetered appID of the user
	@int n : Record Number for Vaccine Registration
*/
int
userIDCheckingDuplication(struct User userRegistrant[], 
						  int newUserID, 
						  int* i)
{
	int j;

    for (j = 0; j < *i; j++) {
        if (userRegistrant[j].userID == newUserID) {
            printf("\n\n\t\t\t\t\t The user ID already exists. Please try again.");
            return 1;
        }
    }
    return 0;
}

/*
	exitPrompt - frees memory and displays exit message to user
	@param userRegistrant array of User structs representing the registrants' information
	@param userAppointment array of Appointment structs representing the scheduled appointments
	@param FAQ array of Chatbot structs representing question and answer
	@return void
	Precondition: userRegistrant, userAppointment, and FAQ have been initialized and allocated memory
*/
void
exitPrompt(struct User userRegistrant[], 
		   struct Appointment userAppointment[], 
		   struct Chatbot FAQ[])
{
	//freeing the memory allocated to the arrays userRegistrant, userAppointment, and FAQ
	free(userRegistrant);
	free(userAppointment);
	free(FAQ);
	system("cls");
	printf("\n\n\n\n \t\t\t\t\tThank you for using Vaccination Registration with Chatbot App!\n\n\n\n");// 
	getch();
}
/*
	chatbotFAQ - A function that provides frequently asked questions and answers related to COVID-19.
	@param strInput A character array that stores user input.
	@param strResponse A character array that stores user response to the answer.
	@return void
	Precondition: The function is called and the user inputs a question related to COVID-19.
 */
void
chatbotFAQ()
{
	char strResponse[5];
	int askAgain=1;

    while(askAgain)
	{
		char strInput[50] = {0};
		system("cls");
		displayHeader();
		printf("\n\t\t\t\t\t\t\t\t\t\tH E L P  C E N T E R  ");						
		printf ("\n\n\t\t\t\t\t\t\t\t(^.^)/ ");  printf("\tGreetings! You've reached the ChatPal\n\t\t\t\t\t\t\t\tFAQs, where you can inquire about COVID-19.");
		printf ("\n\t\t\t\t\t\t\t\tHow can I help you with today?\n");
		fflush(stdin);
		printf ("\n\t\t\t\t\t\t\t\t"); fgets(strInput, sizeof(strInput), stdin);
		strInput[strlen(strInput)] = '0';

		if ((strstr(strInput, "vacci") != NULL && strstr(strInput, "mandatory") != NULL) || (strstr(strInput, "Vacci") != NULL && strstr(strInput, "Mandatory") != NULL))
		{
			 printf("\n\t\t\t\t\t\t\t\t(^.~)");  printf(" No, but highly recommended\n\t\t\t\t\t\t\t\tby the government.");
			getch();
			printf("\n\n\t\t\t\t\t\t\t\tDo you have any more questions?");
			printf("\n\t\t\t\t\t\t\t\tType your response:"); printf("(yes or no)\n\t\t\t\t\t\t\t\t\t");
			 scanf(" %s", strResponse);
			if(strcmp(strResponse, "yes")== 0 || strcmp(strResponse, "Yes") ==0)
				askAgain = 1;

			else if(strcmp(strResponse, "no")==0 || strcmp(strResponse, "No")==0)
				askAgain = 0;

			else askAgain = 0;
        }
		else if ((strstr(strInput, "vacc") != NULL && strstr(strInput, "available") != NULL) || (strstr(strInput, "Vacc") != NULL && strstr(strInput, "Available") != NULL))
		{
			 printf("\n\t\t\t\t\t\t\t\t(^.~)");  printf(" Approved COVID-19 vaccines, including\n\t\t\t\t\t\t\t\tPfizer-BionTech, AstraZeneca, and Sinovac.");
			getch();
			printf("\n\n\t\t\t\t\t\t\t\tDo you have any more questions?");
			printf("\n\t\t\t\t\t\t\t\ttype your response:");  printf("(yes or no)\n\t\t\t\t\t\t\t\t\t");
			scanf(" %s", strResponse);
			strResponse[strlen(strResponse)] = '0';
			if(strcmp(strResponse, "yes")== 0 || strcmp(strResponse, "Yes") ==0)
				askAgain = 1;

			else if(strcmp(strResponse, "no")==0 || strcmp(strResponse, "No")==0)
				askAgain = 0;

			else askAgain = 0;
        }
		else if ((strstr(strInput, "side effects") != NULL && strstr(strInput, "vaccin") != NULL) || (strstr(strInput, "side effect") != NULL && strstr(strInput, "vaccin") != NULL))
		{
			 printf("\n\t\t\t\t\t\t\t\t(^.~)");  printf(" Possible side effects: pain, fever, \n\t\t\t\t\t\t\t\tfatigue, headache, and muscle aches.");
			getch();
			printf("\n\n\t\t\t\t\t\t\t\tDo you have any more questions?");
			printf("\n\t\t\t\t\t\t\t\tType your response:");  printf("(yes or no)\n\t\t\t\t\t\t\t\t\t");
			 scanf(" %s", strResponse);
			if(strcmp(strResponse, "yes")== 0 || strcmp(strResponse, "Yes") ==0)
				askAgain = 1;

			else if(strcmp(strResponse, "no")==0 || strcmp(strResponse, "No")==0)
				askAgain = 0;
			
			else askAgain = 0;
        }
		else if ((strstr(strInput, "comorbidities") != NULL && strstr(strInput, "vaccin") != NULL) || (strstr(strInput, "comorbities") != NULL && strstr(strInput, "vaccin") != NULL))
		{
			printf("\n\t\t\t\t\t\t\t\t(^.~) ");  printf(" Yes, people with comorbidities are among the \n\t\t\t\t\t\t\t\tpriority groups for vaccination.");
			getch();
			printf("\n\n\t\t\t\t\t\t\t\tDo you have any more questions?");
			printf("\n\t\t\t\t\t\t\t\tType your response:");  printf("(yes or no)\n\t\t\t\t\t\t\t\t\t");
			 scanf(" %s", strResponse);
			if(strcmp(strResponse, "yes")== 0 || strcmp(strResponse, "Yes") ==0)
				askAgain = 1;

			else if(strcmp(strResponse, "no")==0 || strcmp(strResponse, "No")==0)
				askAgain = 0;
			else askAgain = 0;
        }
		else if ((strstr(strInput, "age") != NULL && strstr(strInput, "vaccin") != NULL) || (strstr(strInput, "pregnant") != NULL && strstr(strInput, "vaccin") != NULL))
		{
			printf("\n\t\t\t\t\t\t\t\t(^.~) ");  printf(" Minimum age for vaccination in the\n\t\t\t\t\t\t\t\tPhilippines is 18 y.o. If preganant \n\t\t\t\t\t\t\t\twoman, consult professional\n\t\t\t\t\t\t\t\theathcare first before doing so.");
			getch();
			printf("\n\n\t\t\t\t\t\t\t\tDo you have any more questions?");
			printf("\n\t\t\t\t\t\t\t\tType your response:");  printf("(yes or no)\n\t\t\t\t\t\t\t\t\t");
			scanf(" %s", strResponse);
			if(strcmp(strResponse, "yes")== 0 || strcmp(strResponse, "Yes") ==0)
				askAgain = 1;

			else if(strcmp(strResponse, "no")==0 || strcmp(strResponse, "No")==0)
				askAgain = 0;
			else askAgain = 0;
        }
		else if ((strstr(strInput, "safe") != NULL && strstr(strInput, "vaccin") != NULL) || (strstr(strInput, "tested") != NULL && strstr(strInput, "human") != NULL) || (strstr(strInput, "effective") != NULL))
		{
			printf("\n\t\t\t\t\t\t\t\t(^.~) ");  printf(" Vaccines is rigorously tested and \n\t\t\t\t\t\t\t\tmonitored before have been approved \n\t\t\t\t\t\t\t\tfor use in the general population. \n\t\t\t\t\t\t\t\tVaccines are safe and effective.");
			getch();
			printf("\n\n\t\t\t\t\t\t\t\tDo you have any more questions?");
			printf("\n\t\t\t\t\t\t\t\tType your response:");  printf("(yes or no)\n\t\t\t\t\t\t\t\t\t");
			scanf(" %s", strResponse);
			if(strcmp(strResponse, "yes")== 0 || strcmp(strResponse, "Yes") ==0)
				askAgain = 1;

			else if(strcmp(strResponse, "no")==0 || strcmp(strResponse, "No")==0)
				askAgain = 0;
			else askAgain = 0;
        }
		else
		{												
			printf("\n\t\t\t\t\t\t\t\t(T.T) ");  printf("Sorry, I do not know the answer. \n\t\t\t\t\t\t\t\tPlease type another question...");
			getch();
			printf("\n\n\t\t\t\t\t\t\t\tDo you have any more questions?");
			printf("\n\t\t\t\t\t\t\t\tType your response:");  printf("(yes or no)\n\t\t\t\t\t\t\t\t\t");
			scanf(" %s", strResponse);
			if(strcmp(strResponse, "yes")== 0 || strcmp(strResponse, "Yes") ==0)
				askAgain = 1;

			else if(strcmp(strResponse, "no")==0 || strcmp(strResponse, "No")==0)
				askAgain = 0;
			else askAgain = 0;
		}
		system("cls");
	}
}

/*
	loginDataManagement: Manages the user login process
	@param userRegistrant An array of User structures representing the registered users
	@param i A pointer to an integer representing the number of registered users
	@return An integer representing the status of the login process. Returns 1 if login is successful, and 0 if unsuccessful.
	Precondition: The userRegistrant array contains at least one registered user, and the i pointer is pointing to a valid integer.
*/
int
loginDataMananagement(struct User userRegistrant[], int *i)
{
    int loginStatus = 0;
    int userID,index,count = 0;
    char password[10 + 1];
	char ch;
	int index1=0, userExists, passwordMatch, found = 0;

	do
	{
		userExists = 0;
		passwordMatch = 0,
		system("cls");
		displayHeader();
		printf("\n\n\t\t\t\t\t\t\t\t\t\t  L O G - I N ");
		// If the user has attempted to login before, clear console again
		if (loginStatus == 1 && count != 0)
			system("cls");

		// Prompt user for User ID within 1000-9999
		do
		{
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t User ID :  ");
			scanf("%d", &userID);
		}while(userID > 9999 || userID < 1000);
		
		/// Prompt user for Password with masking input with asterisks
		printf("\t\t\t\t\t\t\t\t\t\tPassword :  ");
		// Mask input with asterisks
		index = 0;
		ch = ' ';
		while (ch != '\r' && ch != '\n') // Stop when enter is pressed
		{ // Stop when enter is pressed
			ch = getch();
			if (ch == '\b') 
			{ // Handle backspace
				if (index > 0) 
				{
					index--;
					putchar('\b');
					putchar(' ');
					putchar('\b');
				}
			}
			else if ((index < 10 && ch != '\n') && (index < 10 && ch != '\r')) { // Handle regular input
				password[index] = ch;
				putchar('*');
				index++;
			}
		}
		password[index] = '\0';

		//Check if UserID and Password Match
		for (index1 = 0; (index1 <= *i && found == 0) ; index1++)
		{
			if (userRegistrant[index1].userID == userID)
			{
				userExists = 1;
				if (strcmp(userRegistrant[index1].password, password) == 0)
				{
					passwordMatch = 1;
					found = 1;
				}
			}
		}	// Display login status
			if (found)
			{
				printf("\n\n\t\t\t\t\t\t\t\t\t   Status: Login successful.");
				getch();
				loginStatus =  1;
			}

			if (userExists == 0)
			{ 
				loginStatus =  0;
				printf("\n\n\t\t\t\t\t\t\t\tStatus: Account does not exist. Try again.");
				getch();
			}
			
			if (!passwordMatch && userExists)

			{
				loginStatus =  0;
				printf("\n\n\t\t\t\t\t\t\t\t\tStatus: Incorrect password. Try again.");
				getch();
				
			}
		count++;
	}while (count < 3 && loginStatus == 0);

    return loginStatus;
}

/*
	DataManMenu - Displays a menu for data management and calls functions to perform actions based on user input.
	@param userRegistrant[] An array of User structures representing registered users.
	@param userAppointment[] An array of Appointment structures representing appointments.
	@param FAQ[] An array of Chatbot structures representing frequently asked questions.
	@param i A pointer to the number of registered users.
	@param j A pointer to the number of appointments.
	@param k A pointer to the number of frequently asked questions.
	@return void.
	Precondition: The arrays userRegistrant, userAppointment, and FAQ have been initialized with the appropriate structures and the pointers i, j, and k have been initialized with the number of elements in the respective arrays.
*/
void 
DataManMenu(struct User userRegistrant[], 
			struct Appointment userAppointment[], 
			struct Chatbot FAQ[], 
			int *i, 
			int* j, 
			int*k)
{
	int nChoice, repeat = 1;
	
	while (repeat == 1) // The while loop will keep executing the menu until the user chooses to exit
	{
		// Clear the screen and display the header and menu options
		system("cls");
		displayHeader();
		printf("\n\n\t\t\t\t\t\t\t\t  D A T A   M A N A G E M E N T   M E N U ");
		printf ("\n\n\t\t\t\t\t\t\t\t\t\t1) ");
		printf("User");
		printf ("\n\t\t\t\t\t\t\t\t\t\t2) ");
		printf("Appointment");
		printf ("\n\t\t\t\t\t\t\t\t\t\t3) ");
		printf("Chatbot");
		printf ("\n\t\t\t\t\t\t\t\t\t\t4) ");
		printf("Export");
		printf ("\n\t\t\t\t\t\t\t\t\t\t5) ");
		printf("Import");
		printf ("\n\t\t\t\t\t\t\t\t\t\t6) ");
		printf("Exit");
		// Prompt the user to enter their choice
		printf ("\n\n\t\t\t\t\t\t\t\t\t   Choose command: ");
		scanf("%d", &nChoice);
		fflush(stdin);
		// Execute the selected option based on the user's input
		switch (nChoice)
		{
			case 1: // Case 1: User Management Menu
					userManagementMenu(userRegistrant, i);
					repeat = 1;
					break;
			
			case 2: // Case 2: Appointment Management Menu
					appointmentManagemantMenu(userAppointment, j);
					break;
			
			case 3: // Case 3: Chatbot Management Menu
					chatbotManagemanetMenu(FAQ, k);
					break;
	
			case 4: // Case 4: Export Data Menu
					ExportMenu(userRegistrant, userAppointment, FAQ, i, j, k);
					break;
			
			case 5: // Case 5: Import Data Menu
					importMenu(userRegistrant, userAppointment, FAQ, i, j,k);
					break;
			case 6: // Case 6: Exit the program
					repeat = 0; // Set repeat to 0 to exit the while loop
					break;
		}
	}
}

/*
	displayDataManMenu - Displays the login page and redirects the user to the data management menu if logged in successfully.
	@param userRegistrant An array of struct User representing the list of registered users.
	@param userAppointment An array of struct Appointment representing the list of appointments.
	@param FAQ An array of struct Chatbot representing the frequently asked questions.
	@param i A pointer to an integer representing the number of registered users.
	@param j A pointer to an integer representing the number of appointments.
	@param k A pointer to an integer representing the number of frequently asked questions.
	@return void
	Precondition: The arrays userRegistrant, userAppointment, and FAQ have been initialized and contain valid data. The pointers i, j, and k point to integers that hold the sizes of the corresponding arrays.
*/
void 
displayDataManMenu(struct User userRegistrant[],
                        struct Appointment userAppointment[],
						struct Chatbot FAQ[],
                        int *i,
                        int *j,
						int *k)
{
	int result;
	system("cls");
	displayHeader();

	result = loginDataMananagement(userRegistrant, i);
	getch();

	if (result == 1)
	{
		DataManMenu(userRegistrant,userAppointment, FAQ, i, j, k);
	}
	else if (result == 0)
	{
		system("cls");
		exitPrompt(userRegistrant, userAppointment, FAQ);
	}

}
/*
	userManagementMenu - manages the menu for user management
	@param userRegistrant array of User structure containing user details
	@param i pointer to an integer that indicates the total number of registered users
	@return void
	Precondition: userRegistrant must be a valid array of User structure and i must be a valid pointer to an integer
*/
void
userManagementMenu(struct User userRegistrant[], 
				   int* i)
{
	int nChoices, check, repeat = 1;
	while (repeat == 1)    // loops until the user chooses to exit
	{
		do
		{
			check=0;
			system("cls");
			displayHeader();
			printf("\n\n\t\t\t\t\t\t\t\t      U S E R   M A N A G E M E N T  M E N U");
			printf ("\n\n\t\t\t\t\t\t\t\t\t\t1) Add New User");
			printf("\n\t\t\t\t\t\t\t\t\t\t2) View All Users");
			printf("\n\t\t\t\t\t\t\t\t\t\t3) Edit User Detail");
			printf("\n\t\t\t\t\t\t\t\t\t\t4) Delete User");
			printf("\n\t\t\t\t\t\t\t\t\t\t5) Exit");
			printf("\n\n\t\t\t\t\t\t\t\t\t   Choose command: ");
			scanf("%d" ,&nChoices);
			fflush(stdin);
			if (nChoices!=1 && nChoices!=2 && nChoices!=3 && nChoices!=4 && nChoices!=5)
			{
				system("cls");
				check=1;	// loops back if an invalid option is selected
			}
		}while(check);

		if (nChoices == 1)
		{
			(*i)++;
			addNewUser(userRegistrant,i); // calls the function to add new user
			repeat = 1;
			fflush(stdin);
		}
		else if (nChoices == 2)
		{
			viewAllUser(userRegistrant, i);   // calls the function to view all users
			repeat = 1;
			fflush(stdin);
		}
		else if (nChoices == 3)
		{
			editNewUser(userRegistrant, i); // calls the function to edit user details
			repeat = 1;
			fflush(stdin);
		}
		else if (nChoices == 4)
		{
			deleteNewUser(userRegistrant, i); // calls the function to delete user details
			repeat = 1;
			fflush(stdin);
		}
		else if (nChoices == 5) // exists the loop
		{
			repeat = 0;
			fflush(stdin);
		}
	}
}
/*
	addNewUser - function to add new user to the system
	@param userRegistrant: array of User structure to hold users information
	@param i: pointer to an integer which holds the index of the last added user
	@return void
	Precondition: userRegistrant and i should not be NULL
*/
void
addNewUser(struct User userRegistrant[], 
		   int* i)
{
	
	int check, len, index, repeat = 0;
	char ch;
	char input[12];
	char strResponse[4];
	char password1[11]; // Maximum length is 10 + '\0'

	do
	{
		do
		{
			do
			{
				check = 0;
				system("cls");
				displayHeader();
				printf("\n\t\t\t\t\t\t\t\t\t   A D D   N E W   U S E R");
				//Prompt for getting UserID for the new users added.
				printf("\n\n\t\t\t\t\t\t\t\t    Preferred userID :    ");  
				scanf("%d", &userRegistrant[*i].userID);
				fflush(stdin);

				if(userRegistrant[*i].userID < 1000 || userRegistrant[*i].userID > 9999)
				{
					check = 1;
					printf("\n\t\t\t\t\t\t\t\t\tUser ID must be 4 digit numbers");
					getch();
				}
			} while (check);
			if(userIDCheckingDuplication(userRegistrant, userRegistrant[*i].userID, i)==1)
			{
				check = 1;
				printf("\n\n\t\t\t\t\t\t\t   This userID already exists. Please type another.");
				getch();
			}
		} while (check);

		do 
		{
			//Prompt for getting password for the new users added.
			printf("\t\t\t\t\t\t\t\t\t    Password :    ");

			// Mask input with asterisks
			index = 0;
			ch = ' ';   // to read characters from the input without echoing them to the console.
			while (ch != '\r' && ch != '\n') 
			{
				// Stop when enter is pressed
				ch = getch();
				if (ch == '\b') { // Handle backspace
					if (index > 0) {
						index--;
						putchar('\b');
						putchar(' ');
						putchar('\b');
					}
				}
				else if (index < 10  && ch != '\r' && ch != '\n') { // Handle regular input
					password1[index] = ch;
					putchar('*');
					index++;
				}
			}
			password1[index] = '\0';
			strcpy(userRegistrant[*i].password, password1);
			len = strlen(password1);
			if (len == 0 || len > 10)
			{
				
				printf("\n\t\t\t\t\t\t\t\t(Error)\n");
				check = 1;
			}
			else
			{
				check = 0;
			}
		}while (check);

		do {
			//Prompt for getting fullname for the new users added.
			printf("\n\t\t\t\t\t\t\t\t\t   Full Name :    ");
			scanf(" %[^\n]s", userRegistrant[*i].fullName);
			fflush(stdin);
			if (strlen(userRegistrant[*i].fullName) > 20 || strlen(userRegistrant[*i].fullName) == 0) 
			{
				
				printf("\n\t\t\t\t\t\t\t\t(Error)\n");
				check = 1;
			}
			else 
			{
				check = 0;
			}
		} while (check);

		do 
		{
			//Prompt for getting address for the new users added.
			fflush(stdin);
			check = 0;
				printf("\t\t\t\t\t\t\t\t        Home Address :    ");
			scanf(" %[^\n]s", userRegistrant[*i].address);
			fflush(stdin);
			if (strlen(userRegistrant[*i].address) == 0 || strlen(userRegistrant[*i].address) > 30) 
			{
				check = 1;
				printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		} while (check);

		do 
		{
			check = 0;
			printf("\t\t\t\t\t\t\t\t       Contact number:    ");
			if (fgets(input, 12, stdin) != NULL) 
			{ // read input as string with max length 11
				input[strcspn(input, "\n")] = 0; // remove trailing newline character
				if (strlen(input) == 11) { // check if input is 11 characters long
					userRegistrant[*i].contact = strtoll(input, NULL, 10); // convert string to long long integer
				} else {
					check = 1;
					printf("\n\t\t\t\t\t\t\t\t\t(Error)\n");
				}
			}
    	} while (check);

		do 
		{
			//Prompt for getting sex for the new users added.
			check = 0;
			printf("\t\t\t\t\t\t\t\t\t\t Sex :    ");
			scanf(" %[^\n]s", userRegistrant[*i].sex);
			fflush(stdin);
			if (strlen(userRegistrant[*i].sex) == 0 || strlen(userRegistrant[*i].sex) > 10) 
			{
				check = 1;
				printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		} while (check);

		do 
		{
			//Prompt for getting date of first dose for the new users added.
			check = 0;
			printf("\t\t\t\t\t\t     Date of First Dose (YYYY-MM-DD) :    ");
			scanf(" %[^\n]s", userRegistrant[*i].string[0]);
			fflush(stdin);
			if (strlen(userRegistrant[*i].string[0]) > 10) 
			{
				check = 1;
				printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		} while (check);

		do 
		{
			//Prompt for getting first dose vaccine type for the new users added.
			check = 0;
			printf("\t\t\t\t\t\t\t     First Dose Vaccine Type :    ");
			scanf(" %[^\n]s", userRegistrant[*i].string[1]);
			fflush(stdin);
			if (strlen(userRegistrant[*i].string[1]) == 0 || strlen(userRegistrant[*i].string[1]) > 10) 
			{
				check = 1;
				printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		} while (check);

		do 
		{
			//Prompt for getting first vaccination location for the new users added.
			check = 0;
			printf("\t\t\t\t\t\t\t      Location of First Dose :    ");
			scanf(" %[^\n]s", userRegistrant[*i].string[2]);
			fflush(stdin);
			if (strlen(userRegistrant[*i].string[2]) == 0 || strlen(userRegistrant[*i].string[2]) > 10) 
			{
				check = 1;
				printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		} while (check);

		do
		{
			//Prompt for getting date of second dose for the new users added.
			check=0;
			printf("\t\t\t\t\t\t    Date of Second Dose (YYYY-MM-DD) :    ");
			scanf(" %[^\n]s", userRegistrant[*i].string[3]);
			fflush(stdin);
			if (strlen(userRegistrant[*i].string[3]) > 10)
			{
				check=1;
				printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		} while(check);

		do
		{
			//Prompt for getting second dose vaccine type for the new users added.
			check=0;
			printf("\t\t\t\t\t\t\t    Second Dose Vaccine Type :    ");
			scanf(" %[^\n]s" ,userRegistrant[*i].string[4]);
			fflush(stdin);
			if (strlen(userRegistrant[*i].string[4]) > 10)
			{
				check=1;
				printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		} while (check);

		do
		{
			//Prompt for getting second vaccination location for the new users added.
			check=0;
			printf("\t\t\t\t\t\t\t     Location of Second Dose :    ");
			scanf(" %[^\n]s" ,userRegistrant[*i].string[5]);
			fflush(stdin);
			if (strlen(userRegistrant[*i].string[5]) > 10)
			{
				check=1;
				printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		} while (check);

		do
		{
			//Prompt for getting date of booster dose for the new users added.
			check = 0;
			printf("\t\t\t\t\t\t   Date of Booster Dose (YYYY-MM-DD) :    ");
			scanf(" %[^\n]s", userRegistrant[*i].string[6]);
			fflush(stdin);
			if (strlen(userRegistrant[*i].string[6]) > 10)
			{
				check = 1;
					printf("\t\t\t\t\t\t\t\tInvalid date format. Please enter the date in the format YYYY-MM-DD.\n");
			}
		} while (check);

		do
		{
			//Prompt for getting booster dose vaccine type for the new users added.
			check = 0;
			printf("\t\t\t\t\t\t\t   Booster Dose Vaccine Type :    ");
			scanf(" %[^\n]s", userRegistrant[*i].string[7]);
			fflush(stdin);
			if (strlen(userRegistrant[*i].string[7]) > 10)
			{
				check = 1;
				printf("\t\t\t\t\t\t\t\tThe vaccine type should be no more than 10 characters long.\n");
			}
		} while (check);

		do
		{
			//Prompt for getting second vaccination location for the new users added.
			check = 0;
			printf("\t\t\t\t\t\t\t    Location of Booster Dose :    ");
			scanf(" %[^\n]s", userRegistrant[*i].string[8]);
			fflush(stdin);
			if (strlen(userRegistrant[*i].string[8]) > 10)
			{
				check = 1;
				printf("\t\t\t\t\t\t\t\tThe location should be no more than 10 characters long.\n");
			}
		} while (check);

		printf ("\n\n\n\t\t\t\t\t\t\t\t    Account Registered Successfully !\n");
		getch();

		//Prompt if wanted to add another user to the list on the userRegistration array
		printf("\n\t\t\t\t\t\t\t\t   Do you want to add more new user?"); 
		printf("\n\t\t\t\t\t\t\t\t    Type your response (yes or no): ");
		scanf(" %s", strResponse);
		
		if((strcmp(strResponse, "yes")== 0) || (strcmp(strResponse, "Yes") ==0))
		{
			repeat = 1;
			(*i)++;
			system("cls");
		}
		else 
		{
			repeat = 0;
		} 
	} while(repeat == 1);
	getch();
}

/*
	get_first_word Extracts the first word or the first width characters from a string and returns it.
	@param input The input string to extract the first word from.
	@param width The maximum width of the first word that should be returned.
	@return A pointer to a character array containing the first word or the first width characters from input.
	Precondition: input is not null.
*/
char* 
get_first_word(char* input, 
			  int width) 
{
	int len = strlen(input);
    char* output;
    char* delimiter = " -"; 

    if (len >= width) 
	{
        // Check if the first word itself exceeds the specified width
        int delimiter_pos = strcspn(input, delimiter);
        if (delimiter_pos > width) 
		{
            // Extract first `width` characters from the input string
            output = (char*) malloc((width + 1) * sizeof(char));
            strncpy(output, input, width);
            output[width] = '\0';
            return output;
        }
        // Extract the first word from the input string
        output = strtok(input, delimiter);
    } 
	else 
	{
        output = input;
    }

    output[strlen(output)] = '\0';
	/*
	if (len > width) {
        // Move the pointer past the first delimiter
        char* ptr = input + strcspn(input, delimiter);
        while (strlen(ptr) >= width) {
            // Extract `width` characters from the input string
            char* temp = (char*) malloc((width + 1) * sizeof(char));
            strncpy(temp, ptr, width);
            temp[width] = '\0';
            // Concatenate the extracted text to the output string
            output = (char*) realloc(output, (strlen(output) + width + 1) * sizeof(char));
            strcat(output, temp);
            // Move the pointer past the delimiter and extracted text
            ptr += strcspn(ptr, delimiter) + width;
            free(temp);
        }
        // Concatenate any remaining text to the output string
        output = (char*) realloc(output, (strlen(output) + strlen(ptr) + 1) * sizeof(char));
        strcat(output, ptr);
    }
	*/
    return output;
}
/*
	compareUsers - compares the userID of two User structs and returns the difference between them
	@param a a pointer to a User struct to be compared
	@param b a pointer to a User struct to be compared
	@return an integer value that represents the difference between the userID of the two User structs
	Precondition: a and b must be pointers to valid User structs
*/
int 
compareUsers(const void *a, 
			 const void *b) 
{
	const struct User *userA, *userB;

    userA = (const struct User *)a;
    userB = (const struct User *)b;

    return userA->userID - userB->userID;
}
/*
	viewAllUser - displays all user information in a tabular format sorted by user ID
	@param userRegistrant An array of User structures containing the user information
	@param i A pointer to an integer representing the total number of users
	@return void
	Precondition: The userRegistrant array must have at least one user
*/
void 
viewAllUser(struct User userRegistrant[], 
		    int* i) 
{
    int j;
	char *name, *address, *sex, *string0, *string1, *string2, *string3, *string4, *string5, *string6, *string7, *string8;	

	system("cls"); //clears the console
    printf("\n");

	displayHeader();  //@rints the header
	printf("\n\t\t\t\t\t\t\t\t       V I E W   A L L   U S E R S");
	printf("\n\n");
	
	if (*i > 0)
		qsort(userRegistrant, (*i)+1 , sizeof(struct User), compareUsers); //sorts userRegistrant based on userID

	displayPlainLines(); 	
	printf("| %-6s | %-10s | %-10s | %-11s | %-8s | %-10s | %-9s | %-9s | %-10s | %-9s | %-9s | %-10s | %-9s | %-9s |", "UserID", "Name", "Address", "Contact", "Sex", "Date1", "Vaccine1", "Location1", "Date2", "Vaccine2", "Location2", "Date3", "Vaccine3", "Location3");
	printf("\n");
	displayPlainLines();

	// print each user's information in a row
    for (j = 0; j <= (*i); j++) 
	{
		name = get_first_word(userRegistrant[j].fullName, 10);      //gets the first 10 characters of fullName
		address = get_first_word(userRegistrant[j].address, 10);    //gets the first 10 characters of address
		sex = get_first_word(userRegistrant[j].address, 10);
		string0 = get_first_word(userRegistrant[j].string[0], 10);  //gets the first 10 characters of string[0]
		string1 = get_first_word(userRegistrant[j].string[1], 9);   //gets the first 9 characters of string[1]
		string2 = get_first_word(userRegistrant[j].string[2], 9);   //gets the first 9 characters of string[2]
		string3 = get_first_word(userRegistrant[j].string[3], 10);  //gets the first 10 characters of string[3]
		string4 = get_first_word(userRegistrant[j].string[4], 9);   //gets the first 9 characters of string[4]
		string5 = get_first_word(userRegistrant[j].string[5], 9);   //gets the first 9 characters of string[5]
		string6 = get_first_word(userRegistrant[j].string[6], 10);  //gets the first 10 characters of string[6]
		string7 = get_first_word(userRegistrant[j].string[7], 9);   //gets the first 9 characters of string[7]
		string8 = get_first_word(userRegistrant[j].string[8], 9);   //gets the first 9 characters of string[7]

		if (*i == 0 && userRegistrant[j].userID == 0)
			memset(&userRegistrant[*i], 0, sizeof(struct User));


        printf("| %-6d | %-10s | %-10s | %011lld | %-8s | %-10s | %-9s | %-9s | %-10s | %-9s | %-9s | %-10s | %-9s | %-9s |\n",
                userRegistrant[j].userID, name, address, userRegistrant[j].contact, sex,
               	string0, string1, string2, string3, string4, string5,
                string6, string7, string8);
		if (j != (*i))
		{
			printf("+--------+------------+------------+-------------+----------+------------+-----------+-----------+------------+-----------+-----------+------------+-----------+-----------+");
			
		}
    }
	displayPlainLines(); 	
	getch();
}
/*
	editNewUser - Edits an existing user's information.
	@param userRegistrant: array of User structures representing the list of registered users
	@return void
	Preconditions: userRegistrant should not be NULL
*/
void editNewUser(struct User userRegistrant[],
				int *i)
{
	int repeat, index, len, check = 0, userNum = 0;
	char input[12];
	char password1[11], strResponse[4];
	char ch;

	do{
		do
		{
			system("cls"); //clears console
			displayHeader(); 
			// Prompt the user for the user number to modify
			printf("\n\n\t\t\t\t\t\t\t\t\t   E D I T   N E W   U S E R\n");
			printf("\n\n\t\t\t\t\t\t\t       What user number do you wish to modify :  ");
			scanf("%d", &userNum);
		} while (userNum > *i +1);
		
		userNum -= 1;
		check = 0;  // Initialize check to 0 and clear the console
		
		system("cls");
		displayHeader();
		printf("\n\n\t\t\t\t\t\t\t\t\t   E D I T   N E W   U S E R\n");
		printf("\n\n\t\t\t\t\t\t\t\t    Preferred userID :    ");
		scanf("%d", &userRegistrant[userNum].userID);
		fflush(stdin);
	
	    do 
		{
			// Prompt the user for the password, mask the input with asterisks 
	        printf("\t\t\t\t\t\t\t\t\t    Password :    ");
	        // Mask input with asterisks
	        index = 0;
	        ch = ' ';   // to read characters from the input without echoing them to the console.
	        while (ch != '\r' && ch != '\n') 
			{
				// Stop when enter is pressed
				ch = getch();
	            if (ch == '\b') 
				{ // Handle backspace
	                if (index > 0) {
	                    index--;
	                    putchar('\b');
	                    putchar(' ');
	                    putchar('\b');
	                }
	            }
	            else if (index < 10  && ch != '\r' && ch != '\n')
				{ // Handle regular input
	                password1[index] = ch;
	                putchar('*');
					index++;
	            }
	        }
	        password1[index] = '\0';
			strcpy(userRegistrant[userNum].password, password1); // Copy the password from password1 to userRegistrant[userNum].password
	        len = strlen(password1);
	        if (len == 0 || len > 10) // Check the length of the password
			{
	            printf("\n\t\t\t\t\t\t\t\t(Error)\n");
	            check = 1;
	        }
	        else
			{
	            check = 0; // Set check to 0 if the password is valid
	        }
	    }while (check);
		// Prompt for and store user's full name, with input validation
		do 
		{
	        printf("\n\t\t\t\t\t\t\t\t\t   Full Name :    ");
			scanf(" %[^\n]s", userRegistrant[userNum].fullName);
	        fflush(stdin);
	        if (strlen(userRegistrant[userNum].fullName) > 20 || strlen(userRegistrant[userNum].fullName) == 0) 
			{    
	            printf("\n\t\t\t\t\t\t\t\t(Error)\n");
	            check = 1;
	        }
	        else 
			{
	            check = 0;
	        }
	    } while (check);
		// Prompt for and store user's home address, with input validation
		do {
			check = 0;
			printf("\t\t\t\t\t\t\t\t        Home Address :    ");
			scanf(" %[^\n]s", userRegistrant[userNum].address);
			fflush(stdin);
			if (strlen(userRegistrant[userNum].address) == 0 || strlen(userRegistrant[userNum].address) > 30) 
			{
				check = 1;
				printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		} while (check);
		// Prompt for and store user's contact number, with input validation
		do {
				check = 0;
				printf("\t\t\t\t\t\t\t\t       Contact number:    ");
				if (fgets(input, 12, stdin) != NULL) // read input as string with max length 11
				{ 
					input[strcspn(input, "\n")] = 0; // remove trailing newline character
					if (strlen(input) == 11) // check if input is 11 characters long
					{ 
						userRegistrant[userNum].contact = strtoll(input, NULL, 10); // convert string to long long integer
					} 
					else 
					{
						check = 1;
						printf("\n\t\t\t\t\t\t\t\t\t(Error)\n");
					}
				}
			} while (check);

		// Prompt for and store user's sex, with input validation
		do 
		{
			fflush(stdin);
			check = 0;
			printf("\t\t\t\t\t\t\t\t\t\t Sex :    ");
			scanf(" %[^\n]s", userRegistrant[userNum].sex);
			fflush(stdin);
			if (strlen(userRegistrant[userNum].sex) == 0 || strlen(userRegistrant[userNum].sex) > 10) 
			{
				check = 1;
				 printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		} while (check);
		// Prompt user to input date of first dose in YYYY-MM-DD format
		do 
		{
			fflush(stdin);
			check = 0;
			printf("\t\t\t\t\t\t      Date of First Dose (YYYY-MM-DD):    ");
			scanf(" %[^\n]s", userRegistrant[userNum].string[0]);
			fflush(stdin);
			if (strlen(userRegistrant[userNum].string[0]) > 10) 
			{
				check = 1;
				printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		} while (check);
		// Prompt user to input vaccine type of first dose			
		do {
			fflush(stdin);
			check = 0;
			printf("\t\t\t\t\t\t\t      First Dose Vaccine Type:    ");
			scanf(" %[^\n]s", userRegistrant[userNum].string[1]);
			fflush(stdin);
			if (strlen(userRegistrant[userNum].string[1]) == 0 || strlen(userRegistrant[userNum].string[1]) > 10) 
			{
				check = 1;
				 printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		} while (check);
		// Prompt user to input location of first dose
		do 
		{
			fflush(stdin);
			check = 0;
			 printf("\t\t\t\t\t\t\t       Location of First Dose:    ");
			scanf(" %[^\n]s", userRegistrant[userNum].string[2]);
			fflush(stdin);
			if (strlen(userRegistrant[userNum].string[2]) == 0 || strlen(userRegistrant[userNum].string[2]) > 10) 
			{
				check = 1;
				 printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		} while (check);
		// Prompt user to input date of second dose in YYYY-MM-DD format
		do
		{
			fflush(stdin);
			check=0;
			printf("\t\t\t\t\t\t     Date of Second Dose (YYYY-MM-DD):    ");
			scanf(" %[^\n]s", userRegistrant[userNum].string[3]);
			fflush(stdin);
			if (strlen(userRegistrant[userNum].string[3]) > 10)
			{
				check=1;
				 printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		} while(check);
		// Prompt user to input vaccine type of second dose
		do
		{
			fflush(stdin);
			check=0;
			printf("\t\t\t\t\t\t\t    Second Dose Vaccine Type :    ");
			scanf(" %[^\n]s" ,userRegistrant[userNum].string[4]);
			fflush(stdin);
			if (strlen(userRegistrant[userNum].string[4]) > 10)
			{
				check=1;
				 printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		} while (check);
		// Prompt user to input location of second dose
		do
		{
			fflush(stdin);
			check=0;
			printf("\t\t\t\t\t\t\t     Location of Second Dose :    ");
			scanf(" %[^\n]s" ,userRegistrant[userNum].string[5]);
			fflush(stdin);
			if (strlen(userRegistrant[userNum].string[5]) > 10)
			{
				check=1;
				 printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		} while (check);
		// Checking and getting input for Date of Booster Dose
		do
		{
			fflush(stdin);
			check = 0;
			printf("\t\t\t\t\t\t   Date of Booster Dose (YYYY-MM-DD) :    ");
			scanf(" %[^\n]s", userRegistrant[userNum].string[6]);
			fflush(stdin);
			if (strlen(userRegistrant[userNum].string[6]) > 10)
			{
				check = 1;
				 printf("\t\t\t\t\t\t\t\tInvalid date format. Please enter the date in the format YYYY-MM-DD.\n");
			}
		} while (check);
		// Checking and getting input for Location of Booster Dose
		do
		{
			fflush(stdin);
			check = 0;
			 printf("\t\t\t\t\t\t\t   Booster Dose Vaccine Type :    ");
			scanf(" %[^\n]s", userRegistrant[userNum].string[7]);
			fflush(stdin);
			if (strlen(userRegistrant[userNum].string[7]) > 10)
			{
				check = 1;
				 printf("\t\t\t\t\t\t\t\tThe vaccine type should be no more than 10 characters long.\n");
			}
		} while (check);
		// Checking and getting input for Location of Booster Dose
		do
		{
			fflush(stdin);
			check = 0;
			printf("\t\t\t\t\t\t\t    Location of Booster Dose :    ");
			scanf(" %[^\n]s", userRegistrant[userNum].string[8]);
			fflush(stdin);
			if (strlen(userRegistrant[userNum].string[8]) > 10)
			{
				check = 1;
				printf("\t\t\t\t\t\t\t\tThe location should be no more than 10 characters long.\n");
			}
		} while (check);
		// Prompting user to edit another user's details or not
		printf ("\n\t\t\t\t\t\t\t\tUser No. %d's Details Edited Successfully !\n", userNum+1);
		printf("\n\t\t\t\t\t\t\t\tDo you want to edit another new user?"); 
		printf("\n\t\t\t\t\t\t\t\tType your response (yes or no): ");
		scanf(" %s", strResponse);
		// Checking user's response to repeat the loop or not
		if((strcmp(strResponse, "yes")== 0) || (strcmp(strResponse, "Yes") ==0))
		{
			repeat = 1;
			userNum++;
			system("cls");
		}
		else
		{
			repeat = 0;
		} 
	} while(repeat);

	getch();
}
/*
	deleteNewUser Deletes a user from the userRegistrant array.
	@param userRegistrant The array of struct User containing all the registered users.
	@param i A pointer to the current number of registered users.
	@return Void.
	Precondition: The userRegistrant array must have at least one registered user.
*/
void deleteNewUser(struct User userRegistrant[],
				   int *i) 
{
	int userNum, j, flag = 1;
	char choice;

	do
	{
		system("cls");
		displayHeader();
		printf("\n\n\t\t\t\t\t\t\t\t\t       D E L E T E   U S E R\n");
		printf("\n\n\t\t\t\t\t\t\t\t    What user number do you wish to delete:");
		scanf("%d", &userNum); // Asks user for the user number to delete

		userNum -=1;  // Adjusts userNum to match array index

		if (userNum > (*i + 1)) 
		{
			printf("\n\t\t\t\t\t\t\t\t\t\t    Invalid user number. Please enter a number between 1 and %d, inclusive.\n", *i);
			getch();
			return;
		}
		// Shift all elements after index i one position to the left
		if (userNum == 0 && *i == 0)
		{
			memset(&userRegistrant[*i], 0, sizeof(struct User));  // Clears memory of deleted user
			printf("\n\t\t\t\t\t\t\tUser %d successfully deleted!", userNum + 1);
			getch();
			return;
		}
		else
		{		
			for (j = userNum; j < *i; j++) 
			{
				userRegistrant[j] = userRegistrant[j+1]; // Shifts all elements after index i one position to the left
			}
			memset(&userRegistrant[j], 0, sizeof(struct User)); // Clears memory of last element in the array
		}
		(*i)--;  // Decrements i to account for the deleted user
		printf ("\n\t\t\t\t\t\t\t\t      User No. %d Is Deleted Successfully !", userNum + 1);
		
		printf("\n\n\t\t\t\t\t\t\t\tDo you want to delete another user? (Y/N): ");  // Asks user if they want to delete another user
		scanf(" %c", &choice);
		if (choice == 'N' || choice == 'n') 
		{
			flag = 0;
		}
		getch();
	}while (flag);
}
/*
	appointmentManagemantMenu - manages the appointment data by providing options to add, view, edit and delete appointments.
	@param userAppointment - an array of struct Appointment which stores the appointments.
	@param j - a pointer to an integer variable which stores the index of the last appointment in the array.
	@return None
	Precondition: The userAppointment array must be initialized and the j pointer must point to a valid integer variable.
*/
void appointmentManagemantMenu(struct Appointment userAppointment[], 
						       int *j)
{
	// Function to display appointment management menu and handle user choices
	int nChoices, check, repeat = 1;
	while (repeat == 1)
	{
		do
		{
			check=0;
			system("cls");
			displayHeader();
			printf("\n\n\t\t\t\t\t\t\tA P P O I N T M E N T   D A T A   M A N A G E M E N T  M E N U\n\n");
			printf ("\n \t\t\t\t\t\t\t\t\t    1) ");
			printf ("Add New Appointment");
			printf("\n \t\t\t\t\t\t\t\t\t    2) ");
			printf("View All Appointment");
			printf("\n \t\t\t\t\t\t\t\t\t    3) ");
			printf("Edit Appointment Details");
			printf("\n \t\t\t\t\t\t\t\t\t    4) ");
			printf("Delete Appointment");
			printf("\n \t\t\t\t\t\t\t\t\t    5) ");
			printf("Exit");
			printf("\n\n\t\t\t\t\t\t\t\t\t     Choose command: ");
			scanf("%d" ,&nChoices);
			fflush(stdin);
			if (nChoices!=1 && nChoices!=2 && nChoices!=3 && nChoices!=4 && nChoices!=5)
			{
				system("cls");
				check=1;	//if none of the given choice is selected, loop it back
			}
			printf("\n\t\t\t\t\t\t\t\t\t Current index %d", *j);
		}while(check);

		if (nChoices == 1) // Add new appointment
		{
			(*j)++;
			addNewAppointment(userAppointment,j);
			repeat = 1;
			fflush(stdin);
		}
		else if (nChoices == 2) // View all appointments
		{
			viewAllAppointment(userAppointment, j);
			repeat = 1;
			fflush(stdin);
		}
		 
		else if (nChoices == 3) // Edit appointment details
		{
			editNewAppointment(userAppointment, j);
			repeat = 1;
			fflush(stdin);
		}
		
		else if (nChoices == 4)  // Delete appointment
		{
			deleteNewAppointment(userAppointment, j);
			repeat = 1;
			fflush(stdin);
		}
		else if (nChoices == 5)  // Exit
		{
			repeat = 0;
			fflush(stdin);
		}
	}
}
/*
	addNewAppointment - function to add a new appointment to the system
	@param userAppointment: array of struct Appointment type to store all the user's appointments
	@param j: pointer to an integer to keep track of the number of appointments in the userAppointment array
	@return void
	Precondition: userAppointment must be initialized with struct Appointment type and j must be a valid integer pointer
*/
void addNewAppointment(struct Appointment userAppointment[], 
                       int *j)
{
	int check,repeat = 0;
	char strResponse[4];

	do
	{
		check = 0;
		system("cls");
		displayHeader();
		printf("\n\t\t\t\t\t\t\t\t   A D D   N E W   A P P O I N T M E N T");

		do
		{  //prompts user to enter the appointment ID
      		printf("\n\n\t\t\t\t\t\t\t              Preferred appID :    ");
			scanf("%d", &userAppointment[*j].appID);
			fflush(stdin);
		}while (apptIDCheckingDuplication(userAppointment, userAppointment[*j].appID, j)==1);


	    do 
		{
	        //prompts user to enter the customer name
	        printf("\t\t\t\t\t\t\t                    Full Name :    ");
			scanf(" %[^\n]s", userAppointment[*j].customerName);
	        fflush(stdin);
	        if (strlen(userAppointment[*j].customerName) > 20 || strlen(userAppointment[*j].customerName) == 0) 
			{
	            printf("\n\t\t\t\t\t\t\t\t(Error)\n");
	            check = 1;
	        }
	        else 
			{
	            check = 0;  //sets check to 0 to exit the loop
	        }
	    } while (check); //loops until a valid customer name is entered

		do 
		{
	        //prompts user to enter the appointment time
	        printf("\t\t\t\t\t\t\t                         Time :    ");
			scanf(" %[^\n]s", userAppointment[*j].time);
	        fflush(stdin);
	        if (strlen(userAppointment[*j].time) > 6 || strlen(userAppointment[*j].time) == 0) 
			{
	            
	            printf("\n\t\t\t\t\t\t\t\t(Error)\n");
	            check = 1;  //sets check to 1 to repeat the loop
	        }
	        else 
			{
	            check = 0;  //sets check to 0 to exit the loop
	        }
	    } while (check);  //loops until a valid appointment time is entered

		do 
		{ 
			// Prompt user for vaccination location
			fflush(stdin);
			check = 0;     
			 printf("\t\t\t\t\t\t\t         Vaccination Location :    ");
			scanf(" %[^\n]s", userAppointment[*j].string[0]);
			if (strlen(userAppointment[*j].string[0]) > 10) // Check if location input is valid
			{ 
				check = 1;
				printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		} while (check);
		// Prompt user for vaccine type
		do 
		{
			check = 0;
			fflush(stdin);
			printf("\t\t\t\t\t\t\t                 Vaccine Type :    ");
			scanf("%[^\n]s" ,userAppointment[*j].string[1]);
			fflush(stdin); // Check if vaccine type input is valid
			if (strlen(userAppointment[*j].string[1]) == 0 || strlen(userAppointment[*j].string[1]) > 10) 
			{
				check = 1;
				 printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		} while (check);
		// Prompt user for appointment date
		do 
		{
			check = 0;
			printf("\t\t\t\t\t\t\t             Appointment Date :    ");
			scanf(" %[^\n]s", userAppointment[*j].string[2]);
			fflush(stdin);  // Check if appointment date input is valid
			if (strlen(userAppointment[*j].string[2]) == 0 || strlen(userAppointment[*j].string[2]) > 11)
			{
				check = 1;
				printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		} while (check);
		// Prompt user for vaccine dose date
		do
		{
			check=0;
			printf("\t\t\t\t\t\t\t            Vaccine Dose Date :    ");
			scanf(" %[^\n]s", userAppointment[*j].string[3]);
			fflush(stdin); // Check if vaccine dose date input is valid
			if (strlen(userAppointment[*j].string[3]) > 10)
			{
				check=1;
				 printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		} while(check);
		// Prompt user for confirmation to add more appointments or not
		printf("\n\t\t\t\t\t\t\t              Account Registered Successfully !");
		printf("\n\t\t\t\t\t\t\t          Do you want to add more new appointment?"); 
		printf("\n\t\t\t\t\t\t\t             Type your response (yes or no):  ");scanf(" %s", strResponse);
		// If user wants to add more appointments, increment counter and clear screen
		if((strcmp(strResponse, "yes")== 0) || (strcmp(strResponse, "Yes") ==0))
		{
			repeat = 1;
			(*j)++;
			system("cls");
		}
		else  // Otherwise, set repeat flag to 0 to exit loop
		{
			repeat = 0;
		} 
	// End of appointment addition loop
	}while(repeat == 1);
	return;
}
/*
	viewAllAppointment: displays all the appointments in a formatted table
	@param userAppointment An array of struct Appointment that contains the appointment data
	@param j An integer pointer that points to the number of appointments in the array
	@return void
	Precondition: The userAppointment array must contain valid appointment data, and j must point to a valid integer value indicating the number of appointments.
*/
void viewAllAppointment(struct Appointment userAppointment[], 
 					    int *j)
{
	int l;
	system("cls");
	char *name, *string0, *string1, *string2, *string3;
	// Sort the userAppointment array using qsort
	
	system("cls");
	displayHeader(); // Display the header for the view all appointments screen
	// Display the table header for the appointments
	printf("\n\n\t\t\t\t\t\t\t          V I E W   A L L   A P P O I N T M E N T S");
	printf("\n\n\n\t\t\t");
	printf("===============================================================================================================================");
	printf("\n\t\t\t");
	printf("| %-10s | %-20s | %-15s | %-15s | %-15s | %-15s | %-15s |", "AppID", "Name", "Time", "Location", "Type", "Date", "Vaccine Dose");
	printf("\n\t\t\t");
	printf("===============================================================================================================================");
	printf("\n\t\t\t");
	// If there are no appointments, set the default values
	if((*j) == 0 && userAppointment[*j].appID == 0)
	{
		memset(&userAppointment[*j], 0, sizeof(struct Appointment));
	}
	// Loop through all the appointments and display the details in a table
	for (l = 0; l <= (*j); l++) 
	{
		name = get_first_word(userAppointment[l].customerName, 20);
		string0 = get_first_word(userAppointment[l].string[0], 15);
		string1 = get_first_word(userAppointment[l].string[1], 15);
		string2 = get_first_word(userAppointment[l].string[2], 15);
		string3 = get_first_word(userAppointment[l].string[3], 15);
	
		// Display the details of the appointment in a table row
		printf("| %-10d | %-20s | %-15s | %-15s | %-15s | %-15s | %-15s |", userAppointment[l].appID, name, userAppointment[l].time, string0, string1, string2, string3);
		// If it's not the last row, display a separator line
		if (l != (*j))
		{
			printf("\n\t\t\t");printf("+------------+----------------------+-----------------+-----------------+-----------------+-----------------+-----------------+");
		}
		printf("\n\t\t\t");
	}
	printf("===============================================================================================================================");
	getch();
}


/*
	editNewAppointment - This function allows the user to edit an appointment that has already been added.
	@userAppointment: the array of appointments where the new appointment will be stored.
	@j: a pointer to the number of appointments already in the array.
	Return: void.
	Precondition: the userAppointment array must be initialized with valid values.
*/
void editNewAppointment(struct Appointment userAppointment[], 
						int *j)
{
	// Initializing variables
	int repeat, check = 0, appointmentNum = 0;
	char strResponse[4];
	// Check if j is zero and initialize userAppointment array accordingly
	if(*j == 0)
	{
		strcpy(userAppointment[*j].customerName, " ");
		strcpy(userAppointment[*j].string[0], " ");
		strcpy(userAppointment[*j].string[1], " ");
		strcpy(userAppointment[*j].string[2], " ");
		strcpy(userAppointment[*j].string[3], " ");
		userAppointment[*j].customerName[strlen(userAppointment[*j].customerName)] = '\0';
		userAppointment[*j].string[0][strlen(userAppointment[*j].string[0])] = '\0';
		userAppointment[*j].string[1][strlen(userAppointment[*j].string[1])] = '\0';
		userAppointment[*j].string[2][strlen(userAppointment[*j].string[2])] = '\0';
		userAppointment[*j].string[3][strlen(userAppointment[*j].string[3])] = '\0';
	}
	// Loop until a non-duplicate appID is entered
	do
	{
		do
		{
			system("cls");
			displayHeader();
			printf("\n\t\t\t\t\t\t\t\t      E D I T   N E W   A P P O I N T M E N T");
			printf("\n\n\t\t\t\t\t\t\t\t  What user number do you wish to modify :  ");
			scanf("%d", &appointmentNum);
		}while (appointmentNum > *j+1);
		
		appointmentNum -= 1;

		// Loop until a non-duplicate appID is entered
		check = 0;		
		system("cls");
		displayHeader();
		printf("\n\t\t\t\t\t\t\t\t      E D I T   N E W    A P P O I N T M E N T");;
		do
		{
			printf("\n\n");
			printf("\t\t\t\t\t\t\t\t          Preferred appID :    ");
			scanf("%d", &userAppointment[appointmentNum].appID);
			fflush(stdin);
		}while (apptIDCheckingDuplication(userAppointment, userAppointment[appointmentNum].appID, j)==1);

		// Loop until a valid customer name is entered
	    do 
		{   
	        printf("\t\t\t\t\t\t\t\t                Full Name :    ");
			scanf(" %[^\n]s", userAppointment[appointmentNum].customerName);
			userAppointment[appointmentNum].customerName[strlen(userAppointment[appointmentNum].customerName)] = '\0';
	        fflush(stdin);
	        if (strlen(userAppointment[appointmentNum].customerName) > 20 || strlen(userAppointment[appointmentNum].customerName) == 0) 
			{
	            printf("\n\t\t\t\t\t\t\t\t(Error)\n");
	            check = 1;
	        }
	        else 
			{
	            check = 0;
	        }
	    } while (check);
		// Loop until a valid time is entered
		do {
	        
	        printf("\t\t\t\t\t\t\t\t                     Time :    ");
			scanf(" %[^\n]s", userAppointment[appointmentNum].time);
			userAppointment[appointmentNum].time[strlen(userAppointment[appointmentNum].time)] = '\0';
	        fflush(stdin);
	        if (strlen(userAppointment[appointmentNum].time) > 6 || strlen(userAppointment[appointmentNum].time) == 0) 
			{
	            
	            printf("\n\t\t\t\t\t\t\t\t(Error)\n");
	            check = 1;
	        }
	        else 
			{
	            check = 0;
	        }
	    }while (check);
		// Asking for the vaccination location from the user and storing it in userAppointment array
		do 
		{
			check = 0;
			 printf("\t\t\t\t\t\t\t\t     Vaccination Location :    ");
			scanf(" %[^\n]s", userAppointment[appointmentNum].string[0]);
			userAppointment[appointmentNum].string[0][strlen(userAppointment[appointmentNum].string[0])] = '\0';
			fflush(stdin);
			if (strlen(userAppointment[appointmentNum].string[0]) > 10)  // Checking the length of the input and setting check variable to 1 if it's greater than 10
			{
				check = 1;
				 printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		} while (check);
		// Asking for the first dose vaccine type from the user and storing it in userAppointment array
		do 
		{
			check = 0;
			printf("\t\t\t\t\t\t\t\t  First Dose Vaccine Type :    ");
			scanf(" %[^\n]s", userAppointment[appointmentNum].string[1]);
			userAppointment[appointmentNum].string[1][strlen(userAppointment[appointmentNum].string[1])] = '\0';
			fflush(stdin); // Checking the length of the input and setting check variable to 1 if it's greater than 10 or empty
			if (strlen(userAppointment[appointmentNum].string[1]) == 0 || strlen(userAppointment[appointmentNum].string[1]) > 10) 
			{
				check = 1;
				 printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		} while (check);
		// Asking for the appointment date from the user and storing it in userAppointment array
		do 
		{
			check = 0;
			printf("\t\t\t\t\t\t\t\t         Appointment Date :    ");
			scanf(" %[^\n]s", userAppointment[appointmentNum].string[2]);
			userAppointment[appointmentNum].string[2][strlen(userAppointment[appointmentNum].string[2])] = '\0';
			fflush(stdin); // Checking the length of the input and setting check variable to 1 if it's greater than 11 or empty
			if (strlen(userAppointment[appointmentNum].string[2]) == 0 || strlen(userAppointment[appointmentNum].string[2]) > 11) 
			{
				check = 1;
				printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		} while (check);
		// Asking for the vaccine dose date from the user an
		do
		{
			check=0;
			 printf("\t\t\t\t\t\t\t\t        Vaccine Dose Date :    ");
			scanf(" %[^\n]s", userAppointment[appointmentNum].string[3]);
			userAppointment[appointmentNum].string[3][strlen(userAppointment[appointmentNum].string[3])] = '\0';
			fflush(stdin); // Checking the length of the input and setting check variable to 1 if it's greater than 10
			if (strlen(userAppointment[appointmentNum].string[3]) > 10)
			{
				check=1;
				 printf("\t\t\t\t\t\t\t\t(Error)\n");
			}
		}while(check);
		
		// Displaying a success message after editing user's details
		printf ("\n\t\t\t\t\t\t\t\t    User No. %d's Details Edited Successfully !", appointmentNum+1);
		getch(); // Asking the user if they want to edit another appointment
		printf("\n\t\t\t\t\t\t\t\t       Do you want to edit another new user?"); printf("\n\t\t\t\t\t\t\t\t        Type your response (yes or no): ");
		scanf(" %s", strResponse);
		if((strcmp(strResponse, "yes")== 0) || (strcmp(strResponse, "Yes") ==0))
		{
			repeat = 1;
			appointmentNum++;
			system("cls");
		}
		else
		{
			repeat = 0;
		} 

	}while (repeat);
	getch();
}

/*
	deleteNewAppointment: Deletes an appointment from the userAppointment array.
	@param userAppointment: Pointer to an array of Appointment structures to store user appointments.
	@param j: Pointer to an integer that stores the number of appointments in the userAppointment array.
	@return None
	Precondition: The userAppointment array must have at least one appointment and j must be a non-negative integer.
*/
void deleteNewAppointment(struct Appointment userAppointment[],
					 	  int *j)
{
	int appNum, i, flag = 1;
	char choice;
	do
	{
		system("cls");
		displayHeader(); //displays the header
		printf("\n\n\t\t\t\t\t\t\t\t       D E L E T E   A P P O I N T M E N T\n");
		printf("\n\n\t\t\t\t\t\t\t\t What appointment number do you wish to delete? \n\t\t\t\t\t\t\t\t     Please enter a number between 1 and %d:  ", *j+1);
		scanf("%d", &appNum);
		appNum -= 1;
		if (appNum > (*j + 1))  //if invalid appointment number entered
		{
			printf("\n\t\t\t\t\t\t\t\t    Invalid appointment number. Please enter a number between 1 and %d, inclusive.\n", *j+1);
			getch();
			return;
		}

		// Shift all elements after index i one position to the left
		if (appNum== 0 && *j == 0)  //if only one appointment exists and it is being deleted
		{
			memset(&userAppointment[*j], 0, sizeof(struct Appointment));
			printf("\n\t\t\t\t\t\t\tAppointment successfully deleted.");
			getch();
			return;
		}

		else //if multiple appointments exist and the selected appointment is being deleted
		{
			for (i = appNum; i < (*j) ; i++) 
			{
				//shifts all the appointments one position to the left starting from the selected appointment index
				userAppointment[i] = userAppointment[i+1];
			}
			memset(&userAppointment[i], 0, sizeof(struct Appointment));
		}
		(*j)--; //decrementing the total appointments counter
		printf ("\n\t\t\t\t\t\t\t\t     Appointment No. %d Is Deleted Successfully!", appNum+1);
		printf("\n\t\t\t\t\t\t\t      Do you want to delete another question and answer? (Y/N): ");
		scanf(" %c", &choice);
		if (choice == 'N' || choice == 'n') 
		{
			flag = 0; //setting flag to 0 to exit the loop
		}
		getch();
	}while(flag);  //repeating the loop if flag is not 0
}

/*
	chatbotManagemanetMenu - a function that displays a menu for managing a chatbot's questions and answers
	@param FAQ an array of struct Chatbot containing the  questions and answers
	@param k a pointer to an integer representing the number of questions and answers in the FAQ array
	@return void
	Precondition: The FAQ array has been initialized with the questions and answers and k points to a valid integer
*/
void chatbotManagemanetMenu(struct Chatbot FAQ[], 
							int *k)
{
	int nChoices, check, repeat = 1;

	while (repeat == 1) // Loop until repeat is not equal to 1
	{
		do // Loop until user enters a valid choice
		{
			check=0;
			system("cls");
			displayHeader();
			printf("\n\n\t\t\t\t\t\t\t\tC H A T B O T  M A N A G E M E N T   M E N U");
			printf("\n\n\t\t\t\t\t\t\t\t\t1) ");
			printf("Add New Question and Answer");
			printf("\n\t\t\t\t\t\t\t\t\t2) ");
			printf("View All Question and Answer");
			printf("\n\t\t\t\t\t\t\t\t\t3) ");
			printf("Edit Question and Answer");
			printf("\n\t\t\t\t\t\t\t\t\t4) ");
			printf("Delete Question and Answer");
			printf("\n\t\t\t\t\t\t\t\t\t5) ");
			printf("Exit");
			printf("\n\n\t\t\t\t\t\t\t\t\t   Choose command: ");
			scanf("%d" ,&nChoices);
			fflush(stdin); 
			 // If user enters an invalid choice, clear the screen and set check to 1 to repeat the loop
			if (nChoices!=1 && nChoices!=2 && nChoices!=3 && nChoices!=4 && nChoices!=5)
			{
				system("cls");
				check=1;
			}
		}while(check);

		// Execute different actions based on user's choice
		if (nChoices == 1)
		{
			addNewFAQ(FAQ,k);
			repeat = 1;
			fflush(stdin);
		}
		else if (nChoices == 2)
		{
			viewAllFAQ(FAQ, k);
			repeat = 1;
			fflush(stdin);
		}
		else if (nChoices == 3)
		{
			editNewFAQ(FAQ, k);
			repeat = 1;
			fflush(stdin);
		}
		else if (nChoices == 4)
		{
			deleteNewFAQ(FAQ, k);
			repeat = 1;
			fflush(stdin);
		}
		else if (nChoices == 5)
		{
			repeat = 0;
			fflush(stdin);
		}
	}
}	

/*
	addNewFAQ - Add a new question and answer to the Chatbot FAQ array
	@param FAQ: array of Chatbot structures
	@param k: pointer to an integer representing the number of FAQs in the array
	@return None
	Precondition: The size of the array should be big enough to hold all the new questions and answers.
*/
void addNewFAQ(struct Chatbot FAQ[], 
			   int *k)
{
	int flag = 1;
	char choice;

	do // Start a loop to add a new FAQ
	{
		system("cls");
		displayHeader(); 
		
		// Prompt the user to enter a new question and store it in the current FAQ's "questions" array
		printf("\n\n\t\t\t\t\t\t\t\t\t     A D D   N E W  F A Q");
		fflush(stdin);
		printf("\n\n\n\t\t\t\t\t\t    Enter the question:  ");
		printf("\n\t\t\t\t\t\t\t    ");
		fgets(FAQ[*k].questions, sizeof(FAQ[*k].questions), stdin);
		fflush(stdin);
		FAQ[*k].questions[strlen(FAQ[*k].questions)] = '\0';
        fflush(stdin);

		// Prompt the user to enter a new answer and store it in the current FAQ's "answers" array
        printf("\n\t\t\t\t\t\t    Enter the answer:  ");
		printf("\n\t\t\t\t\t\t\t    ");
		fgets(FAQ[*k].answers, sizeof(FAQ[*k].answers), stdin);
		fflush(stdin);
		FAQ[*k].answers[strlen(FAQ[*k].answers)] = '\0';
        fflush(stdin);

		/// Prompt the user if they want to add another QnA and store their response in "choice"
        printf("\n\t\t\t\t\t\t    Do you want to add another QnA? (Y/N): ");scanf(" %c", &choice);
        // If the user chooses "N" or "n", exit the loop by setting "flag" to 0
		if (choice == 'N' || choice == 'n')
		{
			flag = 0;
		}
		// If the user chooses "Y" or "y", increment "k" to add another FAQ
		else if (choice == 'Y' || choice == 'y')
		{
			(*k)++;
		}
	} while (flag);
	return;
}

	/*
	viewAllFAQ - Displays all the QnA pairs in a tabular format.
	@param FAQ[] An array of Chatbot structures holding all the QnA pairs.
	@param k A pointer to an integer variable that keeps track of the number of QnA pairs.
	@return None
	Precondition: The array FAQ[] has been initialized and populated with QnA pairs.
*/
void viewAllFAQ(struct Chatbot FAQ[], 
				int* k) 
{
	int i;
	char *question, *answer;
	if (*k == 0)  // Check if this is the first QnA being added to the FAQ array
	{
		FAQ[*k].questions[strlen(FAQ[*k].questions)] = '\0';
		FAQ[*k].answers[strlen(FAQ[*k].answers)] = '\0';
	}
	
	system("cls");
	displayHeader();  // Display the view all QnA menu
    printf("\n\n\t\t\t\t\t\t\t\t\t     V I E W   A L L   Q N A");
    printf("\n\n\t\t");
	// Display table headers
    printf("============================================================================================================================================="); 
	printf("\n\t\t");
	printf("| %-67s | %-67s |", "Questions", "Answers");
    printf("\n\t\t");
    printf("============================================================================================================================================="); 
    // Print each FAQ entry in a table row
    for (i = 0; i <= *k; i++) 
	{
		question = get_first_word(FAQ[i].questions, 80);
		answer = get_first_word(FAQ[i].answers, 80);

		if (*k == 0 && strlen(FAQ[*k].questions) == 0)
			memset(&FAQ[*k], 0, sizeof(struct Chatbot));

		gotoxy(16, 19+(2*i));
		printf("| %s", question);
		gotoxy(86, 19+(2*i));
		printf("| %s",answer);
		gotoxy(156, 19+(2*i));
		printf("|");
		if (i != *k)  // Check if this is the last QnA, if not, print a horizontal line to separate the rows
		{
			printf("\n\t\t");printf("|-%-63s-|-%-65s-|","-------------------------------------------------------------------","-------------------------------------------------------------------");

		}
    }
	printf("\n\t\t");
    printf("=============================================================================================================================================");
	
    getchar();
    return;
}

/* 
	editNewFAQ - Edit an existing Q&A in the chatbot FAQ
	@param FAQ[] Array of chatbot FAQs
	@param k Pointer to the number of FAQs in the array
	@return void
	Precondition: The FAQ array has been initialized and contains at least one Q&A
*/
void editNewFAQ (struct Chatbot FAQ[], 
				 int *k)
{
	int index, flag = 1;
	char choice;
    do 
	{
		do 
		{
			system("cls");
			displayHeader(); 
			
			// Ask user for the index of the question to edit
			printf("\n\n\t\t\t\t\t\t\t\t\t     E D I T   C H A T B O T  Q  N A");
			printf("\n\n\t\t\t\t\t\t\t     Enter the row number you want to edit: ");
			scanf("%d", &index);
			fflush(stdin);
		}while (index > *k +1);

		index -= 1;
		
		// Ask user for the new question and answer
        printf("\n\t\t\t\t\t\t\t   Enter the new question: ");
		fgets(FAQ[index].questions, sizeof(FAQ[index].questions), stdin);
		FAQ[index].questions[strlen(FAQ[index].questions)] = '\0';
        printf("\n\t\t\t\t\t\t\t   Enter the new answer: ");
		fgets(FAQ[index].answers, sizeof(FAQ[index].answers), stdin);
		FAQ[index].answers[strlen(FAQ[index].answers)] = '\0';
		fflush(stdin);

		// Ask user if they want to edit another question and answer
        printf("\n\t\t\t\t\t\t\tDo you want to edit another question and answer? (Y/N): ");
        scanf(" %c", &choice);
		getchar();
		
		// Print the edited question and answer
		printf("\n%s\n", FAQ[index].questions);
		printf("%s\n", FAQ[index].answers);
		
		
		// Set flag to 0 if user chooses to stop editing
        if (choice == 'N' || choice == 'n')
		{
            flag = 0;
        }
    } while (flag);
	return;
}

/*
	deleteNewFAQ: Deletes a question and its answer from the FAQ list
	@param FAQ[] The array of FAQ structs
	@param k A pointer to the integer value that represents the number of FAQs
	@return void
	Precondition: The FAQ array and the integer pointer k must be initialized.
*/
void deleteNewFAQ (struct Chatbot FAQ[], 
				   int *k)
{
    int index, i, flag = 1;
	char choice;

    do // Loop to delete questions and answers
	{
		system("cls"); 
		displayHeader();  // Clear the console screen and display the header
		printf("\n\n\t\t\t\t\t\t\t           D E L E T E     C H A T B O T    Q  N A");
		fflush(stdin); 

		// Prompt the user to enter the index of the question they want to delete
        printf("\n\n\n\t\t\t\t\t\t\t\tEnter the question number you want to delete: ");
        scanf("%d", &index);
		
        index -= 1; // Decrement index to match array index and check if the last element of the array needs to be deleted

        if (index == 0 && *k == 0) 
		{
			// If the array only has one element, delete it and return from the function
            memset(&FAQ[*k], 0, sizeof(struct Chatbot));
            printf("\n\n\t\t\t\t\t\t\t          Question and answer deleted.");
            return;
        }
		else
		{
			for (i = index; i < *k; i++) 
			{
				// Shift elements to the left starting from the index to be deleted
				strcpy(FAQ[i].questions, FAQ[i + 1].questions);
				strcpy(FAQ[i].answers, FAQ[i + 1].answers);
			}
			memset(&FAQ[i], 0, sizeof(struct Chatbot)); // Clear the memory for the last element in the array
		}
		(*k)--; // Decrement the array size counter
		// Prompt the user if they want to delete another question and answer
		printf("\n\n\t\t\t\t\t\t\t          Question and answer deleted.");
		printf("\n\t\t\t\t\t\t\tDo you want to delete another question and answer? (Y/N): ");
		
		// Read the user's choice and set the flag to continue or exit the loop
		scanf(" %c", &choice);
		if (choice == 'N' || choice == 'n') 
		{
			flag = 0;
		}
		getch();
    } while (flag);
}

/*
	ExportMenu - Export user, appointment, and chatbot data to text files
	@param userRegistrant[] array of User struct containing user registration details
	@param userAppointment[] array of Appointment struct containing appointment details
	@param FAQ[] array of Chatbot struct containing frequently asked questions and answers
	@param i pointer to integer containing the number of registered users
	@param j pointer to integer containing the number of appointments made
	@param k pointer to integer containing the number of FAQs in the chatbot system
	@return void
	Precondition: The size of userRegistrant, userAppointment, and FAQ should not exceed their respective array size. All pointers should be initialized.
*/
void ExportMenu(struct User userRegistrant[], 
				struct Appointment userAppointment[], 
				struct Chatbot FAQ[], 
				int* i, 
				int* j,
				int* k)
{
	// Declare variables for file names and file pointers
    char fileName1[31], fileName2[31], fileName3[31];
	FILE *fp1, *fp2, *fp3;
	int x, y, z;

	// Clear console and display header
	system("cls");
	displayHeader();

	// Get file name for user details and save data to file
	printf("\n\n\t\t\t\t\t\t\t\t           E X P O R T   M E N U");
	fflush(stdin);
	printf("\n\n\n\t\t\t\t\t\t\t\t\tEnter the filename for saving\n\t\t\t\t\t\t\t\t\tthe User's Details: ");
    fgets(fileName1, sizeof(fileName1), stdin);
	fileName1[strcspn(fileName1, "\n")] = '\0';
	strcat(fileName1,".txt");  // Append ".txt"

    fp1 = fopen(fileName1, "w");
    for (x = 0; x <= *i; x++) 
	{
        fprintf(fp1, "%d %s\n%s\n%s\n%011lld\n%s\n%s %s %s\n%s %s %s\n%s %s %s\n\n",
            userRegistrant[x].userID, userRegistrant[x].password, userRegistrant[x].fullName, userRegistrant[x].address, userRegistrant[x].contact,
            userRegistrant[x].sex, userRegistrant[x].string[0], userRegistrant[x].string[1], userRegistrant[x].string[2],
            userRegistrant[x].string[3], userRegistrant[x].string[4], userRegistrant[x].string[5], userRegistrant[x].string[6],
            userRegistrant[x].string[7], userRegistrant[x].string[8]);
    }
	fprintf(fp1, "\n");
	fclose(fp1);


	// Get file name for appointment details and save data to file
	fflush(stdin);
	printf("\n\n\t\t\t\t\t\t\t\t\tEnter the filename for saving\n\t\t\t\t\t\t\t\t\tthe Appointment's Details: ");
	fflush(stdin);
    fgets(fileName2, sizeof(fileName2), stdin);
	fileName2[strcspn(fileName2, "\n")] = '\0';
	strcat(fileName2,".txt");  // Append ".txt"
	fp2 = fopen(fileName2, "w");
    for (y = 0; y <= *j; y++) 
	{
        fprintf(fp2, "%d %d\n%s \n%s \n%s \n%s \n%s \n%s \n\n",
            userAppointment[y].appID, userRegistrant[y].userID, userAppointment[y].customerName, userAppointment[y].string[0],
            userAppointment[y].string[1], userAppointment[y].string[2], userAppointment[y].string[3], userAppointment[y].time);
    }
	fprintf(fp2, "\n");
	fclose(fp2);

	// Get file name for chatbot FAQ details and save data to file
	fflush(stdin);
	printf("\n\t\t\t\t\t\t\t\t\tEnter the filename for saving\n\t\t\t\t\t\t\t\t\tthe Chatbot's Details: ");
	fgets(fileName3, sizeof(fileName3), stdin);
	fileName3[strcspn(fileName3, "\n")] = '\0'; // Remove newline character
	strncat(fileName3, ".txt", sizeof(fileName3) - strlen(fileName3) - 1); // Append ".txt"
	fileName3[sizeof(fileName3) - 1] = '\0'; // Make sure fileName3 is properly terminated

	fp3 = fopen(fileName3, "w");
    for (z = 0; z <= *k; z++) 
	{
        fprintf(fp3, "%s%s\n", FAQ[z].questions, FAQ[z].answers);
    }
	fprintf(fp3, "\n");
    fclose(fp3);

	printf("\n\t\t\t\t\t\t\t    Successfuly saved the data into those text files!");
	getch();
}

/*
	gotoxy This function moves the cursor to the specified coordinates in the console.
	@param x The x-coordinate to move the cursor to.
	@param y The y-coordinate to move the cursor to.
	@return void
	Precondition: The console window must be open and visible.
*/
void gotoxy(int x, 
 			int y) 
{
    static HANDLE h = NULL;
	// Get the console screen buffer handle
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
	// Set the cursor position to the specified coordinate
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}

/*
	importMenu - function to import data from text files into arrays
	@param userRegistrant[] - an array of User struct to store user registration data
	@param userAppointment[] - an array of Appointment struct to store user appointment data
	@param FAQ[] - an array of Chatbot struct to store chatbot FAQ data
	@param i - a pointer to an integer to store the number of registered users
	@param j - a pointer to an integer to store the number of appointments
	@param k - a pointer to an integer to store the number of FAQs
	@return void
	Precondition: User struct, Appointment struct, and Chatbot struct must be defined
*/
void importMenu(struct User userRegistrant[], 
				struct Appointment userAppointment[], 
				struct Chatbot FAQ[], 
				int* i, 
				int* j,
				int* k) 
{
    char filename[100];
    FILE *fp;
    char line[500];
	char answer;
	int numUsers = 0, numAppt = 0, numQNA = 0;
	int lineNum = 1;
	int count = 0;
	int ctr = 1;
	int idx1, idx3, idx2, idx_2; 

	// Allocate memory for temporary storage of imported data
	struct User* tempUser = calloc(100, sizeof(struct User));
	struct Appointment* tempAppt = calloc(100, sizeof(struct Appointment));
	struct Chatbot* tempQNA = calloc(100, sizeof(struct Chatbot));


	system("cls");
	displayHeader();
	printf("\n\n\t\t\t\t\t\t\t\t              I M P O R T  M E N U");
    
	// Get filename from user input
	printf("\n\n\n\t\t\t\t\t\t\t\t       Enter filename to import data: ");
	fflush(stdin);
    fgets(filename, sizeof(filename), stdin);
	filename[strcspn(filename, "\n")] = '\0';
	strcat(filename,".txt");
	fflush(stdin);

    if (strstr(filename, "Users") != NULL)  // Open file for reading and import data
	{
        fp = fopen(filename, "r");
        if (fp == NULL) 
		{
            printf("Error opening file.\n");
            return;
        }
		while (!feof(fp)) 
		{
			if (fgets(line, MAX_STRINGLEN, fp) != NULL) 
			{
				// check if lineNum is a multiple of 9
				if (lineNum % 9 == 1) 
				{
					// read userID and password
					sscanf(line, "%d %s", &tempUser[numUsers].userID, tempUser[numUsers].password);
					fflush(stdin);
				} else if (lineNum%9 == 2) 
				{
					// read fullName
					sscanf(line, "%[^\n]", tempUser[numUsers].fullName);
					fflush(stdin);
				} else if (lineNum%9 == 3) 
				{
					// read address
					sscanf(line, "%[^\n]", tempUser[numUsers].address);
					fflush(stdin);
				} else if (lineNum%9 == 4) 
				{
					// read contact
					sscanf(line, "%I64u", &tempUser[numUsers].contact);
					fflush(stdin);
				} else if (lineNum%9 == 5) 
				{
					// read sex
					sscanf(line, "%[^\n]", tempUser[numUsers].sex);
					fflush(stdin);
				} else if ((lineNum%9 == 6))
				{
					sscanf(line, "%s %s %[^\n]", tempUser[numUsers].string[2], tempUser[numUsers].string[0], tempUser[numUsers].string[1]);
					fflush(stdin);
				}
				else if ((lineNum%9 == 7))
				{
					sscanf(line, "%s %s %[^\n]", tempUser[numUsers].string[5], tempUser[numUsers].string[3], tempUser[numUsers].string[4]);
					fflush(stdin);
				}
				else if ((lineNum%9 == 8))
				{
					sscanf(line, "%s %s %[^\n]", tempUser[numUsers].string[8], tempUser[numUsers].string[6], tempUser[numUsers].string[7]);
					fflush(stdin);
				}
				// check if this is the last string for this user, then increment numUsers
				else if (lineNum%9 == 0) 
				{
					displayHeader(); 
					// This block of code prints the information of the user registration entry using printf and fprintf functions.
					printf("\n\n\t\t\t\t\t\t\t\t\t\tE N T R Y # %d:", ctr);
					fprintf(stdout, "\n\n\t\t\t\t\t\t\t\t\t\t%d %s\n\t\t\t\t\t\t\t\t\t\t%s\n\t\t\t\t\t\t\t\t\t\t%s\n\t\t\t\t\t\t\t\t\t\t%011lld\n\t\t\t\t\t\t\t\t\t\t%s\n\t\t\t\t\t\t\t\t\t\t%s %s %s\n\t\t\t\t\t\t\t\t\t\t%s %s %s\n\t\t\t\t\t\t\t\t\t\t%s %s %s\n", 
					tempUser[numUsers].userID, tempUser[numUsers].password, tempUser[numUsers].fullName, tempUser[numUsers].address, tempUser[numUsers].contact, tempUser[numUsers].sex,
					tempUser[numUsers].string[2], tempUser[numUsers].string[0],tempUser[numUsers].string[1], tempUser[numUsers].string[5], tempUser[numUsers].string[3], 
					tempUser[numUsers].string[4], tempUser[numUsers].string[8], tempUser[numUsers].string[6], tempUser[numUsers].string[7]);
					
					// It then asks the user whether they want to add the entry to the list
					printf("\n\t\t\t\t\t\t\t\tDo you want to add this entry to the list? (y/n):");
					scanf(" %c", &answer);
					
					// If the answer is 'y' or 'Y', it copies the information of the entry to the userRegistrant array 
					// and increments the numUsers and count variables.
					if (answer == 'y' || answer == 'Y') 
					{
						idx1 = (*i)+1;
						getch();
    					userRegistrant[idx1].userID = tempUser[numUsers].userID;
						strcpy(userRegistrant[idx1].password, tempUser[numUsers].password);
						strcpy(userRegistrant[idx1].fullName, tempUser[numUsers].fullName);
						strcpy(userRegistrant[idx1].address, tempUser[numUsers].address);
						userRegistrant[idx1].contact = tempUser[numUsers].contact;
						strcpy(userRegistrant[idx1].sex, tempUser[numUsers].sex);
						strcpy(userRegistrant[idx1].string[0], tempUser[numUsers].string[0]);
						strcpy(userRegistrant[idx1].string[1], tempUser[numUsers].string[1]);
						strcpy(userRegistrant[idx1].string[2], tempUser[numUsers].string[2]);
						strcpy(userRegistrant[idx1].string[3], tempUser[numUsers].string[3]);
						strcpy(userRegistrant[idx1].string[4], tempUser[numUsers].string[4]);
						strcpy(userRegistrant[idx1].string[5], tempUser[numUsers].string[5]);
						strcpy(userRegistrant[idx1].string[6], tempUser[numUsers].string[6]);
						strcpy(userRegistrant[idx1].string[7], tempUser[numUsers].string[7]);
						strcpy(userRegistrant[idx1].string[8], tempUser[numUsers].string[8]);
						getch();
						numUsers++;
						count++;
						(*i)++;
						
					}ctr++;
				}lineNum++;
			}
			system("cls");
		}fclose(fp);
	}
	// Check if the file name contains "Appointment"
	if (strstr(filename, "Appointment") != NULL) 
	{
		
		FILE *fp = fopen(filename, "r"); // Open the file for reading
		if (fp == NULL) // Check if file exists or can be opened
		{
			printf("Error opening file.\n");
			return;
		}
		memset(&tempAppt[numAppt], 0, sizeof(tempAppt[numAppt]));

		// Read the file line by line
		while (!feof(fp)) 
		{
			// Check if line can be read successfully
			if (fgets(line, MAX_STRINGLEN, fp) != NULL) 
			{
				
				if(lineNum%8 == 1)
				{
					sscanf(line, "%d %d", &tempAppt[numAppt].appID, &tempUser[numUsers].userID);
				
				}
				// read appID and userID
				else if (lineNum%8 == 2)
				{
					// read customerName
					sscanf(line, "%[^\n]", tempAppt[numAppt].customerName);
					
				}
				else if (lineNum%8 == 6)
				{
					// read string3
					
					strncpy(tempAppt[numAppt].time, line, sizeof(tempAppt[numAppt].time) - 1);
					tempAppt[numAppt].time[sizeof(tempAppt[numAppt].time) - 1] = '\0';
					
				}
				else if (lineNum%8 == 3)
				{
					// read string0
					sscanf(line, "%[^\n]", tempAppt[numAppt].string[0]);
					

				}
				else if (lineNum%8 == 4)
				{
					// read string1
					sscanf(line, "%s", tempAppt[numAppt].string[1]);
					
				
				}
				else if (lineNum%8 == 5)
				{
					// read string2
					sscanf(line, "%s", tempAppt[numAppt].string[2]);
					
				}		
				else if (lineNum%8 == 7)
				{
					// read time
					sscanf(line, "%s", tempAppt[numAppt].string[3]);
					tempAppt[numAppt].string[3][strlen(tempAppt[numAppt].string[3])] = '\0';
					
				}
				// Read time and display the entry	
				else if (lineNum%8 == 0)
				{
					displayHeader(); 
					// Ask user if they want to add the entry to the list
					printf("\n\n\t\t\t\t\t\t\t\t\t\tE N T R Y # %d:", ctr);
					
					printf("\n\n\t\t\t\t\t\t\t\t\t\t%d %d\n\t\t\t\t\t\t\t\t\t\t%s\n\t\t\t\t\t\t\t\t\t\t%s\n\t\t\t\t\t\t\t\t\t\t%s\n\t\t\t\t\t\t\t\t\t\t%s\n\t\t\t\t\t\t\t\t\t\t%s\n\t\t\t\t\t\t\t\t\t\t%s\n\n", tempAppt[numAppt].appID, tempUser[numUsers].userID, tempAppt[numAppt].customerName, tempAppt[numAppt].string[0], tempAppt[numAppt].string[1], tempAppt[numAppt].string[2], tempAppt[numAppt].time, tempAppt[numAppt].string[3]);
					
					printf("\n\t\t\t\t\t\t\tDo you want to add this entry to the list? (y/n):");
					scanf(" %c", &answer);
					getch();

					// If yes, add the entry to the list and increment counters
					if (answer == 'y' || answer == 'Y')
					{
						idx2 = (*j)+1;
						idx_2 = (*i)+1;
						userAppointment[idx2].appID = tempAppt[numAppt].appID;
						userRegistrant[idx_2].userID = tempUser[numUsers].userID;
						strcpy(userAppointment[idx2].customerName, tempAppt[numAppt].customerName);
						strcpy(userAppointment[idx2].string[0], tempAppt[numAppt].string[0]);
						strcpy(userAppointment[idx2].string[1], tempAppt[numAppt].string[1]);
						strcpy(userAppointment[idx2].string[2], tempAppt[numAppt].string[2]);
						strcpy(userAppointment[idx2].string[3], tempAppt[numAppt].string[3]);
						strcpy(userAppointment[idx2].time, tempAppt[numAppt].time);
						numAppt++;
						numUsers++;
						count++;
						(*j)++;
						(*i)++;	
					}ctr++;				
				}lineNum++;
				
			}system("cls");
			fflush(stdin);
		}fclose(fp);
    } 
	// Open the file with the specified filename
	if (strstr(filename, "Chatbot") != NULL) 
	{
		// Try to open the file
		fp = fopen(filename, "r");
		// If the file doesn't exist, print an error message and return
		if (fp == NULL)
		{
			printf("\n\t\t\t\t\t\t\tERROR: File Does Not Exist.\n");
			return;
		}
		// Read each line in the file
		while (!feof(fp))
		{
			if (fgets(line, MAX_STRINGLEN, fp) != NULL)
			{
				// If the line number is divisible by 3 with a remainder of 1
				if (lineNum%3 == 1)
				{
					// Get the question and store it in the temporary QNA structure
					fflush(stdin);
					sscanf(line, "%[^\n]", tempQNA[numQNA].questions);
				}
				// If the line number is divisible by 3 with a remainder of 2
				if (lineNum%3 == 2)
				{
					// Get the answer and store it in the temporary QNA structure
					fflush(stdin);
					sscanf(line, "%[^\n]", tempQNA[numQNA].answers);
				}
				// If the line number is divisible by 3 with a remainder of 0
				if (lineNum%3 == 0)
				{
					displayHeader(); 
					// Print the entry number, question, and answer
					printf("\n\n\t\t\t\t\t\t\t\t\t\tE N T R Y # %d:", ctr);
					fprintf(stdout, "\n\n\t\t\t\t\t\t\t%s\n\t\t\t\t\t\t\t%s\n", tempQNA[numQNA].questions, tempQNA[numQNA].answers);
					
					// Ask the user if they want to add the entry to the list
					printf("\n\n\t\t\t\t\t\t\t\tDo you want to add this entry to the list? (y/n):");
					scanf(" %c", &answer);

					// If the user answers "y" or "Y"
					if (answer == 'y' || answer == 'Y')
					{
						idx3 = (*k)+1;
						strcpy(FAQ[idx3].questions, tempQNA[numQNA].questions);
						strcpy(FAQ[idx3].answers, tempQNA[numQNA].answers);
						numQNA++;
						count++;
						(*k)++;
					}ctr++;
				}lineNum++;
			}system("cls");
		}fclose(fp);
	}
	// Free the memory allocated for the temporary structures
	free(tempUser);
	free(tempAppt);
	free(tempQNA);

	// Print a message indicating that the data was imported successfully and wait for a key press
	displayHeader();
	printf("\n\n\t\t\t\t\t\t\t\tSuccessfully Imported Data from %s", filename);
	getch();
	return;
}

int main()
{ 
	int  i=0; //@i: Record Number for Vaccine Registration
	int j=0; //@j: Record Number for Appointment Requests
	int k= 0;
	wprintf(L"%lc\n", 0x2713);
	struct User* userRegistrant = calloc(100, sizeof(struct User));
	struct Appointment* userAppointment = calloc(100, sizeof(struct Appointment));
	struct Chatbot* FAQ = calloc(100, sizeof(struct Chatbot));

	displayMain(userRegistrant,userAppointment, FAQ, &i, &j, &k);	
	return 0;
}
