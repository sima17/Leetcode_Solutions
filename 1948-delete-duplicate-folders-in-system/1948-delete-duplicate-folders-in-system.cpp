struct Folder{
    unordered_map<string, Folder*> children;
    bool toDelete = false;
    string signature = "";
}; 

class Solution {
private: 
    string generateSignatures(Folder* node, unordered_map<string, int>& signatures){
        if(!node) return "";
        vector<string> childSignatures;
        for(auto& [name, child] : node->children){
            string childSignature = generateSignatures(child, signatures);
            childSignatures.push_back(name + "("+childSignature+")");
        }
        sort(childSignatures.begin(),childSignatures.end());
        string nodeSignature = "";
        for(string& childSignature : childSignatures){
            nodeSignature += childSignature;
        }
        signatures[nodeSignature]++;
        node->signature = nodeSignature;
        return nodeSignature;
    }

    void markDuplicates(Folder* node, unordered_map<string, int>& signatures){
        if(!node) return;

        string signature = node->signature;
        if(!signature.empty() && signatures[signature] > 1){
            node->toDelete = true;
            return;
        }

        for(auto& [name, child] : node->children){
            markDuplicates(child,signatures);
        }
    }

    void validFolders(Folder* node, vector<string>& curr, vector<vector<string>>& res){
        if(!node) return;

        for(auto& [name, child] : node->children){
            if(!child->toDelete){
                curr.push_back(name);
                res.push_back(curr);
                validFolders(child,curr,res);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Folder* root = new Folder();
        for(auto& path : paths){
            Folder* curr = root;
            for(string& folder : path){
                if(curr->children.find(folder) == curr->children.end()){
                    curr->children[folder] = new Folder();
                }
                curr = curr->children[folder];
            }
        }

        unordered_map<string, int> signatures;
        generateSignatures(root, signatures);

        markDuplicates(root, signatures);

        vector<vector<string>> res;
        vector<string> temp;
        validFolders(root,temp,res);
        return res;
    }
};