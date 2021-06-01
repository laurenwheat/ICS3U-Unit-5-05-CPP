// Copyright (c) 2021 Lauren Wheatley All rights reserved.
//
// Created by: Lauren Wheatley
// Created on: May 2021
// This program adds numbers

#include <iostream>
#include <algorithm>
#include <string>

std::string Billing(std::string name, std::string strNum,
                    std::string strName, std::string city,
                    std::string prov, std::string postCode,
                    std::string aptNum = "") {
    std::string regAddy;

    regAddy = name;
    if (aptNum != "") {
        regAddy = (regAddy + "\n" + aptNum + "-" + strNum +
                        " " + strName + "\n" + city + " " + prov + "  "
                        + postCode);
    } else {
        regAddy = (regAddy + "\n" + strNum +
                        " " + strName + "\n" + city + " " + prov + "  "
                        + postCode);
    }
    std::transform(regAddy.begin(), regAddy.end(), regAddy.begin(),
                   ::toupper);

    return regAddy;
}


main() {
    std::string name;
    std::string question;
    std::string aptNum = "";
    std::string strNum;
    std::string strName;
    std::string city;
    std::string prov;
    std::string postCode;
    std::string address;

    std::cout << "Enter your full name: ";
    std::getline(std::cin, name);
    std::cout << "Do you live in an apartment? (y/n): ";
    std::getline(std::cin, question);
    if (question == "y" || question == "yes") {
        std::cout << "Enter your apartment number: ";
        std::getline(std::cin, aptNum);
    }
    std::cout << "Enter your street number: ";
    std::getline(std::cin, strNum);
    std::cout << "Enter your street name: ";
    std::getline(std::cin, strName);
    std::cout << "Enter your city: ";
    std::getline(std::cin, city);
    std::cout << "Enter your province as 2 letters";
    std::getline(std::cin, prov);
    std::cout << "Enter your postal code:";
    std::getline(std::cin, postCode);
    std::cout << "" << std::endl;

    if (aptNum != "") {
        address = Billing(name, strNum, strName, city, prov, postCode,
                          aptNum);
    } else {
        address = Billing(name, strNum, strName, city, prov, postCode);
    }
    std::cout << address << std::endl;
}
