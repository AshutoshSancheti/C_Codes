//Change the code in main to have dynamic allocation of object memory in order to have new books
//Change the data memeber to private and make search_book a member of class books
#include <iostream>
#include <cstring>

using namespace std;

class books
{
	static int count;  //to keep the count of no of different books 	
public:
	char *name;  //Name of the book_name
	char *author;  //Name of the author
	int price;
	char *publisher;
	int stock;
	//ADD CONSTRUCTORS
	books(){ }
	books(char *n, char *b, int p, char *pub, int st); //should include memory allocation
	
	//void search_book(char *title, char *author, );  //should it books * or books &
	void display_details(void);  //should it books * or books &; this will be used in search_books
	void no_of_copies(void); 
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

void books :: no_of_copies(void)
{
	int numb;
	cout << "Please enter the no. of copies required: ";
	cin >> numb;
	if(numb <= stock)
		cout << "The total cost of the books: " << (price * numb) << endl;
	else
		cout << "Required no. of copies not available" << endl;
}

void search_book(char *title, char *author, books & b1);

int main()
{
	books book[10];
	int cost = 100;
	int sto = 100;
	char str1[] = "nameX";
	char str2[] = "authorX";
	char str3[] = "publishX";
	int i;
	for(i = 0;i<10;i++)
	{
		int j = i + 1;
		str1[4] = j + '0';
		str2[6] = j + '0';
		str3[7] = j + '0';
		book[i](str1, str2, cost, str3, sto);
		cost +=100;
		sto -=10;
	}
	char in_title[10], in_author[10];
	cout << "Please enter the title of the book: ";
	cin >> in_title;
	cout << "Please enter the author of the book: ";	
	cin >> in_author;
	
	search_book(char *title, char *author,books & b1);
	
	return 0;
}

void search_book(char *title, char *author,books & b1)
{
	int i;
	int flag = 0;
	for(i = 0;i < 10;i++)
	{
		if((!strcmp(title, b1.name)) && (!strcmp(author, b1.author)))
		{
			flag = 1;
			b1.display_details();
			b1.no_of_copies();
			break;
		}
	}
	if(flag == 0)
		cout << "Book not available" << endl;
}
	
