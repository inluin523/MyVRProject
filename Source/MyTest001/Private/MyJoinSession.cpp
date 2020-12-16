// Fill out your copyright notice in the Description page of Project Settings.

#include "MyJoinSession.h"

void UMyJoinSession::FunJoinSession()
{
	WSADATA wd;//��ȡSocket�����Ϣ
	if (WSAStartup(MAKEWORD(2, 2), &wd) != 0)//0��ʶ�ɹ� MAKEWORD�汾
	{
		cout << "WSAStartup error:" << WSAGetLastError() << endl;//WSAGetLastError()��ȡ����
	}

	//
	//TCP Clinet�Ĵ���ṹ
	//1.����TCP socket ��ʽ�׽���
	SOCKET s = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);//��ַ�壬�׽�������,Э��----�ɹ�����һ��socket
	if (s == INVALID_SOCKET)//����ʧ�ܣ����ش�����Ϣ
	{
		cout << "socket error:" << WSAGetLastError() << endl;
		
	}

	//2.���ӷ����
	sockaddr_in6 addr;//sockaddr����
	memset(&addr, 0, sizeof(sockaddr_in6));
	addr.sin6_port = htons(8000);//�����ֽ��򣬶˿ں�
								 //ָ�����ӵķ����������any���ӵ���ʲô������
	inet_pton(AF_INET6, "240e:b5:4800:c57:2984:4fa8:b1cc:64c3", &addr.sin6_addr);
	addr.sin6_family = AF_INET6;//��ַ��
	int len = sizeof(sockaddr_in6);//ָ����С
	if (connect(s, (sockaddr*)&addr, len) == SOCKET_ERROR)
	{
		cout << "connect error:" << WSAGetLastError() << endl;
		
	}

	//4.�ر��׽���
	closesocket(s);
	///
	WSACleanup();
}
