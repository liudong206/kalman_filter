#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream> 
#include "kalman_filter.h"
using namespace std;

int main()
{
    kalman_state state; 
    kalman_init(&state,0.0,1000.0);
    char c[10];
    ifstream inFile("log/tarSteerWheelAngle.xls", ios::in | ios::binary);
    ofstream outFile("log/tarSteerWheelAngle_filter.xls",std::ios::app);
    if (!inFile) {
        cout << "open file error" << endl;
        return 0;
    }
    //连续以行为单位，读取 in.txt 文件中的数据
    while (inFile.getline(c, 320)) {
        float ret = strtol(c,NULL,10);
        float out = kalman_filter(&state,ret);
        if(!outFile.fail()){
            outFile<<out<<endl;
        }
        else {
            cout<<"open failed"<<endl;
        }
    }
    inFile.close();
    cout<<"kalman filter is finished"<<endl;
    return 1;
}
