/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: E9.3 

implements a member functions of a switch class to interact with a light switch
*/

#include <iostream>
#include <string>


class Circuit {
	public:
		int get_first_switch_state();
		int get_second_switch_state();
		int get_lamp_state();
		void toggle_first_switch();
		void toggle_second_switch();
	private:
		int first_switch = 0;
		int second_switch = 0;
		int lamp_state = 0;
};

		int Circuit::get_first_switch_state(){ // 0 for down, 1 for up
			return first_switch;
		}
		int Circuit::get_second_switch_state(){
			return second_switch;
		}
		int Circuit::get_lamp_state(){ // 0 for off, 1 for on
			return lamp_state;
		}
		void Circuit::toggle_first_switch(){
			if(first_switch == 0){
				first_switch = 1;
				lamp_state = !lamp_state;
			}else{
				first_switch = 0;
				lamp_state = !lamp_state;
			}
			
		}
		void Circuit::toggle_second_switch(){
			if(second_switch == 0){
				second_switch = 1;
				lamp_state = !lamp_state;
			}else{
				second_switch = 0;
				lamp_state = !lamp_state;
			}
		}