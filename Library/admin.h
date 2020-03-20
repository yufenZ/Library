//
//  admin.h
//  Library
//  管理员类
//  Created by yufenZ on 2020/3/20.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef admin_h
#define admin_h

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "date.h"
#include "user.h"
#include "book.h"
using namespace std;

class admin{
private:
    string password;
    date dat;
    vector<user> uall;//所有用户
    vector<user>::iterator uit;//所有用户对应的迭代器
    vector<book> bookAll;//所有图书
    vector<book>::iterator bit;//所有图书对应的迭代器
    multimap<string, int> m1;//根据书名查找，<书名， 下标>
    multimap<string, int>::iterator mit1;
    multimap<string, int> m2;//根据作者查找，<作者， 下标>
    multimap<string, int>::iterator mit2;
    multimap<int, int> m3;//根据出版日期查找，<出版日期，下标>
    multimap<int, int>::iterator mit3;
    map<long long int, string> m4;//按学号查找
    map<long long int, string>::iterator mit4;
    map<string, long long int> m5; //按姓名查找
    map<string, long long int>::iterator mit5;
public:
    //构造函数
    admin(){
        password = "123";
    }
    admin(string password){
        this->password = password;
    }
    //修改密码
    void setPassword(string password){
        this->password = password;
    }
    //验证密码
    bool isPassword(string password){
        return this->password == password;
    }
    //读取user文件
    void readUser(){
        uall.clear();
        m4.clear();
        m5.clear();
        ifstream infile;
        infile.open("user.txt", ios::in); //只读形式打开文件
        user temp;
        if(!infile)
            cout<<"Error!读取文件失败"<<endl;
        else{ //更新uall,m4,m5
            while(infile>>temp){
                uall.push_back(temp);
                m4.insert(make_pair(temp.getId(), temp.getName()));
                m5.insert(make_pair(temp.getName(), temp.getId()));
            }
        }
        infile.close();
    }
    //保存user文件
    void saveUser(){
        ofstream outfile;
        outfile.open("user.txt", ios::app);
        if(!outfile)
            cout<<"Error!保存文件失败"<<endl;
        else{
            for(uit=uall.begin(); uit!=uall.end(); uit++){
                outfile<<uit->getId()<<" "<<uit->getName()<<" "<<uit->getPassword()<<endl;
            }
        }
        outfile.close();
        uall.clear();
        m4.clear();
        m5.clear();
    }
    //读取book文件
    void readBook(){
        uall.clear();
        m1.clear();
        m2.clear();
        m3.clear();
        ifstream infile;
        infile.open("book.txt", ios::in); //只读形式打开文件
        book temp;
        if(!infile)
            cout<<"Error!读取文件失败"<<endl;
        else{ //更新bookAll,m1,m2,m3
            while(infile>>temp){
                bookAll.push_back(temp);
                m1.insert(make_pair(temp.getBookName(), temp.getId()));
                m2.insert(make_pair(temp.getAuthor(), temp.getId()));
                m3.insert(make_pair(temp.getDate().getYear(), temp.getId()));
            }
        }
        infile.close();
    }
    //保存book文件
    void saveBook(){
        ofstream outfile;
        outfile.open("book.txt", ios::app);
        if(!outfile)
            cout<<"Error!保存文件失败"<<endl;
        else{
            for(bit=bookAll.begin(); bit!=bookAll.end(); uit++){
                outfile<<bit->getId()<<" "<<bit->getBookName()<<" "<<bit->getAuthor()<<" "<<bit->getDate()<<endl;
            }
        }
        outfile.close();
        bookAll.clear();
        m1.clear();
        m2.clear();
        m3.clear();
    }
    //增加图书
    void addBook(){
        book temp;
        cout<<"请输入书籍信息：编号，书名，作者，出版日期xxxx年xx月"<<endl;
        cin>>temp;
        bookAll.push_back(temp);
        cout<<"书籍添加成功"<<endl;
    }
    //删除书籍
    void delBook(){
        if(bookAll.empty())
            cout<<"Error!书库中没有书籍"<<endl;
        else{ //获取书籍中所有书的编号 ；改进：通过查找确定书的编号
            for(bit=bookAll.begin(); bit!=bookAll.end(); bit++){
                bit->show(0);
            }
            cout<<endl;
            cout<<"请输入要删除的书籍的编号："<<endl;
            int x;
            cin>>x;
            //定位到书籍的位置
            bit = bookAll.begin()+x-1;
            cout<<*bit<<endl;//打印书籍信息确认
            bookAll.erase(bit);//从所有图书中删除选中图书
            cout<<"书籍删除成功"<<endl;
        }
    }
    //查找图书
    //按书名查找
    void seaByBookname(string bookName){
        mit1 = m1.find(bookName);
        int num = m1.count(bookName);
        if(mit1 == m1.end())
            cout<<"未找到该图书，请检查书名是否正确"<<endl;
        else{
            cout<<"你要查找的图书信息如下："<<endl;
            while(num>0){
                int temp = mit1->second;
                bookAll[temp-1].show(0);
                mit1 ++;
                num --;
            }
        }
    }
    //按作者查找
    void seaByAuthor(string author){
        mit2 = m2.find(author);
        int num = m2.count(author);
        if(mit2 == m2.end())
            cout<<"未找到该图书，请检查图书作者是否正确"<<endl;
        else{
            cout<<"你要查找的图书信息如下："<<endl;
            while(num>0){
                int temp = mit2->second;
                bookAll[temp-1].show(0);
                mit2 ++;
                num --;
            }
        }
    }
    //按出版日期查找
    void seaByDate(int x){
        mit3 = m3.find(x);
        int num = m3.count(x);
        if(mit3 == m3.end())
            cout<<"未找到该图书，请检查图书出版日期是否正确"<<endl;
        else{
            while(num>0){
                cout<<"你要查找的图书的信息如下："<<endl;
                int temp = mit3->second;
                bookAll[temp-1].show(0);
                mit3 ++;
                num --;
            }
        }
    }
    //添加用户
    void addUser(){
        cout<<"请输入要创建的用户的信息：[学号 姓名 密码]"<<endl;
        user temp;
        cin>>temp;
        uall.push_back(temp);
        m4.insert(make_pair(temp.getId(), temp.getName()));
        m5.insert(make_pair(temp.getName(), temp.getId()));
        cout<<"成功添加用户:"<<temp<<endl;
    }
    //删除用户
    void delUser(){
        for(mit4 = m4.begin(); mit4!=m4.end(); mit4++){
            cout<<" "<<mit4->first<<" "<<mit4->second<<endl;
        }
        cout<<"请输入要删除的用户学号:"<<endl;
        long long temp;
        cin>>temp;
        mit4 = m4.find(temp);
        if(mit4 != m4.end()){
            cout<<"成功删除用户：";
            cout<<mit4->first<<" "<<mit4->second;
            m4.erase(mit4);
            m5.erase(mit4->second);
        }
        else
            cout<<"未找到该用户"<<endl;
    }
    //查找用户
    //通过学号查找
    void seaById(long long Id){
        mit4 = m4.find(Id);
        if(mit4 == m4.end())
            cout<<"未找到该用户"<<endl;
        else{
            cout<<"你要找的用户信息如下："<<endl;
            cout<<mit4->first<<" "<<mit4->second<<endl;
        }
    }
    //通过姓名查找
    void seaByName(string name){
        mit5 = m5.find(name);
        if(mit5 == m5.end())
            cout<<"未找到该用户"<<endl;
        else{
            cout<<"你要找的用户信息如下："<<endl;
            cout<<mit5->second<<" "<<mit5->first<<endl;
        }
    }
    //显示所有用户
    void dispAllUser(){
        for(uit=uall.begin(); uit!=uall.end(); uit++)
            uit->print();
    }
};


#endif /* admin_h */
