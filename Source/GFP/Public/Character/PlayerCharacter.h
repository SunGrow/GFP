// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GFPCharacter.h"
#include "InputActionValue.h"
#include "PlayerCharacter.generated.h"

class AGFPPlayerController;
class UPlayerAttributeSet;

UCLASS()
class GFP_API APlayerCharacter : public AGFPCharacter,
                                 public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	TObjectPtr<AGFPPlayerController> PlayerController;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& InputActionValue);
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	UFUNCTION(BlueprintPure, Category = "DFP | Player")
	AGFPPlayerController* GetPlayerController();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
	TWeakObjectPtr<UPlayerAttributeSet> PlayerAttributeSet;
	
	UPROPERTY(BlueprintReadOnly, Transient)
	FVector InputVector;
	
	UPROPERTY(BlueprintReadOnly, Transient)
	FVector LastInputVector;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FGameplayTag MovementAllowedGameplayTag;
};
