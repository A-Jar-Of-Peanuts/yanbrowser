#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include "nodestruct.h"

using namespace std;

class Document: public NodeType {
    public:
        string type;
        Document(string t) {
            type = t;
        }
};

class Text: public NodeType {
    public:
        string text;
        Text(string t) {
            text = t;
            type = text;
        }
};

class Element: public NodeType {
    public:
        string tagname;
        unordered_map<string, string> atmap;
        Element(string tn, unordered_map<string, string> am) {
            tagname = tn;
            atmap = am;
            type = tagname;
            for(auto& it : atmap) {
                type += " " + it.first + ": " + it.second;
            }
        }
};

class Comment: public NodeType{

};

Node* text(vector<Node*> children, string t) {
    Text tx(t);
    Node* nd = new Node(children, tx);
    return nd;
}

Node* element(vector<Node*> children, string tn, unordered_map<string, string> am) {
    Element elem(tn, am);
    Node* nd = new Node(children, elem);
    return nd;
}

Node document(string t) {
    Document d(t);
    Node* nd = new Node(vector<Node*>(), d);
}