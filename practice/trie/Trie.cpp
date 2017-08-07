#include "iostream"
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

std::shared_ptr<std::string> Trie::search(const std::string& word_) const
{
    return searchImpl(_head, word_);
}

std::shared_ptr<std::string> Trie::searchImpl(const std::shared_ptr<Node>& currentPtr_,const std::string& word_) const
{
    if(0 == word_.length())
    {
        return currentPtr_->_explanation;
    }
    if(currentPtr_->_childMap.find(word_[0]) == currentPtr_->_childMap.end())
    {
        return std::shared_ptr<std::string>();
    }
        
    return searchImpl(currentPtr_->_childMap.find(word_[0])->second, word_.substr(1));
}

void Trie::print() const {
    printImpl(_head, "");
}
void Trie::printImpl(const std::shared_ptr<Node>& currentPtr_,
                     const std::string& string_) const {
    if(currentPtr_->_explanation) {
        std::cout << string_ << " : "<< *(currentPtr_->_explanation) <<std::endl;
    }
    
    for(auto it = currentPtr_->_childMap.begin(); it != currentPtr_->_childMap.end(); ++it)
    {
        printImpl(it->second, string_ + it->first);
    }   
}
