#include <bits/stdc++.h>
using namespace std;

class FileSystem {
public:
    struct FileNode{
        bool isFile;
        string content;
        unordered_map<string, FileNode*> next;
        FileNode(): isFile(false), content("") {}
    };
    
    FileNode* root;
    
    FileSystem() {
        root = new FileNode();
    }
    
    FileNode* goToPathFolder(string& path){
        FileNode* curr = root;
        istringstream iss(path);
        string folder;
        
        while(getline(iss, folder, '/')){
            if (folder.size()){
                if (!curr->next[folder]){
                    curr->next[folder] = new FileNode();
                }
                curr = curr->next[folder];
            }
        }
        
        return curr;
    }
    
    vector<string> ls(string path) {
        FileNode* curr = goToPathFolder(path);
        
        if (curr->isFile){
            return {path.substr(path.find_last_of('/')+1)};
        }
        
        vector<string> res;
        for (auto& file: curr->next){
            res.push_back(file.first);
        }
        sort(begin(res), end(res));
        return res;
    }
    
    void mkdir(string path) {
        FileNode* curr = goToPathFolder(path);
    }
    
    void addContentToFile(string filePath, string content) {
        FileNode* curr = goToPathFolder(filePath);
        curr->content += content;
        curr->isFile = true;
    }
    
    string readContentFromFile(string filePath) {
        FileNode* curr = goToPathFolder(filePath);
        return curr->content;
    }
};


/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */ 