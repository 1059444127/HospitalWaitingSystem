#include"hospital.h"
#define Max 1000000             //���֧�ֵĹҺŵ�����
long renshu[5]= {0,0,0,0,0};    //��Ÿ���������
long I=0;             //�����±�
long L=0;
long Ghsr=0;         //���ڴ�ŹҺŵ����룡
using namespace std;

struct Patient              //���廼�߽ṹ��
{
    char num[6];              //���߱��
    char time[8] = "";              //�Һ�����,��ʼ��0
    int  sex = 0;                 //�Ա�  1Ϊ��,2ΪŮ
    int  age = 0;                 //����
    char room = '0';                //���ҺŵĿ���
    char jz[4] = "��";   //�Ƿ��Ǽ��Ĭ��ֵ��
    char zp;                  //ר�����ﻹ����ͨ����
} P[Max],Q[Max];                   //�����1000000��

struct Age              //����νṹ��
{
    int e = 0;                 //��ͯ enfant 1-14
    int y = 0;                 //���� young people 15-25
    int m = 0;                 //���� wrinkly 26-55
    int o = 0;                 //���� old folks  55����
};
struct ghfl
{
    int drrs = 0;            //���պ�����
    int yyrs = 0;            //ԤԼ����
    int jzrs = 0;            //��������
} G;
struct Paixu                //��������Ҿ�����������ṹ��
{
    char name[6];             //��������
    int money;                //��������
    struct Age a  ;           //Age �ṹ�����͵ĳ�Ԫ
} J[5];                     //һ��5������

void clear()
{
    system("cls");        //����
    system("date/t");     //��ʾ����
}
//--------------�ֿ��Һ���------------------
void hospital::room(char room)
{
    clear();
    switch(room)
    {
    case '1':
        renshu[0]++;
        cout<<'\t'<<"\n\t�뵽��5�����ң�\n\n\t����ǰ�滹�� " <<  renshu[0]-1 << " ��\n\n\t";
        break;
    case '2':
        renshu[1]++;
        cout<<'\t'<<"\n\t�뵽��4�����ң�\n\n\t����ǰ�滹�� " <<  renshu[1]-1<< " ��\n\n\t";
        break;
    case '3':
        renshu[2]++;
        cout<<'\t'<<"\n\t�뵽��3�����ң�\n\n\t����ǰ�滹�� " <<  renshu[2]-1<< " ��\n\n\t";
        break;
    case '4':
        renshu[3]++;
        cout<<'\t'<<"\n\t�뵽��2�����ң�\n\n\t����ǰ�滹�� " <<  renshu[3]-1<< " ��\n\n\t";
        break;
    case '5':
        renshu[4]++;
        cout<<'\t'<<"\n\t�뵽��1�����ң�\n\n\t����ǰ�滹�� " <<  renshu[4]-1<< " ��\n\n\t";
        break;
    }
}
//--------------�ҵ��պź���------------------
int hospital::gdrh()
{
    char temp[1000] = "";   //Ϊ�˱����������ַ�ʱ������Ĵ���
    if(input() == -1)
    {
        return 1;  //�����input����ѡ���˷����򷵻�
    }
    //tj();  //����ͳ�Ƽ���ǰ���м���
    room(P[I-1].room);  //�ֿ���
    G.drrs++;  //�ҵ��պ�����+1
    system("pause");  //��ͣ
    return 1;
}

//--------------�鿴�Һ���������------------------
int hospital::ghrs()
{
    char temp[100]="";
    clear();
    cout<<"\n\n\n\t\t\t����Һ����һ����\n";
    cout << "\t==================================================\n";
    cout << "\n\n\t" << "\t�ҵ��պŵ�����Ϊ----" << G.drrs;
    cout << "\n\n\t" << "\t��ԤԼ�ŵ�����Ϊ----" << G.yyrs;
    cout << "\n\n\t" << "\t�Ҽ���ŵ�����Ϊ----" << G.jzrs;
    cout << "\n\n\n\t==================================================\n\t";
    system("pause");
    return(1);

}
//--------------�Ҽ���ź���------------------
int hospital::gjzh()
{
    if(-1 == input())
    {
        return 1;  //����
    }
    clear();  //����
    switch(P[I-1].room)
    {
    case '1':
        renshu[0]++;
        cout<<'\t'<<"\n\t�뵽��1�����ң�\n\n\t";
        break;
    case '2':
        renshu[1]++;
        cout<<'\t'<<"\n\t�뵽��2�����ң�\n\n\t";
        break;
    case '3':
        renshu[2]++;
        cout<<'\t'<<"\n\t�뵽��3�����ң�\n\n\t";
        break;
    case '4':
        renshu[3]++;
        cout<<'\t'<<"\n\t�뵽��4�����ң�\n\n\t";
        break;
    case '5':
        renshu[4]++;
        cout<<'\t'<<"\n\t�뵽��5�����ң�\n\n\t";
        break;
    }
    G.jzrs++;  //���������+1
    strcpy( P[I-1].jz,"��");
    system("pause");
    return 1;
}
//--------------�鿴�Һ����뺯��------------------
int hospital::ghsr()
{
    int i=0;
    char temp[100]="";
    char temp1='/';
    clear();
    cout<<"\n\n\n\t\t\t�Һ����һ����\n";
    cout << "\t==================================================\n";
    cout<<"\t����ĹҺŷ�����Ϊ:  "<<Ghsr<<" Ԫ";
    cout << "\n\t==================================================\n";
    for(i=0; i<5; i++)
        cout<<"\n\n\t"<<J[i].name<<"������Ϊ:  "<<J[i].money ;
    cout << "\n\t==================================================\n\t";
    system("pause");
    return(1);

}
//--------------�鿴����Ⱥ���------------------
int hospital::nlb()
{
    long sum[5];
    int i;
    char temp[100]="";
    clear();
    cout<<"\n\n\t\t\t  �����һ������������\n\n";
    cout<<"\t\t�� ͯ\t �� ��\t �� ��\t �� ��\t �� ��\n\n";
    cout<<"\t\t(1-14)\t(15-25)\t(26-55)\t(56����)(1-100)\n";
    cout<<"      =============================================================\n\n";
    for(i=0; i<5; i++)            //��������Ҿ����������
        sum[i]=J[i].a.e+J[i].a.y+J[i].a.m+J[i].a.o ;
    for(i=0; i<5; i++)
    {
        cout <<'\t'<<J[i].name<<'\t'<<J[i].a.e<<"\t "<<J[i].a.y<<"\t "<<J[i].a.m<<"\t "<<J[i].a.o<<"\t "<<sum[i];
        cout<<"\n\n";
    }
    cout<<"      =============================================================\n\t";
    system("pause");
    return(1);


}
//--------------�鿴���ƾ������------------------
int hospital::jzrs()
{
    int i=0;
    char temp[100]="";
    clear();
    cout<<"\n\n\n\t\t\t���ƾ�������һ����\n";
    cout << "\t==================================================";
    for(i=0; i<5; i++)
        cout<<"\n\n\t"<<i+1<<". "<<J[i].name<<"�ľ�������Ϊ:  "<<renshu[i] ;
    cout << "\n\t==================================================\n\t";
    system("pause");
    return(1);


}
//--------------�Һ��򵼺���------------------
int hospital::ghxd()
{
    clear();     //����
    char gn, temp[1000]=""; //Ϊ�˱����������ַ�ʱ������Ĵ���
    cout << "\n\n\t\t\t====�Һ���====\n\n";
    cout << "\t\t���½����ο�,����������ѯҽ����Ա��\n\n";
    cout << "\t===����============================��������===================\n\n" ;
    cout << "\t  �ڿ�\t\t����,����,����,����,����,ѪҺ,�ڷ���,��,��,��\n\n";
    cout << "\t  ���\t\t��Ⱦ,����,�ε�,����,΢��,����,�س�,����,��\n\n";
    cout << "\t  �ǿ�\t\t����,��������,��ʪ,�ؽ�,��֫,����,��\n\n";
    cout << "\t  ��ǻ��\t����,����,���,��,�ܰ�,��ǻ����,��\n\n";
    cout << "\t  Ƥ����\tѢ��,����,Ƥ��,Ƥ������,���,����,��\n\n";
    cout << "\t==============================================================\n\t";
    system("pause");
    return 1;
}
//--------------ԤԼ�ҺŹ��ܺ���------------------
int hospital::yygh()
{
    char str_1[5],str_2[5],str[50],gn;                    //����ϵͳʱ����ԤԼ��ͬ������ϵͳʱ��
    int m=1,n=0;
    if(-1==input())
        return 1;
    struct tm *mytime;
    time_t LocalTime;
    LocalTime=time(NULL);
    mytime=localtime(&LocalTime);
    strftime(str,sizeof(str),"%c",mytime);           //����ϵͳ��ǰʱ�䣬��ʽ09/04/15
    do
    {
        clear();
        if(m-n==0)
        {
            cout << "\n\n\n��ҵ����......\n\n";
            system("pause");
            return 1;
        }

        else
        {
            char date[8];
            int flag=1;
            while(flag==1)
            {
                   clear();
                   memset(str_1,'\0',sizeof(str_1));
                   memset(str_2,'\0',sizeof(str_2));

                   cout << "==================================================\n";
                   cout<< "\n\tע�⣺ԤԼ�Һ�ֻ��ԤԼ��������\n\n"<<endl;

                   cout<< "\t����������(��ʽ����(00)/��(00)/��(00)��";
                   cin>>date;
                   strcpy(P[I].time, date);
                   for(int j=0,r=0; j<strlen(date); j++)                   //���治ͬ����
                   {
                        if(str[j]!=date[j])
                        {
                            if((j==3||j==4)&&(date[j]-'0')>=0&&(date[j]-'0')<=9)
                            {
                                str_1[r]=str[j];
                                str_2[r]=date[j];
                                r++;
                                flag=0;
                            }
                           else
                           {
                                flag=1;
                                clear();
                                cout<<"\n\n\n��������ȷ�����ڸ�ʽ......\n\n";
                                system("pause");
                                break;

                           }
                        }
                   }
               }
           sscanf(str_2,"%d",&m);                                   //�ַ���ת��Ϊ����
           sscanf(str_1,"%d",&n);
        }
    }
          while(m-n>7||m-n<=0);
         cout<< "\n\t��"<<m-n<<"��֮��ǰ�����лл��\n\n\t";            //��ͬ�������
         G.yyrs++;  //ԤԼ�Һ�����+1
         switch(P[I-1].room)
         {
             case '1':
                   renshu[0]++;
                    break;
             case '2':
                   renshu[1]++;
                   break;
             case '3':
                   renshu[2]++;
                   break;
             case '4':
                    renshu[3]++;
                   break;
             case '5':
                   renshu[4]++;
                   break;
          }
        Q[L].zp=P[I-1].zp;
        Q[L].age=P[I-1].age;
        strcpy(Q[L].jz,P[I-1].jz);
        strcpy(Q[L].num,P[I-1].num);
        Q[L].room=P[I-1].room;
        Q[L].sex=P[I-1].sex;
        strcpy(Q[L].time, P[I-1].time);
        L++;
        system("pause");
        return 1;
}

//--------------ͳ�ƹ��ܺ���------------------
void hospital::tj()
{
    long i=0,m;
    struct Paixu t;
    m=I;
    strcpy(J[0].name,"�ڿ�");             //J�ṹ�����鸳��ֵ
    strcpy(J[1].name,"���");
    strcpy(J[2].name,"�ǿ�");
    strcpy(J[3].name,"Ƥ����");
    strcpy(J[4].name,"��ǻ��");
    for(i=0; i<5; i++)                     //�����Ҹ������������ֵΪ0
    {
        J[i].a.e=0;
        J[i].money = 0;
        J[i].a.y=0;
        J[i].a.m=0;
        J[i].a.o=0;
    }
    Ghsr = 0;

    for(i=0; i<m; i++)
    {
        if(P[i].zp=='Y')Ghsr+=10,J[P[i].room-'1'].money+=10;     //ͳ�ƹҺ�����:ר��
        else if(P[i].zp == 'N') Ghsr+=5,J[P[i].room-'1'].money+=5;                 //ͳ�ƹҺ�����:��ͨ
        if (P[i].age<=14)             //ͳ�Ƹ����Ҹ����������
            J[P[i].room-'1'].a.e++;
        else if (P[i].age <=25)
            J[P[i].room-'1'].a.y++;
        else if(P[i].age <=55)
            J[P[i].room-'1'].a.m++;
        else J[P[i].room-'1'].a.o++;

    }

}
//--------------���빦�ܺ���------------------
int hospital::input()
{
    char room2='/',cls1='0',zp2,sex2,qr;
    int age2=0,i=0;
    char room1[1000]="";
    char zp1[1000]="";
    char sex1[1000]="";
    char age1[1000]="";
    char cls[1000]="";
    char temp[6]="";
    char temp1[6]="";
    while(I<Max)                                      //�ظ������¼
    {
        strcpy(room1,"");
        strcpy(zp1,"");
        strcpy(sex1,"");
        strcpy(age1,"");
        strcpy(cls,"");
        strcpy(temp,"");
        strcpy(temp1,"");
        room2='/';
        sex2='/';
        zp2='/';
        cls1='0';
        age2=0;
        qr='/';
        while((room2<'1' || room2 > '5') && room2!='r' )
        {
            clear();
            cout<<"\n\n\t\t\t\t��ѡ�����\n\n";
            cout << "\n\t=============================================================\n";
            cout<<"\n\t\t1.�ڿ�";
            cout<<"\t\t2.���";
            cout<<"\t\t3.�ǿ�\n\n";
            cout<<"\t\t4.Ƥ����";
            cout<<"\t5.��ǻ��";
            cout<<"\tr.����!";
            cout << "\n\n\t=============================================================\n";
            cout<< "\n\t��ѡ����Ҫ�ҿ��ҵı��:";
            cin>>room1;    //���������ʱ����temp��
            if (strlen(room1)==1) room2=tolower(room1[0]);
        }
        if (room2=='r') return(-1);

        while(zp2!='Y'&&zp2!='N')     //ѡ��ר��������
        {
            clear();
            cout<<"\n\n\n��ͨ����: 5Ԫ \nר������: 10Ԫ\n\n\n���Ƿ�Ҫ��ר������(Y/N):";
            cin>>zp1;
            if (strlen(zp1)==1)
                zp2=toupper(zp1[0]);         //��ɴ�д,�Ա���ϵͳ���ִ�Сд
        }
        while(sex2!='1'&&sex2!='2')        //ѡ���Ա�1Ϊ��,2ΪŮ
        {
            clear();
            cout<<"\n\n\n\t�� �� (1.�� 2.Ů):";
            cin>>sex1;
            if (strlen(sex1)==1)
                sex2=sex1[0];
        }
        while(age2<=0||age2>150)           //�����������1--150֮��
        {
            clear();
            cout<<"\n\n\n\t�� ��:";
            cin>>age1;
            if (strlen(age1)<=3)
                age2=atoi(age1);            //���ַ��͵�age1ת�������͸���age2;
        }
        ltoa(I+1,temp,10);                     //���㵱ǰ���߱��
        if(strlen(temp)<6)
            for(i=0; i<6-strlen(temp); i++)
                strcat(temp1,"0");
        strcat(temp1,temp);
        //  ���������Ϣ��ȷ�������Ƿ���ȷ
        while(cls1!='1'&&cls1!='2'&&cls1!='r')
        {
            clear();
            cout<<"\n\n\n\t\t\t�����������Ϣ����,��ȷ���Ƿ���ȷ!\n\n\n\n";
            cout<<"\t��  ��\t �� ��\t�� ��\t���ҿ���\tר������\t�Һŷ�\n\n";
            cout<<'\t'<<temp1;                           //���
            if (sex2=='1')
                cout<<'\t'<<" ��";                      //�Ա�
            else if(sex2 =='2')
                cout<<'\t'<<" Ů";

            cout<<'\t'<<age2;                             //����
            switch(room2)                                   //����
            {
            case '1':
                cout<<'\t'<<"��  ��";
                break;
            case '2':
                cout<<'\t'<<"��  ��";
                break;
            case '3':
                cout<<'\t'<<"��  ��";
                break;
            case '4':
                cout<<'\t'<<"Ƥ����";
                break;
            case '5':
                cout<<'\t'<<"��ǻ��";
                break;
            }
            if (zp2=='Y')                                   //�Ƿ�Ϊר������
                cout<<"\t\t"<<"    ��";
            else cout<<"\t\t"<<"�� ��";
            if (zp2=='Y')                                   //�Һŷ���
                cout<<"\t\t"<<"10";
            else cout<<"\t\t"<<"5";

            cout<<"\n\n================================================================================";
            cout<<"\n\n\t\t1.������д!\t\t2.��Ϣ��ȷ!";
            cout<<"\n\n\n��������Ҫѡ��˵���(1,2):";
            cin>>cls;
            if (strlen(cls)==1)
                cls1=tolower(cls[0]);   //��ΪСд��ĸ
        }

        if (cls1=='2')
        {
            P[I].age =age2;
            P[I].room=room2;
            strcpy(P[I].num,temp1);
            P[I].sex=sex2-'0';
            P[I].zp=zp2;
            I++;
            return 0;
        }
    }       //�ظ������¼(��)

}
//--------------�ҺŹ��ܲ˵�����------------------
int hospital::gh_menu()
{
    int qu[5],i,fh; //qu�������ڽ��շ���ֵ i��ֵ�±� fh���صĿ���
    char gn, temp[1000]=""; //Ϊ�˱����������ַ�ʱ������Ĵ�������123��-2�ȵ�
    //����ͳ�ƹ��ܺ����������Ҫ��ֵ

    do                  //���Ʒ��ز���
    {
        for(i=0; i<5; i++) qu[i]=2; //����ʱ���¸���ֵ
        fh=0;
        i=0;
        gn='0';
        strcpy(temp,"");
        clear();

        while(gn!='1'&&gn!='2'&&gn!='3'&&gn!='4'&&gn!='q'&&gn!='r')  //ֻ������1��2����3
        {
            clear();
            cout<<"\n\n\n\t\t\t===��ѡ������Ҫ�Ĺ���===\n";
            cout << "\n\t=============================================================\n";
            cout<<"\n\t1.�ҵ��պ�\t2.ԤԼ�Һ�\t3.�Ҽ����\t4.�Һ���\n";
            cout <<"\n\t\t\tr.��  ��!\tq.��  ��!\n";
            cout << "\n\t=============================================================\n";
            cout<<"\t������(1,2,3,4,r,q):";
            cin>>temp;     //���������ʱ����temp��
            if (strlen(temp)==1) gn=tolower(temp[0]);//�������ַ�ʱ����
        }
        switch(gn)
        {
        case '1':
            qu[0]=gdrh();
            break;   //�ҵ��պ�
        case '2':
            qu[1]=yygh();
            break;   //ԤԼ�Һ�
        case '3':
            qu[2]=gjzh();
            break;  //�Ҽ����
        case '4':
            qu[3]=ghxd();
            break;  //�Һ���
        case 'r':
            return(1);      //��ʾѡ����"����"
        case 'q':
            qu[4]=0;       //�����˳�����

        }
        for(i=0; i<5; i++)
            if (qu[i]==0)               //�Ѿ�ѡ����"�˳�"
            {
                system("cls");
                cout<<"\n\n\n\n\t\t\t��ȷ��Ҫ�˳���ϵͳ��?(Y/N)";
                cin>>temp;
                if (tolower(temp[0])=='y')
                {
                    f_write(); //д�ļ�
                    system("cls");
                    cout<<"\n\n\n\t\t\t���ѳɹ��˳�ϵͳ!\n\n\n\n\n\n";
                    exit(0);
                }
                else
                {
                    fh=1;
                    break;
                }
            }
            else                        //ѡ����"����"
                if (qu[i]==1)
                {
                    fh=1;
                    break;
                }

    }
    while(fh==1);
    return(-1);


}
int hospital::show()
{
    char n, temp[1000]=""; //Ϊ�˱����������ַ�ʱ������Ĵ�������123��-2�ȵ�
    while(TRUE)
    {
        n = '0';  //ÿ��ѭ����ʼ��ֵ
        while(n!='1'&&n!='2'&&n!='3'&&n!='4'&&n!='5'&&n!='6'&&n!='7'&&n!='r')
        {


            clear();
            cout << "\n\t==============================================================\n\n";
            cout<< "\t1.��������\t2.�ڿ�����\t3.�������\n";
            cout<< "\t4.�ǿ�����\t5.Ƥ��������\t6.��ǻ������\n";
            cout<< "\t7.ԤԼ����";
            cout << "\tr.���أ�\n";
            cout << "\n\t==============================================================\n\n";
            cout<<"\t������ѡ��(1,2,3,4,5,6,7,r)��";
            cin>>temp;
            if (strlen(temp)==1 ) n=tolower(temp[0]);//�������ַ�ʱת��ΪСд
        }
        if(n == 'r')
        {
            return 1;   //����
        }
        clear();
        cout << "\n\t==============================================================\n";
        cout<< "\t���߱��"<<"\t�Ա�"<<"\t����"<<"\t����"<<"\tר������\n";
        switch(n)
        {
        case '1':                                                                      //��ӡ���в�������
        {
            for(int i=0; i<I; i++)
            {
                if(P[i].room != '0')
                {
                    cout<< "\t"<<P[i].num<<"  \t"<<P[i].sex<<"\t"<<P[i].room<<"\t"<<P[i].jz<<"\t"<<P[i].zp<<endl;
                }

            }
            break;
        }
        case '2':                                                                     //��ӡ�ڿ�����
        {
            for(int i=0; i<I; i++)
            {
                if(P[i].room == '1')
                    cout<< "\t"<<P[i].num<<"  \t"<<P[i].sex<<"\t"<<P[i].room<<"\t"<<P[i].jz<<"\t"<<P[i].zp<<endl;
            }
            break;
        }
        case '3':                                                                      //��ӡ�������
        {
            for(int i=0; i<I; i++)
            {
                if(P[i].room=='2')
                    cout<< "\t"<<P[i].num<<"  \t"<<P[i].sex<<"\t"<<P[i].room<<"\t"<<P[i].jz<<"\t"<<P[i].zp<<endl;
            }
            break;
        }
        case '4':                                                                     //��ӡ�ǿ�����
        {
            for(int i=0; i<I; i++)
            {
                if(P[i].room=='3')
                    cout<< "\t"<<P[i].num<<"  \t"<<P[i].sex<<"\t"<<P[i].room<<"\t"<<P[i].jz<<"\t"<<P[i].zp<<endl;
            }
            break;
        }
        case '5':                                                                     //��ӡƤ��������
        {
            for(int i=0; i<I; i++)
            {
                if(P[i].room=='4')
                    cout<< "\t"<<P[i].num<<"  \t"<<P[i].sex<<"\t"<<P[i].room<<"\t"<<P[i].jz<<"\t"<<P[i].zp<<endl;
            }
            break;
        }
        case '6':                                                                    //��ӡ��ǻ������
        {
            for(int i=0; i<I; i++)
            {
                if(P[i].room=='5')
                    cout<< "\t"<<P[i].num<<"  \t"<<P[i].sex<<"\t"<<P[i].room<<"\t"<<P[i].jz<<"\t"<<P[i].zp<<endl;
            }
            break;
        }
        case '7':                                                                    //��ӡ��ǻ������
        {
            for(int i=0; i<L; i++)
            {
                if(Q[i].room != '0')
                    cout<< "\t"<<Q[i].num<<"  \t"<<Q[i].sex<<"\t"<<Q[i].room<<"\t"<<Q[i].jz<<"   \t"<<Q[i].zp<<"    \t"<<Q[i].time<<endl;
            }
            break;
        }
        }
        cout << "\n\t==============================================================\n\n";
        cout << "\n\t";
        system("pause");  //��ͣ
    }
}
//--------------ͳ�ƹ��ܲ˵�����------------------
int hospital::tj_menu()
{
    int qu[6],i,fh; //qu�������ڽ��շ���ֵ i��ֵ�±� fh���صĿ���
    char gn, temp[1000]=""; //Ϊ�˱����������ַ�ʱ������Ĵ�������123��-2�ȵ�
    tj();  //����ͳ�ƺ���
    do                  //���Ʒ��ز���
    {
        for(i=0; i<5; i++) qu[i]=2; //����ʱ���¸���ֵ
        fh=0;
        i=0;
        gn='0';
        strcpy(temp,"");
        clear();

        while(gn!='1'&&gn!='2'&&gn!='3'&&gn!='4'&&gn!='5'&&gn!='q'&&gn!='r')  //ֻ������1��2����3
        {
            clear();
            cout<<"\n\n\n\t\t\t===��ѡ������Ҫ�Ĺ���===\n";
            cout << "\n\t==============================================================\n\n";
            cout<<"\t1.�鿴�Һ����\t2.���ƾ�������\t3.���������\t4.�Һ��������\n\n\t5.��ӡ��������";
            cout <<"\tr.��  ��!\tq.��  ��!\n";
            cout << "\n\t==============================================================\n";
            cout<<"\n\t��������(1,2,3,4,5,6,r,q):";
            cin>>temp;     //���������ʱ����temp��
            if (strlen(temp)==1) gn=tolower(temp[0]);//�������ַ�ʱ����
        }
        switch(gn)              //�����õĸ�����ֻ��������ø�����������1
        {
        case '1':
            qu[0]=ghrs();
            break;   //���ò鿴�Һ��������
        case '2':
            qu[1]=jzrs();
            break;   //���ø��ƾ�����������
        case '3':
            qu[2]=nlb();
            break;  //���ø��ƾ�������Ⱥ���
        case '4':
            qu[3]=ghsr();
            break;  //���ò鿴���뺯��
        case '5':
            qu[4]=show();//���ô�ӡ����
            break;
        case 'r':
            return(1);      //��ʾѡ����"����"
        case 'q':
            qu[5]=0;       //�����˳���

        }
        for(i=0; i<6; i++)
            if (qu[i]==0)               //�Ѿ�ѡ����"�˳�"
            {
                system("cls");
                cout<<"\n\n\n\n\t\t\t��ȷ��Ҫ�˳���ϵͳ��?(Y/N)";
                cin>>temp;
                if (tolower(temp[0])=='y')
                {
                    f_write();
                    system("cls");
                    cout<<"\n\n\n\t\t\t���ѳɹ��˳�ϵͳ!\n\n\n\n\n\n";
                    exit(0);
                }
                else
                {
                    fh=1;
                    break;
                }
            }
            else                        //ѡ����"����"
                if (qu[i]==1)
                {
                    fh=1;
                    break;
                }

    }
    while(fh==1);
    return(-1);

}
//--------------���˵�����------------------
void hospital::menu()
{
    f_read();
    {
        int qu[3],i,fh; //qu�������ڽ��շ���ֵ i��ֵ�±� fh���صĿ���
        char gn, temp[1000]=""; //Ϊ�˱����������ַ�ʱ������Ĵ���

        do                  //���Ʒ��ز���
        {
            for(i=0; i<3; i++) qu[i]=2; //ѡ�񷵻�  ʱ���¸���ֵ
            fh=0;
            i=0;
            gn='0';
            strcpy(temp,"");
            clear();     //����

            while(gn!='1'&&gn!='2'&&gn!='3'&&gn!='q')  //ֻ������1��2����q
            {
                clear();
                cout<<"\n\n\n\t\t\t===��ӭʹ��ҽԺ�������ϵͳ===\n";
                cout << "\n\t=============================================================\n\n";
                cout<<"\n\t1.�ҺŹ���\t2.ͳ�ƹ���\t3.�������˹�\tq.�˳�\n";
                cout << "\n\n\t=============================================================\n";
                cout<<"\n\t������(1,2,q):";
                cin>>temp;     //���������ʱ����temp��
                if (strlen(temp)==1) gn=tolower(temp[0]);//�������ַ�ʱ����
            }
            switch(gn)
            {
            case '1':
                qu[0]=gh_menu();
                break;   //���ùҺŹ��ܺ���
            case '2':
                qu[1]=tj_menu();
                break;   //����ͳ�ƹ��ܵĽ��溯��
            case '3':
                qu[2]=cz_menu();  //���ò��Һ���
                break;
            case 'q':
                qu[3]=0;       //�����˳�����
            }
            for(i=0; i<4; i++)
                if (qu[i]==0)               //�Ѿ�ѡ����"�˳�"
                {
                    system("cls");
                    cout<<"\n\n\n\n\t\t\t��ȷ��Ҫ�˳���ϵͳ��?(Y/N)";
                    cin>>temp;
                    if (tolower(temp[0])=='y')
                    {
                        f_write(); //д�ļ�
                        system("cls");
                        cout<<"\n\n\n\t\t\t���ѳɹ��˳�ϵͳ!\n\n\n\n\n\n";
                        exit(0);
                    }
                    else
                    {
                        fh=1;
                        break;
                    }
                }
                else                        //ѡ����"����"
                    if (qu[i]==1)
                    {
                        fh=1;
                        break;
                    }

        }
        while(fh==1);
    }
}
//--------------�ļ�д������------------------
void hospital::f_write()
{
    int NUM = 50;
    tj();
    FILE *fp1,*fp2, *fp3, *fp4, *fp6;
    fp2 = fopen("ȫ�ֱ���.txt", "wb");
    fp1 = fopen("��������.txt", "wb");  //ֻд�ķ�ʽ��
    fp3 = fopen("ԤԼ����.txt", "wb");
    fp4 = fopen("�Һ�����.txt", "wb");
    //fp5 = fopen("����ṹ��.txt", "wb");
    fp6 = fopen("��������.txt", "wb");

    fprintf(fp2, "%ld\n%ld\n", I, L);  //����ȫ�ֱ���

    fwrite(Q,sizeof(struct Patient),L, fp3);  //����ԤԼ����
    fwrite(&G,sizeof(struct ghfl),1, fp4);  //���滼����Ϣ
    //fwrite(J,sizeof(struct Paixu),5, fp5);  //���滼����Ϣ
    fwrite(renshu,sizeof(renshu[0]),5, fp6);  //�����������
    fwrite(P,sizeof(struct Patient)+2,I, fp1);  //���滼����Ϣ

    //fclose(fp5);
    fclose(fp4);
    fclose(fp3);
    fclose(fp1);
    fclose(fp2);
    fclose(fp6);
    cout << "\n\n\n\t\t\t"<<"��������ɹ�,1����Զ��˳�\n\n\n";

    for(int i=0; i<NUM; i++)
    {
        Sleep(20);
        cout <<"\t\t\t�˳���..."<< i * 100.0 /NUM <<"%\r";
    }
}
//--------------�ļ����뺯��------------------
void hospital::f_read()
{
    int NUM = 50;
    FILE *fp1, *fp2, *fp3, *fp4, *fp6;

    fp2 = fopen("ȫ�ֱ���.txt", "rb");
    fp1 = fopen("��������.txt", "rb");  //ֻ���ķ�ʽ��
    fp3 = fopen("ԤԼ����.txt", "rb");
    fp4 = fopen("�Һ�����.txt", "rb");
    //fp5 = fopen("����ṹ��.txt", "rb");
    fp6 = fopen("��������.txt", "rb");

    fscanf(fp2, "%ld%ld", &I, &L);  //��ȡȫ�ֱ���
    fread(Q,sizeof(struct Patient),L, fp3);  //��ȡԤԼ����
    fread(&G,sizeof(struct ghfl),1, fp4);  //��ȡ������Ϣ
    //fread(J,sizeof(struct Paixu),5, fp5);  //��ȡ������Ϣ
    fread(renshu,sizeof(renshu[0]),5, fp6);  //��ȡ��������
    fread(P,sizeof(struct Patient)+2,I, fp1);  //��ȡ������Ϣ

    //fclose(fp5);
    fclose(fp4);
    fclose(fp3);
    fclose(fp1);
    fclose(fp2);
    fclose(fp6);
    cout << "\n\n\n\t\t\t" << "�ļ���ȡ�ɹ�,1����Զ�����ϵͳ!\n\n";
    for(int i=0; i<NUM; i++)
    {
        Sleep(20);
        cout <<"\t\t\t������..."<< i * 100.0 /NUM <<"%\r";
    }
}
//--------------ģ������-----------------
int hospital::serch()
{
    char gn='0',age1[100]="", temp2[1000]=""; //Ϊ�˱����������ַ�ʱ������Ĵ���
    int age2=0;

    while(gn!='1'&&gn!='2'&&gn!='3'&&gn!='4'&&gn!='5')
    {
        clear();
        cout<<"\n\n\t\tϵͳ�����տ��Һ�����������\n\n\n";
        cout<<"\t�����������ҿ���<1,2,3,4,5>��";
        cin>>temp2;
        if (strlen(temp2)==1)
            gn=tolower(temp2[0]);//�������ַ�ʱ����
    }
    while(age2<=0||age2>150)           //�����������1--150֮��
    {
        clear();
        cout<<"\n\n\n�������������䣺";
        cin>>age1;
        if (strlen(age1)<=3)
            age2=atoi(age1);            //���ַ��͵�age1ת�������͸���age2;
    }
    int flag=1;
    for(int j=0; j<=I; j++)
    {
        if(gn==P[j].room&&age2==P[j].age)
        {
            if(flag==1)
            {
                clear();
                cout << "\n\t\t\tϵͳ���ҵ�������Ϣ��\n";
                cout << "\n\t==============================================================\n";
                cout << "\t���߱��"<<"\t�Ա�"<<"\t����"<<"\t����"<<"\tר������\n";
                flag=0;
            }
            cout<< "\t"<<P[j].num<<"  \t"<<P[j].sex<<"\t"<<P[j].room<<"\t"<<P[j].jz<<"\t"<<P[j].zp<<endl;
        }
    }
    char ch='0',temp1[10]="";
    do
    {
        cout << "\n\n\n\t\t�����Ƿ���������Ϣ<Y/N>:";
        cin>>temp1;
        ch=tolower(temp1[0]);
    }
    while(ch!='y'&&ch!='n');
    switch(ch)
    {
    case 'y':
    {
        char temp[10];
        long i=-1;
        while(i <= 0)           //����ı�ű������0
        {
            clear();
            cout<<"\n\n\n\t������������ţ����ǽ�Ϊ����ӡ�����ﵥ:";
            cin>>temp;
            i = atoi(temp);            //���ַ��͵�age1ת�������͸���age2;
        }
        if(i > I)
        {
            clear();
            cout << "\n\n\n\t\t��Ǹ,�����������ţ�\n\n\t";
            system("pause");
            return 1;
        }
        cout << "\n\t==============================================================\n";
        cout << "\t���߱��"<<"\t�Ա�"<<"\t����"<<"\t����"<<"\tר������\n";
        cout << "\t"<<P[i-1].num<<"  \t"<<P[i-1].sex<<"\t"<<P[i-1].room<<"\t"<<P[i-1].jz<<"\t"<<P[i-1].zp<<endl;
        break;
    }
    case 'n':
        cout << "\n\n\t�����������񴰿�ȥ����!\n\n\n\t";
        break;
    }
    system("pause");  //��ͣ

    return 1;



}
//--------------����ź���------------------
//�β�û��ʵ���ô� ֻ����������
int hospital::serch(int i)
{
    clear();
    long n=-1;
    char temp[100]="";
    while(n <= 0)           //����ı�ű������0
    {
        clear();
        cout<<"\n\n\n\t�������������:";
        cin>>temp;
        n = atoi(temp);            //���ַ��͵�age1ת�������͸���age2;
    }
    if(n > I)
    {
        clear();
        cout << "\n\n\n\t\t��Ǹ,������������ţ�\n\n\t";
        system("pause");
        return 1;
    }
    clear();
    cout << "\n\n\n\n";
    for(int i=0; i<50; i++)
    {
        Sleep(10);
        cout <<"\t\t\t���ڴ�ӡ�����ﵥ..."<< i * 100.0 /50 <<"%\r";
    }
    clear();
    cout << "\n\t==============================================================\n";
    cout << "\t���߱��"<<"\t�Ա�"<<"\t����"<<"\t����"<<"\tר������\n";
    cout << "\t"<<P[n-1].num<<"  \t"<<P[n-1].sex<<"\t"<<P[n-1].room<<"\t"<<P[n-1].jz<<"\t"<<P[n-1].zp<<"\n\n\t";
    system("pause");  //��ͣ
    return 1;
}
//--------------���Ҳ˵�����------------------
int hospital::cz_menu()
{
    int qu[5],i,fh; //qu�������ڽ��շ���ֵ i��ֵ�±� fh���صĿ���
    char gn, temp[1000]=""; //Ϊ�˱����������ַ�ʱ������Ĵ�������123��-2�ȵ�
    do                  //���Ʒ��ز���
    {
        for(i=0; i<5; i++) qu[i]=2; //����ʱ���¸���ֵ
        fh=0;
        i=0;
        gn='0';
        strcpy(temp,"");
        clear();

        while(gn!='1'&&gn!='2'&&gn!='3'&&gn!='4'&&gn!='q'&&gn!='r')  //ֻ������1��2����3
        {
            clear();
            cout<<"\n\n\n\t\t\t===��ѡ������Ҫ�Ĺ���===\n";
            cout << "\n\t==============================================================\n\n";
            cout<<"\t1.����Ų���\t2.ģ������\t3.�˶��� \t4.�������\n\n";
            cout <<"\tr.��  ��!\tq.��  ��!\n";
            cout << "\n\t==============================================================\n";
            cout<<"\n\t��������(1,2,3,4,r,q):";
            cin>>temp;     //���������ʱ����temp��
            if (strlen(temp)==1) gn=tolower(temp[0]);//�������ַ�ʱ����
        }
        switch(gn)              //�����ø�����������1
        {
        case '1':
            qu[0]=serch(1);
            break;   //����Ų��� ,�����β�ֻ����������,û��ʵ���ô�
        case '2':
            qu[1]=serch();
            break;   //ģ������
        case '3':
            qu[2]=delete1(); //ɾ������
            break;
        case '4':
            qu[3]=delete_file();  //�������
        case 'r':
            return(1);      //��ʾѡ����"����"
        case 'q':
            qu[4]=0;       //�����˳���

        }
        for(i=0; i<5; i++)
            if (qu[i]==0)               //�Ѿ�ѡ����"�˳�"
            {
                system("cls");
                cout<<"\n\n\n\n\t\t\t��ȷ��Ҫ�˳���ϵͳ��?(Y/N)";
                cin>>temp;
                if (tolower(temp[0])=='y')
                {
                    f_write();
                    system("cls");
                    cout<<"\n\n\n\t\t\t���ѳɹ��˳�ϵͳ!\n\n\n\n\n\n";
                    exit(0);
                }
                else
                {
                    fh=1;
                    break;
                }
            }
            else                        //ѡ����"����"
                if (qu[i]==1)
                {
                    fh=1;
                    break;
                }

    }
    while(fh==1);
    return(-1);

}
//--------------���βε�delete1����------------------
int hospital::delete1(long i)
{
    if(i > I)
    {
        clear();
        cout << "\n\n\n\t\t��Ǹ,������������ţ�";
        system("pause");
        return 1;
    }

    //����ren������
    switch(P[i-1].room)
    {
    case '1':
        renshu[0]--;
        break;
    case '2':
        renshu[1]--;
        break;
    case '3':
        renshu[2]--;
        break;
    case '4':
        renshu[3]--;
        break;
    case '5':
        renshu[4]--;
        break;

    }
    //����Patient�ṹ��
    P[i-1].age = '0';
    P[i-1].zp = '0';
    P[i-1].room = '0';
    strcpy(P[i-1].num, "0");
    //����ghfl�ṹ��
    if(strcmp( P[i-1].time ,"") != 0)
    {
        G.yyrs--;
    }
    else if(strcmp( P[i-1].jz ,"��") == 0)
    {
        G.jzrs--;
    }
    else
    {
        G.drrs--;
    }
    clear();
    cout << "\n\n\n\t\t�����Ѿ��˶��ɹ�!\n\t";
    system("pause");
    return 1;

}
//--------------����delete1����------------------
int hospital::delete1()
{
    clear();
    long i = -1;  //��ʼ��Ϊ-1
    char temp[1000]=""; //Ϊ�˱����������ַ�ʱ������Ĵ�������123��-2�ȵ�
    while(i <= 0)           //����ı�ű������0
    {
        clear();
        cout<<"\n\n\n\t������Ҫ�˹ҵ����:";
        cin>>temp;
        i = atoi(temp);            //���ַ��͵�age1ת�������͸���age2;
    }
    if(i > I)
    {
        clear();
        cout << "\n\n\n\t\t��Ǹ,������������ţ�\n\n";
        system("pause");
        return 1;
    }
    //����ren������
    switch(P[i-1].room)
    {
    case '1':
        renshu[0]--;
        break;
    case '2':
        renshu[1]--;
        break;
    case '3':
        renshu[2]--;
        break;
    case '4':
        renshu[3]--;
        break;
    case '5':
        renshu[4]--;
        break;

    }
    //����Patient�ṹ��
    P[i-1].age = '0';
    P[i-1].zp = '0';
    P[i-1].room = '0';
    strcpy(P[i-1].num, "0");
    //����ghfl�ṹ��
    if(strcmp( P[i-1].time ,"") != 0)
    {
        G.yyrs--;
    }
    else if(strcmp( P[i-1].jz ,"��") == 0)
    {
        G.jzrs--;
    }
    else
    {
        G.drrs--;
    }
    clear();
    cout << "\n\n\n\t\t�����Ѿ��˶��ɹ�!\n\n";
    system("pause");
    return 1;
}
//------------ɾ�������ļ�--------------------
int hospital::delete_file()
{
    FILE *fp1, *fp2, *fp3, *fp4, *fp6;
    char temp[1000]=""; //Ϊ�˱����������ַ�ʱ������Ĵ�������123��-2�ȵ�
    system("cls");
    cout<<"\n\n\t\t���������֮�󽫻��˳��������ֶ���������";
    cout<<"\n\n\n\n\t\t\t��ȷ��Ҫ���ȫ��������?(Y/N)";
    cin>>temp;
    if (tolower(temp[0])=='y') //ѡ������
    {
        fp2 = fopen("ȫ�ֱ���.txt", "wb");
        fp1 = fopen("��������.txt", "wb");  //ֻ���ķ�ʽ��
        fp3 = fopen("ԤԼ����.txt", "wb");
        fp4 = fopen("�Һ�����.txt", "wb");
        fp6 = fopen("��������.txt", "wb");

        remove("ȫ�ֱ���.txt");
        remove("��������.txt");
        remove("ԤԼ����.txt");
        remove("�Һ�����.txt");
        remove("��������.txt");

        fclose(fp4);
        fclose(fp3);
        fclose(fp1);
        fclose(fp2);
        fclose(fp6);

        system("cls");
        cout << "\n\n\n\t\t���������Ѿ�ȫ�����!\n\n";
        exit(1);
    }
    else //ѡ���˷�
    {
        return 1;
    }
    cout << "\n\n\n\t\t���������Ѿ�ȫ�����!\n\n";
    system("pause");
    return 1;
}







