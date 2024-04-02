// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponComponent.h"
#include "MyCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerController.h"



// 무기 캐릭터에 장착
// 메쉬를 소켓에 붙여주고,
// 입력시스템 Fire 활성화 
// 매핍 컨텍스트 통해서. 
void UWeaponComponent::AttachWeapon(AMyCharacter* TargetCharacter)
{
	Character = TargetCharacter;
	if (Character == nullptr)
		return;

	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);

	// todo : 3인 매쉬에 어테치아니고, 1인 매쉬 어테치... 
	AttachToComponent(Character->GetMesh(), AttachmentRules, FName(TEXT("GripPoint")));



}




