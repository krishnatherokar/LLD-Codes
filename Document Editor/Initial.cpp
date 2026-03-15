#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class DocumentEditor {
private:
    string document;
    vector<pair<char, string>> documentElements;

public:
    void addText(string text){
        documentElements.push_back({'t', text});
    }

    void addImage(string path){
        documentElements.push_back({'i', path});
    }

    string render(){
        if(document.empty()){
            for(auto& [type, content]:documentElements){
                if(type == 't') document += content + "\n";
                else document += "Image: [" + content + "]\n";
            }
        }

        return document;
    }

    void saveToFile(){
        ofstream file("document.txt");
        try {
            file << render();
            file.close();
            cout << "--- Document saved to a file." << endl;
        } catch(...){
            cout << "--- Error opening file." << endl;
        }
    }
};

int main(){
    DocumentEditor editor;
    
    editor.addText("Hello world!");
    editor.addImage("cat.jpg");
    cout<<editor.render();
    editor.saveToFile();

    return 0;
}