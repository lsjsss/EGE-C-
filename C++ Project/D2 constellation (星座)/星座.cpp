#include "stdafx.h"
#include "iostream"
#include "string" 
using namespace std;

int main(){	/*�������ձ���*/	
int  value_birth_month;	
int  value_birth_date;	/*����*/	
string value_constell;	
string constells[12][2] = {	{ "Ħ����","ˮƿ��" },//һ��	
							{ "ˮƿ��","˫����" },//����	
							{ "˫����","������" },//����	
							{ "������","��ţ��" },//����
							{ "��ţ��","˫����" },//����
							{ "˫����","��з��" },//����	
							{ "��з��","ʨ����" },//����
							{ "ʨ����","��Ů��" },//����
							{ "��Ů��","�����" },//����
							{ "�����","��Ы��" },//ʮ��	
							{ "��Ы��","������" },//ʮһ��	
							{ "������","Ħ����" },//ʮһ��	
						};	//ÿ���������������������е�ֵ��Ӧÿ���������������ķָ�����	
int constell_dates[]{ 20,19,21,20,21,22,23,23,23,24,23,22 };	
cout << "�������·ݣ�";	
cin >> value_birth_month;	
cout << "���������ڣ�";	
cin >> value_birth_date; 	/*��һά����·ݣ��ڶ�ά�����յ�����/ÿ���¶�Ӧ�ķָ����ڣ�constell_dates��,	   Ϊ0�ͱ�ʾһ�����е�ǰһ������������Ϊ��һ��������	��������Ϊ5��6�ţ����Ӧ��� constells[4][0] ��Ӧ��ţ��*/	
cout << constells[value_birth_month - 1][value_birth_date / constell_dates[value_birth_month]] << endl;	
return 0;
}

