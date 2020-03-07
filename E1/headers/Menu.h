//
// Created by pskowronski on 07.03.2020.
//

#ifndef E1_MENU_H
#define E1_MENU_H

#include <string>
#include "MyArray.h"
#include "MyList.h"
#include "MyHeap.h"
#include "BSTTree.h"

class Menu {
private:
    std::string menu;
    std::string subMenu;
    MyArray * myArray;
    MyList * list;
    MyHeap *heap;
    BSTTree *tree;

    void set_subMenu(std::string option1, std::string option2);
    void show_menu();
    void show_subMenu();

public:
    void enable();
    Menu();
    ~Menu();
};


#endif //E1_MENU_H
