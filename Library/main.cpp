//
//  main.cpp
//  Library
//
//  Created by yufenZ on 2020/3/17.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#include <iostream>
#include "date.h"
using namespace std;

int main(int argc, const char * argv[]) {
    date D1(2019, 4), D2;
    cout<<"D1的年份："<<D1.getYear()<<"\tD1的月份:"<<D1.getMonth()<<endl;
    D1.setYear(2018);
    D1.setMonth(7);
    cout<<"D1的年份："<<D1.getYear()<<"\tD1的月份:"<<D1.getMonth()<<endl;
    
    cout<<"please input the date D2:"<<endl;
    cin>>D2;
    cout<<D2;
    return 0;
}
