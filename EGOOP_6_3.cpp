//Change the code in main to have dynamic allocation of object memory in order to have new books
//Change the data members to private and make search_book a member of class books
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class books
{
private:
	static int count;  //to keep the count of no of different books 	

	char *name;  //Name of the book_name
	char *author;  //Name of the author
	int price;
	char *publisher;
	int stock;
	
public:
	//ADD CONSTRUCTORS
	books(){ }
	books(char *n, char *b, int p, char *pub, int st); //should include memory allocation
	
	//PUBLIC FUNCTIONS
	int search_book(char *title, char *author);  
	void display_details(void);  //should it books * or books &; this will be used in search_books
	void no_of_copies_and_transact(void); 
	void update_price(void);
};

int books :: count;

books :: books(char *n, char *b, int p, char *pub, int st)
{
	name = new char[30];
	author = new char[30];
	publisher = new char[30];
	strcpy(name, n);
	strcpy(author, b);
	price = p;
	strcpy(publisher, pub);
	stock = st;
}

void books :: display_details(void)
{
	cout << "Book Name  : " << name << endl;
	cout << "Author Name: " << author << endl;
	cout << "Price      : " << price << endl;
	cout << "Publisher  : " << publisher << endl;
}

void books :: no_of_copies_and_transact(void)
{
	int numb, i = 0;
	cout << "Please enter the no. of copies required: ";
	cin >> numb;
	if(numb <= stock)
	{
		cout << "The total cost of the books: " << (price * numb) << "\n";
		cout << "Press 1 to go ahead with the transaction: ";
		cin >> i;
		if(i == 1)
			stock -= numb;
	}
	else
		cout << "Required no. of copies not available" << "\n\n";
}

int books :: search_book(char* title, char* author_name)
{
	int i;
	int flag = 0;
	if((!strcmp(title, name)) && (!strcmp(author_name, author)))
	{
		flag = 1;
		return flag;
		//display_details();
		//no_of_copies();
	}
	return flag;
}

void books :: update_price(void)
{
	int new_price;
	cout << "Please enter the new price: ";
	cin >> new_price;
	price = new_price;
}

void search_and_buy_books(char* title, char* author_name, vector<books> & bV)
{
	int i;
	int ret = 0;
	for(i = 0;i < bV.size();i++)
	{
		ret = bV[i].search_book(title, author_name);
		if(ret)
		{
			bV[i].display_details();
			bV[i].no_of_copies_and_transact();
			break;
		}
	}
	if(!ret)
		cout << "The book is not available\n\n";
}

void update_prices(char* title, char* author_name, vector<books> & bV)
{
	int i;
	int ret = 0;
	for(i = 0;i < bV.size();i++)
	{
		ret = bV[i].search_book(title, author_name);
		if(ret)
		{
			bV[i].update_price();
			break;
		}
	}
	if(!ret)
		cout << "Please enter the correct book name\n\n"; 
}

int main()
{
	int i = 9;
	vector<books> booksVector;
	books book0("Ashu0", "auth0", 100, "pub", 100);
	books book1("Ashu1", "auth1", 200, "pub", 90);
	books book2("Ashu2", "auth2", 300, "pub", 80);
	books book3("Ashu3", "auth3", 400, "pub", 70);
	books book4("Ashu4", "auth4", 500, "pub", 60);
	books book5("Ashu5", "auth5", 600, "pub", 50);
	books book6("Ashu6", "auth6", 700, "pub", 40);
	books book7("Ashu7", "auth7", 800, "pub", 30);
	books book8("Ashu8", "auth8", 900, "pub", 20);
	books book9("Ashu9", "auth9", 1000, "pub", 10);
	
	booksVector.push_back(book0);
	booksVector.push_back(book1);
	booksVector.push_back(book2);
	booksVector.push_back(book3);
	booksVector.push_back(book4);
	booksVector.push_back(book5);
	booksVector.push_back(book6);
	booksVector.push_back(book7);
	booksVector.push_back(book8);
	booksVector.push_back(book9);
	
	while(i)
	{
		cout << "0. To exit" << endl;
		cout << "1. Buy a book: " << endl;
		cout << "2. Update a price: " << endl;
		cout << "Please choose one of the options: ";
		cin >> i;
		
		char in_title[30], in_author[30];
		cout << "Please enter the title of the book: ";
		cin >> in_title;
		cout << "Please enter the author of the book: ";	
		cin >> in_author;
		switch(i)
		{
			case 1:
				search_and_buy_books(in_title,in_author, booksVector);
				break;
			case 2:
				update_prices(in_title, in_author, booksVector);
				break;	
		}
	}
	return 0;
}


		
	
