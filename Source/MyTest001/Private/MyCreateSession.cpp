// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCreateSession.h"


void UMyCreateSession::FunCreateSession()
{
	//��ʼ��winsock2.2��صĶ�̬��
	WSADATA wd;//��ȡSocket�����Ϣ
	if (WSAStartup(MAKEWORD(2, 2), &wd) != 0)//0��ʶ�ɹ� MAKEWORD�汾
	{
		cout << "WSAStartup error:" << WSAGetLastError() << endl;//WSAGetLastError()��ȡ����
	}
	//
	//TCP Server�Ĵ���ṹ
	//1.����TCP socket ��ʽ�׽���
	SOCKET s = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET)//����ʧ�ܣ����ش�����Ϣ
	{
		cout << "socket error:" << WSAGetLastError() << endl;
		
	}

	//2.��socket��һ��IP��ַ�Ͷ˿�
	sockaddr_in6 addr;
	memset(&addr, 0, sizeof(sockaddr_in6));
	addr.sin6_port = htons(8000);//�����ֽ��򣬶˿ں�
	addr.sin6_family = AF_INET6;//��ַ��
								//addr.sin6_addr = in6addr_any;//in6addr_any��ʾ������ip��ַ��IPv6��
								//cmd ipconfig ��ѯ����IPv6��ַ
	inet_pton(AF_INET6, "240e:b5:4800:c57:2984:4fa8:b1cc:64c3", &addr.sin6_addr);//��ָ����ַ

	int len = sizeof(sockaddr_in6);//ָ����С
	if (bind(s, (sockaddr*)&addr, len) == SOCKET_ERROR)//(sockaddr*)ǿ��ת��
	{
		//��ʱsocket�˿ڱ�ռ���ˣ�Ҳû�취bind�ͻ᷵�ش���
		cout << "bind error:" << WSAGetLastError() << endl;
		
	}
	//3.����
	//s�׽��֣�5Ҳ����һ���꣬��ʾ���ڵȴ������ӦTCP��·���ֹ��̵Ķ��г���
	if (listen(s, 5) == SOCKET_ERROR)
	{
		cout << "listen error:" << WSAGetLastError() << endl;
		
	}

	//4.���ܿͻ������󣬲��ҷ��غͿͻ���ͨѶ���׽���
	sockaddr_in6 addrClient;
	memset(&addrClient, 0, sizeof(sockaddr_in6));

	int lenClient = sizeof(addrClient);
	SOCKET c = accept(s, (sockaddr*)&addrClient, &lenClient);//�ɹ�����clinet�˵��׽���
	if (c == INVALID_SOCKET)
	{
		cout << "accept error" << WSAGetLastError() << endl;
		
	}
	//6.�ر��׽���
	closesocket(s);
	///
	WSACleanup();
}
