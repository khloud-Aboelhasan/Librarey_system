#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;
struct Librarian
{
	string User_Name;
	string Password;
} L[4];
struct Date
{
	int Day;
	int Month;
	int Year;
};
struct User
{
	int Id;
	string Name;
	string Password;
	string Email;
	string Account_Type;
	Date Creation_Date;
	string Contact_Number;
}U[20];
struct Book
{
	string Title;
	int Production_Year;
	int Number_Of_Copy;
	string Category;
	int Eddition;
}B[70];
//**************************************************
int check_librarian(Librarian L[4])
{

	int temp = 0; //this variable used to check if librarian valied or not
	string User_Name;
	string Password;
	cout << "Enter your User_Name : \n";
	cin >> User_Name;
	cout << "Enter your Password  :\n";
	cin >> Password;

	for (int i = 0; i < 4; i++)
	{
		if (L[i].User_Name == User_Name && L[i].Password == Password)
		{
			temp = 1;
			break;
		}

	}
	if (temp == 0)
	{
		cout << "This Librarian not valied !! \n ";
	}
	else
	{
		cout << "This Librarian valied \n";
	}

	return temp;


}
//**************************************************
void Add_User(User U)
{
	int  temp = 0; //variable check  if user exist or not by returning value 1 if exist 0 if not
	User x; //this variable used to compare data of user enter by data stored in file (check user foud or not)
	cout << "Enter Id       : \n";
	cin >> x.Id;
	cout << "Enter Name     : \n ";
	cin >> x.Name;
	cout << "Enter Email    : \n";
	cin >> x.Email;
	cout << "Enter Password : \n";
	cin >> x.Password;
	cout << "Enter Account_type  :\n";
	cin >> x.Account_Type;
	cout << "Enter Creation_date :\n";
	cin >> x.Creation_Date.Day;
	cin >> x.Creation_Date.Month;
	cin >> x.Creation_Date.Year;
	cout << "Enter Contact_number : \n";
	cin >> x.Contact_Number;

	ofstream outfile;
	outfile.open("User.txt", ios::app);
	ifstream infile;
	infile.open("User.txt");
	infile >> U.Id;
	infile >> U.Name;
	infile >> U.Email;
	infile >> U.Password;
	infile >> U.Account_Type;
	infile >> U.Creation_Date.Day;
	infile >> U.Creation_Date.Month;
	infile >> U.Creation_Date.Year;
	infile >> U.Contact_Number;

	while (!infile.eof())
	{
		if (U.Name == x.Name)
		{
			temp = 1;
		}

		infile >> U.Id;
		infile >> U.Name;
		infile >> U.Email;
		infile >> U.Password;
		infile >> U.Account_Type;
		infile >> U.Creation_Date.Day >> U.Creation_Date.Month >> U.Creation_Date.Year;
		infile >> U.Contact_Number;

	}
	infile.close();
	if (temp == 1)
	{
		cout << "this User is found  !! \n";
	}
	else
	{
		outfile << x.Id << "\n";
		outfile << x.Name << "\n";
		outfile << x.Email << "\n";
		outfile << x.Password << "\n";
		outfile << x.Account_Type << "\n";
		outfile << x.Creation_Date.Day << "\n";
		outfile << x.Creation_Date.Month << "\n";
		outfile << x.Creation_Date.Year << "\n";
		outfile << x.Contact_Number << "\n";
		outfile.close();


	}
}
//**************************************************
int login_User(User U)
{

	int temp = 0; //variable used to check if user found or not
	int value = 0; // variable used to check about Account_type of user
	string Email;
	string Password;

	cout << "Enter your Email : \n";
	cin >> Email;
	cout << "Enter your Password  :\n";
	cin >> Password;


	ifstream uf;
	uf.open("User.txt");

	uf >> U.Id;
	uf >> U.Name;
	uf >> U.Email;
	uf >> U.Password;
	uf >> U.Account_Type;
	uf >> U.Creation_Date.Day;
	uf >> U.Creation_Date.Month;
	uf >> U.Creation_Date.Year;
	uf >> U.Contact_Number;



	while (!uf.eof())
	{
		if (U.Email == Email && U.Password == Password)
		{

			temp = 1;
			if (U.Account_Type == "student")
			{
				value = 1;
			}
			else if (U.Account_Type == "staff")
			{
				value = 2;
			}
			else
			{
				value = 3;
			}


		}


		uf >> U.Id;
		uf >> U.Name;
		uf >> U.Email;
		uf >> U.Password;
		uf >> U.Account_Type;
		uf >> U.Creation_Date.Day;
		uf >> U.Creation_Date.Month;
		uf >> U.Creation_Date.Year;
		uf >> U.Contact_Number;




	}

	uf.close();
	if (temp == 0)
	{//clean code
		cout << "This User not valied \n ";
	}
	else
	{
		cout << "This User valied \n";
	}

	return value;


}
//**************************************************
void search_Book(Book B, string Title, int Production_Year)
{
	int tempps = 0; //variable used to check if book found or not

	ofstream outfille;
	outfille.open("Book.txt", ios::app);

	outfille.close();

	ifstream bf;
	bf.open("Book.txt");
	bf >> B.Title;
	bf >> B.Production_Year;
	bf >> B.Number_Of_Copy;
	bf >> B.Category;
	bf >> B.Eddition;




	while (!bf.eof())
	{
		if (B.Title == Title || B.Production_Year == Production_Year) //condition used for user can search by title or production year of book
		{

			cout << "Title     : " << B.Title << endl;
			cout << "Production_year  : " << B.Production_Year << endl;
			cout << "Number_of_copy   : " << B.Number_Of_Copy << endl;
			cout << "Category   : " << B.Category << endl;
			cout << "Eddition  : " << B.Eddition << endl;


			tempps = 1;
		}



		bf >> B.Title;
		bf >> B.Production_Year;
		bf >> B.Number_Of_Copy;
		bf >> B.Category;
		bf >> B.Eddition;


	}

	bf.close();
	if (tempps == 0)
	{
		cout << "This Book not found " << endl;
	}
}
//*************************************************
void add_Book(Book B)//clean code
{
	int  temps = 0; //variable used to check about the book found or not befor adding
	Book y;
	cout << "Enter Title   : \n";
	cin >> y.Title;
	cout << "Enter Production_Year  : \n ";
	cin >> y.Production_Year;
	cout << "Enter Number_Of_Copy : \n";
	cin >> y.Number_Of_Copy;
	cout << "Enter Category  : \n";
	cin >> y.Category;
	cout << "Enter Edition    : \n";
	cin >> y.Eddition;


	ofstream outfille;
	outfille.open("Book.txt", ios::app);
	ifstream infille;
	infille.open("Book.txt");
	infille >> B.Title;
	infille >> B.Production_Year;
	infille >> B.Number_Of_Copy;
	infille >> B.Category;
	infille >> B.Eddition;



	while (!infille.eof())
	{
		if (B.Title == y.Title)
		{
			temps = 1;
		}

		infille >> B.Title;
		infille >> B.Production_Year;
		infille >> B.Number_Of_Copy;
		infille >> B.Category;
		infille >> B.Eddition;


	}
	infille.close();
	if (temps == 1)
	{
		cout << "this Book is found   \n";
	}
	else
	{
		outfille << y.Title << "\n";
		outfille << y.Production_Year << "\n";
		outfille << y.Number_Of_Copy << "\n";
		outfille << y.Category << "\n";
		outfille << y.Eddition << "\n";

		outfille.close();



	}
}
//*************************************************
void buy_Book(Book B, string Title)
{



	ifstream bf;
	bf.open("Book.txt");
	ofstream ee;
	ee.open("new_b.txt"); //this new file used to store new data of book After updating in nuber_of_copy of book

	bf >> B.Title;
	bf >> B.Production_Year;
	bf >> B.Number_Of_Copy;
	bf >> B.Category;
	bf >> B.Eddition;



	while (!bf.eof())
	{
		if (B.Title != Title)
		{

			ee << B.Title << endl;
			ee << B.Production_Year << endl;
			ee << B.Number_Of_Copy << endl;
			ee << B.Category << endl;
			ee << B.Eddition << endl;



		}
		else
		{
			if (B.Number_Of_Copy > 1) //condition used to check if The library has more than one copy before selling
			{
				cout << "Your purchase has been successfully: \n ";
				ee << B.Title << endl;
				ee << B.Production_Year << endl;
				ee << B.Number_Of_Copy - 1 << endl;
				ee << B.Category << endl;
				ee << B.Eddition << endl;
			}
			else
			{
				cout << "sorry there is one copy from this book !! " << endl;
				ee << B.Title << endl;
				ee << B.Production_Year << endl;
				ee << B.Number_Of_Copy << endl;
				ee << B.Category << endl;
				ee << B.Eddition << endl;
			}



		}


		bf >> B.Title;
		bf >> B.Production_Year;
		bf >> B.Number_Of_Copy;
		bf >> B.Category;
		bf >> B.Eddition;


	}

	bf.close();
	ee.close();
	remove("Book.txt");
	rename("new_b.txt", "Book.txt"); //clean code





}
//*************************************************
void Report_User(User U)
{
	int	day[7]; // search in only one week
	int month[7]; // search in only one week
	int year[7]; // search in only one week
	int temp = 0; //this value use to test if  user enter or no before week

	time_t currenttime = time(0);
	tm* ltime = localtime(&currenttime);
	int Day = ltime->tm_mday;
	int Month = ltime->tm_mon + 1;
	int Year = ltime->tm_year + 1900;
	cout << "Date is : " << Day << "/" << Month << "/" << Year << endl;

	for (int i = 0; i <= 6; i++)
	{
		if (Day - i > 0 && Month <= 12)
		{
			day[i] = Day - i;
			month[i] = Month;
			year[i] = Year;

		}
		else if (Day - i <= 0 && 1 < Month && Month <= 12)
		{
			day[i] = (Day - i) + 30;
			month[i] = Month - 1;
			year[i] = Year;
		}
		else if (Day - i <= 0 && Month == 1)
		{
			day[i] = (Day - i) + 30;
			month[i] = 12;
			year[i] = Year - 1;;
		}


	}


	ifstream uf;
	uf.open("User.txt");
	uf >> U.Id;
	uf >> U.Name;
	uf >> U.Email;
	uf >> U.Password;
	uf >> U.Account_Type;
	uf >> U.Creation_Date.Day;
	uf >> U.Creation_Date.Month;
	uf >> U.Creation_Date.Year;
	uf >> U.Contact_Number;
	while (!uf.eof())
	{
		for (int i = 0; i <= 6; i++)
		{
			if (U.Creation_Date.Day == day[i] && U.Creation_Date.Month == month[i] && U.Creation_Date.Year == year[i])
			{
				cout << "====================================================" << endl;
				cout << U.Id << endl;
				cout << U.Name << endl;
				cout << U.Email << endl;
				cout << U.Password << endl;
				cout << U.Account_Type << endl;
				cout << U.Creation_Date.Day << endl;
				cout << U.Creation_Date.Month << endl;
				cout << U.Creation_Date.Year << endl;
				cout << U.Contact_Number << endl;
				temp = 1;
			}

		}

		uf >> U.Id;
		uf >> U.Name;
		uf >> U.Email;
		uf >> U.Password;
		uf >> U.Account_Type;
		uf >> U.Creation_Date.Day;
		uf >> U.Creation_Date.Month;
		uf >> U.Creation_Date.Year;
		uf >> U.Contact_Number;
	}

	uf.close();
	if (temp == 0)
	{
		cout << "there is no User enter the system before week " << endl;
	}
}
//*************************************************
void main()
{
	Librarian L[4];
	L[0].User_Name = "l1";
	L[0].Password = "#1";
	L[1].User_Name = "l2";
	L[1].Password = "#2";
	L[2].User_Name = "l3";
	L[2].Password = "#3";
	L[3].User_Name = "l4";
	L[3].Password = "#4";

	int type;
	int check;
	int Option;
	int choise;
	char x;
	string Title;
	int Production_Year;
	User U;
	Book B;

	while (true)
	{
		cout << "Pleas Enter your Option : (1/Librarian - 2/User)" << endl;
		cin >> Option;
		switch (Option)
		{
		case 1:
		{
			check = check_librarian(L);
			if (check == 1)
			{
				do
				{
					cout << "Pleas Enter your chiose : (1/Add user - 2/add book - 3/search Book - 4/Report )" << endl;
					cin >> choise;
					switch (choise)
					{
					case 1:
					{
						Add_User(U);

						break;
					}
					case 2:
					{
						add_Book(B);
						break;

					}
					case 3:
					{
						cout << "Enter Title of book \n";
						cin >> Title;
						cout << "Enter Production year of book \n";
						cin >> Production_Year;
						search_Book(B, Title, Production_Year);
						break;
					}
					case 4:
					{
						Report_User(U);
					}

					}

					cout << "Do you want to back to this case again ? y/n" << endl;
					cin >> x;
				}

				while (x == 'y');
			}

			break;

		}
		case 2:
		{
			type = login_User(U);
			if (type == 1)
			{
				cout << "This is student \n";
				cout << "Enter your choise (1/search_book - 2/Exite): \n";
				cin >> choise;
				switch (choise)
				{
				case 1:
				{
					cout << "Enter title: \n ";
					cin >> Title;
					cout << "Enter Production year \n";
					cin >> Production_Year;
					search_Book(B, Title, Production_Year);
					break;
				}
				case 2:
				{
					break;
				}
				}
			}
			else if (type == 2)
			{
				cout << "This is staff \n";
				cout << "Enter your choise (1/search_book - 2/buy_Book - 3/Exite): \n";
				cin >> choise;
				switch (choise)
				{
				case 1:
				{
					cout << "Enter title: \n ";
					cin >> Title;
					cout << "Enter Production year \n";
					cin >> Production_Year;
					search_Book(B, Title, Production_Year);
					break;
				}
				case 2:
				{
					cout << "Enter your Title \n";
					cin >> Title;
					buy_Book(B, Title); //only staff can buy book
					break;
				}
				case 3:
				{
					break;
				}
				}
			}
			else if (type == 3)
			{
				cout << "This is guest \n ";
				cout << "Enter your choise (1/search_book - 2/Exite): \n";
				cin >> choise;
				switch (choise)
				{
				case 1:
				{
					cout << "Enter title: \n ";
					cin >> Title;
					cout << "Enter Production year \n";
					cin >> Production_Year;
					search_Book(B, Title, Production_Year);
					break;
				}
				case 2:
				{
					break;
				}
				}
			}
			break;
		}

		}
	}
}