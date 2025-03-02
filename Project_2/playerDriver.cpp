#include "Player.h"

using namespace std;

int main(){
    Player p("Simba", 100, 100, 100, 0, 1);
    p.selectAdvisor(0);
    cout << p.getAdvisor() << endl;
    


   
    return 0;
}