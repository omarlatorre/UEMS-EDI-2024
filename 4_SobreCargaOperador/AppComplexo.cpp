#include <iostream>
using namespace std;

class Complexo {
private:
    double real;
    double imaginaria;

public:
    Complexo(double real, double imaginaria) :
    real(real), imaginaria(imaginaria) {
    }
    
    ~Complexo() {
    }
    
    Complexo operator+(const Complexo obj) const {
        double r = this->real + obj.real; 
        double i = this->imaginaria + obj.imaginaria;
        return Complexo(r,i);
    }
    
    Complexo operator-(const Complexo obj) const {
        double r = this->real - obj.real; 
        double i = this->imaginaria - obj.imaginaria;
        return Complexo(r,i);
    }
    
    Complexo operator*(const Complexo obj) const {
        double a = this->real;
        double b = this->imaginaria;
        double c = obj.real;
        double d = obj.imaginaria;
        
        double r = a * c - b * d;
        double i = a * d + b * c;
        return Complexo(r,i);
    }
    
    Complexo operator/(const Complexo obj) const {
        double a = this->real;
        double b = this->imaginaria;
        double c = obj.real;
        double d = obj.imaginaria;
        
        double r = (a * c + b * d) / (c * c + d * d);
        double i = (b * c - a * d) / (c * c + d * d);
        return Complexo(r,i);
    }
    
    friend ostream& operator<<(ostream& os, const Complexo& obj) {
        if (obj.imaginaria >= 0) {
            os << obj.real << " + " << obj.imaginaria << "i";
        } else {
            os << obj.real << " - " << -obj.imaginaria << "i";
        }
        return os;
    }
};

int main()
{
    Complexo c1(2,2);
    Complexo c2(3,5);
    Complexo c3(1,2);
    Complexo c4(3,4);
    cout << c1 << endl;
    cout << c2 << endl;
    cout << c1 + c2 << endl;
    cout << c1 - c2 << endl;
    cout << c3 * c4 << endl;
    cout << c3 / c4 << endl;
    
    return 0;
}
