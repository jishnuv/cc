#include "Trie.h"

Trie::Trie(){
    _head = std::make_shared<Node>();
}

bool Trie::add(const std::string& word_, const std::string& explanation_) {
    addImpl(word_,explanation_,_head);
}

bool Trie::addImpl(const std::string& word_, const std::string& explanation_, const std::shared_ptr<Node>& currentPtr_) {
    if(!word_.size()) {
        currentPtr_->_explanation.reset(new std::string(explanation_));
        return true;
    }
    else {
        if(currentPtr_->_childMap.find(word_[0]) == currentPtr_->_childMap.end()) {
            std::shared_ptr<Node> temp = std::make_shared<Node>();
            currentPtr_->_childMap.insert(std::make_pair(word_[0], temp));
            addImpl(word_.substr(1),explanation_,temp);
        } else {
            addImpl(word_.substr(1),explanation_,currentPtr_->_childMap[word_[0]]);
        }
    }
}

bool Trie::search(const std::string& word_) const {

}

bool Trie::print() const {
}

