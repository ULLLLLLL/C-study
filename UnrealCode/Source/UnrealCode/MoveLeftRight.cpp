// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveLeftRight.h"
#include "Switch.h"

// Sets default values
AMoveLeftRight::AMoveLeftRight():m_LocX(0), m_IsMoveRight(true), m_IsPlay(false)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// CreateDefaultSubobject : new 키워드와 같이 언리얼에서 동적으로 객체를 생성하는 키워드
	// TEXT : 언리얼에서 사용하는 문자형 중에 하나
	// <UStaticMeshComponent>(TEXT("SceneRootRoot")); // UStaticMeshComponent 객체를 "SceneRootRoot" 이름으로 동적으로 생성
	Scene = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SceneRootRoot"));
	// <UStaticMeshComponent>(TEXT("mymyMesh")); // UStaticMeshComponent 객체를 "mymyMesh" 이름으로 동적으로 생성
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mymyMesh"));

	SetRootComponent(Scene); // Scene을 Root Component로 올리겠다.
	//RootComponent = Scene; // Scene을 Root Component로 올리겠다.

	// AttachToComponent : Component 붙이는 기눙
	// Scene에 붙인다. 현재 좌표값을 Scene 기준에 Relative(상대) 좌표계로
	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);

	// RootComponent에 붙인다. 현재 좌표값을 RootComponent 기준에 Relative(상대) 좌표계로
	// StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	// UAsset 가져오기
	// 스태틱 메쉬 컴포넌트 안에 넣은 스태틱메쉬를 가져오는 용도
	// ConstructorHelpers::FClassFinder : 오브젝트 에셋을 찾는다.
	// <UStaticMesh> : 찾을 에셋 타입
	// sm : 찾아서 넣을 객체 이름
	// static ConstructorHelpers::FObjectFinder < UStaticMesh > sm(TEXT("")); 이런 형태에서 넣고자 하는 것의 레퍼런스 주소를 복사하여 "" 안에 붙여넣는다
	/*
	static ConstructorHelpers::FObjectFinder <UStaticMesh> sm(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));

	if (sm.Succeeded()) // 에셋 불러오기 성공 여부 체크
	{
		StaticMesh->SetStaticMesh(sm.Object); // SetStaticMeshComponent애 StaticMesh 적용
	}
	*/
}

AMoveLeftRight::~AMoveLeftRight()
{
}


// Called when the game starts or when spawned
void AMoveLeftRight::BeginPlay()
{
	Super::BeginPlay();
	if (IsValid(m_Switch))
		m_Switch->FDele_EventOverlap.AddDynamic(this, &AMoveLeftRight::EventOverlap);
}

// Called every frame
void AMoveLeftRight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);// 오버라이드한 함수인 경우 부모 함수를 실행한다.
	
	//IsMoveRight; // 움직임 방향

	//LocX += 1; // 오른쪽

	//LocX -= 1; // 왼쪽
	// SetRelativeLocation : 상대적인 위치값을 설정한다.
	// FVector : 언리얼에서 사용하는 3차원 좌표 변수
	// StaticMesh->SetRelativeLocation(FVector(LocX,0,0));
	
	if (m_IsPlay == false)
		return;
	
	if (m_IsMoveRight) // 움직임 방향                                                                                                                                                                                                                                                   
	{
		m_LocX += 1;
		StaticMesh->SetRelativeLocation(FVector(m_LocX, 0, 0)); // 이게 Set Relative Location과 동일하다.
		if (m_LocX >= 200)
		{
			m_IsMoveRight = false;
		}
	}
	else
	{
		m_LocX -= 1;
		StaticMesh->SetRelativeLocation(FVector(m_LocX, 0, 0));
		if (m_LocX <= -200)
		{
			m_IsMoveRight = true;
		}
	}
}

void AMoveLeftRight::EventOverlap(bool isBegin)
{
	m_IsPlay = isBegin;
}

void AMoveLeftRight::Code_DoPlay_Implementation(bool IsPlay)
{
	m_IsPlay = IsPlay;
}