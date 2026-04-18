// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

void UMyGameInstance::Init()
{
	Super::Init(); // 필수이다. 습관처럼 override 한 함수는 사용을 해주자

	TCHAR LogChArray[] = TEXT("Hello Unreal");
	UE_LOG(LogTemp, Log, LogChArray);


	FString LogCharString = LogChArray;
	// pointer연산자를 사용하여 실제 문자열 데이터를 가져올 수 있습니다.
	UE_LOG(LogTemp, Log, TEXT("%s"), *LogCharString); 

	FString TestString(TEXT("Hello YoungHwan."));
	UE_LOG(LogTemp, Log, TEXT("%s"), *TestString);

	// FString을 TCHAR로 받는 방법 1
	const TCHAR* LongCharPtr = *TestString; // FString을 TCHAR로 받는 방법
	TCHAR* LogCharDataPtr = LogCharString.GetCharArray().GetData();

	// FString을 TCHAR로 받는 방법 2
	// 아래 방법의 경우 FString의 데이터를 값 복사 하는 방법이다.
	// 보통 C 스타일 API에 넘겨야 할때 사용한다.
	TCHAR LogCharArrayWithSize[100];
	FCString::Strcpy(LogCharArrayWithSize, LogCharString.Len(), *LogCharString);

	// FString.Contains함수는 문자열에 특정문자가 포함되었는지 확인하는 함수
	if (LogCharString.Contains(TEXT("unreal"), ESearchCase::IgnoreCase))
	{
		int32 Index = LogCharString.Find(TEXT("unreal"), ESearchCase::IgnoreCase);
		FString EndString = LogCharString.Mid(Index);
		UE_LOG(LogTemp, Log, TEXT("Find Test : %s"), *EndString);
	}

	FString Left, Right;
	if (LogCharString.Split(TEXT(" "), &Left, &Right))
	{
		UE_LOG(LogTemp, Log, TEXT("Split Test: %s 와 %s"), *Left, *Right);
	}

	int32 IntValue = 32;
	float FloatValue = 3.141592;

	FString FloatIntString = FString::Printf(TEXT("Int:%d Float:%f"), IntValue, FloatValue);
	FString FloatString = FString::SanitizeFloat(FloatValue);
	FString IntString = FString::FromInt(IntValue);

	UE_LOG(LogTemp, Log, TEXT("%s"), *FloatIntString);
	UE_LOG(LogTemp, Log, TEXT("Int:%s Float:%s"), *IntString, *FloatString);

	int32 IntValueFromString = FCString::Atoi(*IntString);
	float FloatValueFromString = FCString::Atof(*FloatString);
	FloatIntString = FString::Printf(TEXT("Int:%d Float:%f"), IntValueFromString,FloatValueFromString);

	UE_LOG(LogTemp, Log, TEXT("%s"), *FloatIntString);

	FName key1(TEXT("PELVIS"));
	FName Key2(TEXT("pelvis"));

	UE_LOG(LogTemp, Log, TEXT("FName 비교 결과 : %s"), key1 == Key2 ? TEXT("같음") : TEXT("다름"));

	for (int i = 0; i < 1000; ++i) {
		FName SearchInNamePool = FName(TEXT("pelivis"));
		const static FName StaticOnlyOnce(TEXT("pelvis")); // 오버헤드가 발생할 수 있으니 정의하라?
	}
}
