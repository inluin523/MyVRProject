// Fill out your copyright notice in the Description page of Project Settings.

#include "MyJoinSession.h"

void UMyJoinSession::FunJoinSession()
{
	WSADATA wd;//获取Socket相关信息
	if (WSAStartup(MAKEWORD(2, 2), &wd) != 0)//0标识成功 MAKEWORD版本
	{
		cout << "WSAStartup error:" << WSAGetLastError() << endl;//WSAGetLastError()获取错误
	}

	//
	//TCP Clinet的代码结构
	//1.创建TCP socket 流式套接字
	SOCKET s = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);//地址族，套接字类型,协议----成功返回一个socket
	if (s == INVALID_SOCKET)//创建失败，返回错误信息
	{
		cout << "socket error:" << WSAGetLastError() << endl;
		
	}

	//2.链接服务端
	sockaddr_in6 addr;//sockaddr变种
	memset(&addr, 0, sizeof(sockaddr_in6));
	addr.sin6_port = htons(8000);//网络字节序，端口号
								 //指定连接的服务器如果用any步子到用什么服务器
	inet_pton(AF_INET6, "240e:b5:4800:c57:2984:4fa8:b1cc:64c3", &addr.sin6_addr);
	addr.sin6_family = AF_INET6;//地址族
	int len = sizeof(sockaddr_in6);//指定大小
	if (connect(s, (sockaddr*)&addr, len) == SOCKET_ERROR)
	{
		cout << "connect error:" << WSAGetLastError() << endl;
		
	}

	//4.关闭套接字
	closesocket(s);
	///
	WSACleanup();
}
