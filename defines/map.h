#ifndef MAP_H_
#define MAP_H_
#include<bits/stdc++.h>
#include<array>
using namespace std;
namespace di_tu{
	array<array<string,30>,30> a;
	array<array<string,30>,30> print(string s);
};
array<array<string,30>,30> di_tu::print(string s){//��ͼ��
	if(s=="�ɵ�"){
		for(int i=1;i<30;i++){
			for(int j=1;j<30;j++){
				if(i==1||j==1||j==29||i==29)a[i][j]="ǽ";
				else a[i][j]="  ";
			}
		}for(int i=12;i<19;i++)a[i][1]="  ";
	}a[8][3]="��",a[15][10]="ð",a[17][20]="��";
	return a;
}
#endif
