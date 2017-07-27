/* Aim of this trie is to store words in dictionary */

#include <memory>
#include <map>
#include <string>

struct Node {
    typedef std::map<char,std::shared_ptr<Node> > ChildMap;
    std::shared_ptr<std::string>  _explanation;
    ChildMap  _childMap;

};

class Trie
{
public:
    Trie();
    bool add(const std::string& word_, const std::string& explanation_);
    bool search(const std::string& word_) const;
    bool print() const;

private:
    bool addImpl(const std::string& word_, const std::string& explanation_, const std::shared_ptr<Node>& currentPtr_);

    std::shared_ptr<Node>        _head;
};





