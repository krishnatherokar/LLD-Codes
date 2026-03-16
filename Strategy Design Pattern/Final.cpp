#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// strategy interfaces

class WalkingStrategy {
public:
    virtual void walk()=0;
};

class TalkingStrategy {
public:
    virtual void talk()=0;
};

class Robot {
private:
    TalkingStrategy* talk_strategy;
    WalkingStrategy* walk_strategy;

public:
    Robot(TalkingStrategy* t, WalkingStrategy* w){
        talk_strategy = t;
        walk_strategy = w;
    }
    
    void talk(){
        talk_strategy->talk();
    }
    
    void walk(){
        walk_strategy->walk();
    }
};

// concrete strategies

class Walkable : public WalkingStrategy {
public:
    void walk(){
        cout << "Robot is walking." << endl;
    }
};

class NonWalkable : public WalkingStrategy {
public:
    void walk(){
        cout << "Robot cannot walk." << endl;
    }
};

class Talkable : public TalkingStrategy {
public:
    void talk(){
        cout << "Robot is talking." << endl;
    }
};

class NonTalkable : public TalkingStrategy {
public:
    void talk(){
        cout << "Robot cannot talk." << endl;
    }
};

int main(){
    Robot krish(new NonTalkable(), new Walkable());
    krish.walk();
    krish.talk();
    return 0;
}