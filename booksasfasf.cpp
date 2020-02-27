#include "header.h"

class book{
	private:
		int bookId;
		string bookname;
		string author;
		double bookPrice;
	
	public:
		void print();
		
		book(){	}
		book(int id,string name,string author_name, double price){
			bookId = id;
			bookname = name;
			author = author_name;
			bookPrice = price;
		}
		int getid(){
			return bookId;
		}
		string gettitle()
		{
			return bookname;
		}
		string getauthorname()
		{
			return author;
		}
		double bookprices(){
			return bookPrice;
		}
		
};

class store{
	private:
		book* books;
		int bookCount;
	
	public:
		store(int size){
			books = new book[size];
			bookCount = size;
		}	
		void addbook(book bookname);
		void updatebook(book bookid);
		
		book* findbook(int id);
		book* findbook(string authorname);
};

void store::addbook(book bookname)
{
	for(int i=0;i<bookCount;i++)
	{
		if(books[i].gettitle()=="")
			books[i]=bookname;
		else 
		return;
	}
}

void store::updatebook(book bookid){
	for(int i=0 ; i<bookCount; i++)
	{
		if(books[i].getid()==bookid.getid())
			books[i] = bookid;
	}
}

book* store::findbook(int id){
	for(int i=0 ; i<bookCount; i++){
		
		if(books[i].getid()==id)
			return &books[i];
	}
}


book* store::findbook(string authorname){
	for(int i=0 ; i<bookCount; i++){
		if(books[i].getauthorname() == authorname)
			return &books[i];
	}
}

store* app;  //global object

string getMenu(){
	string menu ="~~~~~~~~~~Book Store app~~~~~~~~~~~\n";
	menu += "TO ADD NEW BOOK--------------->PRESS 1\n";
	menu += "TO FIND BOOK BY ID------------>PRESS 2\n";
	menu += "TO FIND BOOK By AUTHOR-------->PRESS 3\n";
	menu += "TO UPDATE BOOK---------------->PRESS 4\n";
	menu += "PS: PRESSING ANY KEY IS CONSIDERED AS EXIT\n";
	return menu;
}


void addBookOperation(){
	int id = getNumber("Enter the book ID");
	string name = getString("Enter the book name");
	string author = getString("Enter the Author");
	double price = getDouble("Enter the price");
	book bk(id, name, author, price);
	app->addbook(bk);
}
bool processMenu(int choice){
	switch(choice){
		case 1:
			addBookOperation();
			return true;
		case 2:					
		case 3:
		case 4:
			return true;
	}
	return false;
}

int main(){
	int size = getNumber("Please enter the no of books with ur store");
	app = new store(size);
	bool processing = true;
	do{
		string menu = getMenu();
		int choice = getNumber(menu);
		processing = processMenu(choice);
	}while(processing);
	
}
