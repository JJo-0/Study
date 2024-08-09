#include <iostream> 
#include <string> 
using namespace std; 

// class Animal { 
//     public:
//         virtual void Walk(){cout << "네발로걷는다.\n";}
// };
// class Duck : public Animal { 
//     public:
//         void Walk() {cout << "두발로걷는다.\n";} //오버라이딩
// };
// int main() {
//     Animal *p;
//     p = new Animal;
//     p->Walk();
//     delete p;
//     p = new Duck;
//     p->Walk();
//     delete p;
//     return 0; 
// }


// class Shape { // 일반적인도형을나타내는부모클래스
//     protected:
//         int x, y;
//     public:
//         void draw() { cout <<"Shape Draw" << endl;} 
//         void setOrigin(int x, int y){this->x = x; this->y = y;}
// };
// class Rectangle : public Shape { 
// private:
//     int width, height;
// public:
//     void setWidth(int w) {width = w;} 
//     void setHeight(int h) {height = h;} 
//     void draw() {cout << "Rectangle Draw"<< endl;}
// };
// class Circle : public Shape {
//     private:  
//         int radius;
//     public:
//         void setRadius(int r) {radius = r;}
//         void draw() {cout << "Circle Draw"<< endl;}
// };

// int main() {
//     Shape *ps = new Rectangle(); // OK!
//     ps->setOrigin(10, 10); 
//     ps->draw(); 
//     ((Rectangle *)ps)->setWidth(100);  // Rectangle의setWidth() 호출 
//     delete ps;
// }


// class Player {
//     private :
//         string name;
//     public:
//         Player(string _name) : name(_name) { }
//         string getName() {
//             return name;
//         }
// };

// class Pitcher : public Player {
//     private:
//         int back_number;
//     public:
//         Pitcher(string _name, int _back_number) : Player(_name), back_number(_back_number) { }
//         void Display() {
//             cout << "이름 : " << getName() << endl;
//             cout << "번호 : " << back_number << endl;
//         }
// };

// int main() {
//     Pitcher s("박찬호", 61);
//     s.Display();
//     return 0; 
// }


// class Base { 
//     public: //어디서든 접근가능
//         void Set_a(int _a)       //a값을 설정해주는 함수
//         {  
//             a = _a; 
//         } 
//         int Get_a()                 //a값을 리턴하는함수
//         { 
//             return a;
//         } 
//     private:
//         int a; 
// };
// class Derived : public Base {
//     public:
//         void Set(int _a, int _b) {
//             Set_a(_a);
//             b = _b;
//         }
//         int Mul() {
//             return Get_a() * b;
//         }
//     private:
//         int b;
// };

// int main() {
//     Derived ob;
//     ob.Set(10, 4);
//     cout << ob.Mul() << endl;
//     return 0; 
// }

