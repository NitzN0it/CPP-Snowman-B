//
// Created by nitzan on 08/03/2021.
//
#include <string>
#include "snowman.hpp"
#include <array>
#include <stdexcept>
#include <iostream>
#include <cmath>

using namespace std;
namespace ariel {
    const array<string,4> hats = {"_===_","  ___ \n .....", "  _\n  /_\\"," ___\n (_*_)"};
    const array<string,4> eyes = {".","o","O","-"};
    const array<string,4> nose = {",",".","_"," "};
    const array<string,4> left_arm_upwards = {" ","\\"," "," "};
    const array<string,4> left_arm = {"<"," ","/"," "};
    const array<string,4> right_arm_upwards = {" ","/"," "," "};
    const array<string,4> right_arm = {">"," ","\\"," "};
    const array<string,4> torsos = {" : ", "] [","> <", "   "};
    const array<string,4> bases = {" : ", "\" \"", "___","   "};
    const int HAT=0,NOSE=1,LEFT_EYE=2,RIGHT_EYE=3,LEFT_ARM=4,RIGHT_ARM=5,TORSO=6,BASE=7,INPUT_SIZE = 8,MAX_SNOWMAN_SIZE=44444444,MIN_SNOWMAN_SIZE=11111111,NEXT_PART=10;
    array<int,INPUT_SIZE> snow_man_arr = {};

    void int_to_arr(int man){
        for (int i = INPUT_SIZE-1; i >= 0; i--) {
            snow_man_arr.at(i) = man%NEXT_PART -1;
            man /= NEXT_PART;
        }
    }
    string face()
    {
        return left_arm_upwards.at(snow_man_arr.at(LEFT_ARM))+"("+eyes.at(snow_man_arr.at(LEFT_EYE))+nose.at(snow_man_arr.at(NOSE))+eyes.at(snow_man_arr.at(RIGHT_EYE))+")"+right_arm_upwards.at(snow_man_arr.at(RIGHT_ARM));

    }
    string body()
    {
        return left_arm.at(snow_man_arr.at(LEFT_ARM))+"("+torsos.at(snow_man_arr.at(TORSO))+")"+right_arm.at(snow_man_arr.at(RIGHT_ARM));
    }
    void validate_input(int man)
    {
        int size =(int) log10(man) +1;
        if (size < INPUT_SIZE) {
            throw std::invalid_argument("Too short");
        }
        if (size > INPUT_SIZE){
            throw std::out_of_range("Too long");
        }
        for (int i = 0; i < INPUT_SIZE; i++) {
                if ((man%NEXT_PART < 1) || (man%NEXT_PART > 4)) {
                    throw std::out_of_range("Not an option");
                }
                man /= NEXT_PART;
        }
    }
    string snowman(int man) {
        validate_input(man);
        int_to_arr(man);
        string snowman_str = hats.at(snow_man_arr.at(HAT)); // Hat
        snowman_str += "\n"+face(); // Face
        snowman_str += "\n"+body(); // Body(arms + torso)
        snowman_str += "\n ("+bases.at(snow_man_arr.at(BASE))+") "; // Base
        return snowman_str;
    }
}