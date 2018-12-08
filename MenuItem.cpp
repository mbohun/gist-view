#include <iostream>
#include <string>

#include "MenuItem.h"
#include "Command.h"

namespace {

    class SubmenuRootCommand : public Command {
    private:
	const MenuItem& mi;

    public:
	SubmenuRootCommand(const MenuItem& m) : mi(m) {}

	void execute(void) const {
	    mi.display();
	}
	
    };
}

MenuItem::MenuItem(const std::string nm ) : name(nm) , destroy_command(true) {
    command =new SubmenuRootCommand(*this);//how to do this without new, or without the destroy_command flag ???
}

MenuItem::MenuItem(const std::string nm, const Command& cmd ) : name(nm), command(&cmd), destroy_command(false) {}

MenuItem::~MenuItem() {
    if(destroy_command) {
	delete command;
    }
}

void MenuItem::execute(void) const
{
    command->execute();
}

void MenuItem::add(const MenuItem& mi )
{
    submenu.push_back(&mi);
}

void MenuItem::display(void) const
{
    std::cout << *this << std::endl;
    
    unsigned int counter =0;
    std::vector<const MenuItem*>::const_iterator iter;
    for(iter =submenu.begin(); iter!=submenu.end(); ++iter) {
	const MenuItem& m =(**iter);
	std::cout << counter << ". " << m << std::endl;
	counter++;
    }

    std::cout << counter << ". " << "Quit" << std::endl;
    
    while(1) {
	int choice =-1;
	std::cin>>choice;

	if(choice>=0 && choice<counter ) {
	    submenu[choice]->execute();
	    break;
	}

	if(choice==counter) {
	    return;
	}

    }

    display();
}

std::ostream& operator<<(std::ostream& out, const MenuItem& mi ) 
{
    out << mi.name;
    return out;
}
