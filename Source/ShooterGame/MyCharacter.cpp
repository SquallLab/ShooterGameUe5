// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/CapsuleComponent.h"


// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	ShooterCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("ShooterCamera"));
	ShooterCameraComponent->SetupAttachment(GetCapsuleComponent());
	ShooterCameraComponent->SetRelativeLocation(FVector(-10.0f, 0.0f, 60.0f));
	ShooterCameraComponent->bUsePawnControlRotation = true;


}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();


	// MappintContext 등록 
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))// 성공 
	{
		if (UEnhancedInputLocalPlayerSubsystem* subSystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			subSystem->AddMappingContext(PlayerContext, 0);
		}
	}


	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// jump / stopjump
		EnhancedInputComponent->BindAction(JumpInputAction, ETriggerEvent::Triggered, this,
			&ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpInputAction, ETriggerEvent::Completed, this,
			&ACharacter::StopJumping);

		EnhancedInputComponent->BindAction(MoveInputAction, ETriggerEvent::Triggered, this,
			&AMyCharacter::Move);

		EnhancedInputComponent->BindAction(CameraInputAction, ETriggerEvent::Triggered, this,
			&AMyCharacter::Camera);
	}
}

void AMyCharacter::Move(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("MoveAction"));
	FVector2d InputValue2D = Value.Get<FVector2d>();

	if (Controller != nullptr)
	{
		AddMovementInput(GetActorForwardVector(), InputValue2D.Y);
		AddMovementInput(GetActorRightVector(), InputValue2D.X);
	}
}

void AMyCharacter::Camera(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("CameraAction"));
	FVector2d InputValue2D = Value.Get<FVector2d>();
	if (Controller != nullptr)
	{
		AddControllerYawInput(InputValue2D.X);
		AddControllerPitchInput(InputValue2D.Y);
	}
}

