#include <iostream> 
#include <string> 
using namespace std; 


// class Date
// {
//     private:
//         int year;
//         int month;
//         int day;
//     public:
//         Date(int year, int month, int day): year(year), month(month), day(day) { }
//         Date(const Date& d) : year(d.year), month(d.month), day(d.day) { }
//         void OutDate() {
//             cout << year << "년 " << month <<"월 "<< day <<"일 " << endl;
//         }
// };

// int main()
// {   
//     Date d1(1986,12, 10);
//     Date d2(2011, 4,  7);

//     d1.OutDate(); 
//     d2.OutDate();

//     Date d3(d1);  
//     d3.OutDate();
//     return 0;
// }


// class Point
// { 
//     int x, y;
// public:
//     Point(int a, int b) : x(a), y(b) { }
// };
// class Rectangle {
//     Point p1, p2; 
// public:
//     Rectangle(int x1, int y1, int x2, int y2) : p1(x1, y1), p2(x2, y2) { }
// };
// int main() 
// {
//     Rectangle r(1, 1, 10, 10);
//     return 0;
// }

//4 DynamicArray 
// class DynamicArray{
//     private:
//         int size;
//     public:
//         int *arr;
//         DynamicArray(int size): size(size) {
//             arr = new int[size];
//             for(int i = 0; i < size; i++ ){
//                 arr[i] = i;
//                 cout << arr[i] << endl;
//             }
//             cout << "동적할당 완료" << endl;
//         }
//         ~DynamicArray() {
//             delete[] arr;
//             cout << "동적할당 해제 완료" << endl;
//         }
// };

// int main()
// { 
//     int size;
//     cout << "몇 개의 정수를 입력받으시겠습니까? : "; 
//     cin >> size;
//     DynamicArray da(size);
//     for(int i = (size); i <= 0; i--)
//     {
//         cout << da.arr[i] << endl;
//     }
//     return 0;
// } 

//3 생성자 소멸자
// class Car { 
//     private:
//         int speed; // 속도
//         int gear; // 주행거리 
//         string color;// 색상
// public: 
//         Car() {
//         cout << "생성자 호출" << endl; 
//         speed = 0; 
//         gear = 1; 
//         color = "white";
//         } 
//         ~Car()
//         {
//         cout << "소멸자 호출" << endl;
//         }
// }; 
// int main() {
//     Car c1; 
//     return 0;
// }


//2
// class ACC
// {
//     int accNum; //계좌번호
//     string pw;  //비밀번호
//     string name;    //이름
//     int balance;    //잔액
// public:
//     ACC(int accNum, string pw, string name, int balance):accNum(accNum), pw(pw), name(name), balance(balance){
//         cout << "생성자를 이용한 멤버변수 초기화 수행" << endl;
//     }
//     void showData() {
//         cout << "계좌번호 : " << accNum << "\n"<< name <<"회원님 잔액은 " << balance << "입니다."<< endl;
//     }
//     void deposit() {
//         int money;
//         cout << "입금금액 입력: ";
//         cin >> money;
//         balance += money;
//         cout << "\t\t" << money <<"원 입금완료" << endl;
//     }
//     void withdraw() {
//         int money;
//         cout << "출금금액 입력: ";
//         cin >> money;
//         balance -= money;
//         cout << "\t\t" <<money <<"원 출금완료" << endl;
//     }
// };

// int main() 
// {
//     ACC ac(1111, "1234", "둘리", 5000);  //계좌번호, 비밀번호, 이름, 잔액
//     ac.showData();  //잔액조회
//     ac.deposit();   //입금
//     ac.withdraw();  //출금
//     ac.showData();  //잔액조회
//     return 0;
// }

// 1
// class MyClass 
// { 
//     public: 
//         MyClass(); 
//         MyClass(int a); 
//         MyClass(char c, int a, double d); 
//         MyClass(string p); 
// };
// int main() 
// {
//     MyClass m1, m2, m3;
//     MyClass m4;
//     MyClass m5(10), m6(20);
//     MyClass m7('a', 30, 3.78);
//     MyClass m8('y', 130, 183.708);
//     MyClass m9("Hello");
//     return 0; 
// } 
// MyClass::MyClass() {cout << "인수가 없는생성자\n"; } 
// MyClass::MyClass(int a) {cout << a << " 받는 생성자\n"; } 
// MyClass::MyClass(char c, int a, double d) {cout << c << ' ' << a << ' ' << d << " 받는생성자\n"; }
// MyClass::MyClass(string p){ cout << p << " 받는생성자\n";}
