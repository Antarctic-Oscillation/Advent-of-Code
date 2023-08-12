#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

constexpr int MAX_SIZE = 100000;
constexpr bool File = false; 
constexpr bool Dir = true;

struct TreeNode {
    int m_size;
    bool m_is_dir;
    std::string m_name;
    TreeNode* m_parent;
    std::vector<std::unique_ptr<TreeNode>> m_children;

    TreeNode(bool is_dir, const std::string& name, int size = -1)
        : m_is_dir(is_dir), m_name(name), m_size(size), m_parent(nullptr) {}

    void add_child(std::unique_ptr<TreeNode> child) {
        child->m_parent = this;
        m_children.push_back(std::move(child));
    }

    int get_size() {
        if (m_is_dir && m_size == -1) {
            m_size = 0;
            for (const auto& child : m_children) {
                m_size += child->get_size();
            }
        }
        return m_size;
    }

    void findSmallDirectories(int& totalSize) {
        if (!m_is_dir) { return; }

        for (const auto& child : m_children) {
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
        iss >> prefix >> name;

        if (prefix == "$") {
            if (name == "cd") {
                iss >> suffix;
                if (suffix == "/") {
                    curr = root.get();
                } else if (suffix == "..") {
                    curr = (!curr->m_parent) ? root.get() : curr->m_parent;
                } else {
                    for (const auto& child : curr->m_children) {
                        if (child->m_is_dir && child->m_name == suffix) {
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