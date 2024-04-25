#include <iostream>
#include <cstdlib>
#include <ctime>   
using namespace std;

int main() {
    
    srand(time(nullptr));

  
    int daysUntilExpiration = rand() % 12;

    
    cout << "Days until expiration: " << daysUntilExpiration << endl;

   
    if (daysUntilExpiration <= 0) {
        cout << "Your subscription has already expired." << endl;
    } else if (daysUntilExpiration == 1) {
        cout << "Your subscription expires tomorrow! Renew now and save 20%!" << endl;
    } else if (daysUntilExpiration <= 5) {
        cout << "Your subscription expires in " << daysUntilExpiration << " days. Renew now and save 10%!" << endl;
    } else if (daysUntilExpiration <= 10) {
        cout << "Your subscription will expire in less than 10 days. Renew now!" << endl;
    } else {
        cout << "You have an active subscription. Enjoy!" << endl;
    }

    return 0;
}
