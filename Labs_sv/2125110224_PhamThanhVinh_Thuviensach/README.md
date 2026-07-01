# ĐỒ ÁN CUỐI KỲ: HỆ THỐNG QUẢN LÝ THƯ VIỆN (CLI)

* **Môn học:** Cấu Trúc Dữ Liệu & Giải Thuật
* **Sinh viên thực hiện:** Phạm Thành Vinh (MSSV: 212110224)
* **Giảng viên hướng dẫn:** Thầy TVS

---

## 1. Các Cấu Trúc Dữ Liệu Sử Dụng & Vai Trò
Ứng dụng đáp ứng yêu cầu tối thiểu bằng cách kết hợp 3 cấu trúc dữ liệu chính:
* **Binary Search Tree (BST):** Dùng để lưu trữ và quản lý danh sách sách. Giúp tối ưu hóa thao tác tìm kiếm sách theo `bookID` với độ phức tạp trung bình là $O(\log n)$.
* **Linked List (Danh sách liên kết đơn):** Dùng để quản lý danh sách độc giả. Phù hợp vì danh sách độc giả thường chỉ thêm mới vào cuối và duyệt tuần tự, không cần cấp phát mảng tĩnh liên tục.
* **Queue (Hàng chờ vòng):** Được nhúng trực tiếp vào mỗi node Sách để quản lý danh sách độc giả xếp hàng chờ mượn khi sách đó đã bị mượn hết (FIFO - Vào trước ra trước).

---

## 2. Hướng Dẫn Biên Dịch Và Chạy Chương Trình

Hệ thống được viết hoàn toàn bằng C++ tiêu chuẩn, không dùng thư viện ngoài.

**Lệnh biên dịch (Compile):**
```bash
g++ -std=c++17 src/main.cpp src/functions.cpp -o app




Labs_sv/2125110224_PhamThanhVinh_ThuViensach/
├── src/
│   ├── main.cpp          # Quản lý Menu và luồng chạy chính
│   ├── structures.h      # Khai báo Struct (BST, Queue, Linked List)
│   └── functions.cpp     # Cài đặt chi tiết các hàm thuật toán
├── tests/
│   └── test_cases.cpp    # File chứa các hàm chạy thử nghiệm (đọc mục 3)
└── README.md             # Tài liệu hướng dẫn sử dụng và báo cáo nhanh
