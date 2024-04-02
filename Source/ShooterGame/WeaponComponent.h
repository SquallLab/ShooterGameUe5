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

	// 플레이어 장착 기능
	UFUNCTION(BlueprintCallable, Category = "MyWeapon")
	void AttachWeapon(AMyCharacter* TargetCharacter);
	
	// 총알 발사하는 기능 
	UFUNCTION(BlueprintCallable, Category = "MyWeapon")
	void Fire();


	// Destroy : 강제 호출로 객체를 삭제했을때 
	// LevelTransition :  레벨 변경으로 객체 소멸 
	// EndPlayInEditor : 에디터 종료. 
protected:
	UFUNCTION()
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	AMyCharacter* Character;


};
