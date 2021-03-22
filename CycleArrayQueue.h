

////////////////////////////////////////////////////////////////////////
//Copyright @2007,xxxx
//Allright reserved.
//
//�ļ�����:CycleArrayQueue.cpp
//�ļ���ʶ:
//ժ    Ҫ:CycleArrayQueue���ʵ��
//
//��ǰ�汾:0.1
//��    ��:bookee
//�������:
//
// ȡ���汾:
// ԭ����  :
// �������:2007.10.20
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
	bool IsEmpty() const { return m_ulFront==m_ulRear; } // �ж϶Կ�
	bool IsFull() const { return (m_ulRear+1)%m_ulMaxSize == m_ulFront; } // �ж϶���
	unsigned long GetCount() const { return (m_ulRear - m_ulFront + m_ulMaxSize)%m_ulMaxSize; } //������Ԫ�ظ���
	void AddTail(const Type &element); // ����
	void GetHead(Type &element);  // ����
	void MakeEmpty() { m_ulFront=m_ulRear=0; }  // ���ÿ�(��ʼ��)
	
private:
	unsigned long m_ulRear, m_ulFront;  // ��β���ͷ
	unsigned long m_ulMaxSize	;   // ������������Ԫ�ظ���-1
	Type *m_pElementArray;   // ���Ԫ�ص�����
	
};

template<typename Type> CycleArrayQueue<Type>::CycleArrayQueue(unsigned long ulMaxLen )
{
	m_ulMaxSize = ulMaxLen;
	m_pElementArray = new Type[m_ulMaxSize];
	m_ulRear=m_ulFront=0;
	assert(m_pElementArray != NULL);  // ����:����ɹ�
}

template<typename Type> CycleArrayQueue<Type>::~CycleArrayQueue()
{
	assert( m_pElementArray != NULL);
	delete[] m_pElementArray;
}

template<typename Type> void CycleArrayQueue<Type>::AddTail(const Type &element)
{
	assert( ! IsFull() );                 // ����: ���в������ܽ���
	m_pElementArray[m_ulRear] = element;
	m_ulRear = (m_ulRear+1)%m_ulMaxSize;			// ָ���β���һ��Ԫ�ص���һ��
}

template<typename Type> void CycleArrayQueue<Type>::GetHead(Type &element)
{
	assert( !IsEmpty() );
	element = m_pElementArray[m_ulFront];
	m_ulFront = (m_ulFront+1)%m_ulMaxSize;			// ������
}

#endif