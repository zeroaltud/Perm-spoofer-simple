#include "include.hpp"
#include "spoof.h"
#include "auth.hpp"

using namespace KeyAuth;

std::string name = skCrypt("Loader").decrypt(); // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = skCrypt("DdVDRJyMHD").decrypt(); // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = skCrypt("038b39c8cf167d31f595298d890d61cad384eddf730a0d1fecaff359d390e836").decrypt(); // app secret, the blurred text on licenses tab and other tabs
std::string version = skCrypt("3.0").decrypt(); // leave alone unless you've changed version on website
std::string url = skCrypt("https://keyauth.win/api/1.2/").decrypt(); // change if you're self-hosting

KeyAuth::api KeyAuthApp(name, ownerid, secret, version, url);

int main() {
    startAntiDebugThread();
    startconsolethread();
   int idkanymore;
 //   std::string username;
 //   std::string password;

	//name.clear(); ownerid.clear(); secret.clear(); version.clear(); url.clear();
	//KeyAuthApp.init();

 //   if (!KeyAuthApp.data.success)
 //   {
 //       std::cout << skCrypt("\n Status: ") << KeyAuthApp.data.message;
 //       Sleep(1500);
 //       exit(1);
 //   }

 //   std::cout << skCrypt("\n\n Enter username: ");
 //   std::cin >> username;
 //   std::cout << skCrypt("\n Enter password: ");
 //   std::cin >> password;
 //   KeyAuthApp.login(username, password);

 //   if (!KeyAuthApp.data.success)
 //   {
 //       std::cout << skCrypt("\n Status: ") << KeyAuthApp.data.message;
 //       Sleep(1500);
 //       exit(1);
 //   }
    // after login
    Sleep(1000);
    system(E("cls"));
    std::cout << (E("Welcome to zerogravity's perm spoofer"));
    Sleep(2000);
    while (true) {
    system(E("cls"));
    std::cout << (E("How would you like the spoof"));
    std::cout << (E("\n\n[1] normal\n[2] asus\n[3] efi\n\nchoise: "));
    std::cin >> idkanymore;
    switch(idkanymore){
    case 1:
        normalspoof();
        system(E("cls"));
        std::cout << (E("Spoofed successfully"));
        Sleep(2000);
        system(E("cls"));
        break;
    case 2:
        asusspoof();
        system(E("cls"));
        std::cout << (E("Spoofed successfully"));
        Sleep(2000);
        system(E("cls"));
        break;
    case 3:
        efispoof();
        system(E("cls"));
        std::cout << (E("successfully written efi files\n\n\nmove the files inside the folder usb to your usb driver then just boot on ur usb"));
        Sleep(5000);
        system(E("cls"));
        break;
    }
}
}