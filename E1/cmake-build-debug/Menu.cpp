//
// Created by pskowronski on 07.03.2020.
//

#include "../headers/Menu.h"
#include "../headers/BSTTree.h"
#include "../headers/MyHeap.h"
#include "../headers/MyArray.h"
#include "../headers/MyList.h"
#include <string>
#include <iostream>
#include <ctime>
#include<unistd.h>

#define RANGE 100

void Menu::set_subMenu(std::string option1, std::string option2) {
    subMenu = "";
    subMenu.append("----------------------------------\n");
    subMenu.append("1.Generuj losowo\n");
    subMenu.append("2.Wczytaj z pliku\n");
    subMenu.append("----------------------------------\n");
    subMenu.append("Operacje na strukturze: 		   \n\n");
    subMenu.append("3.Dodaj\n");
    subMenu.append("4.Usun\n");
    subMenu.append("5.Znajdz\n");
    subMenu.append(option1);
    subMenu.append(option2);
    subMenu.append("----------------------------------\n");
}

void Menu::show_menu() {
    std::cout << menu;
}

void Menu::show_subMenu() {
    std::cout << subMenu;
}

void Menu::enable() {
    std::string file;
    int select1 = 0;
    int select2 = 0;
    int buffer1 = 0;
    int buffer2 = 0;
    bool mainLoop = true;
    bool innerLoop;

    while (mainLoop) {
        innerLoop = true;
        this->show_menu();
        std::cout << "Wybor> ";
        std::cin >> select1;
        switch (select1) {
            case 1: {
                set_subMenu("6.Powrot\n", "");
                while (innerLoop) {
                    std::cout << myArray->toString();
                    show_subMenu();
                    std::cout << "Wybor> ";
                    std::cin >> select2;
                    switch (select2) {
                        case 1: {
                            myArray->clear();
                            std::cout << "Rozmiar> ";
                            std::cin >> buffer1;
                            srand(time(NULL));
                            for (int i = 0; i < buffer1; i++)
                                myArray->addAtTail(rand() % RANGE);
                            break;
                        }
                        case 2: {
                            std::cin.ignore();
                            std::cout << "Nazwa pliku> ";
                            std::cin >> file;
                            myArray->readFromFile(file);
                            break;
                        }
                        case 3: {
                            std::cout << "Indeks> ";
                            std::cin >> buffer1;
                            std::cout << "Wartosc> ";
                            std::cin >> buffer2;
                            myArray->addAtIndex(buffer1, buffer2);
                            break;
                        }
                        case 4: {
                            std::cout << "Indeks> ";
                            std::cin >> buffer1;
                            myArray->deleteAtIndex(buffer1);
                            break;
                        }
                        case 5: {
                            std::cout << "Wartosc> ";
                            std::cin >> buffer1;
                            if (myArray->isInArray(buffer1))
                                std::cout << "Jest w tablicy\n";
                            else
                                std::cout << "Nie ma w tablicy\n";
                            break;
                        }
                        case 6: {
                            innerLoop = false;
                            break;
                        }
                        default: {
                            std::cout << "Niepoprawny wybor\n";
                            break;
                        }
                    }
                }
                break;
            }
            case 2: {
                set_subMenu("6.Powrot\n", "");
                while (innerLoop) {
                    std::cout << list->toString();
                    show_subMenu();
                    std::cout << "Wybor> ";
                    std::cin >> select2;
                    switch (select2) {
                        case 1: {
                            list->clear();
                            std::cout << "Rozmiar> ";
                            std::cin >> buffer1;
                            srand(time(NULL));
                            for (int i = 0; i < buffer1; i++)
                                list->addAtTail(rand() % RANGE);
                            break;
                        }
                        case 2: {
                            std::cout << "Nazwa pliku> ";
                            std::cin >> file;
                            if (list->readFromFile(file))
                                std::cout << "Pomyslnie wczytano\n";
                            else
                                std::cout << "Blad odczytu pliku\n";
                            break;
                        }

                        case 3: {
                            std::cout << "Indeks> ";
                            std::cin >> buffer1;
                            std::cout << "Wartosc> ";
                            std::cin >> buffer2;
                            if (list->insertAtIndex(buffer1, buffer2))
                                std::cout << "Dodano element\n";
                            else
                                std::cout << "Indeks poza zakresem!\n";
                            break;
                        }
                        case 4: {
                            std::cout << "Wartosc> ";
                            std::cin >> buffer1;
                            if (list->deleteByValue(buffer1))
                                std::cout << "Usunieto element\n";
                            else
                                std::cout << "Nie ma w liscie\n";
                            break;
                        }
                        case 5: {
                            std::cout << "Wartosc> ";
                            std::cin >> buffer1;
                            if (list->getNodeByValue(buffer1) != nullptr)
                                std::cout << "Jest w liscie\n";
                            else
                                std::cout << "Nie ma w liscie\n";
                        }
                            break;

                        case 6: {
                            innerLoop = false;
                            break;
                        }
                        default: {
                            std::cout << "Niepoprawny wybor\n";
                            break;
                        }
                    }
                }
                break;
            }
            case 3: {
                set_subMenu("6.Powrot\n", "");
                while (innerLoop) {
                    std::cout << heap->toString();
                    show_subMenu();
                    std::cout << "Wybor> ";
                    std::cin >> select2;
                    switch (select2) {
                        case 1: {
                            heap->clear();
                            std::cout << "Rozmiar> ";
                            std::cin >> buffer1;
                            srand(time(NULL));
                            for (int i = 0; i < buffer1; i++)
                                heap->push(rand() % RANGE);
                            break;
                        }
                        case 2: {
                            std::cout << "Nazwa pliku> ";
                            std::cin >> file;
                            if (heap->readFromFile(file))
                                std::cout << "Pomyslnie wczytano\n";
                            else
                                std::cout << "Blad odczytu pliku\n";
                            break;
                        }
                        case 3: {
                            std::cout << "Klucz> ";
                            std::cin >> buffer1;
                            heap->push(buffer1);
                            std::cout << "Dodano element\n";
                            break;
                        }
                        case 4: {
                            std::cout << "Klucz> ";
                            std::cin >> buffer1;
                            if (heap->getIndex(buffer1 != -1)) {
                                heap->pop(buffer1);
                                std::cout << "Usunieto element\n";
                            } else
                                std::cout << "Nie ma takiego elementu w kopcu!\n";
                            break;
                        }
                        case 5: {
                            std::cout << "Wartosc> ";
                            std::cin >> buffer1;
                            if (heap->getIndex(buffer1) != -1)
                                std::cout << "Jest w kopcu\n";
                            else
                                std::cout << "Nie ma w kopcu\n";
                            break;
                        }
                        case 6: {
                            innerLoop = false;
                            break;
                        }
                        default: {
                            std::cout << "Niepoprawny wybor\n";
                            break;
                        }
                    }
                }
                break;
            }
            case 4: {
                //system("clear");
                set_subMenu("6.Rownowazenie DSW\n", "7.Powrot\n");
                while (innerLoop) {
                    std::cout << tree->toString();
                    show_subMenu();
                    std::cout << "Wybor> ";
                    std::cin >> select2;
                    switch (select2) {
                        case 1: {
                            tree->clear();
                            std::cout << "Rozmiar> ";
                            std::cin >> buffer1;
                            srand(time(NULL));
                            for (int i = 0; i < buffer1; i++)
                                tree->addNode(rand() % RANGE);
                            break;
                        }
                        case 2: {
                            std::cout << "Nazwa pliku> ";
                            std::cin >> file;
                            if (tree->readFromFile(file))
                                std::cout << "Pomyslnie wczytano\n" << std::endl;
                            else
                                std::cout << "Blad odczytu pliku\n" << std::endl;
                            break;
                        }
                        case 3: {
                            std::cout << "Klucz> ";
                            std::cin >> buffer1;
                            tree->addNode(buffer1);
                            std::cout << "Dodano element\n";
                            break;
                        }
                        case 4: {
                            std::cout << "Klucz> ";
                            std::cin >> buffer1;
                            if (tree->findNode(buffer1)) {
                                tree->deleteNode(tree->findNodePtr(buffer1));
                                std::cout << "Usunieto element\n";
                            } else
                                std::cout << "Nie ma w drzewie\n";
                            break;
                        }
                        case 5: {
                            std::cout << "Wartosc> ";
                            std::cin >> buffer1;
                            if (tree->findNode(buffer1))
                                std::cout << "Jest w drzewie\n";
                            else
                                std::cout << "Nie ma w drzewie\n";
                            break;
                        }
                        case 6: {
                            tree->dswBalancing();
                            std::cout << "Rownowazenie\n";
                            break;
                        }
                        case 7: {
                            innerLoop = false;
                            break;
                        }
                        default: {
                            std::cout << "Niepoprawny wybor\n";
                            break;
                        }
                    }
                }
                break;
            }
            case 5: {
                mainLoop = false;
                break;
            }
            default: {
                std::cout << "Niepoprawny wybor\n";
                break;
            }
        }
    }
}

Menu::Menu() {
    myArray = new MyArray();
    list = new MyList();
    heap = new MyHeap(150);
    tree = new BSTTree();
    menu.append("----------------------------------\n");
    menu.append("-------- STRUKTURY DANYCH --------\n");
    menu.append("----------------------------------\n");
    menu.append("MENU\n");
    menu.append("----------------------------------\n");
    menu.append("Wybor badanej struktury: 		   \n\n");
    menu.append("1.Tablica\n");
    menu.append("2.Lista\n");
    menu.append("3.Kopiec binarny\n");
    menu.append("4.Drzewo BST\n");
    menu.append("5.Zakoncz\n");
    menu.append("----------------------------------\n");
    set_subMenu("", "");
}

Menu::~Menu() {
}