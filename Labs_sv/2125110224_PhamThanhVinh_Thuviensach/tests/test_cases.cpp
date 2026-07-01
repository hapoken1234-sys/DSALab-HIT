// main.cpp
#include <iostream>
#include "structures.h"

void showMenu() {
    std::cout << "\n===== HE THONG QUAN LY THU VIEN =====\n";
    std::cout << "1. Them sach moi (Vao cay BST)\n";
    std::cout << "2. Them doc gia moi (Vao Linked List)\n";
    std::cout << "3. Hien thi danh sach sach (In-order BST)\n";
    std::cout << "4. Hien thi danh sach doc gia\n";
    std::cout << "5. Dang ky muon sach (Xu ly Queue hang cho)\n";
    std::cout << "6. Tra sach\n";
    std::cout << "0. Thoat chuong trinh\n";
    std::cout << "Lua chon cua ban: ";
}

int main() {
    BookNode* bstRoot = nullptr;
    ReaderNode* readerHead = nullptr;
    int choice;

    // Chèn sẵn dữ liệu mẫu (Hardcode test case theo yêu cầu đề bài)
    bstRoot = insertBook(bstRoot, { "B02", "Nguyen Van Muoi" });
    bstRoot = insertBook(bstRoot, { "B01", "Ky su rank iron" });
    bstRoot = insertBook(bstRoot, { "B03", "Co So Du Lieu" });

    insertReader(readerHead, { "R01", "Your Name" });
    insertReader(readerHead, { "R02", "Lo Vuong" });

    do {
        showMenu();
        if (!(std::cin >> choice)) {
            std::cout << "Du lieu nhap sai! Vui long nhap so.\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
        case 1: {
            Book b;
            std::cout << "Nhap ma sach: "; std::cin >> b.bookID;
            std::cin.ignore();
            std::cout << "Nhap ten sach: "; std::getline(std::cin, b.title);
            bstRoot = insertBook(bstRoot, b);
            std::cout << "Them sach thanh cong!\n";
            break;
        }
        case 2: {
            Reader r;
            std::cout << "Nhap ma doc gia: "; std::cin >> r.readerID;
            std::cin.ignore();
            std::cout << "Nhap ten doc gia: "; std::getline(std::cin, r.name);
            insertReader(readerHead, r);
            std::cout << "Them doc gia thanh cong!\n";
            break;
        }
        case 3:
            std::cout << "\n--- DANH SACH SACH TRONG THU VIEN ---\n";
            printInOrder(bstRoot);
            break;
        case 4:
            std::cout << "\n--- DANH SACH DOC GIA ---\n";
            printReaderList(readerHead);
            break;
        case 5: {
            std::string bID, rID;
            std::cout << "Nhap ma sach muon muon: "; std::cin >> bID;
            std::cout << "Nhap ma doc gia muon: "; std::cin >> rID;

            BookNode* bNode = searchBook(bstRoot, bID);
            ReaderNode* rNode = searchReader(readerHead, rID);

            if (!bNode) std::cout << "Khong tim thay sach!\n";
            else if (!rNode) std::cout << "Khong tim thay doc gia!\n";
            else {
                if (!bNode->data.isBorrowed) {
                    bNode->data.isBorrowed = true;
                    std::cout << "Doc gia " << rNode->data.name << " da muon thanh cong cuon sach: " << bNode->data.title << "\n";
                }
                else {
                    bNode->data.waitingReaders.enqueue(rID);
                    std::cout << "Sach da co nguoi muon! Doc gia da duoc them vao hang cho (Queue).\n";
                }
            }
            break;
        }
        case 6: {
            std::string bID;
            std::cout << "Nhap ma sach tra: "; std::cin >> bID;
            BookNode* bNode = searchBook(bstRoot, bID);

            if (!bNode) {
                std::cout << "Khong tim thay ma sach nay!\n";
            }
            else if (!bNode->data.isBorrowed) {
                std::cout << "Sach nay hien tai chua co ai muon!\n";
            }
            else {
                std::cout << "Tra sach thanh cong!\n";
                if (!bNode->data.waitingReaders.isEmpty()) {
                    std::string nextReaderID = bNode->data.waitingReaders.dequeue();
                    ReaderNode* nextReader = searchReader(readerHead, nextReaderID);
                    std::cout << "==> Sach tu dong chuyen cho nguoi ke tiep trong Queue: " << nextReader->data.name << "\n";
                }
                else {
                    bNode->data.isBorrowed = false;
                }
            }
            break;
        }
        case 0:
            std::cout << "Cam on ban da su dung he thong!\n";
            break;
        default:
            std::cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);

    // Giải phóng bộ nhớ động trước khi kết thúc chương trình
    freeBST(bstRoot);
    freeLinkedList(readerHead);
    return 0;
}
