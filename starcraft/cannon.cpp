#include <string.h>
#include <iostream>

class Photon_Cannon {
    int hp, shield;
    int coord_x, coord_y;
    int damage;

    public: 
        Photon_Cannon(int x, int y);
        Photon_Cannon(const Photon_Cannon& pc);

        void show_status();
};
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
    std::cout << "복사 생성자 호출!" << std::endl;
    hp = pc.hp;
    
}