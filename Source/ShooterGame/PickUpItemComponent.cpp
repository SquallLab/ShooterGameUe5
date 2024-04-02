// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpItemComponent.h"


// ������ ��ü ũ�� ����

UPickUpItemComponent::UPickUpItemComponent()
{
	SphereRadius = 40.0f;
}

void UPickUpItemComponent::BeginPlay()
{
	Super::BeginPlay(); // �θ��� BeginPlay �����ѵڿ�... 

	OnComponentBeginOverlap.AddDynamic(this, &UPickUpItemComponent::OnSphereBeginOverlap);
}

void UPickUpItemComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// ���� ����... 

	AMyCharacter* Character = Cast<AMyCharacter>(OtherActor);
	if (Character != nullptr)
	{// �ε��� ����� �÷��̾� ĳ�����̴�. AMyCharacter 
		OnPickUp.Broadcast(Character); //  ���Ĺ߻���.... 

		OnComponentBeginOverlap.RemoveAll(this);// ��ħ �̺�Ʈ�� ���̻� �۵����� �ʵ���... 
	}
}

