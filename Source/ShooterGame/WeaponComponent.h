// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "WeaponComponent.generated.h"

class AMyCharacter;



UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SHOOTERGAME_API UWeaponComponent : public USkeletalMeshComponent
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MyInput", meta = (AllowPrivateAccess ="true"))
	class UInputMappingContext* FireMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MyInput", meta = (AllowPrivateAccess = "true"))
	class UInputAction* FireInputAction;

	UWeaponComponent();

	// �÷��̾� ���� ���
	UFUNCTION(BlueprintCallable, Category = "MyWeapon")
	void AttachWeapon(AMyCharacter* TargetCharacter);
	
	// �Ѿ� �߻��ϴ� ��� 
	UFUNCTION(BlueprintCallable, Category = "MyWeapon")
	void Fire();


	// Destroy : ���� ȣ��� ��ü�� ���������� 
	// LevelTransition :  ���� �������� ��ü �Ҹ� 
	// EndPlayInEditor : ������ ����. 
protected:
	UFUNCTION()
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	AMyCharacter* Character;


};
