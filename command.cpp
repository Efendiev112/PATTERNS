
#include <iostream>
using namespace std;

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class Light {
private:
    string location;

public:
    Light(string location ) : location(location){}
    void on() {
        cout << location<<  " Light is on" << endl;
    }

    void off(){
        cout <<location<< " Light is off" << endl;
    }
};

class LightOnCommand : public Command {
private:
    Light* light;
public:
    LightOnCommand(Light* light) : light(light){}
    void execute()override {
        light->on();
    }

    void undo()override {
        light->off();
    }


};


class LightOffCommand : public Command {
private:
    Light* light;
public:
    LightOffCommand(Light* light) : light(light) {}
    void execute()override {
        light->off();
    }

    void undo()override {
        light->on();
    }


};

class RemoteControl {
private:
    Command* command;
public:
    void setCommand(Command* cmd) {
        command = cmd;
     }
    
    void pressButton() {
        if (command) {
            command->execute();
        }
    }

    void pressUndo() {
        if (command) {
            command->undo();
        }
    }

};



int main()
{
    Light* livingRoomLight = new Light("Living room");
    LightOnCommand* lightOn = new LightOnCommand(livingRoomLight);
    LightOffCommand* lightoff = new LightOffCommand(livingRoomLight);

    RemoteControl* remote = new RemoteControl();
    remote->setCommand(lightoff);
    remote->pressUndo();


}


