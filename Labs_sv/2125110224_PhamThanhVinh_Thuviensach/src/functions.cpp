// functions.cpp
#include "structures.h"

// ==========================================
// CÀI ĐẶT CÁC HÀM BST (SÁCH)
// ==========================================
BookNode* insertBook(BookNode* root, Book newBook) {
    if (root == nullptr) {
        BookNode* newNode = new BookNode;
        newNode->data = newBook;
        return newNode;
    }
    if (newBook.bookID < root->data.bookID) {
        root->left = insertBook(root->left, newBook);
    }
    else if (newBook.bookID > root->data.bookID) {
        root->right = insertBook(root->right, newBook);
    }
    return root;
}

BookNode* searchBook(BookNode* root, const std::string& bookID) {
    if (root == nullptr || root->data.bookID == bookID) {
        return root;
    }
    if (bookID < root->data.bookID) {
        return searchBook(root->left, bookID);
    }
    return searchBook(root->right, bookID);
}

void printInOrder(BookNode* root) {
    if (root != nullptr) {
        printInOrder(root->left);
        std::cout << "[" << root->data.bookID << "] " << root->data.title
            << " -> Trang thai: " << (root->data.isBorrowed ? "Dang muon" : "San sang")
            << " (Cho: " << root->data.waitingReaders.count << " nguoi)\n";
        printInOrder(root->right);
    }
}

void freeBST(BookNode* root) {
    if (root != nullptr) {
        freeBST(root->left);
        freeBST(root->right);
        delete root;
    }
}

// ==========================================
// CÀI ĐẶT CÁC HÀM LINKED LIST (ĐỘC GIẢ)
// ==========================================
void insertReader(ReaderNode*& head, Reader newReader) {
    ReaderNode* newNode = new ReaderNode;
    newNode->data = newReader;
    if (head == nullptr) {
        head = newNode;
        return;
    }
    ReaderNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

ReaderNode* searchReader(ReaderNode* head, const std::string& readerID) {
    ReaderNode* curr = head;
    while (curr != nullptr) {
        if (curr->data.readerID == readerID) return curr;
        curr = curr->next;
    }
    return nullptr;
}

void printReaderList(ReaderNode* head) {
    ReaderNode* curr = head;
    while (curr != nullptr) {
        std::cout << "Ma DG: " << curr->data.readerID << " | TEn: " << curr->data.name << "\n";
        curr = curr->next;
    }
}

void freeLinkedList(ReaderNode* head) {
    while (head != nullptr) {
        ReaderNode* temp = head;
        head = head->next;
        delete temp;
    }
}
