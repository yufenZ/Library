//
//  book.h
//  Library
//  书籍类
//  Created by yufenZ on 2020/3/18.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef book_h
#define book_h

#include <iostream>
#include <ctime>
#include <iomanip>
#include "date.h"
using namespace std;

class book{
private:
    int bookId; //图书编号
    string bookName; //书名
    string author; //作者
    date dat; //出版日期
    int num; //库存数量
    int renum; //续借次数，最多一次
    string startDate; // 出借日期
    string endDate;  // 归还日期
public:
    //构造函数
    book(){
        bookId = 0;
        bookName = "NULL";
        author = "NULL";
        dat;
        num = 3;
        renum = 0;
    }
    book(int bookId, string bookName, string author, date dat){
        this->bookId = bookId;
        this->bookName = bookName;
        this->author = author;
        this->dat = dat;
        num = 3;
        renum = 0;
    }
    //获取图书信息函数
    int getId(){return bookId;}
    string getBookName(){return bookName;}
    string getAuthor(){return author;}
    date getDate(){return dat;}
    int getNum(){return num;}
    int getRenum(){return renum;}
    //设置图书信息
    void setId(int bookid){bookId = bookid;}
    void setBookName(string name){bookName = name;}
    void setAuthor(string author){this->author = author;}
    void setDate(date dat){this->dat = dat;}
    void setNum(int num){this->num = num;}
    void setRenum(int renum){this->renum = renum;}
    //获取系统时间作为借书时间
    string getStartDate(){
        time_t t = time(0);
        char tmp[11];
        strftime(tmp, sizeof(tmp), "%Y %m %d", localtime(&t));
        return tmp;
    }
    //显示日期函数
    void printdate(){}
    
    // 显示函数
    void show(bool x){
        if(x){
            cout<<setw(10)<<"编号"<<setw(10)<<"书名"<<setw(10)<<"作者"<<setw(10)<<"出版日期"<<setw(6)<<"库存"<<setw(10)<<"续借"<<setw(12)<<"借阅时间"<<setw(10)<<"应还日期"<<endl;
            cout<<setw(10)<<this->bookId<<setw(10)<<this->bookName<<setw(10)<<this->author<<setw(6)<<this->dat<<setw(6)<<this->num<<setw(6)<<this->renum<<"    "<<setw(6)<<getStartDate()<<"  ";
            printdate();
            cout<<endl;
            cout<<endl;
        }
        else{
            cout<<setw(10)<<"编号"<<setw(10)<<"书名"<<setw(10)<<"作者"<<setw(10)<<"出版日期"<<setw(6)<<" 库存 "<<setw(6)<<"续借次数"<<endl;
            cout<<setw(10)<<this->bookId<<setw(10)<<this->bookName<<setw(10)<<this->author<<setw(6)<<this->dat<<setw(6)<<this->num<<setw(6)<<this->renum<<endl;
            cout<<endl;
        }
    }
    //重载赋值运算符
    void operator=(const book &x){
        bookId = x.bookId;
        bookName = x.bookName;
        author = x.author;
        dat = x.dat;
        num = x.num;
        renum = x.renum;
    }
};

#endif /* book_h */
