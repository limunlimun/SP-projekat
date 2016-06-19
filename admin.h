#ifndef _ADMIN_H
#define _ADMIN_H
#include <string>
//zasebna klasa za administratora
class Admin{
  private:
    //korisnicko ime i pass za administratora ostaju konstantni uvijek
    const std::string k_ime="administrator";
    const std::string pass="projekat";
  public:
    //metod za provjeru podataka za administratora
    bool login(std::string k,std::string loz){
      if(k==k_ime&&pass==loz) return true;
      else return false;
    }
};

#endif
