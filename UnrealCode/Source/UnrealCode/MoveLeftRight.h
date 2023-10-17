// Fill out your copyright notice in the Description page of Project Settings.

#pragma once 

#include "CoreMinimal.h" // 컴파일 속도를 빠르게 하기 위해 기본적인 최소한의 라이브러리만 포함한 헤더
#include "Public/Tools/InterfacePlayObj.h" // Public 폴더에 있는 Tools 폴더에 있는 InterfacePlayObj.h를 가져다가 쓴다.
#include "GameFramework/Actor.h" //AActor클래스 헤더 파일

// ★ .generated.h언리얼 클래스(MoveLeftRight) 생성 처리하는 헤더 - 언리얼 클래스 생성 기본 규칙
// ★ 모든 언리얼 클래스가 생성되려면 아래 코드를 넣어줘야 한다.
// ★ 반드시 모든 #include의 마지막에 배치해야 한다.
#include "MoveLeftRight.generated.h"  // 

// 이 클래스는 UNREALCODE_API 모듈에 포함된다.
UCLASS() // 언리얼 클래스 선언 - 언리얼 클래스 생성 기본 규칙
class UNREALCODE_API AMoveLeftRight : public AActor, public IInterfacePlayObj // public AActor : AActor의 기능을 상속 받겠다. UNREALCODE_API는 마음대로 지은 이름이다.
{
	GENERATED_BODY() // 언리얼 코드 생성 함수 - 언리얼 클래스 생성 기본 규칙

public:	
	// Sets default values for this actor's properties
	AMoveLeftRight();
	~AMoveLeftRight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void EventOverlap(bool isBegin);

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Code_DoPlay(bool IsPlay); // 블루프린트 호출용 함수명 선언 <- 얘는 건드는 거 아님!

	virtual void Code_DoPlay_Implementation(bool IsPlay) override; // C++에서 실행될 함수

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* Scene;

	// UPROPERTY : https://docs.unrealengine.com/4.26/ko/ProgrammingAndScripting/GameplayArchitecture/Properties/
	//아래 두 줄은 반드시 붙어 있어야 한다. 사이에 그 무엇도 있어선 안된다.
	// VisibleAnywhere: StaticMesh라는 이름의 UStaticMeshComponent변수가 블루 프린트 상에서 보인다.
	// BlueprintReadWrite : 블루 프린트 내에서 읽고 쓸 수 있다.
	// 이용하고 싶은 변수 위에 붙여서 쓴다.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh; // 이용하고 싶은 변수

	float m_LocX;
	bool m_IsMoveRight=true;
	bool m_IsPlay=false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<class ASwitch> m_Switch;
};
