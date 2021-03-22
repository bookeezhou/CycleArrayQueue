#include "CycleArrayQueue.h"
#include <iostream>
using namespace std;

int main(){
	int i;
	CycleArrayQueue<char> que(20);                             //缺省为20元素队列，可用19

	char str1[]="abcdefghijklmnopqr";  //19个元素，包括串结束符
	//que.MakeEmpty();

	for(i=0;i<19;i++) 
		que.AddTail(str1[i]);

	if(que.IsFull()) cout<<"����";

	cout<<"����Ԫ�أ�"<<que.GetCount()<<endl;

	char temp;

	for(i=0;i<19;i++) 
	{
		que.GetHead(temp);          //先进先出
		cout<<temp<<' ';
	}
		cout<<endl;	

	if(que.IsEmpty()) cout<<"队空";
		cout<<"共有元素:"<<que.GetCount()<<endl;

	return 0;
}