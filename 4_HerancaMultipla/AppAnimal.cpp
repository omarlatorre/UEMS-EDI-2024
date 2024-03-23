#include <iostream>
using namespace std;

class Animal {
private:
    int weight;
public:
    Animal(int weight) : weight(weight) {
    }
    
    ~Animal() {
    }
    
    int getWeight() {
        return weight;
    }
};

class Lion : public Animal {
public:
    Lion(int weight) : Animal(weight){
    }
    
    ~Lion() {
    }
};

class Tiger : public Animal {
public:
    Tiger(int weight) : Animal(weight){
        
    }
    
    ~Tiger() {
    }
};

class Liger : public Lion, public Tiger {
public:
    Liger(int weight) :
    Lion(weight), Tiger(weight) {
    }
    
    ~Liger() {
    }
    
    int getWeight() {
        return Tiger::getWeight();
    }
};

int main()
{
    Liger lg(100);

    int weight = lg.getWeight();

    cout << weight << endl;
    
    return 0;
}
