#ifndef HOSPITAL_H_INCLUDED
#define HOSPITAL_H_INCLUDED
#include <windows.h>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class hospital          //����ҽԺ��
{
public :
    int delete_file();  //ɾ�������ļ�
    int delete1();      //����ɾ������
    int delete1(long i);//ɾ������
    int cz_menu();      //����ɾ�������˵�
    int serch(int i);   //����serch����ʵ�����ֲ�ͬ���ҷ�ʽ
    int serch();        //����ɾ������
    void f_write();     //д�ļ������������ڳ���ر�֮ǰ�������ݵ�����
    void f_read();      //���ļ������������ڳ����֮ǰ��ȡ����Ҫ������
    int input();        //���뺯��
    void menu();        //���˵�����
    void tj();          //ͳ�ƹ��ܺ���
    int gh_menu();      //�ҺŹ���ѡ��˵�
    int tj_menu();      //ͳ�ƹ���ѡ��˵�����
    int gjzh();         //�Ҽ����
    int yygh();         //ԤԼ�Һź���
    int ghxd();         //�Һ��򵼺���
    int ghrs();         //�Һ����ͳ�ƺ���
    int jzrs();         //���ƾ�������ͳ�ƺ���
    int nlb();          //��������ͳ�ƺ���
    int ghsr();         //�Һ��������
    int gdrh();         //�ҵ��պź���
    int show();         //չʾ��������
    void room(char room);         //�����Һ���
};

#endif // HOSPITAL_H_INCLUDED
