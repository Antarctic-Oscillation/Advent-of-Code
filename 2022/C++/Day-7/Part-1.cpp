#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>

constexpr int MAX_SIZE = 100000;
constexpr bool File = false; 
constexpr bool Dir = true;

struct TreeNode {
    int f_size;
    bool f_is_dir;
    std::string f_name;
    TreeNode* f_parent;
    std::vector<std::unique_ptr<TreeNode>> f_children;

    TreeNode(bool is_dir, const std::string& name, int size = -1)
        : f_is_dir(is_dir), f_name(name), f_size(size), f_parent(nullptr) {}

    void add_child(std::unique_ptr<TreeNode> child) {
        child->f_parent = this;
        f_children.push_back(std::move(child));
    }

    int get_size() {
        if (f_is_dir) {
            f_size = 0;
            for (const auto& child : f_children) {
                f_size += child->get_size();
            }
        }
        return f_size;
    }

    void findSmallDirectories(int& totalSize) {
        if (!f_is_dir) { return; }

        for (const auto& child : f_children) {
            child->findSmallDirectories(totalSize);
        }
        int size = get_size();
        if (size <= MAX_SIZE) {
            totalSize += size;
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::ifstream inputFile("input.txt");
    //-------------------------------------
    std::unique_ptr<TreeNode> root = std::make_unique<TreeNode>(Dir, "/");
    TreeNode* curr = root.get();

    std::string line;
    while (std::getline(inputFile, line) && !line.empty()) {
        std::istringstream iss(line);
        std::string prefix, name, suffix;
        iss >> prefix >> name >> suffix;

        if (prefix == "$") {
            if (name == "cd") {
                if (suffix == "/") {
                    curr = root.get();
                } else if (suffix == "..") {
                    curr = (!curr->f_parent) ? root.get() : curr->f_parent;
                } else {
                    for (const auto& child : curr->f_children) {
                        if (child->f_is_dir && child->f_name == suffix) {
                            curr = child.get();
                        }
                    }
                }
            }
        } else if (std::isdigit(prefix[0])) {
            curr->add_child(
                std::make_unique<TreeNode>(File, name, std::stoi(prefix)));
        } else {
            curr->add_child(std::make_unique<TreeNode>(Dir, name));
        }
    }

    int totalSize = 0;
    root->findSmallDirectories(totalSize);
    std::cout << totalSize << std::endl;
    
    return 0;
}