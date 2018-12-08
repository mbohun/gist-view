#include <iostream>

#include "Command.h"
#include "MenuItem.h"

namespace {

    void play() {
	std::cout << "Starting..." << std::endl;
    }

    void aaa() {
	std::cout << "aaa..." << std::endl;
    }

    void bbb() {
	std::cout << "bbb..." << std::endl;
    }

    void ccc() {
	std::cout << "ccc..." << std::endl;
    }

    void ddd() {
	std::cout << "ddd..." << std::endl;
    }

    void eee() {
	std::cout << "eee..." << std::endl;
    }

    //some command classes

    class DummyCommand : public Command {
    public:
	void execute(void) const {
	    play();
	}
	
    };

    class WrapFooCommand : public Command {
    private:
	void(*fp)(void);

    public:
	WrapFooCommand(void(*f)(void) ) : fp(f) {}

	void execute(void) const {
	    fp();
	}
    };


}


int main(int argc, char* argv[] ) {

    MenuItem root =MenuItem("Main Menu");
    DummyCommand dc;

    MenuItem play =MenuItem("Play", dc );
    MenuItem test =MenuItem("Test");

    WrapFooCommand wfc =WrapFooCommand(aaa);
    MenuItem tmi =MenuItem("aaa", wfc );

    test.add(tmi);
    root.add(play);
    root.add(test);

    root.display();

    return 0;
}
