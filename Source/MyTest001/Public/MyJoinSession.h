// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"


#include <iostream>
#include<winsock2.h>//winsock2.0��ͷ�ļ�������windows�Ķ�̬��
#include<ws2tcpip.h>//sockaddr_in6��ͷ�ļ�
using namespace std;//�����ռ�

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
