#include<bits/stdc++.h>
#include<conio.h>
#include<direct.h>
#include<Windows.h>
#define v "  "
using namespace std;
int n,ex,ey;
int player_bf=1;//玩家过到哪个剧情了。
long long player_blood=1000;//玩家血量。
string diren[7];//攻击敌人的选项。
int diren_blood[7];//敌人的血量。
int dr;//敌人最多有多少个。
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
//1-3是读取和读入存档装置！
user_data user;//存档储存器。
const int BOARD_SIZE=60;//地图范围。
const int MAP_SIZE=30;
const int xx[]={-1,1,0,0},yy[]={0,0,-1,1};//攻击四方向。
const string dz[]={"╃","╄","╅","╆"};//大招图标。
string a[BOARD_SIZE][BOARD_SIZE],mp[MAP_SIZE][MAP_SIZE];
void yu_yin(string s,string name){//语音包。
	s="defines\\sound\\"+name+"\\"+s+".mp3";
//	alert("提示","background_music_name="+background_music_name);
	system(("cd \""+std::string(_getcwd(NULL,0))+"\"").c_str());
	system(("start "+s).c_str());
}
void gotoxy(int i,int j){//控制输出位置。
    COORD position={j,i};SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
    return;
}
void PrintBoard(int x,int y){//输出地图。
    system("cls");
    for(int i=1;i<BOARD_SIZE;++i){
        for(int j=1;j<BOARD_SIZE;++j){
        	if(i==x&&j==y)cout<<"空";
            else if(i==x-1&&j==y-1)cout<<"派";
        	else if(i==ex&&j==ey&&!(i==x&&j==y))cout<<"！";
        	else cout<<a[i][j];
        }cout<<endl;
    }cout<<"当前坐标:("<<x+1<<','<<y+1<<")\n";
    cout<<"任务坐标:("<<ex+1<<','<<ey+1<<")\n";
	return;
}
void print_zhan_dou(string s){//输出战斗地图。
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
void dui_hua_kuang(string people_name,string talk,int x,int y){//对话框。
	system("cls");
	PrintBoard(x,y);
	gotoxy(22,(60-people_name.size())/2+20);
    cout<<people_name;
    gotoxy(23,34);
    for(int i=0;i<32;i++)cout<<'-';
    gotoxy(24,(60-talk.size())/2+20);
    cout<<talk;
    if(people_name!="空"&&people_name!="龙")yu_yin(talk,people_name);
    gotoxy(27,39);
    cout<<"按空格继续/结束。";
    Sleep(talk.size()*100);
    char key=_getch();
    while(key!=' ')key=_getch();
    return;
}
void wan_jia_de_hua(string talk1,string talk2,int x,int y){//玩家说的话。
	gotoxy(21,60);
	cout<<"1:"<<talk1;
	gotoxy(22,60);
	cout<<"2:"<<talk2;
    gotoxy(24,60);
    cout<<"按数字选择。";
    char key=_getch();
    while(key!='1'&&key!='2')key=_getch();
    if(key=='1')dui_hua_kuang("空",talk1,x,y);
    else dui_hua_kuang("空",talk2,x,y);
    return;
}
void ju_qing(int x){//剧情。
	if(x==1){//剧情1
		system("cls");
		gotoxy(30,29);
		printf("那天，\n");
		Sleep(1000);
		system("cls");
		gotoxy(30,22);
		printf("有一位陌生的神灵阻挡了我们的去路\n");
		Sleep(3000);
		system("cls");
		gotoxy(30,27);
		printf("她封印住了我\n");
		Sleep(2000);
		system("cls");
		gotoxy(30,26);
		printf("也带走了我的妹妹\n");
		Sleep(2000);
		system("cls");
		gotoxy(30,26);
		printf("我一直在这里生活着\n");
		Sleep(2000);
		system("cls");
		gotoxy(30,26);
		printf("直到后来遇见了你\n");
		Sleep(2000);
		system("cls");
		gotoxy(30,22);
		printf("对呀对呀，要不是你我那时早淹死了\n");
		Sleep(3000);
		system("cls");
		gotoxy(30,29);
		printf("……\n");
		Sleep(1000);
		system("cls");
	}
	if(x==2){//剧情2
		system("cls");
		gotoxy(30,25);
		printf("这里就是传送锚点了。\n");
		Sleep(1000);
		system("cls");
		gotoxy(30,26);
		printf("快看！是史莱姆！\n");
		Sleep(1000);
		system("cls");
	}
	if(x==3){//剧情3
		dui_hua_kuang("派蒙","如今的提瓦特大陆分由七神统治",40,36);
		//第一个人名,第二个他/她/它说的话。
		dui_hua_kuang("派蒙","现在如果你要去找妹妹的话",40,36);
		dui_hua_kuang("派蒙","那么去风之国——蒙德最好",40,36);
	    dui_hua_kuang("派蒙","而且风的消息最灵通",40,36);
	    system("cls");
	    gotoxy(23,31);
		printf("正在前往星落湖…");
		for(int i=0;i<3;i++)
			for(int w=0;w<4;w++){gotoxy(23,44+w*2);printf("…      ");Sleep(300);}
	}
	if(x==4){//剧情4
		dui_hua_kuang("派蒙","这就是蒙德的神像了",40,36);
	    dui_hua_kuang("派蒙","看看你能不能祈求神的回应",40,36);
	    system("cls");
	    PrintBoard(40,36);
	    gotoxy(23,31);
		printf("你把手放了上去");
		Sleep(500);
		system("cls");
		PrintBoard(40,36);
	    gotoxy(23,31);
		printf("紧接着,你感到一阵头晕");
		Sleep(2000);
		system("cls");
		PrintBoard(40,36);
	    gotoxy(23,31);
	    PrintBoard(40,36);
		printf("过了一会,你清醒了过来");
		PrintBoard(40,36);
		gotoxy(24,31);
		printf("你也突然发现了,你会使用元素力");
		Sleep(2000);
		system("cls");
		dui_hua_kuang("派蒙","欸？你能使用元素力了？",40,36);
		dui_hua_kuang("空","好像在是这样,有什么问题吗?",40,36);
		dui_hua_kuang("派蒙","这个世界里,如果人们想使用元素力,都需要神之眼",40,36);
		dui_hua_kuang("派蒙","不好,又是史莱姆!",40,36);
	}
	if(x==5){//剧情5
		dui_hua_kuang("派蒙","终于清除完了",40,36);
		dui_hua_kuang("派蒙","那我们先去低语森林吧!",40,36);
		system("cls");
	    gotoxy(23,31);
		printf("正在前往低语森林…");
		for(int i=0;i<3;i++)
			for(int w=0;w<4;w++){gotoxy(23,47+w*2);printf("…      ");Sleep(300);}
		a[40][36]="绿",a[40][31]="龙";
		PrintBoard(19,1);
		dui_hua_kuang("派蒙","这里就是低语森林了",19,1);
		dui_hua_kuang("温迪","没事的,请相信我",19,1);
		dui_hua_kuang("龙","我再也不相信你了，巴巴托斯",19,1);
		system("cls");
		PrintBoard(19,1);
	    gotoxy(23,31);
		printf("一阵风声后龙飞走了");
		a[40][31]="红色水晶",a[40][36]=v;
		Sleep(1000);
		dui_hua_kuang("派蒙","那一位绿衣男子居然能跟龙交谈,太厉害了",19,1);
		dui_hua_kuang("派蒙","欸？那个红色水晶是什么,我们去看看吧",19,1);
		system("cls");
	}
	if(x==6){//剧情6 
		dui_hua_kuang("派蒙","看上去好危险的样子",38,29);
		dui_hua_kuang("派蒙","那我们先收起来吧!",38,29);
		wan_jia_de_hua("既然都危险了,我们为什么还要带?","好吧",38,29);
	}
	return;
}
void start(){//初始动画。
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	gotoxy(30,36);
	cout<<"MI HU YO\n";
	gotoxy(31,29);
	cout<<"tech otakus save the world";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	gotoxy(32,31);
	printf("游戏加载中…");
	Sleep(500);
	for(int i=0;i<3;i++)
		for(int w=0;w<4;w++){gotoxy(32,41+w*2);printf("…      ");Sleep(500);}
	ifstream filei("原神存档.txt",ios::in);
	ofstream fileo("原神存档.txt",ios::out|ios::app);
	while(filei>>user)users[user.name]=user;
	system("cls");
	gotoxy(30,26);
	cout<<"是否读取存档?(Y=读取/N=不读):";
	char key=_getch();
	system("cls");
    switch(key){
        case 'Y':case 'y':
        	{
	        	while(1){
	        		string name,password;
		        	gotoxy(30,29);
		        	cout<<"名字:";
		        	cin>>name;
		        	system("cls");
		       		gotoxy(30,29);
		       		cout<<"密码:";
		       		cin>>password;
		       		if(users[name].password==password){
		       			user=users[name];
		       			player_blood=user.blood;
		       			player_bf=user.bufeng;
		       			return;
					}else{
						gotoxy(30,25);
						cout<<"用户名未找到或密码错误!\n";
						Sleep(1000);
						system("cls");
					}
				}
			}break;
        case 'N':case 'n':
			gotoxy(30,26);
			cout<<"新建一个名字:";
			cin>>user.name;
			system("cls");
			gotoxy(30,29);
			cout<<"密码:";
			cin>>user.password;
			user.blood=1000;
			while(users[user.name].password.size()){
				system("cls");
				gotoxy(30,30);
				cout<<"用户已存在！\n";
				Sleep(2000);
				gotoxy(30,26);
				cout<<"新建一个名字:";
				cin>>user.name;
				system("cls");
				gotoxy(30,29);
				cout<<"密码:";
				cin>>user.password;
			}//用户存在时的处理 
			fileo<<user<<'\n';
			break;
    }system("cls");
	gotoxy(32,31);
	printf("游戏加载中…");
	Sleep(300);
	for(int i=0;i<3;i++)
		for(int w=0;w<4;w++){gotoxy(32,41+w*2);printf("…      ");Sleep(300);}
 	system("cls");
 	gotoxy(30,26);
	cout<<"是否观看剧情?(Y=观看/N=不看):";
	key=_getch();
    switch(key){
        case 'Y':
            break;
        case 'N':case 'n':
        	return;
    }ju_qing(1);
	return;
}
bool IsValidMove(int x,int y){//判断是否可以走过去。
    return (x>0&&x<BOARD_SIZE&&y>0&&y<BOARD_SIZE&&a[x][y]==v);
}
void PlayerMove(int &x,int &y){//上下左右移动(玩家)。
    while(1){
    	int roud;//记录上次走的方向。
        char key=_getch();
        if(x==ex&&y==ey)return;
        switch(key){
            case 'w':  //移动上方向
                if(x>1&&IsValidMove(x-1,y))x--;
                PrintBoard(x,y);
                roud=0;
                break;
            case 'a':  //移动左方向
                if(y>1&&IsValidMove(x,y-1))y--;
                PrintBoard(x,y);
                roud=2;
                break;
            case 's':  //移动下方向
                if(x<BOARD_SIZE&&IsValidMove(x+1,y))x++;
                PrintBoard(x,y);
                roud=1;
                break;
            case 'd':  //移动右方向
                if(y<BOARD_SIZE&&IsValidMove(x,y+1))y++;
                PrintBoard(x,y);
                roud=3;
                break;
            case 'j':  //攻击
            	a[x+xx[roud]][y+yy[roud]]="╳";
            	PrintBoard(x,y);
            	Sleep(300);
            	a[x+xx[roud]][y+yy[roud]]=v;
            	PrintBoard(x,y);
                break;
            case 'l':  //冲刺
            	x+=xx[roud]*5,y+=yy[roud]*5;
            	if(!IsValidMove(x,y)){
            		if(x<0)x=0;
            		if(y<0)y=0;
            		if(x>=BOARD_SIZE)x=BOARD_SIZE-1;
            		if(y>=BOARD_SIZE)y=BOARD_SIZE-1;
				}PrintBoard(x,y);
                break;
            case 'e':  //技能 
            	a[x+xx[roud]][y+yy[roud]]="○";
            	PrintBoard(x,y);
            	Sleep(2000);
            	a[x+xx[roud]][y+yy[roud]]="●";
            	for(int i=2;i<=5;i++){
            		a[x+xx[roud]*(i-1)][y+yy[roud]*(i-1)]=v;
            		a[x+xx[roud]*i][y+yy[roud]*i]="●";
            		PrintBoard(x,y);
				}a[x+xx[roud]*5][y+yy[roud]*5]=v;
            	PrintBoard(x,y);
                break;
            case 'q':  //大招
            	a[x+xx[roud]][y+yy[roud]]="╄";
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
void zhan_dou_dong_hua(string s){//进入战斗的动画。
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
void computer(string s,string x){//人机。
	gotoxy(15,(60-s.size())/2);
	cout<<"史莱姆使用了"<<s;
	Sleep(2000);
	if(s=="攻击"){
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
	}if(s=="下落攻击"){
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
void w_j_g_j_m_b(int &x){//玩家攻击目标。
	while(1){
		system("cls");
		print_zhan_dou(diren[1]);
		gotoxy(30,0);
		cout<<"ad,左右切换目标,空格确定";
		gotoxy(31,0);
		cout<<"你现在的攻击目标(第几个):"<<x;
        char key=_getch();
        switch(key){
            case 'a':  //目标往左
                if(x>1)x--;
                break;
            case 'd':  //目标往右 
                if(x<dr)x++;
                break;
            case ' ':
            	return;
            default:
                break;
        }
    }
}
void wan_jia_gong_ji(){//玩家攻击。
	int g_j_m_b=1;//攻击目标。
	while(1){
		char key=_getch();
		switch(key){
		    case 'j':
		    	w_j_g_j_m_b(g_j_m_b);
		    	system("cls");
		    	mp[0][0]="﹩";
		    	mp[1][1]="﹩";
		    	print_zhan_dou(diren[1]);
		    	for(int i=8;i<20;i++){
		    		system("cls");
		    		mp[i-2][i-2]=v;
		    		print_zhan_dou(diren[1]);
		    		mp[i][i]="﹩";
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
				cout<<"输入错误!!!";
				Sleep(1000);
				system("cls");
				print_zhan_dou(diren[g_j_m_b]);
				gotoxy(30,0);
				cout<<"到你的回合了!";
				Sleep(1000);
				gotoxy(31,0);
				cout<<"j单个目标攻击,k单个目标多次攻击。";
		       	break;
		}
	}
}
void jin_ru_zhan_dou(string s,string x){//进入战斗。
	int u=1;//到谁的回合。
	int power=0;//玩家大招能量。
	if(s=="遇袭")u=0;
	mp[16][4]="派",mp[17][5]="空";
	zhan_dou_dong_hua(s),print_zhan_dou(x);
	while(1){
		if(!u){
			for(int i=1;i<=dr;i++)
				if(diren[i]=="史莱姆"){
					int nx=rand()%2;
					if(nx==0)computer("攻击","* ");
					else computer("下落攻击","⊕");
				}
		}else{
			gotoxy(30,0);
			cout<<"到你的回合了!";
			Sleep(1000);
			gotoxy(31,0);
			cout<<"j单个目标攻击,k单个目标多次攻击。";
			wan_jia_gong_ji();
		}u=!u;
		int sum=0;
		for(int i=1;i<=dr;i++){
			if(diren_blood[i]<=0)diren[i]="",sum++;
		}if(sum==dr){
			system("cls");
			gotoxy(30,28);
			cout<<"你胜利了!";
			return;
		}if(player_blood<=0){
			system("cls");
			gotoxy(30,26);
			cout<<"你输了!请再来一遍!";
			Sleep(1000);
			diren[1]="史莱姆",diren_blood[1]=65,dr=1;
    		jin_ru_zhan_dou("遇袭","史莱姆");
    		return;
		}
	}return;
}
void wan_jia_de_jin_du(){//玩家的进度。
	int x=19,y=1;
	if(player_bf==1){//第一个进度。
	    a[41][37]="锚点";
	    ex=40,ey=36;
	    PrintBoard(x,y);
	    PlayerMove(x,y);
	    gotoxy(23,47);
	    cout<<"传送锚点已解锁";
	    Sleep(3000);
	    ju_qing(2);
	    diren[1]="史莱姆",mp[7][20]="史莱姆",diren_blood[1]=65,dr=1;
	    jin_ru_zhan_dou("遇袭","史莱姆");
	    Sleep(1000);
	    PrintBoard(x,y);
	}
	if(player_bf==2){//第二个进度。
		ju_qing(3);
		x=19,y=1;
		ex=40,ey=36;
		a[41][37]="神像";
		PrintBoard(x,y);
	    PlayerMove(x,y);
	    system("cls");
	    gotoxy(23,31);
		printf("七天神像已开启");
		Sleep(3000);
	}
	if(player_bf==3){//第三个进度。
		ju_qing(4);
	    diren[1]="史莱姆",diren[2]="史莱姆",diren_blood[1]=diren_blood[2]=65,dr=2;
	    mp[7][20]="史莱姆1",mp[7][22]="史莱姆2";
	    jin_ru_zhan_dou("遇袭","史莱姆");
	}
	if(player_bf==4){//第四个进度。
		ex=60,ey=61;
		for(int i=0;i<BOARD_SIZE;i++){//初始化。
	        for(int j=0;j<BOARD_SIZE;j++)a[i][j]=v;
	    }ju_qing(5);
	    x=19,y=1;
	    ex=38,ey=29;
	    PlayerMove(x,y);
	}
	if(player_bf==5){//第五个进度。
		ju_qing(6);
	}
	return;
}
void bao_cun_wan_jia_de_cun_dang(){//保存玩家的存档。
	ifstream filei("原神存档.txt",ios::in);
	ofstream fileo("原神存档.txt",ios::out|ios::app);
	user.bufeng=player_bf,user.blood=player_blood;
	fileo<<user<<'\n';
}
int main(){
	srand(time(0));//rand()随机数初始化。
    for(int i=0;i<BOARD_SIZE;i++){//初始化。
        for(int j=0;j<BOARD_SIZE;j++)a[i][j]=v;
    }for(int i=0;i<MAP_SIZE;i++){//初始化。
        for(int j=0;j<MAP_SIZE;j++)mp[i][j]=v;
    }start();
	while(player_bf!=6)wan_jia_de_jin_du(),player_bf++,bao_cun_wan_jia_de_cun_dang();
	
    return 0;
}
