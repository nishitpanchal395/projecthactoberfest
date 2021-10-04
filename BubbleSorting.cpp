//C++ Bubble Sort
#include <iostream>
#include <vector>

using namespace std;

class Sort{
private:

vector<int> privateList;

public:


    //Constructor
    Sort::Sort(vector<int> list){
    
        //Copy vector into private member        
        for(int i = 0; i < list.size(); i ++){
            privateList.at(i) = list.at(i);
        }
    }

    //Sorting
    void Sort::bubbleSort(vector<int> &list){
        
        for(int i = 0; i < list.size(); i++){
            for (int j = (i + 1); j < list.size(); ++j) {


                if(list.at(i) > list.at(j)){
                    
                    int temp;

                    temp = list.at(i);
                    list.at(i) = list.at(j);
                    list.at(j) = temp;

                }
            }
        }
    }

    //Simple print method
    void Sort::print(vector<int> list){

        for(int i = 0; i < list.size(); i++){

            cout << list.at(i) << " ";

        }

    }


};