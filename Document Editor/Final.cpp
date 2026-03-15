#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// single responsibility
// open-closed principle
// liskov substitution

class DocumentElement {
protected:
    string content;

public:
    virtual string render() = 0;
};

class Text : public DocumentElement {
public:
    Text(string text){
        this->content = text;
    }

    string render(){
        return content + "\n";
    }
};

class Image : public DocumentElement {
public:
    Image(string path){
        this->content = path;
    }

    string render(){
        return "Image: [" + content + "]\n";
    }
};

// video element

class Video : public DocumentElement {
public:
    Video(string path){
        this->content = path;
    }

    string render(){
        return "Video: [" + content + "]\n";
    }
};

// we can add more elements in future

class Persistance {
public:
    virtual void save(string document) = 0;
};

class SaveToFile : public Persistance {
public:
    void save(string document){
        ofstream file("document.txt");
        try {
            file << document;
            file.close();
            cout << "--- Document saved to a file." << endl;
        } catch(...){
            cout << "--- Error opening file." << endl;
        }
    }
};

// more persistance methods can be added

class DocumentEditor {
private:
    string document;
    vector<DocumentElement*> documentElements;

public:
    void addElement(DocumentElement* element){
        documentElements.push_back(element);
    }

    string render(){
        if(document.empty()){
            for(auto& element:documentElements){
                document += element->render();
            }
        }

        return document;
    }

    void save(Persistance* storage){
        storage->save(render());
    }
};

int main(){
    DocumentEditor editor;
    
    editor.addElement(new Text("Hello world!"));
    editor.addElement(new Image("cat.jpg"));
    editor.addElement(new Video("bike.mp4"));
    // we can do new Video("cat.mp4") in future

    cout<<editor.render();

    SaveToFile* fileStorage = new SaveToFile;
    // the user can choose where to save: file / cloud / database
    editor.save(fileStorage);

    return 0;
}