#include "Trie.h"

Trie::Trie(){
    _head = std::make_shared<Node>();
}

bool Trie::add(const std::string& word_) const {
    addImpl(word_,_head);
}

bool Trie::addImpl(const std::string& word_, const std::shared_ptr<Node>& currentPtr_) const{
//    shared_ptr<Node>
}

bool Trie::search(const std::string& word_) const {

}

bool Trie::print() const {

}
