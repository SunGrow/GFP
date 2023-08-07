// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/GFPCharacter.h"

#include "System/GFPAbilitySystemComponent.h"


// Sets default values
AGFPCharacter::AGFPCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UGFPAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

// Called when the game starts or when spawned
void AGFPCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGFPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AGFPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

UAbilitySystemComponent* AGFPCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

