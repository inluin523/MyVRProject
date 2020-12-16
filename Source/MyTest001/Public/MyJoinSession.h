// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"


#include <iostream>
#include<winsock2.h>//winsock2.0的头文件，链接windows的动态库
#include<ws2tcpip.h>//sockaddr_in6的头文件
using namespace std;//命名空间

#pragma comment(lib,"ws2_32.lib")

#include "MyJoinSession.generated.h"

/**
 * 
 */
UCLASS()
class MYTEST001_API UMyJoinSession : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
		UFUNCTION(BlueprintCallable)
		static void FunJoinSession();
	
	
};
