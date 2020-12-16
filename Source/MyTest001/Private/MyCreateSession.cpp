// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCreateSession.h"


void UMyCreateSession::FunCreateSession()
{
	//初始化winsock2.2相关的动态库
	WSADATA wd;//获取Socket相关信息
	if (WSAStartup(MAKEWORD(2, 2), &wd) != 0)//0标识成功 MAKEWORD版本
	{
		cout << "WSAStartup error:" << WSAGetLastError() << endl;//WSAGetLastError()获取错误
	}
	//
	//TCP Server的代码结构
	//1.创建TCP socket 流式套接字
	SOCKET s = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET)//创建失败，返回错误信息
	{
		cout << "socket error:" << WSAGetLastError() << endl;
		
	}

	//2.绑定socket到一个IP地址和端口
	sockaddr_in6 addr;
	memset(&addr, 0, sizeof(sockaddr_in6));
	addr.sin6_port = htons(8000);//网络字节序，端口号
	addr.sin6_family = AF_INET6;//地址族
								//addr.sin6_addr = in6addr_any;//in6addr_any表示绑定任意ip地址（IPv6）
								//cmd ipconfig 查询本机IPv6地址
	inet_pton(AF_INET6, "240e:b5:4800:c57:2984:4fa8:b1cc:64c3", &addr.sin6_addr);//绑定指定地址

	int len = sizeof(sockaddr_in6);//指定大小
	if (bind(s, (sockaddr*)&addr, len) == SOCKET_ERROR)//(sockaddr*)强制转换
	{
		//有时socket端口被占用了，也没办法bind就会返回错误
		cout << "bind error:" << WSAGetLastError() << endl;
		
	}
	//3.监听
	//s套接字，5也可用一个宏，表示正在等待完成相应TCP三路握手过程的队列长度
	if (listen(s, 5) == SOCKET_ERROR)
	{
		cout << "listen error:" << WSAGetLastError() << endl;
		
	}

	//4.接受客户端请求，并且返回和客户端通讯的套接字
	sockaddr_in6 addrClient;
	memset(&addrClient, 0, sizeof(sockaddr_in6));

	int lenClient = sizeof(addrClient);
	SOCKET c = accept(s, (sockaddr*)&addrClient, &lenClient);//成功返回clinet端的套接字
	if (c == INVALID_SOCKET)
	{
		cout << "accept error" << WSAGetLastError() << endl;
		
	}
	//6.关闭套接字
	closesocket(s);
	///
	WSACleanup();
}
