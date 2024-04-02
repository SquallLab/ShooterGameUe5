// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Camera/CameraComponent.h"
#include "MyCharacter.generated.h"


// 전방선언 
class USkeletalMeshComponent;

UCLASS()
class SHOOTERGAME_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	// 전방선언... 일단 쓰고, 나중에 정의 
	UPROPERTY(EditAnywhere, Category = "FirstInput")
	class UInputMappingContext* PlayerContext; // 기본  IMC 
	UPROPERTY(EditAnywhere, Category = "FirstInput")
	class UInputAction* MoveInputAction;
	UPROPERTY(EditAnywhere, Category = "FirstInput")
	class UInputAction* CameraInputAction;
	UPROPERTY(EditAnywhere, Category = "FirstInput")
	class UInputAction* JumpInputAction;

	UPROPERTY(EditAnywhere, Category = "Component")
	UCameraComponent* ShooterCameraComponent;

private:
	void Move(const FInputActionValue& value);
	void Camera(const FInputActionValue& value);



	UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	USkeletalMeshComponent* Mesh1P;


};
