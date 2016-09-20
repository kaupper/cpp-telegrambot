#ifndef STORAGE_H_
#define STORAGE_H_

class Storage 
{
private:
    std::string type;
    
protected:
    Storage(std::string type) : type(type) { }
    
public:
    virtual ~Storage() { }
    
    const std::string & GetType() const { return type; }
};

#endif // STORAGE_H_