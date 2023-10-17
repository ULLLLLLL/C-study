// Fill out your copyright notice in the Description page of Project Settings.

#pragma once 

#include "CoreMinimal.h" // ������ �ӵ��� ������ �ϱ� ���� �⺻���� �ּ����� ���̺귯���� ������ ���
#include "Public/Tools/InterfacePlayObj.h" // Public ������ �ִ� Tools ������ �ִ� InterfacePlayObj.h�� �����ٰ� ����.
#include "GameFramework/Actor.h" //AActorŬ���� ��� ����

// �� .generated.h�𸮾� Ŭ����(MoveLeftRight) ���� ó���ϴ� ��� - �𸮾� Ŭ���� ���� �⺻ ��Ģ
// �� ��� �𸮾� Ŭ������ �����Ƿ��� �Ʒ� �ڵ带 �־���� �Ѵ�.
// �� �ݵ�� ��� #include�� �������� ��ġ�ؾ� �Ѵ�.
#include "MoveLeftRight.generated.h"  // 

// �� Ŭ������ UNREALCODE_API ��⿡ ���Եȴ�.
UCLASS() // �𸮾� Ŭ���� ���� - �𸮾� Ŭ���� ���� �⺻ ��Ģ
class UNREALCODE_API AMoveLeftRight : public AActor, public IInterfacePlayObj // public AActor : AActor�� ����� ��� �ްڴ�. UNREALCODE_API�� ������� ���� �̸��̴�.
{
	GENERATED_BODY() // �𸮾� �ڵ� ���� �Լ� - �𸮾� Ŭ���� ���� �⺻ ��Ģ

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
	void Code_DoPlay(bool IsPlay); // �������Ʈ ȣ��� �Լ��� ���� <- ��� �ǵ�� �� �ƴ�!

	virtual void Code_DoPlay_Implementation(bool IsPlay) override; // C++���� ����� �Լ�

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* Scene;

	// UPROPERTY : https://docs.unrealengine.com/4.26/ko/ProgrammingAndScripting/GameplayArchitecture/Properties/
	//�Ʒ� �� ���� �ݵ�� �پ� �־�� �Ѵ�. ���̿� �� ������ �־ �ȵȴ�.
	// VisibleAnywhere: StaticMesh��� �̸��� UStaticMeshComponent������ ��� ����Ʈ �󿡼� ���δ�.
	// BlueprintReadWrite : ��� ����Ʈ ������ �а� �� �� �ִ�.
	// �̿��ϰ� ���� ���� ���� �ٿ��� ����.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh; // �̿��ϰ� ���� ����

	float m_LocX;
	bool m_IsMoveRight=true;
	bool m_IsPlay=false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<class ASwitch> m_Switch;
};
