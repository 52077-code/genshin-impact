#include<bits/stdc++.h>
#include<conio.h>
#include<direct.h>
#include<Windows.h>
#define v "  "
using namespace std;
int n,ex,ey;
int player_bf=1;//��ҹ����ĸ������ˡ�
long long player_blood=1000;//���Ѫ����
string diren[7];//�������˵�ѡ�
int diren_blood[7];//���˵�Ѫ����
int dr;//��������ж��ٸ���
struct user_data{//1
	string name,password;
	long long blood;
	long long bufeng;
};
ostream &operator<<(ostream &os,user_data &user){//2
	os<<user.name<<' '<<user.password<<'\n'<<user.blood<<'\n'<<user.bufeng;
	return os;
}
istream &operator>>(istream &is,user_data &user){//3
	is>>user.name>>user.password>>user.blood>>user.bufeng;
	return is;
}
map<string,user_data> users;
//1-3�Ƕ�ȡ�Ͷ���浵װ�ã�
user_data user;//�浵��������
const int BOARD_SIZE=60;//��ͼ��Χ��
const int MAP_SIZE=30;
const int xx[]={-1,1,0,0},yy[]={0,0,-1,1};//�����ķ���
const string dz[]={"��","��","��","��"};//����ͼ�ꡣ
string a[BOARD_SIZE][BOARD_SIZE],mp[MAP_SIZE][MAP_SIZE];
void yu_yin(string s,string name){//��������
	s="defines\\sound\\"+name+"\\"+s+".mp3";
//	alert("��ʾ","background_music_name="+background_music_name);
	system(("cd \""+std::string(_getcwd(NULL,0))+"\"").c_str());
	system(("start "+s).c_str());
}
void gotoxy(int i,int j){//�������λ�á�
    COORD position={j,i};SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
    return;
}
void PrintBoard(int x,int y){//�����ͼ��
    system("cls");
    for(int i=1;i<BOARD_SIZE;++i){
        for(int j=1;j<BOARD_SIZE;++j){
        	if(i==x&&j==y)cout<<"��";
            else if(i==x-1&&j==y-1)cout<<"��";
        	else if(i==ex&&j==ey&&!(i==x&&j==y))cout<<"��";
        	else cout<<a[i][j];
        }cout<<endl;
    }cout<<"��ǰ����:("<<x+1<<','<<y+1<<")\n";
    cout<<"��������:("<<ex+1<<','<<ey+1<<")\n";
	return;
}
void print_zhan_dou(string s){//���ս����ͼ��
	system("cls");
	for(int i=0;i<MAP_SIZE;i++){
        for(int j=0;j<MAP_SIZE;j++)cout<<mp[i][j];
        cout<<endl;
    }gotoxy(17,1);
    cout<<player_blood;
    for(int i=0;i<dr;i++){
    	gotoxy(7,16-i*5);
	    cout<<diren_blood[i+1];
	}return;
}
void dui_hua_kuang(string people_name,string talk,int x,int y){//�Ի���
	system("cls");
	PrintBoard(x,y);
	gotoxy(22,(60-people_name.size())/2+20);
    cout<<people_name;
    gotoxy(23,34);
    for(int i=0;i<32;i++)cout<<'-';
    gotoxy(24,(60-talk.size())/2+20);
    cout<<talk;
    if(people_name!="��"&&people_name!="��")yu_yin(talk,people_name);
    gotoxy(27,39);
    cout<<"���ո����/������";
    Sleep(talk.size()*100);
    char key=_getch();
    while(key!=' ')key=_getch();
    return;
}
void wan_jia_de_hua(string talk1,string talk2,int x,int y){//���˵�Ļ���
	gotoxy(21,60);
	cout<<"1:"<<talk1;
	gotoxy(22,60);
	cout<<"2:"<<talk2;
    gotoxy(24,60);
    cout<<"������ѡ��";
    char key=_getch();
    while(key!='1'&&key!='2')key=_getch();
    if(key=='1')dui_hua_kuang("��",talk1,x,y);
    else dui_hua_kuang("��",talk2,x,y);
    return;
}
void ju_qing(int x){//���顣
	if(x==1){//����1
		system("cls");
		gotoxy(30,29);
		printf("���죬\n");
		Sleep(1000);
		system("cls");
		gotoxy(30,22);
		printf("��һλİ���������赲�����ǵ�ȥ·\n");
		Sleep(3000);
		system("cls");
		gotoxy(30,27);
		printf("����ӡס����\n");
		Sleep(2000);
		system("cls");
		gotoxy(30,26);
		printf("Ҳ�������ҵ�����\n");
		Sleep(2000);
		system("cls");
		gotoxy(30,26);
		printf("��һֱ������������\n");
		Sleep(2000);
		system("cls");
		gotoxy(30,26);
		printf("ֱ��������������\n");
		Sleep(2000);
		system("cls");
		gotoxy(30,22);
		printf("��ѽ��ѽ��Ҫ����������ʱ��������\n");
		Sleep(3000);
		system("cls");
		gotoxy(30,29);
		printf("����\n");
		Sleep(1000);
		system("cls");
	}
	if(x==2){//����2
		system("cls");
		gotoxy(30,25);
		printf("������Ǵ���ê���ˡ�\n");
		Sleep(1000);
		system("cls");
		gotoxy(30,26);
		printf("�쿴����ʷ��ķ��\n");
		Sleep(1000);
		system("cls");
	}
	if(x==3){//����3
		dui_hua_kuang("����","���������ش�½��������ͳ��",40,36);
		//��һ������,�ڶ�����/��/��˵�Ļ���
		dui_hua_kuang("����","���������Ҫȥ�����õĻ�",40,36);
		dui_hua_kuang("����","��ôȥ��֮�������ɵ����",40,36);
	    dui_hua_kuang("����","���ҷ����Ϣ����ͨ",40,36);
	    system("cls");
	    gotoxy(23,31);
		printf("����ǰ���������");
		for(int i=0;i<3;i++)
			for(int w=0;w<4;w++){gotoxy(23,44+w*2);printf("��      ");Sleep(300);}
	}
	if(x==4){//����4
		dui_hua_kuang("����","������ɵµ�������",40,36);
	    dui_hua_kuang("����","�������ܲ���������Ļ�Ӧ",40,36);
	    system("cls");
	    PrintBoard(40,36);
	    gotoxy(23,31);
		printf("����ַ�����ȥ");
		Sleep(500);
		system("cls");
		PrintBoard(40,36);
	    gotoxy(23,31);
		printf("������,��е�һ��ͷ��");
		Sleep(2000);
		system("cls");
		PrintBoard(40,36);
	    gotoxy(23,31);
	    PrintBoard(40,36);
		printf("����һ��,�������˹���");
		PrintBoard(40,36);
		gotoxy(24,31);
		printf("��ҲͻȻ������,���ʹ��Ԫ����");
		Sleep(2000);
		system("cls");
		dui_hua_kuang("����","�G������ʹ��Ԫ�����ˣ�",40,36);
		dui_hua_kuang("��","������������,��ʲô������?",40,36);
		dui_hua_kuang("����","���������,���������ʹ��Ԫ����,����Ҫ��֮��",40,36);
		dui_hua_kuang("����","����,����ʷ��ķ!",40,36);
	}
	if(x==5){//����5
		dui_hua_kuang("����","�����������",40,36);
		dui_hua_kuang("����","��������ȥ����ɭ�ְ�!",40,36);
		system("cls");
	    gotoxy(23,31);
		printf("����ǰ������ɭ�֡�");
		for(int i=0;i<3;i++)
			for(int w=0;w<4;w++){gotoxy(23,47+w*2);printf("��      ");Sleep(300);}
		a[40][36]="��",a[40][31]="��";
		PrintBoard(19,1);
		dui_hua_kuang("����","������ǵ���ɭ����",19,1);
		dui_hua_kuang("�µ�","û�µ�,��������",19,1);
		dui_hua_kuang("��","����Ҳ���������ˣ��Ͱ���˹",19,1);
		system("cls");
		PrintBoard(19,1);
	    gotoxy(23,31);
		printf("һ���������������");
		a[40][31]="��ɫˮ��",a[40][36]=v;
		Sleep(1000);
		dui_hua_kuang("����","��һλ�������Ӿ�Ȼ�ܸ�����̸,̫������",19,1);
		dui_hua_kuang("����","�G���Ǹ���ɫˮ����ʲô,����ȥ������",19,1);
		system("cls");
	}
	if(x==6){//����6 
		dui_hua_kuang("����","����ȥ��Σ�յ�����",38,29);
		dui_hua_kuang("����","����������������!",38,29);
		wan_jia_de_hua("��Ȼ��Σ����,����Ϊʲô��Ҫ��?","�ð�",38,29);
	}
	return;
}
void start(){//��ʼ������
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	gotoxy(30,36);
	cout<<"MI HU YO\n";
	gotoxy(31,29);
	cout<<"tech otakus save the world";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	gotoxy(32,31);
	printf("��Ϸ�����С�");
	Sleep(500);
	for(int i=0;i<3;i++)
		for(int w=0;w<4;w++){gotoxy(32,41+w*2);printf("��      ");Sleep(500);}
	ifstream filei("ԭ��浵.txt",ios::in);
	ofstream fileo("ԭ��浵.txt",ios::out|ios::app);
	while(filei>>user)users[user.name]=user;
	system("cls");
	gotoxy(30,26);
	cout<<"�Ƿ��ȡ�浵?(Y=��ȡ/N=����):";
	char key=_getch();
	system("cls");
    switch(key){
        case 'Y':case 'y':
        	{
	        	while(1){
	        		string name,password;
		        	gotoxy(30,29);
		        	cout<<"����:";
		        	cin>>name;
		        	system("cls");
		       		gotoxy(30,29);
		       		cout<<"����:";
		       		cin>>password;
		       		if(users[name].password==password){
		       			user=users[name];
		       			player_blood=user.blood;
		       			player_bf=user.bufeng;
		       			return;
					}else{
						gotoxy(30,25);
						cout<<"�û���δ�ҵ����������!\n";
						Sleep(1000);
						system("cls");
					}
				}
			}break;
        case 'N':case 'n':
			gotoxy(30,26);
			cout<<"�½�һ������:";
			cin>>user.name;
			system("cls");
			gotoxy(30,29);
			cout<<"����:";
			cin>>user.password;
			user.blood=1000;
			while(users[user.name].password.size()){
				system("cls");
				gotoxy(30,30);
				cout<<"�û��Ѵ��ڣ�\n";
				Sleep(2000);
				gotoxy(30,26);
				cout<<"�½�һ������:";
				cin>>user.name;
				system("cls");
				gotoxy(30,29);
				cout<<"����:";
				cin>>user.password;
			}//�û�����ʱ�Ĵ��� 
			fileo<<user<<'\n';
			break;
    }system("cls");
	gotoxy(32,31);
	printf("��Ϸ�����С�");
	Sleep(300);
	for(int i=0;i<3;i++)
		for(int w=0;w<4;w++){gotoxy(32,41+w*2);printf("��      ");Sleep(300);}
 	system("cls");
 	gotoxy(30,26);
	cout<<"�Ƿ�ۿ�����?(Y=�ۿ�/N=����):";
	key=_getch();
    switch(key){
        case 'Y':
            break;
        case 'N':case 'n':
        	return;
    }ju_qing(1);
	return;
}
bool IsValidMove(int x,int y){//�ж��Ƿ�����߹�ȥ��
    return (x>0&&x<BOARD_SIZE&&y>0&&y<BOARD_SIZE&&a[x][y]==v);
}
void PlayerMove(int &x,int &y){//���������ƶ�(���)��
    while(1){
    	int roud;//��¼�ϴ��ߵķ���
        char key=_getch();
        if(x==ex&&y==ey)return;
        switch(key){
            case 'w':  //�ƶ��Ϸ���
                if(x>1&&IsValidMove(x-1,y))x--;
                PrintBoard(x,y);
                roud=0;
                break;
            case 'a':  //�ƶ�����
                if(y>1&&IsValidMove(x,y-1))y--;
                PrintBoard(x,y);
                roud=2;
                break;
            case 's':  //�ƶ��·���
                if(x<BOARD_SIZE&&IsValidMove(x+1,y))x++;
                PrintBoard(x,y);
                roud=1;
                break;
            case 'd':  //�ƶ��ҷ���
                if(y<BOARD_SIZE&&IsValidMove(x,y+1))y++;
                PrintBoard(x,y);
                roud=3;
                break;
            case 'j':  //����
            	a[x+xx[roud]][y+yy[roud]]="�w";
            	PrintBoard(x,y);
            	Sleep(300);
            	a[x+xx[roud]][y+yy[roud]]=v;
            	PrintBoard(x,y);
                break;
            case 'l':  //���
            	x+=xx[roud]*5,y+=yy[roud]*5;
            	if(!IsValidMove(x,y)){
            		if(x<0)x=0;
            		if(y<0)y=0;
            		if(x>=BOARD_SIZE)x=BOARD_SIZE-1;
            		if(y>=BOARD_SIZE)y=BOARD_SIZE-1;
				}PrintBoard(x,y);
                break;
            case 'e':  //���� 
            	a[x+xx[roud]][y+yy[roud]]="��";
            	PrintBoard(x,y);
            	Sleep(2000);
            	a[x+xx[roud]][y+yy[roud]]="��";
            	for(int i=2;i<=5;i++){
            		a[x+xx[roud]*(i-1)][y+yy[roud]*(i-1)]=v;
            		a[x+xx[roud]*i][y+yy[roud]*i]="��";
            		PrintBoard(x,y);
				}a[x+xx[roud]*5][y+yy[roud]*5]=v;
            	PrintBoard(x,y);
                break;
            case 'q':  //����
            	a[x+xx[roud]][y+yy[roud]]="��";
            	for(int i=2;i<=10;i++){
            		a[x+xx[roud]*(i-1)][y+yy[roud]*(i-1)]=v;
            		a[x+xx[roud]*i][y+yy[roud]*i]=dz[i%4];
            		PrintBoard(x,y);
				}a[x+xx[roud]*10][y+yy[roud]*10]=v;
            	PrintBoard(x,y);
                break;
            default:
                break;
        }
    }
}
void zhan_dou_dong_hua(string s){//����ս���Ķ�����
	for(int i=0;i<10;i++){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		gotoxy(30,30);
		cout<<s;
		for(int j=0;j<60;j++){
			int nx=rand()%60,ny=rand()%60;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			gotoxy(nx,ny);
			cout<<'#';
		}Sleep(100);
		system("cls");
	}return;
}
void computer(string s,string x){//�˻���
	gotoxy(15,(60-s.size())/2);
	cout<<"ʷ��ķʹ����"<<s;
	Sleep(2000);
	if(s=="����"){
		int nx=8,ny=19;
		mp[nx][ny]=x;
		print_zhan_dou(x);
		Sleep(300);
		for(int i=1;i<=9;i++){
			mp[nx+i-1][ny+1-i]=v;
			mp[nx+i][ny-i]=x;
			print_zhan_dou(x);
			Sleep(300);
		}nx=17,ny=10;
		for(int i=1;i<=4;i++){
			mp[nx][ny+1-i]=v;
			mp[nx][ny-i]=x;
			print_zhan_dou(x);
		}player_blood-=rand()%21+25;
		mp[nx][ny-4]=v;
		print_zhan_dou(x);
		return;
	}if(s=="���乥��"){
		print_zhan_dou(x);
		Sleep(300);
		for(int j=2;j>=1;j--){
			for(int i=0;i<4;i++)mp[17+xx[i]*j][5+yy[i]*j]=x;
			print_zhan_dou(x);
			Sleep(2000);
			for(int i=0;i<4;i++)mp[17+xx[i]*j][5+yy[i]*j]=v;
		}player_blood-=rand()%21+35;
		print_zhan_dou(x);
		return;
	}
}
void w_j_g_j_m_b(int &x){//��ҹ���Ŀ�ꡣ
	while(1){
		system("cls");
		print_zhan_dou(diren[1]);
		gotoxy(30,0);
		cout<<"ad,�����л�Ŀ��,�ո�ȷ��";
		gotoxy(31,0);
		cout<<"�����ڵĹ���Ŀ��(�ڼ���):"<<x;
        char key=_getch();
        switch(key){
            case 'a':  //Ŀ������
                if(x>1)x--;
                break;
            case 'd':  //Ŀ������ 
                if(x<dr)x++;
                break;
            case ' ':
            	return;
            default:
                break;
        }
    }
}
void wan_jia_gong_ji(){//��ҹ�����
	int g_j_m_b=1;//����Ŀ�ꡣ
	while(1){
		char key=_getch();
		switch(key){
		    case 'j':
		    	w_j_g_j_m_b(g_j_m_b);
		    	system("cls");
		    	mp[0][0]="��";
		    	mp[1][1]="��";
		    	print_zhan_dou(diren[1]);
		    	for(int i=8;i<20;i++){
		    		system("cls");
		    		mp[i-2][i-2]=v;
		    		print_zhan_dou(diren[1]);
		    		mp[i][i]="��";
		    		print_zhan_dou(diren[1]);
				}mp[18][18]=v;
				print_zhan_dou(diren[g_j_m_b]);
				system("cls");
				mp[19][19]=v;
				diren_blood[g_j_m_b]-=15+rand()%21;
				print_zhan_dou(diren[g_j_m_b]);
				system("cls");
		        return;
		    case 'k':
		    	w_j_g_j_m_b(g_j_m_b);
		    	system("cls");
		    	mp[0][0]="sb";
		    	mp[1][1]="sb";
		    	print_zhan_dou(diren[g_j_m_b]);
		    	for(int i=2;i<20;i++){
		    		system("cls");
		    		mp[i-2][i-2]=v;
		    		print_zhan_dou(diren[g_j_m_b]);
		    		mp[i][i]="sb";
		    		print_zhan_dou(diren[g_j_m_b]);
				}mp[18][18]=v;
				print_zhan_dou(diren[g_j_m_b]);
				system("cls");
				mp[19][19]=v;
				diren_blood[g_j_m_b]-=21+rand()%21;
				print_zhan_dou(diren[g_j_m_b]);
				system("cls");
		        return;
			default:
				system("cls");
				print_zhan_dou(diren[g_j_m_b]);
				gotoxy(30,0);
				cout<<"�������!!!";
				Sleep(1000);
				system("cls");
				print_zhan_dou(diren[g_j_m_b]);
				gotoxy(30,0);
				cout<<"����Ļغ���!";
				Sleep(1000);
				gotoxy(31,0);
				cout<<"j����Ŀ�깥��,k����Ŀ���ι�����";
		       	break;
		}
	}
}
void jin_ru_zhan_dou(string s,string x){//����ս����
	int u=1;//��˭�Ļغϡ�
	int power=0;//��Ҵ���������
	if(s=="��Ϯ")u=0;
	mp[16][4]="��",mp[17][5]="��";
	zhan_dou_dong_hua(s),print_zhan_dou(x);
	while(1){
		if(!u){
			for(int i=1;i<=dr;i++)
				if(diren[i]=="ʷ��ķ"){
					int nx=rand()%2;
					if(nx==0)computer("����","* ");
					else computer("���乥��","��");
				}
		}else{
			gotoxy(30,0);
			cout<<"����Ļغ���!";
			Sleep(1000);
			gotoxy(31,0);
			cout<<"j����Ŀ�깥��,k����Ŀ���ι�����";
			wan_jia_gong_ji();
		}u=!u;
		int sum=0;
		for(int i=1;i<=dr;i++){
			if(diren_blood[i]<=0)diren[i]="",sum++;
		}if(sum==dr){
			system("cls");
			gotoxy(30,28);
			cout<<"��ʤ����!";
			return;
		}if(player_blood<=0){
			system("cls");
			gotoxy(30,26);
			cout<<"������!������һ��!";
			Sleep(1000);
			diren[1]="ʷ��ķ",diren_blood[1]=65,dr=1;
    		jin_ru_zhan_dou("��Ϯ","ʷ��ķ");
    		return;
		}
	}return;
}
void wan_jia_de_jin_du(){//��ҵĽ��ȡ�
	int x=19,y=1;
	if(player_bf==1){//��һ�����ȡ�
	    a[41][37]="ê��";
	    ex=40,ey=36;
	    PrintBoard(x,y);
	    PlayerMove(x,y);
	    gotoxy(23,47);
	    cout<<"����ê���ѽ���";
	    Sleep(3000);
	    ju_qing(2);
	    diren[1]="ʷ��ķ",mp[7][20]="ʷ��ķ",diren_blood[1]=65,dr=1;
	    jin_ru_zhan_dou("��Ϯ","ʷ��ķ");
	    Sleep(1000);
	    PrintBoard(x,y);
	}
	if(player_bf==2){//�ڶ������ȡ�
		ju_qing(3);
		x=19,y=1;
		ex=40,ey=36;
		a[41][37]="����";
		PrintBoard(x,y);
	    PlayerMove(x,y);
	    system("cls");
	    gotoxy(23,31);
		printf("���������ѿ���");
		Sleep(3000);
	}
	if(player_bf==3){//���������ȡ�
		ju_qing(4);
	    diren[1]="ʷ��ķ",diren[2]="ʷ��ķ",diren_blood[1]=diren_blood[2]=65,dr=2;
	    mp[7][20]="ʷ��ķ1",mp[7][22]="ʷ��ķ2";
	    jin_ru_zhan_dou("��Ϯ","ʷ��ķ");
	}
	if(player_bf==4){//���ĸ����ȡ�
		ex=60,ey=61;
		for(int i=0;i<BOARD_SIZE;i++){//��ʼ����
	        for(int j=0;j<BOARD_SIZE;j++)a[i][j]=v;
	    }ju_qing(5);
	    x=19,y=1;
	    ex=38,ey=29;
	    PlayerMove(x,y);
	}
	if(player_bf==5){//��������ȡ�
		ju_qing(6);
	}
	return;
}
void bao_cun_wan_jia_de_cun_dang(){//������ҵĴ浵��
	ifstream filei("ԭ��浵.txt",ios::in);
	ofstream fileo("ԭ��浵.txt",ios::out|ios::app);
	user.bufeng=player_bf,user.blood=player_blood;
	fileo<<user<<'\n';
}
int main(){
	srand(time(0));//rand()�������ʼ����
    for(int i=0;i<BOARD_SIZE;i++){//��ʼ����
        for(int j=0;j<BOARD_SIZE;j++)a[i][j]=v;
    }for(int i=0;i<MAP_SIZE;i++){//��ʼ����
        for(int j=0;j<MAP_SIZE;j++)mp[i][j]=v;
    }start();
	while(player_bf!=6)wan_jia_de_jin_du(),player_bf++,bao_cun_wan_jia_de_cun_dang();
	
    return 0;
}
