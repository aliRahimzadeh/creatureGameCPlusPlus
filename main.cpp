
//A simple demonstration of classes and inheritance
//Along with object oriented design for reusability and scalability


#include <string>
#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>


using namespace std;

class Creature
{
private:
    int strength;
    int hitpoints;
public:
    virtual string getSpecies() = 0;
    Creature() {strength = 10;hitpoints = 10;}
    Creature(int newStrength, int newHitpoints) {strength = newStrength; newHitpoints = newHitpoints;}
    int getStrength()const {return strength;}
    int getHitpoints()const{return hitpoints;}
    void setStrength(int newStrength){strength = newStrength;}
    void setHitpoints(int newHitpoints){hitpoints = newHitpoints;}
    
    virtual int getDamage()
    {
        int damage = (rand() % strength) + 1;
        cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;
        return damage;
    }
    virtual ~Creature(){cout << ""<<endl;};
    
};




class Demon : public Creature
{
public:
    //Demon():Creature(){};
    
    Demon(int newStrength = 10, int newHitpoints = 10):Creature (newStrength,newHitpoints ){};
    
    virtual string getSpecies()= 0;
    
    int getDamage()
    {
        int damage=Creature::getDamage();
        if ((rand() % 100) < 25)
        {
            damage += 50;
            cout << "Demonic attack inflicts 50 additional damage points!" << endl;
        }
        return damage;
    }
    virtual ~Demon(){cout << "destructed"<< endl;}
};


class Elf : public Creature
{
public:
    
    Elf (int newStrength = 20, int newHitpoints = 20):Creature(newStrength, newHitpoints){};
    
    string getSpecies() {return "Elf";}
    
    int getDamage()
    {
        int damage;
        
        damage = Creature::getDamage();
        
        if ((rand() % 100) < 50)
        {
            cout << "\n Magical attack inflicts " << damage << " additional damage points!" << endl;
            damage = damage * 2;
        }
        return damage;
    }
    ~Elf(){cout << "destructed"<< endl;}
};



class Human : public Creature
{
public:
    
    Human (int newStrength = 20, int newHitpoints = 20):Creature(newStrength, newHitpoints){};
    
    string getSpecies() {return "Human";}
    
    int getDamage(){
        return Creature::getDamage();
    }
    
    ~Human(){cout << "destructed"<< endl;}
};


class Cyberdemon : public Demon
{
public:
    
    Cyberdemon (int newStrength = 20, int newHitpoints = 20):Demon(newStrength, newHitpoints){};
    
    string getSpecies() {return "Cyberdemon";}
    ~Cyberdemon(){cout << "destructed"<< endl;};
};



class Balrog : public Demon
{
public:
    
    Balrog (int newStrength = 20, int newHitpoints = 20):Demon(newStrength, newHitpoints){};
    
    
    string getSpecies()  {return "Balrog";}
    
    int getDamage()
    {
        int damage;
        int second_damage;
        
        
        damage = Demon::getDamage();
        second_damage = (rand() % getStrength()) + 1;
        
        cout << "Balrog speed attack inflicts " << second_damage << " additional damage points!\n";
        
        damage = damage + second_damage;
        return damage;
    }
    ~Balrog(){cout << "destructed"<< endl;}
};



int main()
{
    unsigned length = 4;
    Creature **c = new (nothrow) Creature*[length];
    
    //    if memory was allocated
    if(c == nullptr){
        cout << "memory wasnt allocated"<<endl;
        exit(1);
    }
    
    //  dynamic memory allocation
    c[0] = new (nothrow) Elf(20, 20);
    c[1] = new (nothrow) Human(20, 20);
    c[2] = new (nothrow) Cyberdemon(20, 20);
    c[3] = new (nothrow) Balrog(20, 20);
    
    for (int i = 0; i < length; i++ ){
        if(c[i] == nullptr){
            cout << "memory wasnt allocated"<<endl;
            exit(1);
        }
    }
    
    //    deallocation for memebers
    
    for (int i = 0; i < length; i++ ){
        delete c[i];
    }
    delete[] c;
    
    
    
}

