// structures.h
#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <string>
#include <iostream>

// ==========================================
// 1. CẤU TRÚC HÀNG CHỜ (QUEUE) - Dùng mảng vòng đơn giản để quản lý hàng chờ mượn sách
// ==========================================
struct Queue {
    std::string data[100];
    int frontIdx = 0;
    int rearIdx = 0;
    int count = 0;

    void enqueue(const std::string& readerID) {
        if (count < 100) {
            data[rearIdx] = readerID;
            rearIdx = (rearIdx + 1) % 100;
            count++;
        }
    }

    std::string dequeue() {
        if (count == 0) return "";
        std::string res = data[frontIdx];
        frontIdx = (frontIdx + 1) % 100;
        count--;
        return res;
    }

    bool isEmpty() const { return count == 0; }
};

// ==========================================
// 2. CẤU TRÚC CÂY NHỊ PHÂN TÌM KIẾM (BST) - Quản lý Sách
// ==========================================
struct Book {
    std::string bookID;     // Khóa chính để tìm kiếm
    std::string title;
    bool isBorrowed = false;
    Queue waitingReaders;   // Hàng chờ khi sách bị mượn hết
};

struct BookNode {
    Book data;
    BookNode* left = nullptr;
    BookNode* right = nullptr;
};

// Các hàm thao tác trên BST Sách
BookNode* insertBook(BookNode* root, Book newBook);
BookNode* searchBook(BookNode* root, const std::string& bookID);
void printInOrder(BookNode* root);
void freeBST(BookNode* root);

// ==========================================
// 3. CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN (LINKED LIST) - Quản lý Độc giả
// ==========================================
struct Reader {
    std::string readerID;
    std::string name;
};

struct ReaderNode {
    Reader data;
    ReaderNode* next = nullptr;
};

// Các hàm thao tác trên Linked List Độc giả
void insertReader(ReaderNode*& head, Reader newReader);
ReaderNode* searchReader(ReaderNode* head, const std::string& readerID);
void printReaderList(ReaderNode* head);
void freeLinkedList(ReaderNode* head);

#endif
