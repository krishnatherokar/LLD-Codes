#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Robot {};

class walkableRobot : public Robot {
public:
    void walk(){
        cout << "Robot is walking." << endl;
    }
};

class nonWalkableRobot : public Robot {
public:
    void walk(){
        cout << "Robot cannot walk." << endl;
    }
};

class talkableWalkableRobot : public walkableRobot {
public:
    void talk(){
        cout << "Robot is talking." << endl;
    }
};

class nonTalkableWalkableRobot : public walkableRobot {
public:
    void talk(){
        cout << "Robot cannot talk." << endl;
    }
};

class nonTalkableNonWalkableRobot : public nonWalkableRobot {
public:
    void talk(){
        cout << "Robot cannot talk." << endl;
    }
};

int main(){
    nonTalkableWalkableRobot krish;
    krish.walk();
    krish.talk();
    return 0;
}