#include "../include/cache.hpp"
class SimpleCache {
private:
    unordered_map<string, string> storage_;
    
public:
    bool set(const string& key, const string& value){
        if(key.size()>0 && value.size()>0){
            storage_[key]=value;
            return true;
        }
        return false;
    }
    bool exists(const string& key) const {
        storage_.find(key)!=storage_.end() ? true:false;
    }

    auto get(const string& key){
        if(exists(key)) return storage_[key];
        return "";
    }

    bool del(const string& key){
        if(exists(key)){
            storage_.erase(key);
            return true;
        }
        return false;

    }
    
    size_t size() const{
        return storage_.size();

    }
    void clear(){
        storage_.clear();
    }
};