

////////////////////////////////////////////////////////////////////////
//Copyright @2007,xxxx
//Allright reserved.
//
//文件名称:CycleArrayQueue.cpp
//文件标识:
//摘    要:CycleArrayQueue类的实现
//
//当前版本:0.1
//作    者:bookee
//完成日期:
//
// 取代版本:
// 原作者  :
// 完成日期:2007.10.20
////////////////////////////////////////////////////////////////////////


#ifndef CYCLE_ARRAY_QUEUE
#define CYCLE_ARRAY_QUEUE

#include <cassert>
#include <iostream>

template<typename Type> class CycleArrayQueue
{
public:
	CycleArrayQueue( unsigned long ulMaxLen = 20 );
	~CycleArrayQueue();

public:
	bool IsEmpty() const { return m_ulFront==m_ulRear; } // 判断对空
	bool IsFull() const { return (m_ulRear+1)%m_ulMaxSize == m_ulFront; } // 判断队满
	unsigned long GetCount() const { return (m_ulRear - m_ulFront + m_ulMaxSize)%m_ulMaxSize; } //队列中元素个数
	void AddTail(const Type &element); // 进队
	void GetHead(Type &element);  // 出队
	void MakeEmpty() { m_ulFront=m_ulRear=0; }  // 队置空(初始化)
	
private:
	unsigned long m_ulRear, m_ulFront;  // 队尾与对头
	unsigned long m_ulMaxSize	;   // 队列最多可容纳元素个数-1
	Type *m_pElementArray;   // 存放元素的数组
	
};

template<typename Type> CycleArrayQueue<Type>::CycleArrayQueue(unsigned long ulMaxLen )
{
	m_ulMaxSize = ulMaxLen;
	m_pElementArray = new Type[m_ulMaxSize];
	m_ulRear=m_ulFront=0;
	assert(m_pElementArray != NULL);  // 断言:分配成功
}

template<typename Type> CycleArrayQueue<Type>::~CycleArrayQueue()
{
	assert( m_pElementArray != NULL);
	delete[] m_pElementArray;
}

template<typename Type> void CycleArrayQueue<Type>::AddTail(const Type &element)
{
	assert( ! IsFull() );                 // 断言: 队列不满才能进队
	m_pElementArray[m_ulRear] = element;
	m_ulRear = (m_ulRear+1)%m_ulMaxSize;			// 指向队尾最后一个元素的下一个
}

template<typename Type> void CycleArrayQueue<Type>::GetHead(Type &element)
{
	assert( !IsEmpty() );
	element = m_pElementArray[m_ulFront];
	m_ulFront = (m_ulFront+1)%m_ulMaxSize;			// 出队列
}

#endif