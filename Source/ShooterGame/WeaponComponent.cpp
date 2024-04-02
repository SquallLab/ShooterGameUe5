// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponComponent.h"
#include "MyCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerController.h"



// ���� ĳ���Ϳ� ����
// �޽��� ���Ͽ� �ٿ��ְ�,
// �Է½ý��� Fire Ȱ��ȭ 
// ���� ���ؽ�Ʈ ���ؼ�. 
void UWeaponComponent::AttachWeapon(AMyCharacter* TargetCharacter)
{
	Character = TargetCharacter;
	if (Character == nullptr)
		return;

	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);

	// todo : 3�� �Ž��� ����ġ�ƴϰ�, 1�� �Ž� ����ġ... 
	AttachToComponent(Character->GetMesh(), AttachmentRules, FName(TEXT("GripPoint")));



}




