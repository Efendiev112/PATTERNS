
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(string magazineIssue) = 0;
};

class Subject {
public:
    virtual ~Subject() = default;
    virtual void addObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void notifyObservers() = 0;
};

class MagazibePublisher : public Subject {
private:
    vector<Observer*> observers;
    string lastestIssue;
public:
    void addObserver(Observer* o) override {
        observers.push_back(o);
    }
    void removeObserver(Observer* o) {
        observers.erase(remove(observers.begin(), observers.end(), o), observers.end());
    }

    void notifyObservers() override {
        for (auto observer : observers) {
            observer->update(lastestIssue);
        }
    }

    void releseNewIssue(string issue) {
        lastestIssue = issue;
        notifyObservers();

    }

};

class Subscriber : public Observer {
private:
    string name;
public:
    Subscriber(string name) : name(name){}

    void update(string magazineIssue) {
        cout << "Subscriber " << name << " recived new magazine issue " << magazineIssue<<endl;
    }
};






int main()
{
    Subscriber* sub1 = new Subscriber("Artem4ik");
    Subscriber* sub2 = new Subscriber("NAzar4ik");
    Subscriber* sub3 = new Subscriber("Nikitka");
    Subscriber* sub4 = new Subscriber("Vadim4ik");

    MagazibePublisher* mag = new MagazibePublisher();
    mag->addObserver(sub1);
    //mag->addObserver(sub2);
    mag->addObserver(sub3);
    mag->addObserver(sub4);

    mag->notifyObservers();


}
