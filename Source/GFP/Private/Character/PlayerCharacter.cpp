// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayerCharacter.h"

#include "EnhancedInputComponent.h"

#include "Core/GFPPlayerController.h"

#include "System/GFPAbilitySystemComponent.h"
#include "Core/GFPPlayerState.h"
#include "System/Gameplay/Attributes/PlayerAttributeSet.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MovementAllowedGameplayTag = FGameplayTag::RequestGameplayTag(FName("Movement.MovementAllowed"));
	
	AttributeSet = CreateDefaultSubobject<UPlayerAttributeSet>(TEXT("PlayerAttributeSet"));
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	PlayerAttributeSet = StaticCast<AGFPPlayerState*>(GetPlayerState())->PlayerAttributeSet;
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	const auto InputsAsset = GetPlayerController()->GetInputAsset();
	
	if (IsValid(InputsAsset))
	{
		UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
		
		EnhancedInputComponent->BindAction(InputsAsset->Look, ETriggerEvent::Triggered, this, &APlayerCharacter::Look);
		EnhancedInputComponent->BindAction(InputsAsset->Move, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);
		AbilitySystemComponent->BindToInputComponent(PlayerInputComponent);
		FGameplayAbilityInputBinds
		AbilitySystemComponent->BindAbilityActivationToInputComponent(PlayerInputComponent, )
	}
}

AGFPPlayerController* APlayerCharacter::GetPlayerController()
{
	if (!IsValid(PlayerController))
	{
		PlayerController = GetController<AGFPPlayerController>();
	}

	return PlayerController;
}

UAbilitySystemComponent* APlayerCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent.Get();
}

void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	auto PS = GetPlayerState<AGFPPlayerState>();
	if (IsValid(PS))
	{
		AbilitySystemComponent = PS->AbilitySystemComponent;
		AbilitySystemComponent->InitAbilityActorInfo(PS, this);
	}
}

void APlayerCharacter::Move(const FInputActionValue& Value)
{
	FVector2d MovementVector = Value.Get<FVector2D>();
	
	if (Controller != nullptr)
	{
		if (!AbilitySystemComponent->HasMatchingGameplayTag(MovementAllowedGameplayTag))
		{
			return;
		}
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		InputVector = ForwardDirection * MovementVector.Y + RightDirection * MovementVector.X;
		InputVector.Normalize();
		// add movement 
		AddMovementInput(InputVector, 1.f);
	}
}

void APlayerCharacter::Look(const FInputActionValue& InputActionValue)
{
	const auto Vector = InputActionValue.Get<FVector>();
	APawn::AddControllerYawInput(Vector.X);
	APawn::AddControllerPitchInput(-Vector.Y);
}
