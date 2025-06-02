#ifndef LIBRARY_MANAGEMENT_H
#define LIBRARY_MANAGEMENT_H

#include<stdbool.h>

#define MAX_USERS 100
#define MAX_BOOKS 1000
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

typedef enum {
    AVAILABLE,
    BORROWED
} BookStatus;

typedef enum {
    SUCCESS,
    ERROR_INVALID_ID,
    ERROR_INVALID_NAME,
    ERROR_LIBRARY_FULL,
    ERROR_BOOK_NOT_FOUND,
    ERROR_USER_NOT_FOUND,
    ERROR_BOOK_ALREADY_BORROWED,
    ERROR_BOOK_NOT_BORROWED
} ErrorCode;

typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    BookStatus bookstatus;
} Book;

typedef struct {
    int id;
    char name[MAX_TITLE_LENGTH];
    int borrowedBooks[MAX_BOOKS];
    int user_borrowedCount;
} User;

typedef struct {
    Book books[MAX_BOOKS];
    int bookCount;
    User users[MAX_USERS];
    int userCount;
} Library;

void initLibrary(Library* library);

bool isValidBookId(int id);
bool isValidUserId(int id);
bool isValidName(const char* name);
bool isBookAvailable(const Book* book);

ErrorCode addBook(Library* library, int id, const char* title, const char* author);
ErrorCode removeBook(Library* library, int id);
Book* findBookById(Library* library, int id);
void listAllBooks(const Library* library);

ErrorCode addUser(Library* library, int id, const char* name);
ErrorCode removeUser(Library* library, int id);
User* findUserById(Library* library, int id);
void listAllUsers(const Library* library);

ErrorCode borrowBook(Library* library, int userId, int bookId);
ErrorCode returnBook(Library* library, int userId, int bookId);
void listBorrowedBooks(const Library* library, int userId);

const char* getErrorMessage(ErrorCode code);

#endif