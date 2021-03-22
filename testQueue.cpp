#include "CycleArrayQueue.h"
#include <iostream>
using namespace std;

int main(){
	int i;
	CycleArrayQueue<char> que(20);                             //ȱʡΪ20Ԫ�ض��У�����19

	char str1[]="abcdefghijklmnopqr";//19��Ԫ�أ�������������
	//que.MakeEmpty();

	for(i=0;i<19;i++) 
		que.AddTail(str1[i]);

	if(que.IsFull()) cout<<"����";

	cout<<"����Ԫ�أ�"<<que.GetCount()<<endl;

	char temp;

	for(i=0;i<19;i++) 
	{
		que.GetHead(temp);           //�Ƚ��ȳ�
		cout<<temp<<' ';
	}
		cout<<endl;	

	if(que.IsEmpty()) cout<<"�ӿ�";
		cout<<"����Ԫ�أ�"<<que.GetCount()<<endl;

	return 0;
}