#include <iostream>
using namespace std;

typedef struct Animal {
    char name[30]; //dlfma
    int age; // 나이
    int health; // 체력
    int food; // 배부른 정도
    int clean; // 깨끗한 정도
} Animal;

void create_animal(Animal *animal) {
    cout << "동물의 이름? ";
    cin >> animal->name;
    cout << "동물의 나이? ";
    cin >> animal->age;
    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;
}

void play(Animal *animal) {
  animal->health += 10;
  animal->food -= 20;
  animal->clean -= 30;
}
void one_day_pass(Animal *animal) {
  // 하루가 지나면
  animal->health -= 10;
  animal->food -= 30;
  animal->clean -= 20;
}
void show_stat(Animal *animal) {
  std::cout << animal->name << "의 상태" << std::endl;
  std::cout << "체력    : " << animal->health << std::endl;
  std::cout << "배부름 : " << animal->food << std::endl;
  std::cout << "청결    : " << animal->clean << std::endl;
}

int main()
{
    Animal *list[10];
    int animal_num = 0;
    for(;;) {
        int play_with;
        cout << "1. 동물 추가하기 " << endl;
        cout << "2. 놀기 " << endl;
        cout << "3. 상태 보기" << endl;

        int input;
        cin >> input;

        switch(input) {
            case 1: 
                list[animal_num] = new Animal;
                create_animal(list[animal_num]);
                animal_num++;
                break;
             case 2:
                 std::cout << "누구랑 놀게? : ";
                 std::cin >> play_with;

                 if (play_with < animal_num) play(list[play_with]);

                    break;
             case 3:
                std::cout << "누구껄 보게? : ";
                std::cin >> play_with;
                if (play_with < animal_num) show_stat(list[play_with]);
                break;

            }
            for(int i = 0; i != animal_num; i++) {
                one_day_pass(list[i]);
            }
    }
    for(int i = 0; i != animal_num; i++) {
        delete list[i];
    }
}