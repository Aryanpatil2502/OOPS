#include<iostream>
#include<string>
using namespace std;

class Publication
{
	string title;
	float price;
	public:
		void add()
		{
			cout << "\nEnter the Publication Information:" << endl;
			cout << "Enter Title of the Publication: ";
			cin.ignore();
			getline(cin, title);
			cout << "Enter Price of Publication: ";
			cin >> price;
		}
		
		void display()
		{
			cout << "\nTitle of Publication: " << title;
			cout << "\nPrice : " << price;
		}
};

class Book : public Publication
{
	int pages;
	public:
		void addBook()
		{
			try
			{
				add();
				cout << "Enter Pages of Book : ";
				cin >> pages;
				if (pages <= 0)
					throw pages;
					
			}catch(int invadipages)
			{
				cout << "\nInvalid Pages " << pages << " !!" ;
				pages = 0;
			}
		}
		
		void display_book()
		{
			display();
			cout << "\nPages : " << pages;
			cout << "\n--------------------------------------------------------\n";
			
		}
};

class tape : public Publication
{
	float mins;
	public:
		void add_tape()
		{
			try
			{
				
			add();
			cout << "Enter Play Duration of the Tape (mins) : ";
			cin >> mins;
			if (mins <=0 )
				throw mins;
		}catch (float mins)
		{
			cout << "\nInvalid Play Time " << mins << " !! ";
			mins =0;
			
		}
			
		}
		
		void display_tape()
		{
			display();
			cout << "\nPlay Time : " << mins << "mins";
			cout << "\n-------------------------------------------------------\n";
			
		}
};

int main()
{
	Book b[10];
	tape t[10];
	int ch, books=0, tapes=0;
	
	do
	{
		cout << "\nPublication database\n";
		cout << "1. Add Book\n";
		cout << "2. Add Tape\n";
		cout << "3. Display Books\n";
		cout << "4. Display Tapes\n";
		cout << "5. Exit.\n";
		cout << "Enter your choice : ";
		cin >> ch;
		
		switch (ch)
		{
			case 1:
				if(books < 10)
				{
					b[books].addBook();
					books++;
				}
				else{
					cout << "\n Book data base full";
				}
				break;
			case 2:{
				if(tapes < 10 )
				{
					t[tapes].add_tape();
					tapes++;
				}
				else{
					cout << "\nTapes Database Full";
				}
				break;
			}
			case 3:{
				if(books>0)
				{
					for (int i=0;i<books;i++)
					{
						b[i].display_book();
					}
				}
				else{
					cout << "\nNo Books";
				}
				break;
			}
			case 4:{
				if (tapes >0)
				{
					for (int i=0;i<tapes;i++)
					{
						t[i].display_tape();
					}
				}else
				{
					cout << "\nNo tapes";
				}
				break;
			}
			case 5:
				break;
		}
	}while( ch != 5);
	
	return 0;
}
