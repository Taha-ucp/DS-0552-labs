//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class LibraryItem {
//public:
//    virtual ~LibraryItem() = default;
//    virtual void display() const = 0;
//};
//
//
//class Book : public LibraryItem {
//private:
//    string title;
//    string author;
//    int pages;
//
//public:
//    Book() : pages(0) {}
//    Book(const string& t, const string& a, int p) : title(t), author(a), pages(p) {}
//
//    const string& getTitle() const { return title; }
//    int getPages() const { return pages; }
//
//    void display() const override {
//        cout << "Book Title: " << title << "\n"
//            << "Author: " << author << "\n"
//            << "Pages: " << pages << "\n";
//    }
//};
//
//// Newspaper class
//class Newspaper : public LibraryItem {
//private:
//    string name;
//    string date;
//    string edition;
//
//public:
//    Newspaper() = default;
//    Newspaper(const string& n, const string& d, const string& e) : name(n), date(d), edition(e) {}
//
//    const string& getName() const { return name; }
//    const string& getEdition() const { return edition; }
//
//    void display() const override {
//        cout << "Newspaper Name: " << name << "\n"
//            << "Date: " << date << "\n"
//            << "Edition: " << edition << "\n";
//    }
//};
//
//class Library {
//private:
//    static const int MaxBOOKS = 100;
//    static const int MaxNewspapers = 100;
//
//    Book books[MaxBOOKS];
//    int bookCount;
//
//    Newspaper newspapers[MaxNewspapers];
//    int newspaperCount;
//
//public:
//    Library() : bookCount(0), newspaperCount(0) {}
//
//    void addBook(const Book& b) {
//        if (bookCount < MaxBOOKS) {
//            books[bookCount++] = b;
//        }
//        else {
//            cout << "Book list is full!" << endl;
//        }
//    }
//
//    void addNewspaper(const Newspaper& n) {
//        if (newspaperCount < MaxNewspapers) {
//            newspapers[newspaperCount++] = n;
//        }
//        else {
//            cout << "Newspaper list is full!" << endl;
//        }
//    }
//
//    void displayCollection() const {
//        cout << "\n=== Books ===\n";
//        for (int i = 0; i < bookCount; i++) {
//            books[i].display();
//
//        }
//
//        cout << endl << "=== Newspapers ===" << endl;
//        for (int i = 0; i < newspaperCount; i++) {
//            newspapers[i].display();
//            cout << "              " << endl;
//        }
//    }
//
//    void sortBooksByPages() {
//        for (int i = 0; i < bookCount - 1; i++) {
//            for (int j = 0; j < bookCount - 1 - i; j++) {
//                if (books[j].getPages() > books[j + 1].getPages()) {
//                    Book temp = books[j];
//                    books[j] = books[j + 1];
//                    books[j + 1] = temp;
//                }
//            }
//        }
//    }
//
//    void sortNewspapersByEdition() {
//        for (int i = 0; i < newspaperCount - 1; i++) {
//            for (int j = 0; j < newspaperCount - 1 - i; j++) {
//                if (newspapers[j].getEdition() > newspapers[j + 1].getEdition()) {
//                    Newspaper temp = newspapers[j];
//                    newspapers[j] = newspapers[j + 1];
//                    newspapers[j + 1] = temp;
//                }
//            }
//        }
//    }
//
//    Book* searchBookByTitle(const string& title) {
//        for (int i = 0; i < bookCount; i++) {
//            if (books[i].getTitle() == title) {
//                return &books[i];
//            }
//        }
//        return nullptr;
//    }
//
//    Newspaper* searchNewspaperByName(const string& name) {
//        for (int i = 0; i < newspaperCount; i++) {
//            if (newspapers[i].getName() == name) {
//                return &newspapers[i];
//            }
//        }
//        return nullptr;
//    }
//};
//
//int main() {
//    // Create book objects
//    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
//    Book book2("To Kill a Mockingbird", "Harper Lee", 324);
//
//    // Create newspaper objects
//    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
//    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");
//
//    // library object
//    Library library;
//
//    // Add books and newspapers 
//    library.addBook(book1);
//    library.addBook(book2);
//    library.addNewspaper(newspaper1);
//    library.addNewspaper(newspaper2);
//
//    // Display the entire collection
//    cout << "Before Sorting:\n";
//    library.displayCollection();
//
//    // Sort books by pages and newspapers by edition
//    library.sortBooksByPages();
//    library.sortNewspapersByEdition();
//
//    cout << "\nAfter Sorting:\n";
//    library.displayCollection();
//
//    // Search for a book by title
//    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
//    if (foundBook) {
//        cout << "\nFound Book:\n";
//        foundBook->display();
//    }
//    else {
//        cout << "\nBook not found.\n";
//    }
//
//    // Search for a newspaper by name
//    Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
//    if (foundNewspaper) {
//        cout << endl << "Found Newspaper:" << endl;
//        foundNewspaper->display();
//    }
//    else {
//        cout << endl << "Newspaper not found." << endl;
//    }
//
//    return 0;
//}