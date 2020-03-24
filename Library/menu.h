//
//  menu.h
//  Library
//  菜单类，交互界面
//  Created by yufenZ on 2020/3/22.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef menu_h
#define menu_h

#include <iostream>
#include "date.h"
#include "book.h"
#include "user.h"
#include "admin.h"
using namespace std;

class menu{
private:
    date dat;
    book b;
    user u;
    admin a;
public:
    //主界面
    void welcome(){
        system("color 0B");
        cout << "----------------------------------------------"<<endl;
        cout <<"-                                                                 -"<<endl;
        cout <<"-                                                                 -"<<endl;
        cout <<"-             ┏━━━━━━━━━━━━━━━━━━━━━━━┓                           -"<<endl;
        cout <<"-             ┃                       ┃                           -"<<endl;
        cout <<"-             ┃ 图书馆管理系统 Ver 1.0   ┃                           -"<<endl;
        cout <<"-             ┃                       ┃                           -"<<endl;
        cout <<"-             ┃        深圳大学         ┃                           -"<<endl;
        cout <<"-             ┃                       ┃                           -"<<endl;
        cout <<"-             ┃  By  Leo  2018.5      ┃                           -"<<endl;
        cout <<"-             ┃                       ┃                           -"<<endl;
        cout <<"-             ┗━━━━━━━━━━━━━━━━━━━━━━━┛                           -"<<endl;
        cout <<"-                                                                 -"<<endl;
        cout <<"-                                                                 -"<<endl;
        cout <<"----------------------------------------------"<<endl;
        cout <<endl<<"                  按 任 意 键 清 屏                                "<<endl;
        system("pause");
        system("cls");
        system("color 0F");
    }
    //选择菜单 管理员or用户
    void selectMenu(){
        cout<<"     [0] 退出系统"<<endl;
        cout<<"     [1] 管理员界面"<<endl;
        cout<<"     [2] 用户界面"<<endl;
        cout<<"请输入要进入的界面："<<endl;
        int command;
        cin>>command;
        switch (command) {
            case 0:{
                cout<<"     -   感谢使用    -   正在推出系统  -   "<<endl;
                system("pause");
                system("cls");
                exit(0);
                break;
            }
            case 1:{
                cout<<"请输入管理员初始密码："<<endl;
                string pass;
                rcin : while(cin>>pass){
                    if(a.isPassword(pass)){
                        system("cls");
                        a.readBook();
                        a.readUser();
                        Administrator();
                    }
                    else{
                        cout<<"密码输入错误！请重新输入："<<endl;
                        goto rcin;
                    }
                }
                break;
            }
            case 2:{
                cout<<"请输入用户初始密码："<<endl;
                string pass;
                recin:while(cin>>pass){
                    if(u.isPassword(pass)){
                        system("cls");
                        long long a;
                        string b, c;
                        cout<<"请输入用户信息：[学号 姓名 密码]"<<endl;
                        cin>>a>>b>>c;
                        u.setId(a);
                        u.setName(b);
                        u.setPassword(c);
                        cout<<"初始化用户完成！进入用户操作菜单"<<endl;
                        useroperator();
                    }
                }
            }
                
            default:{
                cout<<"Command Error! 请重新输入!"<<endl;
                selectMenu();
            }
        }
    }
    //管理员界面
    void Administrator(){
        amenu:cout << "■■■■■■■■■■■■管理员系统■■■■■■■■■■■■■"<<endl;
        cout << "■                  ┏━━━━━━━━━━━━━━┓                      ■"<<endl;
        cout << "■                  ┃ [0] 退出系统   ┃                      ■"<<endl;
        cout << "■                  ┣━━━━━━━━━━━━━━┫                      ■"<<endl;
        cout << "■                  ┃ [1] 增加图书   ┃                      ■"<<endl;
        cout << "■                  ┣━━━━━━━━━━━━━━┫                      ■"<<endl;
        cout << "■                  ┃ [2] 删除图书   ┃                      ■"<<endl;
        cout << "■                  ┣━━━━━━━━━━━━━━┫                      ■"<<endl;
        cout << "■                  ┃ [3] 查找图书   ┃                      ■"<<endl;
        cout << "■                  ┣━━━━━━━━━━━━━━┫                      ■"<<endl;
        cout << "■                  ┃ [4] 修改图书   ┃                      ■"<<endl;
        cout << "■                  ┣━━━━━━━━━━━━━━┫                      ■"<<endl;
        cout << "■                  ┃ [5] 创建用户   ┃                      ■"<<endl;
        cout << "■                  ┣━━━━━━━━━━━━━━┫                      ■"<<endl;
        cout << "■                  ┃ [6] 删除用户   ┃                      ■"<<endl;
        cout << "■                  ┣━━━━━━━━━━━━━━┫                      ■"<<endl;
        cout << "■                  ┃ [7] 查询用户   ┃                      ■"<<endl;
        cout << "■                  ┣━━━━━━━━━━━━━━┫                      ■"<<endl;
        cout << "■                  ┃ [8] 修改用户   ┃                      ■"<<endl;
        cout << "■                  ┣━━━━━━━━━━━━━━┫                      ■"<<endl;
        cout << "■                  ┃ [9] 修改密码   ┃                      ■"<<endl;
        cout << "■                  ┗━━━━━━━━━━━━━━┛                      ■"<<endl;
        cout << "■■■■■■■■■■■[-1] 返回上一层■■■■■■■■■■■■"<<endl;
        cout << "输入要进行的操作："<<endl;
        int command;
        cincom:cin>>command;
        switch(command){
            case -1:{
                system("cls");
                selectMenu();
            }
            case 0:{
                a.saveBook();
                a.saveUser();
                cout<<"     -   感谢使用    -   正在退出系统  -   "<<endl;
                system("pause");
                system("cls");
                exit(0);
                break;
            }
            case 1:{
                system("cls");
                a.addBook();
                goto amenu;
                break;
            }
            case 2:{
                system("cls");
                a.delBook();
                goto amenu;
                break;
            }
            case 3:{
                system("cls");
            chaxun:cout<<"      [1]按书名查找"<<endl;
                cout<<"     [2]按作者查找"<<endl;
                cout<<"     [3]按出版日期查找"<<endl;
                cout<<"请输入查询方式:"<<endl;
                int way;
                cin>>way;
                switch(way){
                    case 1:{
                        cout<<"请输入要查询的书名:"<<endl;
                        string bookname;
                        cin>>bookname;
                        a.seaByBookname(bookname);
                        system("pause");
                        system("cls");
                        goto amenu;
                    }
                    case 2:{
                        cout<<"请输入要查询的书的作者:"<<endl;
                        string au;
                        cin>>au;
                        a.seaByAuthor(au);
                        system("pause");
                        system("cls");
                        goto amenu;
                    }
                    case 3:{
                        cout<<"请输入要查询的书的出版日期:"<<endl;
                        int year;
                        cin>>year;
                        a.seaByDate(year);
                        system("pause");
                        system("cls");
                        goto amenu;
                    }
                    default:{
                        system("cls");
                        cout<<"Command Error!请重新输入："<<endl;
                        goto chaxun;
                    }
                }
            }
            case 5:{
                system("cls");
                a.addUser();
                system("pause");
                goto amenu;
                break;
            }
            case 6:{
                system("cls");
                a.delUser();
                system("pause");
                goto amenu;
                break;
            }
            case 7:{
                system("cls");
                cout<<"     [1]按学号查询"<<endl;
                cout<<"     [2]按姓名查询"<<endl;
                cout<<"请输入查询方式："<<endl;
                int way;
                cin>>way;
                switch(way){
                    case 1:{
                        cout<<"请输入要查找的学号："<<endl;
                        long long stdid;
                        cin>>stdid;
                        a.seaById(stdid);
                        system("pause");
                        system("cls");
                        goto amenu;
                        break;
                    }
                    case 2:{
                        cout<<"请输入要查找的姓名"<<endl;
                        string stdname;
                        cin>>stdname;
                        a.seaByName(stdname);
                        system("pause");
                        system("cls");
                        goto amenu;
                        break;
                    }
                }
            }
            case 9:{
                system("cls");
                string pass;
                cout<<"请输入原密码"<<endl;
                cin>>pass;
                if(a.isPassword(pass)){
                    cout<<"请输入新密码："<<endl;
                    cin>>pass;
                    a.setPassword(pass);
                    cout<<"密码修改成功！"<<endl;
                }
                else
                    cout<<"密码输入错误！已返回主菜单"<<endl;
                goto amenu;
                break;
            }
            default:{
                cout<<"Command Error!请重新输入！"<<endl;
                goto cincom;
            }
        }
    }
    //用户界面
    void useroperator();
    
};

#endif /* menu_h */
