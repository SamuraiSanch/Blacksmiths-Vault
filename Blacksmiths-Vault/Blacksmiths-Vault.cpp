#include "Database.h"
#include "Menu.h"

using namespace std;

int main()
{
	Database::getInstance().initialize();
	Menu menu;
	menu.startMenu();
	return 0;
}
