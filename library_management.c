#include <stdio.h>
#include <string.h>
#include "library_management.h"

void initLibrary(Library* library) {
    library->bookCount = 0;
    library->userCount = 0;
}

bool isValidBookId(int id) {
    return id > 0;
}

bool isValidUserId(int id) {
    return id > 0;
}

bool isValidName(const char* name) {
    return name != NULL && strlen(name) > 0;
}

bool isBookAvailable(const Book* book) {
    return book != NULL && book->bookstatus == AVAILABLE;
}

ErrorCode addBook(Library* library, int id, const char* title, const char* author) {
    if (!isValidBookId(id)) {
        return ERROR_INVALID_ID;
    }
    
    if (!isValidName(title) || !isValidName(author)) {
        return ERROR_INVALID_NAME;
    }
    
    if (library->bookCount >= MAX_BOOKS) {
        return ERROR_LIBRARY_FULL;
    }
    
    // Check if the ID already exists
    for (int i = 0; i < library->bookCount; i++) {
        if (library->books[i].id == id) {
            return ERROR_INVALID_ID;
        }
    }
    
    Book newBook;
    newBook.id = id;
    strncpy(newBook.title, title, MAX_TITLE_LENGTH - 1);
    newBook.title[MAX_TITLE_LENGTH - 1] = '\0';
    strncpy(newBook.author, author, MAX_AUTHOR_LENGTH - 1);
    newBook.author[MAX_AUTHOR_LENGTH - 1] = '\0';
    newBook.bookstatus = AVAILABLE;
    
    library->books[library->bookCount] = newBook;
    library->bookCount++;
    
    return SUCCESS;
}

ErrorCode removeBook(Library* library, int id) {
    if (!isValidBookId(id)) {
        return ERROR_INVALID_ID;
    }
    
    int bookIndex = -1;
    for (int i = 0; i < library->bookCount; i++) {
        if (library->books[i].id == id) {
            bookIndex = i;
            break;
        }
    }
    
    if (bookIndex == -1) {
        return ERROR_BOOK_NOT_FOUND;
    }
    
    // Move all books after this position up by one
    for (int i = bookIndex; i < library->bookCount - 1; i++) {
        library->books[i] = library->books[i + 1];
    }
    
    library->bookCount--;
    
    return SUCCESS;
}

Book* findBookById(Library* library, int id) {
    for (int i = 0; i < library->bookCount; i++) {
        if (library->books[i].id == id) {
            return &library->books[i];
        }
    }
    
    return NULL;
}

void listAllBooks(const Library* library) {
    printf("List of books in the library:\n");
    printf("%-5s %-30s %-20s %-10s\n", "ID", "Title", "Author", "bookStatus");
    printf("------------------------------------------------------------------\n");
    
    for (int i = 0; i < library->bookCount; i++) {
        const Book* book = &library->books[i];
        printf("%-5d %-30s %-20s %-10s\n", 
              book->id, 
              book->title, 
              book->author, 
              book->bookstatus == AVAILABLE ? "Available" : "Borrowed");
    }
}

ErrorCode addUser(Library* library, int id, const char* name) {
    if (!isValidUserId(id)) {
        return ERROR_INVALID_ID;
    }
    
    if (!isValidName(name)) {
        return ERROR_INVALID_NAME;
    }
    
    if (library->userCount >= MAX_USERS) {
        return ERROR_LIBRARY_FULL;
    }
    
    // Check if the ID already exists
    for (int i = 0; i < library->userCount; i++) {
        if (library->users[i].id == id) {
            return ERROR_INVALID_ID;
        }
    }
    
    User newUser;
    newUser.id = id;
    strncpy(newUser.name, name, MAX_TITLE_LENGTH - 1);
    newUser.name[MAX_TITLE_LENGTH - 1] = '\0';
    newUser.user_borrowedCount = 0;
    
    library->users[library->userCount] = newUser;
    library->userCount++;
    
    return SUCCESS;
}

ErrorCode removeUser(Library* library, int id) {
    if (!isValidUserId(id)) {
        return ERROR_INVALID_ID;
    }
    
    int userIndex = -1;
    for (int i = 0; i < library->userCount; i++) {
        if (library->users[i].id == id) {
            userIndex = i;
            break;
        }
    }
    
    if (userIndex == -1) {
        return ERROR_USER_NOT_FOUND;
    }
    
    // Check if the user is currently borrowing any books
    if (library->users[userIndex].user_borrowedCount > 0) {
        return ERROR_BOOK_ALREADY_BORROWED;
    }
    
    // Move all users after this position up by one
    for (int i = userIndex; i < library->userCount - 1; i++) {
        library->users[i] = library->users[i + 1];
    }
    
    library->userCount--;
    
    return SUCCESS;
}

User* findUserById(Library* library, int id) {
    for (int i = 0; i < library->userCount; i++) {
        if (library->users[i].id == id) {
            return &library->users[i];
        }
    }
    
    return NULL;
}

void listAllUsers(const Library* library) {
    printf("List of users:\n");
    printf("%-5s %-30s %-15s\n", "ID", "Name", "Books Borrowed");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < library->userCount; i++) {
        const User* user = &library->users[i];
        printf("%-5d %-30s %-15d\n", 
              user->id, 
              user->name, 
              user->user_borrowedCount);
    }
}

ErrorCode borrowBook(Library* library, int userId, int bookId) {
    User* user = findUserById(library, userId);
    if (user == NULL) {
        return ERROR_USER_NOT_FOUND;
    }
    
    Book* book = findBookById(library, bookId);
    if (book == NULL) {
        return ERROR_BOOK_NOT_FOUND;
    }
    
    if (!isBookAvailable(book)) {
        return ERROR_BOOK_ALREADY_BORROWED;
    }

    user->borrowedBooks[user->user_borrowedCount] = bookId;
    user->user_borrowedCount++;

    book->bookstatus = BORROWED;

    return SUCCESS;
}

ErrorCode returnBook(Library* library, int userId, int bookId) {
    User* user = findUserById(library, userId);
    if (user == NULL) {
        return ERROR_USER_NOT_FOUND;
    }
    
    Book* book = findBookById(library, bookId);
    if (book == NULL) {
        return ERROR_BOOK_NOT_FOUND;
    }

    int bookIndex = -1;
    for (int i = 0; i < user->user_borrowedCount; i++) {
        if (user->borrowedBooks[i] == bookId) {
            bookIndex = i;
            break;
        }
    }
    
    if (bookIndex == -1) {
        return ERROR_BOOK_NOT_BORROWED;
    }

    for (int i = bookIndex; i < user->user_borrowedCount - 1; i++) {
        user->borrowedBooks[i] = user->user_borrowedCount[ i + 1];
    }
    user->user_borrowedCount--;
    
    // Update book status
    book->bookstatus = AVAILABLE;
    
    return SUCCESS;
}

void listBorrowedBooks(const Library* library, int userId) {
    const User* user = NULL;
    for (int i = 0; i < library->userCount; i++) {
        if (library->users[i].id == userId) {
            user = &library->users[i];
            break;
        }
    }
    
    if (user == NULL) {
        printf("User not found with ID: %d\n", userId);
        return;
    }
    
    printf("Books borrowed by user %s (ID: %d):\n", user->name, user->id);
    printf("%-5s %-30s %-20s\n", "ID", "Title", "Author");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < user->user_borrowedCount; i++) {
        int bookId = user->borrowedBooks[i];
        const Book* book = NULL;
        
        for (int j = 0; j < library->bookCount; j++) {
            if (library->books[j].id == bookId) {
                book = &library->books[j];
                break;
            }
        }
        
        if (book != NULL) {
            printf("%-5d %-30s %-20s\n", 
                  book->id, 
                  book->title, 
                  book->author);
        }
    }
}

const char* getErrorMessage(ErrorCode code) {
    switch (code) {
        case SUCCESS: 
            return "Success";
        case ERROR_INVALID_ID: 
            return "Invalid ID";
        case ERROR_INVALID_NAME: 
            return "Invalid name";
        case ERROR_LIBRARY_FULL: 
            return "Library is full";
        case ERROR_BOOK_NOT_FOUND: 
            return "Book not found";
        case ERROR_USER_NOT_FOUND: 
            return "User not found";
        case ERROR_BOOK_ALREADY_BORROWED: 
            return "Book already borrowed";
        case ERROR_BOOK_NOT_BORROWED: 
            return "Book not borrowed by this user";
        default: 
            return "Unknown error";
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library_management.h"

void printMenu() {
    printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
    printf("1. Add new book\n");
    printf("2. Remove book\n");
    printf("3. Display all books\n");
    printf("4. Add new user\n");
    printf("5. Remove user\n");
    printf("6. Display all users\n");
    printf("7. Borrow book\n");
    printf("8. Return book\n");
    printf("9. Display user's borrowed books\n");
    printf("0. Exit\n");
    printf("Your choice: ");
}

void handleAddBook(Library* library) {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    
    printf("Enter book ID: ");
    scanf("%d", &id);
    getchar(); // Read newline character
    
    printf("Enter book title: ");
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline character
    
    printf("Enter author name: ");
    fgets(author, MAX_AUTHOR_LENGTH, stdin);
    author[strcspn(author, "\n")] = 0; // Remove newline character
    
    ErrorCode result = addBook(library, id, title, author);
    
    if (result == SUCCESS) {
        printf("Book added successfully!\n");
    } else {
        printf("Error: %s\n", getErrorMessage(result));
    }
}

void handleRemoveBook(Library* library) {
    int id;
    
    printf("Enter book ID to remove: ");
    scanf("%d", &id);
    
    ErrorCode result = removeBook(library, id);
    
    if (result == SUCCESS) {
        printf("Book removed successfully!\n");
    } else {
        printf("Error: %s\n", getErrorMessage(result));
    }
}

void handleAddUser(Library* library) {
    int id;
    char name[MAX_TITLE_LENGTH];
    
    printf("Enter user ID: ");
    scanf("%d", &id);
    getchar(); // Read newline character
    
    printf("Enter user name: ");
    fgets(name, MAX_TITLE_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character
    
    ErrorCode result = addUser(library, id, name);
    
    if (result == SUCCESS) {
        printf("User added successfully!\n");
    } else {
        printf("Error: %s\n", getErrorMessage(result));
    }
}

void handleRemoveUser(Library* library) {
    int id;
    
    printf("Enter user ID to remove: ");
    scanf("%d", &id);
    
    ErrorCode result = removeUser(library, id);
    
    if (result == SUCCESS) {
        printf("User removed successfully!\n");
    } else {
        printf("Error: %s\n", getErrorMessage(result));
    }
}

void handleBorrowBook(Library* library) {
    int userId, bookId;
    
    printf("Enter user ID: ");
    scanf("%d", &userId);
    
    printf("Enter book ID to borrow: ");
    scanf("%d", &bookId);
    
    ErrorCode result = borrowBook(library, userId, bookId);
    
    if (result == SUCCESS) {
        printf("Book borrowed successfully!\n");
    } else {
        printf("Error: %s\n", getErrorMessage(result));
    }
}

void handleReturnBook(Library* library) {
    int userId, bookId;
    
    printf("Enter user ID: ");
    scanf("%d", &userId);
    
    printf("Enter book ID to return: ");
    scanf("%d", &bookId);
    
    ErrorCode result = returnBook(library, userId, bookId);
    
    if (result == SUCCESS) {
        printf("Book returned successfully!\n");
    } else {
        printf("Error: %s\n", getErrorMessage(result));
    }
}

void handleListBorrowedBooks(Library* library) {
    int userId;
    
    printf("Enter user ID: ");
    scanf("%d", &userId);
    
    listBorrowedBooks(library, userId);
}

int main() {
    Library library;
    initLibrary(&library);
    
    int choice;
    
    do {
        printMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                handleAddBook(&library);
                break;
            case 2:
                handleRemoveBook(&library);
                break;
            case 3:
                listAllBooks(&library);
                break;
            case 4:
                handleAddUser(&library);
                break;
            case 5:
                handleRemoveUser(&library);
                break;
            case 6:
                listAllUsers(&library);
                break;
            case 7:
                handleBorrowBook(&library);
                break;
            case 8:
                handleReturnBook(&library);
                break;
            case 9:
                handleListBorrowedBooks(&library);
                break;
            case 0:
                printf("Thank you for using the library management system!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}



