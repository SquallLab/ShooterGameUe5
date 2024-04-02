// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "MyCharacter.h"
#include "PickUpItemComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPickUp, AMyCharacter*, PickUpCharacter);

UCLASS(Blueprintable, BlueprintType, ClassGroup =(Custom) , meta=(BlueprintSpawnableComponent))
class SHOOTERGAME_API UPickUpItemComponent : public USphereComponent
{
	GENERATED_BODY()
	

public:
	UPROPERTY(BlueprintAssignable, Category = "Interaction")
	FOnPickUp OnPickUp;

	UPickUpItemComponent();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
