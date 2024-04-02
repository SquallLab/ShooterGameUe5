// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpItemComponent.h"


// 생성자 구체 크기 세팅

UPickUpItemComponent::UPickUpItemComponent()
{
	SphereRadius = 40.0f;
}

void UPickUpItemComponent::BeginPlay()
{
	Super::BeginPlay(); // 부모의 BeginPlay 실행한뒤에... 

	OnComponentBeginOverlap.AddDynamic(this, &UPickUpItemComponent::OnSphereBeginOverlap);
}

void UPickUpItemComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 할일 구현... 

	AMyCharacter* Character = Cast<AMyCharacter>(OtherActor);
	if (Character != nullptr)
	{// 부딪힌 대상이 플레이어 캐릭터이다. AMyCharacter 
		OnPickUp.Broadcast(Character); //  전파발생기.... 

		OnComponentBeginOverlap.RemoveAll(this);// 겹침 이벤트가 더이상 작동하지 않도록... 
	}
}

