// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h" // ������ �ӵ��� ������ �ϱ� ���� �⺻���� �ּ����� ���̺귯���� ������ ���
#include "GameFramework/Actor.h" //AActorŬ���� ��� ����

// �� .generated.h�𸮾� Ŭ����(MoveLeftRight) ���� ó���ϴ� ��� - �𸮾� Ŭ���� ���� �⺻ ��Ģ
// �� ��� �𸮾� Ŭ������ �����Ƿ��� �Ʒ� �ڵ带 �־���� �Ѵ�.
// �� �ݵ�� ��� #include�� �������� ��ġ�ؾ� �Ѵ�.
#include "MoveLeftRight.generated.h" 

// �� Ŭ������ UNREALCODE_API ��⿡ ���Եȴ�.
UCLASS() // �𸮾� Ŭ���� ���� - �𸮾� Ŭ���� ���� �⺻ ��Ģ
class UNREALCODE_API AMoveLeftRight : public AActor // public AActor : AActor�� ����� ��� �ްڴ�.
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* Scene;

	// UPROPERTY : https://docs.unrealengine.com/4.26/ko/ProgrammingAndScripting/GameplayArchitecture/Properties/
	//�Ʒ� �� ���� �ݵ�� �پ� �־�� �Ѵ�. ���̿� �� ������ �־ �ȵȴ�.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	float LocX;
	bool IsMoveRight=true;
};
