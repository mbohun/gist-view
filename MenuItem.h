#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <string>
#include <vector>

#include "Command.h"

class MenuItem {
 private:
  const std::string name;
  const Command* command;
  const bool destroy_command;
  std::vector<const MenuItem* > submenu;

  MenuItem& operator=(const MenuItem& ) {}

 public:
  MenuItem(const std::string nm );
  MenuItem(const std::string nm, const Command& cmd );
  ~MenuItem();

  void execute(void) const;
  void add(const MenuItem& mi );
  void display(void) const;

  friend std::ostream& operator<<(std::ostream& out, const MenuItem& mi ); 

};

#endif
