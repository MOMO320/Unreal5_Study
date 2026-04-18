// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

void UMyGameInstance::Init()
{
	// 가상함수를 상속받아 overrdie 하는 경우
	// 부모 객체의 함수를 먼저 호출해줘야 한다.
	Super::Init(); 

	// CatetoryName, 수준,  Format(TEXT라는 매크로를 이용해서 작성한다.)
	// 문자열은 TEXT로 바꿔서 만들어주는게 좋다.
	UE_LOG(LogTemp, Log, TEXT("%s"), TEXT("Hello  Unreal!"));
}
