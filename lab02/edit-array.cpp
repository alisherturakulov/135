/*
Author: Alisherjon Turakulov
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab2C

1. Initialize an array of integers with a default value of 1; 
2. prints all elemnts of the array;
3. asks user for inputs: index i, and new value v
4. if the index if valid it changes it to v
5. return to step 3, and stops the loop if i is not a valid index
*/

#include <iostream>

int main(){
    int arr[10];
    for(int i = 0; i < 10; i++){
        arr[i] = 1;
    }
    int ind{}, v{1};//not necessary in do-while but
    //  is for a while loop (where changing would be before printing)
    do{
        arr[ind] = v;//put here to make sure index runs through condition
        for(int i=0; i< 10; i++){
            if(i == 0){ //no space before first item
                std::cout << arr[i];
            }else{ //adds spaces between subsequent items
                std::cout << " " << arr[i];
            }          
        }
        std::cout << "\nInput index: ";//takes input for index and value
        std::cin >> ind;
        std::cout << "Input value: ";
        std::cin >> v;
    }while(ind >= 0 && ind < 10);
    std::cout << "Index out of range. Exit." << std::endl;

    return 0;
}