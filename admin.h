#ifndef _ADMIN_H
#define _ADMIN_H
#include <string>
class Admin{
  private:
    const std::string k_ime="administrator";
    const std::string pass="projekat";
  public:
    bool login(std::string k,std::string loz){
      if(k==k_ime&&pass==loz) return true;
      else return false;
    }
};

#endif
