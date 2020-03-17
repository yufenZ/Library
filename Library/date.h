//
//  date.h
//  Library
//  日期类,包含年和月
//  Created by yufenZ on 2020/3/17.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef date_h
#define date_h
#include <iostream>
using namespace std;

class date{
private:
    int year;
    int month;
public:
    //构造函数
    date(){
        year = 0;
        month = 0;
    }
    date(int y, int m){
        year = y;
        month = m;
    }
    //析构函数
    ~date(){}
    //返回年份
    int getYear(){return year;}
    //返回月份
    int getMonth(){return month;}
    //设置年份
    void setYear(int y){year = y;}
    //设置月份
    void setMonth(int m){month = m;}
    //显示日期
    void showDate(){
        cout<<year<<"年"<<month<<"月"<<endl;
    }
    //重载输入运算符
    friend istream &operator>>(istream &input, date &x){
        input>>x.year>>x.month;
        return input;
    }
    //重载输出运算符
    friend ostream &operator<<(ostream &output, const date &x){
        output<<x.year<<"  "<<x.month;
        return output;
    }
};

#endif /* date_h */
