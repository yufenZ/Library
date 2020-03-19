//
//  user.h
//  Library
//
//  Created by yufenZ on 2020/3/19.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef user_h
#define user_h

#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <iomanip>
#include "book.h"
using namespace std;

class user{
private:
    long long int stdId; //学号
    string stdName;  //姓名
    string password;  //密码
    int bookNum; //借阅数目
    vector<book> userBook; //存放用户借的图书
    vector<book>::iterator ubIter; //用户所借图书迭代器
    vector<book> libraryBook; //文件读写容器，相当于图书馆
    vector<book>::iterator lbIter; //图书馆图书迭代器
    multimap<string, int> m1; //根据书名查找
    multimap<string, int>::iterator mit1; //根据书名查找对应的迭代器
    multimap<string, int> m2; //根据作者查找
    multimap<string, int>::iterator mit2; //根据作者查找对应的迭代器
    multimap<string, int> m3; //根据出版日期查找
    multimap<string, int>::iterator mit3; //根据出版日期查找对应的迭代器
public:
    //构造函数
    user(){
        stdId = 0;
        stdName = "NULL";
        password = "123";
        bookNum = 0;
    }
    user(long long stdId, string stdName, string password){
        this->stdId = stdId;
        this->stdName = stdName;
        this->password = password;
        bookNum = 0;
    }
    //get函数
    long long getId(){return stdId;}
    string getName(){return stdName;}
    string getPassword(){return password;}
    int getBooknum(){return bookNum;}
    //set函数
    void setId(long long stdId){this->stdId = stdId;}
    void setName(string stdName){this->stdName = stdName;}
    void setPassword(string password){this->password = password;}
    void setBooknum(int bookNum){this->bookNum = bookNum;}
    //验证密码
    bool isPassword(string x){
        return password == x;
    }
    //重载输入运算符
    friend istream &operator>>(istream &input, user &std){
        input>>std.stdId>>std.stdName>>std.password;
        return input;
    }
    //重载输出运算符
    friend ostream &operator<<(ostream &output, const user &std){
        output<<std.stdId<<"  "<<std.stdName<<"  "<<std.password;
        return output;
    }
    //显示函数
    void print(){
        cout<<setw(10)<<"学号"<<setw(10)<<"姓名"<<setw(10)<<"借阅数量"<<endl;
        cout<<setw(10)<<stdId<<setw(10)<<stdName<<setw(10)<<bookNum<<endl;
        if(bookNum){
            for(ubIter=userBook.begin(); ubIter!=userBook.end(); ubIter++){
                ubIter->show(1);
            }
        }
    }
    //借阅图书  需要实现查询是否有库存
    void borrowBook(int x){
        userBook.push_back(libraryBook[x-1]);
        userBook[bookNum].setId(bookNum+1);
        bookNum ++;
        int i = libraryBook[x-1].getId()-1;
        int j = libraryBook[x-1].getNum()-1;
        userBook[i].setNum(j);
        userBook[i].setRenum(1);
    }
    //续借图书
    void reBorrowBook(){
        print();
        cout<<"请输入你要续借的图书编号："<<endl;
        int x;
        cin>>x;
        if(userBook[x-1].getRenum() == 1){
            userBook[x-1].show(1);
            cout<<endl;
            cout<<"续借成功"<<endl;
            userBook[x-1].setRenum(0);
        }
        else{
            cout<<"很抱歉，此书续借次数已用完"<<endl;
        }
    }
    //归还图书
    void returnBook(int x){
        if(userBook.empty())
            cout<<"该用户没有借阅图书"<<endl;
        else{
            ubIter = userBook.begin()+x-1;
            userBook.erase(ubIter);
            bookNum --;
            int i = libraryBook[x-1].getId()-1;
            int j = libraryBook[x-1].getNum()+1;
            userBook[i].setNum(j);
            cout<<"归还图书成功！"<<endl;
        }
    }
    //查询图书馆中的图书
    //根据书名查找
    void seaByBookname(string name){
        mit1 = m1.find(name);
        int num = m1.count(name);
        if(mit1 == m1.end())
            cout<<"未找到该图书，请检查书名是否正确"<<endl;
        else{
            cout<<"你查找的图书信息如下："<<endl<<endl;
            while(num>0) {
                int temp = mit1->second;
                libraryBook[temp-1].show(0);
                mit1 ++;
                num --;
            }
        }
    }
    //根据作者查找
    void seaByAuthor(string au){
        mit2 = m2.find(au);
        int num = m2.count(au);
        if(mit2 == m2.end())
            cout<<"未找到图书，请检查作者是否正确"<<endl;
        else{
            cout<<"你要找的图书的信息如下:"<<endl;
            while(num > 0){
                int temp = mit2->second;
                libraryBook[temp-1].show(0);
                mit2 ++;
                num --;
            }
        }
    }
    //保存用户借阅图书文件
    void save(){
        ofstream outfile;
        outfile.open("userborrow.txt", ios::out);
        if(!outfile)
            cout<<"Error!保存文件失败！"<<endl;
        else{
            for(ubIter = userBook.begin(); ubIter!=userBook.end(); ubIter++)
                outfile<<&ubIter<<endl;
        }
        outfile.close();
        userBook.clear();
        libraryBook.clear();
        m1.clear();
        m2.clear();
        m3.clear();
    }
};

#endif /* user_h */
