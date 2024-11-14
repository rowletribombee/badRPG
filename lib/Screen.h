#include <vector>
#include <string>
using namespace std;

class Screen 
{
    private:
    string startScreenTxt;
    string introScreenTxt;
    vector<string> raceOptions;
    vector<string> commandMenuOptions;
    vector<string> inventoryItems;
    public:
    string displayStartScreen();
    string displayIntroScreen();
    //string raceOptions();
    string displayCommandMenu();
    string displayInventory();
    string displayMapScreen();
    int sleep_for();
    void clearScreen();
}